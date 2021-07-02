#include "VBS.h"
#include "rooutil.h"
#include "cxxopts.h"
// #include "lester_mt2_bisect.h"

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
    // the "www" object is defined in the wwwtree.h/cc
    // This is an instance which helps read variables in the WWW baby TTree
    // It is a giant wrapper that facilitates reading TBranch values.
    // e.g. if there is a TBranch named "lep_pt" which is a std::vector<float> then, one can access the branch via
    //
    //    std::vector<float> lep_pt = www.lep_pt();
    //
    // and no need for "SetBranchAddress" and declaring variable shenanigans necessary
    // This is a standard thing SNT does pretty much every looper we use
    ana.looper.init(ana.events_tchain, &vbs, ana.n_events);

//********************************************************************************
//
// Interlude... notes on RooUtil framework
//
//********************************************************************************

    // ~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
    // Quick tutorial on RooUtil::Cutflow object cut tree formation
    // ~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
    //
    // The RooUtil::Cutflow object facilitates creating a tree structure of cuts
    //
    // To add cuts to each node of the tree with cuts defined, use "addCut" or "addCutToLastActiveCut"
    // The "addCut" or "addCutToLastActiveCut" accepts three argument, <name>, and two lambda's that define the cut selection, and the weight to apply to that cut stage
    //
    // e.g. To create following cut-tree structure one does
    //
    //             (Root) <--- Always exists as soon as RooUtil::Cutflow object is created. But this is basically hidden underneath and users do not have to care
    //                |
    //            CutWeight
    //            |       |
    //     CutPreSel1    CutPreSel2
    //       |                  |
    //     CutSel1           CutSel2
    //
    //
    //   code:
    //
    //      // Create the object (Root node is created as soon as the instance is created)
    //      RooUtil::Cutflow cutflow;
    //
    //      cutflow.addCut("CutWeight"                 , <lambda> , <lambda>); // CutWeight is added below "Root"-node
    //      cutflow.addCutToLastActiveCut("CutPresel1" , <lambda> , <lambda>); // The last "active" cut is "CutWeight" since I just added that. So "CutPresel1" is added below "CutWeight"
    //      cutflow.addCutToLastActiveCut("CutSel1"    , <lambda> , <lambda>); // The last "active" cut is "CutPresel1" since I just added that. So "CutSel1" is added below "CutPresel1"
    //
    //      cutflow.getCut("CutWeight"); // By "getting" the cut object, this makes the "CutWeight" the last "active" cut.
    //      cutflow.addCutToLastActiveCut("CutPresel2" , <lambda> , <lambda>); // The last "active" cut is "CutWeight" since I "getCut" on it. So "CutPresel2" is added below "CutWeight"
    //      cutflow.addCutToLastActiveCut("CutSel2"    , <lambda> , <lambda>); // The last "active" cut is "CutPresel2" since I just added that. So "CutSel2" is added below "CutPresel1"
    //
    // (Side note: "UNITY" lambda is defined in the framework to just return 1. This so that use don't have to type [&]() {return 1;} so many times.)
    //
    // Once the cutflow is formed, create cutflow histograms can be created by calling RooUtil::Cutflow::bookCutflows())
    // This function looks through the terminating nodes of the tree structured cut tree. and creates a histogram that will fill the yields
    // For the example above, there are two terminationg nodes, "CutSel1", and "CutSel2"
    // So in this case Root::Cutflow::bookCutflows() will create two histograms. (Actually four histograms.)
    //
    //  - TH1F* type object :  CutSel1_cutflow (4 bins, with first bin labeled "Root", second bin labeled "CutWeight", third bin labeled "CutPreSel1", fourth bin labeled "CutSel1")
    //  - TH1F* type object :  CutSel2_cutflow (...)
    //  - TH1F* type object :  CutSel1_rawcutflow (...)
    //  - TH1F* type object :  CutSel2_rawcutflow (...)
    //                                ^
    //                                |
    // NOTE: There is only one underscore "_" between <CutName>_cutflow or <CutName>_rawcutflow
    //
    // And later in the loop when RooUtil::Cutflow::fill() function is called, the tree structure will be traversed through and the appropriate yields will be filled into the histograms
    //
    // After running the loop check for the histograms in the output root file

    // ~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
    // Quick tutorial on RooUtil::Histograms object
    // ~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
    //
    // The RooUtil::Histograms object facilitates book keeping histogram definitions
    // And in conjunction with RooUtil::Cutflow object, one can book same histograms across different cut stages easily without copy pasting codes many times by hand.
    //
    // The histogram addition happens in two steps.
    // 1. Defining histograms
    // 2. Booking histograms to cuts
    //
    // Histograms are defined via following functions
    //
    //      RooUtil::Histograms::addHistogram       : Typical 1D histogram (TH1F*) "Fill()" called once per event
    //      RooUtil::Histograms::addVecHistogram    : Typical 1D histogram (TH1F*) "Fill()" called multiple times per event
    //      RooUtil::Histograms::add2DHistogram     : Typical 2D histogram (TH2F*) "Fill()" called once per event
    //      RooUtil::Histograms::add2DVecHistogram  : Typical 2D histogram (TH2F*) "Fill()" called multiple times per event
    // e.g.
    //
    //    RooUtil::Histograms histograms;
    //    histograms.addHistogram   ("MllSS"    , 180 , 0. , 300. , [&]() { return www.MllSS()  ; }); // The lambda returns float
    //    histograms.addVecHistogram("AllLepPt" , 180 , 0. , 300. , [&]() { return www.lep_pt() ; }); // The lambda returns vector<float>
    //
    // The addVecHistogram will have lambda to return vector<float> and it will loop over the values and call TH1F::Fill() for each item
    //
    // To book histograms to cuts one uses
    //
    //      RooUtil::Cutflow::bookHistogramsForCut()
    //      RooUtil::Cutflow::bookHistogramsForCutAndBelow()
    //      RooUtil::Cutflow::bookHistogramsForCutAndAbove()
    //      RooUtil::Cutflow::bookHistogramsForEndCuts()
    //
    // e.g. Given a tree like the following, we can book histograms to various cuts as we want
    //
    //              Root
    //                |
    //            CutWeight
    //            |       |
    //     CutPreSel1    CutPreSel2
    //       |                  |
    //     CutSel1           CutSel2
    //
    // For example,
    //
    //    1. book a set of histograms to one cut:
    //
    //       cutflow.bookHistogramsForCut(histograms, "CutPreSel2")
    //
    //    2. book a set of histograms to a cut and below
    //
    //       cutflow.bookHistogramsForCutAndBelow(histograms, "CutWeight") // will book a set of histograms to CutWeight, CutPreSel1, CutPreSel2, CutSel1, and CutSel2
    //
    //    3. book a set of histograms to a cut and above (... useless...?)
    //
    //       cutflow.bookHistogramsForCutAndAbove(histograms, "CutPreSel2") // will book a set of histograms to CutPreSel2, CutWeight (nothing happens to Root node)
    //
    //    4. book a set of histograms to a terminating nodes
    //
    //       cutflow.bookHistogramsForEndCuts(histograms) // will book a set of histograms to CutSel1 and CutSel2
    //
    // The naming convention of the booked histograms are as follows
    //
    //   cutflow.bookHistogramsForCut(histograms, "CutSel1");
    //
    //  - TH1F* type object : CutSel1__MllSS;
    //  - TH1F* type object : CutSel1__AllLepPt;
    //                               ^^
    //                               ||
    // NOTE: There are two underscores "__" between <CutName>__<HistogramName>
    //
    // And later in the loop when RooUtil::CutName::fill() function is called, the tree structure will be traversed through and the appropriate histograms will be filled with appropriate variables
    // After running the loop check for the histograms in the output root file

    // Set the cutflow object output file
    ana.cutflow.setTFile(ana.output_tfile);

    // Splitting events by channels
    ana.cutflow.addCut("LooseVRChannel",
                       [&]()
                       {
                           bool pass = 
                               (vbs.j0() + vbs.j1()).mass() > 500.
                               and (fabs(RooUtil::Calc::DeltaEta(vbs.j0(), vbs.j1())) > 3.0)
                               and vbs.channel() >= 0;
                           // if (pass)
                           // {
                           //     std::cout << std::endl
                           //     std::cout << vbs.j0().pt() << ":" << vbs.j1().pt() << ":" << (vbs.j0()+vbs.j1()).mass() << ":" << fabs(RooUtil::Calc::DeltaEta(vbs.j0(),vbs.j1())) << ":" << vbs.run() << ":" << vbs.lumi() << ":" << vbs.evt() << std::endl;
                           // }
                           return pass;
                       }, [&]() { return vbs.wgt() * vbs.btagsf() * vbs.lepsf(); } );

    ana.cutflow.getCut("LooseVRChannel"); ana.cutflow.addCutToLastActiveCut("TightLXChannel", [&]() { return vbs.btagchannel() == 0;                                                         }, UNITY);
    ana.cutflow.getCut("LooseVRChannel"); ana.cutflow.addCutToLastActiveCut("TightEEChannel", [&]() { return vbs.btagchannel() == 0 and vbs.lepchannel() == 0;                               }, UNITY);
    ana.cutflow.getCut("LooseVRChannel"); ana.cutflow.addCutToLastActiveCut("TightEMChannel", [&]() { return vbs.btagchannel() == 0 and vbs.lepchannel() == 1 and abs(vbs.leadlepID()) == 11;}, UNITY);
    ana.cutflow.getCut("LooseVRChannel"); ana.cutflow.addCutToLastActiveCut("TightMEChannel", [&]() { return vbs.btagchannel() == 0 and vbs.lepchannel() == 1 and abs(vbs.leadlepID()) != 11;}, UNITY);
    ana.cutflow.getCut("LooseVRChannel"); ana.cutflow.addCutToLastActiveCut("TightMMChannel", [&]() { return vbs.btagchannel() == 0 and vbs.lepchannel() == 2;                               }, UNITY);
    ana.cutflow.getCut("LooseVRChannel"); ana.cutflow.addCutToLastActiveCut("TightETChannel", [&]() { return vbs.btagchannel() == 0 and vbs.lepchannel() == 3;                               }, UNITY);
    ana.cutflow.getCut("LooseVRChannel"); ana.cutflow.addCutToLastActiveCut("TightMTChannel", [&]() { return vbs.btagchannel() == 0 and vbs.lepchannel() == 4;                               }, UNITY);
    ana.cutflow.getCut("LooseVRChannel"); ana.cutflow.addCutToLastActiveCut("TightLLChannel", [&]() { return vbs.btagchannel() == 0 and vbs.lepchannel() >= 0 and vbs.lepchannel() <= 2;     }, UNITY);
    ana.cutflow.getCut("LooseVRChannel"); ana.cutflow.addCutToLastActiveCut("TightLTChannel", [&]() { return vbs.btagchannel() == 0 and vbs.lepchannel() >= 3 and vbs.lepchannel() <= 4;     }, UNITY);
    ana.cutflow.getCut("LooseVRChannel"); ana.cutflow.addCutToLastActiveCut("TightLEChannel", [&]() { return vbs.btagchannel() == 0 and vbs.lepchannel() >= 0 and vbs.lepchannel() <= 2 and abs(vbs.subllepID()) == 11; }, UNITY);
    ana.cutflow.getCut("LooseVRChannel"); ana.cutflow.addCutToLastActiveCut("TightLMChannel", [&]() { return vbs.btagchannel() == 0 and vbs.lepchannel() >= 0 and vbs.lepchannel() <= 2 and abs(vbs.subllepID()) == 13; }, UNITY);

    ana.cutflow.getCut("LooseVRChannel"); ana.cutflow.addCutToLastActiveCut("LooseEEChannel", [&]() { return vbs.btagchannel() == 1 and vbs.lepchannel() == 0;                               }, UNITY);
    ana.cutflow.getCut("LooseVRChannel"); ana.cutflow.addCutToLastActiveCut("LooseEMChannel", [&]() { return vbs.btagchannel() == 1 and vbs.lepchannel() == 1 and abs(vbs.leadlepID()) == 11;}, UNITY);
    ana.cutflow.getCut("LooseVRChannel"); ana.cutflow.addCutToLastActiveCut("LooseMEChannel", [&]() { return vbs.btagchannel() == 1 and vbs.lepchannel() == 1 and abs(vbs.leadlepID()) != 11;}, UNITY);
    ana.cutflow.getCut("LooseVRChannel"); ana.cutflow.addCutToLastActiveCut("LooseMMChannel", [&]() { return vbs.btagchannel() == 1 and vbs.lepchannel() == 2;                               }, UNITY);
    ana.cutflow.getCut("LooseVRChannel"); ana.cutflow.addCutToLastActiveCut("LooseLLChannel", [&]() { return vbs.btagchannel() == 1 and vbs.lepchannel() >= 0 and vbs.lepchannel() <= 2;     }, UNITY);
    ana.cutflow.getCut("LooseVRChannel"); ana.cutflow.addCutToLastActiveCut("LooseLEChannel", [&]() { return vbs.btagchannel() == 1 and vbs.lepchannel() >= 0 and vbs.lepchannel() <= 2 and abs(vbs.subllepID()) == 11; }, UNITY);
    ana.cutflow.getCut("LooseVRChannel"); ana.cutflow.addCutToLastActiveCut("LooseLMChannel", [&]() { return vbs.btagchannel() == 1 and vbs.lepchannel() >= 0 and vbs.lepchannel() <= 2 and abs(vbs.subllepID()) == 13; }, UNITY);

    ana.cutflow.getCut("LooseVRChannel"); ana.cutflow.addCutToLastActiveCut("LightLLChannel", [&]() { return                            vbs.lepchannel() >= 0 and vbs.lepchannel() <= 2;     }, UNITY);

    ana.cutflow.getCut("LooseVRChannel"); ana.cutflow.addCutToLastActiveCut("ElChannel"      , [&]() { return (vbs.leadlepID() < 0) and (vbs.lepchannel()  == 0 or (vbs.lepchannel() == 1 and abs(vbs.leadlepID()) == 11)); }, UNITY);
    ana.cutflow.getCut("LooseVRChannel"); ana.cutflow.addCutToLastActiveCut("MuChannel"      , [&]() { return (vbs.leadlepID() < 0) and (vbs.lepchannel()  == 2 or (vbs.lepchannel() == 1 and abs(vbs.leadlepID()) == 13)); }, UNITY);
    // ana.cutflow.getCut("LooseVRChannel"); ana.cutflow.addCutToLastActiveCut("TightElChannel" , [&]() { return (vbs.btagchannel() == 0) and (vbs.leadlepID() < 0) and (vbs.lepchannel()  == 0 or (vbs.lepchannel() == 1 and abs(vbs.leadlepID()) == 11)); }, UNITY);
    // ana.cutflow.getCut("LooseVRChannel"); ana.cutflow.addCutToLastActiveCut("TightMuChannel" , [&]() { return (vbs.btagchannel() == 0) and (vbs.leadlepID() < 0) and (vbs.lepchannel()  == 2 or (vbs.lepchannel() == 1 and abs(vbs.leadlepID()) == 13)); }, UNITY);
    // ana.cutflow.getCut("LooseVRChannel"); ana.cutflow.addCutToLastActiveCut("LooseElChannel" , [&]() { return (vbs.btagchannel() == 1) and (vbs.leadlepID() < 0) and (vbs.lepchannel()  == 0 or (vbs.lepchannel() == 1 and abs(vbs.leadlepID()) == 11)); }, UNITY);
    // ana.cutflow.getCut("LooseVRChannel"); ana.cutflow.addCutToLastActiveCut("LooseMuChannel" , [&]() { return (vbs.btagchannel() == 1) and (vbs.leadlepID() < 0) and (vbs.lepchannel()  == 2 or (vbs.lepchannel() == 1 and abs(vbs.leadlepID()) == 13)); }, UNITY);
    ana.cutflow.getCut("LooseVRChannel"); ana.cutflow.addCutToLastActiveCut("TauChannel"     , [&]() { return (vbs.leadlepID() < 0) and (vbs.btagchannel() == 0 and vbs.lepchannel() >= 3 and vbs.lepchannel() <= 4);       }, UNITY);
    ana.cutflow.getCut("LooseVRChannel"); ana.cutflow.addCutToLastActiveCut("NegChannel"     , [&]() { return (vbs.leadlepID() > 0);}, UNITY);

    // Selecting channels of interest
    std::vector<TString> channels =
        {
            // All channels
            "LooseVR", // All channels included

            "El",
            "Mu",
            "Tau",
            "Neg",
        };

    std::vector<std::pair<TString, std::function<bool()>>> kin_regs = {
        std::make_pair("MbbOn",   [&]() { return      (vbs.b0()+vbs.b1()).mass() < 150. and (vbs.b0()+vbs.b1()).mass() > 0.; }),
        std::make_pair("MbbOff",  [&]() { return not ((vbs.b0()+vbs.b1()).mass() < 150. and (vbs.b0()+vbs.b1()).mass() > 0.); }),
        // std::make_pair("MbbHigh", [&]() { return      (vbs.b0()+vbs.b1()).mass() > 140.; }),
        std::make_pair("MbbAll",  UNITY),
    };

    // Looping over channels of interest and adding kinematic selections
    for (auto& channel : channels)
    {
        for (auto& kin_reg : kin_regs)
        {
            ana.cutflow.getCut(TString::Format("%sChannel", channel.Data()));
            ana.cutflow.addCutToLastActiveCut(TString::Format("%s%s", channel.Data(), kin_reg.first.Data()), kin_reg.second, UNITY );

            ana.cutflow.getCut(TString::Format("%s%s", channel.Data(), kin_reg.first.Data()));
            ana.cutflow.addCutToLastActiveCut(TString::Format("%s%sPS"   , channel.Data(), kin_reg.first.Data()), UNITY, UNITY );
            ana.cutflow.getCut(TString::Format("%s%s", channel.Data(), kin_reg.first.Data()));
            ana.cutflow.addCutToLastActiveCut(TString::Format("%s%sSR"    , channel.Data(), kin_reg.first.Data()), [&]() { return      (vbs.j0()+vbs.j1()).mass() > 500. and fabs(RooUtil::Calc::DeltaEta(vbs.j0(), vbs.j1())) > 3.0 and vbs.leadlep().pt() > 140 and vbs.subllep().pt() > 60;  }, UNITY );
            ana.cutflow.getCut(TString::Format("%s%s", channel.Data(), kin_reg.first.Data()));
            ana.cutflow.addCutToLastActiveCut(TString::Format("%s%sPS2"   , channel.Data(), kin_reg.first.Data()),
                                              [&]()
                                              {
                                                  return ((vbs.b0() + vbs.b1() + vbs.leadlep() + vbs.subllep() + vbs.met_p4()).mass() > 700.);
                                              } , UNITY );

            ana.cutflow.getCut(TString::Format("%s%s", channel.Data(), kin_reg.first.Data()));
            ana.cutflow.addCutToLastActiveCut(TString::Format("%s%sLT"   , channel.Data(), kin_reg.first.Data()),
                                              [&]()
                                              {
                                                  return
                                                      // ((vbs.b0() + vbs.b1() + vbs.leadlep() + vbs.subllep() + vbs.met_p4()).mass() > 1000.)
                                                      // and
                                                      (vbs.leadlep().pt() + vbs.subllep().pt() + vbs.met_p4().pt()) > 450.
                                                      and
                                                      vbs.b0().pt() + vbs.b0().pt() + vbs.leadlep().pt() + vbs.subllep().pt() + vbs.met_p4().pt() > 900.
                                                      and (fabs(RooUtil::Calc::DeltaEta(vbs.j0(), vbs.j1())) > 5.0)
                                                      ;
                                              } , UNITY );
            ana.cutflow.getCut(TString::Format("%s%s", channel.Data(), kin_reg.first.Data()));
            ana.cutflow.addCutToLastActiveCut(TString::Format("%s%sLTVR1"   , channel.Data(), kin_reg.first.Data()),
                                              [&]()
                                              {
                                                  return ((vbs.b0() + vbs.b1() + vbs.leadlep() + vbs.subllep() + vbs.met_p4()).mass() > 1000.);
                                              } , UNITY );
            ana.cutflow.getCut(TString::Format("%s%s", channel.Data(), kin_reg.first.Data()));
            ana.cutflow.addCutToLastActiveCut(TString::Format("%s%sLTVR2"   , channel.Data(), kin_reg.first.Data()),
                                              [&]()
                                              {
                                                  return (vbs.leadlep().pt() + vbs.subllep().pt() + vbs.met_p4().pt()) > 500.;
                                              } , UNITY );
            ana.cutflow.getCut(TString::Format("%s%s", channel.Data(), kin_reg.first.Data()));
            ana.cutflow.addCutToLastActiveCut(TString::Format("%s%sLTVR3"   , channel.Data(), kin_reg.first.Data()),
                                              [&]()
                                              {
                                                  return vbs.b0().pt() + vbs.b0().pt() + vbs.leadlep().pt() + vbs.subllep().pt() + vbs.met_p4().pt() > 1000.;
                                              } , UNITY );
            ana.cutflow.getCut(TString::Format("%s%s", channel.Data(), kin_reg.first.Data()));
            ana.cutflow.addCutToLastActiveCut(TString::Format("%s%sLTVR4"   , channel.Data(), kin_reg.first.Data()),
                                              [&]()
                                              {
                                                  return (fabs(RooUtil::Calc::DeltaEta(vbs.j0(), vbs.j1())) > 6.0);
                                              } , UNITY );
            ana.cutflow.getCut(TString::Format("%s%s", channel.Data(), kin_reg.first.Data()));
            ana.cutflow.addCutToLastActiveCut(TString::Format("%s%sLTVR5"   , channel.Data(), kin_reg.first.Data()),
                                              [&]()
                                              {
                                                  return (vbs.j0() + vbs.j1()).mass() > 1500.;
                                              } , UNITY );
            ana.cutflow.getCut(TString::Format("%s%s", channel.Data(), kin_reg.first.Data()));
            ana.cutflow.addCutToLastActiveCut(TString::Format("%s%sLTVR"   , channel.Data(), kin_reg.first.Data()),
                                              [&]()
                                              {
                                                  return not (
                                                      (vbs.leadlep().pt() + vbs.subllep().pt() + vbs.met_p4().pt()) > 450.
                                                      and
                                                      vbs.b0().pt() + vbs.b0().pt() + vbs.leadlep().pt() + vbs.subllep().pt() + vbs.met_p4().pt() > 900.
                                                      and (fabs(RooUtil::Calc::DeltaEta(vbs.j0(), vbs.j1())) > 5.0))
                                                      ;
                                              } , UNITY );
        }
    }

    // Defining histograms
    ana.histograms.addHistogram("NCenJet30"           , 9   , 0       , 9      , [&]() { return vbs.ncenjet30();                                                             } );
    ana.histograms.addHistogram("NJet30"              , 9   , 0       , 9      , [&]() { return vbs.njet30();                                                                } );
    ana.histograms.addHistogram("NBLoose"             , 5   , 0       , 5      , [&]() { return vbs.nbloose();                                                               } );
    ana.histograms.addHistogram("NBMedium"            , 5   , 0       , 5      , [&]() { return vbs.nbmedium();                                                              } );
    ana.histograms.addHistogram("NBTight"             , 5   , 0       , 5      , [&]() { return vbs.nbtight();                                                               } );
    ana.histograms.addHistogram("LeptonPt0"           , 180 , 0       , 600    , [&]() { return vbs.leadlep().pt();                                                          } );
    ana.histograms.addHistogram("LeptonPt1"           , 180 , 0       , 600    , [&]() { return vbs.subllep().pt();                                                          } );
    ana.histograms.addHistogram("LeptonPt0Zoom"       , 180 , 0       , 250    , [&]() { return vbs.leadlep().pt();                                                          } );
    ana.histograms.addHistogram("LeptonPt1Zoom"       , 180 , 0       , 250    , [&]() { return vbs.subllep().pt();                                                          } );
    ana.histograms.addHistogram("LeptonEta0"          , 180 , -3      , 3      , [&]() { return vbs.leadlep().eta();                                                         } );
    ana.histograms.addHistogram("LeptonEta1"          , 180 , -3      , 3      , [&]() { return vbs.subllep().eta();                                                         } );
    ana.histograms.addHistogram("LeptonPhi0"          , 180 , -3.1416 , 3.1416 , [&]() { return vbs.leadlep().phi();                                                         } );
    ana.histograms.addHistogram("LeptonPhi1"          , 180 , -3.1416 , 3.1416 , [&]() { return vbs.subllep().phi();                                                         } );
    ana.histograms.addHistogram("LeptonPtFlavor0"     , 180 , 0       , 600    , [&]() { return vbs.lep0().pt();                                                             } );
    ana.histograms.addHistogram("LeptonPtFlavor1"     , 180 , 0       , 600    , [&]() { return vbs.lep1().pt();                                                             } );
    ana.histograms.addHistogram("LeptonPtFlavor0Zoom" , 180 , 0       , 250    , [&]() { return vbs.lep0().pt();                                                             } );
    ana.histograms.addHistogram("LeptonPtFlavor1Zoom" , 180 , 0       , 250    , [&]() { return vbs.lep1().pt();                                                             } );
    ana.histograms.addHistogram("LeptonEtaFlavor0"    , 180 , -3      , 3      , [&]() { return vbs.lep0().eta();                                                            } );
    ana.histograms.addHistogram("LeptonEtaFlavor1"    , 180 , -3      , 3      , [&]() { return vbs.lep1().eta();                                                            } );
    ana.histograms.addHistogram("LeptonPhiFlavor0"    , 180 , -3.1416 , 3.1416 , [&]() { return vbs.lep0().phi();                                                            } );
    ana.histograms.addHistogram("LeptonPhiFlavor1"    , 180 , -3.1416 , 3.1416 , [&]() { return vbs.lep1().phi();                                                            } );
    ana.histograms.addHistogram("JetPt0"              , 180 , 0       , 250    , [&]() { return vbs.j0().pt();                                                               } );
    ana.histograms.addHistogram("JetPt1"              , 180 , 0       , 250    , [&]() { return vbs.j1().pt();                                                               } );
    ana.histograms.addHistogram("JetEta0"             , 180 , -5      , 5      , [&]() { return vbs.j0().eta();                                                              } );
    ana.histograms.addHistogram("JetEta1"             , 180 , -5      , 5      , [&]() { return vbs.j1().eta();                                                              } );
    ana.histograms.addHistogram("AbsJetEta0"          , 180 , 0       , 5      , [&]() { return fabs(vbs.j0().eta());                                                        } );
    ana.histograms.addHistogram("AbsJetEta1"          , 180 , 0       , 5      , [&]() { return fabs(vbs.j1().eta());                                                        } );
    ana.histograms.addHistogram("JetPhi0"             , 180 , -3.1416 , 3.1416 , [&]() { return vbs.j0().phi();                                                              } );
    ana.histograms.addHistogram("JetPhi1"             , 180 , -3.1416 , 3.1416 , [&]() { return vbs.j1().phi();                                                              } );
    ana.histograms.addHistogram("BJetPt0"             , 180 , 0       , 450    , [&]() { return vbs.b0().pt();                                                               } );
    ana.histograms.addHistogram("BJetPt1"             , 180 , 0       , 250    , [&]() { return vbs.b1().pt();                                                               } );
    ana.histograms.addHistogram("BJetEta0"            , 180 , -5      , 5      , [&]() { return vbs.b0().eta();                                                              } );
    ana.histograms.addHistogram("BJetEta1"            , 180 , -5      , 5      , [&]() { return vbs.b1().eta();                                                              } );
    ana.histograms.addHistogram("BJetPhi0"            , 180 , -3.1416 , 3.1416 , [&]() { return vbs.b0().phi();                                                              } );
    ana.histograms.addHistogram("BJetPhi1"            , 180 , -3.1416 , 3.1416 , [&]() { return vbs.b1().phi();                                                              } );
    ana.histograms.addHistogram("PtJJ"                , 180 , 0       , 250    , [&]() { return (vbs.j0()+vbs.j1()).pt();                                                    } );
    ana.histograms.addHistogram("MJJ"                 , 180 , 0       , 4500   , [&]() { return (vbs.j0()+vbs.j1()).mass();                                                  } );
    ana.histograms.addHistogram("MJJLow"              , 180 , 0       , 350    , [&]() { return (vbs.j0()+vbs.j1()).mass();                                                  } );
    ana.histograms.addHistogram("DEtaJJ"              , 180 , 0       , 10     , [&]() { return fabs(RooUtil::Calc::DeltaEta(vbs.j0(), vbs.j1()));                           } );
    ana.histograms.addHistogram("DPhiJJ"              , 180 , 0       , 3.1416 , [&]() { return fabs(RooUtil::Calc::DeltaPhi(vbs.j0(), vbs.j1()));                           } );
    ana.histograms.addHistogram("HiggsPt"             , 180 , 0       , 1000   , [&]() { return (vbs.b0()+vbs.b1()).pt();                                                    } );
    ana.histograms.addHistogram("HiggsPtLow"          , 180 , 0       , 350    , [&]() { return (vbs.b0()+vbs.b1()).pt();                                                    } );
    ana.histograms.addHistogram("DPhill"              , 180 , 0       , 3.1416 , [&]() { return fabs(RooUtil::Calc::DeltaPhi(vbs.leadlep(), vbs.subllep()));                 } );
    ana.histograms.addHistogram("DEtall"              , 180 , 0       , 7      , [&]() { return fabs(RooUtil::Calc::DeltaEta(vbs.leadlep(), vbs.subllep()));                 } );
    ana.histograms.addHistogram("DRll"                , 180 , 0       , 7      , [&]() { return fabs(RooUtil::Calc::DeltaR(vbs.leadlep(), vbs.subllep()));                   } );
    ana.histograms.addHistogram("Mll"                 , 180 , 0       , 2000   , [&]() { return (vbs.leadlep()+vbs.subllep()).mass();                                        } );
    ana.histograms.addHistogram("MllLow"              , 180 , 0       , 250    , [&]() { return (vbs.leadlep()+vbs.subllep()).mass();                                        } );
    ana.histograms.addHistogram("Mbb"                 , 180 , 0       , 300    , [&]() { return (vbs.b0()+vbs.b1()).mass();                                                  } );
    ana.histograms.addHistogram("MbbMax"              , 180 , 0       , 600    , [&]() { return (vbs.b0()+vbs.b1()).mass();                                                  } );
    ana.histograms.addHistogram("MbbInOut"            , 2   , 0       , 2      , [&]() { return (vbs.b0()+vbs.b1()).mass() < 150 and (vbs.b0()+vbs.b1()).mass() > 0.;        } );
    ana.histograms.addHistogram("MbbInOutV1"          , 2   , 0       , 2      , [&]() { return (vbs.b0()+vbs.b1()).mass() < 140 and (vbs.b0()+vbs.b1()).mass() > 90.;       } );
    ana.histograms.addHistogram("DRbb"                , 180 , 0       , 6      , [&]() { return RooUtil::Calc::DeltaR(vbs.b0(), vbs.b1());                                   } );
    ana.histograms.addHistogram("MET"                 , 180 , 0       , 1500   , [&]() { return vbs.met_p4().pt();                                                           } );
    ana.histograms.addHistogram("METLow"              , 180 , 0       , 250    , [&]() { return vbs.met_p4().pt();                                                           } );
    ana.histograms.addHistogram("Channels"            , 8   , 0       , 8      , [&]() { return vbs.channel();                                                               } );
    ana.histograms.addHistogram("ChannelsDetails"     , 16  , 0       , 16     , [&]() { return vbs.channeldetail();                                                         } );
    ana.histograms.addHistogram("ChannelsMbbMerged"   , 8   , 0       , 8      , [&]() { return vbs.channeldetail() / 2;                                                     } );
    ana.histograms.addHistogram("MVVH"                , 180 , 0       , 2500   , [&]() { return (vbs.b0() + vbs.b1() + vbs.leadlep() + vbs.subllep() + vbs.met_p4()).mass(); } );
    ana.histograms.addHistogram("ST"                  , 180 , 0       , 2500   , [&]() { return vbs.b0().pt() + vbs.b0().pt() + vbs.leadlep().pt() + vbs.subllep().pt() + vbs.met_p4().pt(); } );
    ana.histograms.addHistogram("LT"                  , 180 , 0       , 2500   , [&]() { return vbs.leadlep().pt() + vbs.subllep().pt() + vbs.met_p4().pt(); } );
    // ana.histograms.addHistogram("BJetMatchCategory"   , 4   , -1      , 3      , [&]() { return vbs.bmatchcateg();                                                             } );
    // ana.histograms.addHistogram("MbbBothGenMatched"   , 180 , -10     , 290    , [&]() { if (vbs.higgs_jets_genmatched()[0] and vbs.higgs_jets_genmatched()[1]) return (vbs.b0()+vbs.b1()).mass(); else return -999.f;} );
    // ana.histograms.addHistogram("MbbMaxBothGenMatched", 180 , -10     , 290    , [&]() { if (vbs.higgs_jets_genmatched()[0] and vbs.higgs_jets_genmatched()[1]) return (vbs.b0()+vbs.b1()).mass(); else return -999.f;} );
    // ana.histograms.addHistogram("MbbLeadGenMatched"   , 180 , -10     , 290    , [&]() { if (vbs.higgs_jets_genmatched()[0] and not vbs.higgs_jets_genmatched()[1]) return (vbs.b0()+vbs.b1()).mass(); else return -999.f;} );
    // ana.histograms.addHistogram("MbbMaxLeadGenMatched", 180 , -10     , 290    , [&]() { if (vbs.higgs_jets_genmatched()[0] and not vbs.higgs_jets_genmatched()[1]) return (vbs.b0()+vbs.b1()).mass(); else return -999.f;} );
    // ana.histograms.addHistogram("MbbSublGenMatched"   , 180 , -10     , 290    , [&]() { if (vbs.higgs_jets_genmatched()[1] and not vbs.higgs_jets_genmatched()[0]) return (vbs.b0()+vbs.b1()).mass(); else return -999.f;} );
    // ana.histograms.addHistogram("MbbMaxSublGenMatched", 180 , -10     , 290    , [&]() { if (vbs.higgs_jets_genmatched()[1] and not vbs.higgs_jets_genmatched()[0]) return (vbs.b0()+vbs.b1()).mass(); else return -999.f;} );
    // ana.histograms.addHistogram("MbbLoneGenMatched"   , 180 , -10     , 290    , [&]() { if (vbs.higgs_jets_genmatched()[0] + vbs.higgs_jets_genmatched()[1] == 1) return (vbs.b0()+vbs.b1()).mass(); else return -999.f;} );
    // ana.histograms.addHistogram("MbbMaxLoneGenMatched", 180 , -10     , 290    , [&]() { if (vbs.higgs_jets_genmatched()[0] + vbs.higgs_jets_genmatched()[1] == 1) return (vbs.b0()+vbs.b1()).mass(); else return -999.f;} );
    // ana.histograms.addHistogram("MbbNoneGenMatched"   , 180 , -10     , 290    , [&]() { if (not vbs.higgs_jets_genmatched()[0] and not vbs.higgs_jets_genmatched()[1]) return (vbs.b0()+vbs.b1()).mass(); else return -999.f;} );
    // ana.histograms.addHistogram("MbbMaxNoneGenMatched", 180 , -10     , 290    , [&]() { if (not vbs.higgs_jets_genmatched()[0] and not vbs.higgs_jets_genmatched()[1]) return (vbs.b0()+vbs.b1()).mass(); else return -999.f;} );
    ana.histograms.addHistogram("Yield"               , 1   , 0       , 1      , [&]() { return 0; } );
    ana.histograms.addHistogram("Channels4Bins"       , 4   , 0       , 4      ,
                                [&]()
                                {
                                    if ((vbs.leadlepID() < 0) and (vbs.lepchannel()  == 0 or (vbs.lepchannel() == 1 and abs(vbs.leadlepID()) == 11)))
                                        return 0;
                                    else if ((vbs.leadlepID() < 0) and (vbs.lepchannel()  == 2 or (vbs.lepchannel() == 1 and abs(vbs.leadlepID()) == 13)))
                                        return 1;
                                    else if ((vbs.leadlepID() < 0) and (vbs.btagchannel() == 0 and vbs.lepchannel() >= 3 and vbs.lepchannel() <= 4))
                                        return 2;
                                    else if ((vbs.leadlepID() > 0))
                                        return 3;
                                    else
                                        return -999;
                                } );
    ana.histograms.addHistogram("Channels8Bins"       , 8   , 0       , 8      ,
                                [&]()
                                {
                                    if ((vbs.leadlepID() < 0) and (vbs.lepchannel()  == 0 or (vbs.lepchannel() == 1 and abs(vbs.leadlepID()) == 11)))
                                    {
                                        if ((vbs.b0()+vbs.b1()).mass() < 150.)
                                            return 0;
                                        if ((vbs.b0()+vbs.b1()).mass() >= 150.)
                                            return 1;
                                    }
                                    else if ((vbs.leadlepID() < 0) and (vbs.lepchannel()  == 2 or (vbs.lepchannel() == 1 and abs(vbs.leadlepID()) == 13)))
                                    {
                                        if ((vbs.b0()+vbs.b1()).mass() < 150.)
                                            return 2;
                                        if ((vbs.b0()+vbs.b1()).mass() >= 150.)
                                            return 3;
                                    }
                                    else if ((vbs.leadlepID() < 0) and (vbs.btagchannel() == 0 and vbs.lepchannel() >= 3 and vbs.lepchannel() <= 4))
                                    {
                                        if ((vbs.b0()+vbs.b1()).mass() < 150.)
                                            return 4;
                                        if ((vbs.b0()+vbs.b1()).mass() >= 150.)
                                            return 5;
                                    }
                                    else if ((vbs.leadlepID() > 0))
                                    {
                                        if ((vbs.b0()+vbs.b1()).mass() < 150.)
                                            return 6;
                                        if ((vbs.b0()+vbs.b1()).mass() >= 150.)
                                            return 7;
                                    }
                                    else
                                    {
                                        return -999;
                                    }
                                } );
    ana.histograms.addHistogram("MbbInOutv2"          , 3   , 0       , 3      ,
                                [&]()
                                {
                                    if ((vbs.b0()+vbs.b1()).mass() > 150)
                                        return 2;
                                    else if ((vbs.b0()+vbs.b1()).mass() > 90)
                                        return 1;
                                    else
                                        return 0;
                                } );
    ana.histograms.addVecHistogram("VRs"                 , 6   , 0       , 6      ,
                                [&]()
                                {
                                    std::vector<float> bins;
                                    bins.push_back(0);
                                    if ((vbs.leadlep().pt() + vbs.subllep().pt() + vbs.met_p4().pt()) > 500.)
                                        bins.push_back(1);
                                    if ((fabs(RooUtil::Calc::DeltaEta(vbs.j0(), vbs.j1())) > 6.0))
                                        bins.push_back(2);
                                    if ((vbs.j0() + vbs.j1()).mass() > 1500.)
                                        bins.push_back(3);
                                    if (vbs.b0().pt() + vbs.b0().pt() + vbs.leadlep().pt() + vbs.subllep().pt() + vbs.met_p4().pt() > 1000.)
                                        bins.push_back(4);
                                    if (((vbs.b0() + vbs.b1() + vbs.leadlep() + vbs.subllep() + vbs.met_p4()).mass() > 1000.))
                                        bins.push_back(5);
                                    return bins;
                                } );


    // ana.histograms.addHistogram("MT2"                 , 180 , 0       , 250   ,
    //                             [&]()
    //                             {
    //                                 TLorentzVector lepton1 = RooUtil::Calc::getTLV(vbs.leadlep());
    //                                 TLorentzVector lepton2 = RooUtil::Calc::getTLV(vbs.subllep());
    //                                 TLorentzVector misspart = RooUtil::Calc::getTLV(vbs.met_p4());
    //                                 // TLorentzVector rest_WW = lepton1 + lepton2 + misspart;
    //                                 // TVector3 beta_from_miss_reverse(rest_WW.BoostVector());
    //                                 // TVector3 beta_from_miss(-beta_from_miss_reverse.X(),-beta_from_miss_reverse.Y(),-beta_from_miss_reverse.Z());
    //                                 // lepton1.Boost(beta_from_miss);
    //                                 // lepton2.Boost(beta_from_miss);
    //                                 // misspart.Boost(beta_from_miss);
    //                                 double MT2_0mass = asymm_mt2_lester_bisect::get_mT2(0,lepton1.Px(),lepton1.Py(),0,lepton2.Px(),lepton2.Py(),misspart.Px(), misspart.Py(),0,0,0);
    //                                 return MT2_0mass;
    //                             } );

    ana.histograms.addHistogram("NCenJet"             , 9   , 0       , 9      , [&]()
                                {
                                    int njets = 0;
                                    const vector<LV>& good_jets_p4 = vbs.good_jets_p4();
                                    for (unsigned int i = 0; i < good_jets_p4.size(); i++)
                                    {
                                        if (vbs.higgs_jets_good_jets_idx()[0] == i) continue;
                                        if (vbs.higgs_jets_good_jets_idx()[1] == i) continue;
                                        if (vbs.vbs_jets_good_jets_idx()[0] == i) continue;
                                        if (vbs.vbs_jets_good_jets_idx()[1] == i) continue;
                                        float eta = good_jets_p4[i].eta();
                                        float eta0 = vbs.j0().eta();
                                        float eta1 = vbs.j1().eta();
                                        if ((eta0 - eta) * (eta1 - eta) > 0)
                                            continue;
                                        njets++;
                                    }
                                    return njets;
                                } );

    ana.histograms.add2DHistogram("Mbb", 50 , 0 , 300 , "HiggsPt", 50, 0, 600, [&]() { return (vbs.b0()+vbs.b1()).mass(); }, [&]() { return (vbs.b0()+vbs.b1()).pt(); } );
    ana.histograms.add2DHistogram("Mbb", 50 , 0 , 300 , "DRbb", 50, 0, 6, [&]() { return (vbs.b0()+vbs.b1()).mass(); }, [&]() { return RooUtil::Calc::DeltaR(vbs.b0(), vbs.b1()); } );
    ana.histograms.add2DHistogram("Mbb", 50 , 0 , 300 , "MJJ", 50, 0, 4500, [&]() { return (vbs.b0()+vbs.b1()).mass(); }, [&]() { return (vbs.j0()+vbs.j1()).mass(); } );
    ana.histograms.add2DHistogram("Mbb", 50 , 0 , 300 , "DEtaJJ", 50, 0, 6, [&]() { return (vbs.b0()+vbs.b1()).mass(); }, [&]() { return fabs(RooUtil::Calc::DeltaEta(vbs.j0(), vbs.j1())); } );
    ana.histograms.add2DHistogram("Mbb", 50 , 0 , 300 , "LepPt0", 50, 0, 450, [&]() { return (vbs.b0()+vbs.b1()).mass(); }, [&]() { return vbs.leadlep().pt(); } );
    ana.histograms.add2DHistogram("Mbb", 50 , 0 , 300 , "LepPt1", 50, 0, 250, [&]() { return (vbs.b0()+vbs.b1()).mass(); }, [&]() { return vbs.subllep().pt(); } );
    ana.histograms.add2DHistogram("Mbb", 50 , 0 , 300 , "BJetPt0", 50, 0, 450, [&]() { return (vbs.b0()+vbs.b1()).mass(); }, [&]() { return vbs.b0().pt(); } );
    ana.histograms.add2DHistogram("Mbb", 50 , 0 , 300 , "BJetPt1", 50, 0, 250, [&]() { return (vbs.b0()+vbs.b1()).mass(); }, [&]() { return vbs.b1().pt(); } );
    ana.histograms.add2DHistogram("Mbb", 50 , 0 , 300 , "ST", 50, 0, 2500, [&]() { return (vbs.b0()+vbs.b1()).mass(); }, [&]() { return vbs.b0().pt() + vbs.b0().pt() + vbs.leadlep().pt() + vbs.subllep().pt() + vbs.met_p4().pt() + vbs.j0().pt() + vbs.j1().pt(); } );
    ana.histograms.add2DHistogram("Mbb", 50 , 0 , 300 , "MVVH", 50, 0, 2500, [&]() { return (vbs.b0()+vbs.b1()).mass(); }, [&]() { return (vbs.b0() + vbs.b1() + vbs.leadlep() + vbs.subllep() + vbs.met_p4()).mass(); } );
    ana.histograms.add2DHistogram("MJJ", 50 , 0 , 3000, "MVVH", 50, 0, 2500, [&]() { return (vbs.j0()+vbs.j1()).mass(); }, [&]() { return (vbs.b0() + vbs.b1() + vbs.leadlep() + vbs.subllep() + vbs.met_p4()).mass(); } );
    ana.histograms.add2DHistogram("MbbMax", 50 , 0 , 700 , "ST", 50, 0, 2500, [&]() { return (vbs.b0()+vbs.b1()).mass(); }, [&]() { return vbs.b0().pt() + vbs.b0().pt() + vbs.leadlep().pt() + vbs.subllep().pt() + vbs.met_p4().pt() + vbs.j0().pt() + vbs.j1().pt(); } );
    ana.histograms.add2DHistogram("MbbMax", 50 , 0 , 700 , "MVVH", 50, 0, 2500, [&]() { return (vbs.b0()+vbs.b1()).mass(); }, [&]() { return (vbs.b0() + vbs.b1() + vbs.leadlep() + vbs.subllep() + vbs.met_p4()).mass(); } );
    ana.histograms.add2DHistogram("MbbMax", 50 , 0 , 700 , "HiggsPt", 50, 0, 600, [&]() { return (vbs.b0()+vbs.b1()).mass(); }, [&]() { return (vbs.b0()+vbs.b1()).pt(); } );
    ana.histograms.add2DHistogram("ST", 50 , 0 , 2500 , "MVVH", 50, 0, 2500, [&]() { return vbs.b0().pt() + vbs.b0().pt() + vbs.leadlep().pt() + vbs.subllep().pt() + vbs.met_p4().pt() + vbs.j0().pt() + vbs.j1().pt(); }, [&]() { return (vbs.b0() + vbs.b1() + vbs.leadlep() + vbs.subllep() + vbs.met_p4()).mass(); } );
    ana.histograms.add2DHistogram("Mbb", 50 , 0 , 300 , "LT", 50, 0, 2500, [&]() { return (vbs.b0()+vbs.b1()).mass(); }, [&]() { return vbs.leadlep().pt() + vbs.subllep().pt() + vbs.met_p4().pt(); } );
    ana.histograms.add2DHistogram("MbbMax", 50 , 0 , 700 , "LT", 50, 0, 2500, [&]() { return (vbs.b0()+vbs.b1()).mass(); }, [&]() { return vbs.leadlep().pt() + vbs.subllep().pt() + vbs.met_p4().pt(); } );


    // Print cut structure
    ana.cutflow.printCuts();

    // Book cutflows
    ana.cutflow.bookCutflows();

    // Book Histograms
    ana.cutflow.bookHistogramsForCutAndBelow(ana.histograms, "LooseVRChannel");

    // Looping input file
    while (ana.looper.nextEvent())
    {

        // If splitting jobs are requested then determine whether to process the event or not based on remainder
        if (result.count("job_index") and result.count("nsplit_jobs"))
        {
            if (ana.looper.getNEventsProcessed() % ana.nsplit_jobs != (unsigned int) ana.job_index)
                continue;
        }

        //Do what you need to do in for each event here
        //To save use the following function
        ana.cutflow.fill();
    }

    // Writing output file
    ana.cutflow.saveOutput();

    // The below can be sometimes crucial
    delete ana.output_tfile;
}
