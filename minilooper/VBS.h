// -*- C++ -*-
// This is a header file generated with the command:
// makeCMS3ClassFiles("/home/users/jguiang/projects/philipVBSWWH/hadds/v2.6_SS/v2/createMini_Run2/vbshwwlvlvbb_c2v.root", "variable", "VBS", "tas", "vbs")

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
  vector<float> *lherewgts_;
  TBranch *lherewgts_branch;
  bool     lherewgts_isLoaded;
  float    pu_rewgt_;
  TBranch *pu_rewgt_branch;
  bool     pu_rewgt_isLoaded;
  float    pu_rewgt_up_;
  TBranch *pu_rewgt_up_branch;
  bool     pu_rewgt_up_isLoaded;
  float    pu_rewgt_dn_;
  TBranch *pu_rewgt_dn_branch;
  bool     pu_rewgt_dn_isLoaded;
  int      ntrueint_;
  TBranch *ntrueint_branch;
  bool     ntrueint_isLoaded;
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
  float    btagsf_up_;
  TBranch *btagsf_up_branch;
  bool     btagsf_up_isLoaded;
  float    btagsf_dn_;
  TBranch *btagsf_dn_branch;
  bool     btagsf_dn_isLoaded;
  float    trigsf_;
  TBranch *trigsf_branch;
  bool     trigsf_isLoaded;
  float    trigsf_up_;
  TBranch *trigsf_up_branch;
  bool     trigsf_up_isLoaded;
  float    trigsf_dn_;
  TBranch *trigsf_dn_branch;
  bool     trigsf_dn_isLoaded;
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
  int      pass_blind_bdt_;
  TBranch *pass_blind_bdt_branch;
  bool     pass_blind_bdt_isLoaded;
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
  float    LHE_muF0p5_muR0p5_;
  TBranch *LHE_muF0p5_muR0p5_branch;
  bool     LHE_muF0p5_muR0p5_isLoaded;
  float    LHE_muF1p0_muR0p5_;
  TBranch *LHE_muF1p0_muR0p5_branch;
  bool     LHE_muF1p0_muR0p5_isLoaded;
  float    LHE_muF2p0_muR0p5_;
  TBranch *LHE_muF2p0_muR0p5_branch;
  bool     LHE_muF2p0_muR0p5_isLoaded;
  float    LHE_muF0p5_muR1p0_;
  TBranch *LHE_muF0p5_muR1p0_branch;
  bool     LHE_muF0p5_muR1p0_isLoaded;
  float    LHE_muF2p0_muR1p0_;
  TBranch *LHE_muF2p0_muR1p0_branch;
  bool     LHE_muF2p0_muR1p0_isLoaded;
  float    LHE_muF0p5_muR2p0_;
  TBranch *LHE_muF0p5_muR2p0_branch;
  bool     LHE_muF0p5_muR2p0_isLoaded;
  float    LHE_muF1p0_muR2p0_;
  TBranch *LHE_muF1p0_muR2p0_branch;
  bool     LHE_muF1p0_muR2p0_isLoaded;
  float    LHE_muF2p0_muR2p0_;
  TBranch *LHE_muF2p0_muR2p0_branch;
  bool     LHE_muF2p0_muR2p0_isLoaded;
  float    LHE_pdf_wgt_up_;
  TBranch *LHE_pdf_wgt_up_branch;
  bool     LHE_pdf_wgt_up_isLoaded;
  float    LHE_pdf_wgt_dn_;
  TBranch *LHE_pdf_wgt_dn_branch;
  bool     LHE_pdf_wgt_dn_isLoaded;
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
  const vector<float> &lherewgts();
  const float &pu_rewgt();
  const float &pu_rewgt_up();
  const float &pu_rewgt_dn();
  const int &ntrueint();
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
  const float &btagsf_up();
  const float &btagsf_dn();
  const float &trigsf();
  const float &trigsf_up();
  const float &trigsf_dn();
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
  const int &pass_blind_bdt();
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
  const float &LHE_muF0p5_muR0p5();
  const float &LHE_muF1p0_muR0p5();
  const float &LHE_muF2p0_muR0p5();
  const float &LHE_muF0p5_muR1p0();
  const float &LHE_muF2p0_muR1p0();
  const float &LHE_muF0p5_muR2p0();
  const float &LHE_muF1p0_muR2p0();
  const float &LHE_muF2p0_muR2p0();
  const float &LHE_pdf_wgt_up();
  const float &LHE_pdf_wgt_dn();

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
  const vector<float> &lherewgts();
  const float &pu_rewgt();
  const float &pu_rewgt_up();
  const float &pu_rewgt_dn();
  const int &ntrueint();
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
  const float &btagsf_up();
  const float &btagsf_dn();
  const float &trigsf();
  const float &trigsf_up();
  const float &trigsf_dn();
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
  const int &pass_blind_bdt();
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
  const float &LHE_muF0p5_muR0p5();
  const float &LHE_muF1p0_muR0p5();
  const float &LHE_muF2p0_muR0p5();
  const float &LHE_muF0p5_muR1p0();
  const float &LHE_muF2p0_muR1p0();
  const float &LHE_muF0p5_muR2p0();
  const float &LHE_muF1p0_muR2p0();
  const float &LHE_muF2p0_muR2p0();
  const float &LHE_pdf_wgt_up();
  const float &LHE_pdf_wgt_dn();
}
#include "rooutil.h"
#endif
