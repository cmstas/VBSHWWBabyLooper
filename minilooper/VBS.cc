#include "VBS.h"
VBS vbs;

void VBS::Init(TTree *tree) {
  met_p4_branch = tree->GetBranch("met_p4");
  if (met_p4_branch) met_p4_branch->SetAddress(&met_p4_);
  gen_jet0_branch = tree->GetBranch("gen_jet0");
  if (gen_jet0_branch) gen_jet0_branch->SetAddress(&gen_jet0_);
  gen_jet1_branch = tree->GetBranch("gen_jet1");
  if (gen_jet1_branch) gen_jet1_branch->SetAddress(&gen_jet1_);
  gen_w0_branch = tree->GetBranch("gen_w0");
  if (gen_w0_branch) gen_w0_branch->SetAddress(&gen_w0_);
  gen_w1_branch = tree->GetBranch("gen_w1");
  if (gen_w1_branch) gen_w1_branch->SetAddress(&gen_w1_);
  gen_h_branch = tree->GetBranch("gen_h");
  if (gen_h_branch) gen_h_branch->SetAddress(&gen_h_);
  gen_lep0_branch = tree->GetBranch("gen_lep0");
  if (gen_lep0_branch) gen_lep0_branch->SetAddress(&gen_lep0_);
  gen_lep1_branch = tree->GetBranch("gen_lep1");
  if (gen_lep1_branch) gen_lep1_branch->SetAddress(&gen_lep1_);
  gen_lep2_branch = tree->GetBranch("gen_lep2");
  if (gen_lep2_branch) gen_lep2_branch->SetAddress(&gen_lep2_);
  gen_nu0_branch = tree->GetBranch("gen_nu0");
  if (gen_nu0_branch) gen_nu0_branch->SetAddress(&gen_nu0_);
  gen_nu1_branch = tree->GetBranch("gen_nu1");
  if (gen_nu1_branch) gen_nu1_branch->SetAddress(&gen_nu1_);
  gen_b0_branch = tree->GetBranch("gen_b0");
  if (gen_b0_branch) gen_b0_branch->SetAddress(&gen_b0_);
  gen_b1_branch = tree->GetBranch("gen_b1");
  if (gen_b1_branch) gen_b1_branch->SetAddress(&gen_b1_);
  gen_lepA_branch = tree->GetBranch("gen_lepA");
  if (gen_lepA_branch) gen_lepA_branch->SetAddress(&gen_lepA_);
  gen_nuA_branch = tree->GetBranch("gen_nuA");
  if (gen_nuA_branch) gen_nuA_branch->SetAddress(&gen_nuA_);
  gen_lepB_branch = tree->GetBranch("gen_lepB");
  if (gen_lepB_branch) gen_lepB_branch->SetAddress(&gen_lepB_);
  gen_nuB_branch = tree->GetBranch("gen_nuB");
  if (gen_nuB_branch) gen_nuB_branch->SetAddress(&gen_nuB_);
  lep0_branch = tree->GetBranch("lep0");
  if (lep0_branch) lep0_branch->SetAddress(&lep0_);
  lep1_branch = tree->GetBranch("lep1");
  if (lep1_branch) lep1_branch->SetAddress(&lep1_);
  leadlep_branch = tree->GetBranch("leadlep");
  if (leadlep_branch) leadlep_branch->SetAddress(&leadlep_);
  subllep_branch = tree->GetBranch("subllep");
  if (subllep_branch) subllep_branch->SetAddress(&subllep_);
  b0_branch = tree->GetBranch("b0");
  if (b0_branch) b0_branch->SetAddress(&b0_);
  b1_branch = tree->GetBranch("b1");
  if (b1_branch) b1_branch->SetAddress(&b1_);
  j0_branch = tree->GetBranch("j0");
  if (j0_branch) j0_branch->SetAddress(&j0_);
  j1_branch = tree->GetBranch("j1");
  if (j1_branch) j1_branch->SetAddress(&j1_);

  tree->SetMakeClass(1);

  run_branch = tree->GetBranch("run");
  if (run_branch) run_branch->SetAddress(&run_);
  lumi_branch = tree->GetBranch("lumi");
  if (lumi_branch) lumi_branch->SetAddress(&lumi_);
  evt_branch = tree->GetBranch("evt");
  if (evt_branch) evt_branch->SetAddress(&evt_);
  wgt_branch = tree->GetBranch("wgt");
  if (wgt_branch) wgt_branch->SetAddress(&wgt_);
  scalewgts_branch = tree->GetBranch("scalewgts");
  if (scalewgts_branch) scalewgts_branch->SetAddress(&scalewgts_);
  pswgts_branch = tree->GetBranch("pswgts");
  if (pswgts_branch) pswgts_branch->SetAddress(&pswgts_);
  isvbswwh_branch = tree->GetBranch("isvbswwh");
  if (isvbswwh_branch) isvbswwh_branch->SetAddress(&isvbswwh_);
  iswwhlvlvbb_branch = tree->GetBranch("iswwhlvlvbb");
  if (iswwhlvlvbb_branch) iswwhlvlvbb_branch->SetAddress(&iswwhlvlvbb_);
  gen_sign_branch = tree->GetBranch("gen_sign");
  if (gen_sign_branch) gen_sign_branch->SetAddress(&gen_sign_);
  genchannel_branch = tree->GetBranch("genchannel");
  if (genchannel_branch) genchannel_branch->SetAddress(&genchannel_);
  genrewgt_branch = tree->GetBranch("genrewgt");
  if (genrewgt_branch) genrewgt_branch->SetAddress(&genrewgt_);
  gen_cosThetaStarA_branch = tree->GetBranch("gen_cosThetaStarA");
  if (gen_cosThetaStarA_branch) gen_cosThetaStarA_branch->SetAddress(&gen_cosThetaStarA_);
  gen_cosThetaStarB_branch = tree->GetBranch("gen_cosThetaStarB");
  if (gen_cosThetaStarB_branch) gen_cosThetaStarB_branch->SetAddress(&gen_cosThetaStarB_);
  lepsf_branch = tree->GetBranch("lepsf");
  if (lepsf_branch) lepsf_branch->SetAddress(&lepsf_);
  lepsf_up_branch = tree->GetBranch("lepsf_up");
  if (lepsf_up_branch) lepsf_up_branch->SetAddress(&lepsf_up_);
  lepsf_dn_branch = tree->GetBranch("lepsf_dn");
  if (lepsf_dn_branch) lepsf_dn_branch->SetAddress(&lepsf_dn_);
  btagsf_branch = tree->GetBranch("btagsf");
  if (btagsf_branch) btagsf_branch->SetAddress(&btagsf_);
  nbloose_branch = tree->GetBranch("nbloose");
  if (nbloose_branch) nbloose_branch->SetAddress(&nbloose_);
  nbmedium_branch = tree->GetBranch("nbmedium");
  if (nbmedium_branch) nbmedium_branch->SetAddress(&nbmedium_);
  nbtight_branch = tree->GetBranch("nbtight");
  if (nbtight_branch) nbtight_branch->SetAddress(&nbtight_);
  ncenjet30_branch = tree->GetBranch("ncenjet30");
  if (ncenjet30_branch) ncenjet30_branch->SetAddress(&ncenjet30_);
  njet30_branch = tree->GetBranch("njet30");
  if (njet30_branch) njet30_branch->SetAddress(&njet30_);
  lep0ID_branch = tree->GetBranch("lep0ID");
  if (lep0ID_branch) lep0ID_branch->SetAddress(&lep0ID_);
  lep1ID_branch = tree->GetBranch("lep1ID");
  if (lep1ID_branch) lep1ID_branch->SetAddress(&lep1ID_);
  lep0GenPartFlav_branch = tree->GetBranch("lep0GenPartFlav");
  if (lep0GenPartFlav_branch) lep0GenPartFlav_branch->SetAddress(&lep0GenPartFlav_);
  lep1GenPartFlav_branch = tree->GetBranch("lep1GenPartFlav");
  if (lep1GenPartFlav_branch) lep1GenPartFlav_branch->SetAddress(&lep1GenPartFlav_);
  leadlepID_branch = tree->GetBranch("leadlepID");
  if (leadlepID_branch) leadlepID_branch->SetAddress(&leadlepID_);
  subllepID_branch = tree->GetBranch("subllepID");
  if (subllepID_branch) subllepID_branch->SetAddress(&subllepID_);
  leadlepGenPartFlav_branch = tree->GetBranch("leadlepGenPartFlav");
  if (leadlepGenPartFlav_branch) leadlepGenPartFlav_branch->SetAddress(&leadlepGenPartFlav_);
  subllepGenPartFlav_branch = tree->GetBranch("subllepGenPartFlav");
  if (subllepGenPartFlav_branch) subllepGenPartFlav_branch->SetAddress(&subllepGenPartFlav_);
  channel_branch = tree->GetBranch("channel");
  if (channel_branch) channel_branch->SetAddress(&channel_);
  channeldetail_branch = tree->GetBranch("channeldetail");
  if (channeldetail_branch) channeldetail_branch->SetAddress(&channeldetail_);
  lepchannel_branch = tree->GetBranch("lepchannel");
  if (lepchannel_branch) lepchannel_branch->SetAddress(&lepchannel_);
  btagchannel_branch = tree->GetBranch("btagchannel");
  if (btagchannel_branch) btagchannel_branch->SetAddress(&btagchannel_);
  bmatchcateg_branch = tree->GetBranch("bmatchcateg");
  if (bmatchcateg_branch) bmatchcateg_branch->SetAddress(&bmatchcateg_);
  mee_noZ_branch = tree->GetBranch("mee_noZ");
  if (mee_noZ_branch) mee_noZ_branch->SetAddress(&mee_noZ_);
  mbbIn_branch = tree->GetBranch("mbbIn");
  if (mbbIn_branch) mbbIn_branch->SetAddress(&mbbIn_);
  pass_blind_branch = tree->GetBranch("pass_blind");
  if (pass_blind_branch) pass_blind_branch->SetAddress(&pass_blind_);
  pass_blind_bdt_branch = tree->GetBranch("pass_blind_bdt");
  if (pass_blind_bdt_branch) pass_blind_bdt_branch->SetAddress(&pass_blind_bdt_);
  categ_branch = tree->GetBranch("categ");
  if (categ_branch) categ_branch->SetAddress(&categ_);
  categ_F_branch = tree->GetBranch("categ_F");
  if (categ_F_branch) categ_F_branch->SetAddress(&categ_F_);
  mbb_branch = tree->GetBranch("mbb");
  if (mbb_branch) mbb_branch->SetAddress(&mbb_);
  dphibb_branch = tree->GetBranch("dphibb");
  if (dphibb_branch) dphibb_branch->SetAddress(&dphibb_);
  detabb_branch = tree->GetBranch("detabb");
  if (detabb_branch) detabb_branch->SetAddress(&detabb_);
  drbb_branch = tree->GetBranch("drbb");
  if (drbb_branch) drbb_branch->SetAddress(&drbb_);
  ptbb_branch = tree->GetBranch("ptbb");
  if (ptbb_branch) ptbb_branch->SetAddress(&ptbb_);
  b0pt_branch = tree->GetBranch("b0pt");
  if (b0pt_branch) b0pt_branch->SetAddress(&b0pt_);
  b1pt_branch = tree->GetBranch("b1pt");
  if (b1pt_branch) b1pt_branch->SetAddress(&b1pt_);
  b0tight_branch = tree->GetBranch("b0tight");
  if (b0tight_branch) b0tight_branch->SetAddress(&b0tight_);
  b1tight_branch = tree->GetBranch("b1tight");
  if (b1tight_branch) b1tight_branch->SetAddress(&b1tight_);
  mjj_branch = tree->GetBranch("mjj");
  if (mjj_branch) mjj_branch->SetAddress(&mjj_);
  dphijj_branch = tree->GetBranch("dphijj");
  if (dphijj_branch) dphijj_branch->SetAddress(&dphijj_);
  detajj_branch = tree->GetBranch("detajj");
  if (detajj_branch) detajj_branch->SetAddress(&detajj_);
  drjj_branch = tree->GetBranch("drjj");
  if (drjj_branch) drjj_branch->SetAddress(&drjj_);
  ptjj_branch = tree->GetBranch("ptjj");
  if (ptjj_branch) ptjj_branch->SetAddress(&ptjj_);
  j0pt_branch = tree->GetBranch("j0pt");
  if (j0pt_branch) j0pt_branch->SetAddress(&j0pt_);
  j1pt_branch = tree->GetBranch("j1pt");
  if (j1pt_branch) j1pt_branch->SetAddress(&j1pt_);
  j_lead_p_branch = tree->GetBranch("j_lead_p");
  if (j_lead_p_branch) j_lead_p_branch->SetAddress(&j_lead_p_);
  j_sublead_p_branch = tree->GetBranch("j_sublead_p");
  if (j_sublead_p_branch) j_sublead_p_branch->SetAddress(&j_sublead_p_);
  mll_branch = tree->GetBranch("mll");
  if (mll_branch) mll_branch->SetAddress(&mll_);
  dphill_branch = tree->GetBranch("dphill");
  if (dphill_branch) dphill_branch->SetAddress(&dphill_);
  detall_branch = tree->GetBranch("detall");
  if (detall_branch) detall_branch->SetAddress(&detall_);
  drll_branch = tree->GetBranch("drll");
  if (drll_branch) drll_branch->SetAddress(&drll_);
  ptll_branch = tree->GetBranch("ptll");
  if (ptll_branch) ptll_branch->SetAddress(&ptll_);
  l0pt_branch = tree->GetBranch("l0pt");
  if (l0pt_branch) l0pt_branch->SetAddress(&l0pt_);
  l1pt_branch = tree->GetBranch("l1pt");
  if (l1pt_branch) l1pt_branch->SetAddress(&l1pt_);
  met_branch = tree->GetBranch("met");
  if (met_branch) met_branch->SetAddress(&met_);
  lt_branch = tree->GetBranch("lt");
  if (lt_branch) lt_branch->SetAddress(&lt_);
  st_branch = tree->GetBranch("st");
  if (st_branch) st_branch->SetAddress(&st_);
  mvvh_branch = tree->GetBranch("mvvh");
  if (mvvh_branch) mvvh_branch->SetAddress(&mvvh_);
  mtvvh_branch = tree->GetBranch("mtvvh");
  if (mtvvh_branch) mtvvh_branch->SetAddress(&mtvvh_);
  ptvvh_branch = tree->GetBranch("ptvvh");
  if (ptvvh_branch) ptvvh_branch->SetAddress(&ptvvh_);
  v0pt_branch = tree->GetBranch("v0pt");
  if (v0pt_branch) v0pt_branch->SetAddress(&v0pt_);
  v1pt_branch = tree->GetBranch("v1pt");
  if (v1pt_branch) v1pt_branch->SetAddress(&v1pt_);
  w0mass_branch = tree->GetBranch("w0mass");
  if (w0mass_branch) w0mass_branch->SetAddress(&w0mass_);
  w1mass_branch = tree->GetBranch("w1mass");
  if (w1mass_branch) w1mass_branch->SetAddress(&w1mass_);
  is_ttbar_madgraph_branch = tree->GetBranch("is_ttbar_madgraph");
  if (is_ttbar_madgraph_branch) is_ttbar_madgraph_branch->SetAddress(&is_ttbar_madgraph_);
  is_ttbar_powheg_branch = tree->GetBranch("is_ttbar_powheg");
  if (is_ttbar_powheg_branch) is_ttbar_powheg_branch->SetAddress(&is_ttbar_powheg_);
  is_train_branch = tree->GetBranch("is_train");
  if (is_train_branch) is_train_branch->SetAddress(&is_train_);
  is_test_branch = tree->GetBranch("is_test");
  if (is_test_branch) is_test_branch->SetAddress(&is_test_);
  is_signal_branch = tree->GetBranch("is_signal");
  if (is_signal_branch) is_signal_branch->SetAddress(&is_signal_);
  is_background_branch = tree->GetBranch("is_background");
  if (is_background_branch) is_background_branch->SetAddress(&is_background_);
  is_ps_el_branch = tree->GetBranch("is_ps_el");
  if (is_ps_el_branch) is_ps_el_branch->SetAddress(&is_ps_el_);
  is_ps_mu_branch = tree->GetBranch("is_ps_mu");
  if (is_ps_mu_branch) is_ps_mu_branch->SetAddress(&is_ps_mu_);
  is_ps_tau_branch = tree->GetBranch("is_ps_tau");
  if (is_ps_tau_branch) is_ps_tau_branch->SetAddress(&is_ps_tau_);
  is_ps_neg_branch = tree->GetBranch("is_ps_neg");
  if (is_ps_neg_branch) is_ps_neg_branch->SetAddress(&is_ps_neg_);
  is_ps_lgt_branch = tree->GetBranch("is_ps_lgt");
  if (is_ps_lgt_branch) is_ps_lgt_branch->SetAddress(&is_ps_lgt_);
  is_cut_sr_el_branch = tree->GetBranch("is_cut_sr_el");
  if (is_cut_sr_el_branch) is_cut_sr_el_branch->SetAddress(&is_cut_sr_el_);
  is_cut_sr_mu_branch = tree->GetBranch("is_cut_sr_mu");
  if (is_cut_sr_mu_branch) is_cut_sr_mu_branch->SetAddress(&is_cut_sr_mu_);
  is_cut_sr_tau_branch = tree->GetBranch("is_cut_sr_tau");
  if (is_cut_sr_tau_branch) is_cut_sr_tau_branch->SetAddress(&is_cut_sr_tau_);
  is_cut_sr_neg_branch = tree->GetBranch("is_cut_sr_neg");
  if (is_cut_sr_neg_branch) is_cut_sr_neg_branch->SetAddress(&is_cut_sr_neg_);
  is_cut_sr_lgt_branch = tree->GetBranch("is_cut_sr_lgt");
  if (is_cut_sr_lgt_branch) is_cut_sr_lgt_branch->SetAddress(&is_cut_sr_lgt_);
  is_cut_cr_el_branch = tree->GetBranch("is_cut_cr_el");
  if (is_cut_cr_el_branch) is_cut_cr_el_branch->SetAddress(&is_cut_cr_el_);
  is_cut_cr_mu_branch = tree->GetBranch("is_cut_cr_mu");
  if (is_cut_cr_mu_branch) is_cut_cr_mu_branch->SetAddress(&is_cut_cr_mu_);
  is_cut_cr_tau_branch = tree->GetBranch("is_cut_cr_tau");
  if (is_cut_cr_tau_branch) is_cut_cr_tau_branch->SetAddress(&is_cut_cr_tau_);
  is_cut_cr_neg_branch = tree->GetBranch("is_cut_cr_neg");
  if (is_cut_cr_neg_branch) is_cut_cr_neg_branch->SetAddress(&is_cut_cr_neg_);
  is_cut_cr_lgt_branch = tree->GetBranch("is_cut_cr_lgt");
  if (is_cut_cr_lgt_branch) is_cut_cr_lgt_branch->SetAddress(&is_cut_cr_lgt_);
  is_cut_sr2_el_branch = tree->GetBranch("is_cut_sr2_el");
  if (is_cut_sr2_el_branch) is_cut_sr2_el_branch->SetAddress(&is_cut_sr2_el_);
  is_cut_sr2_mu_branch = tree->GetBranch("is_cut_sr2_mu");
  if (is_cut_sr2_mu_branch) is_cut_sr2_mu_branch->SetAddress(&is_cut_sr2_mu_);
  is_cut_sr2_tau_branch = tree->GetBranch("is_cut_sr2_tau");
  if (is_cut_sr2_tau_branch) is_cut_sr2_tau_branch->SetAddress(&is_cut_sr2_tau_);
  is_cut_sr2_neg_branch = tree->GetBranch("is_cut_sr2_neg");
  if (is_cut_sr2_neg_branch) is_cut_sr2_neg_branch->SetAddress(&is_cut_sr2_neg_);
  is_cut_cr2_el_branch = tree->GetBranch("is_cut_cr2_el");
  if (is_cut_cr2_el_branch) is_cut_cr2_el_branch->SetAddress(&is_cut_cr2_el_);
  is_cut_cr2_mu_branch = tree->GetBranch("is_cut_cr2_mu");
  if (is_cut_cr2_mu_branch) is_cut_cr2_mu_branch->SetAddress(&is_cut_cr2_mu_);
  is_cut_cr2_tau_branch = tree->GetBranch("is_cut_cr2_tau");
  if (is_cut_cr2_tau_branch) is_cut_cr2_tau_branch->SetAddress(&is_cut_cr2_tau_);
  is_cut_cr2_neg_branch = tree->GetBranch("is_cut_cr2_neg");
  if (is_cut_cr2_neg_branch) is_cut_cr2_neg_branch->SetAddress(&is_cut_cr2_neg_);
  is_bdt_sr_el_branch = tree->GetBranch("is_bdt_sr_el");
  if (is_bdt_sr_el_branch) is_bdt_sr_el_branch->SetAddress(&is_bdt_sr_el_);
  is_bdt_sr_mu_branch = tree->GetBranch("is_bdt_sr_mu");
  if (is_bdt_sr_mu_branch) is_bdt_sr_mu_branch->SetAddress(&is_bdt_sr_mu_);
  is_bdt_sr_tau_branch = tree->GetBranch("is_bdt_sr_tau");
  if (is_bdt_sr_tau_branch) is_bdt_sr_tau_branch->SetAddress(&is_bdt_sr_tau_);
  is_bdt_sr_neg_branch = tree->GetBranch("is_bdt_sr_neg");
  if (is_bdt_sr_neg_branch) is_bdt_sr_neg_branch->SetAddress(&is_bdt_sr_neg_);
  is_bdt_cr_el_branch = tree->GetBranch("is_bdt_cr_el");
  if (is_bdt_cr_el_branch) is_bdt_cr_el_branch->SetAddress(&is_bdt_cr_el_);
  is_bdt_cr_mu_branch = tree->GetBranch("is_bdt_cr_mu");
  if (is_bdt_cr_mu_branch) is_bdt_cr_mu_branch->SetAddress(&is_bdt_cr_mu_);
  is_bdt_cr_tau_branch = tree->GetBranch("is_bdt_cr_tau");
  if (is_bdt_cr_tau_branch) is_bdt_cr_tau_branch->SetAddress(&is_bdt_cr_tau_);
  is_bdt_cr_neg_branch = tree->GetBranch("is_bdt_cr_neg");
  if (is_bdt_cr_neg_branch) is_bdt_cr_neg_branch->SetAddress(&is_bdt_cr_neg_);
  is_bdt_sr2_el_branch = tree->GetBranch("is_bdt_sr2_el");
  if (is_bdt_sr2_el_branch) is_bdt_sr2_el_branch->SetAddress(&is_bdt_sr2_el_);
  is_bdt_sr2_mu_branch = tree->GetBranch("is_bdt_sr2_mu");
  if (is_bdt_sr2_mu_branch) is_bdt_sr2_mu_branch->SetAddress(&is_bdt_sr2_mu_);
  is_bdt_sr2_tau_branch = tree->GetBranch("is_bdt_sr2_tau");
  if (is_bdt_sr2_tau_branch) is_bdt_sr2_tau_branch->SetAddress(&is_bdt_sr2_tau_);
  is_bdt_sr2_neg_branch = tree->GetBranch("is_bdt_sr2_neg");
  if (is_bdt_sr2_neg_branch) is_bdt_sr2_neg_branch->SetAddress(&is_bdt_sr2_neg_);
  is_bdt_cr2_el_branch = tree->GetBranch("is_bdt_cr2_el");
  if (is_bdt_cr2_el_branch) is_bdt_cr2_el_branch->SetAddress(&is_bdt_cr2_el_);
  is_bdt_cr2_mu_branch = tree->GetBranch("is_bdt_cr2_mu");
  if (is_bdt_cr2_mu_branch) is_bdt_cr2_mu_branch->SetAddress(&is_bdt_cr2_mu_);
  is_bdt_cr2_tau_branch = tree->GetBranch("is_bdt_cr2_tau");
  if (is_bdt_cr2_tau_branch) is_bdt_cr2_tau_branch->SetAddress(&is_bdt_cr2_tau_);
  is_bdt_cr2_neg_branch = tree->GetBranch("is_bdt_cr2_neg");
  if (is_bdt_cr2_neg_branch) is_bdt_cr2_neg_branch->SetAddress(&is_bdt_cr2_neg_);
  is_ps_branch = tree->GetBranch("is_ps");
  if (is_ps_branch) is_ps_branch->SetAddress(&is_ps_);
  is_cut_sr_branch = tree->GetBranch("is_cut_sr");
  if (is_cut_sr_branch) is_cut_sr_branch->SetAddress(&is_cut_sr_);
  is_cut_cr_branch = tree->GetBranch("is_cut_cr");
  if (is_cut_cr_branch) is_cut_cr_branch->SetAddress(&is_cut_cr_);
  is_cut_sr2_branch = tree->GetBranch("is_cut_sr2");
  if (is_cut_sr2_branch) is_cut_sr2_branch->SetAddress(&is_cut_sr2_);
  is_cut_cr2_branch = tree->GetBranch("is_cut_cr2");
  if (is_cut_cr2_branch) is_cut_cr2_branch->SetAddress(&is_cut_cr2_);
  is_bdt_sr_branch = tree->GetBranch("is_bdt_sr");
  if (is_bdt_sr_branch) is_bdt_sr_branch->SetAddress(&is_bdt_sr_);
  is_bdt_cr_branch = tree->GetBranch("is_bdt_cr");
  if (is_bdt_cr_branch) is_bdt_cr_branch->SetAddress(&is_bdt_cr_);
  is_bdt_sr2_branch = tree->GetBranch("is_bdt_sr2");
  if (is_bdt_sr2_branch) is_bdt_sr2_branch->SetAddress(&is_bdt_sr2_);
  is_bdt_cr2_branch = tree->GetBranch("is_bdt_cr2");
  if (is_bdt_cr2_branch) is_bdt_cr2_branch->SetAddress(&is_bdt_cr2_);
  xsec_sf_branch = tree->GetBranch("xsec_sf");
  if (xsec_sf_branch) xsec_sf_branch->SetAddress(&xsec_sf_);
  bdt_branch = tree->GetBranch("bdt");
  if (bdt_branch) bdt_branch->SetAddress(&bdt_);
  bdt_mbboff_branch = tree->GetBranch("bdt_mbboff");
  if (bdt_mbboff_branch) bdt_mbboff_branch->SetAddress(&bdt_mbboff_);

  tree->SetMakeClass(0);
}

