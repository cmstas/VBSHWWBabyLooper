#include "VBSHWW.h"



//________________________________________________________________________________________________________________________________________
VBSHWW::~VBSHWW() {}



//________________________________________________________________________________________________________________________________________
VBSHWW::VBSHWW(int argc, char** argv) :
    tx(
       (parseCLI(argc, argv), "variable"), // This weird syntax guarantees that parseCLI runs prior to initializing "tx"
       "variable"
      )
{

//=============================
//
// Setting Up Analysis
//
//=============================

    // Create the TChain that holds the TTree's of the baby ntuples
    events_tchain = RooUtil::FileUtil::createTChain(input_tree_name, input_file_list_tstring);

    // Determine whether the sample being run over has LHEScaleWeight and PSWeight
    hasLHEScaleWeight = false; // default is false
    hasPSWeight = false; // default is false
    hasLHEReweightingWeight = false; // default is false
    TObjArray* brobjArray = events_tchain->GetListOfBranches();
    for (unsigned int ibr = 0; ibr < (unsigned int) brobjArray->GetEntries(); ++ibr)
    {
        TString brname = brobjArray->At(ibr)->GetName();
        if (brname.EqualTo("LHEScaleWeight"))
            hasLHEScaleWeight = true; // if it has the branch it is set to true
        if (brname.EqualTo("PSWeight"))
            hasPSWeight = true; // if it has the branch it is set to true
        if (brname.EqualTo("LHEReweightingWeight"))
            hasLHEReweightingWeight = true; // if it has the branch it is set to true
    }

    // Set up a looper
    looper.init(events_tchain, &nt, n_events);

    isUL = (
        input_file_list_tstring.Contains("UL18") or input_file_list_tstring.Contains("UL2018") or
        input_file_list_tstring.Contains("UL17") or input_file_list_tstring.Contains("UL2017")
        );

    // Setup the process of the input
    TString ofile_name = output_tfile->GetName();
    if (ofile_name.Contains("/TTToSemi")) { processType = ProcessType::kTT1LPowheg; }
    else if (ofile_name.Contains("/TTTo2L2Nu")) { processType = ProcessType::kTT2LPowheg; }
    else if (ofile_name.Contains("/TTJets_Sing")) { processType = ProcessType::kTT1LMadGraph; }
    else if (ofile_name.Contains("/TTJets_Di")) { processType = ProcessType::kTT2LMadGraph; }
    else if (ofile_name.Contains("/TTWJets")) { processType = ProcessType::kTTW; }
    else if (ofile_name.Contains("/TTZTo")) { processType = ProcessType::kTTZ; }
    else if (ofile_name.Contains("/VBSWmpWmp")) { processType = ProcessType::kSignal; }
    else if (ofile_name.Contains("/WJetsTo") or
             ofile_name.Contains("/DY") or
             ofile_name.Contains("/GluGluHToZZTo4L") or
             ofile_name.Contains("/WWW") or
             ofile_name.Contains("/WWZ") or
             ofile_name.Contains("/WZZ") or
             ofile_name.Contains("/ZZZ") or
             ofile_name.Contains("/WW_") or
             ofile_name.Contains("/WWTo") or
             ofile_name.Contains("/WWTo") or
             ofile_name.Contains("/WpWp") or
             ofile_name.Contains("/SSWW_") or
             ofile_name.Contains("/WZTo3LNu") or
             ofile_name.Contains("/ZZ")
            )
    {
        processType = ProcessType::kBosons;
    }
    else if (ofile_name.Contains("/ttHJetTo") or
             ofile_name.Contains("/ttHTo") or
             ofile_name.Contains("/ST_") or
             ofile_name.Contains("/TWZ") or
             ofile_name.Contains("/tZq") or
             ofile_name.Contains("/TTWW") or
             ofile_name.Contains("/TTWZ") or
             ofile_name.Contains("/TTWH") or
             ofile_name.Contains("/TTZZ") or
             ofile_name.Contains("/TTZH") or
             ofile_name.Contains("/TTTT")
            )
    {
        processType = ProcessType::kRaretop;
    }



    // Set the cutflow object output file
    cutflow.setTFile(output_tfile);

    // Set up the NanoCORE's common configuration service tool
    gconf.nanoAOD_ver = isUL ? 8 : 0;
    gconf.GetConfigs(nt.year());
    std::cout <<  " gconf.WP_DeepFlav_tight: " << gconf.WP_DeepFlav_tight <<  std::endl;

    // Setting up good runs list
    // TString vbsHwwNanoLooperDirPath = gSystem->Getenv("VBSHWWNANOLOOPERDIR");
    // const char* json_file = TString::Format("%s/NanoTools/NanoCORE/Tools/data/Cert_271036-325175_13TeV_Combined161718_JSON_snt.txt", vbsHwwNanoLooperDirPath.Data()).Data();
    // cout << "Setting grl: " << json_file << endl;
    if (nt.year() == 2016)
        set_goodrun_file("/nfs-7/userdata/phchang/analysis_data/grl/Cert_271036-325175_13TeV_Combined161718_JSON_snt.txt");
    if (nt.year() == 2017)
        set_goodrun_file("/nfs-7/userdata/phchang/analysis_data/grl/Cert_294927-306462_13TeV_UL2017_Collisions17_GoldenJSON_snt.txt");
    if (nt.year() == 2018)
        set_goodrun_file("/nfs-7/userdata/phchang/analysis_data/grl/Cert_314472-325175_13TeV_Legacy2018_Collisions18_JSON_snt.txt");

    // Setting up tau ID scale factors (used tight ttH tau ID DeepTau working points)
    // TODO: check that 'embedding' should indeed be false (last bool in the TauIDSFTool constructor)
    if (nt.year() == 2016)
    {
        tauSF_vsJet = new TauIDSFTool("2016Legacy", "DeepTau2017v2p1VSjet", "Medium", false, false);
        tauSF_vsMu = new TauIDSFTool("2016Legacy", "DeepTau2017v2p1VSmu", "Loose", false, false);
        tauSF_vsEl = new TauIDSFTool("2016Legacy", "DeepTau2017v2p1VSe", "VVLoose", false, false); // ttH uses VVVLoose but sfs only available up to VVLoose
    }
    else if (nt.year() == 2017)
    {
        tauSF_vsJet = new TauIDSFTool("2017ReReco", "DeepTau2017v2p1VSjet", "Medium", false, false);
        tauSF_vsMu = new TauIDSFTool("2017ReReco", "DeepTau2017v2p1VSmu", "Loose", false, false);
        tauSF_vsEl = new TauIDSFTool("2017ReReco", "DeepTau2017v2p1VSe", "VVLoose", false, false); // ttH uses VVVLoose but sfs only available up to VVLoose
    }
    else if (nt.year() == 2018)
    {
        tauSF_vsJet = new TauIDSFTool("2018ReReco", "DeepTau2017v2p1VSjet", "Medium", false, false);
        tauSF_vsMu = new TauIDSFTool("2018ReReco", "DeepTau2017v2p1VSmu", "Loose", false, false);
        tauSF_vsEl = new TauIDSFTool("2018ReReco", "DeepTau2017v2p1VSe", "VVLoose", false, false); // ttH uses VVVLoose but sfs only available up to VVLoose
    }
    else
    {
        RooUtil::error(TString::Format("While setting tau ID scale factors, found year = %d that is not recognized.", nt.year()));
    }

    // Setting up btagging scale factors
    if (nt.year() == 2016)
    {
        btagCalib = new BTagCalibration("DeepJet", "data/DeepJet_2016LegacySF_V1.csv");
    }
    else if (nt.year() == 2017 and isUL)
    {
        btagCalib = new BTagCalibration("DeepJet", "data/DeepJet_106XUL17SF_WPonly_V2p1.csv");
    }
    else if (nt.year() == 2017 and not isUL)
    {
        btagCalib = new BTagCalibration("DeepJet", "data/DeepJet_94XSF_V4_B_F.csv");
    }
    else if (nt.year() == 2018 and isUL)
    {
        btagCalib = new BTagCalibration("DeepJet", "data/DeepJet_106XUL18SF_WPonly.csv");
    }
    else if (nt.year() == 2018 and not isUL)
    {
        btagCalib = new BTagCalibration("DeepJet", "data/DeepJet_102XSF_V3.csv");
    }
    else
    {
        RooUtil::error(TString::Format("While setting b-tag scale factors, found year = %d that is not recognized.", nt.year()));
    }
    btagReaderTight = new BTagCalibrationReader(BTagEntry::OP_TIGHT, "central", {"up", "down"});
    btagReaderMedium = new BTagCalibrationReader(BTagEntry::OP_MEDIUM, "central", {"up", "down"});
    btagReaderLoose = new BTagCalibrationReader(BTagEntry::OP_LOOSE, "central", {"up", "down"});
    btagReaderTight->load(*btagCalib, BTagEntry::FLAV_B, "comb");
    btagReaderTight->load(*btagCalib, BTagEntry::FLAV_C, "comb");
    btagReaderTight->load(*btagCalib, BTagEntry::FLAV_UDSG, "incl");
    btagReaderMedium->load(*btagCalib, BTagEntry::FLAV_B, "comb");
    btagReaderMedium->load(*btagCalib, BTagEntry::FLAV_C, "comb");
    btagReaderMedium->load(*btagCalib, BTagEntry::FLAV_UDSG, "incl");
    btagReaderLoose->load(*btagCalib, BTagEntry::FLAV_B, "comb");
    btagReaderLoose->load(*btagCalib, BTagEntry::FLAV_C, "comb");
    btagReaderLoose->load(*btagCalib, BTagEntry::FLAV_UDSG, "incl");
    if (nt.year() == 2016)
    {
        btagEffTight_b = new RooUtil::HistMap("data/eff_DeepFlav_102X_2016_ttbar_1lep.root:h2_BTaggingEff_tight_Eff_b");
        btagEffTight_c = new RooUtil::HistMap("data/eff_DeepFlav_102X_2016_ttbar_1lep.root:h2_BTaggingEff_tight_Eff_c");
        btagEffTight_l = new RooUtil::HistMap("data/eff_DeepFlav_102X_2016_ttbar_1lep.root:h2_BTaggingEff_tight_Eff_udsg");
        btagEffLoose_b = new RooUtil::HistMap("data/eff_DeepFlav_102X_2016_ttbar_1lep.root:h2_BTaggingEff_loose_Eff_b");
        btagEffLoose_c = new RooUtil::HistMap("data/eff_DeepFlav_102X_2016_ttbar_1lep.root:h2_BTaggingEff_loose_Eff_c");
        btagEffLoose_l = new RooUtil::HistMap("data/eff_DeepFlav_102X_2016_ttbar_1lep.root:h2_BTaggingEff_loose_Eff_udsg");
    }
    else if (nt.year() == 2017 and isUL)
    {
        btagEffTight_b = new RooUtil::HistMap("data/eff_DeepFlav_106X_2017_ttbar_1lep_lead.root:h2_BTaggingEff_tight_Eff_b");
        btagEffTight_c = new RooUtil::HistMap("data/eff_DeepFlav_106X_2017_ttbar_1lep_lead.root:h2_BTaggingEff_tight_Eff_c");
        btagEffTight_l = new RooUtil::HistMap("data/eff_DeepFlav_106X_2017_ttbar_1lep_lead.root:h2_BTaggingEff_tight_Eff_udsg");
        btagEffLoose_b = new RooUtil::HistMap("data/eff_DeepFlav_106X_2017_ttbar_1lep_lead.root:h2_BTaggingEff_loose_Eff_b");
        btagEffLoose_c = new RooUtil::HistMap("data/eff_DeepFlav_106X_2017_ttbar_1lep_lead.root:h2_BTaggingEff_loose_Eff_c");
        btagEffLoose_l = new RooUtil::HistMap("data/eff_DeepFlav_106X_2017_ttbar_1lep_lead.root:h2_BTaggingEff_loose_Eff_udsg");
        btagEffTight_b_subl = new RooUtil::HistMap("data/eff_DeepFlav_106X_2017_ttbar_1lep_subl.root:h2_BTaggingEff_tight_Eff_b");
        btagEffTight_c_subl = new RooUtil::HistMap("data/eff_DeepFlav_106X_2017_ttbar_1lep_subl.root:h2_BTaggingEff_tight_Eff_c");
        btagEffTight_l_subl = new RooUtil::HistMap("data/eff_DeepFlav_106X_2017_ttbar_1lep_subl.root:h2_BTaggingEff_tight_Eff_udsg");
        btagEffLoose_b_subl = new RooUtil::HistMap("data/eff_DeepFlav_106X_2017_ttbar_1lep_subl.root:h2_BTaggingEff_loose_Eff_b");
        btagEffLoose_c_subl = new RooUtil::HistMap("data/eff_DeepFlav_106X_2017_ttbar_1lep_subl.root:h2_BTaggingEff_loose_Eff_c");
        btagEffLoose_l_subl = new RooUtil::HistMap("data/eff_DeepFlav_106X_2017_ttbar_1lep_subl.root:h2_BTaggingEff_loose_Eff_udsg");
    }
    else if (nt.year() == 2017 and not isUL)
    {
        btagEffTight_b = new RooUtil::HistMap("data/eff_DeepFlav_102X_2017_ttbar_1lep.root:h2_BTaggingEff_tight_Eff_b");
        btagEffTight_c = new RooUtil::HistMap("data/eff_DeepFlav_102X_2017_ttbar_1lep.root:h2_BTaggingEff_tight_Eff_c");
        btagEffTight_l = new RooUtil::HistMap("data/eff_DeepFlav_102X_2017_ttbar_1lep.root:h2_BTaggingEff_tight_Eff_udsg");
        btagEffLoose_b = new RooUtil::HistMap("data/eff_DeepFlav_102X_2017_ttbar_1lep.root:h2_BTaggingEff_loose_Eff_b");
        btagEffLoose_c = new RooUtil::HistMap("data/eff_DeepFlav_102X_2017_ttbar_1lep.root:h2_BTaggingEff_loose_Eff_c");
        btagEffLoose_l = new RooUtil::HistMap("data/eff_DeepFlav_102X_2017_ttbar_1lep.root:h2_BTaggingEff_loose_Eff_udsg");
    }
    else if (nt.year() == 2018 and isUL)
    {
        btagEffTight_b = new RooUtil::HistMap("data/eff_DeepFlav_106X_2018_ttbar_1lep_lead.root:h2_BTaggingEff_tight_Eff_b");
        btagEffTight_c = new RooUtil::HistMap("data/eff_DeepFlav_106X_2018_ttbar_1lep_lead.root:h2_BTaggingEff_tight_Eff_c");
        btagEffTight_l = new RooUtil::HistMap("data/eff_DeepFlav_106X_2018_ttbar_1lep_lead.root:h2_BTaggingEff_tight_Eff_udsg");
        btagEffLoose_b = new RooUtil::HistMap("data/eff_DeepFlav_106X_2018_ttbar_1lep_lead.root:h2_BTaggingEff_loose_Eff_b");
        btagEffLoose_c = new RooUtil::HistMap("data/eff_DeepFlav_106X_2018_ttbar_1lep_lead.root:h2_BTaggingEff_loose_Eff_c");
        btagEffLoose_l = new RooUtil::HistMap("data/eff_DeepFlav_106X_2018_ttbar_1lep_lead.root:h2_BTaggingEff_loose_Eff_udsg");
        btagEffTight_b_subl = new RooUtil::HistMap("data/eff_DeepFlav_106X_2018_ttbar_1lep_subl.root:h2_BTaggingEff_tight_Eff_b");
        btagEffTight_c_subl = new RooUtil::HistMap("data/eff_DeepFlav_106X_2018_ttbar_1lep_subl.root:h2_BTaggingEff_tight_Eff_c");
        btagEffTight_l_subl = new RooUtil::HistMap("data/eff_DeepFlav_106X_2018_ttbar_1lep_subl.root:h2_BTaggingEff_tight_Eff_udsg");
        btagEffLoose_b_subl = new RooUtil::HistMap("data/eff_DeepFlav_106X_2018_ttbar_1lep_subl.root:h2_BTaggingEff_loose_Eff_b");
        btagEffLoose_c_subl = new RooUtil::HistMap("data/eff_DeepFlav_106X_2018_ttbar_1lep_subl.root:h2_BTaggingEff_loose_Eff_c");
        btagEffLoose_l_subl = new RooUtil::HistMap("data/eff_DeepFlav_106X_2018_ttbar_1lep_subl.root:h2_BTaggingEff_loose_Eff_udsg");
    }
    else if (nt.year() == 2018 and not isUL)
    {
        btagEffTight_b = new RooUtil::HistMap("data/eff_DeepFlav_102X_2018_ttbar_1lep.root:h2_BTaggingEff_tight_Eff_b");
        btagEffTight_c = new RooUtil::HistMap("data/eff_DeepFlav_102X_2018_ttbar_1lep.root:h2_BTaggingEff_tight_Eff_c");
        btagEffTight_l = new RooUtil::HistMap("data/eff_DeepFlav_102X_2018_ttbar_1lep.root:h2_BTaggingEff_tight_Eff_udsg");
        btagEffLoose_b = new RooUtil::HistMap("data/eff_DeepFlav_102X_2018_ttbar_1lep.root:h2_BTaggingEff_loose_Eff_b");
        btagEffLoose_c = new RooUtil::HistMap("data/eff_DeepFlav_102X_2018_ttbar_1lep.root:h2_BTaggingEff_loose_Eff_c");
        btagEffLoose_l = new RooUtil::HistMap("data/eff_DeepFlav_102X_2018_ttbar_1lep.root:h2_BTaggingEff_loose_Eff_udsg");
    }
    else
    {
        RooUtil::error(TString::Format("While setting b-tag efficiencies, found year = %d that is not recognized.", nt.year()));
    }

    sig_rewgt = new RooUtil::HistMap("data/gen_reweight.root:signal_rewgt");

    // readerX = new RooUtil::TMVAUtil::ReaderX("BDT", "/nfs-7/userdata/yxiang/BDTResult/dataset/weights/TMVAClassification_BDT.weights.xml"); // 24 variables
    readerX = new RooUtil::TMVAUtil::ReaderX("BDT", "/nfs-7/userdata/yxiang/BDTResult/dataset_19variables/weights/TMVAClassification_BDT.weights.xml");

    // Set up JEC uncertainty tool
    jec_unc = new JetCorrectionUncertainty(
        "NanoTools/NanoCORE/Tools/jetcorr/data/"
        + gconf.jecEraMC 
        + "/"
        + gconf.jecEraMC
        + "_Uncertainty_AK4PFchs.txt"
    ); 

//=============================
//
// Analysis Data Structure
//
//=============================

    //=====================================================================================
    //            Branch Type                    Branch Name                    WriteToTree
    //=====================================================================================
    // Create event level branches
    tx.createBranch  < int                 >   ( "run"                           , true  );
    tx.createBranch  < int                 >   ( "lumi"                          , true  );
    tx.createBranch  < unsigned long long  >   ( "evt"                           , true  );
    tx.createBranch  < float               >   ( "wgt"                           , true  );
    tx.createBranch  < vector<float>       >   ( "scalewgts"                     , true  );
    tx.createBranch  < vector<float>       >   ( "pswgts"                        , true  );
    tx.createBranch  < vector<float>       >   ( "lherewgts"                     , true  );
    tx.createBranch  < float               >   ( "pu_rewgt"                      , true  );
    tx.createBranch  < float               >   ( "pu_rewgt_up"                   , true  );
    tx.createBranch  < float               >   ( "pu_rewgt_dn"                   , true  );

    // Create trigger branches
    tx.createBranch  < int                 >   ( "trig_ee"                       , false );
    tx.createBranch  < int                 >   ( "trig_em"                       , false );
    tx.createBranch  < int                 >   ( "trig_mm"                       , false );
    tx.createBranch  < int                 >   ( "trig_se"                       , false );
    tx.createBranch  < int                 >   ( "trig_sm"                       , false );
    tx.createBranch  < int                 >   ( "pass_duplicate_ee_em_mm"       , false );
    tx.createBranch  < int                 >   ( "pass_duplicate_mm_em_ee"       , false );
    tx.createBranch  < int                 >   ( "is_pd_ee"                      , false );
    tx.createBranch  < int                 >   ( "is_pd_em"                      , false );
    tx.createBranch  < int                 >   ( "is_pd_mm"                      , false );
    tx.createBranch  < int                 >   ( "is_pd_se"                      , false );
    tx.createBranch  < int                 >   ( "is_pd_sm"                      , false );

    // Create met branches
    tx.createBranch  < LV                  >   ( "met_p4"                        , true  );

    // Create gen particle branches
    tx.createBranch  < int                 >   ( "isvbswwh"                      , true  );
    tx.createBranch  < int                 >   ( "iswwhlvlvbb"                   , true  );
    tx.createBranch  < LV                  >   ( "gen_jet0"                      , true  );
    tx.createBranch  < LV                  >   ( "gen_jet1"                      , true  );
    tx.createBranch  < LV                  >   ( "gen_w0"                        , true  );
    tx.createBranch  < LV                  >   ( "gen_w1"                        , true  );
    tx.createBranch  < LV                  >   ( "gen_h"                         , true  );
    tx.createBranch  < LV                  >   ( "gen_lep0"                      , true  );
    tx.createBranch  < LV                  >   ( "gen_lep1"                      , true  );
    tx.createBranch  < LV                  >   ( "gen_lep2"                      , true  );
    tx.createBranch  < LV                  >   ( "gen_nu0"                       , true  );
    tx.createBranch  < LV                  >   ( "gen_nu1"                       , true  );
    tx.createBranch  < LV                  >   ( "gen_b0"                        , true  );
    tx.createBranch  < LV                  >   ( "gen_b1"                        , true  );
    tx.createBranch  < LV                  >   ( "gen_lepA"                      , true  );
    tx.createBranch  < LV                  >   ( "gen_nuA"                       , true  );
    tx.createBranch  < LV                  >   ( "gen_lepB"                      , true  );
    tx.createBranch  < LV                  >   ( "gen_nuB"                       , true  );
    tx.createBranch  < int                 >   ( "gen_sign"                      , true  );
    tx.createBranch  < int                 >   ( "genchannel"                    , true  );
    tx.createBranch  < float               >   ( "genrewgt"                      , true  );
    tx.createBranch  < float               >   ( "gen_cosThetaStarA"             , true  );
    tx.createBranch  < float               >   ( "gen_cosThetaStarB"             , true  );

    // Create scale factor branches
    tx.createBranch  < float               >   ( "lepsf"                         , true  );
    tx.createBranch  < float               >   ( "lepsf_up"                      , true  );
    tx.createBranch  < float               >   ( "lepsf_dn"                      , true  );
    tx.createBranch  < float               >   ( "btagsf"                        , true  );

    // Create lepton branches
    tx.createBranch  < vector<LV>          >   ( "good_leptons_p4"               , false );
    tx.createBranch  < vector<int>         >   ( "good_leptons_pdgid"            , false );
    tx.createBranch  < vector<int>         >   ( "good_leptons_tight"            , false );
    tx.createBranch  < vector<int>         >   ( "good_leptons_jetIdx"           , false );
    tx.createBranch  < vector<int>         >   ( "good_leptons_genPartFlav"      , false );
    tx.createBranch  < vector<float>       >   ( "good_leptons_pfRelIso03_all"   , false );
    tx.createBranch  < vector<float>       >   ( "good_leptons_pfRelIso03_chg"   , false );
    tx.createBranch  < vector<float>       >   ( "good_leptons_jetPtRelv2"       , false );
    tx.createBranch  < vector<float>       >   ( "good_leptons_jetRelIso"        , false );
    tx.createBranch  < vector<float>       >   ( "good_leptons_miniPFRelIso_all" , false );

    // Create tau branches
    tx.createBranch  < vector<LV>          >   ( "good_taus_p4"                  , false );
    tx.createBranch  < vector<int>         >   ( "good_taus_pdgid"               , false );
    tx.createBranch  < vector<int>         >   ( "good_taus_tight"               , false );
    tx.createBranch  < vector<int>         >   ( "good_taus_jetIdx"              , false );
    tx.createBranch  < vector<int>         >   ( "good_taus_genPartFlav"         , false );

    // Create jet branches
    tx.createBranch  < vector<LV>          >   ( "good_jets_p4"                  , false );
    tx.createBranch  < vector<int>         >   ( "good_jets_loose_btagged"       , false );
    tx.createBranch  < vector<int>         >   ( "good_jets_medium_btagged"      , false );
    tx.createBranch  < vector<int>         >   ( "good_jets_tight_btagged"       , false );
    tx.createBranch  < vector<float>       >   ( "good_jets_btag_score"          , false );
    tx.createBranch  < vector<float>       >   ( "good_jets_qg_disc"             , false );
    tx.createBranch  < vector<int>         >   ( "good_jets_flavor"              , false );

    // Create fatjet branches
    tx.createBranch  < vector<LV>          >   ( "good_fatjets_p4"               , false );
    tx.createBranch  < vector<int>         >   ( "good_fatjets_loose"            , false );
    tx.createBranch  < vector<int>         >   ( "good_fatjets_medium"           , false );
    tx.createBranch  < vector<int>         >   ( "good_fatjets_tight"            , false );
    tx.createBranch  < vector<float>       >   ( "good_fatjets_msd"              , false );

    // Create higgs tagged jet branches
    tx.createBranch  < vector<LV>          >   ( "higgs_jets_p4"                 , false );
    tx.createBranch  < vector<int>         >   ( "higgs_jets_loose_btagged"      , false );
    tx.createBranch  < vector<int>         >   ( "higgs_jets_medium_btagged"     , false );
    tx.createBranch  < vector<int>         >   ( "higgs_jets_tight_btagged"      , false );
    tx.createBranch  < vector<float>       >   ( "higgs_jets_btag_score"         , false );
    tx.createBranch  < vector<int>         >   ( "higgs_jets_flavor"             , false );
    tx.createBranch  < vector<int>         >   ( "higgs_jets_good_jets_idx"      , false );
    tx.createBranch  < vector<int>         >   ( "higgs_jets_genmatched"         , false );
    tx.createBranch  < vector<float>       >   ( "higgs_jets_genmatched_dr"      , false );

    // Create vbs tagged jet branches
    tx.createBranch  < vector<LV>          >   ( "vbs_jets_p4"                   , false );
    tx.createBranch  < vector<int>         >   ( "vbs_jets_good_jets_idx"        , false );

    // Create number of b-tagged jets branches
    tx.createBranch  < int                 >   ( "nbloose"                       , true  );
    tx.createBranch  < int                 >   ( "nbmedium"                      , true  );
    tx.createBranch  < int                 >   ( "nbtight"                       , true  );

    // Create jet multiplicity branches
    tx.createBranch  < int                 >   ( "ncenjet30"                     , true  );
    tx.createBranch  < int                 >   ( "njet30"                        , true  );

    // Create 6 fermion vectors
    // lep0 is lead if same flavor
    // lep1 is sublead if same flavor
    // lep0 is electron if emu
    // lep1 is muon if emu
    // lep0 is e or mu if lep-tau
    // lep1 is tau if lep-tau
    tx.createBranch  < LV                  >   ( "lep0"                          , true  );
    tx.createBranch  < LV                  >   ( "lep1"                          , true  );
    tx.createBranch  < int                 >   ( "lep0ID"                        , true  );
    tx.createBranch  < int                 >   ( "lep1ID"                        , true  );
    tx.createBranch  < int                 >   ( "lep0GenPartFlav"               , true  ); // Truth MC information
    tx.createBranch  < int                 >   ( "lep1GenPartFlav"               , true  ); // Truth MC information
    tx.createBranch  < LV                  >   ( "leadlep"                       , true  ); // leading in pt
    tx.createBranch  < LV                  >   ( "subllep"                       , true  ); // subleading in pt
    tx.createBranch  < int                 >   ( "leadlepID"                     , true  ); // PDGID of the lepton leading in pt
    tx.createBranch  < int                 >   ( "subllepID"                     , true  ); // PDGID of the lepton subleading in pt
    tx.createBranch  < int                 >   ( "leadlepGenPartFlav"            , true  ); // Truth MC information
    tx.createBranch  < int                 >   ( "subllepGenPartFlav"            , true  ); // Truth MC information
    tx.createBranch  < LV                  >   ( "b0"                            , true  ); // leading in pt
    tx.createBranch  < LV                  >   ( "b1"                            , true  ); // subleading in pt
    tx.createBranch  < LV                  >   ( "j0"                            , true  ); // leading in pt
    tx.createBranch  < LV                  >   ( "j1"                            , true  ); // subleading in pt
    tx.createBranch  < int                 >   ( "channel"                       , true  ); // 0=tight-ee 1=tight-em 2=tight-mm 3=loose-ee 4=loose-em 5=loose-mm 6=tight-etau 7=tight-mutau
    tx.createBranch  < int                 >   ( "channeldetail"                 , true  ); // 2 * channel +                                                                                ( Mbb in ? 1 : 0)
    tx.createBranch  < int                 >   ( "lepchannel"                    , true  ); // 0=ee 1=em 2=mm 3=etau 4=mtau
    tx.createBranch  < int                 >   ( "btagchannel"                   , true  ); // 0=tight 1=loose
    tx.createBranch  < int                 >   ( "bmatchcateg"                   , true  ); // Truth MC information
    tx.createBranch  < int                 >   ( "mee_noZ"                       , true  ); // if dielectron is ee channel, is the ee within Z mass?
    tx.createBranch  < int                 >   ( "mbbIn"                         , true  ); // mbb < 150? or not?
    tx.createBranch  < int                 >   ( "pass_blind"                    , true  ); // for data, to blind the mbb < 150 region
    tx.createBranch  < int                 >   ( "pass_blind_bdt"                , true  ); // for data, to blind the bdt > 0.543 region or mbb < 150

    tx.createBranch  < int                 >   ( "categ"                         , true  ); // categ 0=e+l+ 1=m+l+ 2=t+l+
    tx.createBranch  < float               >   ( "categ_F"                       , true  ); // categ 0=e+l+ 1=m+l+ 2=t+l+                                                                   ( float version)

    // Create keyvariables worth computing
    tx.createBranch  < float               >   ( "mbb"                           , true  );
    tx.createBranch  < float               >   ( "dphibb"                        , true  );
    tx.createBranch  < float               >   ( "detabb"                        , true  );
    tx.createBranch  < float               >   ( "drbb"                          , true  );
    tx.createBranch  < float               >   ( "ptbb"                          , true  );

    tx.createBranch  < float               >   ( "b0pt"                          , true  );
    tx.createBranch  < float               >   ( "b1pt"                          , true  );
    tx.createBranch  < int                 >   ( "b0tight"                       , true  ); // is the leading in pt b-quark tight tagged
    tx.createBranch  < int                 >   ( "b1tight"                       , true  ); // is the leading in pt b-quark tight tagged

    tx.createBranch  < float               >   ( "mjj"                           , true  );
    tx.createBranch  < float               >   ( "dphijj"                        , true  );
    tx.createBranch  < float               >   ( "detajj"                        , true  );
    tx.createBranch  < float               >   ( "drjj"                          , true  );
    tx.createBranch  < float               >   ( "ptjj"                          , true  );

    tx.createBranch  < float               >   ( "j0pt"                          , true  );
    tx.createBranch  < float               >   ( "j1pt"                          , true  );
    tx.createBranch  < float               >   ( "j_lead_p"                      , true  ); // jet momentum of the jet leading in momentum
    tx.createBranch  < float               >   ( "j_sublead_p"                   , true  ); // jet momentum of the jet subleading in momentum

    tx.createBranch  < float               >   ( "mll"                           , true  );
    tx.createBranch  < float               >   ( "dphill"                        , true  );
    tx.createBranch  < float               >   ( "detall"                        , true  );
    tx.createBranch  < float               >   ( "drll"                          , true  );
    tx.createBranch  < float               >   ( "ptll"                          , true  );

    tx.createBranch  < float               >   ( "l0pt"                          , true  );
    tx.createBranch  < float               >   ( "l1pt"                          , true  );

    tx.createBranch  < float               >   ( "met"                           , true  );

    tx.createBranch  < float               >   ( "lt"                            , true  );
    tx.createBranch  < float               >   ( "st"                            , true  );
    tx.createBranch  < float               >   ( "mvvh"                          , true  );
    tx.createBranch  < float               >   ( "mtvvh"                         , true  );
    tx.createBranch  < float               >   ( "ptvvh"                         , true  );

    tx.createBranch  < float               >   ( "v0pt"                          , true  );
    tx.createBranch  < float               >   ( "v1pt"                          , true  );

    tx.createBranch  < float               >   ( "w0mass"                        , true  );
    tx.createBranch  < float               >   ( "w1mass"                        , true  );

    tx.createBranch  < int                 >   ( "is_ttbar_madgraph"             , true  );
    tx.createBranch  < int                 >   ( "is_ttbar_powheg"               , true  );
    tx.createBranch  < int                 >   ( "is_train"                      , true  );
    tx.createBranch  < int                 >   ( "is_test"                       , true  );
    tx.createBranch  < int                 >   ( "is_signal"                     , true  );
    tx.createBranch  < int                 >   ( "is_background"                 , true  );

    tx.createBranch  < int                 >   ( "is_ps_el"                      , true  );
    tx.createBranch  < int                 >   ( "is_ps_mu"                      , true  );
    tx.createBranch  < int                 >   ( "is_ps_tau"                     , true  );
    tx.createBranch  < int                 >   ( "is_ps_neg"                     , true  );
    tx.createBranch  < int                 >   ( "is_ps_lgt"                     , true  );

    tx.createBranch  < int                 >   ( "is_cut_sr_el"                  , true  );
    tx.createBranch  < int                 >   ( "is_cut_sr_mu"                  , true  );
    tx.createBranch  < int                 >   ( "is_cut_sr_tau"                 , true  );
    tx.createBranch  < int                 >   ( "is_cut_sr_neg"                 , true  );
    tx.createBranch  < int                 >   ( "is_cut_sr_lgt"                 , true  );

    tx.createBranch  < int                 >   ( "is_cut_cr_el"                  , true  );
    tx.createBranch  < int                 >   ( "is_cut_cr_mu"                  , true  );
    tx.createBranch  < int                 >   ( "is_cut_cr_tau"                 , true  );
    tx.createBranch  < int                 >   ( "is_cut_cr_neg"                 , true  );
    tx.createBranch  < int                 >   ( "is_cut_cr_lgt"                 , true  );

    tx.createBranch  < int                 >   ( "is_cut_sr2_el"                 , true  );
    tx.createBranch  < int                 >   ( "is_cut_sr2_mu"                 , true  );
    tx.createBranch  < int                 >   ( "is_cut_sr2_tau"                , true  );
    tx.createBranch  < int                 >   ( "is_cut_sr2_neg"                , true  );

    tx.createBranch  < int                 >   ( "is_cut_cr2_el"                 , true  );
    tx.createBranch  < int                 >   ( "is_cut_cr2_mu"                 , true  );
    tx.createBranch  < int                 >   ( "is_cut_cr2_tau"                , true  );
    tx.createBranch  < int                 >   ( "is_cut_cr2_neg"                , true  );

    tx.createBranch  < int                 >   ( "is_bdt_sr_el"                  , true  );
    tx.createBranch  < int                 >   ( "is_bdt_sr_mu"                  , true  );
    tx.createBranch  < int                 >   ( "is_bdt_sr_tau"                 , true  );
    tx.createBranch  < int                 >   ( "is_bdt_sr_neg"                 , true  );

    tx.createBranch  < int                 >   ( "is_bdt_cr_el"                  , true  );
    tx.createBranch  < int                 >   ( "is_bdt_cr_mu"                  , true  );
    tx.createBranch  < int                 >   ( "is_bdt_cr_tau"                 , true  );
    tx.createBranch  < int                 >   ( "is_bdt_cr_neg"                 , true  );

    tx.createBranch  < int                 >   ( "is_bdt_sr2_el"                 , true  );
    tx.createBranch  < int                 >   ( "is_bdt_sr2_mu"                 , true  );
    tx.createBranch  < int                 >   ( "is_bdt_sr2_tau"                , true  );
    tx.createBranch  < int                 >   ( "is_bdt_sr2_neg"                , true  );

    tx.createBranch  < int                 >   ( "is_bdt_cr2_el"                 , true  );
    tx.createBranch  < int                 >   ( "is_bdt_cr2_mu"                 , true  );
    tx.createBranch  < int                 >   ( "is_bdt_cr2_tau"                , true  );
    tx.createBranch  < int                 >   ( "is_bdt_cr2_neg"                , true  );

    tx.createBranch  < int                 >   ( "is_ps"                         , true  );
    tx.createBranch  < int                 >   ( "is_cut_sr"                     , true  );
    tx.createBranch  < int                 >   ( "is_cut_cr"                     , true  );
    tx.createBranch  < int                 >   ( "is_cut_sr2"                    , true  );
    tx.createBranch  < int                 >   ( "is_cut_cr2"                    , true  );
    tx.createBranch  < int                 >   ( "is_bdt_sr"                     , true  );
    tx.createBranch  < int                 >   ( "is_bdt_cr"                     , true  );
    tx.createBranch  < int                 >   ( "is_bdt_sr2"                    , true  );
    tx.createBranch  < int                 >   ( "is_bdt_cr2"                    , true  );

    tx.createBranch  < float               >   ( "xsec_sf"                       , true  );
    tx.createBranch  < float               >   ( "bdt"                           , true  );
    tx.createBranch  < float               >   ( "bdt_mbboff"                    , true  );

//=============================
//
// Common Selections
//
//=============================

    //********************************
    // - Signal Gen Level Particles
    //********************************
    // Description: If signal sample, select the gen level particles
    cutflow.addCut("SelectSignalGenPart",
        [&]()
        {
            if (looper.getCurrentFileName().Contains("VBSWmpWmpHToLNuLNu_C2V"))
            {
                processGenParticles_VBSWWH();
            }
            if (looper.getCurrentFileName().Contains("VBSWmpWmpH_C2V"))
            {
                processGenParticles_VBSWWH_UL();
            }
            if (looper.getCurrentFileName().Contains("VBSWWHTo"))
            {
                processGenParticles_VBSWWH();
            }
            return true;
        }, UNITY);


    //*****************************
    // Weighting each MC event
    //*****************************
    // Description: Weighting each event to 137/fb
    cutflow.addCutToLastActiveCut("InitialFilter",
        [&]()
        {

            std::vector<int> charges;
            std::vector<LV> good_leptons_p4;
            std::vector<LV> good_taus_p4;
            std::vector<int> good_leptons_jetIdx;

            // Select muons
            for (unsigned int imu = 0; imu < nt.Muon_pt().size(); ++imu)
            {
                if (not (nt.Muon_p4()[imu].pt() > 40.)) continue;
                if (not (ttH::muonID(imu, ttH::IDtight, nt.year()))) continue;
                charges.push_back(nt.Muon_charge()[imu]);
                good_leptons_p4.push_back(nt.Muon_p4()[imu]);
                good_leptons_jetIdx.push_back(nt.Muon_jetIdx()[imu]);
            }

            // Select muons
            for (unsigned int iel = 0; iel < nt.Electron_pt().size(); ++iel)
            {
                if (not (nt.Electron_p4()[iel].pt() > 40.)) continue;
                if (not (ttH::electronID(iel, ttH::IDtight, nt.year()))) continue;
                charges.push_back(nt.Electron_charge()[iel]);
                good_leptons_p4.push_back(nt.Electron_p4()[iel]);
                good_leptons_jetIdx.push_back(nt.Electron_jetIdx()[iel]);
            }

            // Select taus
            for (unsigned int itau = 0; itau < nt.nTau(); ++itau)
            {
                if (not (nt.Tau_p4()[itau].pt() > 40.)) continue;
                if (ttH::tauID(itau, ttH::IDtight, nt.year()))
                {
                    // tau-(non-tau lep) overlap removal
                    bool save_this_tau = true;

                    for (unsigned int ilep = 0; ilep < good_leptons_p4.size(); ++ilep)
                    {
                        if (RooUtil::Calc::DeltaR(nt.Tau_p4().at(itau), good_leptons_p4.at(ilep)) < 0.4)
                        {
                            save_this_tau = false;
                            break;
                        }
                    }

                    if (!save_this_tau)
                    {
                        continue;
                    }
                    charges.push_back(nt.Tau_charge()[itau]);
                    good_taus_p4.push_back(nt.Tau_p4()[itau]);
                }
            }

            if (charges.size() != 2)
                return false;

            if (looper.getCurrentFileName().Contains("_OS/"))
            {
                if (not (charges[0] * charges[1] < 0))
                    return false;
            }
            else
            {
                if (not (charges[0] * charges[1] > 0))
                    return false;
            }

            // Loop over the jets
            int njets20 = 0;
            int njets30 = 0;
            for (unsigned int ijet = 0; ijet < nt.Jet_pt().size(); ++ijet)
            {

                // Read jet p4
                const LV& jet_p4 = nt.Jet_p4()[ijet];

                if (nt.year() == 2016)
                {
                    if (nt.Jet_jetId()[ijet] < 1) // For 2016 apparently it's >= 1
                        continue;
                }
                else
                {
                    if (nt.Jet_jetId()[ijet] < 2) // "Tight" ID requirement while for others >= 2
                        continue;
                }

                // if (nt.year() == 2017)
                // {
                //     if (nt.Jet_puId()[ijet] < 7) // For 2017 "111" (pass tight)
                //         continue;
                // }

                // Overlap check against good leptons
                bool isOverlap = false;
                for (unsigned int ilep = 0; ilep < good_leptons_jetIdx.size(); ++ilep)
                {
                    if (good_leptons_jetIdx.at(ilep) == (int) ijet)
                    {
                        isOverlap = true;
                        break;
                    }
                }

                for (unsigned int itau = 0; itau < good_taus_p4.size(); ++itau)
                {
                    if (RooUtil::Calc::DeltaR(good_taus_p4.at(itau), jet_p4) < 0.4)
                    {
                        isOverlap = true;
                        break;
                    }
                }

                // Then skip
                if (isOverlap)
                    continue;

                if (not (jet_p4.pt() > 20.))
                    continue;

                njets20++;

                if (not (jet_p4.pt() > 30.))
                    continue;

                njets30++;

            }

            if (not (njets20 >= 4))
                return false;

            if (not (njets30 >= 2))
                return false;

            return true;

        }, UNITY);

    //*****************************
    // Weighting each MC event
    //*****************************
    // Description: Weighting each event to 137/fb
    cutflow.addCutToLastActiveCut("Weight",
        [&]()
        {
            // Set event level variables that would be processed for the given event regardless
            tx.setBranch<int>("run", nt.run());
            tx.setBranch<int>("lumi", nt.luminosityBlock());
            tx.setBranch<unsigned long long>("evt", nt.event());
            tx.setBranch<LV>("met_p4", RooUtil::Calc::getLV(nt.MET_pt(), 0, nt.MET_phi(), 0));
            return 1/*set your cut here*/;
        },
        [&]()
        {
            if (nt.isData())
            {
                tx.setBranch<float>("wgt", 1.);
            }
            else
            {
                float wgt = ((nt.Generator_weight() > 0) - (nt.Generator_weight() < 0)) * scale1fb;
                tx.setBranch<float>("wgt", wgt * gconf.lumi);
                if (isUL)
                {
                    tx.setBranch<float>("pu_rewgt", pileUpReweightUL(nt.Pileup_nTrueInt(), nt.year()));
                    tx.setBranch<float>("pu_rewgt_up", pileUpReweightUpUL(nt.Pileup_nTrueInt(), nt.year()));
                    tx.setBranch<float>("pu_rewgt_dn", pileUpReweightDownUL(nt.Pileup_nTrueInt(), nt.year()));
                }
                else
                {
                    tx.setBranch<float>("pu_rewgt", pileUpReweight(nt.Pileup_nTrueInt(), nt.year()));
                    tx.setBranch<float>("pu_rewgt_up", pileUpReweightUp(nt.Pileup_nTrueInt(), nt.year()));
                    tx.setBranch<float>("pu_rewgt_dn", pileUpReweightDown(nt.Pileup_nTrueInt(), nt.year()));
                }
                if (hasLHEScaleWeight)
                {
                    for (unsigned int i = 0; i < nt.LHEScaleWeight().size(); ++i)
                    {
                        tx.pushbackToBranch<float>("scalewgts", nt.LHEScaleWeight()[i]);
                    }
                }
                if (hasPSWeight)
                {
                    for (unsigned int i = 0; i < nt.PSWeight().size(); ++i)
                    {
                        tx.pushbackToBranch<float>("pswgts", nt.PSWeight()[i]);
                    }
                }
                if (hasLHEReweightingWeight)
                {
                    for (unsigned int i = 0; i < nt.LHEReweightingWeight().size(); ++i)
                    {
                        tx.pushbackToBranch<float>("lherewgts", nt.LHEReweightingWeight()[i]);
                    }
                }
            }
            return tx.getBranch<float>("wgt");
        });

    //*****************************
    // - NanoAOD level preselection
    //*****************************
    // Description: Select at least two leptons in NanoAOD with 20 GeV and above
    cutflow.addCutToLastActiveCut("Preselection",
        [&]()
        {

            int nel20 = 0;
            int nmu20 = 0;
            int ntau20 = 0;
            std::vector<int> el20_idx;
            std::vector<int> mu20_idx;
            std::vector<int> tau20_idx;

            // loop over electrons to count electrons above 20 GeV
            for (unsigned int idx = 0; idx < nt.Electron_pt().size(); ++idx)
            {
                float el_pt = nt.Electron_pt()[idx];
                if (el_pt > 20)
                {
                    nel20++;
                    el20_idx.push_back(idx);
                }
            }

            // loop over muons to count muons above 20 GeV
            for (unsigned int idx = 0; idx < nt.Muon_pt().size(); ++idx)
            {
                float mu_pt = nt.Muon_pt()[idx];
                if (mu_pt > 20)
                {
                    nmu20++;
                    mu20_idx.push_back(idx);
                }
            }

            // loop over taus to count taus above 20 GeV
            for (unsigned int idx = 0; idx < nt.Tau_pt().size(); ++idx)
            {
                float tau_pt = nt.Tau_pt()[idx];
                if (tau_pt > 20)
                {
                    ntau20++;
                    tau20_idx.push_back(idx);
                }
            }

            // return true if more than or equals to 2 leptons
            return nel20 + nmu20 + ntau20 >= 2;
        },
        UNITY);
}



