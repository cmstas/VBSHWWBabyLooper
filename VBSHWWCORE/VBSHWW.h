#ifndef VBSHWW_h
#define VBSHWW_h

// Misc
#include "cxxopts.h"
// Rooutil
#include "rooutil.h"
// NanoCORE
#include "Nano.h"
#include "Config.h"
#include "Base.h"
#include "ElectronSelections.h"
#include "MuonSelections.h"
#include "TauSelections.h"
#include "MCTools.h"
#include "Tools/goodrun.h"
#include "Tools/btagsf/BTagCalibrationStandalone.h"
// VBSHWWCORE
#include "tools/lepScaleFactors.h" // ttH analysis scale factors
#include "tools/TauIDSFTool.h"     // tau POG scale factors

#include "TMVA/Reader.h"

class VBSHWW
{
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

    // scale1fb of the sample
    float scale1fb;

    // Debug boolean
    bool debug;

    // Tau boolean
    bool do_tau;

    // Boolean to determine whether it is UL
    bool isUL;

    // Boolean to say whether the sample contains LHEScaleWeight
    bool hasLHEScaleWeight;

    // Boolean to say whether the sample contains PSWeight
    bool hasPSWeight;

    // Boolean to say whether the sample contains LHEReweightingWeight
    bool hasLHEReweightingWeight;

    // TChain that holds the input TTree's
    TChain* events_tchain;

    // Custom Looper object to facilitate looping over many files
    RooUtil::Looper<Nano> looper;

    // Custom Cutflow framework
    RooUtil::Cutflow cutflow;

    // Custom Histograms object compatible with RooUtil::Cutflow framework
    RooUtil::Histograms histograms;

    // Custom TTree object
    RooUtil::TTreeX tx;

    // process category
    enum ProcessType
    {
        kBosons = 0,
        kRaretop,
        kTTW,
        kTTZ,
        kSignal,
        kTT1LMadGraph,
        kTT2LMadGraph,
        kTT1LPowheg,
        kTT2LPowheg,
        kNProcess,
    };

    ProcessType processType;

    TauIDSFTool* tauSF_vsJet;
    TauIDSFTool* tauSF_vsMu;
    TauIDSFTool* tauSF_vsEl;

    BTagCalibration* btagCalib;
    BTagCalibrationReader* btagReaderTight;
    BTagCalibrationReader* btagReaderMedium;
    BTagCalibrationReader* btagReaderLoose;
    RooUtil::HistMap* btagEffTight_b; // lead
    RooUtil::HistMap* btagEffTight_c; // lead
    RooUtil::HistMap* btagEffTight_l; // lead
    RooUtil::HistMap* btagEffLoose_b; // lead
    RooUtil::HistMap* btagEffLoose_c; // lead
    RooUtil::HistMap* btagEffLoose_l; // lead
    RooUtil::HistMap* btagEffTight_b_subl; // sublead
    RooUtil::HistMap* btagEffTight_c_subl; // sublead
    RooUtil::HistMap* btagEffTight_l_subl; // sublead
    RooUtil::HistMap* btagEffLoose_b_subl; // sublead
    RooUtil::HistMap* btagEffLoose_c_subl; // sublead
    RooUtil::HistMap* btagEffLoose_l_subl; // sublead

    RooUtil::HistMap* sig_rewgt; // signal reweighting

    RooUtil::TMVAUtil::ReaderX* readerX;

    VBSHWW(int, char**);
    ~VBSHWW();

    // Parse command line arguments
    void parseCLI(int argc, char** argv);
    void writeEventList(TString cutname);

    // Actions to take per event are placed here
    void process(TString final_cutname);

    // Signal and Control regions
    void initSRCutflow();

    // Select Gen particles for different processes
    void processGenParticles_VBSWWH();
    void processGenParticles_VBSWWH_UL();
    void processGenParticles_TopBackgrounds();

    // b-tagging SF
    void setBTagSF(std::vector<float> jet_pt, std::vector<float> jet_eta, std::vector<float> jet_score, std::vector<int> jet_flavor);

};


#endif