void VBS::GetEntry(unsigned int idx) {
  // this only marks branches as not loaded, saving a lot of time
  index = idx;
  run_isLoaded = false;
  lumi_isLoaded = false;
  evt_isLoaded = false;
  wgt_isLoaded = false;
  scalewgts_isLoaded = false;
  pswgts_isLoaded = false;
  met_p4_isLoaded = false;
  isvbswwh_isLoaded = false;
  iswwhlvlvbb_isLoaded = false;
  gen_jet0_isLoaded = false;
  gen_jet1_isLoaded = false;
  gen_w0_isLoaded = false;
  gen_w1_isLoaded = false;
  gen_h_isLoaded = false;
  gen_lep0_isLoaded = false;
  gen_lep1_isLoaded = false;
  gen_lep2_isLoaded = false;
  gen_nu0_isLoaded = false;
  gen_nu1_isLoaded = false;
  gen_b0_isLoaded = false;
  gen_b1_isLoaded = false;
  gen_lepA_isLoaded = false;
  gen_nuA_isLoaded = false;
  gen_lepB_isLoaded = false;
  gen_nuB_isLoaded = false;
  gen_sign_isLoaded = false;
  genchannel_isLoaded = false;
  genrewgt_isLoaded = false;
  gen_cosThetaStarA_isLoaded = false;
  gen_cosThetaStarB_isLoaded = false;
  lepsf_isLoaded = false;
  lepsf_up_isLoaded = false;
  lepsf_dn_isLoaded = false;
  btagsf_isLoaded = false;
  nbloose_isLoaded = false;
  nbmedium_isLoaded = false;
  nbtight_isLoaded = false;
  ncenjet30_isLoaded = false;
  njet30_isLoaded = false;
  lep0_isLoaded = false;
  lep1_isLoaded = false;
  lep0ID_isLoaded = false;
  lep1ID_isLoaded = false;
  lep0GenPartFlav_isLoaded = false;
  lep1GenPartFlav_isLoaded = false;
  leadlep_isLoaded = false;
  subllep_isLoaded = false;
  leadlepID_isLoaded = false;
  subllepID_isLoaded = false;
  leadlepGenPartFlav_isLoaded = false;
  subllepGenPartFlav_isLoaded = false;
  b0_isLoaded = false;
  b1_isLoaded = false;
  j0_isLoaded = false;
  j1_isLoaded = false;
  channel_isLoaded = false;
  channeldetail_isLoaded = false;
  lepchannel_isLoaded = false;
  btagchannel_isLoaded = false;
  bmatchcateg_isLoaded = false;
  mee_noZ_isLoaded = false;
  mbbIn_isLoaded = false;
  pass_blind_isLoaded = false;
  pass_blind_bdt_isLoaded = false;
  categ_isLoaded = false;
  categ_F_isLoaded = false;
  mbb_isLoaded = false;
  dphibb_isLoaded = false;
  detabb_isLoaded = false;
  drbb_isLoaded = false;
  ptbb_isLoaded = false;
  b0pt_isLoaded = false;
  b1pt_isLoaded = false;
  b0tight_isLoaded = false;
  b1tight_isLoaded = false;
  mjj_isLoaded = false;
  dphijj_isLoaded = false;
  detajj_isLoaded = false;
  drjj_isLoaded = false;
  ptjj_isLoaded = false;
  j0pt_isLoaded = false;
  j1pt_isLoaded = false;
  j_lead_p_isLoaded = false;
  j_sublead_p_isLoaded = false;
  mll_isLoaded = false;
  dphill_isLoaded = false;
  detall_isLoaded = false;
  drll_isLoaded = false;
  ptll_isLoaded = false;
  l0pt_isLoaded = false;
  l1pt_isLoaded = false;
  met_isLoaded = false;
  lt_isLoaded = false;
  st_isLoaded = false;
  mvvh_isLoaded = false;
  mtvvh_isLoaded = false;
  ptvvh_isLoaded = false;
  v0pt_isLoaded = false;
  v1pt_isLoaded = false;
  w0mass_isLoaded = false;
  w1mass_isLoaded = false;
  is_ttbar_madgraph_isLoaded = false;
  is_ttbar_powheg_isLoaded = false;
  is_train_isLoaded = false;
  is_test_isLoaded = false;
  is_signal_isLoaded = false;
  is_background_isLoaded = false;
  is_ps_el_isLoaded = false;
  is_ps_mu_isLoaded = false;
  is_ps_tau_isLoaded = false;
  is_ps_neg_isLoaded = false;
  is_ps_lgt_isLoaded = false;
  is_cut_sr_el_isLoaded = false;
  is_cut_sr_mu_isLoaded = false;
  is_cut_sr_tau_isLoaded = false;
  is_cut_sr_neg_isLoaded = false;
  is_cut_sr_lgt_isLoaded = false;
  is_cut_cr_el_isLoaded = false;
  is_cut_cr_mu_isLoaded = false;
  is_cut_cr_tau_isLoaded = false;
  is_cut_cr_neg_isLoaded = false;
  is_cut_cr_lgt_isLoaded = false;
  is_cut_sr2_el_isLoaded = false;
  is_cut_sr2_mu_isLoaded = false;
  is_cut_sr2_tau_isLoaded = false;
  is_cut_sr2_neg_isLoaded = false;
  is_cut_cr2_el_isLoaded = false;
  is_cut_cr2_mu_isLoaded = false;
  is_cut_cr2_tau_isLoaded = false;
  is_cut_cr2_neg_isLoaded = false;
  is_bdt_sr_el_isLoaded = false;
  is_bdt_sr_mu_isLoaded = false;
  is_bdt_sr_tau_isLoaded = false;
  is_bdt_sr_neg_isLoaded = false;
  is_bdt_cr_el_isLoaded = false;
  is_bdt_cr_mu_isLoaded = false;
  is_bdt_cr_tau_isLoaded = false;
  is_bdt_cr_neg_isLoaded = false;
  is_bdt_sr2_el_isLoaded = false;
  is_bdt_sr2_mu_isLoaded = false;
  is_bdt_sr2_tau_isLoaded = false;
  is_bdt_sr2_neg_isLoaded = false;
  is_bdt_cr2_el_isLoaded = false;
  is_bdt_cr2_mu_isLoaded = false;
  is_bdt_cr2_tau_isLoaded = false;
  is_bdt_cr2_neg_isLoaded = false;
  is_ps_isLoaded = false;
  is_cut_sr_isLoaded = false;
  is_cut_cr_isLoaded = false;
  is_cut_sr2_isLoaded = false;
  is_cut_cr2_isLoaded = false;
  is_bdt_sr_isLoaded = false;
  is_bdt_cr_isLoaded = false;
  is_bdt_sr2_isLoaded = false;
  is_bdt_cr2_isLoaded = false;
  xsec_sf_isLoaded = false;
  bdt_isLoaded = false;
  bdt_mbboff_isLoaded = false;
}

