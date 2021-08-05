// -*- C++ -*-
// This is a header file generated with the command:
// makeCMS3ClassFiles("/home/users/phchang/public_html/analysis/hwh/VBSHWWBabyLooper_____/hists/v2.4_SS/v1/createMini_2018/VBSWmpWmpH_C2V_4p5_TuneCP5_output_0.root", "variable", "VBS", "tas", "vbs")

#ifndef VBS_H
#define VBS_H

#include "Math/LorentzVector.h"
#include "Math/GenVector/PtEtaPhiM4D.h"
#include "Math/Point3D.h"
#include "TMath.h"
#include "TBranch.h"
#include "TTree.h"
#include "TH1F.h"
#include "TFile.h"
#include "TBits.h"
#include <vector> 
#include <unistd.h> 
typedef ROOT::Math::LorentzVector< ROOT::Math::PtEtaPhiM4D<float> > LorentzVector;

using namespace std; 
class VBS {
 private: 
 protected: 
  unsigned int index;
  int      run_;
  TBranch *run_branch;
  bool     run_isLoaded;
  int      lumi_;
  TBranch *lumi_branch;
  bool     lumi_isLoaded;
  unsigned long long evt_;
  TBranch *evt_branch;
  bool     evt_isLoaded;
  float    wgt_;
  TBranch *wgt_branch;
  bool     wgt_isLoaded;
  vector<float> *scalewgts_;
  TBranch *scalewgts_branch;
  bool     scalewgts_isLoaded;
  vector<float> *pswgts_;
  TBranch *pswgts_branch;
  bool     pswgts_isLoaded;
  int      trig_ee_;
  TBranch *trig_ee_branch;
  bool     trig_ee_isLoaded;
  int      trig_em_;
  TBranch *trig_em_branch;
  bool     trig_em_isLoaded;
  int      trig_mm_;
  TBranch *trig_mm_branch;
  bool     trig_mm_isLoaded;
  int      trig_se_;
  TBranch *trig_se_branch;
  bool     trig_se_isLoaded;
  int      trig_sm_;
  TBranch *trig_sm_branch;
  bool     trig_sm_isLoaded;
  int      pass_duplicate_ee_em_mm_;
  TBranch *pass_duplicate_ee_em_mm_branch;
  bool     pass_duplicate_ee_em_mm_isLoaded;
  int      pass_duplicate_mm_em_ee_;
  TBranch *pass_duplicate_mm_em_ee_branch;
  bool     pass_duplicate_mm_em_ee_isLoaded;
  int      is_pd_ee_;
  TBranch *is_pd_ee_branch;
  bool     is_pd_ee_isLoaded;
  int      is_pd_em_;
  TBranch *is_pd_em_branch;
  bool     is_pd_em_isLoaded;
  int      is_pd_mm_;
  TBranch *is_pd_mm_branch;
  bool     is_pd_mm_isLoaded;
  int      is_pd_se_;
  TBranch *is_pd_se_branch;
  bool     is_pd_se_isLoaded;
  int      is_pd_sm_;
  TBranch *is_pd_sm_branch;
  bool     is_pd_sm_isLoaded;
  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *met_p4_;
  TBranch *met_p4_branch;
  bool     met_p4_isLoaded;
  int      isvbswwh_;
  TBranch *isvbswwh_branch;
  bool     isvbswwh_isLoaded;
  int      iswwhlvlvbb_;
  TBranch *iswwhlvlvbb_branch;
  bool     iswwhlvlvbb_isLoaded;
  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *gen_jet0_;
  TBranch *gen_jet0_branch;
  bool     gen_jet0_isLoaded;
  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *gen_jet1_;
  TBranch *gen_jet1_branch;
  bool     gen_jet1_isLoaded;
  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *gen_w0_;
  TBranch *gen_w0_branch;
  bool     gen_w0_isLoaded;
  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *gen_w1_;
  TBranch *gen_w1_branch;
  bool     gen_w1_isLoaded;
  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *gen_h_;
  TBranch *gen_h_branch;
  bool     gen_h_isLoaded;
  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *gen_lep0_;
  TBranch *gen_lep0_branch;
  bool     gen_lep0_isLoaded;
  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *gen_lep1_;
  TBranch *gen_lep1_branch;
  bool     gen_lep1_isLoaded;
  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *gen_lep2_;
  TBranch *gen_lep2_branch;
  bool     gen_lep2_isLoaded;
  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *gen_nu0_;
  TBranch *gen_nu0_branch;
  bool     gen_nu0_isLoaded;
  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *gen_nu1_;
  TBranch *gen_nu1_branch;
  bool     gen_nu1_isLoaded;
  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *gen_b0_;
  TBranch *gen_b0_branch;
  bool     gen_b0_isLoaded;
  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *gen_b1_;
  TBranch *gen_b1_branch;
  bool     gen_b1_isLoaded;
  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *gen_lepA_;
  TBranch *gen_lepA_branch;
  bool     gen_lepA_isLoaded;
  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *gen_nuA_;
  TBranch *gen_nuA_branch;
  bool     gen_nuA_isLoaded;
  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *gen_lepB_;
  TBranch *gen_lepB_branch;
  bool     gen_lepB_isLoaded;
  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *gen_nuB_;
  TBranch *gen_nuB_branch;
  bool     gen_nuB_isLoaded;
  int      gen_sign_;
  TBranch *gen_sign_branch;
  bool     gen_sign_isLoaded;
  int      genchannel_;
  TBranch *genchannel_branch;
  bool     genchannel_isLoaded;
  float    genrewgt_;
  TBranch *genrewgt_branch;
  bool     genrewgt_isLoaded;
  float    gen_cosThetaStarA_;
  TBranch *gen_cosThetaStarA_branch;
  bool     gen_cosThetaStarA_isLoaded;
  float    gen_cosThetaStarB_;
  TBranch *gen_cosThetaStarB_branch;
  bool     gen_cosThetaStarB_isLoaded;
  float    lepsf_;
  TBranch *lepsf_branch;
  bool     lepsf_isLoaded;
  float    lepsf_up_;
  TBranch *lepsf_up_branch;
  bool     lepsf_up_isLoaded;
  float    lepsf_dn_;
  TBranch *lepsf_dn_branch;
  bool     lepsf_dn_isLoaded;
  float    btagsf_;
  TBranch *btagsf_branch;
  bool     btagsf_isLoaded;
  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *good_leptons_p4_;
  TBranch *good_leptons_p4_branch;
  bool     good_leptons_p4_isLoaded;
  vector<int> *good_leptons_pdgid_;
  TBranch *good_leptons_pdgid_branch;
  bool     good_leptons_pdgid_isLoaded;
  vector<int> *good_leptons_tight_;
  TBranch *good_leptons_tight_branch;
  bool     good_leptons_tight_isLoaded;
  vector<int> *good_leptons_jetIdx_;
  TBranch *good_leptons_jetIdx_branch;
  bool     good_leptons_jetIdx_isLoaded;
  vector<int> *good_leptons_genPartFlav_;
  TBranch *good_leptons_genPartFlav_branch;
  bool     good_leptons_genPartFlav_isLoaded;
  vector<float> *good_leptons_pfRelIso03_all_;
  TBranch *good_leptons_pfRelIso03_all_branch;
  bool     good_leptons_pfRelIso03_all_isLoaded;
  vector<float> *good_leptons_pfRelIso03_chg_;
  TBranch *good_leptons_pfRelIso03_chg_branch;
  bool     good_leptons_pfRelIso03_chg_isLoaded;
  vector<float> *good_leptons_jetPtRelv2_;
  TBranch *good_leptons_jetPtRelv2_branch;
  bool     good_leptons_jetPtRelv2_isLoaded;
  vector<float> *good_leptons_jetRelIso_;
  TBranch *good_leptons_jetRelIso_branch;
  bool     good_leptons_jetRelIso_isLoaded;
  vector<float> *good_leptons_miniPFRelIso_all_;
  TBranch *good_leptons_miniPFRelIso_all_branch;
  bool     good_leptons_miniPFRelIso_all_isLoaded;
  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *good_taus_p4_;
  TBranch *good_taus_p4_branch;
  bool     good_taus_p4_isLoaded;
  vector<int> *good_taus_pdgid_;
  TBranch *good_taus_pdgid_branch;
  bool     good_taus_pdgid_isLoaded;
  vector<int> *good_taus_tight_;
  TBranch *good_taus_tight_branch;
  bool     good_taus_tight_isLoaded;
  vector<int> *good_taus_jetIdx_;
  TBranch *good_taus_jetIdx_branch;
  bool     good_taus_jetIdx_isLoaded;
  vector<int> *good_taus_genPartFlav_;
  TBranch *good_taus_genPartFlav_branch;
  bool     good_taus_genPartFlav_isLoaded;
  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *good_jets_p4_;
  TBranch *good_jets_p4_branch;
  bool     good_jets_p4_isLoaded;
  vector<int> *good_jets_loose_btagged_;
  TBranch *good_jets_loose_btagged_branch;
  bool     good_jets_loose_btagged_isLoaded;
  vector<int> *good_jets_medium_btagged_;
  TBranch *good_jets_medium_btagged_branch;
  bool     good_jets_medium_btagged_isLoaded;
  vector<int> *good_jets_tight_btagged_;
  TBranch *good_jets_tight_btagged_branch;
  bool     good_jets_tight_btagged_isLoaded;
  vector<float> *good_jets_btag_score_;
  TBranch *good_jets_btag_score_branch;
  bool     good_jets_btag_score_isLoaded;
  vector<float> *good_jets_qg_disc_;
  TBranch *good_jets_qg_disc_branch;
  bool     good_jets_qg_disc_isLoaded;
  vector<int> *good_jets_flavor_;
  TBranch *good_jets_flavor_branch;
  bool     good_jets_flavor_isLoaded;
  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *good_fatjets_p4_;
  TBranch *good_fatjets_p4_branch;
  bool     good_fatjets_p4_isLoaded;
  vector<int> *good_fatjets_loose_;
  TBranch *good_fatjets_loose_branch;
  bool     good_fatjets_loose_isLoaded;
  vector<int> *good_fatjets_medium_;
  TBranch *good_fatjets_medium_branch;
  bool     good_fatjets_medium_isLoaded;
  vector<int> *good_fatjets_tight_;
  TBranch *good_fatjets_tight_branch;
  bool     good_fatjets_tight_isLoaded;
  vector<float> *good_fatjets_msd_;
  TBranch *good_fatjets_msd_branch;
  bool     good_fatjets_msd_isLoaded;
  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *higgs_jets_p4_;
  TBranch *higgs_jets_p4_branch;
  bool     higgs_jets_p4_isLoaded;
  vector<int> *higgs_jets_loose_btagged_;
  TBranch *higgs_jets_loose_btagged_branch;
  bool     higgs_jets_loose_btagged_isLoaded;
  vector<int> *higgs_jets_medium_btagged_;
  TBranch *higgs_jets_medium_btagged_branch;
  bool     higgs_jets_medium_btagged_isLoaded;
  vector<int> *higgs_jets_tight_btagged_;
  TBranch *higgs_jets_tight_btagged_branch;
  bool     higgs_jets_tight_btagged_isLoaded;
  vector<float> *higgs_jets_btag_score_;
  TBranch *higgs_jets_btag_score_branch;
  bool     higgs_jets_btag_score_isLoaded;
  vector<int> *higgs_jets_flavor_;
  TBranch *higgs_jets_flavor_branch;
  bool     higgs_jets_flavor_isLoaded;
  vector<int> *higgs_jets_good_jets_idx_;
  TBranch *higgs_jets_good_jets_idx_branch;
  bool     higgs_jets_good_jets_idx_isLoaded;
  vector<int> *higgs_jets_genmatched_;
  TBranch *higgs_jets_genmatched_branch;
  bool     higgs_jets_genmatched_isLoaded;
  vector<float> *higgs_jets_genmatched_dr_;
  TBranch *higgs_jets_genmatched_dr_branch;
  bool     higgs_jets_genmatched_dr_isLoaded;
  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *vbs_jets_p4_;
  TBranch *vbs_jets_p4_branch;
  bool     vbs_jets_p4_isLoaded;
  vector<int> *vbs_jets_good_jets_idx_;
  TBranch *vbs_jets_good_jets_idx_branch;
  bool     vbs_jets_good_jets_idx_isLoaded;
  int      nbloose_;
  TBranch *nbloose_branch;
  bool     nbloose_isLoaded;
  int      nbmedium_;
  TBranch *nbmedium_branch;
  bool     nbmedium_isLoaded;
  int      nbtight_;
  TBranch *nbtight_branch;
  bool     nbtight_isLoaded;
  int      ncenjet30_;
  TBranch *ncenjet30_branch;
  bool     ncenjet30_isLoaded;
  int      njet30_;
  TBranch *njet30_branch;
  bool     njet30_isLoaded;
  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *lep0_;
  TBranch *lep0_branch;
  bool     lep0_isLoaded;
  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *lep1_;
  TBranch *lep1_branch;
  bool     lep1_isLoaded;
  int      lep0ID_;
  TBranch *lep0ID_branch;
  bool     lep0ID_isLoaded;
  int      lep1ID_;
  TBranch *lep1ID_branch;
  bool     lep1ID_isLoaded;
  int      lep0GenPartFlav_;
  TBranch *lep0GenPartFlav_branch;
  bool     lep0GenPartFlav_isLoaded;
  int      lep1GenPartFlav_;
  TBranch *lep1GenPartFlav_branch;
  bool     lep1GenPartFlav_isLoaded;
  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *leadlep_;
  TBranch *leadlep_branch;
  bool     leadlep_isLoaded;
  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *subllep_;
  TBranch *subllep_branch;
  bool     subllep_isLoaded;
  int      leadlepID_;
  TBranch *leadlepID_branch;
  bool     leadlepID_isLoaded;
  int      subllepID_;
  TBranch *subllepID_branch;
  bool     subllepID_isLoaded;
  int      leadlepGenPartFlav_;
  TBranch *leadlepGenPartFlav_branch;
  bool     leadlepGenPartFlav_isLoaded;
  int      subllepGenPartFlav_;
  TBranch *subllepGenPartFlav_branch;
  bool     subllepGenPartFlav_isLoaded;
  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *b0_;
  TBranch *b0_branch;
  bool     b0_isLoaded;
  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *b1_;
  TBranch *b1_branch;
  bool     b1_isLoaded;
  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *j0_;
  TBranch *j0_branch;
  bool     j0_isLoaded;
  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *j1_;
  TBranch *j1_branch;
  bool     j1_isLoaded;
  int      channel_;
  TBranch *channel_branch;
  bool     channel_isLoaded;
  int      channeldetail_;
  TBranch *channeldetail_branch;
  bool     channeldetail_isLoaded;
  int      lepchannel_;
  TBranch *lepchannel_branch;
  bool     lepchannel_isLoaded;
  int      btagchannel_;
  TBranch *btagchannel_branch;
  bool     btagchannel_isLoaded;
  int      bmatchcateg_;
  TBranch *bmatchcateg_branch;
  bool     bmatchcateg_isLoaded;
  int      mee_noZ_;
  TBranch *mee_noZ_branch;
  bool     mee_noZ_isLoaded;
  int      mbbIn_;
  TBranch *mbbIn_branch;
  bool     mbbIn_isLoaded;
  int      pass_blind_;
  TBranch *pass_blind_branch;
  bool     pass_blind_isLoaded;
  int      categ_;
  TBranch *categ_branch;
  bool     categ_isLoaded;
  float    categ_F_;
  TBranch *categ_F_branch;
  bool     categ_F_isLoaded;
  float    mbb_;
  TBranch *mbb_branch;
  bool     mbb_isLoaded;
  float    dphibb_;
  TBranch *dphibb_branch;
  bool     dphibb_isLoaded;
  float    detabb_;
  TBranch *detabb_branch;
  bool     detabb_isLoaded;
  float    drbb_;
  TBranch *drbb_branch;
  bool     drbb_isLoaded;
  float    ptbb_;
  TBranch *ptbb_branch;
  bool     ptbb_isLoaded;
  float    b0pt_;
  TBranch *b0pt_branch;
  bool     b0pt_isLoaded;
  float    b1pt_;
  TBranch *b1pt_branch;
  bool     b1pt_isLoaded;
  int      b0tight_;
  TBranch *b0tight_branch;
  bool     b0tight_isLoaded;
  int      b1tight_;
  TBranch *b1tight_branch;
  bool     b1tight_isLoaded;
  float    mjj_;
  TBranch *mjj_branch;
  bool     mjj_isLoaded;
  float    dphijj_;
  TBranch *dphijj_branch;
  bool     dphijj_isLoaded;
  float    detajj_;
  TBranch *detajj_branch;
  bool     detajj_isLoaded;
  float    drjj_;
  TBranch *drjj_branch;
  bool     drjj_isLoaded;
  float    ptjj_;
  TBranch *ptjj_branch;
  bool     ptjj_isLoaded;
  float    j0pt_;
  TBranch *j0pt_branch;
  bool     j0pt_isLoaded;
  float    j1pt_;
  TBranch *j1pt_branch;
  bool     j1pt_isLoaded;
  float    j_lead_p_;
  TBranch *j_lead_p_branch;
  bool     j_lead_p_isLoaded;
  float    j_sublead_p_;
  TBranch *j_sublead_p_branch;
  bool     j_sublead_p_isLoaded;
  float    mll_;
  TBranch *mll_branch;
  bool     mll_isLoaded;
  float    dphill_;
  TBranch *dphill_branch;
  bool     dphill_isLoaded;
  float    detall_;
  TBranch *detall_branch;
  bool     detall_isLoaded;
  float    drll_;
  TBranch *drll_branch;
  bool     drll_isLoaded;
  float    ptll_;
  TBranch *ptll_branch;
  bool     ptll_isLoaded;
  float    l0pt_;
  TBranch *l0pt_branch;
  bool     l0pt_isLoaded;
  float    l1pt_;
  TBranch *l1pt_branch;
  bool     l1pt_isLoaded;
  float    met_;
  TBranch *met_branch;
  bool     met_isLoaded;
  float    lt_;
  TBranch *lt_branch;
  bool     lt_isLoaded;
  float    st_;
  TBranch *st_branch;
  bool     st_isLoaded;
  float    mvvh_;
  TBranch *mvvh_branch;
  bool     mvvh_isLoaded;
  float    mtvvh_;
  TBranch *mtvvh_branch;
  bool     mtvvh_isLoaded;
  float    ptvvh_;
  TBranch *ptvvh_branch;
  bool     ptvvh_isLoaded;
  float    v0pt_;
  TBranch *v0pt_branch;
  bool     v0pt_isLoaded;
  float    v1pt_;
  TBranch *v1pt_branch;
  bool     v1pt_isLoaded;
  float    w0mass_;
  TBranch *w0mass_branch;
  bool     w0mass_isLoaded;
  float    w1mass_;
  TBranch *w1mass_branch;
  bool     w1mass_isLoaded;
  int      is_ttbar_madgraph_;
  TBranch *is_ttbar_madgraph_branch;
  bool     is_ttbar_madgraph_isLoaded;
  int      is_ttbar_powheg_;
  TBranch *is_ttbar_powheg_branch;
  bool     is_ttbar_powheg_isLoaded;
  int      is_train_;
  TBranch *is_train_branch;
  bool     is_train_isLoaded;
  int      is_test_;
  TBranch *is_test_branch;
  bool     is_test_isLoaded;
  int      is_signal_;
  TBranch *is_signal_branch;
  bool     is_signal_isLoaded;
  int      is_background_;
  TBranch *is_background_branch;
  bool     is_background_isLoaded;
  int      is_ps_el_;
  TBranch *is_ps_el_branch;
  bool     is_ps_el_isLoaded;
  int      is_ps_mu_;
  TBranch *is_ps_mu_branch;
  bool     is_ps_mu_isLoaded;
  int      is_ps_tau_;
  TBranch *is_ps_tau_branch;
  bool     is_ps_tau_isLoaded;
  int      is_ps_neg_;
  TBranch *is_ps_neg_branch;
  bool     is_ps_neg_isLoaded;
  int      is_ps_lgt_;
  TBranch *is_ps_lgt_branch;
  bool     is_ps_lgt_isLoaded;
  int      is_cut_sr_el_;
  TBranch *is_cut_sr_el_branch;
  bool     is_cut_sr_el_isLoaded;
  int      is_cut_sr_mu_;
  TBranch *is_cut_sr_mu_branch;
  bool     is_cut_sr_mu_isLoaded;
  int      is_cut_sr_tau_;
  TBranch *is_cut_sr_tau_branch;
  bool     is_cut_sr_tau_isLoaded;
  int      is_cut_sr_neg_;
  TBranch *is_cut_sr_neg_branch;
  bool     is_cut_sr_neg_isLoaded;
  int      is_cut_sr_lgt_;
  TBranch *is_cut_sr_lgt_branch;
  bool     is_cut_sr_lgt_isLoaded;
  int      is_cut_cr_el_;
  TBranch *is_cut_cr_el_branch;
  bool     is_cut_cr_el_isLoaded;
  int      is_cut_cr_mu_;
  TBranch *is_cut_cr_mu_branch;
  bool     is_cut_cr_mu_isLoaded;
  int      is_cut_cr_tau_;
  TBranch *is_cut_cr_tau_branch;
  bool     is_cut_cr_tau_isLoaded;
  int      is_cut_cr_neg_;
  TBranch *is_cut_cr_neg_branch;
  bool     is_cut_cr_neg_isLoaded;
  int      is_cut_cr_lgt_;
  TBranch *is_cut_cr_lgt_branch;
  bool     is_cut_cr_lgt_isLoaded;
  int      is_cut_sr2_el_;
  TBranch *is_cut_sr2_el_branch;
  bool     is_cut_sr2_el_isLoaded;
  int      is_cut_sr2_mu_;
  TBranch *is_cut_sr2_mu_branch;
  bool     is_cut_sr2_mu_isLoaded;
  int      is_cut_sr2_tau_;
  TBranch *is_cut_sr2_tau_branch;
  bool     is_cut_sr2_tau_isLoaded;
  int      is_cut_sr2_neg_;
  TBranch *is_cut_sr2_neg_branch;
  bool     is_cut_sr2_neg_isLoaded;
  int      is_cut_cr2_el_;
  TBranch *is_cut_cr2_el_branch;
  bool     is_cut_cr2_el_isLoaded;
  int      is_cut_cr2_mu_;
  TBranch *is_cut_cr2_mu_branch;
  bool     is_cut_cr2_mu_isLoaded;
  int      is_cut_cr2_tau_;
  TBranch *is_cut_cr2_tau_branch;
  bool     is_cut_cr2_tau_isLoaded;
  int      is_cut_cr2_neg_;
  TBranch *is_cut_cr2_neg_branch;
  bool     is_cut_cr2_neg_isLoaded;
  int      is_bdt_sr_el_;
  TBranch *is_bdt_sr_el_branch;
  bool     is_bdt_sr_el_isLoaded;
  int      is_bdt_sr_mu_;
  TBranch *is_bdt_sr_mu_branch;
  bool     is_bdt_sr_mu_isLoaded;
  int      is_bdt_sr_tau_;
  TBranch *is_bdt_sr_tau_branch;
  bool     is_bdt_sr_tau_isLoaded;
  int      is_bdt_sr_neg_;
  TBranch *is_bdt_sr_neg_branch;
  bool     is_bdt_sr_neg_isLoaded;
  int      is_bdt_cr_el_;
  TBranch *is_bdt_cr_el_branch;
  bool     is_bdt_cr_el_isLoaded;
  int      is_bdt_cr_mu_;
  TBranch *is_bdt_cr_mu_branch;
  bool     is_bdt_cr_mu_isLoaded;
  int      is_bdt_cr_tau_;
  TBranch *is_bdt_cr_tau_branch;
  bool     is_bdt_cr_tau_isLoaded;
  int      is_bdt_cr_neg_;
  TBranch *is_bdt_cr_neg_branch;
  bool     is_bdt_cr_neg_isLoaded;
  int      is_bdt_sr2_el_;
  TBranch *is_bdt_sr2_el_branch;
  bool     is_bdt_sr2_el_isLoaded;
  int      is_bdt_sr2_mu_;
  TBranch *is_bdt_sr2_mu_branch;
  bool     is_bdt_sr2_mu_isLoaded;
  int      is_bdt_sr2_tau_;
  TBranch *is_bdt_sr2_tau_branch;
  bool     is_bdt_sr2_tau_isLoaded;
  int      is_bdt_sr2_neg_;
  TBranch *is_bdt_sr2_neg_branch;
  bool     is_bdt_sr2_neg_isLoaded;
  int      is_bdt_cr2_el_;
  TBranch *is_bdt_cr2_el_branch;
  bool     is_bdt_cr2_el_isLoaded;
  int      is_bdt_cr2_mu_;
  TBranch *is_bdt_cr2_mu_branch;
  bool     is_bdt_cr2_mu_isLoaded;
  int      is_bdt_cr2_tau_;
  TBranch *is_bdt_cr2_tau_branch;
  bool     is_bdt_cr2_tau_isLoaded;
  int      is_bdt_cr2_neg_;
  TBranch *is_bdt_cr2_neg_branch;
  bool     is_bdt_cr2_neg_isLoaded;
  int      is_ps_;
  TBranch *is_ps_branch;
  bool     is_ps_isLoaded;
  int      is_cut_sr_;
  TBranch *is_cut_sr_branch;
  bool     is_cut_sr_isLoaded;
  int      is_cut_cr_;
  TBranch *is_cut_cr_branch;
  bool     is_cut_cr_isLoaded;
  int      is_cut_sr2_;
  TBranch *is_cut_sr2_branch;
  bool     is_cut_sr2_isLoaded;
  int      is_cut_cr2_;
  TBranch *is_cut_cr2_branch;
  bool     is_cut_cr2_isLoaded;
  int      is_bdt_sr_;
  TBranch *is_bdt_sr_branch;
  bool     is_bdt_sr_isLoaded;
  int      is_bdt_cr_;
  TBranch *is_bdt_cr_branch;
  bool     is_bdt_cr_isLoaded;
  int      is_bdt_sr2_;
  TBranch *is_bdt_sr2_branch;
  bool     is_bdt_sr2_isLoaded;
  int      is_bdt_cr2_;
  TBranch *is_bdt_cr2_branch;
  bool     is_bdt_cr2_isLoaded;
  float    xsec_sf_;
  TBranch *xsec_sf_branch;
  bool     xsec_sf_isLoaded;
  float    bdt_;
  TBranch *bdt_branch;
  bool     bdt_isLoaded;
  float    bdt_mbboff_;
  TBranch *bdt_mbboff_branch;
  bool     bdt_mbboff_isLoaded;
public: 
void Init(TTree *tree);
void GetEntry(unsigned int idx); 
void LoadAllBranches(); 
  const int &run();
  const int &lumi();
  const unsigned long long &evt();
  const float &wgt();
  const vector<float> &scalewgts();
  const vector<float> &pswgts();
  const int &trig_ee();
  const int &trig_em();
  const int &trig_mm();
  const int &trig_se();
  const int &trig_sm();
  const int &pass_duplicate_ee_em_mm();
  const int &pass_duplicate_mm_em_ee();
  const int &is_pd_ee();
  const int &is_pd_em();
  const int &is_pd_mm();
  const int &is_pd_se();
  const int &is_pd_sm();
  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &met_p4();
  const int &isvbswwh();
  const int &iswwhlvlvbb();
  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &gen_jet0();
  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &gen_jet1();
  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &gen_w0();
  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &gen_w1();
  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &gen_h();
  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &gen_lep0();
  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &gen_lep1();
  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &gen_lep2();
  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &gen_nu0();
  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &gen_nu1();
  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &gen_b0();
  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &gen_b1();
  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &gen_lepA();
  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &gen_nuA();
  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &gen_lepB();
  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &gen_nuB();
  const int &gen_sign();
  const int &genchannel();
  const float &genrewgt();
  const float &gen_cosThetaStarA();
  const float &gen_cosThetaStarB();
  const float &lepsf();
  const float &lepsf_up();
  const float &lepsf_dn();
  const float &btagsf();
  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &good_leptons_p4();
  const vector<int> &good_leptons_pdgid();
  const vector<int> &good_leptons_tight();
  const vector<int> &good_leptons_jetIdx();
  const vector<int> &good_leptons_genPartFlav();
  const vector<float> &good_leptons_pfRelIso03_all();
  const vector<float> &good_leptons_pfRelIso03_chg();
  const vector<float> &good_leptons_jetPtRelv2();
  const vector<float> &good_leptons_jetRelIso();
  const vector<float> &good_leptons_miniPFRelIso_all();
  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &good_taus_p4();
  const vector<int> &good_taus_pdgid();
  const vector<int> &good_taus_tight();
  const vector<int> &good_taus_jetIdx();
  const vector<int> &good_taus_genPartFlav();
  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &good_jets_p4();
  const vector<int> &good_jets_loose_btagged();
  const vector<int> &good_jets_medium_btagged();
  const vector<int> &good_jets_tight_btagged();
  const vector<float> &good_jets_btag_score();
  const vector<float> &good_jets_qg_disc();
  const vector<int> &good_jets_flavor();
  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &good_fatjets_p4();
  const vector<int> &good_fatjets_loose();
  const vector<int> &good_fatjets_medium();
  const vector<int> &good_fatjets_tight();
  const vector<float> &good_fatjets_msd();
  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &higgs_jets_p4();
  const vector<int> &higgs_jets_loose_btagged();
  const vector<int> &higgs_jets_medium_btagged();
  const vector<int> &higgs_jets_tight_btagged();
  const vector<float> &higgs_jets_btag_score();
  const vector<int> &higgs_jets_flavor();
  const vector<int> &higgs_jets_good_jets_idx();
  const vector<int> &higgs_jets_genmatched();
  const vector<float> &higgs_jets_genmatched_dr();
  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &vbs_jets_p4();
  const vector<int> &vbs_jets_good_jets_idx();
  const int &nbloose();
  const int &nbmedium();
  const int &nbtight();
  const int &ncenjet30();
  const int &njet30();
  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &lep0();
  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &lep1();
  const int &lep0ID();
  const int &lep1ID();
  const int &lep0GenPartFlav();
  const int &lep1GenPartFlav();
  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &leadlep();
  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &subllep();
  const int &leadlepID();
  const int &subllepID();
  const int &leadlepGenPartFlav();
  const int &subllepGenPartFlav();
  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &b0();
  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &b1();
  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &j0();
  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &j1();
  const int &channel();
  const int &channeldetail();
  const int &lepchannel();
  const int &btagchannel();
  const int &bmatchcateg();
  const int &mee_noZ();
  const int &mbbIn();
  const int &pass_blind();
  const int &categ();
  const float &categ_F();
  const float &mbb();
  const float &dphibb();
  const float &detabb();
  const float &drbb();
  const float &ptbb();
  const float &b0pt();
  const float &b1pt();
  const int &b0tight();
  const int &b1tight();
  const float &mjj();
  const float &dphijj();
  const float &detajj();
  const float &drjj();
  const float &ptjj();
  const float &j0pt();
  const float &j1pt();
  const float &j_lead_p();
  const float &j_sublead_p();
  const float &mll();
  const float &dphill();
  const float &detall();
  const float &drll();
  const float &ptll();
  const float &l0pt();
  const float &l1pt();
  const float &met();
  const float &lt();
  const float &st();
  const float &mvvh();
  const float &mtvvh();
  const float &ptvvh();
  const float &v0pt();
  const float &v1pt();
  const float &w0mass();
  const float &w1mass();
  const int &is_ttbar_madgraph();
  const int &is_ttbar_powheg();
  const int &is_train();
  const int &is_test();
  const int &is_signal();
  const int &is_background();
  const int &is_ps_el();
  const int &is_ps_mu();
  const int &is_ps_tau();
  const int &is_ps_neg();
  const int &is_ps_lgt();
  const int &is_cut_sr_el();
  const int &is_cut_sr_mu();
  const int &is_cut_sr_tau();
  const int &is_cut_sr_neg();
  const int &is_cut_sr_lgt();
  const int &is_cut_cr_el();
  const int &is_cut_cr_mu();
  const int &is_cut_cr_tau();
  const int &is_cut_cr_neg();
  const int &is_cut_cr_lgt();
  const int &is_cut_sr2_el();
  const int &is_cut_sr2_mu();
  const int &is_cut_sr2_tau();
  const int &is_cut_sr2_neg();
  const int &is_cut_cr2_el();
  const int &is_cut_cr2_mu();
  const int &is_cut_cr2_tau();
  const int &is_cut_cr2_neg();
  const int &is_bdt_sr_el();
  const int &is_bdt_sr_mu();
  const int &is_bdt_sr_tau();
  const int &is_bdt_sr_neg();
  const int &is_bdt_cr_el();
  const int &is_bdt_cr_mu();
  const int &is_bdt_cr_tau();
  const int &is_bdt_cr_neg();
  const int &is_bdt_sr2_el();
  const int &is_bdt_sr2_mu();
  const int &is_bdt_sr2_tau();
  const int &is_bdt_sr2_neg();
  const int &is_bdt_cr2_el();
  const int &is_bdt_cr2_mu();
  const int &is_bdt_cr2_tau();
  const int &is_bdt_cr2_neg();
  const int &is_ps();
  const int &is_cut_sr();
  const int &is_cut_cr();
  const int &is_cut_sr2();
  const int &is_cut_cr2();
  const int &is_bdt_sr();
  const int &is_bdt_cr();
  const int &is_bdt_sr2();
  const int &is_bdt_cr2();
  const float &xsec_sf();
  const float &bdt();
  const float &bdt_mbboff();

