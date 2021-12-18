#include "process.h"

AnalysisConfig ana;

int main(int argc, char** argv)
{

    parseCLI(argc, argv);

    // Create the TChain that holds the TTree's of the baby ntuples
    ana.events_tchain = RooUtil::FileUtil::createTChain(ana.input_tree_name, ana.input_file_list_tstring);

    // Create a Looper object to loop over input files
    ana.looper.init(ana.events_tchain, &vbs, ana.n_events);

    // Set the cutflow object output file
    ana.cutflow.setTFile(ana.output_tfile);

    TString tstr = ana.input_file_list_tstring;
    bool isdata = tstr.Contains("Run201") or tstr.Contains("data.root");
    bool issignal = tstr.Contains("VBSWWHToLNuLNubb") or tstr.Contains("vbshww");

    TString group = "none";
    if (tstr.Contains("WW")) group = "bosons";
    if (tstr.Contains("ZZ")) group = "bosons";
    if (tstr.Contains("tZq_ll_4f_ckm_NLO")) group = "raretop";
    if (tstr.Contains("ST_s-channel_4f")) group = "raretop";
    if (tstr.Contains("ST_t-channel_antitop_4f")) group = "raretop";
    if (tstr.Contains("ST_t-channel_top_4f")) group = "raretop";
    if (tstr.Contains("ST_tW_antitop_5f")) group = "raretop";
    if (tstr.Contains("ST_tW_top_5f")) group = "raretop";
    if (tstr.Contains("ST_tWll_5f_LO")) group = "raretop";
    if (tstr.Contains("TWZToLL_tlept_Whad_5f_DR")) group = "raretop";
    if (tstr.Contains("TWZToLL_thad_Wlept_5f_DR")) group = "raretop";
    if (tstr.Contains("ZZTo4L")) group = "bosons";
    if (tstr.Contains("GluGluHToZZTo4L")) group = "bosons";
    if (tstr.Contains("DYJetsToLL_M-10to50")) group = "bosons";
    if (tstr.Contains("DYJetsToLL_M-50")) group = "bosons";
    if (tstr.Contains("WJetsToLNu")) group = "bosons";
    if (tstr.Contains("TTWJetsToLNu")) group = "ttw";
    if (tstr.Contains("TTZToLLNuNu_M-10")) group = "ttz";
    if (tstr.Contains("TTZToLL_M-1to10")) group = "ttz";
    if (tstr.Contains("TTJets_DiLept")) group = "tt2l";
    if (tstr.Contains("TTJets_SingleLeptFromT")) group = "tt1l";
    if (tstr.Contains("TTJets_SingleLeptFromTbar")) group = "tt1l";
    if (tstr.Contains("TTTo2L2Nu")) group = "tt2lpowheg";
    if (tstr.Contains("TTToSemiLeptonic")) group = "tt1lpowheg";
    if (tstr.Contains("WpWpJJ_EWK")) group = "bosons";
    if (tstr.Contains("SSWW")) group = "bosons";
    if (tstr.Contains("WZTo3LNu")) group = "bosons";
    if (tstr.Contains("VBSWWHToLNuLNubb_C2V")) group = "vbshwwc2v";
    if (tstr.Contains("VBSWWHToLNuLNubb_CV")) group = "vbshwwcv";
    if (tstr.Contains("VBSWWHToLNuLNubb_C3")) group = "vbshwwc3";
    if (tstr.Contains("ttHJetTobb")) group = "raretop";
    if (tstr.Contains("ttHJetToNonbb")) group = "raretop";
    if (tstr.Contains("TTTT")) group = "raretop";
    if (tstr.Contains("TTWW")) group = "raretop";
    if (tstr.Contains("TTWZ")) group = "raretop";
    if (tstr.Contains("TTZZ")) group = "raretop";
    if (tstr.Contains("TTWH")) group = "raretop";
    if (tstr.Contains("TTZH")) group = "raretop";
    if (tstr.Contains("WWW_4F")) group = "bosons";
    if (tstr.Contains("WWZ")) group = "bosons";
    if (tstr.Contains("WZG")) group = "bosons";
    if (tstr.Contains("WZZ")) group = "bosons";
    if (tstr.Contains("ZZZ")) group = "bosons";
    if (tstr.Contains("WWToLNuQQ")) group = "bosons";
    if (tstr.Contains("WWTo2L2Nu")) group = "bosons";
    if (tstr.Contains("Run201")) group = "data";


    // Preselection
    //____________________________________________________________________________________________________________________________________________________________
    ana.cutflow.addCut("Presel", [&]() { return vbs.channel() >= 0; },
                       [&, isdata, issignal]()
                       {
                           return
                               vbs.wgt() *
                               // vbs.btagsf() *
                               // vbs.lepsf() *
                               // (issignal ? 1. : vbs.xsec_sf()) *
                               vbs.genrewgt() *
                               (isdata ? 1. : vbs.trigsf()) *
                               (ana.rwgtidx < 0 ? 1. : vbs.lherewgts()[ana.rwgtidx]) *
                               (isdata ? 1. : vbs.pu_rewgt());
                       });
    ana.cutflow.addCutToLastActiveCut("LooseVR", [&]() { return vbs.is_ps(); }, UNITY);

    ana.cutflow.getCut("LooseVR");
    ana.cutflow.addCutToLastActiveCut("El", [&]() { return vbs.is_ps_el(); }, UNITY);

    ana.cutflow.getCut("LooseVR");
    ana.cutflow.addCutToLastActiveCut("Mu", [&]() { return vbs.is_ps_mu(); }, UNITY);

    ana.cutflow.getCut("LooseVR");
    ana.cutflow.addCutToLastActiveCut("Lgt", [&]() { return vbs.is_ps_lgt(); }, UNITY);
    ana.cutflow.addCutToLastActiveCut("LgtMbbOff", [&]() { return vbs.mbb() > 150; }, UNITY);
    ana.cutflow.addCutToLastActiveCut("LgtMbbOffLowBDT", [&]() { return vbs.bdt() < 0.543; }, UNITY);

    ana.cutflow.getCut("LooseVR");
    ana.cutflow.addCutToLastActiveCut("Tau", [&]() { return vbs.is_ps_tau(); }, UNITY);
    ana.cutflow.addCutToLastActiveCut("TauMbbOff", [&]() { return vbs.mbb() > 150; }, UNITY);
    ana.cutflow.addCutToLastActiveCut("TauMbbOffLowBDT", [&]() { return vbs.bdt() < 0.543; }, UNITY);

    ana.cutflow.getCut("LooseVR");
    ana.cutflow.addCutToLastActiveCut("Neg", [&]() { return vbs.is_ps_neg(); }, UNITY);
    ana.cutflow.addCutToLastActiveCut("NegMbbOff", [&]() { return vbs.mbb() > 150; }, UNITY);
    ana.cutflow.addCutToLastActiveCut("NegMbbOffLowBDT", [&]() { return vbs.bdt() < 0.543; }, UNITY);

    ana.cutflow.getCut("LooseVR");
    ana.cutflow.addCutToLastActiveCut("MbbOff", [&]() { return vbs.mbb() > 150; }, UNITY);
    ana.cutflow.addCutToLastActiveCut("MbbOffLowBDT", [&]() { return vbs.bdt() < 0.543; }, UNITY);

    ana.cutflow.getCut("LooseVR");
    ana.cutflow.addCutToLastActiveCut("LL", [&]() { return vbs.lepchannel() == 0 or vbs.lepchannel() == 1 or vbs.lepchannel() == 2; }, UNITY);
    ana.cutflow.addCutToLastActiveCut("LLMbbOff", [&]() { return vbs.mbb() > 150; }, UNITY);

    ana.cutflow.getCut("LooseVR");
    ana.cutflow.addCutToLastActiveCut("LT", [&]() { return vbs.lepchannel() == 3 or vbs.lepchannel() == 4; }, UNITY);
    ana.cutflow.addCutToLastActiveCut("LTMbbOff", [&]() { return vbs.mbb() > 150; }, UNITY);

    enum CutBasedRegion { 
        Excluded = -999,
        // Control regions
        CR_Neg = -4, CR_Tau = -3, CR_Mu = -2, CR_El = -1,
        // Main signal regions
        C2V_El, C2V_Mu, C2V_Tau, C2V_Neg, C2V_Lgt,
        C3_El, C3_Mu, C3_Tau, C3_Neg,
        SM_El, SM_Mu, SM_Tau, SM_Neg
    };
    // Function to categorize events into bins
    auto cut_bin = [&]() {
        // C2V/CV signal regions
        if (vbs.is_cut_sr_el() and vbs.pass_blind()) return C2V_El;
        if (vbs.is_cut_sr_mu() and vbs.pass_blind()) return C2V_Mu;
        if (vbs.is_cut_sr_tau() and vbs.pass_blind()) return C2V_Tau;
        if (vbs.is_cut_sr_neg() and vbs.pass_blind()) return C2V_Neg;
        if (vbs.is_cut_sr_lgt() and vbs.pass_blind()) return C2V_Lgt;
        // C3 signal regions
        if (vbs.is_cut_c3_sr_el() and vbs.pass_blind()) return C3_El;
        if (vbs.is_cut_c3_sr_mu() and vbs.pass_blind()) return C3_Mu;
        if (vbs.is_cut_c3_sr_tau() and vbs.pass_blind()) return C3_Tau;
        if (vbs.is_cut_c3_sr_neg() and vbs.pass_blind()) return C3_Neg;
        // SM signal regions
        if (vbs.is_cut_sm_sr_el() and vbs.pass_blind()) return SM_El;
        if (vbs.is_cut_sm_sr_mu() and vbs.pass_blind()) return SM_Mu;
        if (vbs.is_cut_sm_sr_tau() and vbs.pass_blind()) return SM_Tau;
        if (vbs.is_cut_sm_sr_neg() and vbs.pass_blind()) return SM_Neg;
        // Control regions (inclusive)
        if (vbs.is_cut_cr_el()) return CR_El;
        if (vbs.is_cut_cr_mu()) return CR_Mu;
        if (vbs.is_cut_cr_tau()) return CR_Tau;
        if (vbs.is_cut_cr_neg()) return CR_Neg;
        return Excluded;
    };

    // Weaker classification
    auto cut_bin_2 = [&]() {
        if (vbs.is_cut_sr2_el() and vbs.pass_blind()) return 0;
        if (vbs.is_cut_sr2_mu() and vbs.pass_blind()) return 1;
        if (vbs.is_cut_sr2_tau() and vbs.pass_blind()) return 2;
        if (vbs.is_cut_sr2_neg() and vbs.pass_blind()) return 3;
        if (vbs.is_cut_cr_el()) return int(CR_El);
        if (vbs.is_cut_cr_mu()) return int(CR_Mu);
        if (vbs.is_cut_cr_tau()) return int(CR_Tau);
        if (vbs.is_cut_cr_neg()) return int(CR_Neg);
        return int(Excluded);
    };

    // BDT cut
    auto bdt_bin = [&]() {
        if (vbs.is_bdt_sr_el() and vbs.pass_blind_bdt()) return 0;
        if (vbs.is_bdt_sr_mu() and vbs.pass_blind_bdt()) return 1;
        if (vbs.is_bdt_sr_tau() and vbs.pass_blind_bdt()) return 2;
        if (vbs.is_bdt_sr_neg() and vbs.pass_blind_bdt()) return 3;
        if (vbs.is_bdt_cr_el()) return -1;
        if (vbs.is_bdt_cr_mu()) return -2;
        if (vbs.is_bdt_cr_tau()) return -3;
        if (vbs.is_bdt_cr_neg()) return -4;
        return -999;
    };

    // BDT cut weaker classification
    auto bdt_bin_2 = [&]() {
        if (vbs.is_bdt_sr2_el() and vbs.pass_blind_bdt()) return 0;
        if (vbs.is_bdt_sr2_mu() and vbs.pass_blind_bdt()) return 1;
        if (vbs.is_bdt_sr2_tau() and vbs.pass_blind_bdt()) return 2;
        if (vbs.is_bdt_sr2_neg() and vbs.pass_blind_bdt()) return 3;
        if (vbs.is_bdt_cr2_el()) return -1;
        if (vbs.is_bdt_cr2_mu()) return -2;
        if (vbs.is_bdt_cr2_tau()) return -3;
        if (vbs.is_bdt_cr2_neg()) return -4;
        return -999;
    };

    ana.histograms.addHistogram("NCenJet30", 9, 0, 9, [&]() { return vbs.ncenjet30(); });
    ana.histograms.addHistogram("NJet30", 9, 0, 9, [&]() { return vbs.njet30(); });
    ana.histograms.addHistogram("LT", 180, 0, 2500, [&]() { return vbs.lt(); });
    ana.histograms.addHistogram("ST", 180, 0, 3500, [&]() { return vbs.st(); });
    ana.histograms.addHistogram("LTVarBin", {0., CLTLO, CLTHI, 750}, [&]() { return vbs.lt(); });
    ana.histograms.addHistogram("STVarBin", {0., CSTLO, CSTHI, 1500}, [&]() { return vbs.st(); });
    ana.histograms.addHistogram("LTVarBin2", {0., CLTLO, CLTMD, CLTHI, 750}, [&]() { return vbs.lt(); });
    ana.histograms.addHistogram("STVarBin2", {0., CSTLO, CSTMD, CSTHI, 1500}, [&]() { return vbs.st(); });
    ana.histograms.addHistogram("STVarBin3", {0., CSTLO, 1500}, [&]() { return vbs.st(); });
    ana.histograms.addHistogram("LTZoom", 180, 0, 750, [&]() { return vbs.lt(); });
    ana.histograms.addHistogram("STZoom", 180, 0, 1500, [&]() { return vbs.st(); });
    ana.histograms.addHistogram("LeptonPt0", 180, 0, 1000, [&]() { return vbs.l0pt(); });
    ana.histograms.addHistogram("LeptonPt1", 180, 0, 600, [&]() { return vbs.l1pt(); });
    ana.histograms.addHistogram("LeptonPt0Zoom", 180, 0, 250, [&]() { return vbs.l0pt(); });
    ana.histograms.addHistogram("LeptonPt1Zoom", 180, 0, 250, [&]() { return vbs.l1pt(); });
    ana.histograms.addHistogram("LeptonPtAZoom", 180, 0, 250, [&]() { return vbs.lep0().pt(); });
    ana.histograms.addHistogram("LeptonPtBZoom", 180, 0, 250, [&]() { return vbs.lep1().pt(); });
    ana.histograms.addHistogram("LeptonEta0", 180, -3, 3, [&]() { return vbs.leadlep().eta(); });
    ana.histograms.addHistogram("LeptonEta1", 180, -3, 3, [&]() { return vbs.subllep().eta(); });
    ana.histograms.addHistogram("MJJ", 180, 0, 4500, [&]() { return vbs.mjj(); });
    ana.histograms.addHistogram("MJJZoom", 180, 0, 2500, [&]() { return vbs.mjj(); });
    ana.histograms.addHistogram("MJJVarBin", {0., CMJJ, 1200., 2500}, [&]() { return vbs.mjj(); });
    ana.histograms.addHistogram("DEtaJJ", 180, 0, 10, [&]() { return vbs.detajj(); });
    ana.histograms.addHistogram("DEtaJJVarBin", {0., 3., CDETAJJ, 10.}, [&]() { return vbs.detajj(); });
    ana.histograms.addHistogram("JetPt0", 180, 0, 250, [&]() { return vbs.j0().pt(); });
    ana.histograms.addHistogram("JetPt1", 180, 0, 150, [&]() { return vbs.j1().pt(); });
    ana.histograms.addHistogram("JetEta0", 180, -5, 5, [&]() { return vbs.j0().eta(); });
    ana.histograms.addHistogram("JetEta1", 180, -5, 5, [&]() { return vbs.j1().eta(); });
    ana.histograms.addHistogram("BJetPt0", 180, 0, 450, [&]() { return vbs.b0().pt(); });
    ana.histograms.addHistogram("BJetPt1", 180, 0, 250, [&]() { return vbs.b1().pt(); });
    ana.histograms.addHistogram("Ptbb", 180, 0, 2000, [&]() { return vbs.ptbb(); });
    ana.histograms.addHistogram("MET", 180, 0, 500, [&]() { return vbs.met(); });
    ana.histograms.addHistogram("MbbZoom", 180, 0, 300, [&]() { return vbs.mbb(); });
    ana.histograms.addHistogram("Mbb", 180, 0, 600, [&]() { return vbs.mbb(); });
    ana.histograms.addHistogram("BDT", 180, CBDT - 0.5, CBDT + 0.5, [&]() { return vbs.bdt(); });
    ana.histograms.addHistogram("BDTPassFail", 2, CBDT - 0.3, CBDT + 0.3, [&]() { return vbs.bdt(); });
    ana.histograms.addHistogram("BDTBkg", 180, CBDT - 0.45, CBDT, [&]() { return vbs.bdt(); });
    ana.histograms.addHistogram("BDTBkg2", 180, CBDT - 0.35, CBDT, [&]() { return vbs.bdt(); });
    ana.histograms.addHistogram("BDTVarBin", {CBDT - 0.3, CBDT - 0.18, CBDT - 0.12, CBDT}, [&]() { return vbs.bdt(); });
    ana.histograms.addHistogram("BDTVarBin2", {CBDT - 0.3, CBDT - 0.24, CBDT - 0.18, CBDT - 0.12, CBDT}, [&]() { return vbs.bdt(); });
    ana.histograms.addHistogram("BDTVarBin3", {CBDT - 0.3, CBDT - 0.12, CBDT}, [&]() { return vbs.bdt(); });
    ana.histograms.addHistogram("BDTVarBin4", {CBDT - 0.3, CBDT - 0.12, CBDT - 0.075, CBDT}, [&]() { return vbs.bdt(); });
    ana.histograms.addHistogram("BDTMD", 180, CBDT - 0.3, CBDT + 0.3, [&]() { return vbs.bdt_mbboff(); });
    ana.histograms.addHistogram("Yield", 1, 0, 1, [&]() { return 0; });
    ana.histograms.addHistogram("Channel", 4, 0, 4, [&]() { return vbs.categ(); });
    ana.histograms.addHistogram("DEtabb", 180, 0, 10, [&]() { return vbs.detabb(); });
    ana.histograms.addHistogram("DPhibb", 180, 0, 3.1416, [&]() { return vbs.dphibb(); });
    ana.histograms.addHistogram("DRbb", 180, 0, 10, [&]() { return vbs.drbb(); });
    ana.histograms.addHistogram("DRJJ", 180, 0, 10, [&]() { return vbs.drjj(); });
    ana.histograms.addHistogram("PtJJ", 180, 0, 600, [&]() { return vbs.ptjj(); });
    ana.histograms.addHistogram("JetE0", 180, 0, 2000, [&]() { return vbs.j_lead_p(); });
    ana.histograms.addHistogram("JetE1", 180, 0, 1500, [&]() { return vbs.j_sublead_p(); });
    ana.histograms.addHistogram("Mll", 180, 0, 600, [&]() { return vbs.mll(); });
    ana.histograms.addHistogram("DPhill", 180, 0, 3.1416, [&]() { return vbs.dphill(); });
    ana.histograms.addHistogram("DRll", 180, 0, 10, [&]() { return vbs.drll(); });
    ana.histograms.addHistogram("Ptll", 180, 0, 600, [&]() { return vbs.ptll(); });
    ana.histograms.addHistogram("MTVVH", 180, 0, 2000, [&]() { return vbs.mtvvh(); });
    ana.histograms.addHistogram("PtbbZoom", 180, 0, 500, [&]() { return vbs.ptbb(); });

    // Important variables
    ana.histograms.addVecHistogram("CutSR", 5, 0, 5, [&]() {
        std::vector<float> bins;
        CutBasedRegion bin = cut_bin();
        if (bin >= 0) bins.push_back(bin);
        return bins;
    });
    ana.histograms.addVecHistogram("CutSR2", 4, 0, 4, [&]() {
        std::vector<float> bins;
        int bin = cut_bin_2();
        if (bin >= 0) bins.push_back(bin);
        return bins;
    });
    ana.histograms.addVecHistogram("BDTSR", 4, 0, 4, [&]() {
        std::vector<float> bins;
        int bin = bdt_bin();
        if (bin >= 0) bins.push_back(bin);
        return bins;
    });
    ana.histograms.addVecHistogram("BDTSR2", 4, 0, 4, [&]() {
        std::vector<float> bins;
        int bin = bdt_bin_2();
        if (bin >= 0) bins.push_back(bin);
        return bins;
    });

    ana.histograms.addVecHistogram("CutSREl", 2, 0, 2, [&]() {
        std::vector<float> bins;
        CutBasedRegion bin = cut_bin();
        if (bin == C2V_El)
            bins.push_back(1);
        else if (bin == CR_El)
            bins.push_back(0);
        return bins;
    });
    ana.histograms.addVecHistogram("CutSRMu", 2, 0, 2, [&]() {
        std::vector<float> bins;
        CutBasedRegion bin = cut_bin();
        if (bin == C2V_Mu)
            bins.push_back(1);
        else if (bin == CR_Mu)
            bins.push_back(0);
        return bins;
    });
    ana.histograms.addVecHistogram("CutSRTau", 2, 0, 2, [&]() {
        std::vector<float> bins;
        CutBasedRegion bin = cut_bin();
        if (bin == C2V_Tau)
            bins.push_back(1);
        else if (bin == CR_Tau)
            bins.push_back(0);
        return bins;
    });
    ana.histograms.addVecHistogram("CutSRNeg", 2, 0, 2, [&]() {
        std::vector<float> bins;
        CutBasedRegion bin = cut_bin();
        if (bin == C2V_Neg)
            bins.push_back(1);
        else if (bin == CR_Neg)
            bins.push_back(0);
        return bins;
    });
    ana.histograms.addVecHistogram("CutSRLgt", 2, 0, 2, [&]() {
        std::vector<float> bins;
        CutBasedRegion bin = cut_bin();
        if (bin == C2V_Lgt)
            bins.push_back(1);
        else if (bin == CR_El or bin == CR_Mu)
            bins.push_back(0);
        return bins;
    });

    ana.histograms.addVecHistogram("CutC3SREl", 2, 0, 2, [&]() {
        std::vector<float> bins;
        CutBasedRegion bin = cut_bin();
        if (bin == C3_El)
            bins.push_back(1);
        else if (bin == CR_El)
            bins.push_back(0);
        return bins;
    });
    ana.histograms.addVecHistogram("CutC3SRMu", 2, 0, 2, [&]() {
        std::vector<float> bins;
        CutBasedRegion bin = cut_bin();
        if (bin == C3_Mu)
            bins.push_back(1);
        else if (bin == CR_Mu)
            bins.push_back(0);
        return bins;
    });
    ana.histograms.addVecHistogram("CutC3SRTau", 2, 0, 2, [&]() {
        std::vector<float> bins;
        CutBasedRegion bin = cut_bin();
        if (bin == C3_Tau)
            bins.push_back(1);
        else if (bin == CR_Tau)
            bins.push_back(0);
        return bins;
    });
    ana.histograms.addVecHistogram("CutC3SRNeg", 2, 0, 2, [&]() {
        std::vector<float> bins;
        CutBasedRegion bin = cut_bin();
        if (bin == C3_Neg)
            bins.push_back(1);
        else if (bin == CR_Neg)
            bins.push_back(0);
        return bins;
    });

    ana.histograms.addVecHistogram("CutSMSREl", 2, 0, 2, [&]() {
        std::vector<float> bins;
        CutBasedRegion bin = cut_bin();
        if (bin == SM_El)
            bins.push_back(1);
        else if (bin == CR_El)
            bins.push_back(0);
        return bins;
    });
    ana.histograms.addVecHistogram("CutSMSRMu", 2, 0, 2, [&]() {
        std::vector<float> bins;
        CutBasedRegion bin = cut_bin();
        if (bin == SM_Mu)
            bins.push_back(1);
        else if (bin == CR_Mu)
            bins.push_back(0);
        return bins;
    });
    ana.histograms.addVecHistogram("CutSMSRTau", 2, 0, 2, [&]() {
        std::vector<float> bins;
        CutBasedRegion bin = cut_bin();
        if (bin == SM_Tau)
            bins.push_back(1);
        else if (bin == CR_Tau)
            bins.push_back(0);
        return bins;
    });
    ana.histograms.addVecHistogram("CutSMSRNeg", 2, 0, 2, [&]() {
        std::vector<float> bins;
        CutBasedRegion bin = cut_bin();
        if (bin == SM_Neg)
            bins.push_back(1);
        else if (bin == CR_Neg)
            bins.push_back(0);
        return bins;
    });

    ana.histograms.addVecHistogram("BDTSREl", 2, 0, 2, [&]() {
        std::vector<float> bins;
        int bin = bdt_bin();
        if (bin == 0)
            bins.push_back(1);
        else if (bin == -1)
            bins.push_back(0);
        return bins;
    });
    ana.histograms.addVecHistogram("BDTSRMu", 2, 0, 2, [&]() {
        std::vector<float> bins;
        int bin = bdt_bin();
        if (bin == 1)
            bins.push_back(1);
        else if (bin == -2)
            bins.push_back(0);
        return bins;
    });
    ana.histograms.addVecHistogram("BDTSRTau", 2, 0, 2, [&]() {
        std::vector<float> bins;
        int bin = bdt_bin();
        if (bin == 2)
            bins.push_back(1);
        else if (bin == -3)
            bins.push_back(0);
        return bins;
    });
    ana.histograms.addVecHistogram("BDTSRNeg", 2, 0, 2, [&]() {
        std::vector<float> bins;
        int bin = bdt_bin();
        if (bin == 3)
            bins.push_back(1);
        else if (bin == -4)
            bins.push_back(0);
        return bins;
    });
    ana.histograms.addVecHistogram("BDTSRLgt", 2, 0, 2, [&]() {
        std::vector<float> bins;
        int bin = bdt_bin();
        if (bin == 0 or bin == 1)
            bins.push_back(1);
        else if (bin == -1 or bin == -2)
            bins.push_back(0);
        return bins;
    });

    ana.histograms.addVecHistogram("CutSR2El", 2, 0, 2, [&]() {
        std::vector<float> bins;
        int bin = cut_bin_2();
        if (bin == 0)
            bins.push_back(1);
        else if (bin == -1)
            bins.push_back(0);
        return bins;
    });
    ana.histograms.addVecHistogram("CutSR2Mu", 2, 0, 2, [&]() {
        std::vector<float> bins;
        int bin = cut_bin_2();
        if (bin == 1)
            bins.push_back(1);
        else if (bin == -2)
            bins.push_back(0);
        return bins;
    });
    ana.histograms.addVecHistogram("CutSR2Tau", 2, 0, 2, [&]() {
        std::vector<float> bins;
        int bin = cut_bin_2();
        if (bin == 2)
            bins.push_back(1);
        else if (bin == -3)
            bins.push_back(0);
        return bins;
    });
    ana.histograms.addVecHistogram("CutSR2Neg", 2, 0, 2, [&]() {
        std::vector<float> bins;
        int bin = cut_bin_2();
        if (bin == 3)
            bins.push_back(1);
        else if (bin == -4)
            bins.push_back(0);
        return bins;
    });
    ana.histograms.addVecHistogram("CutSR2Lgt", 2, 0, 2, [&]() {
        std::vector<float> bins;
        int bin = cut_bin_2();
        if (bin == 0 or bin == 1)
            bins.push_back(1);
        else if (bin == -1 or bin == -2)
            bins.push_back(0);
        return bins;
    });

    ana.histograms.addVecHistogram("BDTSR2El", 2, 0, 2, [&]() {
        std::vector<float> bins;
        int bin = bdt_bin_2();
        if (bin == 0)
            bins.push_back(1);
        else if (bin == -1)
            bins.push_back(0);
        return bins;
    });
    ana.histograms.addVecHistogram("BDTSR2Mu", 2, 0, 2, [&]() {
        std::vector<float> bins;
        int bin = bdt_bin_2();
        if (bin == 1)
            bins.push_back(1);
        else if (bin == -2)
            bins.push_back(0);
        return bins;
    });
    ana.histograms.addVecHistogram("BDTSR2Tau", 2, 0, 2, [&]() {
        std::vector<float> bins;
        int bin = bdt_bin_2();
        if (bin == 2)
            bins.push_back(1);
        else if (bin == -3)
            bins.push_back(0);
        return bins;
    });
    ana.histograms.addVecHistogram("BDTSR2Neg", 2, 0, 2, [&]() {
        std::vector<float> bins;
        int bin = bdt_bin_2();
        if (bin == 3)
            bins.push_back(1);
        else if (bin == -4)
            bins.push_back(0);
        return bins;
    });
    ana.histograms.addVecHistogram("BDTSR2Lgt", 2, 0, 2, [&]() {
        std::vector<float> bins;
        int bin = bdt_bin_2();
        if (bin == 0 or bin == 1)
            bins.push_back(1);
        else if (bin == -1 or bin == -2)
            bins.push_back(0);
        return bins;
    });

    ana.histograms.addVecHistogram("CutC3SR2El", 2, 0, 2, [&]() {
        std::vector<float> bins;
        CutBasedRegion bin = cut_bin();
        if (bin == C3_El)
            bins.push_back(1);
        else if (bin == CR_El)
            bins.push_back(0);
        return bins;
    });
    ana.histograms.addVecHistogram("CutC3SR2Mu", 2, 0, 2, [&]() {
        std::vector<float> bins;
        CutBasedRegion bin = cut_bin();
        if (bin == C3_Mu)
            bins.push_back(1);
        else if (bin == CR_Mu)
            bins.push_back(0);
        return bins;
    });
    ana.histograms.addVecHistogram("CutC3SR2Tau", 2, 0, 2, [&]() {
        std::vector<float> bins;
        CutBasedRegion bin = cut_bin();
        if (bin == C3_Tau)
            bins.push_back(1);
        else if (bin == CR_Tau)
            bins.push_back(0);
        return bins;
    });
    ana.histograms.addVecHistogram("CutC3SR2Neg", 2, 0, 2, [&]() {
        std::vector<float> bins;
        CutBasedRegion bin = cut_bin();
        if (bin == C3_Neg)
            bins.push_back(1);
        else if (bin == CR_Neg)
            bins.push_back(0);
        return bins;
    });
    ana.histograms.addVecHistogram("CutC3SR2Lgt", 2, 0, 2, [&]() {
        // Used to top composition systs
        std::vector<float> bins;
        CutBasedRegion bin = cut_bin();
        if (bin == C3_El || bin == C3_Mu)
            bins.push_back(1);
        else if (bin == CR_El || bin == CR_Mu)
            bins.push_back(0);
        return bins;
    });

    ana.histograms.addVecHistogram("CutSMSR2El", 2, 0, 2, [&]() {
        std::vector<float> bins;
        CutBasedRegion bin = cut_bin();
        if (bin == SM_El)
            bins.push_back(1);
        else if (bin == CR_El)
            bins.push_back(0);
        return bins;
    });
    ana.histograms.addVecHistogram("CutSMSR2Mu", 2, 0, 2, [&]() {
        std::vector<float> bins;
        CutBasedRegion bin = cut_bin();
        if (bin == SM_Mu)
            bins.push_back(1);
        else if (bin == CR_Mu)
            bins.push_back(0);
        return bins;
    });
    ana.histograms.addVecHistogram("CutSMSR2Tau", 2, 0, 2, [&]() {
        std::vector<float> bins;
        CutBasedRegion bin = cut_bin();
        if (bin == SM_Tau)
            bins.push_back(1);
        else if (bin == CR_Tau)
            bins.push_back(0);
        return bins;
    });
    ana.histograms.addVecHistogram("CutSMSR2Neg", 2, 0, 2, [&]() {
        std::vector<float> bins;
        CutBasedRegion bin = cut_bin();
        if (bin == SM_Neg)
            bins.push_back(1);
        else if (bin == CR_Neg)
            bins.push_back(0);
        return bins;
    });
    ana.histograms.addVecHistogram("CutSMSR2Lgt", 2, 0, 2, [&]() {
        std::vector<float> bins;
        CutBasedRegion bin = cut_bin();
        if (bin == SM_El || bin == SM_Mu)
            bins.push_back(1);
        else if (bin == CR_El || bin == CR_Mu)
            bins.push_back(0);
        return bins;
    });

    // Filtering histograms
    if (gSystem->AccessPathName("histograms.txt") == 0)
        ana.cutflow.setHistogramFilterFromFile("histograms.txt");

    ana.cutflow.addWgtSyst("2xTT1LUp", [&, tstr, group]() { return tstr.Contains("tt1lpowheg") or group.EqualTo("tt1lpowheg") ? 2 : 1.; });
    ana.cutflow.addWgtSyst("2xTT1LDn", [&, tstr, group]() { return tstr.Contains("tt1lpowheg") or group.EqualTo("tt1lpowheg") ? 1. / 2 : 1.; });
    ana.cutflow.addWgtSyst("2xTT2LUp", [&, tstr, group]() { return tstr.Contains("tt2lpowheg") or group.EqualTo("tt2lpowheg") ? 2 : 1.; });
    ana.cutflow.addWgtSyst("2xTT2LDn", [&, tstr, group]() { return tstr.Contains("tt2lpowheg") or group.EqualTo("tt2lpowheg") ? 1. / 2 : 1.; });
    ana.cutflow.addWgtSyst("2xTTWUp", [&, tstr, group]() { return tstr.Contains("ttw") or group.EqualTo("ttw") ? 2 : 1.; });
    ana.cutflow.addWgtSyst("2xTTWDn", [&, tstr, group]() { return tstr.Contains("ttw") or group.EqualTo("ttw") ? 1. / 2 : 1.; });
    ana.cutflow.addWgtSyst("2xTTZUp", [&, tstr, group]() { return tstr.Contains("ttz") or group.EqualTo("ttz") ? 2 : 1.; });
    ana.cutflow.addWgtSyst("2xTTZDn", [&, tstr, group]() { return tstr.Contains("ttz") or group.EqualTo("ttz") ? 1. / 2 : 1.; });
    ana.cutflow.addWgtSyst("2xRareTopUp", [&, tstr, group]() { return tstr.Contains("raretop") or group.EqualTo("raretop") ? 2 : 1.; });
    ana.cutflow.addWgtSyst("2xRareTopDn", [&, tstr, group]() { return tstr.Contains("raretop") or group.EqualTo("raretop") ? 1. / 2 : 1.; });
    ana.cutflow.addWgtSyst("LepSFUp", [&, tstr, isdata]() { return isdata ? 1. : vbs.lepsf_up() / vbs.lepsf(); });
    ana.cutflow.addWgtSyst("LepSFDn", [&, tstr, isdata]() { return isdata ? 1. : vbs.lepsf_dn() / vbs.lepsf(); });
    ana.cutflow.addWgtSyst("BTagSFUp", [&, tstr, isdata]() { return isdata ? 1. : vbs.btagsf_up() / vbs.btagsf(); });
    ana.cutflow.addWgtSyst("BTagSFDn", [&, tstr, isdata]() { return isdata ? 1. : vbs.btagsf_dn() / vbs.btagsf(); });
    ana.cutflow.addWgtSyst("PURewgtUp", [&, tstr, isdata]() { return isdata ? 1. : vbs.pu_rewgt_up() / vbs.pu_rewgt(); });
    ana.cutflow.addWgtSyst("PURewgtDn", [&, tstr, isdata]() { return isdata ? 1. : vbs.pu_rewgt_dn() / vbs.pu_rewgt(); });
    ana.cutflow.addWgtSyst("TrigSFUp", [&, tstr, isdata]() { return isdata ? 1. : vbs.trigsf_up() / vbs.trigsf(); });
    ana.cutflow.addWgtSyst("TrigSFDn", [&, tstr, isdata]() { return isdata ? 1. : vbs.trigsf_dn() / vbs.trigsf(); });
    ana.cutflow.addWgtSyst("PDFRewgtUp", [&, tstr, isdata]() { return isdata ? 1. : vbs.LHE_pdf_wgt_up(); });
    ana.cutflow.addWgtSyst("PDFRewgtDn", [&, tstr, isdata]() { return isdata ? 1. : vbs.LHE_pdf_wgt_dn(); });
    ana.cutflow.addWgtSyst("LHEmuF0p5muR0p5", [&, tstr, isdata]() { return isdata ? 1. : vbs.LHE_muF0p5_muR0p5(); });
    ana.cutflow.addWgtSyst("LHEmuF1p0muR0p5", [&, tstr, isdata]() { return isdata ? 1. : vbs.LHE_muF1p0_muR0p5(); });
    ana.cutflow.addWgtSyst("LHEmuF2p0muR0p5", [&, tstr, isdata]() { return isdata ? 1. : vbs.LHE_muF2p0_muR0p5(); });
    ana.cutflow.addWgtSyst("LHEmuF0p5muR1p0", [&, tstr, isdata]() { return isdata ? 1. : vbs.LHE_muF0p5_muR1p0(); });
    ana.cutflow.addWgtSyst("LHEmuF2p0muR1p0", [&, tstr, isdata]() { return isdata ? 1. : vbs.LHE_muF2p0_muR1p0(); });
    ana.cutflow.addWgtSyst("LHEmuF0p5muR2p0", [&, tstr, isdata]() { return isdata ? 1. : vbs.LHE_muF0p5_muR2p0(); });
    ana.cutflow.addWgtSyst("LHEmuF1p0muR2p0", [&, tstr, isdata]() { return isdata ? 1. : vbs.LHE_muF1p0_muR2p0(); });
    ana.cutflow.addWgtSyst("LHEmuF2p0muR2p0", [&, tstr, isdata]() { return isdata ? 1. : vbs.LHE_muF2p0_muR2p0(); });

    // Print cut structure
    ana.cutflow.printCuts();

    // Book cutflows
    ana.cutflow.bookCutflows();

    // Book Histograms
    ana.cutflow.bookHistogramsForCutAndBelow(ana.histograms, "Presel");

    ana.cutflow.bookEventLists();

    // Looping input file
    while (ana.looper.nextEvent())
    {

        // If splitting jobs are requested then determine whether to process the event or not based on remainder
        if (ana.job_index >= 0 and ana.nsplit_jobs > 0)
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








void parseCLI(int argc, char** argv)
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
        ("r,rwgtidx"     , "Index to use to reweight"                                                                            , cxxopts::value<int>()->default_value("-1"))
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
    // --rwgtidx 
    ana.rwgtidx = result["rwgtidx"].as<int>();

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
}
