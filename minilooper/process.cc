#include "VBS.h"
#include "rooutil.h"
#include "cxxopts.h"

#define CLTLO 300
#define CLTMD 400
#define CLTHI 500
#define CSTLO 700
#define CSTMD 800
#define CSTHI 900
#define CMJJ 500
#define CDETAJJ 5
#define CBDT 0.545

class AnalysisConfig {

public:

    // TString that holds the input file list (comma separated)
    TString input_file_list_tstring;

    // TString that holds the name of the TTree to open for each input files
    TString input_tree_name;

    // Output TFile
    TFile* output_tfile;

    // Number of events to loop over
    int n_events;

    // Jobs to split (if this number is positive, then we will skip certain number of events)
    // If there are N events, and was asked to split 2 ways, then depending on job_index, it will run over first half or latter half
    int nsplit_jobs;

    // Job index (assuming nsplit_jobs is set, the job_index determine where to loop over)
    int job_index;

    // Debug boolean
    bool debug;

    // TChain that holds the input TTree's
    TChain* events_tchain;

    // Custom Looper object to facilitate looping over many files
    RooUtil::Looper<VBS> looper;

    // Custom Cutflow framework
    RooUtil::Cutflow cutflow;

    // Custom Histograms object compatible with RooUtil::Cutflow framework
    RooUtil::Histograms histograms;

};

AnalysisConfig ana;