  static void progress(int nEventsTotal, int nEventsChain);
};

#ifndef __CINT__
extern VBS vbs;
#endif

namespace tas {
  const int &run();
  const int &lumi();
  const unsigned long long &evt();
  const float &wgt();
  const vector<float> &scalewgts();
  const vector<float> &pswgts();
  const int &trig_ee();
  const int &trig_em();
  const int &trig_mm();
  const int &trig_se();
  const int &trig_sm();
  const int &pass_duplicate_ee_em_mm();
  const int &pass_duplicate_mm_em_ee();
  const int &is_pd_ee();
  const int &is_pd_em();
  const int &is_pd_mm();
  const int &is_pd_se();
  const int &is_pd_sm();
  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &met_p4();
  const int &isvbswwh();
  const int &iswwhlvlvbb();
  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &gen_jet0();
  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &gen_jet1();
  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &gen_w0();
  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &gen_w1();
  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &gen_h();
  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &gen_lep0();
  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &gen_lep1();
  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &gen_lep2();
  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &gen_nu0();
  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &gen_nu1();
  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &gen_b0();
  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &gen_b1();
  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &gen_lepA();
  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &gen_nuA();
  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &gen_lepB();
  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &gen_nuB();
  const int &gen_sign();
  const int &genchannel();
  const float &genrewgt();
  const float &gen_cosThetaStarA();
  const float &gen_cosThetaStarB();
  const float &lepsf();
  const float &lepsf_up();
  const float &lepsf_dn();
  const float &btagsf();
  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &good_leptons_p4();
  const vector<int> &good_leptons_pdgid();
  const vector<int> &good_leptons_tight();
  const vector<int> &good_leptons_jetIdx();
  const vector<int> &good_leptons_genPartFlav();
  const vector<float> &good_leptons_pfRelIso03_all();
  const vector<float> &good_leptons_pfRelIso03_chg();
  const vector<float> &good_leptons_jetPtRelv2();
  const vector<float> &good_leptons_jetRelIso();
  const vector<float> &good_leptons_miniPFRelIso_all();
  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &good_taus_p4();
  const vector<int> &good_taus_pdgid();
  const vector<int> &good_taus_tight();
  const vector<int> &good_taus_jetIdx();
  const vector<int> &good_taus_genPartFlav();
  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &good_jets_p4();
  const vector<int> &good_jets_loose_btagged();
  const vector<int> &good_jets_medium_btagged();
  const vector<int> &good_jets_tight_btagged();
  const vector<float> &good_jets_btag_score();
  const vector<float> &good_jets_qg_disc();
  const vector<int> &good_jets_flavor();
  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &good_fatjets_p4();
  const vector<int> &good_fatjets_loose();
  const vector<int> &good_fatjets_medium();
  const vector<int> &good_fatjets_tight();
  const vector<float> &good_fatjets_msd();
  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &higgs_jets_p4();
  const vector<int> &higgs_jets_loose_btagged();
  const vector<int> &higgs_jets_medium_btagged();
  const vector<int> &higgs_jets_tight_btagged();
  const vector<float> &higgs_jets_btag_score();
  const vector<int> &higgs_jets_flavor();
  const vector<int> &higgs_jets_good_jets_idx();
  const vector<int> &higgs_jets_genmatched();
  const vector<float> &higgs_jets_genmatched_dr();
  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &vbs_jets_p4();
  const vector<int> &vbs_jets_good_jets_idx();
  const int &nbloose();
  const int &nbmedium();
  const int &nbtight();
  const int &ncenjet30();
  const int &njet30();
  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &lep0();
  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &lep1();
  const int &lep0ID();
  const int &lep1ID();
  const int &lep0GenPartFlav();
  const int &lep1GenPartFlav();
  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &leadlep();
  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &subllep();
  const int &leadlepID();
  const int &subllepID();
  const int &leadlepGenPartFlav();
  const int &subllepGenPartFlav();
  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &b0();
  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &b1();
  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &j0();
  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &j1();
  const int &channel();
  const int &channeldetail();
  const int &lepchannel();
  const int &btagchannel();
  const int &bmatchcateg();
  const int &mee_noZ();
  const int &mbbIn();
  const int &pass_blind();
  const int &categ();
  const float &categ_F();
  const float &mbb();
  const float &dphibb();
  const float &detabb();
  const float &drbb();
  const float &ptbb();
  const float &b0pt();
  const float &b1pt();
  const int &b0tight();
  const int &b1tight();
  const float &mjj();
  const float &dphijj();
  const float &detajj();
  const float &drjj();
  const float &ptjj();
  const float &j0pt();
  const float &j1pt();
  const float &j_lead_p();
  const float &j_sublead_p();
  const float &mll();
  const float &dphill();
  const float &detall();
  const float &drll();
  const float &ptll();
  const float &l0pt();
  const float &l1pt();
  const float &met();
  const float &lt();
  const float &st();
  const float &mvvh();
  const float &mtvvh();
  const float &ptvvh();
  const float &v0pt();
  const float &v1pt();
  const float &w0mass();
  const float &w1mass();
  const int &is_ttbar_madgraph();
  const int &is_ttbar_powheg();
  const int &is_train();
  const int &is_test();
  const int &is_signal();
  const int &is_background();
  const int &is_ps_el();
  const int &is_ps_mu();
  const int &is_ps_tau();
  const int &is_ps_neg();
  const int &is_ps_lgt();
  const int &is_cut_sr_el();
  const int &is_cut_sr_mu();
  const int &is_cut_sr_tau();
  const int &is_cut_sr_neg();
  const int &is_cut_sr_lgt();
  const int &is_cut_cr_el();
  const int &is_cut_cr_mu();
  const int &is_cut_cr_tau();
  const int &is_cut_cr_neg();
  const int &is_cut_cr_lgt();
  const int &is_cut_sr2_el();
  const int &is_cut_sr2_mu();
  const int &is_cut_sr2_tau();
  const int &is_cut_sr2_neg();
  const int &is_cut_cr2_el();
  const int &is_cut_cr2_mu();
  const int &is_cut_cr2_tau();
  const int &is_cut_cr2_neg();
  const int &is_bdt_sr_el();
  const int &is_bdt_sr_mu();
  const int &is_bdt_sr_tau();
  const int &is_bdt_sr_neg();
  const int &is_bdt_cr_el();
  const int &is_bdt_cr_mu();
  const int &is_bdt_cr_tau();
  const int &is_bdt_cr_neg();
  const int &is_bdt_sr2_el();
  const int &is_bdt_sr2_mu();
  const int &is_bdt_sr2_tau();
  const int &is_bdt_sr2_neg();
  const int &is_bdt_cr2_el();
  const int &is_bdt_cr2_mu();
  const int &is_bdt_cr2_tau();
  const int &is_bdt_cr2_neg();
  const int &is_ps();
  const int &is_cut_sr();
  const int &is_cut_cr();
  const int &is_cut_sr2();
  const int &is_cut_cr2();
  const int &is_bdt_sr();
  const int &is_bdt_cr();
  const int &is_bdt_sr2();
  const int &is_bdt_cr2();
  const float &xsec_sf();
  const float &bdt();
  const float &bdt_mbboff();
}
#include "rooutil.h"
#endif
