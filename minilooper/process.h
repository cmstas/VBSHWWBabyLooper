#ifndef process_h
#define process_h

#include "VBS.h"
#include "rooutil.h"
#include "cxxopts.h"

#define CLTLO 300
#define CLTMD 400
#define CLTHI 500
#define CSTLO2 700
#define CSTLO 700
#define CSTMD 800
#define CSTHI 900
#define CMJJ 500
#define CDETAJJ 5
#define CDETAJJLO 4
#define CBDT 0.545
#define CBDTLO 0.52

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

extern AnalysisConfig ana;

void parseCLI(int argc, char** argv);

#endif