// ./process INPUTFILEPATH OUTPUTFILE [NEVENTS]
int main(int argc, char** argv)
{

//********************************************************************************
//
// 1. Parsing options
//
//********************************************************************************

    // cxxopts is just a tool to parse argc, and argv easily

    // Grand option setting
    cxxopts::Options options("\n  $ doAnalysis",  "\n         **********************\n         *                    *\n         *       Looper       *\n         *                    *\n         **********************\n");

    // Read the options
    options.add_options()
        ("i,input"       , "Comma separated input file list OR if just a directory is provided it will glob all in the directory BUT must end with '/' for the path", cxxopts::value<std::string>())
        ("t,tree"        , "Name of the tree in the root file to open and loop over"                                             , cxxopts::value<std::string>())
        ("o,output"      , "Output file name"                                                                                    , cxxopts::value<std::string>())
        ("n,nevents"     , "N events to loop over"                                                                               , cxxopts::value<int>()->default_value("-1"))
        ("j,nsplit_jobs" , "Enable splitting jobs by N blocks (--job_index must be set)"                                         , cxxopts::value<int>())
        ("I,job_index"   , "job_index of split jobs (--nsplit_jobs must be set. index starts from 0. i.e. 0, 1, 2, 3, etc...)"   , cxxopts::value<int>())
        ("d,debug"       , "Run debug job. i.e. overrides output option to 'debug.root' and 'recreate's the file.")
        ("h,help"        , "Print help")
        ;

    auto result = options.parse(argc, argv);

    // NOTE: When an option was provided (e.g. -i or --input), then the result.count("<option name>") is more than 0
    // Therefore, the option can be parsed easily by asking the condition if (result.count("<option name>");
    // That's how the several options are parsed below

    //_______________________________________________________________________________
    // --help
    if (result.count("help"))
    {
        std::cout << options.help() << std::endl;
        exit(1);
    }

    //_______________________________________________________________________________
    // --input
    if (result.count("input"))
    {
        ana.input_file_list_tstring = result["input"].as<std::string>();
    }
    else
    {
        std::cout << options.help() << std::endl;
        std::cout << "ERROR: Input list is not provided! Check your arguments" << std::endl;
        exit(1);
    }

    //_______________________________________________________________________________
    // --tree
    if (result.count("tree"))
    {
        ana.input_tree_name = result["tree"].as<std::string>();
    }
    else
    {
        std::cout << options.help() << std::endl;
        std::cout << "ERROR: Input tree name is not provided! Check your arguments" << std::endl;
        exit(1);
    }

    //_______________________________________________________________________________
    // --debug
    if (result.count("debug"))
    {
        ana.output_tfile = new TFile("debug.root", "recreate");
    }
    else
    {
        //_______________________________________________________________________________
        // --output
        if (result.count("output"))
        {
            ana.output_tfile = new TFile(result["output"].as<std::string>().c_str(), "create");
            if (not ana.output_tfile->IsOpen())
            {
                std::cout << options.help() << std::endl;
                std::cout << "ERROR: output already exists! provide new output name or delete old file. OUTPUTFILE=" << result["output"].as<std::string>() << std::endl;
                exit(1);
            }
        }
        else
        {
            std::cout << options.help() << std::endl;
            std::cout << "ERROR: Output file name is not provided! Check your arguments" << std::endl;
            exit(1);
        }
    }

    //_______________________________________________________________________________
    // --nevents
    ana.n_events = result["nevents"].as<int>();

    //_______________________________________________________________________________
    // --nsplit_jobs
    if (result.count("nsplit_jobs"))
    {
        ana.nsplit_jobs = result["nsplit_jobs"].as<int>();
        if (ana.nsplit_jobs <= 0)
        {
            std::cout << options.help() << std::endl;
            std::cout << "ERROR: option string --nsplit_jobs" << ana.nsplit_jobs << " has zero or negative value!" << std::endl;
            std::cout << "I am not sure what this means..." << std::endl;
            exit(1);
        }
    }
    else
    {
        ana.nsplit_jobs = -1;
    }

    //_______________________________________________________________________________
    // --nsplit_jobs
    if (result.count("job_index"))
    {
        ana.job_index = result["job_index"].as<int>();
        if (ana.job_index < 0)
        {
            std::cout << options.help() << std::endl;
            std::cout << "ERROR: option string --job_index" << ana.job_index << " has negative value!" << std::endl;
            std::cout << "I am not sure what this means..." << std::endl;
            exit(1);
        }
    }
    else
    {
        ana.job_index = -1;
    }


    // Sanity check for split jobs (if one is set the other must be set too)
    if (result.count("job_index") or result.count("nsplit_jobs"))
    {
        // If one is not provided then throw error
        if ( not (result.count("job_index") and result.count("nsplit_jobs")))
        {
            std::cout << options.help() << std::endl;
            std::cout << "ERROR: option string --job_index and --nsplit_jobs must be set at the same time!" << std::endl;
            exit(1);
        }
        // If it is set then check for sanity
        else
        {
            if (ana.job_index >= ana.nsplit_jobs)
            {
                std::cout << options.help() << std::endl;
                std::cout << "ERROR: --job_index >= --nsplit_jobs ! This does not make sense..." << std::endl;
                exit(1);
            }
        }
    }

    //
    // Printing out the option settings overview
    //
    std::cout <<  "=========================================================" << std::endl;
    std::cout <<  " Setting of the analysis job based on provided arguments " << std::endl;
    std::cout <<  "---------------------------------------------------------" << std::endl;
    std::cout <<  " ana.input_file_list_tstring: " << ana.input_file_list_tstring <<  std::endl;
    std::cout <<  " ana.output_tfile: " << ana.output_tfile->GetName() <<  std::endl;
    std::cout <<  " ana.n_events: " << ana.n_events <<  std::endl;
    std::cout <<  " ana.nsplit_jobs: " << ana.nsplit_jobs <<  std::endl;
    std::cout <<  " ana.job_index: " << ana.job_index <<  std::endl;
    std::cout <<  "=========================================================" << std::endl;

//********************************************************************************
//
// 2. Opening input baby files
//
//********************************************************************************

    // Create the TChain that holds the TTree's of the baby ntuples
    ana.events_tchain = RooUtil::FileUtil::createTChain(ana.input_tree_name, ana.input_file_list_tstring);

    // Create a Looper object to loop over input files
    ana.looper.init(ana.events_tchain, &vbs, ana.n_events);


    // Set the cutflow object output file
    ana.cutflow.setTFile(ana.output_tfile);

    // Splitting events by channels
    ana.cutflow.addCut("PreselChannel", [&]() { return vbs.channel() >= 0; }, [&]() { return vbs.wgt() * vbs.btagsf() * vbs.lepsf() * vbs.xsec_sf() * vbs.genrewgt(); } );
    ana.cutflow.addCutToLastActiveCut("LooseVRChannel", [&]() { return vbs.mjj() > CMJJ  and vbs.detajj() > 3.0 and vbs.channel() >= 0; }, UNITY);

    ana.cutflow.getCut("LooseVRChannel"); ana.cutflow.addCutToLastActiveCut("EEChannel" , [&]() { return vbs.lepchannel() == 0 and fabs(vbs.mll() - 91.1874) > 15.; }, UNITY);
    ana.cutflow.getCut("LooseVRChannel"); ana.cutflow.addCutToLastActiveCut("EMChannel" , [&]() { return vbs.lepchannel() == 1; }, UNITY);
    ana.cutflow.getCut("LooseVRChannel"); ana.cutflow.addCutToLastActiveCut("MMChannel" , [&]() { return vbs.lepchannel() == 2; }, UNITY);
    ana.cutflow.getCut("LooseVRChannel"); ana.cutflow.addCutToLastActiveCut("LLChannel" , [&]() { return vbs.lepchannel() == 0 or vbs.lepchannel() == 1 or vbs.lepchannel() == 2; }, UNITY);
    ana.cutflow.getCut("LooseVRChannel"); ana.cutflow.addCutToLastActiveCut("ETChannel" , [&]() { return vbs.lepchannel() == 3; }, UNITY);
    ana.cutflow.getCut("LooseVRChannel"); ana.cutflow.addCutToLastActiveCut("MTChannel" , [&]() { return vbs.lepchannel() == 4; }, UNITY);
    ana.cutflow.getCut("LooseVRChannel"); ana.cutflow.addCutToLastActiveCut("LTChannel" , [&]() { return vbs.lepchannel() >= 3; }, UNITY);
    ana.cutflow.getCut("LooseVRChannel"); ana.cutflow.addCutToLastActiveCut("ElChannel" , [&]() { return vbs.categ() == 0; }, UNITY);
    ana.cutflow.getCut("LooseVRChannel"); ana.cutflow.addCutToLastActiveCut("MuChannel" , [&]() { return vbs.categ() == 1; }, UNITY);
    ana.cutflow.getCut("LooseVRChannel"); ana.cutflow.addCutToLastActiveCut("LgtChannel", [&]() { return vbs.categ() == 0 or vbs.categ() == 1; }, UNITY);
    ana.cutflow.getCut("LooseVRChannel"); ana.cutflow.addCutToLastActiveCut("TauChannel", [&]() { return vbs.categ() == 2; }, UNITY);
    ana.cutflow.getCut("LooseVRChannel"); ana.cutflow.addCutToLastActiveCut("NegChannel", [&]() { return vbs.categ() == 3; }, UNITY);

    ana.cutflow.getCut("PreselChannel"); ana.cutflow.addCutToLastActiveCut("PSEEChannel" , [&]() { return vbs.lepchannel() == 0 and fabs(vbs.mll() - 91.1874) > 15.; }, UNITY);
    ana.cutflow.getCut("PreselChannel"); ana.cutflow.addCutToLastActiveCut("PSEMChannel" , [&]() { return vbs.lepchannel() == 1; }, UNITY);
    ana.cutflow.getCut("PreselChannel"); ana.cutflow.addCutToLastActiveCut("PSMMChannel" , [&]() { return vbs.lepchannel() == 2; }, UNITY);
    ana.cutflow.getCut("PreselChannel"); ana.cutflow.addCutToLastActiveCut("PSLLChannel" , [&]() { return vbs.lepchannel() == 0 or vbs.lepchannel() == 1 or vbs.lepchannel() == 2; }, UNITY);
    ana.cutflow.getCut("PreselChannel"); ana.cutflow.addCutToLastActiveCut("PSETChannel" , [&]() { return vbs.lepchannel() == 3; }, UNITY);
    ana.cutflow.getCut("PreselChannel"); ana.cutflow.addCutToLastActiveCut("PSMTChannel" , [&]() { return vbs.lepchannel() == 4; }, UNITY);
    ana.cutflow.getCut("PreselChannel"); ana.cutflow.addCutToLastActiveCut("PSLTChannel" , [&]() { return vbs.lepchannel() >= 3; }, UNITY);
    ana.cutflow.getCut("PreselChannel"); ana.cutflow.addCutToLastActiveCut("PSElChannel" , [&]() { return vbs.categ() == 0; }, UNITY);
    ana.cutflow.getCut("PreselChannel"); ana.cutflow.addCutToLastActiveCut("PSMuChannel" , [&]() { return vbs.categ() == 1; }, UNITY);
    ana.cutflow.getCut("PreselChannel"); ana.cutflow.addCutToLastActiveCut("PSTauChannel", [&]() { return vbs.categ() == 2; }, UNITY);
    ana.cutflow.getCut("PreselChannel"); ana.cutflow.addCutToLastActiveCut("PSNegChannel", [&]() { return vbs.categ() == 3; }, UNITY);
    ana.cutflow.getCut("PreselChannel"); ana.cutflow.addCutToLastActiveCut("PSMTPosChannel" , [&]() { return vbs.lepchannel() == 4 and vbs.leadlepID() < 0; }, UNITY);
    ana.cutflow.getCut("PreselChannel"); ana.cutflow.addCutToLastActiveCut("PSMTNegChannel" , [&]() { return vbs.lepchannel() == 4 and vbs.leadlepID() > 0; }, UNITY);

    ana.cutflow.getCut("PreselChannel"); ana.cutflow.addCutToLastActiveCut("TestEvents", [&]() { return vbs.is_test(); }, UNITY);
    ana.cutflow.getCut("PreselChannel"); ana.cutflow.addCutToLastActiveCut("TrainEvents", [&]() { return vbs.is_train(); }, UNITY);

    // Selecting channels of interest
    std::vector<TString> channels =
        {
            // All channels
            "Presel",
            "PSEE",
            "PSEM",
            "PSMM",
            "PSLL",
            "PSET",
            "PSMT",
            "PSLT",
            "PSEl",
            "PSMu",
            "PSTau", 
            "PSNeg", 
            "PSMTPos",
            "PSMTNeg",

            "LooseVR", // All channels included
            "LL",
            "EE",
            "EM",
            "MM",
            "ET",
            "MT",
            "LT",

            "El",
            "Mu",
            "Lgt",
            "Tau",
            "Neg",
        };

    std::vector<std::pair<TString, std::function<bool()>>> kin_regs = {
        std::make_pair("MbbOn",   [&]() { return      (vbs.b0()+vbs.b1()).mass() < 150. and (vbs.b0()+vbs.b1()).mass() > 0.; }),
        std::make_pair("MbbOff",  [&]() { return not (vbs.mbb() <= 150); }),
        // std::make_pair("MbbOff",  [&]() { return not ((vbs.b0()+vbs.b1()).mass() < 150. and (vbs.b0()+vbs.b1()).mass() > 0.); }),
        std::make_pair("MbbAll",  UNITY),
    };

    // Looping over channels of interest and adding kinematic selections
    for (auto& channel : channels)
    {
        for (auto& kin_reg : kin_regs)
        {
            // Create starting point
            ana.cutflow.getCut(TString::Format("%sChannel", channel.Data())); ana.cutflow.addCutToLastActiveCut(TString::Format("%s%s", channel.Data(), kin_reg.first.Data()), kin_reg.second, UNITY );

            // Add SR and VR
            ana.cutflow.getCut(TString::Format("%s%s", channel.Data(), kin_reg.first.Data())); ana.cutflow.addCutToLastActiveCut(TString::Format("%s%sPS"   , channel.Data(), kin_reg.first.Data()), UNITY, UNITY );
            ana.cutflow.getCut(TString::Format("%s%s", channel.Data(), kin_reg.first.Data())); ana.cutflow.addCutToLastActiveCut(TString::Format("%s%sSR"   , channel.Data(), kin_reg.first.Data()), [&]() { return         vbs.lt() > CLTHI and vbs.st() > CSTHI   and vbs.detajj() > CDETAJJ; } , UNITY );
            ana.cutflow.getCut(TString::Format("%s%s", channel.Data(), kin_reg.first.Data())); ana.cutflow.addCutToLastActiveCut(TString::Format("%s%sSR2"  , channel.Data(), kin_reg.first.Data()), [&]() { return   (not (vbs.lt() > CLTHI and vbs.st() > CSTHI)) and vbs.detajj() > CDETAJJ and vbs.lt() > CLTLO and vbs.st() > CLTLO; } , UNITY );
            ana.cutflow.getCut(TString::Format("%s%s", channel.Data(), kin_reg.first.Data())); ana.cutflow.addCutToLastActiveCut(TString::Format("%s%sVR1"  , channel.Data(), kin_reg.first.Data()), [&]() { return vbs.lt() > CLTLO; } , UNITY );
            ana.cutflow.getCut(TString::Format("%s%s", channel.Data(), kin_reg.first.Data())); ana.cutflow.addCutToLastActiveCut(TString::Format("%s%sVR2"  , channel.Data(), kin_reg.first.Data()), [&]() { return vbs.lt() > CLTMD; } , UNITY );
            ana.cutflow.getCut(TString::Format("%s%s", channel.Data(), kin_reg.first.Data())); ana.cutflow.addCutToLastActiveCut(TString::Format("%s%sVR3"  , channel.Data(), kin_reg.first.Data()), [&]() { return vbs.lt() > CLTHI; } , UNITY );
            ana.cutflow.getCut(TString::Format("%s%s", channel.Data(), kin_reg.first.Data())); ana.cutflow.addCutToLastActiveCut(TString::Format("%s%sVR4"  , channel.Data(), kin_reg.first.Data()), [&]() { return vbs.lt() > CSTLO; } , UNITY );
            ana.cutflow.getCut(TString::Format("%s%s", channel.Data(), kin_reg.first.Data())); ana.cutflow.addCutToLastActiveCut(TString::Format("%s%sVR5"  , channel.Data(), kin_reg.first.Data()), [&]() { return vbs.st() > CSTMD; } , UNITY );
            ana.cutflow.getCut(TString::Format("%s%s", channel.Data(), kin_reg.first.Data())); ana.cutflow.addCutToLastActiveCut(TString::Format("%s%sVR6"  , channel.Data(), kin_reg.first.Data()), [&]() { return vbs.st() > CSTHI; } , UNITY );
            ana.cutflow.getCut(TString::Format("%s%s", channel.Data(), kin_reg.first.Data())); ana.cutflow.addCutToLastActiveCut(TString::Format("%s%sVR7"  , channel.Data(), kin_reg.first.Data()), [&]() { return vbs.detajj() > CDETAJJ; } , UNITY );
            ana.cutflow.getCut(TString::Format("%s%s", channel.Data(), kin_reg.first.Data())); ana.cutflow.addCutToLastActiveCut(TString::Format("%s%sVR8"  , channel.Data(), kin_reg.first.Data()), [&]() { return vbs.mjj() > CMJJ; } , UNITY );
            ana.cutflow.getCut(TString::Format("%s%s", channel.Data(), kin_reg.first.Data())); ana.cutflow.addCutToLastActiveCut(TString::Format("%s%sSRB"  , channel.Data(), kin_reg.first.Data()), [&]() { return         vbs.bdt() > CBDT; } , UNITY );
            ana.cutflow.getCut(TString::Format("%s%s", channel.Data(), kin_reg.first.Data())); ana.cutflow.addCutToLastActiveCut(TString::Format("%s%sSRA"  , channel.Data(), kin_reg.first.Data()),
                                                                                                     [&]()
                                                                                                     {
                                                                                                         // Always pass VBF selection
                                                                                                         if (vbs.mjj() > CMJJ and vbs.detajj() > CDETAJJ)
                                                                                                         {
                                                                                                             // High purity
                                                                                                             if (vbs.lt() > CLTHI and vbs.st() > CSTHI)
                                                                                                             {
                                                                                                                 return true;
                                                                                                             }
                                                                                                             // Medium purity
                                                                                                             else if (vbs.lt() > CLTLO and vbs.st() > CSTLO)
                                                                                                             {
                                                                                                                 // Only accept e and mu
                                                                                                                 if (vbs.categ() == 0 or vbs.categ() == 1)
                                                                                                                     return true;
                                                                                                                 else
                                                                                                                     return false;
                                                                                                             }
                                                                                                             else
                                                                                                             {
                                                                                                                 return false;
                                                                                                             }
                                                                                                         }
                                                                                                         else
                                                                                                         {
                                                                                                             return false;
                                                                                                         }
                                                                                                     } , UNITY );
        }
    }

    ana.histograms.addHistogram("NCenJet30"       , 9   , 0       , 9                                 , [&]() { return vbs.ncenjet30(); } );
    ana.histograms.addHistogram("NJet30"          , 9   , 0       , 9                                 , [&]() { return vbs.njet30(); } );
    ana.histograms.addHistogram("LT"              , 180 , 0       , 2500                              , [&]() { return vbs.lt(); } );
    ana.histograms.addHistogram("ST"              , 180 , 0       , 3500                              , [&]() { return vbs.st(); } );
    ana.histograms.addHistogram("LTVarBin"        , {0., CLTLO, CLTHI, 750}                           , [&]() { return vbs.lt(); } );
    ana.histograms.addHistogram("STVarBin"        , {0., CSTLO, CSTHI, 1500}                          , [&]() { return vbs.st(); } );
    ana.histograms.addHistogram("LTVarBin2"       , {0., CLTLO, CLTMD, CLTHI, 750}                    , [&]() { return vbs.lt(); } );
    ana.histograms.addHistogram("STVarBin2"       , {0., CSTLO, CSTMD, CSTHI, 1500}                   , [&]() { return vbs.st(); } );
    ana.histograms.addHistogram("LTZoom"          , 180 , 0       ,  750                              , [&]() { return vbs.lt(); } );
    ana.histograms.addHistogram("STZoom"          , 180 , 0       , 1500                              , [&]() { return vbs.st(); } );
    ana.histograms.addHistogram("LeptonPt0"       , 180 , 0       , 1000                              , [&]() { return vbs.l0pt(); } );
    ana.histograms.addHistogram("LeptonPt1"       , 180 , 0       , 600                               , [&]() { return vbs.l1pt(); } );
    ana.histograms.addHistogram("LeptonPt0Zoom"   , 180 , 0       , 250                               , [&]() { return vbs.l0pt(); } );
    ana.histograms.addHistogram("LeptonPt1Zoom"   , 180 , 0       , 250                               , [&]() { return vbs.l1pt(); } );
    ana.histograms.addHistogram("LeptonPtAZoom"   , 180 , 0       , 250                               , [&]() { return vbs.lep0().pt(); } );
    ana.histograms.addHistogram("LeptonPtBZoom"   , 180 , 0       , 250                               , [&]() { return vbs.lep1().pt(); } );
    ana.histograms.addHistogram("LeptonEta0"      , 180 , -3      , 3                                 , [&]() { return vbs.leadlep().eta(); } );
    ana.histograms.addHistogram("LeptonEta1"      , 180 , -3      , 3                                 , [&]() { return vbs.subllep().eta(); } );
    ana.histograms.addHistogram("MJJ"             , 180 , 0       , 4500                              , [&]() { return vbs.mjj(); } );
    ana.histograms.addHistogram("MJJZoom"         , 180 , 0       , 2500                              , [&]() { return vbs.mjj(); } );
    ana.histograms.addHistogram("MJJVarBin"       , {0., CMJJ, 1200., 2500}                           , [&]() { return vbs.mjj(); } );
    ana.histograms.addHistogram("DEtaJJ"          , 180 , 0       , 10                                , [&]() { return vbs.detajj(); } );
    ana.histograms.addHistogram("DEtaJJVarBin"    , {0., 3., CDETAJJ, 10.}                            , [&]() { return vbs.detajj(); } );
    ana.histograms.addHistogram("JetPt0"          , 180 , 0       , 250                               , [&]() { return vbs.j0().pt(); } );
    ana.histograms.addHistogram("JetPt1"          , 180 , 0       , 150                               , [&]() { return vbs.j1().pt(); } );
    ana.histograms.addHistogram("JetEta0"         , 180 , -5      , 5                                 , [&]() { return vbs.j0().eta(); } );
    ana.histograms.addHistogram("JetEta1"         , 180 , -5      , 5                                 , [&]() { return vbs.j1().eta(); } );
    ana.histograms.addHistogram("BJetPt0"         , 180 , 0       , 450                               , [&]() { return vbs.b0().pt(); } );
    ana.histograms.addHistogram("BJetPt1"         , 180 , 0       , 250                               , [&]() { return vbs.b1().pt(); } );
    ana.histograms.addHistogram("Ptbb"            , 180 , 0       , 2000                              , [&]() { return vbs.ptbb(); } );
    ana.histograms.addHistogram("MET"             , 180 , 0       , 500                               , [&]() { return vbs.met(); } );
    ana.histograms.addHistogram("MbbZoom"         , 180 , 0       , 300                               , [&]() { return vbs.mbb(); } );
    ana.histograms.addHistogram("Mbb"             , 180 , 0       , 600                               , [&]() { return vbs.mbb(); } );
    ana.histograms.addHistogram("BDT"             , 180 , CBDT-0.3, CBDT+0.3                          , [&]() { return vbs.bdt(); } );
    ana.histograms.addHistogram("BDTBkg"          , 180 , CBDT-0.3, CBDT                              , [&]() { return vbs.bdt(); } );
    ana.histograms.addHistogram("BDTVarBin"       , {CBDT-0.3,            CBDT-0.18, CBDT-0.12, CBDT} , [&]() { return vbs.bdt(); } );
    ana.histograms.addHistogram("BDTVarBin2"      , {CBDT-0.3, CBDT-0.24, CBDT-0.18, CBDT-0.12, CBDT} , [&]() { return vbs.bdt(); } );
    ana.histograms.addHistogram("BDTMD"           , 180 , CBDT-0.3, CBDT+0.3                          , [&]() { return vbs.bdt_mbboff(); } );
    ana.histograms.addHistogram("Yield"           , 1   , 0       , 1                                 , [&]() { return 0; } );
    ana.histograms.addHistogram("Channels4Bins"   , 4   , 0       , 4                                 , [&]() { return vbs.categ(); } );
    ana.histograms.addHistogram("ChannelsDetails" , 32  , 0       , 32                                , [&]() { return 16 * (vbs.leadlepID() < 0) + vbs.channeldetail(); } );

    ana.histograms.addHistogram("ChannelsDetails2", 24, 0, 24,
                                [&]()
                                {

                                    if (vbs.btagchannel() == 0)
                                    {
                                        if (vbs.leadlepID() > 0)
                                        {
                                            if (abs(vbs.leadlepID()) == 11 and abs(vbs.subllepID()) == 11)      return 0;
                                            else if (abs(vbs.leadlepID()) == 11 and abs(vbs.subllepID()) == 13) return 1;
                                            else if (abs(vbs.leadlepID()) == 13 and abs(vbs.subllepID()) == 11) return 2;
                                            else if (abs(vbs.leadlepID()) == 13 and abs(vbs.subllepID()) == 13) return 3;

                                            else if (abs(vbs.leadlepID()) == 11 and abs(vbs.subllepID()) == 15) return 16;
                                            else if (abs(vbs.leadlepID()) == 15 and abs(vbs.subllepID()) == 11) return 17;
                                            else if (abs(vbs.leadlepID()) == 13 and abs(vbs.subllepID()) == 15) return 18;
                                            else if (abs(vbs.leadlepID()) == 15 and abs(vbs.subllepID()) == 13) return 19;
                                        }
                                        else
                                        {
                                            if (abs(vbs.leadlepID()) == 11 and abs(vbs.subllepID()) == 11)      return 4;
                                            else if (abs(vbs.leadlepID()) == 11 and abs(vbs.subllepID()) == 13) return 5;
                                            else if (abs(vbs.leadlepID()) == 13 and abs(vbs.subllepID()) == 11) return 6;
                                            else if (abs(vbs.leadlepID()) == 13 and abs(vbs.subllepID()) == 13) return 7;

                                            else if (abs(vbs.leadlepID()) == 11 and abs(vbs.subllepID()) == 15) return 20;
                                            else if (abs(vbs.leadlepID()) == 15 and abs(vbs.subllepID()) == 11) return 21;
                                            else if (abs(vbs.leadlepID()) == 13 and abs(vbs.subllepID()) == 15) return 22;
                                            else if (abs(vbs.leadlepID()) == 15 and abs(vbs.subllepID()) == 13) return 23;
                                        }
                                    }
                                    else
                                    {
                                        if (vbs.leadlepID() > 0)
                                        {
                                            if (abs(vbs.leadlepID()) == 11 and abs(vbs.subllepID()) == 11)      return 8;
                                            else if (abs(vbs.leadlepID()) == 11 and abs(vbs.subllepID()) == 13) return 9;
                                            else if (abs(vbs.leadlepID()) == 13 and abs(vbs.subllepID()) == 11) return 10;
                                            else if (abs(vbs.leadlepID()) == 13 and abs(vbs.subllepID()) == 13) return 11;
                                        }
                                        else
                                        {
                                            if (abs(vbs.leadlepID()) == 11 and abs(vbs.subllepID()) == 11)      return 12;
                                            else if (abs(vbs.leadlepID()) == 11 and abs(vbs.subllepID()) == 13) return 13;
                                            else if (abs(vbs.leadlepID()) == 13 and abs(vbs.subllepID()) == 11) return 14;
                                            else if (abs(vbs.leadlepID()) == 13 and abs(vbs.subllepID()) == 13) return 15;
                                        }
                                    }
                                    return -999;
                                } );
    ana.histograms.addHistogram("Channels5Bins", 5, 0, 5,
                                [&]()
                                {
                                    // Always pass VBF selection
                                    if (vbs.mjj() > CMJJ and vbs.detajj() > CDETAJJ)
                                    {
                                        // High purity
                                        if (vbs.lt() > CLTHI and vbs.st() > CSTHI)
                                        {
                                            return vbs.categ();
                                        }
                                        // Medium purity
                                        else if (vbs.lt() > CLTLO and vbs.st() > CSTLO)
                                        {
                                            // Only accept e and mu
                                            if (vbs.categ() == 0 or vbs.categ() == 1)
                                                return 4;
                                            else
                                                return -999;
                                        }
                                        else
                                        {
                                            return -999;
                                        }
                                    }
                                    else
                                    {
                                        return -999;
                                    }
                                } );

    ana.histograms.addVecHistogram("VRs", 18, 0, 18,
                                [&]()
                                {
                                    std::vector<float> bins;
                                    if (abs(vbs.leadlepID()) == 15 or abs(vbs.subllepID()) == 15)
                                    {
                                                                    bins.push_back(9);
                                        if (vbs.lt()     > CLTLO)   bins.push_back(10);
                                        if (vbs.lt()     > CLTMD)   bins.push_back(11);
                                        if (vbs.lt()     > CLTHI)   bins.push_back(12);
                                        if (vbs.st()     > CSTLO)   bins.push_back(13);
                                        if (vbs.st()     > CSTMD)   bins.push_back(14);
                                        if (vbs.st()     > CSTHI)   bins.push_back(15);
                                        if (vbs.detajj() > CDETAJJ) bins.push_back(17);
                                        if (vbs.mjj()    > CMJJ)    bins.push_back(16);
                                    }
                                    else
                                    {
                                                                    bins.push_back(0);
                                        if (vbs.lt()     > CLTLO)   bins.push_back(1);
                                        if (vbs.lt()     > CLTMD)   bins.push_back(2);
                                        if (vbs.lt()     > CLTHI)   bins.push_back(3);
                                        if (vbs.st()     > CSTLO)   bins.push_back(4);
                                        if (vbs.st()     > CSTMD)   bins.push_back(5);
                                        if (vbs.st()     > CSTHI)   bins.push_back(6);
                                        if (vbs.detajj() > CDETAJJ) bins.push_back(8);
                                        if (vbs.mjj()    > CMJJ)    bins.push_back(7);
                                    }
                                    return bins;
                                } );
    ana.histograms.addVecHistogram("SRs", 5, 0, 5,
                                [&]()
                                {
                                    std::vector<float> bins;
                                    if (vbs.mjj() > CMJJ and vbs.detajj() > CDETAJJ)
                                    {
                                        if (vbs.lt() > CLTHI and vbs.st() > CSTHI)
                                        {
                                            bins.push_back(vbs.categ());
                                        }
                                        else if (vbs.lt() > CLTLO and vbs.st() > CSTLO)
                                        {
                                            if (vbs.categ() == 0 or vbs.categ() == 1)
                                                bins.push_back(4);
                                        }
                                    }
                                    return bins;
                                } );
    ana.histograms.addVecHistogram("VRsLT",  9, 0,  9,
                                [&]()
                                {
                                    std::vector<float> bins;
                                    if (abs(vbs.leadlepID()) == 15 or abs(vbs.subllepID()) == 15)
                                    {
                                        bins.push_back(0);
                                        if (vbs.lt()     > CLTLO)   bins.push_back(1);
                                        if (vbs.lt()     > CLTMD)   bins.push_back(2);
                                        if (vbs.lt()     > CLTHI)   bins.push_back(3);
                                        if (vbs.st()     > CSTLO)   bins.push_back(4);
                                        if (vbs.st()     > CSTMD)   bins.push_back(5);
                                        if (vbs.st()     > CSTHI)   bins.push_back(6);
                                        if (vbs.detajj() > CDETAJJ) bins.push_back(8);
                                        if (vbs.mjj()    > CMJJ)    bins.push_back(7);
                                    }
                                    return bins;
                                } );
    ana.histograms.addVecHistogram("VRsLL",  9, 0,  9,
                                [&]()
                                {
                                    std::vector<float> bins;
                                    if (not (abs(vbs.leadlepID()) == 15 or abs(vbs.subllepID()) == 15))
                                    {
                                        bins.push_back(0);
                                        if (vbs.lt()     > CLTLO)   bins.push_back(1);
                                        if (vbs.lt()     > CLTMD)   bins.push_back(2);
                                        if (vbs.lt()     > CLTHI)   bins.push_back(3);
                                        if (vbs.st()     > CSTLO)   bins.push_back(4);
                                        if (vbs.st()     > CSTMD)   bins.push_back(5);
                                        if (vbs.st()     > CSTHI)   bins.push_back(6);
                                        if (vbs.detajj() > CDETAJJ) bins.push_back(8);
                                        if (vbs.mjj()    > CMJJ)    bins.push_back(7);
                                    }
                                    return bins;
                                } );

    // Print cut structure
    ana.cutflow.printCuts();

    // Book cutflows
    ana.cutflow.bookCutflows();

    // Book Histograms
    ana.cutflow.bookHistogramsForCutAndBelow(ana.histograms, "PreselChannel");

    ana.cutflow.bookEventLists();

    // Looping input file
    while (ana.looper.nextEvent())
    {

        // If splitting jobs are requested then determine whether to process the event or not based on remainder
        if (result.count("job_index") and result.count("nsplit_jobs"))
        {
            if (ana.looper.getNEventsProcessed() % ana.nsplit_jobs != (unsigned int) ana.job_index)
                continue;
        }

        ana.cutflow.setEventID(vbs.run(), vbs.lumi(), vbs.evt()); // Setting event ID in case we need to keep track of event id

        //Do what you need to do in for each event here
        //To save use the following function
        ana.cutflow.fill();
    }

    // Writing output file
    ana.cutflow.saveOutput();

    // ana.cutflow.getCut("EEMbbAll").writeEventList("list.txt");

    // The below can be sometimes crucial
    delete ana.output_tfile;
}





    // // Defining histograms
    // ana.histograms.addHistogram("NCenJet30"           , 9   , 0       , 9      , [&]() { return vbs.ncenjet30();                                                             } );
    // ana.histograms.addHistogram("NJet30"              , 9   , 0       , 9      , [&]() { return vbs.njet30();                                                                } );
    // ana.histograms.addHistogram("NBLoose"             , 5   , 0       , 5      , [&]() { return vbs.nbloose();                                                               } );
    // ana.histograms.addHistogram("NBMedium"            , 5   , 0       , 5      , [&]() { return vbs.nbmedium();                                                              } );
    // ana.histograms.addHistogram("NBTight"             , 5   , 0       , 5      , [&]() { return vbs.nbtight();                                                               } );
    // ana.histograms.addHistogram("LeptonPt0"           , 180 , 0       , 600    , [&]() { return vbs.leadlep().pt();                                                          } );
    // ana.histograms.addHistogram("LeptonPt1"           , 180 , 0       , 600    , [&]() { return vbs.subllep().pt();                                                          } );
    // ana.histograms.addHistogram("LeptonPt0Zoom"       , 180 , 0       , 250    , [&]() { return vbs.leadlep().pt();                                                          } );
    // ana.histograms.addHistogram("LeptonPt1Zoom"       , 180 , 0       , 250    , [&]() { return vbs.subllep().pt();                                                          } );
    // ana.histograms.addHistogram("LeptonEta0"          , 180 , -3      , 3      , [&]() { return vbs.leadlep().eta();                                                         } );
    // ana.histograms.addHistogram("LeptonEta1"          , 180 , -3      , 3      , [&]() { return vbs.subllep().eta();                                                         } );
    // ana.histograms.addHistogram("LeptonPhi0"          , 180 , -3.1416 , 3.1416 , [&]() { return vbs.leadlep().phi();                                                         } );
    // ana.histograms.addHistogram("LeptonPhi1"          , 180 , -3.1416 , 3.1416 , [&]() { return vbs.subllep().phi();                                                         } );
    // ana.histograms.addHistogram("LeptonPtFlavor0"     , 180 , 0       , 600    , [&]() { return vbs.lep0().pt();                                                             } );
    // ana.histograms.addHistogram("LeptonPtFlavor1"     , 180 , 0       , 600    , [&]() { return vbs.lep1().pt();                                                             } );
    // ana.histograms.addHistogram("LeptonPtFlavor0Zoom" , 180 , 0       , 250    , [&]() { return vbs.lep0().pt();                                                             } );
    // ana.histograms.addHistogram("LeptonPtFlavor1Zoom" , 180 , 0       , 250    , [&]() { return vbs.lep1().pt();                                                             } );
    // ana.histograms.addHistogram("LeptonEtaFlavor0"    , 180 , -3      , 3      , [&]() { return vbs.lep0().eta();                                                            } );
    // ana.histograms.addHistogram("LeptonEtaFlavor1"    , 180 , -3      , 3      , [&]() { return vbs.lep1().eta();                                                            } );
    // ana.histograms.addHistogram("LeptonPhiFlavor0"    , 180 , -3.1416 , 3.1416 , [&]() { return vbs.lep0().phi();                                                            } );
    // ana.histograms.addHistogram("LeptonPhiFlavor1"    , 180 , -3.1416 , 3.1416 , [&]() { return vbs.lep1().phi();                                                            } );
    // ana.histograms.addHistogram("JetPt0"              , 180 , 0       , 250    , [&]() { return vbs.j0().pt();                                                               } );
    // ana.histograms.addHistogram("JetPt1"              , 180 , 0       , 250    , [&]() { return vbs.j1().pt();                                                               } );
    // ana.histograms.addHistogram("JetEta0"             , 180 , -5      , 5      , [&]() { return vbs.j0().eta();                                                              } );
    // ana.histograms.addHistogram("JetEta1"             , 180 , -5      , 5      , [&]() { return vbs.j1().eta();                                                              } );
    // ana.histograms.addHistogram("AbsJetEta0"          , 180 , 0       , 5      , [&]() { return fabs(vbs.j0().eta());                                                        } );
    // ana.histograms.addHistogram("AbsJetEta1"          , 180 , 0       , 5      , [&]() { return fabs(vbs.j1().eta());                                                        } );
    // ana.histograms.addHistogram("JetPhi0"             , 180 , -3.1416 , 3.1416 , [&]() { return vbs.j0().phi();                                                              } );
    // ana.histograms.addHistogram("JetPhi1"             , 180 , -3.1416 , 3.1416 , [&]() { return vbs.j1().phi();                                                              } );
    // ana.histograms.addHistogram("BJetPt0"             , 180 , 0       , 450    , [&]() { return vbs.b0().pt();                                                               } );
    // ana.histograms.addHistogram("BJetPt1"             , 180 , 0       , 250    , [&]() { return vbs.b1().pt();                                                               } );
    // ana.histograms.addHistogram("BJetEta0"            , 180 , -5      , 5      , [&]() { return vbs.b0().eta();                                                              } );
    // ana.histograms.addHistogram("BJetEta1"            , 180 , -5      , 5      , [&]() { return vbs.b1().eta();                                                              } );
    // ana.histograms.addHistogram("BJetPhi0"            , 180 , -3.1416 , 3.1416 , [&]() { return vbs.b0().phi();                                                              } );
    // ana.histograms.addHistogram("BJetPhi1"            , 180 , -3.1416 , 3.1416 , [&]() { return vbs.b1().phi();                                                              } );
    // ana.histograms.addHistogram("BJetScore0"          , 180 , 0       , 1      , [&]() { return vbs.higgs_jets_btag_score()[0];                                              } );
    // ana.histograms.addHistogram("BJetScore1"          , 180 , 0       , 1      , [&]() { return vbs.higgs_jets_btag_score()[1];                                              } );
    // ana.histograms.addHistogram("BJetLeadScore0"      , 180 , 0       , 1      , [&]() { return vbs.higgs_jets_btag_score()[0] > vbs.higgs_jets_btag_score()[1] ? vbs.higgs_jets_btag_score()[0] : vbs.higgs_jets_btag_score()[1]; } );
    // ana.histograms.addHistogram("BJetSublScore1"      , 180 , 0       , 1      , [&]() { return vbs.higgs_jets_btag_score()[0] > vbs.higgs_jets_btag_score()[1] ? vbs.higgs_jets_btag_score()[1] : vbs.higgs_jets_btag_score()[0]; } );
    // ana.histograms.addHistogram("PtJJ"                , 180 , 0       , 250    , [&]() { return (vbs.j0()+vbs.j1()).pt();                                                    } );
    // ana.histograms.addHistogram("MJJ"                 , 180 , 0       , 4500   , [&]() { return (vbs.j0()+vbs.j1()).mass();                                                  } );
    // ana.histograms.addHistogram("MJJMed"              , 180 , 0       , 2000   , [&]() { return (vbs.j0()+vbs.j1()).mass();                                                  } );
    // ana.histograms.addHistogram("MJJLow"              , 180 , 0       , 350    , [&]() { return (vbs.j0()+vbs.j1()).mass();                                                  } );
    // ana.histograms.addHistogram("DEtaJJ"              , 180 , 0       , 8      , [&]() { return fabs(RooUtil::Calc::DeltaEta(vbs.j0(), vbs.j1()));                           } );
    // ana.histograms.addHistogram("DPhiJJ"              , 180 , 0       , 3.1416 , [&]() { return fabs(RooUtil::Calc::DeltaPhi(vbs.j0(), vbs.j1()));                           } );
    // ana.histograms.addHistogram("HiggsPt"             , 180 , 0       , 1000   , [&]() { return (vbs.b0()+vbs.b1()).pt();                                                    } );
    // ana.histograms.addHistogram("HiggsPtLow"          , 180 , 0       , 350    , [&]() { return (vbs.b0()+vbs.b1()).pt();                                                    } );
    // ana.histograms.addHistogram("DPhill"              , 180 , 0       , 3.1416 , [&]() { return fabs(RooUtil::Calc::DeltaPhi(vbs.leadlep(), vbs.subllep()));                 } );
    // ana.histograms.addHistogram("DEtall"              , 180 , 0       , 7      , [&]() { return fabs(RooUtil::Calc::DeltaEta(vbs.leadlep(), vbs.subllep()));                 } );
    // ana.histograms.addHistogram("DRll"                , 180 , 0       , 7      , [&]() { return fabs(RooUtil::Calc::DeltaR(vbs.leadlep(), vbs.subllep()));                   } );
    // ana.histograms.addHistogram("Mll"                 , 180 , 0       , 2000   , [&]() { return (vbs.leadlep()+vbs.subllep()).mass();                                        } );
    // ana.histograms.addHistogram("MllLow"              , 180 , 0       , 250    , [&]() { return (vbs.leadlep()+vbs.subllep()).mass();                                        } );
    // ana.histograms.addHistogram("Mbb"                 , 180 , 0       , 300    , [&]() { return (vbs.b0()+vbs.b1()).mass();                                                  } );
    // ana.histograms.addHistogram("MbbMax"              , 180 , 0       , 600    , [&]() { return (vbs.b0()+vbs.b1()).mass();                                                  } );
    // ana.histograms.addHistogram("MbbInOut"            , 2   , 0       , 2      , [&]() { return (vbs.b0()+vbs.b1()).mass() < 150 and (vbs.b0()+vbs.b1()).mass() > 0.;        } );
    // ana.histograms.addHistogram("MbbInOutV1"          , 2   , 0       , 2      , [&]() { return (vbs.b0()+vbs.b1()).mass() < 140 and (vbs.b0()+vbs.b1()).mass() > 90.;       } );
    // ana.histograms.addHistogram("DRbb"                , 180 , 0       , 6      , [&]() { return RooUtil::Calc::DeltaR(vbs.b0(), vbs.b1());                                   } );
    // ana.histograms.addHistogram("DEtabb"              , 180 , 0       , 6      , [&]() { return fabs(RooUtil::Calc::DeltaEta(vbs.b0(), vbs.b1()));                           } );
    // ana.histograms.addHistogram("DPhibb"              , 180 , 0       , 6      , [&]() { return fabs(RooUtil::Calc::DeltaPhi(vbs.b0(), vbs.b1()));                           } );
    // ana.histograms.addHistogram("MET"                 , 180 , 0       , 1500   , [&]() { return vbs.met_p4().pt();                                                           } );
    // ana.histograms.addHistogram("METLow"              , 180 , 0       , 250    , [&]() { return vbs.met_p4().pt();                                                           } );
    // ana.histograms.addHistogram("Channels"            , 8   , 0       , 8      , [&]() { return vbs.channel();                                                               } );
    // ana.histograms.addHistogram("ChannelsDetails"     , 16  , 0       , 16     , [&]() { return vbs.channeldetail();                                                         } );
    // ana.histograms.addHistogram("ChannelsMbbMerged"   , 8   , 0       , 8      , [&]() { return vbs.channeldetail() / 2;                                                     } );
    // ana.histograms.addHistogram("MVVH"                , 180 , 0       , 2500   , [&]() { return vbs.mvvh(); } );
    // ana.histograms.addHistogram("ST"                  , 180 , 0       , 2500   , [&]() { return vbs.st(); } );
    // ana.histograms.addHistogram("LT"                  , 180 , 0       , 2500   , [&]() { return vbs.lt(); } );
    // ana.histograms.addHistogram("LTVarBin"            , {0., 300., 500., 2500} , [&]() { return vbs.lt(); } );
    // ana.histograms.addHistogram("STZoom"              , 180 , 0       , 1500   , [&]() { return vbs.st(); } );
    // ana.histograms.addHistogram("LTZoom"              , 180 , 0       ,  700   , [&]() { return vbs.lt(); } );
    // ana.histograms.addHistogram("BDT"                 , 180 , -1      ,  1     , [&]() { return vbs.bdt();                                                   } );
    // ana.histograms.addHistogram("BDTMbbOff"           , 180 , -1      ,  1     , [&]() { return vbs.bdt_mbboff();                                            } );

    // ana.histograms.addHistogram("MinDRlb"             , 180 , 0       , 6      , [&]()
    //                             {
    //                                 return
    //                                 std::min(
    //                                     RooUtil::Calc::DeltaR(vbs.lep1(), vbs.b0()),
    //                                     std::min(
    //                                         RooUtil::Calc::DeltaR(vbs.lep1(), vbs.b1()),
    //                                         std::min(
    //                                             RooUtil::Calc::DeltaR(vbs.lep0(), vbs.b0()),
    //                                             RooUtil::Calc::DeltaR(vbs.lep0(), vbs.b1())
    //                                             )
    //                                         )
    //                                     );
    //                             } );
    // ana.histograms.addHistogram("MaxDRlb"             , 180 , 0       , 6      , [&]()
    //                             {
    //                                 return
    //                                 std::max(
    //                                     RooUtil::Calc::DeltaR(vbs.lep1(), vbs.b0()),
    //                                     std::max(
    //                                         RooUtil::Calc::DeltaR(vbs.lep1(), vbs.b1()),
    //                                         std::max(
    //                                             RooUtil::Calc::DeltaR(vbs.lep0(), vbs.b0()),
    //                                             RooUtil::Calc::DeltaR(vbs.lep0(), vbs.b1())
    //                                             )
    //                                         )
    //                                     );
    //                             } );
    // ana.histograms.addHistogram("MinMaxRatioDRlb"             , 180 , 0       , 1      , [&]()
    //                             {
    //                                 return
    //                                 std::min(
    //                                     RooUtil::Calc::DeltaR(vbs.lep1(), vbs.b0()),
    //                                     std::min(
    //                                         RooUtil::Calc::DeltaR(vbs.lep1(), vbs.b1()),
    //                                         std::min(
    //                                             RooUtil::Calc::DeltaR(vbs.lep0(), vbs.b0()),
    //                                             RooUtil::Calc::DeltaR(vbs.lep0(), vbs.b1())
    //                                             )
    //                                         )
    //                                     ) /
    //                                 std::max(
    //                                     RooUtil::Calc::DeltaR(vbs.lep1(), vbs.b0()),
    //                                     std::max(
    //                                         RooUtil::Calc::DeltaR(vbs.lep1(), vbs.b1()),
    //                                         std::max(
    //                                             RooUtil::Calc::DeltaR(vbs.lep0(), vbs.b0()),
    //                                             RooUtil::Calc::DeltaR(vbs.lep0(), vbs.b1())
    //                                             )
    //                                         )
    //                                     );
    //                             } );
    // ana.histograms.addHistogram("Yield"               , 1   , 0       , 1      , [&]() { return 0; } );
    // ana.histograms.addHistogram("Channels4Bins"       , 4   , 0       , 4      ,
    //                             [&]()
    //                             {
    //                                 if ((vbs.leadlepID() < 0) and (vbs.lepchannel()  == 0 or (vbs.lepchannel() == 1 and abs(vbs.leadlepID()) == 11)))
    //                                     return 0;
    //                                 else if ((vbs.leadlepID() < 0) and (vbs.lepchannel()  == 2 or (vbs.lepchannel() == 1 and abs(vbs.leadlepID()) == 13)))
    //                                     return 1;
    //                                 else if ((vbs.leadlepID() < 0) and (vbs.btagchannel() == 0 and vbs.lepchannel() >= 3 and vbs.lepchannel() <= 4))
    //                                     return 2;
    //                                 else if ((vbs.leadlepID() > 0))
    //                                     return 3;
    //                                 else
    //                                     return -999;
    //                             } );
    // ana.histograms.addHistogram("Channels8Bins"       , 8   , 0       , 8      ,
    //                             [&]()
    //                             {
    //                                 if ((vbs.leadlepID() < 0) and (vbs.lepchannel()  == 0 or (vbs.lepchannel() == 1 and abs(vbs.leadlepID()) == 11)))
    //                                 {
    //                                     if ((vbs.b0()+vbs.b1()).mass() < 150.)
    //                                         return 0;
    //                                     if ((vbs.b0()+vbs.b1()).mass() >= 150.)
    //                                         return 1;
    //                                 }
    //                                 else if ((vbs.leadlepID() < 0) and (vbs.lepchannel()  == 2 or (vbs.lepchannel() == 1 and abs(vbs.leadlepID()) == 13)))
    //                                 {
    //                                     if ((vbs.b0()+vbs.b1()).mass() < 150.)
    //                                         return 2;
    //                                     if ((vbs.b0()+vbs.b1()).mass() >= 150.)
    //                                         return 3;
    //                                 }
    //                                 else if ((vbs.leadlepID() < 0) and (vbs.btagchannel() == 0 and vbs.lepchannel() >= 3 and vbs.lepchannel() <= 4))
    //                                 {
    //                                     if ((vbs.b0()+vbs.b1()).mass() < 150.)
    //                                         return 4;
    //                                     if ((vbs.b0()+vbs.b1()).mass() >= 150.)
    //                                         return 5;
    //                                 }
    //                                 else if ((vbs.leadlepID() > 0))
    //                                 {
    //                                     if ((vbs.b0()+vbs.b1()).mass() < 150.)
    //                                         return 6;
    //                                     if ((vbs.b0()+vbs.b1()).mass() >= 150.)
    //                                         return 7;
    //                                 }
    //                                 else
    //                                 {
    //                                     return -999;
    //                                 }
    //                             } );
    // ana.histograms.addHistogram("MbbInOutv2"          , 3   , 0       , 3      ,
    //                             [&]()
    //                             {
    //                                 if ((vbs.b0()+vbs.b1()).mass() > 150)
    //                                     return 2;
    //                                 else if ((vbs.b0()+vbs.b1()).mass() > 90)
    //                                     return 1;
    //                                 else
    //                                     return 0;
    //                             } );
    // ana.histograms.addVecHistogram("VRs"                 , 6   , 0       , 6      ,
    //                             [&]()
    //                             {
    //                                 std::vector<float> bins;
    //                                 bins.push_back(0);
    //                                 if ((vbs.leadlep().pt() + vbs.subllep().pt() + vbs.met_p4().pt()) > 500.)
    //                                     bins.push_back(1);
    //                                 if ((fabs(RooUtil::Calc::DeltaEta(vbs.j0(), vbs.j1())) > 6.0))
    //                                     bins.push_back(2);
    //                                 if ((vbs.j0() + vbs.j1()).mass() > 1500.)
    //                                     bins.push_back(3);
    //                                 if (vbs.b0().pt() + vbs.b0().pt() + vbs.leadlep().pt() + vbs.subllep().pt() + vbs.met_p4().pt() > 1000.)
    //                                     bins.push_back(4);
    //                                 if (((vbs.b0() + vbs.b1() + vbs.leadlep() + vbs.subllep() + vbs.met_p4()).mass() > 1000.))
    //                                     bins.push_back(5);
    //                                 return bins;
    //                             } );


    // ana.histograms.addHistogram("NCenJet"             , 9   , 0       , 9      , [&]()
    //                             {
    //                                 int njets = 0;
    //                                 const vector<LV>& good_jets_p4 = vbs.good_jets_p4();
    //                                 for (unsigned int i = 0; i < good_jets_p4.size(); i++)
    //                                 {
    //                                     if (vbs.higgs_jets_good_jets_idx()[0] == i) continue;
    //                                     if (vbs.higgs_jets_good_jets_idx()[1] == i) continue;
    //                                     if (vbs.vbs_jets_good_jets_idx()[0] == i) continue;
    //                                     if (vbs.vbs_jets_good_jets_idx()[1] == i) continue;
    //                                     float eta = good_jets_p4[i].eta();
    //                                     float eta0 = vbs.j0().eta();
    //                                     float eta1 = vbs.j1().eta();
    //                                     if ((eta0 - eta) * (eta1 - eta) > 0)
    //                                         continue;
    //                                     njets++;
    //                                 }
    //                                 return njets;
    //                             } );

    // ana.histograms.add2DHistogram("Mbb", 50 , 0 , 300 , "HiggsPt", 50, 0, 600, [&]() { return (vbs.b0()+vbs.b1()).mass(); }, [&]() { return (vbs.b0()+vbs.b1()).pt(); } );
    // ana.histograms.add2DHistogram("Mbb", 50 , 0 , 300 , "DRbb", 50, 0, 6, [&]() { return (vbs.b0()+vbs.b1()).mass(); }, [&]() { return RooUtil::Calc::DeltaR(vbs.b0(), vbs.b1()); } );
    // ana.histograms.add2DHistogram("Mbb", 50 , 0 , 300 , "MJJ", 50, 0, 4500, [&]() { return (vbs.b0()+vbs.b1()).mass(); }, [&]() { return (vbs.j0()+vbs.j1()).mass(); } );
    // ana.histograms.add2DHistogram("Mbb", 50 , 0 , 300 , "DEtaJJ", 50, 0, 6, [&]() { return (vbs.b0()+vbs.b1()).mass(); }, [&]() { return fabs(RooUtil::Calc::DeltaEta(vbs.j0(), vbs.j1())); } );
    // ana.histograms.add2DHistogram("Mbb", 50 , 0 , 300 , "LepPt0", 50, 0, 450, [&]() { return (vbs.b0()+vbs.b1()).mass(); }, [&]() { return vbs.leadlep().pt(); } );
    // ana.histograms.add2DHistogram("Mbb", 50 , 0 , 300 , "LepPt1", 50, 0, 250, [&]() { return (vbs.b0()+vbs.b1()).mass(); }, [&]() { return vbs.subllep().pt(); } );
    // ana.histograms.add2DHistogram("Mbb", 50 , 0 , 300 , "BJetPt0", 50, 0, 450, [&]() { return (vbs.b0()+vbs.b1()).mass(); }, [&]() { return vbs.b0().pt(); } );
    // ana.histograms.add2DHistogram("Mbb", 50 , 0 , 300 , "BJetPt1", 50, 0, 250, [&]() { return (vbs.b0()+vbs.b1()).mass(); }, [&]() { return vbs.b1().pt(); } );
    // ana.histograms.add2DHistogram("Mbb", 50 , 0 , 300 , "ST", 50, 0, 2500, [&]() { return (vbs.b0()+vbs.b1()).mass(); }, [&]() { return vbs.b0().pt() + vbs.b0().pt() + vbs.leadlep().pt() + vbs.subllep().pt() + vbs.met_p4().pt() + vbs.j0().pt() + vbs.j1().pt(); } );
    // ana.histograms.add2DHistogram("Mbb", 50 , 0 , 300 , "MVVH", 50, 0, 2500, [&]() { return (vbs.b0()+vbs.b1()).mass(); }, [&]() { return (vbs.b0() + vbs.b1() + vbs.leadlep() + vbs.subllep() + vbs.met_p4()).mass(); } );
    // ana.histograms.add2DHistogram("MJJ", 50 , 0 , 3000, "MVVH", 50, 0, 2500, [&]() { return (vbs.j0()+vbs.j1()).mass(); }, [&]() { return (vbs.b0() + vbs.b1() + vbs.leadlep() + vbs.subllep() + vbs.met_p4()).mass(); } );
    // ana.histograms.add2DHistogram("MbbMax", 50 , 0 , 700 , "ST", 50, 0, 2500, [&]() { return (vbs.b0()+vbs.b1()).mass(); }, [&]() { return vbs.b0().pt() + vbs.b0().pt() + vbs.leadlep().pt() + vbs.subllep().pt() + vbs.met_p4().pt() + vbs.j0().pt() + vbs.j1().pt(); } );
    // ana.histograms.add2DHistogram("MbbMax", 50 , 0 , 700 , "MVVH", 50, 0, 2500, [&]() { return (vbs.b0()+vbs.b1()).mass(); }, [&]() { return (vbs.b0() + vbs.b1() + vbs.leadlep() + vbs.subllep() + vbs.met_p4()).mass(); } );
    // ana.histograms.add2DHistogram("MbbMax", 50 , 0 , 700 , "HiggsPt", 50, 0, 600, [&]() { return (vbs.b0()+vbs.b1()).mass(); }, [&]() { return (vbs.b0()+vbs.b1()).pt(); } );
    // ana.histograms.add2DHistogram("ST", 50 , 0 , 2500 , "MVVH", 50, 0, 2500, [&]() { return vbs.b0().pt() + vbs.b0().pt() + vbs.leadlep().pt() + vbs.subllep().pt() + vbs.met_p4().pt() + vbs.j0().pt() + vbs.j1().pt(); }, [&]() { return (vbs.b0() + vbs.b1() + vbs.leadlep() + vbs.subllep() + vbs.met_p4()).mass(); } );
    // ana.histograms.add2DHistogram("Mbb", 50 , 0 , 300 , "LT", 50, 0, 2500, [&]() { return (vbs.b0()+vbs.b1()).mass(); }, [&]() { return vbs.leadlep().pt() + vbs.subllep().pt() + vbs.met_p4().pt(); } );
    // ana.histograms.add2DHistogram("MbbMax", 50 , 0 , 700 , "LT", 50, 0, 2500, [&]() { return (vbs.b0()+vbs.b1()).mass(); }, [&]() { return vbs.leadlep().pt() + vbs.subllep().pt() + vbs.met_p4().pt(); } );

    // ana.cutflow.addWgtSyst("TopScaleWgt0", [&]()
    //                        {
    //                            if (
    //                                ana.looper.getCurrentFileName().Contains("tt2lpowheg")
    //                                or ana.looper.getCurrentFileName().Contains("tt1lpowheg")
    //                                )
    //                                return vbs.pswgts()[0];
    //                            else
    //                                return 1;
    //                        });

    // ana.histograms.addVecHistogram("BDT", 180, -1,  1,
    //                                [&]()
    //                                {
    //                                    std::vector<float> rtn =  {vbs.bdt()};
    //                                    return rtn;
    //                                },
    //                                [&]()
    //                                {
    //                                    if (ana.looper.getCurrentFileName().Contains("data.root"))
    //                                    {
    //                                        std::vector<float> rtn = {1.};
    //                                        return rtn;
    //                                    }
    //                                    else
    //                                    {
    //                                        std::vector<float> rtn = {vbs.xsec_sf() * vbs.is_test()};
    //                                        return rtn;
    //                                    }
    //                                });
    // ana.histograms.addVecHistogram("BDTMbb125", 180, -1,  1,
    //                                [&]()
    //                                {
    //                                    std::vector<float> rtn =  {vbs.bdt_mbboff()};
    //                                    return rtn;
    //                                },
    //                                [&]()
    //                                {
    //                                    if (ana.looper.getCurrentFileName().Contains("data.root"))
    //                                    {
    //                                        std::vector<float> rtn = {1.};
    //                                        return rtn;
    //                                    }
    //                                    else
    //                                    {
    //                                        std::vector<float> rtn = {vbs.xsec_sf() * vbs.is_test()};
    //                                        return rtn;
    //                                    }
    //                                });