void VBS::LoadAllBranches() {
  // load all branches
  if (run_branch != 0) run();
  if (lumi_branch != 0) lumi();
  if (evt_branch != 0) evt();
  if (wgt_branch != 0) wgt();
  if (scalewgts_branch != 0) scalewgts();
  if (pswgts_branch != 0) pswgts();
  if (met_p4_branch != 0) met_p4();
  if (isvbswwh_branch != 0) isvbswwh();
  if (iswwhlvlvbb_branch != 0) iswwhlvlvbb();
  if (gen_jet0_branch != 0) gen_jet0();
  if (gen_jet1_branch != 0) gen_jet1();
  if (gen_w0_branch != 0) gen_w0();
  if (gen_w1_branch != 0) gen_w1();
  if (gen_h_branch != 0) gen_h();
  if (gen_lep0_branch != 0) gen_lep0();
  if (gen_lep1_branch != 0) gen_lep1();
  if (gen_lep2_branch != 0) gen_lep2();
  if (gen_nu0_branch != 0) gen_nu0();
  if (gen_nu1_branch != 0) gen_nu1();
  if (gen_b0_branch != 0) gen_b0();
  if (gen_b1_branch != 0) gen_b1();
  if (gen_lepA_branch != 0) gen_lepA();
  if (gen_nuA_branch != 0) gen_nuA();
  if (gen_lepB_branch != 0) gen_lepB();
  if (gen_nuB_branch != 0) gen_nuB();
  if (gen_sign_branch != 0) gen_sign();
  if (genchannel_branch != 0) genchannel();
  if (genrewgt_branch != 0) genrewgt();
  if (gen_cosThetaStarA_branch != 0) gen_cosThetaStarA();
  if (gen_cosThetaStarB_branch != 0) gen_cosThetaStarB();
  if (lepsf_branch != 0) lepsf();
  if (lepsf_up_branch != 0) lepsf_up();
  if (lepsf_dn_branch != 0) lepsf_dn();
  if (btagsf_branch != 0) btagsf();
  if (nbloose_branch != 0) nbloose();
  if (nbmedium_branch != 0) nbmedium();
  if (nbtight_branch != 0) nbtight();
  if (ncenjet30_branch != 0) ncenjet30();
  if (njet30_branch != 0) njet30();
  if (lep0_branch != 0) lep0();
  if (lep1_branch != 0) lep1();
  if (lep0ID_branch != 0) lep0ID();
  if (lep1ID_branch != 0) lep1ID();
  if (lep0GenPartFlav_branch != 0) lep0GenPartFlav();
  if (lep1GenPartFlav_branch != 0) lep1GenPartFlav();
  if (leadlep_branch != 0) leadlep();
  if (subllep_branch != 0) subllep();
  if (leadlepID_branch != 0) leadlepID();
  if (subllepID_branch != 0) subllepID();
  if (leadlepGenPartFlav_branch != 0) leadlepGenPartFlav();
  if (subllepGenPartFlav_branch != 0) subllepGenPartFlav();
  if (b0_branch != 0) b0();
  if (b1_branch != 0) b1();
  if (j0_branch != 0) j0();
  if (j1_branch != 0) j1();
  if (channel_branch != 0) channel();
  if (channeldetail_branch != 0) channeldetail();
  if (lepchannel_branch != 0) lepchannel();
  if (btagchannel_branch != 0) btagchannel();
  if (bmatchcateg_branch != 0) bmatchcateg();
  if (mee_noZ_branch != 0) mee_noZ();
  if (mbbIn_branch != 0) mbbIn();
  if (pass_blind_branch != 0) pass_blind();
  if (pass_blind_bdt_branch != 0) pass_blind_bdt();
  if (categ_branch != 0) categ();
  if (categ_F_branch != 0) categ_F();
  if (mbb_branch != 0) mbb();
  if (dphibb_branch != 0) dphibb();
  if (detabb_branch != 0) detabb();
  if (drbb_branch != 0) drbb();
  if (ptbb_branch != 0) ptbb();
  if (b0pt_branch != 0) b0pt();
  if (b1pt_branch != 0) b1pt();
  if (b0tight_branch != 0) b0tight();
  if (b1tight_branch != 0) b1tight();
  if (mjj_branch != 0) mjj();
  if (dphijj_branch != 0) dphijj();
  if (detajj_branch != 0) detajj();
  if (drjj_branch != 0) drjj();
  if (ptjj_branch != 0) ptjj();
  if (j0pt_branch != 0) j0pt();
  if (j1pt_branch != 0) j1pt();
  if (j_lead_p_branch != 0) j_lead_p();
  if (j_sublead_p_branch != 0) j_sublead_p();
  if (mll_branch != 0) mll();
  if (dphill_branch != 0) dphill();
  if (detall_branch != 0) detall();
  if (drll_branch != 0) drll();
  if (ptll_branch != 0) ptll();
  if (l0pt_branch != 0) l0pt();
  if (l1pt_branch != 0) l1pt();
  if (met_branch != 0) met();
  if (lt_branch != 0) lt();
  if (st_branch != 0) st();
  if (mvvh_branch != 0) mvvh();
  if (mtvvh_branch != 0) mtvvh();
  if (ptvvh_branch != 0) ptvvh();
  if (v0pt_branch != 0) v0pt();
  if (v1pt_branch != 0) v1pt();
  if (w0mass_branch != 0) w0mass();
  if (w1mass_branch != 0) w1mass();
  if (is_ttbar_madgraph_branch != 0) is_ttbar_madgraph();
  if (is_ttbar_powheg_branch != 0) is_ttbar_powheg();
  if (is_train_branch != 0) is_train();
  if (is_test_branch != 0) is_test();
  if (is_signal_branch != 0) is_signal();
  if (is_background_branch != 0) is_background();
  if (is_ps_el_branch != 0) is_ps_el();
  if (is_ps_mu_branch != 0) is_ps_mu();
  if (is_ps_tau_branch != 0) is_ps_tau();
  if (is_ps_neg_branch != 0) is_ps_neg();
  if (is_ps_lgt_branch != 0) is_ps_lgt();
  if (is_cut_sr_el_branch != 0) is_cut_sr_el();
  if (is_cut_sr_mu_branch != 0) is_cut_sr_mu();
  if (is_cut_sr_tau_branch != 0) is_cut_sr_tau();
  if (is_cut_sr_neg_branch != 0) is_cut_sr_neg();
  if (is_cut_sr_lgt_branch != 0) is_cut_sr_lgt();
  if (is_cut_cr_el_branch != 0) is_cut_cr_el();
  if (is_cut_cr_mu_branch != 0) is_cut_cr_mu();
  if (is_cut_cr_tau_branch != 0) is_cut_cr_tau();
  if (is_cut_cr_neg_branch != 0) is_cut_cr_neg();
  if (is_cut_cr_lgt_branch != 0) is_cut_cr_lgt();
  if (is_cut_sr2_el_branch != 0) is_cut_sr2_el();
  if (is_cut_sr2_mu_branch != 0) is_cut_sr2_mu();
  if (is_cut_sr2_tau_branch != 0) is_cut_sr2_tau();
  if (is_cut_sr2_neg_branch != 0) is_cut_sr2_neg();
  if (is_cut_cr2_el_branch != 0) is_cut_cr2_el();
  if (is_cut_cr2_mu_branch != 0) is_cut_cr2_mu();
  if (is_cut_cr2_tau_branch != 0) is_cut_cr2_tau();
  if (is_cut_cr2_neg_branch != 0) is_cut_cr2_neg();
  if (is_bdt_sr_el_branch != 0) is_bdt_sr_el();
  if (is_bdt_sr_mu_branch != 0) is_bdt_sr_mu();
  if (is_bdt_sr_tau_branch != 0) is_bdt_sr_tau();
  if (is_bdt_sr_neg_branch != 0) is_bdt_sr_neg();
  if (is_bdt_cr_el_branch != 0) is_bdt_cr_el();
  if (is_bdt_cr_mu_branch != 0) is_bdt_cr_mu();
  if (is_bdt_cr_tau_branch != 0) is_bdt_cr_tau();
  if (is_bdt_cr_neg_branch != 0) is_bdt_cr_neg();
  if (is_bdt_sr2_el_branch != 0) is_bdt_sr2_el();
  if (is_bdt_sr2_mu_branch != 0) is_bdt_sr2_mu();
  if (is_bdt_sr2_tau_branch != 0) is_bdt_sr2_tau();
  if (is_bdt_sr2_neg_branch != 0) is_bdt_sr2_neg();
  if (is_bdt_cr2_el_branch != 0) is_bdt_cr2_el();
  if (is_bdt_cr2_mu_branch != 0) is_bdt_cr2_mu();
  if (is_bdt_cr2_tau_branch != 0) is_bdt_cr2_tau();
  if (is_bdt_cr2_neg_branch != 0) is_bdt_cr2_neg();
  if (is_ps_branch != 0) is_ps();
  if (is_cut_sr_branch != 0) is_cut_sr();
  if (is_cut_cr_branch != 0) is_cut_cr();
  if (is_cut_sr2_branch != 0) is_cut_sr2();
  if (is_cut_cr2_branch != 0) is_cut_cr2();
  if (is_bdt_sr_branch != 0) is_bdt_sr();
  if (is_bdt_cr_branch != 0) is_bdt_cr();
  if (is_bdt_sr2_branch != 0) is_bdt_sr2();
  if (is_bdt_cr2_branch != 0) is_bdt_cr2();
  if (xsec_sf_branch != 0) xsec_sf();
  if (bdt_branch != 0) bdt();
  if (bdt_mbboff_branch != 0) bdt_mbboff();
}