//________________________________________________________________________________________________________________________________________
void VBSHWW::initSRCutflow()
{

    //********************************
    // - Selecting Gen Level Particles
    //********************************
    // Description: If signal sample, select the gen level particles
    cutflow.addCutToLastActiveCut("SelectGenPart",
        [&]()
        {
            if (looper.getCurrentFileName().Contains("TTWJetsToLNu")
                or looper.getCurrentFileName().Contains("TTJets_")
                or looper.getCurrentFileName().Contains("TTZTo")
               )
            {
                processGenParticles_TopBackgrounds();
            }
            return true;
        }, UNITY);

    // Description: If signal sample, select the gen level particles
    cutflow.addCutToLastActiveCut("ReweightGen",
        [&]()
        {
            float rewgt = 1;
            if (looper.getCurrentFileName().Contains("VBSWmpWmpH_C2V"))
            {
                if (tx.getBranch<int>("iswwhlvlvbb"))
                {
                    if (looper.getCurrentFileName().Contains("VBSWmpWmpH_C2V"))
                    {
                        rewgt = sig_rewgt->eval(tx.getBranch<float>("gen_cosThetaStarA"));
                        rewgt *= sig_rewgt->eval(tx.getBranch<float>("gen_cosThetaStarB"));
                    }
                }
            }
            tx.setBranch<float>("genrewgt", rewgt);
            return true;
        }, UNITY);

    //************************************
    // - Selecting Good Runs List for data
    //************************************
    cutflow.addCutToLastActiveCut("GoodRunsList",
        [&]()
        {
            if (nt.isData())
            {
                if (goodrun(nt.run(), nt.luminosityBlock()))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return true;
            }
        }, UNITY);

    //*****************************
    // - Applying MET event filters
    //*****************************
    cutflow.addCutToLastActiveCut("EventFilters",
        [&]()
        {

            bool filterflag   = false;
            bool filterflagMC = false;
            switch (nt.year())
            {
                case 2016:
                    filterflag   = nt.Flag_goodVertices() and nt.Flag_globalSuperTightHalo2016Filter() and nt.Flag_HBHENoiseFilter() and nt.Flag_HBHENoiseIsoFilter() and nt.Flag_EcalDeadCellTriggerPrimitiveFilter() and nt.Flag_BadPFMuonFilter();
                    filterflagMC = nt.Flag_goodVertices() and                                              nt.Flag_HBHENoiseFilter() and nt.Flag_HBHENoiseIsoFilter() and nt.Flag_EcalDeadCellTriggerPrimitiveFilter() and nt.Flag_BadPFMuonFilter();
                    break;
                case 2017:
                    if (isUL)
                    {
                        filterflag   = nt.Flag_goodVertices() and nt.Flag_globalSuperTightHalo2016Filter() and nt.Flag_HBHENoiseFilter() and nt.Flag_HBHENoiseIsoFilter() and nt.Flag_EcalDeadCellTriggerPrimitiveFilter() and nt.Flag_BadPFMuonFilter() and nt.Flag_ecalBadCalibFilter();
                        filterflagMC = nt.Flag_goodVertices() and                                              nt.Flag_HBHENoiseFilter() and nt.Flag_HBHENoiseIsoFilter() and nt.Flag_EcalDeadCellTriggerPrimitiveFilter() and nt.Flag_BadPFMuonFilter() and nt.Flag_ecalBadCalibFilter();
                    }
                    else
                    {
                        filterflag   = nt.Flag_goodVertices() and nt.Flag_globalSuperTightHalo2016Filter() and nt.Flag_HBHENoiseFilter() and nt.Flag_HBHENoiseIsoFilter() and nt.Flag_EcalDeadCellTriggerPrimitiveFilter() and nt.Flag_BadPFMuonFilter() and nt.Flag_ecalBadCalibFilterV2();
                        filterflagMC = nt.Flag_goodVertices() and                                              nt.Flag_HBHENoiseFilter() and nt.Flag_HBHENoiseIsoFilter() and nt.Flag_EcalDeadCellTriggerPrimitiveFilter() and nt.Flag_BadPFMuonFilter() and nt.Flag_ecalBadCalibFilterV2();
                    }
                    break;
                case 2018:
                    if (isUL)
                    {
                        filterflag   = nt.Flag_goodVertices() and nt.Flag_globalSuperTightHalo2016Filter() and nt.Flag_HBHENoiseFilter() and nt.Flag_HBHENoiseIsoFilter() and nt.Flag_EcalDeadCellTriggerPrimitiveFilter() and nt.Flag_BadPFMuonFilter() and nt.Flag_ecalBadCalibFilter();
                        filterflagMC = nt.Flag_goodVertices() and                                              nt.Flag_HBHENoiseFilter() and nt.Flag_HBHENoiseIsoFilter() and nt.Flag_EcalDeadCellTriggerPrimitiveFilter() and nt.Flag_BadPFMuonFilter() and nt.Flag_ecalBadCalibFilter();
                    }
                    else
                    {
                        filterflag   = nt.Flag_goodVertices() and nt.Flag_globalSuperTightHalo2016Filter() and nt.Flag_HBHENoiseFilter() and nt.Flag_HBHENoiseIsoFilter() and nt.Flag_EcalDeadCellTriggerPrimitiveFilter() and nt.Flag_BadPFMuonFilter() and nt.Flag_ecalBadCalibFilterV2();
                        filterflagMC = nt.Flag_goodVertices() and                                              nt.Flag_HBHENoiseFilter() and nt.Flag_HBHENoiseIsoFilter() and nt.Flag_EcalDeadCellTriggerPrimitiveFilter() and nt.Flag_BadPFMuonFilter() and nt.Flag_ecalBadCalibFilterV2();
                    }
                    break;
            }
            if (nt.isData())
            {
                return filterflag;
            }
            else
            {
                return filterflagMC;
            }
        }, UNITY);

    //*****************************
    // - Selecting Analysis Leptons
    //*****************************
    // Description: Select leptons used for the analysis
    //              The electrons / muons / taus definitions are in NanoCORE/Electron(Muon/Tau)Selections.cc
    cutflow.addCutToLastActiveCut("SelectLeptons",
        [&]()
        {
            // Lepton sf
            float lepsf = 1.;
            // Percent errors (up/down) on sf
            float err_up = 0.;
            float err_dn = 0.;

            // Select muons
            for (unsigned int imu = 0; imu < nt.Muon_pt().size(); ++imu)
            {
                if (ttH::muonID(imu, ttH::IDveto, nt.year()))
                {
                    tx.pushbackToBranch<LV>("good_leptons_p4", nt.Muon_p4()[imu]);
                    tx.pushbackToBranch<int>("good_leptons_pdgid", (-nt.Muon_charge()[imu]) * 13);
                    tx.pushbackToBranch<int>("good_leptons_tight", ttH::muonID(imu, ttH::IDtight, nt.year()));
                    tx.pushbackToBranch<int>("good_leptons_jetIdx", nt.Muon_jetIdx()[imu]);
                    tx.pushbackToBranch<int>("good_leptons_genPartFlav", nt.isData() ? -999 : nt.Muon_genPartFlav()[imu]);
                    tx.pushbackToBranch<float>("good_leptons_pfRelIso03_all", nt.Muon_pfRelIso03_all()[imu]);
                    tx.pushbackToBranch<float>("good_leptons_pfRelIso03_chg", -999);
                    tx.pushbackToBranch<float>("good_leptons_jetPtRelv2", nt.Muon_jetPtRelv2()[imu]);
                    tx.pushbackToBranch<float>("good_leptons_jetRelIso", nt.Muon_jetRelIso()[imu]);
                    tx.pushbackToBranch<float>("good_leptons_miniPFRelIso_all", nt.Muon_miniPFRelIso_all()[imu]);
                    float mu_eta = nt.Muon_eta()[imu];
                    float mu_pt = nt.Muon_pt()[imu];
                    // medium POG ID -> loose ttH ID -> tight ttH ID
                    // NOTE: POG ID SF are folded into the ttH
                    lepsf *= ttH::getMuonLooseSF(mu_eta, mu_pt, nt.year());
                    lepsf *= ttH::getMuonTightSF(mu_eta, mu_pt, nt.year());
                    err_up += std::pow(ttH::getMuonTTHSFErr(mu_eta, mu_pt, nt.year(), true), 2);
                    err_dn += std::pow(ttH::getMuonTTHSFErr(mu_eta, mu_pt, nt.year(), false), 2);
                }
            }

            // Select electrons
            for (unsigned int iel = 0; iel < nt.Electron_pt().size(); ++iel)
            {
                if (ttH::electronID(iel, ttH::IDveto, nt.year()))
                {
                    tx.pushbackToBranch<LV>("good_leptons_p4", nt.Electron_p4()[iel]);
                    tx.pushbackToBranch<int>("good_leptons_pdgid", (-nt.Electron_charge()[iel]) * 11);
                    tx.pushbackToBranch<int>("good_leptons_tight", ttH::electronID(iel, ttH::IDtight, nt.year()));
                    tx.pushbackToBranch<int>("good_leptons_jetIdx", nt.Electron_jetIdx()[iel]);
                    tx.pushbackToBranch<int>("good_leptons_genPartFlav", nt.isData() ? -999 : nt.Electron_genPartFlav()[iel]);
                    tx.pushbackToBranch<float>("good_leptons_pfRelIso03_all", nt.Electron_pfRelIso03_all()[iel]);
                    tx.pushbackToBranch<float>("good_leptons_pfRelIso03_chg", nt.Electron_pfRelIso03_chg()[iel]);
                    tx.pushbackToBranch<float>("good_leptons_jetPtRelv2", nt.Electron_jetPtRelv2()[iel]);
                    tx.pushbackToBranch<float>("good_leptons_jetRelIso", nt.Electron_jetRelIso()[iel]);
                    tx.pushbackToBranch<float>("good_leptons_miniPFRelIso_all", nt.Electron_miniPFRelIso_all()[iel]);
                    float el_eta = nt.Electron_eta()[iel];
                    float el_pt = nt.Electron_pt()[iel];
                    if (isUL)
                    {
                        // event -> reco
                        lepsf *= ttH::getElecRecoEffSFUL(el_eta, el_pt, nt.year());
                        err_up += std::pow(ttH::getElecRecoEffSFULErr(el_eta, el_pt, nt.year()), 2);
                        err_dn += std::pow(ttH::getElecRecoEffSFULErr(el_eta, el_pt, nt.year()), 2);
                    }
                    else
                    {
                        // event -> reco
                        lepsf *= ttH::getElecRecoEffSF(el_eta, el_pt, nt.year());
                        err_up += std::pow(ttH::getElecRecoEffSFErr(el_eta, el_pt, nt.year()), 2);
                        err_dn += std::pow(ttH::getElecRecoEffSFErr(el_eta, el_pt, nt.year()), 2);
                    }
                    // reco -> loose POG ID
                    lepsf *= ttH::getElecPOGLooseSF(el_eta, el_pt, nt.year());
                    err_up += std::pow(ttH::getElecPOGLooseSFErr(el_eta, el_pt, nt.year()), 2);
                    err_dn += std::pow(ttH::getElecPOGLooseSFErr(el_eta, el_pt, nt.year()), 2);
                    // loose POG ID -> loose ttH ID -> tight ttH ID
                    lepsf *= ttH::getElecLooseSF(el_eta, el_pt, nt.year());
                    lepsf *= ttH::getElecTightSF(el_eta, el_pt, nt.year());
                    err_up += std::pow(ttH::getElecTTHSFErr(el_eta, el_pt, nt.year(), true), 2);
                    err_dn += std::pow(ttH::getElecTTHSFErr(el_eta, el_pt, nt.year(), false), 2);
                }
            }

            tx.sortVecBranchesByPt(
                /* name of the 4vector branch to use to pt sort by*/
                "good_leptons_p4",
                /* names of any associated vector<float> branches to sort along */
                {
                    "good_leptons_pfRelIso03_all",
                    "good_leptons_pfRelIso03_chg",
                    "good_leptons_jetPtRelv2",
                    "good_leptons_jetRelIso",
                    "good_leptons_miniPFRelIso_all"
                },
                /* names of any associated vector<int>   branches to sort along */
                {
                    "good_leptons_pdgid",
                    "good_leptons_tight",
                    "good_leptons_jetIdx",
                    "good_leptons_genPartFlav",
                },
                /* names of any associated vector<bool>  branches to sort along */
                {}
            );

            // Select taus
            const vector<LV>& good_leptons_p4 = tx.getBranchLazy<vector<LV>>("good_leptons_p4");
            const vector<int>& good_leptons_pdgid = tx.getBranchLazy<vector<int>>("good_leptons_pdgid");
            for (unsigned int itau = 0; itau < nt.nTau(); ++itau)
            {
                if (ttH::tauID(itau, ttH::IDfakable, nt.year()))
                {
                    // tau-(non-tau lep) overlap removal
                    bool save_this_tau = true;

                    for (unsigned int ilep = 0; ilep < good_leptons_p4.size(); ++ilep)
                    {
                        if (RooUtil::Calc::DeltaR(nt.Tau_p4().at(itau), good_leptons_p4.at(ilep)) < 0.4)
                        {
                            save_this_tau = false;
                            break;
                        }
                    }

                    if (!save_this_tau)
                    {
                        continue;
                    }

                    // Only save >= loose taus that do not overlap w/ a 'good' lepton
                    tx.pushbackToBranch<LV>("good_taus_p4", nt.Tau_p4()[itau]);
                    tx.pushbackToBranch<int>("good_taus_genPartFlav", nt.isData() ? -999 : nt.Tau_genPartFlav()[itau]);
                    tx.pushbackToBranch<int>("good_taus_pdgid", (-nt.Tau_charge()[itau]) * 15);
                    tx.pushbackToBranch<int>("good_taus_tight", ttH::tauID(itau, ttH::IDtight, nt.year()));
                    tx.pushbackToBranch<int>("good_taus_jetIdx", nt.Tau_jetIdx()[itau]);
                    float tau_pt = nt.Tau_pt()[itau];
                    float tau_eta = nt.Tau_eta()[itau];
                    float tau_gflav = nt.isData() ? -999 : nt.Tau_genPartFlav()[itau];
                    // DeepTau vs. jets sf
                    float vs_jet_sf = nt.isData() ? 1 : tauSF_vsJet->getSFvsPT(tau_pt, tau_gflav);
                    lepsf *= vs_jet_sf;
                    err_up += nt.isData() ? 0 : std::pow((tauSF_vsJet->getSFvsPT(tau_pt, tau_gflav, "Up") - vs_jet_sf)/vs_jet_sf, 2);
                    err_dn += nt.isData() ? 0 : std::pow((vs_jet_sf - tauSF_vsJet->getSFvsPT(tau_pt, tau_gflav, "Down"))/vs_jet_sf, 2);
                    // DeepTau vs. muons sf
                    float vs_mu_sf = nt.isData() ? 1 : tauSF_vsMu->getSFvsEta(fabs(tau_eta), tau_gflav);
                    lepsf *= vs_mu_sf;
                    err_up += nt.isData() ? 0 : std::pow((tauSF_vsMu->getSFvsEta(fabs(tau_eta), tau_gflav, "Up") - vs_mu_sf)/vs_mu_sf, 2);
                    err_dn += nt.isData() ? 0 : std::pow((vs_mu_sf - tauSF_vsMu->getSFvsEta(fabs(tau_eta), tau_gflav, "Down"))/vs_mu_sf, 2);
                    // DeepTau vs. electrons sf
                    float vs_el_sf = nt.isData() ? 1 : tauSF_vsEl->getSFvsEta(fabs(tau_eta), tau_gflav);
                    lepsf *= vs_el_sf;
                    err_up += nt.isData() ? 0 : std::pow((tauSF_vsEl->getSFvsEta(fabs(tau_eta), tau_gflav, "Up") - vs_el_sf)/vs_el_sf, 2);
                    err_dn += nt.isData() ? 0 : std::pow((vs_el_sf - tauSF_vsEl->getSFvsEta(fabs(tau_eta), tau_gflav, "Down"))/vs_el_sf, 2);
                }
            }

            tx.sortVecBranchesByPt(
                /* name of the 4vector branch to use to pt sort by*/
                "good_taus_p4",
                /* names of any associated vector<float> branches to sort along */
                {},
                /* names of any associated vector<int>   branches to sort along */
                {
                    "good_taus_pdgid",
                    "good_taus_tight",
                    "good_taus_jetIdx",
                    "good_taus_genPartFlav"
                },
                /* names of any associated vector<bool>  branches to sort along */
                {}
                );

            // Finish the error computation
            err_up = std::sqrt(err_up);
            err_dn = std::sqrt(err_dn);

            // Set the lepton scale factor weight
            tx.setBranch<float>("lepsf", nt.isData() ? 1. : lepsf);
            tx.setBranch<float>("lepsf_up", nt.isData() ? 1. : lepsf + err_up * lepsf);
            tx.setBranch<float>("lepsf_dn", nt.isData() ? 1. : lepsf - err_dn * lepsf);

            return true;

        },
        UNITY);

    //*****************************
    // - Select Good Reco Jets
    //*****************************
    // Description: Select Good Reco Jets
    //              - TODO TODO TODO TODO : Check pileup jet ID for year 2017
    //              - Perform overlap removal against loose leptons
    //              - Accept jets above 20 GeV for the container
    //              - Count N btagged jets (nbloose, nbmedium, nbtight)
    //              - Count central and all jets with pt > 30 GeV
    //              - Save the jets into good_jets containers
    cutflow.addCutToLastActiveCut("SelectJets",
        [&]()
        {

            // b tagging counters
            int nbloose = 0;
            int nbmedium = 0;
            int nbtight = 0;

            int ncenjet30 = 0;
            int njet30 = 0;

            // Loop over the jets
            for (unsigned int ijet = 0; ijet < nt.Jet_pt().size(); ++ijet)
            {

                // Read jet p4
                LV jet_p4 = nt.Jet_p4()[ijet];
                // Apply up/down corrections
                if (jecvar == 1 || jecvar == -1)
                {
                    jec_unc->setJetEta(jet_p4.eta());
                    jec_unc->setJetPt(jet_p4.pt());
                    float jec_err = abs(jec_unc->getUncertainty(jecvar == 1))*jecvar;
                    jet_p4 *= (1. + jec_err);
                }

                if (nt.year() == 2016)
                {
                    if (nt.Jet_jetId()[ijet] < 1) // For 2016 apparently it's >= 1
                        continue;
                }
                else
                {
                    if (nt.Jet_jetId()[ijet] < 2) // "Tight" ID requirement while for others >= 2
                        continue;
                }

                // if (nt.year() == 2017)
                // {
                //     if (nt.Jet_puId()[ijet] < 7) // For 2017 "111" (pass tight)
                //         continue;
                // }

                // Overlap check against good leptons
                bool isOverlap = false;
                for (unsigned int ilep = 0; ilep < tx.getBranchLazy<vector<LV>>("good_leptons_p4").size(); ++ilep)
                {
                    if (tx.getBranchLazy<vector<int>>("good_leptons_jetIdx").at(ilep) == (int) ijet)
                    {
                        isOverlap = true;
                        break;
                    }
                }

                for (unsigned int itau = 0; itau < tx.getBranchLazy<vector<LV>>("good_taus_p4").size(); ++itau)
                {
                    if (RooUtil::Calc::DeltaR(tx.getBranchLazy<vector<LV>>("good_taus_p4").at(itau), jet_p4) < 0.4)
                    {
                        isOverlap = true;
                        break;
                    }
                }

                // Then skip
                if (isOverlap)
                    continue;

                // B-tagging is done down to 20 GeV
                if (not (jet_p4.pt() > 20.))
                    continue;

                bool is_loose_btagged = false;
                bool is_medium_btagged = false;
                bool is_tight_btagged = false;

                // B-tagging is also done up to 2.4 in eta only
                if (abs(jet_p4.eta()) < 2.4)
                {
                    // Check if it passes btagging
                    is_loose_btagged = nt.Jet_btagDeepFlavB()[ijet] > gconf.WP_DeepFlav_loose;
                    is_medium_btagged = nt.Jet_btagDeepFlavB()[ijet] > gconf.WP_DeepFlav_medium;
                    is_tight_btagged = nt.Jet_btagDeepFlavB()[ijet] > gconf.WP_DeepFlav_tight;

                    // Count up the btagging
                    if (is_loose_btagged) nbloose++;
                    if (is_medium_btagged) nbmedium++;
                    if (is_tight_btagged) nbtight++;
                }

                tx.pushbackToBranch<LV>("good_jets_p4", jet_p4);
                tx.pushbackToBranch<int>("good_jets_loose_btagged", is_loose_btagged);
                tx.pushbackToBranch<int>("good_jets_medium_btagged", is_medium_btagged);
                tx.pushbackToBranch<int>("good_jets_tight_btagged", is_tight_btagged);
                tx.pushbackToBranch<float>("good_jets_btag_score", nt.Jet_btagDeepFlavB()[ijet]);
                tx.pushbackToBranch<float>("good_jets_qg_disc", nt.Jet_qgl()[ijet]);
                tx.pushbackToBranch<int>("good_jets_flavor", nt.isData() ? -999 : nt.Jet_hadronFlavour()[ijet]);

                if (abs(jet_p4.eta()) < 3.0 and jet_p4.pt() > 30.)
                {
                    ncenjet30 ++;
                }
                if (jet_p4.pt() > 30.)
                {
                    njet30 ++;
                }

            }

            tx.setBranch<int>("nbloose", nbloose);
            tx.setBranch<int>("nbmedium", nbmedium);
            tx.setBranch<int>("nbtight", nbtight);
            tx.setBranch<int>("ncenjet30", ncenjet30);
            tx.setBranch<int>("njet30", njet30);

            tx.sortVecBranchesByPt(
                    /* name of the 4vector branch to use to pt sort by*/               "good_jets_p4",
                    /* names of any associated vector<float> branches to sort along */ {"good_jets_btag_score", "good_jets_qg_disc"},
                    /* names of any associated vector<int>   branches to sort along */ {"good_jets_loose_btagged", "good_jets_medium_btagged", "good_jets_tight_btagged", "good_jets_flavor"},
                    /* names of any associated vector<bool>  branches to sort along */ {}
                    );

            // Loop over the jets
            for (unsigned int ifatjet = 0; ifatjet < nt.FatJet_pt().size(); ++ifatjet)
            {

                // Read jet p4
                const LV& jet_p4 = nt.FatJet_p4()[ifatjet];

                // Overlap check against good leptons
                bool isOverlap = false;
                for (unsigned int ilep = 0; ilep < tx.getBranchLazy<vector<LV>>("good_leptons_p4").size(); ++ilep)
                {
                    if (RooUtil::Calc::DeltaR(tx.getBranchLazy<vector<LV>>("good_leptons_p4")[ilep], jet_p4) < 0.8)
                    {
                        isOverlap = true;
                        break;
                    }
                }

                for (unsigned int itau = 0; itau < tx.getBranchLazy<vector<LV>>("good_taus_p4").size(); ++itau)
                {
                    if (RooUtil::Calc::DeltaR(tx.getBranchLazy<vector<LV>>("good_taus_p4").at(itau), jet_p4) < 0.4)
                    {
                        isOverlap = true;
                        break;
                    }
                }

                // Then skip
                if (isOverlap)
                    continue;

                // FatJet pt preselection is 250 GeV as Hbb tagger SF starts at 250 GeV.
                if (not (jet_p4.pt() > 250.))
                    continue;

                bool is_loose_btagged = false;
                bool is_medium_btagged = false;
                bool is_tight_btagged = false;

                // B-tagging is also done up to 2.4 in eta only
                if (abs(jet_p4.eta()) < 2.4)
                {
                    // Check if it passes btagging
                    if (nt.year() == 2018)
                    {
                        is_loose_btagged = nt.FatJet_btagDDBvL()[ifatjet] > 0.7; // 85% after SF
                        is_medium_btagged = nt.FatJet_btagDDBvL()[ifatjet] > 0.86; // 55% after SF
                        is_tight_btagged = nt.FatJet_btagDDBvL()[ifatjet] > 0.91; // 30% after SF
                    }
                }

                tx.pushbackToBranch<LV>("good_fatjets_p4", jet_p4);
                tx.pushbackToBranch<int>("good_fatjets_loose", is_loose_btagged);
                tx.pushbackToBranch<int>("good_fatjets_medium", is_medium_btagged);
                tx.pushbackToBranch<int>("good_fatjets_tight", is_tight_btagged);
                tx.pushbackToBranch<float>("good_fatjets_msd", nt.FatJet_msoftdrop()[ifatjet]);


            }

            tx.sortVecBranchesByPt(
                    /* name of the 4vector branch to use to pt sort by*/               "good_fatjets_p4",
                    /* names of any associated vector<float> branches to sort along */ {"good_fatjets_msd"},
                    /* names of any associated vector<int>   branches to sort along */ {"good_fatjets_loose", "good_fatjets_medium", "good_fatjets_tight"},
                    /* names of any associated vector<bool>  branches to sort along */ {}
                    );

            return true;
        },
        UNITY);

    //**************************************************
    // - Selecting Trigger and removing duplicate events
    //**************************************************
    cutflow.addCutToLastActiveCut("Trigger",
        [&]()
        {

            bool is_pd_ee = looper.getCurrentFileName().Contains("DoubleEG") or looper.getCurrentFileName().Contains("EGamma");
            bool is_pd_em = looper.getCurrentFileName().Contains("MuonEG");
            bool is_pd_mm = looper.getCurrentFileName().Contains("DoubleMuon");
            bool is_pd_se = looper.getCurrentFileName().Contains("SingleElectron") or looper.getCurrentFileName().Contains("EGamma");
            bool is_pd_sm = looper.getCurrentFileName().Contains("SingleMuon");
            bool pass_duplicate_ee_em_mm = false;
            bool pass_duplicate_mm_em_ee = false;

            bool trig_ee = false;
            bool trig_em = false;
            bool trig_mm = false;
            bool trig_se = false;
            bool trig_sm = false;

            bool Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ                = false;
            bool Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL                   = false;
            bool Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8        = false;
            bool Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ          = false;
            bool Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL             = false;
            bool Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ = false;
            bool Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL    = false;
            bool Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ  = false;
            bool Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL     = false;

            try { Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ                 = nt.HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ();                } catch (std::runtime_error) { Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ                 = false; } // Lowest unprescaled
            try { Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL                    = nt.HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL();                   } catch (std::runtime_error) { Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL                    = false; } // Lowest unprescaled
            try { Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8         = nt.HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8();        } catch (std::runtime_error) { Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8         = false; } // Lowest unprescaled for >= 2017C
            try { Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ           = nt.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ();          } catch (std::runtime_error) { Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ           = false; }
            try { Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL              = nt.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL();             } catch (std::runtime_error) { Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL              = false; } // Lowest unprescaled
            try { Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ  = nt.HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ(); } catch (std::runtime_error) { Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ  = false; } // Lowest unprescaled
            try { Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL     = nt.HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL();    } catch (std::runtime_error) { Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL     = false; }
            try { Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ   = nt.HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ();  } catch (std::runtime_error) { Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ   = false; } // Lowest unprescaled
            try { Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL      = nt.HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL();     } catch (std::runtime_error) { Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL      = false; }

            bool Common_HLT_Ele27_WPTight_Gsf        = false;
            bool Common_HLT_Ele25_eta2p1_WPTight_Gsf = false;
            bool Common_HLT_Ele35_WPTight_Gsf        = false;
            bool Common_HLT_Ele32_WPTight_Gsf        = false;
            try { Common_HLT_Ele27_WPTight_Gsf        = nt.HLT_Ele27_WPTight_Gsf();        } catch (std::runtime_error) { Common_HLT_Ele27_WPTight_Gsf        = false; }
            try { Common_HLT_Ele25_eta2p1_WPTight_Gsf = nt.HLT_Ele25_eta2p1_WPTight_Gsf(); } catch (std::runtime_error) { Common_HLT_Ele25_eta2p1_WPTight_Gsf = false; }
            try { Common_HLT_Ele35_WPTight_Gsf        = nt.HLT_Ele35_WPTight_Gsf();        } catch (std::runtime_error) { Common_HLT_Ele35_WPTight_Gsf        = false; }
            try { Common_HLT_Ele32_WPTight_Gsf        = nt.HLT_Ele32_WPTight_Gsf();        } catch (std::runtime_error) { Common_HLT_Ele32_WPTight_Gsf        = false; }

            bool Common_HLT_IsoMu24   = false;
            bool Common_HLT_IsoTkMu24 = false;
            bool Common_HLT_IsoMu27   = false;
            try { Common_HLT_IsoMu24   = nt.HLT_IsoMu24();   } catch (std::runtime_error) { Common_HLT_IsoMu24   = false; }
            try { Common_HLT_IsoTkMu24 = nt.HLT_IsoTkMu24(); } catch (std::runtime_error) { Common_HLT_IsoTkMu24 = false; }
            try { Common_HLT_IsoMu27   = nt.HLT_IsoMu27();   } catch (std::runtime_error) { Common_HLT_IsoMu27   = false; }

            switch (nt.year())
            {
                case 2016:
                    trig_ee = Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ;
                    trig_em = Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL or Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL or
                        Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ or Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ;
                    trig_mm = Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ or
                        Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL;
                    break;
                case 2017:
                    trig_ee = Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL;
                    trig_em = Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ or Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ;
                    trig_mm = Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8;
                    break;
                case 2018:
                    trig_ee = Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL;
                    trig_em = Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ or Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ;
                    trig_mm = Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8;
                    break;
            }

            if (is_pd_ee)
            {
                if (trig_ee)
                    pass_duplicate_ee_em_mm = true;
                if (not trig_mm and not trig_em and trig_ee)
                    pass_duplicate_mm_em_ee = true;
            }
            else if (is_pd_em)
            {
                if (not trig_ee and trig_em)
                    pass_duplicate_ee_em_mm = true;
                if (not trig_mm and trig_em)
                    pass_duplicate_mm_em_ee = true;
            }
            else if (is_pd_mm)
            {
                if (not trig_ee and not trig_em and trig_mm)
                    pass_duplicate_ee_em_mm = true;
                if (trig_mm)
                    pass_duplicate_mm_em_ee = true;
            }

            switch (nt.year())
            {
                case 2016:
                    trig_se = Common_HLT_Ele27_WPTight_Gsf or Common_HLT_Ele25_eta2p1_WPTight_Gsf;
                    break;
                case 2017:
                    trig_se = Common_HLT_Ele35_WPTight_Gsf;
                    break;
                case 2018:
                    trig_se = Common_HLT_Ele32_WPTight_Gsf;
                    break;
            }

            switch (nt.year())
            {
                case 2016:
                    trig_sm = Common_HLT_IsoMu24 or Common_HLT_IsoTkMu24;
                    break;
                case 2017:
                    trig_sm = Common_HLT_IsoMu27;
                    break;
                case 2018:
                    trig_sm = Common_HLT_IsoMu24;
                    break;
            }

            // Create trigger branches
            tx.setBranch<int>("trig_ee", trig_ee);
            tx.setBranch<int>("trig_em", trig_em);
            tx.setBranch<int>("trig_mm", trig_mm);
            tx.setBranch<int>("trig_se", trig_se);
            tx.setBranch<int>("trig_sm", trig_sm);
            tx.setBranch<int>("pass_duplicate_ee_em_mm", pass_duplicate_ee_em_mm);
            tx.setBranch<int>("pass_duplicate_mm_em_ee", pass_duplicate_mm_em_ee);
            tx.setBranch<int>("is_pd_ee", is_pd_ee);
            tx.setBranch<int>("is_pd_em", is_pd_em);
            tx.setBranch<int>("is_pd_mm", is_pd_mm);
            tx.setBranch<int>("is_pd_se", is_pd_se);
            tx.setBranch<int>("is_pd_sm", is_pd_sm);

            return true;

        }, UNITY);

    //*******************************
    // - Select Two Same-Sign Leptons
    //*******************************
    cutflow.addCutToLastActiveCut("ObjectsSelection", UNITY, UNITY);

    //*******************************
    // - Select Two Same-Sign Leptons
    //*******************************
    cutflow.addCutToLastActiveCut("SSPreselection",
        [&]()
        {

            // At least one loose light lepton
            if (not (tx.getBranchLazy<vector<LV>>("good_leptons_p4").size() >= 1))
                return false;

            // Only two loose leptons
            if (not (tx.getBranchLazy<vector<LV>>("good_leptons_p4").size() + tx.getBranchLazy<vector<LV>>("good_taus_p4").size() == 2))
                return false;

            int ntight = 0;
            for (auto& istight : tx.getBranch<vector<int>>("good_leptons_tight"))
            {
                if (istight)
                    ntight++;
            }

            for (auto& istight : tx.getBranchLazy<vector<int>>("good_taus_tight"))
            {
                if (istight)
                    ntight++;
            }

            // Select only two tight leptons
            if (not (ntight == 2))
                return false;
            // // Select only two tight leptons
            // if (not (ntight == 1))
            //     return false;

            // Therefore I will only have two leptons in the good_leptons container
            const int& pdgid0 = tx.getBranchLazy<vector<int>>("good_leptons_pdgid")[0];
            const int& pdgid1 = tx.getBranchLazy<vector<int>>("good_leptons_pdgid").size() == 2 ? tx.getBranchLazy<vector<int>>("good_leptons_pdgid")[1] : tx.getBranchLazy<vector<int>>("good_taus_pdgid")[0];

            // if (
            //     looper.getCurrentFileName().Contains("/VBSHWWNanoSkim_v40/")
            //     or looper.getCurrentFileName().Contains("/VBSHWWNanoSkim_v60/")
            //     or looper.getCurrentFileName().Contains("/VBSHWWNanoSkim_v70_SS/")
            //     or looper.getCurrentFileName().Contains("/VBSHWWNanoSkim_v2.0_SS/")
            //     or looper.getCurrentFileName().Contains("/VBSHWWNanoSkim_v2.1_SS/")
            //     or looper.getCurrentFileName().Contains("/VBSHWWNanoSkim_v2.2_SS/")
            //     )
            // {
            //     // Require same sign
            //     if (not (pdgid0 * pdgid1 > 0))
            //         return false;
            // }
            // else if (
            //     looper.getCurrentFileName().Contains("/VBSHWWNanoSkim_v41/")
            //     or looper.getCurrentFileName().Contains("/VBSHWWNanoSkim_v44/")
            //     or looper.getCurrentFileName().Contains("/VBSHWWNanoSkim_v70_OS/")
            //     or looper.getCurrentFileName().Contains("/VBSHWWNanoSkim_v2.1_OS/")
            //     or looper.getCurrentFileName().Contains("/VBSHWWNanoSkim_v2.2_OS/")
            //     )
            // {
            //     // Require opposite sign
            //     if (not (pdgid0 * pdgid1 < 0))
            //         return false;
            // }

            const float& pt0 = tx.getBranchLazy<vector<LV>>("good_leptons_p4")[0].pt();
            const float& pt1 = tx.getBranchLazy<vector<LV>>("good_leptons_p4").size() == 2 ? tx.getBranchLazy<vector<LV>>("good_leptons_p4")[1].pt() : tx.getBranchLazy<vector<LV>>("good_taus_p4")[0].pt();

            // Set the channel
            int lepchannel = -1;
            if (tx.getBranch<vector<LV>>("good_leptons_p4").size() == 2)
            {
                if (abs(tx.getBranch<vector<int>>("good_leptons_pdgid")[0]) * abs(tx.getBranch<vector<int>>("good_leptons_pdgid")[1]) == 121)
                    lepchannel = 0;
                else if (abs(tx.getBranch<vector<int>>("good_leptons_pdgid")[0]) * abs(tx.getBranch<vector<int>>("good_leptons_pdgid")[1]) == 143)
                    lepchannel = 1;
                else if (abs(tx.getBranch<vector<int>>("good_leptons_pdgid")[0]) * abs(tx.getBranch<vector<int>>("good_leptons_pdgid")[1]) == 169)
                    lepchannel = 2;
            }
            else // It has to be good_leptons_p4.size() == 1 by now
            {
                if (abs(tx.getBranch<vector<int>>("good_leptons_pdgid")[0]) == 11)
                    lepchannel = 3;
                else if (abs(tx.getBranch<vector<int>>("good_leptons_pdgid")[0]) == 13)
                    lepchannel = 4;
            }

            tx.setBranch<int>("lepchannel", lepchannel);

            // lep0 is lead if same flavor
            // lep1 is sublead if same flavor
            // lep0 is electron if emu
            // lep1 is muon if emu
            // lep0 is e or mu if lep-tau
            // lep1 is tau if lep-tau
            switch (lepchannel)
            {
                case 0:
                    tx.setBranch<LV>("lep0", tx.getBranch<vector<LV>>("good_leptons_p4")[0]);
                    tx.setBranch<LV>("lep1", tx.getBranch<vector<LV>>("good_leptons_p4")[1]);
                    tx.setBranch<int>("lep0ID", tx.getBranch<vector<int>>("good_leptons_pdgid")[0]);
                    tx.setBranch<int>("lep1ID", tx.getBranch<vector<int>>("good_leptons_pdgid")[1]);
                    tx.setBranch<int>("lep0GenPartFlav", tx.getBranch<vector<int>>("good_leptons_genPartFlav")[0]);
                    tx.setBranch<int>("lep1GenPartFlav", tx.getBranch<vector<int>>("good_leptons_genPartFlav")[1]);
                    break;
                case 1:
                    tx.setBranch<LV>("lep0", abs(tx.getBranch<vector<int>>("good_leptons_pdgid")[0]) == 11 ? tx.getBranch<vector<LV>>("good_leptons_p4")[0] : tx.getBranch<vector<LV>>("good_leptons_p4")[1]);
                    tx.setBranch<LV>("lep1", abs(tx.getBranch<vector<int>>("good_leptons_pdgid")[0]) == 11 ? tx.getBranch<vector<LV>>("good_leptons_p4")[1] : tx.getBranch<vector<LV>>("good_leptons_p4")[0]);
                    tx.setBranch<int>("lep0ID", abs(tx.getBranch<vector<int>>("good_leptons_pdgid")[0]) == 11 ? tx.getBranch<vector<int>>("good_leptons_pdgid")[0] : tx.getBranch<vector<int>>("good_leptons_pdgid")[1]);
                    tx.setBranch<int>("lep1ID", abs(tx.getBranch<vector<int>>("good_leptons_pdgid")[0]) == 11 ? tx.getBranch<vector<int>>("good_leptons_pdgid")[1] : tx.getBranch<vector<int>>("good_leptons_pdgid")[0]);
                    tx.setBranch<int>("lep0GenPartFlav", abs(tx.getBranch<vector<int>>("good_leptons_genPartFlav")[0]) == 11 ? tx.getBranch<vector<int>>("good_leptons_genPartFlav")[0] : tx.getBranch<vector<int>>("good_leptons_genPartFlav")[1]);
                    tx.setBranch<int>("lep1GenPartFlav", abs(tx.getBranch<vector<int>>("good_leptons_genPartFlav")[0]) == 11 ? tx.getBranch<vector<int>>("good_leptons_genPartFlav")[1] : tx.getBranch<vector<int>>("good_leptons_genPartFlav")[0]);
                    break;
                case 2:
                    tx.setBranch<LV>("lep0", tx.getBranch<vector<LV>>("good_leptons_p4")[0]);
                    tx.setBranch<LV>("lep1", tx.getBranch<vector<LV>>("good_leptons_p4")[1]);
                    tx.setBranch<int>("lep0ID", tx.getBranch<vector<int>>("good_leptons_pdgid")[0]);
                    tx.setBranch<int>("lep1ID", tx.getBranch<vector<int>>("good_leptons_pdgid")[1]);
                    tx.setBranch<int>("lep0GenPartFlav", tx.getBranch<vector<int>>("good_leptons_genPartFlav")[0]);
                    tx.setBranch<int>("lep1GenPartFlav", tx.getBranch<vector<int>>("good_leptons_genPartFlav")[1]);
                    break;
                case 3:
                    tx.setBranch<LV>("lep0", tx.getBranch<vector<LV>>("good_leptons_p4")[0]);
                    tx.setBranch<LV>("lep1", tx.getBranch<vector<LV>>("good_taus_p4")[0]);
                    tx.setBranch<int>("lep0ID", tx.getBranch<vector<int>>("good_leptons_pdgid")[0]);
                    tx.setBranch<int>("lep1ID", tx.getBranch<vector<int>>("good_taus_pdgid")[0]);
                    tx.setBranch<int>("lep0GenPartFlav", tx.getBranch<vector<int>>("good_leptons_genPartFlav")[0]);
                    tx.setBranch<int>("lep1GenPartFlav", tx.getBranch<vector<int>>("good_taus_genPartFlav")[0]);
                    break;
                case 4:
                    tx.setBranch<LV>("lep0", tx.getBranch<vector<LV>>("good_leptons_p4")[0]);
                    tx.setBranch<LV>("lep1", tx.getBranch<vector<LV>>("good_taus_p4")[0]);
                    tx.setBranch<int>("lep0ID", tx.getBranch<vector<int>>("good_leptons_pdgid")[0]);
                    tx.setBranch<int>("lep1ID", tx.getBranch<vector<int>>("good_taus_pdgid")[0]);
                    tx.setBranch<int>("lep0GenPartFlav", tx.getBranch<vector<int>>("good_leptons_genPartFlav")[0]);
                    tx.setBranch<int>("lep1GenPartFlav", tx.getBranch<vector<int>>("good_taus_genPartFlav")[0]);
                    break;
            }
            tx.setBranch<LV>("leadlep", tx.getBranch<LV>("lep0").pt() > tx.getBranch<LV>("lep1").pt() ? tx.getBranch<LV>("lep0") : tx.getBranch<LV>("lep1"));
            tx.setBranch<LV>("subllep", tx.getBranch<LV>("lep0").pt() > tx.getBranch<LV>("lep1").pt() ? tx.getBranch<LV>("lep1") : tx.getBranch<LV>("lep0"));
            tx.setBranch<int>("leadlepID", tx.getBranch<LV>("lep0").pt() > tx.getBranch<LV>("lep1").pt() ? tx.getBranch<int>("lep0ID") : tx.getBranch<int>("lep1ID"));
            tx.setBranch<int>("subllepID", tx.getBranch<LV>("lep0").pt() > tx.getBranch<LV>("lep1").pt() ? tx.getBranch<int>("lep1ID") : tx.getBranch<int>("lep0ID"));
            tx.setBranch<int>("leadlepGenPartFlav", tx.getBranch<LV>("lep0").pt() > tx.getBranch<LV>("lep1").pt() ? tx.getBranch<int>("lep0GenPartFlav") : tx.getBranch<int>("lep1GenPartFlav"));
            tx.setBranch<int>("subllepGenPartFlav", tx.getBranch<LV>("lep0").pt() > tx.getBranch<LV>("lep1").pt() ? tx.getBranch<int>("lep1GenPartFlav") : tx.getBranch<int>("lep0GenPartFlav"));

            // To veto same-sign dielectron on-Z (charge flip)
            int mee_noZ = (not (lepchannel == 0 and abs((tx.getBranch<LV>("lep0")+tx.getBranch<LV>("lep1")).mass() - 91.1876) < 15. and (tx.getBranch<int>("lep0ID") * tx.getBranch<int>("lep1ID") == 121))); // if ee channel and mll is on-Z
            tx.setBranch<int>("mee_noZ", mee_noZ);

            if (not mee_noZ) // reject events with dielectrons being on-Z (charge flip from likely Z+jets)
                return false;

            if (not (pt0 > 40. and pt1 > 40.))
                return false;

            if (lepchannel <= 2 and lepchannel >= 0)
            {
                const int& trig_ee = tx.getBranch<int>("trig_ee");
                const int& trig_em = tx.getBranch<int>("trig_em");
                const int& trig_mm = tx.getBranch<int>("trig_mm");
                const int& pass_duplicate_ee_em_mm = tx.getBranch<int>("pass_duplicate_ee_em_mm");
                bool pass_trigger = trig_ee or trig_em or trig_mm;
                bool duplicate = nt.isData() ? pass_duplicate_ee_em_mm : 1.;
                return (pass_trigger and duplicate);
            }
            else if (tx.getBranch<int>("lepchannel") == 3)
            {
                const int& is_pd_se = tx.getBranch<int>("is_pd_se");
                const int& trig_se = tx.getBranch<int>("trig_se");
                return nt.isData() ? (is_pd_se and trig_se) : trig_se == 1;
            }
            else if (tx.getBranch<int>("lepchannel") == 4)
            {
                const int& is_pd_sm = tx.getBranch<int>("is_pd_sm");
                const int& trig_sm = tx.getBranch<int>("trig_sm");
                return nt.isData() ? (is_pd_sm and trig_sm) : trig_sm == 1;
            }
            else
            {
                return false;
            }

        },
        [&]() { return tx.getBranch<float>("lepsf"); } );
        // UNITY);

    cutflow.addCutToLastActiveCut("NjetGeq4",
        [&]()
        {
            // std::cout <<  " looper.getCurrentEventIndex(): " << looper.getCurrentEventIndex() <<  std::endl;
            // std::cout <<  " tx.getBranch<vector<LV>>('good_jets_p4').size(): " << tx.getBranch<vector<LV>>("good_jets_p4").size() <<  std::endl;
            if (tx.getBranchLazy<vector<LV>>("good_jets_p4").size() < 4)
                return false;
            return true;

        },
        UNITY);


    //*****************************
    // - Tag Hbb jets
    //*****************************
    // Description: Select the two b-tagged jets with highest btagging score as Hbb jets and require two highest bjets pass tight
    cutflow.addCutToLastActiveCut("AK4CategTagHiggsJets",
        [&]()
        {
           // If less than two jets skip entirely
           if (tx.getBranchLazy<vector<LV>>("good_jets_p4").size() < 2)
               return false;

            // get scores and indices pairs
            std::vector<std::pair<float, int>> btag_jets;
            for (unsigned int i = 0; i < tx.getBranch<vector<LV>>("good_jets_p4").size(); i++)
            {
                const LV& bp4 = tx.getBranch<vector<LV>>("good_jets_p4")[i];
                float btag_score = tx.getBranch<vector<float>>("good_jets_btag_score")[i];
                if (abs(bp4.eta()) > 2.4) // If the jet is outside of 2.4 set the btag score to -999 so that we don't choose them
                {
                    btag_score = -999.f;
                }
                btag_jets.push_back(std::make_pair(btag_score, i));
            }

            // // printing
            // for (auto& item : btag_jets)
            // {
            //     std::cout <<  " item.first: " << item.first <<  std::endl;
            //     std::cout <<  " item.second: " << item.second <<  std::endl;
            // }

            // Sort the pairs
            std::sort(btag_jets.begin(), btag_jets.end(),
                    [](const std::pair<float, int> & a, const std::pair<float, int> & b) -> bool
                    {
                        return a.first > b.first;
                    });

            int higgs_jet_0 = btag_jets[0].second < btag_jets[1].second ? btag_jets[0].second : btag_jets[1].second;
            int higgs_jet_1 = btag_jets[0].second < btag_jets[1].second ? btag_jets[1].second : btag_jets[0].second;

            // std::cout <<  " higgs_jet_0: " << higgs_jet_0 <<  std::endl;
            // std::cout <<  " higgs_jet_1: " << higgs_jet_1 <<  std::endl;

            tx.pushbackToBranch<LV>("higgs_jets_p4", tx.getBranch<vector<LV>>("good_jets_p4")[higgs_jet_0]);
            tx.pushbackToBranch<int>("higgs_jets_loose_btagged", tx.getBranch<vector<int>>("good_jets_loose_btagged")[higgs_jet_0]);
            tx.pushbackToBranch<int>("higgs_jets_medium_btagged", tx.getBranch<vector<int>>("good_jets_medium_btagged")[higgs_jet_0]);
            tx.pushbackToBranch<int>("higgs_jets_tight_btagged", tx.getBranch<vector<int>>("good_jets_tight_btagged")[higgs_jet_0]);
            tx.pushbackToBranch<float>("higgs_jets_btag_score", tx.getBranch<vector<float>>("good_jets_btag_score")[higgs_jet_0]);
            tx.pushbackToBranch<int>("higgs_jets_flavor", tx.getBranch<vector<int>>("good_jets_flavor")[higgs_jet_0]);
            tx.pushbackToBranch<int>("higgs_jets_good_jets_idx", higgs_jet_0);

            tx.pushbackToBranch<LV>("higgs_jets_p4", tx.getBranch<vector<LV>>("good_jets_p4")[higgs_jet_1]);
            tx.pushbackToBranch<int>("higgs_jets_loose_btagged", tx.getBranch<vector<int>>("good_jets_loose_btagged")[higgs_jet_1]);
            tx.pushbackToBranch<int>("higgs_jets_medium_btagged", tx.getBranch<vector<int>>("good_jets_medium_btagged")[higgs_jet_1]);
            tx.pushbackToBranch<int>("higgs_jets_tight_btagged", tx.getBranch<vector<int>>("good_jets_tight_btagged")[higgs_jet_1]);
            tx.pushbackToBranch<float>("higgs_jets_btag_score", tx.getBranch<vector<float>>("good_jets_btag_score")[higgs_jet_1]);
            tx.pushbackToBranch<int>("higgs_jets_flavor", tx.getBranch<vector<int>>("good_jets_flavor")[higgs_jet_1]);
            tx.pushbackToBranch<int>("higgs_jets_good_jets_idx", higgs_jet_1);

            if (tx.isBranchSet<LV>("gen_b0"))
            {
                std::vector<LV> reco_bs = {tx.getBranch<vector<LV>>("good_jets_p4")[higgs_jet_0], tx.getBranch<vector<LV>>("good_jets_p4")[higgs_jet_1]};
                std::vector<LV> gen_bs = {tx.getBranch<LV>("gen_b0"), tx.getBranch<LV>("gen_b1")};

                std::vector<int> idxs = RooUtil::Calc::hungarianDeltaRMatching(reco_bs, gen_bs);

                float reco_b_match_dr_0 = RooUtil::Calc::DeltaR(reco_bs[0], gen_bs[idxs[0]]);
                float reco_b_match_dr_1 = RooUtil::Calc::DeltaR(reco_bs[1], gen_bs[idxs[1]]);
                int reco_b_match_0 = reco_b_match_dr_0 < 0.4;
                int reco_b_match_1 = reco_b_match_dr_1 < 0.4;

                tx.pushbackToBranch<int>("higgs_jets_genmatched", reco_b_match_1);
                tx.pushbackToBranch<float>("higgs_jets_genmatched_dr", reco_b_match_dr_1);
                tx.pushbackToBranch<int>("higgs_jets_genmatched", reco_b_match_0);
                tx.pushbackToBranch<float>("higgs_jets_genmatched_dr", reco_b_match_dr_0);

                int bmatchcateg = reco_b_match_0 + reco_b_match_1;
                tx.setBranch<int>("bmatchcateg", bmatchcateg);
            }
            else
            {
                tx.pushbackToBranch<int>("higgs_jets_genmatched", 0);
                tx.pushbackToBranch<float>("higgs_jets_genmatched_dr", -999);
                tx.pushbackToBranch<int>("higgs_jets_genmatched", 0);
                tx.pushbackToBranch<float>("higgs_jets_genmatched_dr", -999);
                tx.setBranch<int>("bmatchcateg", -1);
            }

            // Set the tagged higgs jets
            tx.setBranch<LV>("b0", tx.getBranch<vector<LV>>("higgs_jets_p4")[0]);
            tx.setBranch<LV>("b1", tx.getBranch<vector<LV>>("higgs_jets_p4")[1]);
            float mbb = (tx.getBranch<LV>("b0")+tx.getBranch<LV>("b1")).mass();
            // int mbbIn = mbb > 90. and mbb < 140.;
            int mbbIn = mbb < 150.;
            tx.setBranch<int>("mbbIn", mbbIn);

            // Require at least one of them pass a tight and another pass loose
            const int& btight0 = tx.getBranch<vector<int>>("higgs_jets_tight_btagged")[0];
            const int& btight1 = tx.getBranch<vector<int>>("higgs_jets_tight_btagged")[1];
            const int& bloose0 = tx.getBranch<vector<int>>("higgs_jets_loose_btagged")[0];
            const int& bloose1 = tx.getBranch<vector<int>>("higgs_jets_loose_btagged")[1];
            int btagchannel = -999;
            if (btight0 and btight1)
            {
                btagchannel = 0;
            }
            else if (btight0 and bloose1)
            {
                btagchannel = 1;
            }
            else if (bloose0 and btight1)
            {
                btagchannel = 1;
            }
            else
            {
                btagchannel = -1;
            }
            tx.setBranch<int>("btagchannel", btagchannel);
            setBTagSF(
                {tx.getBranch<LV>("b0").pt(), tx.getBranch<LV>("b1").pt()},
                {tx.getBranch<LV>("b0").eta(), tx.getBranch<LV>("b1").eta()},
                {tx.getBranch<vector<float>>("higgs_jets_btag_score")[0], tx.getBranch<vector<float>>("higgs_jets_btag_score")[1]},
                {tx.getBranch<vector<int>>("higgs_jets_flavor")[0], tx.getBranch<vector<int>>("higgs_jets_flavor")[1]}
                );
            // std::cout <<  " looper.getCurrentEventIndex(): " << looper.getCurrentEventIndex() <<  std::endl;
            // std::cout <<  " tx.getBranch<LV>('b0').pt(): " << tx.getBranch<LV>("b0").pt() <<  " tx.getBranch<LV>('b1').pt(): " << tx.getBranch<LV>("b1").pt() <<  std::endl;
            // std::cout <<  " tx.getBranch<vector<LV>>('good_jets_p4').size(): " << tx.getBranch<vector<LV>>("good_jets_p4").size() <<  std::endl;

            return true;
        }, UNITY);

    //*****************************
    // - Tag VBS jets
    //*****************************
    // Description: Select two jets that are not part of the Hbb jets to be VBS jets with following algorithm
    //              - If all jets are in same hemisphere (eta > 0 or eta < 0) then choose the two leading jets in P (N.B. not pt!)
    //              - If not choose the leading jet in each hemisphere leading in P (N.B. not pt!)
    cutflow.addCutToLastActiveCut("AK4CategTagVBSJets",
        [&]()
        {

            // higgs jet indices
            const int& higgs_jet_0 = tx.getBranch<vector<int>>("higgs_jets_good_jets_idx")[0];
            const int& higgs_jet_1 = tx.getBranch<vector<int>>("higgs_jets_good_jets_idx")[1];
            // good jets p4
            const vector<LV>& good_jets_p4 = tx.getBranch<vector<LV>>("good_jets_p4");

            // Select VBS candidates
            std::vector<int> vbs_jet_cands_idxs;
            for (unsigned int i = 0; i < good_jets_p4.size(); i++)
            {
                if ((int) i != higgs_jet_0 and (int) i != higgs_jet_1)
                {
                    if (good_jets_p4[i].pt() >= 30.)
                    {
                        vbs_jet_cands_idxs.push_back(i);
                    }
                }
            }

            if (vbs_jet_cands_idxs.size() < 2)
                return false;

            if (vbs_jet_cands_idxs.size() == 2)
            {
                tx.pushbackToBranch<LV>("vbs_jets_p4", good_jets_p4[vbs_jet_cands_idxs[0]]);
                tx.pushbackToBranch<LV>("vbs_jets_p4", good_jets_p4[vbs_jet_cands_idxs[1]]);
                tx.pushbackToBranch<int>("vbs_jets_good_jets_idx", vbs_jet_cands_idxs[0]);
                tx.pushbackToBranch<int>("vbs_jets_good_jets_idx", vbs_jet_cands_idxs[1]);
                // Set the vbs jets
                tx.setBranch<LV>("j0", good_jets_p4[vbs_jet_cands_idxs[0]]);
                tx.setBranch<LV>("j1", good_jets_p4[vbs_jet_cands_idxs[1]]);
            }
            else
            {

                // Otherwise, I have 3 or more vbs candidate jets
                std::vector<std::pair<float, int>> vbs_pos_eta_jets;
                std::vector<std::pair<float, int>> vbs_neg_eta_jets;
                for (unsigned int ijet = 0; ijet < vbs_jet_cands_idxs.size(); ijet++)
                {
                    const LV& jet = good_jets_p4[vbs_jet_cands_idxs[ijet]];
                    const float& P = good_jets_p4[vbs_jet_cands_idxs[ijet]].P();
                    if (jet.eta() >= 0)
                    {
                        vbs_pos_eta_jets.push_back(std::make_pair(P, vbs_jet_cands_idxs[ijet]));
                    }
                    if (jet.eta() < 0)
                    {
                        vbs_neg_eta_jets.push_back(std::make_pair(P, vbs_jet_cands_idxs[ijet]));
                    }
                }

                // Sort the pairs
                std::sort(vbs_pos_eta_jets.begin(), vbs_pos_eta_jets.end(),
                          [](const std::pair<float, int> & a, const std::pair<float, int> & b) -> bool
                          {
                              return a.first > b.first;
                          });

                // Sort the pairs
                std::sort(vbs_neg_eta_jets.begin(), vbs_neg_eta_jets.end(),
                          [](const std::pair<float, int> & a, const std::pair<float, int> & b) -> bool
                          {
                              return a.first > b.first;
                          });

                int vbs_jet_idx_A = -999;
                int vbs_jet_idx_B = -999;
                if (vbs_pos_eta_jets.size() == 0)
                {
                    vbs_jet_idx_A = vbs_neg_eta_jets[0].second;
                    vbs_jet_idx_B = vbs_neg_eta_jets[1].second;
                }
                else if (vbs_neg_eta_jets.size() == 0)
                {
                    vbs_jet_idx_A = vbs_pos_eta_jets[0].second;
                    vbs_jet_idx_B = vbs_pos_eta_jets[1].second;
                }
                else
                {
                    vbs_jet_idx_A = vbs_pos_eta_jets[0].second;
                    vbs_jet_idx_B = vbs_neg_eta_jets[0].second;
                }

                int vbs_jet_idx_0 = vbs_jet_idx_A < vbs_jet_idx_B ? vbs_jet_idx_A : vbs_jet_idx_B;
                int vbs_jet_idx_1 = vbs_jet_idx_A < vbs_jet_idx_B ? vbs_jet_idx_B : vbs_jet_idx_A;

                tx.pushbackToBranch<LV>("vbs_jets_p4", good_jets_p4[vbs_jet_idx_0]);
                tx.pushbackToBranch<LV>("vbs_jets_p4", good_jets_p4[vbs_jet_idx_1]);
                tx.pushbackToBranch<int>("vbs_jets_good_jets_idx", vbs_jet_idx_0);
                tx.pushbackToBranch<int>("vbs_jets_good_jets_idx", vbs_jet_idx_1);

                // Set the vbs jets
                tx.setBranch<LV>("j0", good_jets_p4[vbs_jet_idx_0]);
                tx.setBranch<LV>("j1", good_jets_p4[vbs_jet_idx_1]);
            }
            float mjj = (tx.getBranch<LV>("j0") + tx.getBranch<LV>("j1")).mass();
            float detajj = fabs(RooUtil::Calc::DeltaEta(tx.getBranch<LV>("j0"), tx.getBranch<LV>("j1")));
            float leppt0 = tx.getBranch<LV>("leadlep").pt();
            float leppt1 = tx.getBranch<LV>("subllep").pt();
            return true;

        },
        UNITY);

    cutflow.addCutToLastActiveCut("AK4CategChannels",
        [&]()
        {
            const int& btagchannel = tx.getBranch<int>("btagchannel");
            const int& lepchannel = tx.getBranch<int>("lepchannel");
            const int& mbbIn = tx.getBranch<int>("mbbIn");
            int channel = -1;
            if (btagchannel == 0 and lepchannel <= 2 and     mbbIn) channel = 0;
            if (btagchannel == 0 and lepchannel <= 2 and not mbbIn) channel = 1;
            if (btagchannel == 1 and lepchannel <= 2 and     mbbIn) channel = 2;
            if (btagchannel == 1 and lepchannel <= 2 and not mbbIn) channel = 3;
            if (btagchannel == 0 and lepchannel == 3 and     mbbIn) channel = 4;
            if (btagchannel == 0 and lepchannel == 3 and not mbbIn) channel = 5;
            if (btagchannel == 0 and lepchannel == 4 and     mbbIn) channel = 6;
            if (btagchannel == 0 and lepchannel == 4 and not mbbIn) channel = 7;
            tx.setBranch<int>("channel", channel);
            int channeldetail = -1;
            if (btagchannel == 0 and lepchannel == 0 and     mbbIn) channeldetail = 0;
            if (btagchannel == 0 and lepchannel == 0 and not mbbIn) channeldetail = 1;
            if (btagchannel == 0 and lepchannel == 1 and     mbbIn) channeldetail = 2;
            if (btagchannel == 0 and lepchannel == 1 and not mbbIn) channeldetail = 3;
            if (btagchannel == 0 and lepchannel == 2 and     mbbIn) channeldetail = 4;
            if (btagchannel == 0 and lepchannel == 2 and not mbbIn) channeldetail = 5;
            if (btagchannel == 1 and lepchannel == 0 and     mbbIn) channeldetail = 6;
            if (btagchannel == 1 and lepchannel == 0 and not mbbIn) channeldetail = 7;
            if (btagchannel == 1 and lepchannel == 1 and     mbbIn) channeldetail = 8;
            if (btagchannel == 1 and lepchannel == 1 and not mbbIn) channeldetail = 9;
            if (btagchannel == 1 and lepchannel == 2 and     mbbIn) channeldetail = 10;
            if (btagchannel == 1 and lepchannel == 2 and not mbbIn) channeldetail = 11;
            if (btagchannel == 0 and lepchannel == 3 and     mbbIn) channeldetail = 12;
            if (btagchannel == 0 and lepchannel == 3 and not mbbIn) channeldetail = 13;
            if (btagchannel == 0 and lepchannel == 4 and     mbbIn) channeldetail = 14;
            if (btagchannel == 0 and lepchannel == 4 and not mbbIn) channeldetail = 15;
            tx.setBranch<int>("channeldetail", channeldetail);

            // Create keyvariables worth computing
            const LV& b0 = tx.getBranch<LV>("b0");
            const LV& b1 = tx.getBranch<LV>("b1");
            tx.setBranch<float>("mbb", (b0 + b1).mass());
            tx.setBranch<float>("dphibb", fabs(RooUtil::Calc::DeltaPhi(b0, b1)));
            tx.setBranch<float>("detabb", fabs(RooUtil::Calc::DeltaEta(b0, b1)));
            tx.setBranch<float>("drbb", RooUtil::Calc::DeltaR(b0, b1));
            tx.setBranch<float>("ptbb", (b0 + b1).pt());

            tx.setBranch<float>("b0pt", b0.pt());
            tx.setBranch<float>("b1pt", b1.pt());
            tx.setBranch<int>("b0tight", tx.getBranch<vector<int>>("higgs_jets_tight_btagged")[0]);
            tx.setBranch<int>("b1tight", tx.getBranch<vector<int>>("higgs_jets_tight_btagged")[1]);

            const LV& j0 = tx.getBranch<LV>("j0");
            const LV& j1 = tx.getBranch<LV>("j1");
            tx.setBranch<float>("mjj", (j0 + j1).mass());
            tx.setBranch<float>("dphijj", fabs(RooUtil::Calc::DeltaPhi(j0, j1)));
            tx.setBranch<float>("detajj", fabs(RooUtil::Calc::DeltaEta(j0, j1)));
            tx.setBranch<float>("drjj", RooUtil::Calc::DeltaR(j0, j1));
            tx.setBranch<float>("ptjj", (j0 + j1).pt());

            tx.setBranch<float>("j0pt", j0.pt());
            tx.setBranch<float>("j1pt", j1.pt());

            tx.setBranch<float>("j_lead_p", j0.P() > j1.P() ? j0.P() : j1.P());
            tx.setBranch<float>("j_sublead_p", j0.P() > j1.P() ? j1.P() : j0.P());

            const LV& leadlep = tx.getBranch<LV>("leadlep");
            const LV& subllep = tx.getBranch<LV>("subllep");
            tx.setBranch<float>("mll", (leadlep + subllep).mass());
            tx.setBranch<float>("dphill", fabs(RooUtil::Calc::DeltaPhi(leadlep, subllep)));
            tx.setBranch<float>("detall", fabs(RooUtil::Calc::DeltaEta(leadlep, subllep)));
            tx.setBranch<float>("drll", RooUtil::Calc::DeltaR(leadlep, subllep));
            tx.setBranch<float>("ptll", (leadlep + subllep).pt());

            tx.setBranch<float>("l0pt", leadlep.pt());
            tx.setBranch<float>("l1pt", subllep.pt());

            const LV& met_p4 = tx.getBranch<LV>("met_p4");
            tx.setBranch<float>("met", met_p4.pt());

            tx.setBranch<float>("lt", leadlep.pt() + subllep.pt() + met_p4.pt());
            tx.setBranch<float>("st", leadlep.pt() + subllep.pt() + met_p4.pt() + b0.pt() + b1.pt());
            tx.setBranch<float>("mvvh", (leadlep + subllep + met_p4 + b0 + b1).mass());
            tx.setBranch<float>("mtvvh", (leadlep + subllep + met_p4 + b0 + b1).mt());
            tx.setBranch<float>("ptvvh", (leadlep + subllep + met_p4 + b0 + b1).pt());

            // computing neutrino assuming neutrinos are collinear with leptons
            float l0x = leadlep.pt() * std::cos(leadlep.phi());
            float l0y = leadlep.pt() * std::sin(leadlep.phi());
            float l1x = subllep.pt() * std::cos(subllep.phi());
            float l1y = subllep.pt() * std::sin(subllep.phi());
            float metx = met_p4.pt() * std::cos(met_p4.phi());
            float mety = met_p4.pt() * std::sin(met_p4.phi());

            // // https://www.wolframalpha.com/input/?i=Solve+x+%3D+m+*+a+%2B+n+*+b%2C+y+%3D+m+*+c+%2B+n+*+d+for+m%2C+n
            // float a = std::sin(leadlep.theta()) * std::cos(leadlep.phi());
            // float b = std::sin(subllep.theta()) * std::cos(subllep.phi());
            // float c = std::sin(leadlep.theta()) * std::sin(leadlep.phi());
            // float d = std::sin(subllep.theta()) * std::sin(subllep.phi());
            // float v0p = (d * metx - b * mety) / (a * d - b * c);
            // float v1p = (c * metx - a * mety) / (b * c - a * d);
            // float v0pt = v0p * std::sin(leadlep.theta());
            // float v1pt = v1p * std::sin(subllep.theta());

            // https://www.wolframalpha.com/input/?i=Solve+x+%3D+m+*+a+%2B+n+*+b%2C+y+%3D+m+*+c+%2B+n+*+d+for+m%2C+n
            float a = std::cos(leadlep.phi());
            float b = std::cos(subllep.phi());
            float c = std::sin(leadlep.phi());
            float d = std::sin(subllep.phi());
            float v0p = (d * metx - b * mety) / (a * d - b * c);
            float v1p = (c * metx - a * mety) / (b * c - a * d);
            // float v0pt = v0p * std::sin(leadlep.theta());
            // float v1pt = v1p * std::sin(subllep.theta());
            float v0pt = v0p * std::sin(leadlep.theta());
            float v1pt = v1p * std::sin(subllep.theta());

            tx.setBranch<float>("v0pt", v0pt);
            tx.setBranch<float>("v1pt", v1pt);

            // TLorentzVector
            TLorentzVector v0_tlv;
            TLorentzVector v1_tlv;
            // v0_tlv.SetPtEtaPhiM(v0pt, leadlep.eta(), leadlep.phi(), 0);
            // v1_tlv.SetPtEtaPhiM(v1pt, subllep.eta(), subllep.phi(), 0);
            v0_tlv.SetPtEtaPhiM(v0pt, 0, leadlep.phi(), 0);
            v1_tlv.SetPtEtaPhiM(v1pt, 0, subllep.phi(), 0);

            LV v0 = RooUtil::Calc::getLV(v0_tlv);
            LV v1 = RooUtil::Calc::getLV(v1_tlv);

            float w0mass = (v0 + leadlep).mass();
            float w1mass = (v1 + subllep).mass();

            tx.setBranch<float>("w0mass", w0mass);
            tx.setBranch<float>("w1mass", w1mass);

            int categ = -1;
            const int& leadlepID = tx.getBranch<int>("leadlepID");
            if (leadlepID < 0 and   btagchannel <= 1 and lepchannel <= 2 and abs(leadlepID) == 11)
                categ = 0;
            else if (leadlepID < 0 and   btagchannel <= 1 and lepchannel <= 2 and abs(leadlepID) == 13)
                categ = 1;
            else if (leadlepID < 0 and   btagchannel == 0 and lepchannel >  2)
                categ = 2;
            else if (leadlepID > 0 and ((btagchannel <= 1 and lepchannel <= 2) or (btagchannel == 0 and lepchannel > 2)))
                categ = 3;
            tx.setBranch<int>("categ", categ);
            tx.setBranch<float>("categ_F", categ);

            tx.setBranch<int>("is_ttbar_madgraph", processType == ProcessType::kTT1LMadGraph or processType == ProcessType::kTT2LMadGraph);
            tx.setBranch<int>("is_ttbar_powheg", processType == ProcessType::kTT1LPowheg or processType == ProcessType::kTT2LPowheg);
            tx.setBranch<int>("is_train", (nt.event() % 2 == 0) or tx.getBranch<int>("is_ttbar_madgraph"));
            tx.setBranch<int>("is_test" , (nt.event() % 2 == 1) or tx.getBranch<int>("is_ttbar_powheg"));
            tx.setBranch<int>("is_signal", processType == ProcessType::kSignal);
            tx.setBranch<int>("is_background" ,  not (processType == ProcessType::kSignal));

            // XSEC SF for when splitting training and testing
            float xsec_sf = 1;
            if (nt.year() == 2016 and not nt.isData())
            {
                if (tx.getBranch<int>("is_test"))
                {
                    // v2.3_SS
                    // Processing print_yield.C("bosons")...
                    //  xsec_sf: 0.412045

                    // Processing print_yield.C("ttz")...
                    //  xsec_sf: 2.06165

                    // Processing print_yield.C("ttw")...
                    //  xsec_sf: 2.05014

                    // Processing print_yield.C("raretop")...
                    //  xsec_sf: 1.99267

                    // Processing print_yield.C("tt1lpowheg")...
                    //  xsec_sf: 1.4919

                    // Processing print_yield.C("tt2lpowheg")...
                    //  xsec_sf: 1.46055

                    if (processType == ProcessType::kBosons) xsec_sf = 0.412045; // this is because there are significantly more neg weights in training
                    if (processType == ProcessType::kRaretop) xsec_sf = 1.99267;
                    if (processType == ProcessType::kTTW) xsec_sf = 2.05014;
                    if (processType == ProcessType::kTTZ) xsec_sf = 2.06165;
                }
                else
                {
                    xsec_sf = 0;
                }
            }
            tx.setBranch<float>("xsec_sf", xsec_sf);

            tx.setBranch<float>("bdt", readerX->eval(tx));
            float mbb = tx.getBranch<float>("mbb");
            tx.setBranch<float>("mbb", 125);
            tx.setBranch<float>("bdt_mbboff", readerX->eval(tx));
            tx.setBranch<float>("mbb", mbb);


            const float& mjj = tx.getBranch<float>("mjj");
            const float& detajj = tx.getBranch<float>("detajj");
            const float& lt = tx.getBranch<float>("lt");
            const float& st = tx.getBranch<float>("st");
            const float& bdt = tx.getBranch<float>("bdt");

            int is_preselection = channel >= 0 and mjj > 500 and detajj > 3;

            int islgt = categ == 0 or categ == 1;

            tx.setBranch<int>("is_ps_el"  , is_preselection and (categ == 0) );
            tx.setBranch<int>("is_ps_mu"  , is_preselection and (categ == 1) );
            tx.setBranch<int>("is_ps_tau" , is_preselection and (categ == 2) );
            tx.setBranch<int>("is_ps_neg" , is_preselection and (categ == 3) );
            tx.setBranch<int>("is_ps_lgt" , is_preselection and (islgt == 1) );

            tx.setBranch<int>("is_cut_sr_el"   , is_preselection and (categ == 0) and (mbb < 150) and detajj > 5 and lt > 500 and st > 900 );
            tx.setBranch<int>("is_cut_sr_mu"   , is_preselection and (categ == 1) and (mbb < 150) and detajj > 5 and lt > 500 and st > 900 );
            tx.setBranch<int>("is_cut_sr_tau"  , is_preselection and (categ == 2) and (mbb < 150) and detajj > 5 and lt > 500 and st > 900 );
            tx.setBranch<int>("is_cut_sr_neg"  , is_preselection and (categ == 3) and (mbb < 150) and detajj > 5 and lt > 500 and st > 900 );
            tx.setBranch<int>("is_cut_sr_lgt"  , is_preselection and (islgt == 1) and (mbb < 150) and detajj > 5 and lt > 300 and st > 700 and not (lt > 500 and st > 900) );

            tx.setBranch<int>("is_cut_cr_el"   , is_preselection and (categ == 0) and (mbb > 150) );
            tx.setBranch<int>("is_cut_cr_mu"   , is_preselection and (categ == 1) and (mbb > 150) );
            tx.setBranch<int>("is_cut_cr_tau"  , is_preselection and (categ == 2) and (mbb > 150) );
            tx.setBranch<int>("is_cut_cr_neg"  , is_preselection and (categ == 3) and (mbb > 150) );
            tx.setBranch<int>("is_cut_cr_lgt"  , is_preselection and (islgt == 1) and (mbb > 150) );

            tx.setBranch<int>("is_cut_sr2_el"  , is_preselection and (categ == 0) and (mbb < 150) and detajj > 4 and lt > 300 and st > 700 );
            tx.setBranch<int>("is_cut_sr2_mu"  , is_preselection and (categ == 1) and (mbb < 150) and detajj > 4 and lt > 300 and st > 700 );
            tx.setBranch<int>("is_cut_sr2_tau" , is_preselection and (categ == 2) and (mbb < 150) and detajj > 4 and lt > 300 and st > 700 );
            tx.setBranch<int>("is_cut_sr2_neg" , is_preselection and (categ == 3) and (mbb < 150) and detajj > 4 and lt > 300 and st > 700 );

            tx.setBranch<int>("is_cut_cr2_el"  , is_preselection and (categ == 0) and (mbb > 150) );
            tx.setBranch<int>("is_cut_cr2_mu"  , is_preselection and (categ == 1) and (mbb > 150) );
            tx.setBranch<int>("is_cut_cr2_tau" , is_preselection and (categ == 2) and (mbb > 150) );
            tx.setBranch<int>("is_cut_cr2_neg" , is_preselection and (categ == 3) and (mbb > 150) );

            tx.setBranch<int>("is_bdt_sr_el"   , is_preselection and (categ == 0) and                 (bdt > 0.543) );
            tx.setBranch<int>("is_bdt_sr_mu"   , is_preselection and (categ == 1) and                 (bdt > 0.543) );
            tx.setBranch<int>("is_bdt_sr_tau"  , is_preselection and (categ == 2) and                 (bdt > 0.543) );
            tx.setBranch<int>("is_bdt_sr_neg"  , is_preselection and (categ == 3) and                 (bdt > 0.543) );

            tx.setBranch<int>("is_bdt_cr_el"   , is_preselection and (categ == 0) and (mbb > 150) and (bdt < 0.543) );
            tx.setBranch<int>("is_bdt_cr_mu"   , is_preselection and (categ == 1) and (mbb > 150) and (bdt < 0.543) );
            tx.setBranch<int>("is_bdt_cr_tau"  , is_preselection and (categ == 2) and (mbb > 150) and (bdt < 0.543) );
            tx.setBranch<int>("is_bdt_cr_neg"  , is_preselection and (categ == 3) and (mbb > 150) and (bdt < 0.543) );

            tx.setBranch<int>("is_bdt_sr2_el"  , is_preselection and (categ == 0) and                 (bdt > 0.52) );
            tx.setBranch<int>("is_bdt_sr2_mu"  , is_preselection and (categ == 1) and                 (bdt > 0.52) );
            tx.setBranch<int>("is_bdt_sr2_tau" , is_preselection and (categ == 2) and                 (bdt > 0.52) );
            tx.setBranch<int>("is_bdt_sr2_neg" , is_preselection and (categ == 3) and                 (bdt > 0.52) );

            tx.setBranch<int>("is_bdt_cr2_el"  , is_preselection and (categ == 0) and (mbb > 150) and (bdt < 0.52) );
            tx.setBranch<int>("is_bdt_cr2_mu"  , is_preselection and (categ == 1) and (mbb > 150) and (bdt < 0.52) );
            tx.setBranch<int>("is_bdt_cr2_tau" , is_preselection and (categ == 2) and (mbb > 150) and (bdt < 0.52) );
            tx.setBranch<int>("is_bdt_cr2_neg" , is_preselection and (categ == 3) and (mbb > 150) and (bdt < 0.52) );

            tx.setBranch<int>("is_ps"      , tx.getBranch<int>("is_ps_el")      or tx.getBranch<int>("is_ps_mu")      or tx.getBranch<int>("is_ps_tau")      or tx.getBranch<int>("is_ps_neg")      );
            tx.setBranch<int>("is_cut_sr"  , tx.getBranch<int>("is_cut_sr_el")  or tx.getBranch<int>("is_cut_sr_mu")  or tx.getBranch<int>("is_cut_sr_tau")  or tx.getBranch<int>("is_cut_sr_neg")  );
            tx.setBranch<int>("is_cut_cr"  , tx.getBranch<int>("is_cut_cr_el")  or tx.getBranch<int>("is_cut_cr_mu")  or tx.getBranch<int>("is_cut_cr_tau")  or tx.getBranch<int>("is_cut_cr_neg")  );
            tx.setBranch<int>("is_cut_sr2" , tx.getBranch<int>("is_cut_sr2_el") or tx.getBranch<int>("is_cut_sr2_mu") or tx.getBranch<int>("is_cut_sr2_tau") or tx.getBranch<int>("is_cut_sr2_neg") );
            tx.setBranch<int>("is_cut_cr2" , tx.getBranch<int>("is_cut_cr2_el") or tx.getBranch<int>("is_cut_cr2_mu") or tx.getBranch<int>("is_cut_cr2_tau") or tx.getBranch<int>("is_cut_cr2_neg") );
            tx.setBranch<int>("is_bdt_sr"  , tx.getBranch<int>("is_bdt_sr_el")  or tx.getBranch<int>("is_bdt_sr_mu")  or tx.getBranch<int>("is_bdt_sr_tau")  or tx.getBranch<int>("is_bdt_sr_neg")  );
            tx.setBranch<int>("is_bdt_cr"  , tx.getBranch<int>("is_bdt_cr_el")  or tx.getBranch<int>("is_bdt_cr_mu")  or tx.getBranch<int>("is_bdt_cr_tau")  or tx.getBranch<int>("is_bdt_cr_neg")  );
            tx.setBranch<int>("is_bdt_sr2" , tx.getBranch<int>("is_bdt_sr2_el") or tx.getBranch<int>("is_bdt_sr2_mu") or tx.getBranch<int>("is_bdt_sr2_tau") or tx.getBranch<int>("is_bdt_sr2_neg") );
            tx.setBranch<int>("is_bdt_cr2" , tx.getBranch<int>("is_bdt_cr2_el") or tx.getBranch<int>("is_bdt_cr2_mu") or tx.getBranch<int>("is_bdt_cr2_tau") or tx.getBranch<int>("is_bdt_cr2_neg") );

            int isSS = (tx.getBranch<int>("lep0ID") * tx.getBranch<int>("lep1ID")) > 0;
            tx.setBranch<int>("pass_blind", nt.isData() and isSS ? not (mbbIn): 1);
            tx.setBranch<int>("pass_blind_bdt", nt.isData() and isSS ? not (mbbIn or bdt > 0.543): 1);

            return tx.getBranch<int>("is_ps");
        },
        UNITY);

    cutflow.addCutToLastActiveCut("AK4CategPresel", [&]() { return tx.getBranch<int>("is_ps"); }, [&]() { return tx.getBranch<float>("btagsf"); } );
    return;
}