const int &VBS::run() {
  if (not run_isLoaded) {
    if (run_branch != 0) {
      run_branch->GetEntry(index);
    } else {
      printf("branch run_branch does not exist!\n");
      exit(1);
    }
    run_isLoaded = true;
  }
  return run_;
}

const int &VBS::lumi() {
  if (not lumi_isLoaded) {
    if (lumi_branch != 0) {
      lumi_branch->GetEntry(index);
    } else {
      printf("branch lumi_branch does not exist!\n");
      exit(1);
    }
    lumi_isLoaded = true;
  }
  return lumi_;
}

const unsigned long long &VBS::evt() {
  if (not evt_isLoaded) {
    if (evt_branch != 0) {
      evt_branch->GetEntry(index);
    } else {
      printf("branch evt_branch does not exist!\n");
      exit(1);
    }
    evt_isLoaded = true;
  }
  return evt_;
}

const float &VBS::wgt() {
  if (not wgt_isLoaded) {
    if (wgt_branch != 0) {
      wgt_branch->GetEntry(index);
    } else {
      printf("branch wgt_branch does not exist!\n");
      exit(1);
    }
    wgt_isLoaded = true;
  }
  return wgt_;
}

const vector<float> &VBS::scalewgts() {
  if (not scalewgts_isLoaded) {
    if (scalewgts_branch != 0) {
      scalewgts_branch->GetEntry(index);
    } else {
      printf("branch scalewgts_branch does not exist!\n");
      exit(1);
    }
    scalewgts_isLoaded = true;
  }
  return *scalewgts_;
}