//________________________________________________________________________________________________________________________________________
void VBSHWW::processGenParticles_VBSWWH()
{

    bool isvbswwh = nt.GenPart_status()[2] == 23;
    tx.setBranch<int>("isvbswwh", isvbswwh);
    tx.setBranch<int>("iswwhlvlvbb", isvbswwh); // For VBSWWH v7 sample, this is always true if isvbswwh
    if (isvbswwh)
    {
        const LV& ijet = nt.GenPart_p4()[2];
        const LV& jjet = nt.GenPart_p4()[3];
        const LV& jet0 = ijet.pt() > jjet.pt() ? ijet : jjet;
        const LV& jet1 = ijet.pt() > jjet.pt() ? jjet : ijet;
        tx.setBranch<LV>("gen_jet0", jet0);
        tx.setBranch<LV>("gen_jet1", jet1);
        const LV& iW = nt.GenPart_p4()[4];
        const LV& jW = nt.GenPart_p4()[5];
        const LV& W0 = iW.pt() > jW.pt() ? iW : jW;
        const LV& W1 = iW.pt() > jW.pt() ? jW : iW;
        tx.setBranch<LV>("gen_w0", W0);
        tx.setBranch<LV>("gen_w1", W1);
        const LV& h = nt.GenPart_p4()[6];
        tx.setBranch<LV>("gen_h", h);

        int gen_sign = nt.GenPart_pdgId()[4] > 0;
        tx.setBranch<int>("gen_sign", gen_sign);

        std::vector<LV> leptons;
        std::vector<int> lepton_pdgids;
        for (unsigned int igen = 0; igen < nt.GenPart_p4().size(); ++igen)
        {
            int midx = nt.GenPart_genPartIdxMother()[igen];
            if (midx > 1)
            {
                if (abs(nt.GenPart_pdgId()[midx]) == 24 and abs(nt.GenPart_status()[midx]) == 62
                    and (
                        ((nt.GenPart_status()[igen] == 1 or nt.GenPart_status()[igen] == 23) and (abs(nt.GenPart_pdgId()[igen]) == 11 or abs(nt.GenPart_pdgId()[igen]) == 13))
                        or
                        ((nt.GenPart_status()[igen] == 2 or nt.GenPart_status()[igen] == 23) and (abs(nt.GenPart_pdgId()[igen]) == 15))
                        )
                   )
                {
                    leptons.push_back(nt.GenPart_p4()[igen]);
                    lepton_pdgids.push_back(nt.GenPart_pdgId()[igen]);
                }
            }
            else
            {
                continue;
            }
        }

        if (leptons.size() != 2)
        {
            std::cout <<  " leptons.size(): " << leptons.size() <<  std::endl;
            for (unsigned int igen = 0; igen < nt.GenPart_p4().size(); ++igen)
            {
                int pdgid = nt.GenPart_pdgId()[igen];
                int status = nt.GenPart_status()[igen];
                int midx = nt.GenPart_genPartIdxMother()[igen];
                int mid = midx > -1 ? nt.GenPart_pdgId()[midx] : -1;
                int mstatus = midx > -1 ? nt.GenPart_status()[midx] : -1;
                std::cout <<  " pdgid: " << pdgid <<  " status: " << status <<  " midx: " << midx <<  " mid: " << mid <<  " mstatus: " << mstatus <<  std::endl;
            }
        }
        const LV& lep0 = leptons[0].pt() > leptons[1].pt() ? leptons[0] : leptons[1];
        const LV& lep1 = leptons[0].pt() > leptons[1].pt() ? leptons[1] : leptons[0];

        std::vector<LV> nus;
        for (unsigned int igen = 0; igen < nt.GenPart_p4().size(); ++igen)
        {
            int midx = nt.GenPart_genPartIdxMother()[igen];
            if (midx > 1)
            {
                if (abs(nt.GenPart_pdgId()[midx]) == 24 and abs(nt.GenPart_status()[midx]) == 62
                    and (
                        ((nt.GenPart_status()[igen] == 1 or nt.GenPart_status()[igen] == 23) and (abs(nt.GenPart_pdgId()[igen]) == 12 or abs(nt.GenPart_pdgId()[igen]) == 14))
                        or
                        ((nt.GenPart_status()[igen] == 1 or nt.GenPart_status()[igen] == 23) and (abs(nt.GenPart_pdgId()[igen]) == 16))
                        )
                   )
                {
                    nus.push_back(nt.GenPart_p4()[igen]);
                }
            }
            else
            {
                continue;
            }
        }

        if (nus.size() != 2)
        {
            std::cout <<  " nus.size(): " << nus.size() <<  std::endl;
        }
        const LV& nu0 = nus[0].pt() > nus[1].pt() ? nus[0] : nus[1];
        const LV& nu1 = nus[0].pt() > nus[1].pt() ? nus[1] : nus[0];

        std::vector<LV> bs;
        for (unsigned int igen = 0; igen < nt.GenPart_p4().size(); ++igen)
        {
            if (abs(nt.GenPart_pdgId()[igen]) == 5 and nt.GenPart_status()[igen] == 23)
            {
                bs.push_back(nt.GenPart_p4()[igen]);
            }
        }

        if (bs.size() != 2)
        {
            std::cout <<  " bs.size(): " << bs.size() <<  std::endl;
        }
        const LV& b0 = bs[0].pt() > bs[1].pt() ? bs[0] : bs[1];
        const LV& b1 = bs[0].pt() > bs[1].pt() ? bs[1] : bs[0];

        tx.setBranch<LV>("gen_lep0", lep0);
        tx.setBranch<LV>("gen_lep1", lep1);
        tx.setBranch<LV>("gen_nu0", nu0);
        tx.setBranch<LV>("gen_nu1", nu1);
        tx.setBranch<LV>("gen_b0", b0);
        tx.setBranch<LV>("gen_b1", b1);

        tx.setBranch<LV>("gen_lepA", (leptons[0] + nus[0]).pt() > (leptons[1] + nus[1]).pt() ? leptons[0] : leptons[1]);
        tx.setBranch<LV>("gen_lepB", (leptons[0] + nus[0]).pt() > (leptons[1] + nus[1]).pt() ? leptons[1] : leptons[0]);
        tx.setBranch<LV>("gen_nuA" , (leptons[0] + nus[0]).pt() > (leptons[1] + nus[1]).pt() ? nus[0]     : nus[1]    );
        tx.setBranch<LV>("gen_nuB" , (leptons[0] + nus[0]).pt() > (leptons[1] + nus[1]).pt() ? nus[1]     : nus[0]    );
        const LV& gen_lepA = tx.getBranch<LV>("gen_lepA");
        const LV& gen_nuA  = tx.getBranch<LV>("gen_nuA");
        const LV& gen_lepB = tx.getBranch<LV>("gen_lepB");
        const LV& gen_nuB  = tx.getBranch<LV>("gen_nuB");
        TLorentzVector lepA = RooUtil::Calc::getTLV(gen_lepA);
        TLorentzVector nuA  = RooUtil::Calc::getTLV(gen_nuA);
        TLorentzVector lepB = RooUtil::Calc::getTLV(gen_lepB);
        TLorentzVector nuB  = RooUtil::Calc::getTLV(gen_nuB);
        TLorentzVector WA = lepA + nuA;
        TLorentzVector WB = lepB + nuB;
        auto betaA = WA.BoostVector();
        lepA.Boost(-betaA);
        nuA.Boost(-betaA);
        float costhetaA = TMath::Cos(lepA.Angle(WA.Vect()));
        auto betaB = WB.BoostVector();
        lepB.Boost(-betaB);
        nuB.Boost(-betaB);
        float costhetaB = TMath::Cos(lepB.Angle(WB.Vect()));
        tx.setBranch<float>("gen_cosThetaStarA", costhetaA);
        tx.setBranch<float>("gen_cosThetaStarB", costhetaB);

        int channel = -1;
        if (lepton_pdgids[0] * lepton_pdgids[1] == 121)
        {
            channel = 0;
        }
        else if (lepton_pdgids[0] * lepton_pdgids[1] == 143)
        {
            channel = 1;
        }
        else if (lepton_pdgids[0] * lepton_pdgids[1] == 169)
        {
            channel = 2;
        }
        else if (lepton_pdgids[0] * lepton_pdgids[1] == 165)
        {
            channel = 3;
        }
        else if (lepton_pdgids[0] * lepton_pdgids[1] == 195)
        {
            channel = 4;
        }
        else if (lepton_pdgids[0] * lepton_pdgids[1] == 225)
        {
            channel = 5;
        }
        tx.setBranch<int>("genchannel", channel);
    }
}