const vector<float> &VBS::pswgts() {
  if (not pswgts_isLoaded) {
    if (pswgts_branch != 0) {
      pswgts_branch->GetEntry(index);
    } else {
      printf("branch pswgts_branch does not exist!\n");
      exit(1);
    }
    pswgts_isLoaded = true;
  }
  return *pswgts_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &VBS::met_p4() {
  if (not met_p4_isLoaded) {
    if (met_p4_branch != 0) {
      met_p4_branch->GetEntry(index);
    } else {
      printf("branch met_p4_branch does not exist!\n");
      exit(1);
    }
    met_p4_isLoaded = true;
  }
  return *met_p4_;
}

const int &VBS::isvbswwh() {
  if (not isvbswwh_isLoaded) {
    if (isvbswwh_branch != 0) {
      isvbswwh_branch->GetEntry(index);
    } else {
      printf("branch isvbswwh_branch does not exist!\n");
      exit(1);
    }
    isvbswwh_isLoaded = true;
  }
  return isvbswwh_;
}

const int &VBS::iswwhlvlvbb() {
  if (not iswwhlvlvbb_isLoaded) {
    if (iswwhlvlvbb_branch != 0) {
      iswwhlvlvbb_branch->GetEntry(index);
    } else {
      printf("branch iswwhlvlvbb_branch does not exist!\n");
      exit(1);
    }
    iswwhlvlvbb_isLoaded = true;
  }
  return iswwhlvlvbb_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &VBS::gen_jet0() {
  if (not gen_jet0_isLoaded) {
    if (gen_jet0_branch != 0) {
      gen_jet0_branch->GetEntry(index);
    } else {
      printf("branch gen_jet0_branch does not exist!\n");
      exit(1);
    }
    gen_jet0_isLoaded = true;
  }
  return *gen_jet0_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &VBS::gen_jet1() {
  if (not gen_jet1_isLoaded) {
    if (gen_jet1_branch != 0) {
      gen_jet1_branch->GetEntry(index);
    } else {
      printf("branch gen_jet1_branch does not exist!\n");
      exit(1);
    }
    gen_jet1_isLoaded = true;
  }
  return *gen_jet1_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &VBS::gen_w0() {
  if (not gen_w0_isLoaded) {
    if (gen_w0_branch != 0) {
      gen_w0_branch->GetEntry(index);
    } else {
      printf("branch gen_w0_branch does not exist!\n");
      exit(1);
    }
    gen_w0_isLoaded = true;
  }
  return *gen_w0_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &VBS::gen_w1() {
  if (not gen_w1_isLoaded) {
    if (gen_w1_branch != 0) {
      gen_w1_branch->GetEntry(index);
    } else {
      printf("branch gen_w1_branch does not exist!\n");
      exit(1);
    }
    gen_w1_isLoaded = true;
  }
  return *gen_w1_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &VBS::gen_h() {
  if (not gen_h_isLoaded) {
    if (gen_h_branch != 0) {
      gen_h_branch->GetEntry(index);
    } else {
      printf("branch gen_h_branch does not exist!\n");
      exit(1);
    }
    gen_h_isLoaded = true;
  }
  return *gen_h_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &VBS::gen_lep0() {
  if (not gen_lep0_isLoaded) {
    if (gen_lep0_branch != 0) {
      gen_lep0_branch->GetEntry(index);
    } else {
      printf("branch gen_lep0_branch does not exist!\n");
      exit(1);
    }
    gen_lep0_isLoaded = true;
  }
  return *gen_lep0_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &VBS::gen_lep1() {
  if (not gen_lep1_isLoaded) {
    if (gen_lep1_branch != 0) {
      gen_lep1_branch->GetEntry(index);
    } else {
      printf("branch gen_lep1_branch does not exist!\n");
      exit(1);
    }
    gen_lep1_isLoaded = true;
  }
  return *gen_lep1_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &VBS::gen_lep2() {
  if (not gen_lep2_isLoaded) {
    if (gen_lep2_branch != 0) {
      gen_lep2_branch->GetEntry(index);
    } else {
      printf("branch gen_lep2_branch does not exist!\n");
      exit(1);
    }
    gen_lep2_isLoaded = true;
  }
  return *gen_lep2_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &VBS::gen_nu0() {
  if (not gen_nu0_isLoaded) {
    if (gen_nu0_branch != 0) {
      gen_nu0_branch->GetEntry(index);
    } else {
      printf("branch gen_nu0_branch does not exist!\n");
      exit(1);
    }
    gen_nu0_isLoaded = true;
  }
  return *gen_nu0_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &VBS::gen_nu1() {
  if (not gen_nu1_isLoaded) {
    if (gen_nu1_branch != 0) {
      gen_nu1_branch->GetEntry(index);
    } else {
      printf("branch gen_nu1_branch does not exist!\n");
      exit(1);
    }
    gen_nu1_isLoaded = true;
  }
  return *gen_nu1_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &VBS::gen_b0() {
  if (not gen_b0_isLoaded) {
    if (gen_b0_branch != 0) {
      gen_b0_branch->GetEntry(index);
    } else {
      printf("branch gen_b0_branch does not exist!\n");
      exit(1);
    }
    gen_b0_isLoaded = true;
  }
  return *gen_b0_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &VBS::gen_b1() {
  if (not gen_b1_isLoaded) {
    if (gen_b1_branch != 0) {
      gen_b1_branch->GetEntry(index);
    } else {
      printf("branch gen_b1_branch does not exist!\n");
      exit(1);
    }
    gen_b1_isLoaded = true;
  }
  return *gen_b1_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &VBS::gen_lepA() {
  if (not gen_lepA_isLoaded) {
    if (gen_lepA_branch != 0) {
      gen_lepA_branch->GetEntry(index);
    } else {
      printf("branch gen_lepA_branch does not exist!\n");
      exit(1);
    }
    gen_lepA_isLoaded = true;
  }
  return *gen_lepA_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &VBS::gen_nuA() {
  if (not gen_nuA_isLoaded) {
    if (gen_nuA_branch != 0) {
      gen_nuA_branch->GetEntry(index);
    } else {
      printf("branch gen_nuA_branch does not exist!\n");
      exit(1);
    }
    gen_nuA_isLoaded = true;
  }
  return *gen_nuA_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &VBS::gen_lepB() {
  if (not gen_lepB_isLoaded) {
    if (gen_lepB_branch != 0) {
      gen_lepB_branch->GetEntry(index);
    } else {
      printf("branch gen_lepB_branch does not exist!\n");
      exit(1);
    }
    gen_lepB_isLoaded = true;
  }
  return *gen_lepB_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &VBS::gen_nuB() {
  if (not gen_nuB_isLoaded) {
    if (gen_nuB_branch != 0) {
      gen_nuB_branch->GetEntry(index);
    } else {
      printf("branch gen_nuB_branch does not exist!\n");
      exit(1);
    }
    gen_nuB_isLoaded = true;
  }
  return *gen_nuB_;
}

const int &VBS::gen_sign() {
  if (not gen_sign_isLoaded) {
    if (gen_sign_branch != 0) {
      gen_sign_branch->GetEntry(index);
    } else {
      printf("branch gen_sign_branch does not exist!\n");
      exit(1);
    }
    gen_sign_isLoaded = true;
  }
  return gen_sign_;
}

const int &VBS::genchannel() {
  if (not genchannel_isLoaded) {
    if (genchannel_branch != 0) {
      genchannel_branch->GetEntry(index);
    } else {
      printf("branch genchannel_branch does not exist!\n");
      exit(1);
    }
    genchannel_isLoaded = true;
  }
  return genchannel_;
}

const float &VBS::genrewgt() {
  if (not genrewgt_isLoaded) {
    if (genrewgt_branch != 0) {
      genrewgt_branch->GetEntry(index);
    } else {
      printf("branch genrewgt_branch does not exist!\n");
      exit(1);
    }
    genrewgt_isLoaded = true;
  }
  return genrewgt_;
}

const float &VBS::gen_cosThetaStarA() {
  if (not gen_cosThetaStarA_isLoaded) {
    if (gen_cosThetaStarA_branch != 0) {
      gen_cosThetaStarA_branch->GetEntry(index);
    } else {
      printf("branch gen_cosThetaStarA_branch does not exist!\n");
      exit(1);
    }
    gen_cosThetaStarA_isLoaded = true;
  }
  return gen_cosThetaStarA_;
}

const float &VBS::gen_cosThetaStarB() {
  if (not gen_cosThetaStarB_isLoaded) {
    if (gen_cosThetaStarB_branch != 0) {
      gen_cosThetaStarB_branch->GetEntry(index);
    } else {
      printf("branch gen_cosThetaStarB_branch does not exist!\n");
      exit(1);
    }
    gen_cosThetaStarB_isLoaded = true;
  }
  return gen_cosThetaStarB_;
}

const float &VBS::lepsf() {
  if (not lepsf_isLoaded) {
    if (lepsf_branch != 0) {
      lepsf_branch->GetEntry(index);
    } else {
      printf("branch lepsf_branch does not exist!\n");
      exit(1);
    }
    lepsf_isLoaded = true;
  }
  return lepsf_;
}

const float &VBS::lepsf_up() {
  if (not lepsf_up_isLoaded) {
    if (lepsf_up_branch != 0) {
      lepsf_up_branch->GetEntry(index);
    } else {
      printf("branch lepsf_up_branch does not exist!\n");
      exit(1);
    }
    lepsf_up_isLoaded = true;
  }
  return lepsf_up_;
}

const float &VBS::lepsf_dn() {
  if (not lepsf_dn_isLoaded) {
    if (lepsf_dn_branch != 0) {
      lepsf_dn_branch->GetEntry(index);
    } else {
      printf("branch lepsf_dn_branch does not exist!\n");
      exit(1);
    }
    lepsf_dn_isLoaded = true;
  }
  return lepsf_dn_;
}

const float &VBS::btagsf() {
  if (not btagsf_isLoaded) {
    if (btagsf_branch != 0) {
      btagsf_branch->GetEntry(index);
    } else {
      printf("branch btagsf_branch does not exist!\n");
      exit(1);
    }
    btagsf_isLoaded = true;
  }
  return btagsf_;
}

const int &VBS::nbloose() {
  if (not nbloose_isLoaded) {
    if (nbloose_branch != 0) {
      nbloose_branch->GetEntry(index);
    } else {
      printf("branch nbloose_branch does not exist!\n");
      exit(1);
    }
    nbloose_isLoaded = true;
  }
  return nbloose_;
}

const int &VBS::nbmedium() {
  if (not nbmedium_isLoaded) {
    if (nbmedium_branch != 0) {
      nbmedium_branch->GetEntry(index);
    } else {
      printf("branch nbmedium_branch does not exist!\n");
      exit(1);
    }
    nbmedium_isLoaded = true;
  }
  return nbmedium_;
}

const int &VBS::nbtight() {
  if (not nbtight_isLoaded) {
    if (nbtight_branch != 0) {
      nbtight_branch->GetEntry(index);
    } else {
      printf("branch nbtight_branch does not exist!\n");
      exit(1);
    }
    nbtight_isLoaded = true;
  }
  return nbtight_;
}

const int &VBS::ncenjet30() {
  if (not ncenjet30_isLoaded) {
    if (ncenjet30_branch != 0) {
      ncenjet30_branch->GetEntry(index);
    } else {
      printf("branch ncenjet30_branch does not exist!\n");
      exit(1);
    }
    ncenjet30_isLoaded = true;
  }
  return ncenjet30_;
}

const int &VBS::njet30() {
  if (not njet30_isLoaded) {
    if (njet30_branch != 0) {
      njet30_branch->GetEntry(index);
    } else {
      printf("branch njet30_branch does not exist!\n");
      exit(1);
    }
    njet30_isLoaded = true;
  }
  return njet30_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &VBS::lep0() {
  if (not lep0_isLoaded) {
    if (lep0_branch != 0) {
      lep0_branch->GetEntry(index);
    } else {
      printf("branch lep0_branch does not exist!\n");
      exit(1);
    }
    lep0_isLoaded = true;
  }
  return *lep0_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &VBS::lep1() {
  if (not lep1_isLoaded) {
    if (lep1_branch != 0) {
      lep1_branch->GetEntry(index);
    } else {
      printf("branch lep1_branch does not exist!\n");
      exit(1);
    }
    lep1_isLoaded = true;
  }
  return *lep1_;
}

const int &VBS::lep0ID() {
  if (not lep0ID_isLoaded) {
    if (lep0ID_branch != 0) {
      lep0ID_branch->GetEntry(index);
    } else {
      printf("branch lep0ID_branch does not exist!\n");
      exit(1);
    }
    lep0ID_isLoaded = true;
  }
  return lep0ID_;
}

const int &VBS::lep1ID() {
  if (not lep1ID_isLoaded) {
    if (lep1ID_branch != 0) {
      lep1ID_branch->GetEntry(index);
    } else {
      printf("branch lep1ID_branch does not exist!\n");
      exit(1);
    }
    lep1ID_isLoaded = true;
  }
  return lep1ID_;
}

const int &VBS::lep0GenPartFlav() {
  if (not lep0GenPartFlav_isLoaded) {
    if (lep0GenPartFlav_branch != 0) {
      lep0GenPartFlav_branch->GetEntry(index);
    } else {
      printf("branch lep0GenPartFlav_branch does not exist!\n");
      exit(1);
    }
    lep0GenPartFlav_isLoaded = true;
  }
  return lep0GenPartFlav_;
}

const int &VBS::lep1GenPartFlav() {
  if (not lep1GenPartFlav_isLoaded) {
    if (lep1GenPartFlav_branch != 0) {
      lep1GenPartFlav_branch->GetEntry(index);
    } else {
      printf("branch lep1GenPartFlav_branch does not exist!\n");
      exit(1);
    }
    lep1GenPartFlav_isLoaded = true;
  }
  return lep1GenPartFlav_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &VBS::leadlep() {
  if (not leadlep_isLoaded) {
    if (leadlep_branch != 0) {
      leadlep_branch->GetEntry(index);
    } else {
      printf("branch leadlep_branch does not exist!\n");
      exit(1);
    }
    leadlep_isLoaded = true;
  }
  return *leadlep_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &VBS::subllep() {
  if (not subllep_isLoaded) {
    if (subllep_branch != 0) {
      subllep_branch->GetEntry(index);
    } else {
      printf("branch subllep_branch does not exist!\n");
      exit(1);
    }
    subllep_isLoaded = true;
  }
  return *subllep_;
}

const int &VBS::leadlepID() {
  if (not leadlepID_isLoaded) {
    if (leadlepID_branch != 0) {
      leadlepID_branch->GetEntry(index);
    } else {
      printf("branch leadlepID_branch does not exist!\n");
      exit(1);
    }
    leadlepID_isLoaded = true;
  }
  return leadlepID_;
}

const int &VBS::subllepID() {
  if (not subllepID_isLoaded) {
    if (subllepID_branch != 0) {
      subllepID_branch->GetEntry(index);
    } else {
      printf("branch subllepID_branch does not exist!\n");
      exit(1);
    }
    subllepID_isLoaded = true;
  }
  return subllepID_;
}

const int &VBS::leadlepGenPartFlav() {
  if (not leadlepGenPartFlav_isLoaded) {
    if (leadlepGenPartFlav_branch != 0) {
      leadlepGenPartFlav_branch->GetEntry(index);
    } else {
      printf("branch leadlepGenPartFlav_branch does not exist!\n");
      exit(1);
    }
    leadlepGenPartFlav_isLoaded = true;
  }
  return leadlepGenPartFlav_;
}

const int &VBS::subllepGenPartFlav() {
  if (not subllepGenPartFlav_isLoaded) {
    if (subllepGenPartFlav_branch != 0) {
      subllepGenPartFlav_branch->GetEntry(index);
    } else {
      printf("branch subllepGenPartFlav_branch does not exist!\n");
      exit(1);
    }
    subllepGenPartFlav_isLoaded = true;
  }
  return subllepGenPartFlav_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &VBS::b0() {
  if (not b0_isLoaded) {
    if (b0_branch != 0) {
      b0_branch->GetEntry(index);
    } else {
      printf("branch b0_branch does not exist!\n");
      exit(1);
    }
    b0_isLoaded = true;
  }
  return *b0_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &VBS::b1() {
  if (not b1_isLoaded) {
    if (b1_branch != 0) {
      b1_branch->GetEntry(index);
    } else {
      printf("branch b1_branch does not exist!\n");
      exit(1);
    }
    b1_isLoaded = true;
  }
  return *b1_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &VBS::j0() {
  if (not j0_isLoaded) {
    if (j0_branch != 0) {
      j0_branch->GetEntry(index);
    } else {
      printf("branch j0_branch does not exist!\n");
      exit(1);
    }
    j0_isLoaded = true;
  }
  return *j0_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &VBS::j1() {
  if (not j1_isLoaded) {
    if (j1_branch != 0) {
      j1_branch->GetEntry(index);
    } else {
      printf("branch j1_branch does not exist!\n");
      exit(1);
    }
    j1_isLoaded = true;
  }
  return *j1_;
}

const int &VBS::channel() {
  if (not channel_isLoaded) {
    if (channel_branch != 0) {
      channel_branch->GetEntry(index);
    } else {
      printf("branch channel_branch does not exist!\n");
      exit(1);
    }
    channel_isLoaded = true;
  }
  return channel_;
}

const int &VBS::channeldetail() {
  if (not channeldetail_isLoaded) {
    if (channeldetail_branch != 0) {
      channeldetail_branch->GetEntry(index);
    } else {
      printf("branch channeldetail_branch does not exist!\n");
      exit(1);
    }
    channeldetail_isLoaded = true;
  }
  return channeldetail_;
}

const int &VBS::lepchannel() {
  if (not lepchannel_isLoaded) {
    if (lepchannel_branch != 0) {
      lepchannel_branch->GetEntry(index);
    } else {
      printf("branch lepchannel_branch does not exist!\n");
      exit(1);
    }
    lepchannel_isLoaded = true;
  }
  return lepchannel_;
}

const int &VBS::btagchannel() {
  if (not btagchannel_isLoaded) {
    if (btagchannel_branch != 0) {
      btagchannel_branch->GetEntry(index);
    } else {
      printf("branch btagchannel_branch does not exist!\n");
      exit(1);
    }
    btagchannel_isLoaded = true;
  }
  return btagchannel_;
}

const int &VBS::bmatchcateg() {
  if (not bmatchcateg_isLoaded) {
    if (bmatchcateg_branch != 0) {
      bmatchcateg_branch->GetEntry(index);
    } else {
      printf("branch bmatchcateg_branch does not exist!\n");
      exit(1);
    }
    bmatchcateg_isLoaded = true;
  }
  return bmatchcateg_;
}

const int &VBS::mee_noZ() {
  if (not mee_noZ_isLoaded) {
    if (mee_noZ_branch != 0) {
      mee_noZ_branch->GetEntry(index);
    } else {
      printf("branch mee_noZ_branch does not exist!\n");
      exit(1);
    }
    mee_noZ_isLoaded = true;
  }
  return mee_noZ_;
}

const int &VBS::mbbIn() {
  if (not mbbIn_isLoaded) {
    if (mbbIn_branch != 0) {
      mbbIn_branch->GetEntry(index);
    } else {
      printf("branch mbbIn_branch does not exist!\n");
      exit(1);
    }
    mbbIn_isLoaded = true;
  }
  return mbbIn_;
}

const int &VBS::pass_blind() {
  if (not pass_blind_isLoaded) {
    if (pass_blind_branch != 0) {
      pass_blind_branch->GetEntry(index);
    } else {
      printf("branch pass_blind_branch does not exist!\n");
      exit(1);
    }
    pass_blind_isLoaded = true;
  }
  return pass_blind_;
}

const int &VBS::pass_blind_bdt() {
  if (not pass_blind_bdt_isLoaded) {
    if (pass_blind_bdt_branch != 0) {
      pass_blind_bdt_branch->GetEntry(index);
    } else {
      printf("branch pass_blind_bdt_branch does not exist!\n");
      exit(1);
    }
    pass_blind_bdt_isLoaded = true;
  }
  return pass_blind_bdt_;
}

const int &VBS::categ() {
  if (not categ_isLoaded) {
    if (categ_branch != 0) {
      categ_branch->GetEntry(index);
    } else {
      printf("branch categ_branch does not exist!\n");
      exit(1);
    }
    categ_isLoaded = true;
  }
  return categ_;
}

const float &VBS::categ_F() {
  if (not categ_F_isLoaded) {
    if (categ_F_branch != 0) {
      categ_F_branch->GetEntry(index);
    } else {
      printf("branch categ_F_branch does not exist!\n");
      exit(1);
    }
    categ_F_isLoaded = true;
  }
  return categ_F_;
}

const float &VBS::mbb() {
  if (not mbb_isLoaded) {
    if (mbb_branch != 0) {
      mbb_branch->GetEntry(index);
    } else {
      printf("branch mbb_branch does not exist!\n");
      exit(1);
    }
    mbb_isLoaded = true;
  }
  return mbb_;
}

const float &VBS::dphibb() {
  if (not dphibb_isLoaded) {
    if (dphibb_branch != 0) {
      dphibb_branch->GetEntry(index);
    } else {
      printf("branch dphibb_branch does not exist!\n");
      exit(1);
    }
    dphibb_isLoaded = true;
  }
  return dphibb_;
}

const float &VBS::detabb() {
  if (not detabb_isLoaded) {
    if (detabb_branch != 0) {
      detabb_branch->GetEntry(index);
    } else {
      printf("branch detabb_branch does not exist!\n");
      exit(1);
    }
    detabb_isLoaded = true;
  }
  return detabb_;
}

const float &VBS::drbb() {
  if (not drbb_isLoaded) {
    if (drbb_branch != 0) {
      drbb_branch->GetEntry(index);
    } else {
      printf("branch drbb_branch does not exist!\n");
      exit(1);
    }
    drbb_isLoaded = true;
  }
  return drbb_;
}

const float &VBS::ptbb() {
  if (not ptbb_isLoaded) {
    if (ptbb_branch != 0) {
      ptbb_branch->GetEntry(index);
    } else {
      printf("branch ptbb_branch does not exist!\n");
      exit(1);
    }
    ptbb_isLoaded = true;
  }
  return ptbb_;
}

const float &VBS::b0pt() {
  if (not b0pt_isLoaded) {
    if (b0pt_branch != 0) {
      b0pt_branch->GetEntry(index);
    } else {
      printf("branch b0pt_branch does not exist!\n");
      exit(1);
    }
    b0pt_isLoaded = true;
  }
  return b0pt_;
}

const float &VBS::b1pt() {
  if (not b1pt_isLoaded) {
    if (b1pt_branch != 0) {
      b1pt_branch->GetEntry(index);
    } else {
      printf("branch b1pt_branch does not exist!\n");
      exit(1);
    }
    b1pt_isLoaded = true;
  }
  return b1pt_;
}

const int &VBS::b0tight() {
  if (not b0tight_isLoaded) {
    if (b0tight_branch != 0) {
      b0tight_branch->GetEntry(index);
    } else {
      printf("branch b0tight_branch does not exist!\n");
      exit(1);
    }
    b0tight_isLoaded = true;
  }
  return b0tight_;
}

const int &VBS::b1tight() {
  if (not b1tight_isLoaded) {
    if (b1tight_branch != 0) {
      b1tight_branch->GetEntry(index);
    } else {
      printf("branch b1tight_branch does not exist!\n");
      exit(1);
    }
    b1tight_isLoaded = true;
  }
  return b1tight_;
}

const float &VBS::mjj() {
  if (not mjj_isLoaded) {
    if (mjj_branch != 0) {
      mjj_branch->GetEntry(index);
    } else {
      printf("branch mjj_branch does not exist!\n");
      exit(1);
    }
    mjj_isLoaded = true;
  }
  return mjj_;
}

const float &VBS::dphijj() {
  if (not dphijj_isLoaded) {
    if (dphijj_branch != 0) {
      dphijj_branch->GetEntry(index);
    } else {
      printf("branch dphijj_branch does not exist!\n");
      exit(1);
    }
    dphijj_isLoaded = true;
  }
  return dphijj_;
}

const float &VBS::detajj() {
  if (not detajj_isLoaded) {
    if (detajj_branch != 0) {
      detajj_branch->GetEntry(index);
    } else {
      printf("branch detajj_branch does not exist!\n");
      exit(1);
    }
    detajj_isLoaded = true;
  }
  return detajj_;
}

const float &VBS::drjj() {
  if (not drjj_isLoaded) {
    if (drjj_branch != 0) {
      drjj_branch->GetEntry(index);
    } else {
      printf("branch drjj_branch does not exist!\n");
      exit(1);
    }
    drjj_isLoaded = true;
  }
  return drjj_;
}

const float &VBS::ptjj() {
  if (not ptjj_isLoaded) {
    if (ptjj_branch != 0) {
      ptjj_branch->GetEntry(index);
    } else {
      printf("branch ptjj_branch does not exist!\n");
      exit(1);
    }
    ptjj_isLoaded = true;
  }
  return ptjj_;
}

const float &VBS::j0pt() {
  if (not j0pt_isLoaded) {
    if (j0pt_branch != 0) {
      j0pt_branch->GetEntry(index);
    } else {
      printf("branch j0pt_branch does not exist!\n");
      exit(1);
    }
    j0pt_isLoaded = true;
  }
  return j0pt_;
}

const float &VBS::j1pt() {
  if (not j1pt_isLoaded) {
    if (j1pt_branch != 0) {
      j1pt_branch->GetEntry(index);
    } else {
      printf("branch j1pt_branch does not exist!\n");
      exit(1);
    }
    j1pt_isLoaded = true;
  }
  return j1pt_;
}

const float &VBS::j_lead_p() {
  if (not j_lead_p_isLoaded) {
    if (j_lead_p_branch != 0) {
      j_lead_p_branch->GetEntry(index);
    } else {
      printf("branch j_lead_p_branch does not exist!\n");
      exit(1);
    }
    j_lead_p_isLoaded = true;
  }
  return j_lead_p_;
}

const float &VBS::j_sublead_p() {
  if (not j_sublead_p_isLoaded) {
    if (j_sublead_p_branch != 0) {
      j_sublead_p_branch->GetEntry(index);
    } else {
      printf("branch j_sublead_p_branch does not exist!\n");
      exit(1);
    }
    j_sublead_p_isLoaded = true;
  }
  return j_sublead_p_;
}

const float &VBS::mll() {
  if (not mll_isLoaded) {
    if (mll_branch != 0) {
      mll_branch->GetEntry(index);
    } else {
      printf("branch mll_branch does not exist!\n");
      exit(1);
    }
    mll_isLoaded = true;
  }
  return mll_;
}

const float &VBS::dphill() {
  if (not dphill_isLoaded) {
    if (dphill_branch != 0) {
      dphill_branch->GetEntry(index);
    } else {
      printf("branch dphill_branch does not exist!\n");
      exit(1);
    }
    dphill_isLoaded = true;
  }
  return dphill_;
}

const float &VBS::detall() {
  if (not detall_isLoaded) {
    if (detall_branch != 0) {
      detall_branch->GetEntry(index);
    } else {
      printf("branch detall_branch does not exist!\n");
      exit(1);
    }
    detall_isLoaded = true;
  }
  return detall_;
}

const float &VBS::drll() {
  if (not drll_isLoaded) {
    if (drll_branch != 0) {
      drll_branch->GetEntry(index);
    } else {
      printf("branch drll_branch does not exist!\n");
      exit(1);
    }
    drll_isLoaded = true;
  }
  return drll_;
}

const float &VBS::ptll() {
  if (not ptll_isLoaded) {
    if (ptll_branch != 0) {
      ptll_branch->GetEntry(index);
    } else {
      printf("branch ptll_branch does not exist!\n");
      exit(1);
    }
    ptll_isLoaded = true;
  }
  return ptll_;
}

const float &VBS::l0pt() {
  if (not l0pt_isLoaded) {
    if (l0pt_branch != 0) {
      l0pt_branch->GetEntry(index);
    } else {
      printf("branch l0pt_branch does not exist!\n");
      exit(1);
    }
    l0pt_isLoaded = true;
  }
  return l0pt_;
}

const float &VBS::l1pt() {
  if (not l1pt_isLoaded) {
    if (l1pt_branch != 0) {
      l1pt_branch->GetEntry(index);
    } else {
      printf("branch l1pt_branch does not exist!\n");
      exit(1);
    }
    l1pt_isLoaded = true;
  }
  return l1pt_;
}

const float &VBS::met() {
  if (not met_isLoaded) {
    if (met_branch != 0) {
      met_branch->GetEntry(index);
    } else {
      printf("branch met_branch does not exist!\n");
      exit(1);
    }
    met_isLoaded = true;
  }
  return met_;
}

const float &VBS::lt() {
  if (not lt_isLoaded) {
    if (lt_branch != 0) {
      lt_branch->GetEntry(index);
    } else {
      printf("branch lt_branch does not exist!\n");
      exit(1);
    }
    lt_isLoaded = true;
  }
  return lt_;
}

const float &VBS::st() {
  if (not st_isLoaded) {
    if (st_branch != 0) {
      st_branch->GetEntry(index);
    } else {
      printf("branch st_branch does not exist!\n");
      exit(1);
    }
    st_isLoaded = true;
  }
  return st_;
}

const float &VBS::mvvh() {
  if (not mvvh_isLoaded) {
    if (mvvh_branch != 0) {
      mvvh_branch->GetEntry(index);
    } else {
      printf("branch mvvh_branch does not exist!\n");
      exit(1);
    }
    mvvh_isLoaded = true;
  }
  return mvvh_;
}

const float &VBS::mtvvh() {
  if (not mtvvh_isLoaded) {
    if (mtvvh_branch != 0) {
      mtvvh_branch->GetEntry(index);
    } else {
      printf("branch mtvvh_branch does not exist!\n");
      exit(1);
    }
    mtvvh_isLoaded = true;
  }
  return mtvvh_;
}

const float &VBS::ptvvh() {
  if (not ptvvh_isLoaded) {
    if (ptvvh_branch != 0) {
      ptvvh_branch->GetEntry(index);
    } else {
      printf("branch ptvvh_branch does not exist!\n");
      exit(1);
    }
    ptvvh_isLoaded = true;
  }
  return ptvvh_;
}

const float &VBS::v0pt() {
  if (not v0pt_isLoaded) {
    if (v0pt_branch != 0) {
      v0pt_branch->GetEntry(index);
    } else {
      printf("branch v0pt_branch does not exist!\n");
      exit(1);
    }
    v0pt_isLoaded = true;
  }
  return v0pt_;
}

const float &VBS::v1pt() {
  if (not v1pt_isLoaded) {
    if (v1pt_branch != 0) {
      v1pt_branch->GetEntry(index);
    } else {
      printf("branch v1pt_branch does not exist!\n");
      exit(1);
    }
    v1pt_isLoaded = true;
  }
  return v1pt_;
}

const float &VBS::w0mass() {
  if (not w0mass_isLoaded) {
    if (w0mass_branch != 0) {
      w0mass_branch->GetEntry(index);
    } else {
      printf("branch w0mass_branch does not exist!\n");
      exit(1);
    }
    w0mass_isLoaded = true;
  }
  return w0mass_;
}

const float &VBS::w1mass() {
  if (not w1mass_isLoaded) {
    if (w1mass_branch != 0) {
      w1mass_branch->GetEntry(index);
    } else {
      printf("branch w1mass_branch does not exist!\n");
      exit(1);
    }
    w1mass_isLoaded = true;
  }
  return w1mass_;
}

const int &VBS::is_ttbar_madgraph() {
  if (not is_ttbar_madgraph_isLoaded) {
    if (is_ttbar_madgraph_branch != 0) {
      is_ttbar_madgraph_branch->GetEntry(index);
    } else {
      printf("branch is_ttbar_madgraph_branch does not exist!\n");
      exit(1);
    }
    is_ttbar_madgraph_isLoaded = true;
  }
  return is_ttbar_madgraph_;
}

const int &VBS::is_ttbar_powheg() {
  if (not is_ttbar_powheg_isLoaded) {
    if (is_ttbar_powheg_branch != 0) {
      is_ttbar_powheg_branch->GetEntry(index);
    } else {
      printf("branch is_ttbar_powheg_branch does not exist!\n");
      exit(1);
    }
    is_ttbar_powheg_isLoaded = true;
  }
  return is_ttbar_powheg_;
}

const int &VBS::is_train() {
  if (not is_train_isLoaded) {
    if (is_train_branch != 0) {
      is_train_branch->GetEntry(index);
    } else {
      printf("branch is_train_branch does not exist!\n");
      exit(1);
    }
    is_train_isLoaded = true;
  }
  return is_train_;
}

const int &VBS::is_test() {
  if (not is_test_isLoaded) {
    if (is_test_branch != 0) {
      is_test_branch->GetEntry(index);
    } else {
      printf("branch is_test_branch does not exist!\n");
      exit(1);
    }
    is_test_isLoaded = true;
  }
  return is_test_;
}

const int &VBS::is_signal() {
  if (not is_signal_isLoaded) {
    if (is_signal_branch != 0) {
      is_signal_branch->GetEntry(index);
    } else {
      printf("branch is_signal_branch does not exist!\n");
      exit(1);
    }
    is_signal_isLoaded = true;
  }
  return is_signal_;
}

const int &VBS::is_background() {
  if (not is_background_isLoaded) {
    if (is_background_branch != 0) {
      is_background_branch->GetEntry(index);
    } else {
      printf("branch is_background_branch does not exist!\n");
      exit(1);
    }
    is_background_isLoaded = true;
  }
  return is_background_;
}

const int &VBS::is_ps_el() {
  if (not is_ps_el_isLoaded) {
    if (is_ps_el_branch != 0) {
      is_ps_el_branch->GetEntry(index);
    } else {
      printf("branch is_ps_el_branch does not exist!\n");
      exit(1);
    }
    is_ps_el_isLoaded = true;
  }
  return is_ps_el_;
}

const int &VBS::is_ps_mu() {
  if (not is_ps_mu_isLoaded) {
    if (is_ps_mu_branch != 0) {
      is_ps_mu_branch->GetEntry(index);
    } else {
      printf("branch is_ps_mu_branch does not exist!\n");
      exit(1);
    }
    is_ps_mu_isLoaded = true;
  }
  return is_ps_mu_;
}

const int &VBS::is_ps_tau() {
  if (not is_ps_tau_isLoaded) {
    if (is_ps_tau_branch != 0) {
      is_ps_tau_branch->GetEntry(index);
    } else {
      printf("branch is_ps_tau_branch does not exist!\n");
      exit(1);
    }
    is_ps_tau_isLoaded = true;
  }
  return is_ps_tau_;
}

const int &VBS::is_ps_neg() {
  if (not is_ps_neg_isLoaded) {
    if (is_ps_neg_branch != 0) {
      is_ps_neg_branch->GetEntry(index);
    } else {
      printf("branch is_ps_neg_branch does not exist!\n");
      exit(1);
    }
    is_ps_neg_isLoaded = true;
  }
  return is_ps_neg_;
}

const int &VBS::is_ps_lgt() {
  if (not is_ps_lgt_isLoaded) {
    if (is_ps_lgt_branch != 0) {
      is_ps_lgt_branch->GetEntry(index);
    } else {
      printf("branch is_ps_lgt_branch does not exist!\n");
      exit(1);
    }
    is_ps_lgt_isLoaded = true;
  }
  return is_ps_lgt_;
}

const int &VBS::is_cut_sr_el() {
  if (not is_cut_sr_el_isLoaded) {
    if (is_cut_sr_el_branch != 0) {
      is_cut_sr_el_branch->GetEntry(index);
    } else {
      printf("branch is_cut_sr_el_branch does not exist!\n");
      exit(1);
    }
    is_cut_sr_el_isLoaded = true;
  }
  return is_cut_sr_el_;
}

const int &VBS::is_cut_sr_mu() {
  if (not is_cut_sr_mu_isLoaded) {
    if (is_cut_sr_mu_branch != 0) {
      is_cut_sr_mu_branch->GetEntry(index);
    } else {
      printf("branch is_cut_sr_mu_branch does not exist!\n");
      exit(1);
    }
    is_cut_sr_mu_isLoaded = true;
  }
  return is_cut_sr_mu_;
}

const int &VBS::is_cut_sr_tau() {
  if (not is_cut_sr_tau_isLoaded) {
    if (is_cut_sr_tau_branch != 0) {
      is_cut_sr_tau_branch->GetEntry(index);
    } else {
      printf("branch is_cut_sr_tau_branch does not exist!\n");
      exit(1);
    }
    is_cut_sr_tau_isLoaded = true;
  }
  return is_cut_sr_tau_;
}

const int &VBS::is_cut_sr_neg() {
  if (not is_cut_sr_neg_isLoaded) {
    if (is_cut_sr_neg_branch != 0) {
      is_cut_sr_neg_branch->GetEntry(index);
    } else {
      printf("branch is_cut_sr_neg_branch does not exist!\n");
      exit(1);
    }
    is_cut_sr_neg_isLoaded = true;
  }
  return is_cut_sr_neg_;
}

const int &VBS::is_cut_sr_lgt() {
  if (not is_cut_sr_lgt_isLoaded) {
    if (is_cut_sr_lgt_branch != 0) {
      is_cut_sr_lgt_branch->GetEntry(index);
    } else {
      printf("branch is_cut_sr_lgt_branch does not exist!\n");
      exit(1);
    }
    is_cut_sr_lgt_isLoaded = true;
  }
  return is_cut_sr_lgt_;
}

const int &VBS::is_cut_cr_el() {
  if (not is_cut_cr_el_isLoaded) {
    if (is_cut_cr_el_branch != 0) {
      is_cut_cr_el_branch->GetEntry(index);
    } else {
      printf("branch is_cut_cr_el_branch does not exist!\n");
      exit(1);
    }
    is_cut_cr_el_isLoaded = true;
  }
  return is_cut_cr_el_;
}

const int &VBS::is_cut_cr_mu() {
  if (not is_cut_cr_mu_isLoaded) {
    if (is_cut_cr_mu_branch != 0) {
      is_cut_cr_mu_branch->GetEntry(index);
    } else {
      printf("branch is_cut_cr_mu_branch does not exist!\n");
      exit(1);
    }
    is_cut_cr_mu_isLoaded = true;
  }
  return is_cut_cr_mu_;
}

const int &VBS::is_cut_cr_tau() {
  if (not is_cut_cr_tau_isLoaded) {
    if (is_cut_cr_tau_branch != 0) {
      is_cut_cr_tau_branch->GetEntry(index);
    } else {
      printf("branch is_cut_cr_tau_branch does not exist!\n");
      exit(1);
    }
    is_cut_cr_tau_isLoaded = true;
  }
  return is_cut_cr_tau_;
}

const int &VBS::is_cut_cr_neg() {
  if (not is_cut_cr_neg_isLoaded) {
    if (is_cut_cr_neg_branch != 0) {
      is_cut_cr_neg_branch->GetEntry(index);
    } else {
      printf("branch is_cut_cr_neg_branch does not exist!\n");
      exit(1);
    }
    is_cut_cr_neg_isLoaded = true;
  }
  return is_cut_cr_neg_;
}

const int &VBS::is_cut_cr_lgt() {
  if (not is_cut_cr_lgt_isLoaded) {
    if (is_cut_cr_lgt_branch != 0) {
      is_cut_cr_lgt_branch->GetEntry(index);
    } else {
      printf("branch is_cut_cr_lgt_branch does not exist!\n");
      exit(1);
    }
    is_cut_cr_lgt_isLoaded = true;
  }
  return is_cut_cr_lgt_;
}

const int &VBS::is_cut_sr2_el() {
  if (not is_cut_sr2_el_isLoaded) {
    if (is_cut_sr2_el_branch != 0) {
      is_cut_sr2_el_branch->GetEntry(index);
    } else {
      printf("branch is_cut_sr2_el_branch does not exist!\n");
      exit(1);
    }
    is_cut_sr2_el_isLoaded = true;
  }
  return is_cut_sr2_el_;
}

const int &VBS::is_cut_sr2_mu() {
  if (not is_cut_sr2_mu_isLoaded) {
    if (is_cut_sr2_mu_branch != 0) {
      is_cut_sr2_mu_branch->GetEntry(index);
    } else {
      printf("branch is_cut_sr2_mu_branch does not exist!\n");
      exit(1);
    }
    is_cut_sr2_mu_isLoaded = true;
  }
  return is_cut_sr2_mu_;
}

const int &VBS::is_cut_sr2_tau() {
  if (not is_cut_sr2_tau_isLoaded) {
    if (is_cut_sr2_tau_branch != 0) {
      is_cut_sr2_tau_branch->GetEntry(index);
    } else {
      printf("branch is_cut_sr2_tau_branch does not exist!\n");
      exit(1);
    }
    is_cut_sr2_tau_isLoaded = true;
  }
  return is_cut_sr2_tau_;
}

const int &VBS::is_cut_sr2_neg() {
  if (not is_cut_sr2_neg_isLoaded) {
    if (is_cut_sr2_neg_branch != 0) {
      is_cut_sr2_neg_branch->GetEntry(index);
    } else {
      printf("branch is_cut_sr2_neg_branch does not exist!\n");
      exit(1);
    }
    is_cut_sr2_neg_isLoaded = true;
  }
  return is_cut_sr2_neg_;
}

const int &VBS::is_cut_cr2_el() {
  if (not is_cut_cr2_el_isLoaded) {
    if (is_cut_cr2_el_branch != 0) {
      is_cut_cr2_el_branch->GetEntry(index);
    } else {
      printf("branch is_cut_cr2_el_branch does not exist!\n");
      exit(1);
    }
    is_cut_cr2_el_isLoaded = true;
  }
  return is_cut_cr2_el_;
}

const int &VBS::is_cut_cr2_mu() {
  if (not is_cut_cr2_mu_isLoaded) {
    if (is_cut_cr2_mu_branch != 0) {
      is_cut_cr2_mu_branch->GetEntry(index);
    } else {
      printf("branch is_cut_cr2_mu_branch does not exist!\n");
      exit(1);
    }
    is_cut_cr2_mu_isLoaded = true;
  }
  return is_cut_cr2_mu_;
}

const int &VBS::is_cut_cr2_tau() {
  if (not is_cut_cr2_tau_isLoaded) {
    if (is_cut_cr2_tau_branch != 0) {
      is_cut_cr2_tau_branch->GetEntry(index);
    } else {
      printf("branch is_cut_cr2_tau_branch does not exist!\n");
      exit(1);
    }
    is_cut_cr2_tau_isLoaded = true;
  }
  return is_cut_cr2_tau_;
}

const int &VBS::is_cut_cr2_neg() {
  if (not is_cut_cr2_neg_isLoaded) {
    if (is_cut_cr2_neg_branch != 0) {
      is_cut_cr2_neg_branch->GetEntry(index);
    } else {
      printf("branch is_cut_cr2_neg_branch does not exist!\n");
      exit(1);
    }
    is_cut_cr2_neg_isLoaded = true;
  }
  return is_cut_cr2_neg_;
}

const int &VBS::is_bdt_sr_el() {
  if (not is_bdt_sr_el_isLoaded) {
    if (is_bdt_sr_el_branch != 0) {
      is_bdt_sr_el_branch->GetEntry(index);
    } else {
      printf("branch is_bdt_sr_el_branch does not exist!\n");
      exit(1);
    }
    is_bdt_sr_el_isLoaded = true;
  }
  return is_bdt_sr_el_;
}

const int &VBS::is_bdt_sr_mu() {
  if (not is_bdt_sr_mu_isLoaded) {
    if (is_bdt_sr_mu_branch != 0) {
      is_bdt_sr_mu_branch->GetEntry(index);
    } else {
      printf("branch is_bdt_sr_mu_branch does not exist!\n");
      exit(1);
    }
    is_bdt_sr_mu_isLoaded = true;
  }
  return is_bdt_sr_mu_;
}

const int &VBS::is_bdt_sr_tau() {
  if (not is_bdt_sr_tau_isLoaded) {
    if (is_bdt_sr_tau_branch != 0) {
      is_bdt_sr_tau_branch->GetEntry(index);
    } else {
      printf("branch is_bdt_sr_tau_branch does not exist!\n");
      exit(1);
    }
    is_bdt_sr_tau_isLoaded = true;
  }
  return is_bdt_sr_tau_;
}

const int &VBS::is_bdt_sr_neg() {
  if (not is_bdt_sr_neg_isLoaded) {
    if (is_bdt_sr_neg_branch != 0) {
      is_bdt_sr_neg_branch->GetEntry(index);
    } else {
      printf("branch is_bdt_sr_neg_branch does not exist!\n");
      exit(1);
    }
    is_bdt_sr_neg_isLoaded = true;
  }
  return is_bdt_sr_neg_;
}

const int &VBS::is_bdt_cr_el() {
  if (not is_bdt_cr_el_isLoaded) {
    if (is_bdt_cr_el_branch != 0) {
      is_bdt_cr_el_branch->GetEntry(index);
    } else {
      printf("branch is_bdt_cr_el_branch does not exist!\n");
      exit(1);
    }
    is_bdt_cr_el_isLoaded = true;
  }
  return is_bdt_cr_el_;
}

const int &VBS::is_bdt_cr_mu() {
  if (not is_bdt_cr_mu_isLoaded) {
    if (is_bdt_cr_mu_branch != 0) {
      is_bdt_cr_mu_branch->GetEntry(index);
    } else {
      printf("branch is_bdt_cr_mu_branch does not exist!\n");
      exit(1);
    }
    is_bdt_cr_mu_isLoaded = true;
  }
  return is_bdt_cr_mu_;
}

const int &VBS::is_bdt_cr_tau() {
  if (not is_bdt_cr_tau_isLoaded) {
    if (is_bdt_cr_tau_branch != 0) {
      is_bdt_cr_tau_branch->GetEntry(index);
    } else {
      printf("branch is_bdt_cr_tau_branch does not exist!\n");
      exit(1);
    }
    is_bdt_cr_tau_isLoaded = true;
  }
  return is_bdt_cr_tau_;
}

const int &VBS::is_bdt_cr_neg() {
  if (not is_bdt_cr_neg_isLoaded) {
    if (is_bdt_cr_neg_branch != 0) {
      is_bdt_cr_neg_branch->GetEntry(index);
    } else {
      printf("branch is_bdt_cr_neg_branch does not exist!\n");
      exit(1);
    }
    is_bdt_cr_neg_isLoaded = true;
  }
  return is_bdt_cr_neg_;
}

const int &VBS::is_bdt_sr2_el() {
  if (not is_bdt_sr2_el_isLoaded) {
    if (is_bdt_sr2_el_branch != 0) {
      is_bdt_sr2_el_branch->GetEntry(index);
    } else {
      printf("branch is_bdt_sr2_el_branch does not exist!\n");
      exit(1);
    }
    is_bdt_sr2_el_isLoaded = true;
  }
  return is_bdt_sr2_el_;
}

const int &VBS::is_bdt_sr2_mu() {
  if (not is_bdt_sr2_mu_isLoaded) {
    if (is_bdt_sr2_mu_branch != 0) {
      is_bdt_sr2_mu_branch->GetEntry(index);
    } else {
      printf("branch is_bdt_sr2_mu_branch does not exist!\n");
      exit(1);
    }
    is_bdt_sr2_mu_isLoaded = true;
  }
  return is_bdt_sr2_mu_;
}

const int &VBS::is_bdt_sr2_tau() {
  if (not is_bdt_sr2_tau_isLoaded) {
    if (is_bdt_sr2_tau_branch != 0) {
      is_bdt_sr2_tau_branch->GetEntry(index);
    } else {
      printf("branch is_bdt_sr2_tau_branch does not exist!\n");
      exit(1);
    }
    is_bdt_sr2_tau_isLoaded = true;
  }
  return is_bdt_sr2_tau_;
}

const int &VBS::is_bdt_sr2_neg() {
  if (not is_bdt_sr2_neg_isLoaded) {
    if (is_bdt_sr2_neg_branch != 0) {
      is_bdt_sr2_neg_branch->GetEntry(index);
    } else {
      printf("branch is_bdt_sr2_neg_branch does not exist!\n");
      exit(1);
    }
    is_bdt_sr2_neg_isLoaded = true;
  }
  return is_bdt_sr2_neg_;
}

const int &VBS::is_bdt_cr2_el() {
  if (not is_bdt_cr2_el_isLoaded) {
    if (is_bdt_cr2_el_branch != 0) {
      is_bdt_cr2_el_branch->GetEntry(index);
    } else {
      printf("branch is_bdt_cr2_el_branch does not exist!\n");
      exit(1);
    }
    is_bdt_cr2_el_isLoaded = true;
  }
  return is_bdt_cr2_el_;
}

const int &VBS::is_bdt_cr2_mu() {
  if (not is_bdt_cr2_mu_isLoaded) {
    if (is_bdt_cr2_mu_branch != 0) {
      is_bdt_cr2_mu_branch->GetEntry(index);
    } else {
      printf("branch is_bdt_cr2_mu_branch does not exist!\n");
      exit(1);
    }
    is_bdt_cr2_mu_isLoaded = true;
  }
  return is_bdt_cr2_mu_;
}

const int &VBS::is_bdt_cr2_tau() {
  if (not is_bdt_cr2_tau_isLoaded) {
    if (is_bdt_cr2_tau_branch != 0) {
      is_bdt_cr2_tau_branch->GetEntry(index);
    } else {
      printf("branch is_bdt_cr2_tau_branch does not exist!\n");
      exit(1);
    }
    is_bdt_cr2_tau_isLoaded = true;
  }
  return is_bdt_cr2_tau_;
}

const int &VBS::is_bdt_cr2_neg() {
  if (not is_bdt_cr2_neg_isLoaded) {
    if (is_bdt_cr2_neg_branch != 0) {
      is_bdt_cr2_neg_branch->GetEntry(index);
    } else {
      printf("branch is_bdt_cr2_neg_branch does not exist!\n");
      exit(1);
    }
    is_bdt_cr2_neg_isLoaded = true;
  }
  return is_bdt_cr2_neg_;
}

const int &VBS::is_ps() {
  if (not is_ps_isLoaded) {
    if (is_ps_branch != 0) {
      is_ps_branch->GetEntry(index);
    } else {
      printf("branch is_ps_branch does not exist!\n");
      exit(1);
    }
    is_ps_isLoaded = true;
  }
  return is_ps_;
}

const int &VBS::is_cut_sr() {
  if (not is_cut_sr_isLoaded) {
    if (is_cut_sr_branch != 0) {
      is_cut_sr_branch->GetEntry(index);
    } else {
      printf("branch is_cut_sr_branch does not exist!\n");
      exit(1);
    }
    is_cut_sr_isLoaded = true;
  }
  return is_cut_sr_;
}

const int &VBS::is_cut_cr() {
  if (not is_cut_cr_isLoaded) {
    if (is_cut_cr_branch != 0) {
      is_cut_cr_branch->GetEntry(index);
    } else {
      printf("branch is_cut_cr_branch does not exist!\n");
      exit(1);
    }
    is_cut_cr_isLoaded = true;
  }
  return is_cut_cr_;
}

const int &VBS::is_cut_sr2() {
  if (not is_cut_sr2_isLoaded) {
    if (is_cut_sr2_branch != 0) {
      is_cut_sr2_branch->GetEntry(index);
    } else {
      printf("branch is_cut_sr2_branch does not exist!\n");
      exit(1);
    }
    is_cut_sr2_isLoaded = true;
  }
  return is_cut_sr2_;
}

const int &VBS::is_cut_cr2() {
  if (not is_cut_cr2_isLoaded) {
    if (is_cut_cr2_branch != 0) {
      is_cut_cr2_branch->GetEntry(index);
    } else {
      printf("branch is_cut_cr2_branch does not exist!\n");
      exit(1);
    }
    is_cut_cr2_isLoaded = true;
  }
  return is_cut_cr2_;
}

const int &VBS::is_bdt_sr() {
  if (not is_bdt_sr_isLoaded) {
    if (is_bdt_sr_branch != 0) {
      is_bdt_sr_branch->GetEntry(index);
    } else {
      printf("branch is_bdt_sr_branch does not exist!\n");
      exit(1);
    }
    is_bdt_sr_isLoaded = true;
  }
  return is_bdt_sr_;
}

const int &VBS::is_bdt_cr() {
  if (not is_bdt_cr_isLoaded) {
    if (is_bdt_cr_branch != 0) {
      is_bdt_cr_branch->GetEntry(index);
    } else {
      printf("branch is_bdt_cr_branch does not exist!\n");
      exit(1);
    }
    is_bdt_cr_isLoaded = true;
  }
  return is_bdt_cr_;
}

const int &VBS::is_bdt_sr2() {
  if (not is_bdt_sr2_isLoaded) {
    if (is_bdt_sr2_branch != 0) {
      is_bdt_sr2_branch->GetEntry(index);
    } else {
      printf("branch is_bdt_sr2_branch does not exist!\n");
      exit(1);
    }
    is_bdt_sr2_isLoaded = true;
  }
  return is_bdt_sr2_;
}

const int &VBS::is_bdt_cr2() {
  if (not is_bdt_cr2_isLoaded) {
    if (is_bdt_cr2_branch != 0) {
      is_bdt_cr2_branch->GetEntry(index);
    } else {
      printf("branch is_bdt_cr2_branch does not exist!\n");
      exit(1);
    }
    is_bdt_cr2_isLoaded = true;
  }
  return is_bdt_cr2_;
}

const float &VBS::xsec_sf() {
  if (not xsec_sf_isLoaded) {
    if (xsec_sf_branch != 0) {
      xsec_sf_branch->GetEntry(index);
    } else {
      printf("branch xsec_sf_branch does not exist!\n");
      exit(1);
    }
    xsec_sf_isLoaded = true;
  }
  return xsec_sf_;
}

const float &VBS::bdt() {
  if (not bdt_isLoaded) {
    if (bdt_branch != 0) {
      bdt_branch->GetEntry(index);
    } else {
      printf("branch bdt_branch does not exist!\n");
      exit(1);
    }
    bdt_isLoaded = true;
  }
  return bdt_;
}

const float &VBS::bdt_mbboff() {
  if (not bdt_mbboff_isLoaded) {
    if (bdt_mbboff_branch != 0) {
      bdt_mbboff_branch->GetEntry(index);
    } else {
      printf("branch bdt_mbboff_branch does not exist!\n");
      exit(1);
    }
    bdt_mbboff_isLoaded = true;
  }
  return bdt_mbboff_;
}


void VBS::progress( int nEventsTotal, int nEventsChain ){
  int period = 1000;
  if (nEventsTotal%1000 == 0) {
    // xterm magic from L. Vacavant and A. Cerri
    if (isatty(1)) {
      if ((nEventsChain - nEventsTotal) > period) {
        float frac = (float)nEventsTotal/(nEventsChain*0.01);
        printf("\015\033[32m ---> \033[1m\033[31m%4.1f%%"
             "\033[0m\033[32m <---\033[0m\015", frac);
        fflush(stdout);
      }
      else {
        printf("\015\033[32m ---> \033[1m\033[31m%4.1f%%"
               "\033[0m\033[32m <---\033[0m\015", 100.);
        cout << endl;
      }
    }
  }
}

namespace tas {

const int &run() { return vbs.run(); }
const int &lumi() { return vbs.lumi(); }
const unsigned long long &evt() { return vbs.evt(); }
const float &wgt() { return vbs.wgt(); }
const vector<float> &scalewgts() { return vbs.scalewgts(); }
const vector<float> &pswgts() { return vbs.pswgts(); }
const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &met_p4() { return vbs.met_p4(); }
const int &isvbswwh() { return vbs.isvbswwh(); }
const int &iswwhlvlvbb() { return vbs.iswwhlvlvbb(); }
const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &gen_jet0() { return vbs.gen_jet0(); }
const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &gen_jet1() { return vbs.gen_jet1(); }
const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &gen_w0() { return vbs.gen_w0(); }
const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &gen_w1() { return vbs.gen_w1(); }
const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &gen_h() { return vbs.gen_h(); }
const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &gen_lep0() { return vbs.gen_lep0(); }
const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &gen_lep1() { return vbs.gen_lep1(); }
const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &gen_lep2() { return vbs.gen_lep2(); }
const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &gen_nu0() { return vbs.gen_nu0(); }
const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &gen_nu1() { return vbs.gen_nu1(); }
const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &gen_b0() { return vbs.gen_b0(); }
const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &gen_b1() { return vbs.gen_b1(); }
const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &gen_lepA() { return vbs.gen_lepA(); }
const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &gen_nuA() { return vbs.gen_nuA(); }
const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &gen_lepB() { return vbs.gen_lepB(); }
const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &gen_nuB() { return vbs.gen_nuB(); }
const int &gen_sign() { return vbs.gen_sign(); }
const int &genchannel() { return vbs.genchannel(); }
const float &genrewgt() { return vbs.genrewgt(); }
const float &gen_cosThetaStarA() { return vbs.gen_cosThetaStarA(); }
const float &gen_cosThetaStarB() { return vbs.gen_cosThetaStarB(); }
const float &lepsf() { return vbs.lepsf(); }
const float &lepsf_up() { return vbs.lepsf_up(); }
const float &lepsf_dn() { return vbs.lepsf_dn(); }
const float &btagsf() { return vbs.btagsf(); }
const int &nbloose() { return vbs.nbloose(); }
const int &nbmedium() { return vbs.nbmedium(); }
const int &nbtight() { return vbs.nbtight(); }
const int &ncenjet30() { return vbs.ncenjet30(); }
const int &njet30() { return vbs.njet30(); }
const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &lep0() { return vbs.lep0(); }
const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &lep1() { return vbs.lep1(); }
const int &lep0ID() { return vbs.lep0ID(); }
const int &lep1ID() { return vbs.lep1ID(); }
const int &lep0GenPartFlav() { return vbs.lep0GenPartFlav(); }
const int &lep1GenPartFlav() { return vbs.lep1GenPartFlav(); }
const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &leadlep() { return vbs.leadlep(); }
const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &subllep() { return vbs.subllep(); }
const int &leadlepID() { return vbs.leadlepID(); }
const int &subllepID() { return vbs.subllepID(); }
const int &leadlepGenPartFlav() { return vbs.leadlepGenPartFlav(); }
const int &subllepGenPartFlav() { return vbs.subllepGenPartFlav(); }
const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &b0() { return vbs.b0(); }
const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &b1() { return vbs.b1(); }
const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &j0() { return vbs.j0(); }
const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &j1() { return vbs.j1(); }
const int &channel() { return vbs.channel(); }
const int &channeldetail() { return vbs.channeldetail(); }
const int &lepchannel() { return vbs.lepchannel(); }
const int &btagchannel() { return vbs.btagchannel(); }
const int &bmatchcateg() { return vbs.bmatchcateg(); }
const int &mee_noZ() { return vbs.mee_noZ(); }
const int &mbbIn() { return vbs.mbbIn(); }
const int &pass_blind() { return vbs.pass_blind(); }
const int &pass_blind_bdt() { return vbs.pass_blind_bdt(); }
const int &categ() { return vbs.categ(); }
const float &categ_F() { return vbs.categ_F(); }
const float &mbb() { return vbs.mbb(); }
const float &dphibb() { return vbs.dphibb(); }
const float &detabb() { return vbs.detabb(); }
const float &drbb() { return vbs.drbb(); }
const float &ptbb() { return vbs.ptbb(); }
const float &b0pt() { return vbs.b0pt(); }
const float &b1pt() { return vbs.b1pt(); }
const int &b0tight() { return vbs.b0tight(); }
const int &b1tight() { return vbs.b1tight(); }
const float &mjj() { return vbs.mjj(); }
const float &dphijj() { return vbs.dphijj(); }
const float &detajj() { return vbs.detajj(); }
const float &drjj() { return vbs.drjj(); }
const float &ptjj() { return vbs.ptjj(); }
const float &j0pt() { return vbs.j0pt(); }
const float &j1pt() { return vbs.j1pt(); }
const float &j_lead_p() { return vbs.j_lead_p(); }
const float &j_sublead_p() { return vbs.j_sublead_p(); }
const float &mll() { return vbs.mll(); }
const float &dphill() { return vbs.dphill(); }
const float &detall() { return vbs.detall(); }
const float &drll() { return vbs.drll(); }
const float &ptll() { return vbs.ptll(); }
const float &l0pt() { return vbs.l0pt(); }
const float &l1pt() { return vbs.l1pt(); }
const float &met() { return vbs.met(); }
const float &lt() { return vbs.lt(); }
const float &st() { return vbs.st(); }
const float &mvvh() { return vbs.mvvh(); }
const float &mtvvh() { return vbs.mtvvh(); }
const float &ptvvh() { return vbs.ptvvh(); }
const float &v0pt() { return vbs.v0pt(); }
const float &v1pt() { return vbs.v1pt(); }
const float &w0mass() { return vbs.w0mass(); }
const float &w1mass() { return vbs.w1mass(); }
const int &is_ttbar_madgraph() { return vbs.is_ttbar_madgraph(); }
const int &is_ttbar_powheg() { return vbs.is_ttbar_powheg(); }
const int &is_train() { return vbs.is_train(); }
const int &is_test() { return vbs.is_test(); }
const int &is_signal() { return vbs.is_signal(); }
const int &is_background() { return vbs.is_background(); }
const int &is_ps_el() { return vbs.is_ps_el(); }
const int &is_ps_mu() { return vbs.is_ps_mu(); }
const int &is_ps_tau() { return vbs.is_ps_tau(); }
const int &is_ps_neg() { return vbs.is_ps_neg(); }
const int &is_ps_lgt() { return vbs.is_ps_lgt(); }
const int &is_cut_sr_el() { return vbs.is_cut_sr_el(); }
const int &is_cut_sr_mu() { return vbs.is_cut_sr_mu(); }
const int &is_cut_sr_tau() { return vbs.is_cut_sr_tau(); }
const int &is_cut_sr_neg() { return vbs.is_cut_sr_neg(); }
const int &is_cut_sr_lgt() { return vbs.is_cut_sr_lgt(); }
const int &is_cut_cr_el() { return vbs.is_cut_cr_el(); }
const int &is_cut_cr_mu() { return vbs.is_cut_cr_mu(); }
const int &is_cut_cr_tau() { return vbs.is_cut_cr_tau(); }
const int &is_cut_cr_neg() { return vbs.is_cut_cr_neg(); }
const int &is_cut_cr_lgt() { return vbs.is_cut_cr_lgt(); }
const int &is_cut_sr2_el() { return vbs.is_cut_sr2_el(); }
const int &is_cut_sr2_mu() { return vbs.is_cut_sr2_mu(); }
const int &is_cut_sr2_tau() { return vbs.is_cut_sr2_tau(); }
const int &is_cut_sr2_neg() { return vbs.is_cut_sr2_neg(); }
const int &is_cut_cr2_el() { return vbs.is_cut_cr2_el(); }
const int &is_cut_cr2_mu() { return vbs.is_cut_cr2_mu(); }
const int &is_cut_cr2_tau() { return vbs.is_cut_cr2_tau(); }
const int &is_cut_cr2_neg() { return vbs.is_cut_cr2_neg(); }
const int &is_bdt_sr_el() { return vbs.is_bdt_sr_el(); }
const int &is_bdt_sr_mu() { return vbs.is_bdt_sr_mu(); }
const int &is_bdt_sr_tau() { return vbs.is_bdt_sr_tau(); }
const int &is_bdt_sr_neg() { return vbs.is_bdt_sr_neg(); }
const int &is_bdt_cr_el() { return vbs.is_bdt_cr_el(); }
const int &is_bdt_cr_mu() { return vbs.is_bdt_cr_mu(); }
const int &is_bdt_cr_tau() { return vbs.is_bdt_cr_tau(); }
const int &is_bdt_cr_neg() { return vbs.is_bdt_cr_neg(); }
const int &is_bdt_sr2_el() { return vbs.is_bdt_sr2_el(); }
const int &is_bdt_sr2_mu() { return vbs.is_bdt_sr2_mu(); }
const int &is_bdt_sr2_tau() { return vbs.is_bdt_sr2_tau(); }
const int &is_bdt_sr2_neg() { return vbs.is_bdt_sr2_neg(); }
const int &is_bdt_cr2_el() { return vbs.is_bdt_cr2_el(); }
const int &is_bdt_cr2_mu() { return vbs.is_bdt_cr2_mu(); }
const int &is_bdt_cr2_tau() { return vbs.is_bdt_cr2_tau(); }
const int &is_bdt_cr2_neg() { return vbs.is_bdt_cr2_neg(); }
const int &is_ps() { return vbs.is_ps(); }
const int &is_cut_sr() { return vbs.is_cut_sr(); }
const int &is_cut_cr() { return vbs.is_cut_cr(); }
const int &is_cut_sr2() { return vbs.is_cut_sr2(); }
const int &is_cut_cr2() { return vbs.is_cut_cr2(); }
const int &is_bdt_sr() { return vbs.is_bdt_sr(); }
const int &is_bdt_cr() { return vbs.is_bdt_cr(); }
const int &is_bdt_sr2() { return vbs.is_bdt_sr2(); }
const int &is_bdt_cr2() { return vbs.is_bdt_cr2(); }
const float &xsec_sf() { return vbs.xsec_sf(); }
const float &bdt() { return vbs.bdt(); }
const float &bdt_mbboff() { return vbs.bdt_mbboff(); }

}

#include "rooutil.cc"