//________________________________________________________________________________________________________________________________________
void VBSHWW::processGenParticles_VBSWWH_UL()
{

    bool isvbswwh = nt.GenPart_status()[2] == 23;
    tx.setBranch<int>("isvbswwh", isvbswwh);
    tx.setBranch<int>("iswwhlvlvbb", 0);
    if (isvbswwh)
    {

        const LV& ijet = nt.GenPart_p4()[2];
        const LV& jjet = nt.GenPart_p4()[3];
        const LV& jet0 = ijet.pt() > jjet.pt() ? ijet : jjet;
        const LV& jet1 = ijet.pt() > jjet.pt() ? jjet : ijet;
        tx.setBranch<LV>("gen_jet0", jet0);
        tx.setBranch<LV>("gen_jet1", jet1);
        const LV& iW = nt.GenPart_p4()[4];
        const LV& jW = nt.GenPart_p4()[5];
        const LV& W0 = iW.pt() > jW.pt() ? iW : jW;
        const LV& W1 = iW.pt() > jW.pt() ? jW : iW;
        tx.setBranch<LV>("gen_w0", W0);
        tx.setBranch<LV>("gen_w1", W1);
        const LV& h = nt.GenPart_p4()[6];
        tx.setBranch<LV>("gen_h", h);

        int gen_sign = nt.GenPart_pdgId()[4] > 0;
        tx.setBranch<int>("gen_sign", gen_sign);

        std::vector<LV> h_decay_p4s;
        std::vector<int> h_decay_pdgIds;
        std::vector<int> h_decay_statuses;
        int h_decay_id;
        for (unsigned int igen = 0; igen < nt.GenPart_p4().size(); ++igen)
        {
            int imom = nt.GenPart_genPartIdxMother()[igen];
            if (abs(nt.GenPart_pdgId()[imom]) == 25 and nt.GenPart_status()[imom] == 62)
            {
                int pdgid = nt.GenPart_pdgId()[igen];
                int status = nt.GenPart_status()[igen];
                // std::cout << std::endl;
                // std::cout <<  " pdgid: " << pdgid <<  " status: " << status <<  std::endl;
                h_decay_p4s.push_back(nt.GenPart_p4()[igen]);
                h_decay_pdgIds.push_back(nt.GenPart_pdgId()[igen]);
                h_decay_statuses.push_back(nt.GenPart_status()[igen]);
            }
        }

        // sanity check
        if (h_decay_pdgIds.size() != 2)
        {
            std::cout << "NOT " << " " << h_decay_pdgIds.size() << " ";
            for (auto& id : h_decay_pdgIds)
                std::cout << id << " ";
            std::cout << std::endl;
        }

        bool is_hbb = false;
        if (abs(h_decay_pdgIds[0]) == 5)
        {
            is_hbb = true;
        }

        const LV& b0 = h_decay_p4s[0].pt() > h_decay_p4s[1].pt() ? h_decay_p4s[0] : h_decay_p4s[1];
        const LV& b1 = h_decay_p4s[0].pt() > h_decay_p4s[1].pt() ? h_decay_p4s[1] : h_decay_p4s[0];

        std::vector<int> wsidx;
        int w0idx = -1;
        int w1idx = -1;
        for (unsigned int igen = 0; igen < nt.GenPart_p4().size(); ++igen)
        {
            if (abs(nt.GenPart_pdgId()[igen]) == 24 and abs(nt.GenPart_status()[igen]) == 62)
            {
                wsidx.push_back(igen);
            }
        }

        w0idx = wsidx[0];
        w1idx = wsidx[1];

        std::vector<LV> w0decay_p4s;
        std::vector<int> w0decay_pdgids;
        std::vector<LV> w1decay_p4s;
        std::vector<int> w1decay_pdgids;
        for (unsigned int igen = 0; igen < nt.GenPart_p4().size(); ++igen)
        {
            int midx = nt.GenPart_genPartIdxMother()[igen];
            if (midx == w0idx)
            {
                w0decay_p4s.push_back(nt.GenPart_p4()[igen]);
                w0decay_pdgids.push_back(nt.GenPart_pdgId()[igen]);
            }
            if (midx == w1idx)
            {
                w1decay_p4s.push_back(nt.GenPart_p4()[igen]);
                w1decay_pdgids.push_back(nt.GenPart_pdgId()[igen]);
            }
        }

        if (w0decay_pdgids.size() != 2)
        {
            std::cout << std::endl;
            std::cout << "NOT ";

            for (auto& id : w0decay_pdgids)
            {
                std::cout << id << " ";
            }
            std::cout << std::endl;
        }
        if (w1decay_pdgids.size() != 2)
        {
            std::cout << std::endl;
            std::cout << "NOT ";

            for (auto& id : w1decay_pdgids)
            {
                std::cout << id << " ";
            }
            std::cout << std::endl;
        }

        bool isw0lep = abs(w0decay_pdgids[0]) == 11 or abs(w0decay_pdgids[0]) == 13 or abs(w0decay_pdgids[0]) == 15;
        bool isw1lep = abs(w1decay_pdgids[0]) == 11 or abs(w1decay_pdgids[0]) == 13 or abs(w1decay_pdgids[0]) == 15;

        int iswwhlvlvbb = isw0lep and isw1lep and is_hbb;
        tx.setBranch<int>("iswwhlvlvbb", iswwhlvlvbb);

        if (iswwhlvlvbb)
        {
            LV lep0 = w0decay_p4s[0].pt() > w1decay_p4s[0].pt() ? w0decay_p4s[0] : w1decay_p4s[0];
            LV lep1 = w0decay_p4s[0].pt() > w1decay_p4s[0].pt() ? w1decay_p4s[0] : w0decay_p4s[0];
            LV nu0 = w0decay_p4s[1].pt() > w1decay_p4s[1].pt() ? w0decay_p4s[1] : w1decay_p4s[1];
            LV nu1 = w0decay_p4s[1].pt() > w1decay_p4s[1].pt() ? w1decay_p4s[1] : w0decay_p4s[1];
            LV b0 = h_decay_p4s[0].pt() > h_decay_p4s[1].pt() ? h_decay_p4s[0] : h_decay_p4s[1];
            LV b1 = h_decay_p4s[0].pt() > h_decay_p4s[1].pt() ? h_decay_p4s[1] : h_decay_p4s[0];
            tx.setBranch<LV>("gen_lep0", lep0);
            tx.setBranch<LV>("gen_lep1", lep1);
            tx.setBranch<LV>("gen_nu0", nu0);
            tx.setBranch<LV>("gen_nu1", nu1);
            tx.setBranch<LV>("gen_b0", b0);
            tx.setBranch<LV>("gen_b1", b1);

            tx.setBranch<LV>("gen_lepA", w0decay_p4s[0]);
            tx.setBranch<LV>("gen_lepB", w1decay_p4s[0]);
            tx.setBranch<LV>("gen_nuA", w0decay_p4s[1]);
            tx.setBranch<LV>("gen_nuB", w1decay_p4s[1]);

            tx.setBranch<LV>("gen_lepA", (w0decay_p4s[0] + w0decay_p4s[1]).pt() > (w1decay_p4s[0] + w1decay_p4s[1]).pt() ? w0decay_p4s[0] : w1decay_p4s[0]);
            tx.setBranch<LV>("gen_lepB", (w0decay_p4s[0] + w0decay_p4s[1]).pt() > (w1decay_p4s[0] + w1decay_p4s[1]).pt() ? w1decay_p4s[0] : w0decay_p4s[0]);
            tx.setBranch<LV>("gen_nuA" , (w0decay_p4s[0] + w0decay_p4s[1]).pt() > (w1decay_p4s[0] + w1decay_p4s[1]).pt() ? w0decay_p4s[1] : w1decay_p4s[1]);
            tx.setBranch<LV>("gen_nuB" , (w0decay_p4s[0] + w0decay_p4s[1]).pt() > (w1decay_p4s[0] + w1decay_p4s[1]).pt() ? w1decay_p4s[1] : w0decay_p4s[1]);
            const LV& gen_lepA = tx.getBranch<LV>("gen_lepA");
            const LV& gen_nuA  = tx.getBranch<LV>("gen_nuA");
            const LV& gen_lepB = tx.getBranch<LV>("gen_lepB");
            const LV& gen_nuB  = tx.getBranch<LV>("gen_nuB");
            TLorentzVector lepA = RooUtil::Calc::getTLV(gen_lepA);
            TLorentzVector nuA  = RooUtil::Calc::getTLV(gen_nuA);
            TLorentzVector lepB = RooUtil::Calc::getTLV(gen_lepB);
            TLorentzVector nuB  = RooUtil::Calc::getTLV(gen_nuB);
            TLorentzVector WA = lepA + nuA;
            TLorentzVector WB = lepB + nuB;
            auto betaA = WA.BoostVector();
            lepA.Boost(-betaA);
            nuA.Boost(-betaA);
            float costhetaA = TMath::Cos(lepA.Angle(WA.Vect()));
            auto betaB = WB.BoostVector();
            lepB.Boost(-betaB);
            nuB.Boost(-betaB);
            float costhetaB = TMath::Cos(lepB.Angle(WB.Vect()));
            tx.setBranch<float>("gen_cosThetaStarA", costhetaA);
            tx.setBranch<float>("gen_cosThetaStarB", costhetaB);

        }
    }
}



//________________________________________________________________________________________________________________________________________
void VBSHWW::processGenParticles_TopBackgrounds()
{

    std::vector<int> b_idxs;
    std::vector<int> b_from_top_idxs;
    std::vector<int> b_midx;
    std::vector<LV> b_from_top_p4s;
    for (unsigned int igen = 0; igen < nt.GenPart_p4().size(); ++igen)
    {
        // Selecting the following will 100% select the b quarks from the top quark
        // Note that when you look at it more generally that you find extra bquarks from the ISR
        // In those cases the mother points to the incoming parton, and presumably the 21 gluon is "contracted out".
        // So the gluons doesn't show up
        if (nt.GenPart_status()[igen] == 23 and abs(nt.GenPart_pdgId()[igen]) == 5)
        {
            b_idxs.push_back(igen);
            int midx = nt.GenPart_genPartIdxMother()[igen];
            if (abs(nt.GenPart_pdgId()[midx]) == 6 and abs(nt.GenPart_status()[midx]) == 62)
            {
                b_from_top_idxs.push_back(igen);
                b_from_top_p4s.push_back(nt.GenPart_p4()[igen]);
            }
            b_midx.push_back(midx);
        }
    }

    const LV& b0 = b_from_top_p4s[0].pt() > b_from_top_p4s[1].pt() ? b_from_top_p4s[0] : b_from_top_p4s[1];
    const LV& b1 = b_from_top_p4s[0].pt() > b_from_top_p4s[1].pt() ? b_from_top_p4s[1] : b_from_top_p4s[0];

    tx.setBranch<LV>("gen_b0", b0);
    tx.setBranch<LV>("gen_b1", b1);

    if (b_from_top_idxs.size() != 2)
    {
        std::cout << std::endl;
        std::cout <<  "WARNING! b_from_top_idxs.size(): " << b_from_top_idxs.size() <<  std::endl;
        std::cout << std::endl;
    }

    // if (b_idxs.size() == 4)
    // {
    //     std::cout << std::endl;
    //     std::cout <<  " (nt.GenPart_p4()[b_idxs[0]]+nt.GenPart_p4()[b_idxs[1]]).mass(): " << (nt.GenPart_p4()[b_idxs[0]]+nt.GenPart_p4()[b_idxs[1]]).mass() <<  std::endl;
    //     std::cout <<  " RooUtil::Calc::DeltaR(nt.GenPart_p4()[b_idxs[0]],nt.GenPart_p4()[b_idxs[1]]): " << RooUtil::Calc::DeltaR(nt.GenPart_p4()[b_idxs[0]],nt.GenPart_p4()[b_idxs[1]]) <<  std::endl;
    //     std::cout << std::endl;
    // }

}



//________________________________________________________________________________________________________________________________________
void VBSHWW::setBTagSF(std::vector<float> jet_pt, std::vector<float> jet_eta, std::vector<float> jet_score, std::vector<int> jet_flavor)
{

    // ******
    // Warning: This function assumes you only pass 2 jets!!
    // Warning: This function assumes you only pass 2 jets!!
    // Warning: This function assumes you only pass 2 jets!!
    // ******

    if (nt.isData())
    {
        tx.setBranch<float>("btagsf", 1);
    }
    else
    {
        int idx_lead_bscore = jet_score[0] > jet_score[1] ? 0 : 1;
        int idx_subl_bscore = jet_score[0] > jet_score[1] ? 1 : 0;

        float btag_prob_MC = 1;
        float btag_prob_DATA = 1;
        for (unsigned ijet = 0; ijet < jet_pt.size(); ++ijet)
        {
            float pt = min(jet_pt.at(ijet), 599.99f);
            float eta = min(abs(jet_eta.at(ijet)), 2.399f);
            float score = jet_score.at(ijet);
            int flavor = jet_flavor.at(ijet);
            bool is_loose_btagged = score > gconf.WP_DeepFlav_loose;
            bool is_tight_btagged = score > gconf.WP_DeepFlav_tight;

            float eff_tight = 1;
            float eff_loose = 1;

            if (isUL)
            {
                if (idx_lead_bscore == ijet)
                {
                    eff_tight = flavor == 5 ? btagEffTight_b->eval(pt, eta) : (flavor == 0 ? btagEffTight_l->eval(pt, eta) : btagEffTight_c->eval(pt, eta));
                    eff_loose = flavor == 5 ? btagEffLoose_b->eval(pt, eta) : (flavor == 0 ? btagEffLoose_l->eval(pt, eta) : btagEffLoose_c->eval(pt, eta));
                }
                else
                {
                    eff_tight = flavor == 5 ? btagEffTight_b_subl->eval(pt, eta) : (flavor == 0 ? btagEffTight_l_subl->eval(pt, eta) : btagEffTight_c_subl->eval(pt, eta));
                    eff_loose = flavor == 5 ? btagEffLoose_b_subl->eval(pt, eta) : (flavor == 0 ? btagEffLoose_l_subl->eval(pt, eta) : btagEffLoose_c_subl->eval(pt, eta));
                }
                // eff_tight = flavor == 5 ? btagEffTight_b->eval(pt, eta) : (flavor == 0 ? btagEffTight_l->eval(pt, eta) : btagEffTight_c->eval(pt, eta));
                // eff_loose = flavor == 5 ? btagEffLoose_b->eval(pt, eta) : (flavor == 0 ? btagEffLoose_l->eval(pt, eta) : btagEffLoose_c->eval(pt, eta));
            }
            else
            {
                eff_tight = flavor == 5 ? btagEffTight_b->eval(pt, eta) : (flavor == 0 ? btagEffTight_l->eval(pt, eta) : btagEffTight_c->eval(pt, eta));
                eff_loose = flavor == 5 ? btagEffLoose_b->eval(pt, eta) : (flavor == 0 ? btagEffLoose_l->eval(pt, eta) : btagEffLoose_c->eval(pt, eta));
            }

            float sf_tight =
                flavor == 5 ? btagReaderTight->eval_auto_bounds("central", BTagEntry::FLAV_B, eta, pt) : (
                flavor == 0 ? btagReaderTight->eval_auto_bounds("central", BTagEntry::FLAV_UDSG, eta, pt) :
                              btagReaderTight->eval_auto_bounds("central", BTagEntry::FLAV_C, eta, pt));
            float sf_loose =
                flavor == 5 ? btagReaderLoose->eval_auto_bounds("central", BTagEntry::FLAV_B, eta, pt) : (
                flavor == 0 ? btagReaderLoose->eval_auto_bounds("central", BTagEntry::FLAV_UDSG, eta, pt) :
                              btagReaderLoose->eval_auto_bounds("central", BTagEntry::FLAV_C, eta, pt));
            // std::cout <<  " eff_tight: " << eff_tight <<  " eff_loose: " << eff_loose <<  " sf_tight: " << sf_tight <<  " sf_loose: " << sf_loose <<  std::endl;
            if (is_tight_btagged)
            {
                btag_prob_MC *= eff_tight;
                btag_prob_DATA *= sf_tight * eff_tight;
            }
            else if (is_loose_btagged)
            {
                btag_prob_MC *= (eff_loose - eff_tight);
                btag_prob_DATA *= (sf_loose * eff_loose - sf_tight * eff_tight);
            }
            else
            {
                btag_prob_MC *= (1 - eff_loose);
                btag_prob_DATA *= (1 - sf_loose * eff_loose);
            }
        }
        float btagsf = btag_prob_DATA / btag_prob_MC;
        tx.setBranch<float>("btagsf", btagsf);
    }
}



//________________________________________________________________________________________________________________________________________
// For a given cutname it writes the run, lumi, evt into a textfile based on the output root name
void VBSHWW::writeEventList(TString cutname)
{
    TString eventlist_output_name = output_tfile->GetName(); // get the output file name
    TString suffix = TString::Format(".%s.txt", cutname.Data());
    eventlist_output_name.ReplaceAll(".root", suffix); // replace .root with suffix if .root exists
    if (not eventlist_output_name.Contains(suffix)) eventlist_output_name += suffix; // if no suffix exists, then append suffix
    cutflow.getCut(cutname).writeEventList(eventlist_output_name);
}



//________________________________________________________________________________________________________________________________________
void VBSHWW::process(TString final_cutname)
{
    // Clear the data structure for the event
    tx.clear();

    // // Set the run lumi and event for this event
    cutflow.setEventID(nt.run(), nt.luminosityBlock(), nt.event()); // Setting event ID in case we need to keep track of event id

    // Run all the cutflow selections and filling histograms
    cutflow.fill();

    // Writing skimmed event tree for the data structure we created
    if (cutflow.getCut(final_cutname).pass)
    {
        tx.fill();
    }
}



//________________________________________________________________________________________________________________________________________
void VBSHWW::parseCLI(int argc, char** argv)
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
        ("s,scale1fb"    , "pass scale1fb of the sample"                                                                         , cxxopts::value<float>())
        ("e,jecvar"      , "JEC variations to apply (1 = up, 0 = nominal, -1 = down)"                                            , cxxopts::value<int>()->default_value("0"))
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
        input_file_list_tstring = result["input"].as<std::string>();
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
        input_tree_name = result["tree"].as<std::string>();
    }
    else
    {
        std::cout << options.help() << std::endl;
        std::cout << "ERROR: Input tree name is not provided! Check your arguments" << std::endl;
        exit(1);
    }

    //_______________________________________________________________________________
    // --scale1fb
    if (result.count("scale1fb"))
    {
        scale1fb = result["scale1fb"].as<float>();
    }

    //_______________________________________________________________________________
    // --jecvar
    if (result.count("jecvar"))
    {
        jecvar = result["jecvar"].as<int>(); // -1, 0, or 1
        if (jecvar != -1 && jecvar != 0 && jecvar != 1)
        {
            std::cout << "ERROR: jecvar must be -1, 0, or 1. Received: " << jecvar << std::endl;
            exit(1);
        }
    }

    //_______________________________________________________________________________
    // --debug
    if (result.count("debug"))
    {
        output_tfile = new TFile("debug.root", "recreate");
    }
    else
    {
        //_______________________________________________________________________________
        // --output
        if (result.count("output"))
        {
            output_tfile = new TFile(result["output"].as<std::string>().c_str(), "create");
            if (not output_tfile->IsOpen())
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
    n_events = result["nevents"].as<int>();

    //_______________________________________________________________________________
    // --nsplit_jobs
    if (result.count("nsplit_jobs"))
    {
        nsplit_jobs = result["nsplit_jobs"].as<int>();
        if (nsplit_jobs <= 0)
        {
            std::cout << options.help() << std::endl;
            std::cout << "ERROR: option string --nsplit_jobs" << nsplit_jobs << " has zero or negative value!" << std::endl;
            std::cout << "I am not sure what this means..." << std::endl;
            exit(1);
        }
    }
    else
    {
        nsplit_jobs = -1;
    }

    //_______________________________________________________________________________
    // --nsplit_jobs
    if (result.count("job_index"))
    {
        job_index = result["job_index"].as<int>();
        if (job_index < 0)
        {
            std::cout << options.help() << std::endl;
            std::cout << "ERROR: option string --job_index" << job_index << " has negative value!" << std::endl;
            std::cout << "I am not sure what this means..." << std::endl;
            exit(1);
        }
    }
    else
    {
        job_index = -1;
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
            if (job_index >= nsplit_jobs)
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
    std::cout <<  " input_file_list_tstring: " << input_file_list_tstring <<  std::endl;
    std::cout <<  " output_tfile: " << output_tfile->GetName() <<  std::endl;
    std::cout <<  " n_events: " << n_events <<  std::endl;
    std::cout <<  " nsplit_jobs: " << nsplit_jobs <<  std::endl;
    std::cout <<  " job_index: " << job_index <<  std::endl;
    std::cout <<  "=========================================================" << std::endl;

}
