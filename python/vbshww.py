#!/bin/env python

import sys
import os
import ROOT
import glob
import subprocess
from pprint import pprint

def get_groups():
    return ["data", "bosons", "ttw", "ttz", "tt1lpowheg", "tt2lpowheg", "raretop", "vbshwwc2v", "vbshwwcv", "vbshwwc3", "vbshwwsm"]

def get_years():
    return ["Run2", "2016APV", "2016", "2017", "2018"]

def get_xsec(**kwargs):
    samplename = kwargs.get("samplename")
    xsec = -999
    if "WW"                        in samplename: xsec = 118.71
    if "WZ"                        in samplename: xsec = 47.13 # from WWW hadronic B2G https://cms.cern.ch/iCMS/jsp/db_notes/noteInfo.jsp?cmsnoteid=CMS%20AN-2019/198
    if "ZZ"                        in samplename: xsec = 10.32
    if "tZq_ll_4f_ckm_NLO"         in samplename: xsec = 0.0758
    if "ST_s-channel_4f"           in samplename: xsec = 3.74
    if "ST_t-channel_antitop_4f"   in samplename: xsec = 80.95
    if "ST_t-channel_top_4f"       in samplename: xsec = 136.02
    if "ST_tW_antitop_5f"          in samplename: xsec = 19.559
    if "ST_tW_top_5f"              in samplename: xsec = 19.559
    if "ST_tWll_5f_LO"             in samplename: xsec = 0.01123
    if "TWZToLL_tlept_Whad_5f_DR"  in samplename: xsec = 0.003004
    if "TWZToLL_thad_Wlept_5f_DR"  in samplename: xsec = 0.003004
    if "ZZTo4L"                    in samplename: xsec = 1.256
    if "ZGToLLG"                   in samplename: xsec = 59.21
    if "WGToLNuG"                  in samplename: xsec = 585.8
    if "VHToNonbb"                 in samplename: xsec = 0.9561
    if "GluGluHToZZTo4L"           in samplename: xsec = 0.0082323
    if "DYJetsToLL_M-10to50"       in samplename: xsec = 20657.0
    if "DYJetsToLL_M-50"           in samplename: xsec = 6198.0
    if "WJetsToLNu"                in samplename: xsec = 61335.0
    if "TTWJetsToLNu"              in samplename: xsec = 0.2043
    if "TTZToLLNuNu_M-10"          in samplename: xsec = 0.2529
    if "TTZToLL_M-1to10"           in samplename: xsec = 0.0493
    if "TTJets_DiLept"             in samplename: xsec = 91.044
    if "TTJets_SingleLeptFromT"    in samplename: xsec = 182.96
    if "TTJets_SingleLeptFromTbar" in samplename: xsec = 182.96
    if "TTTo2L2Nu"                 in samplename: xsec = 87.315
    if "TTToSemiLeptonic"          in samplename: xsec = 365.34
    if "WpWpJJ_EWK"                in samplename: xsec = 0.0539
    if "SSWW"                      in samplename: xsec = 0.02794
    if "WZTo3LNu"                  in samplename: xsec = 4.6660 # 4.4297 is what we had before 4.6660 https://cms.cern.ch/iCMS/jsp/db_notes/noteInfo.jsp?cmsnoteid=CMS%20AN-2019/156
    if "VBSWWHToLNuLNubb_C2V"      in samplename: xsec = 0.0009246749816
    if "VBSWWHToLNuLNubb_SM"       in samplename: xsec = 0.0009246749816 # Same as above because it is actually C2V sample with a symlink to the directory
    if "VBSWWHToLNuLNubb_CV"       in samplename: xsec = 0.0009246749816 # Same as above because default was generated with C2V being set then being reweighted later
    if "VBSWWHToLNuLNubb_C3"       in samplename: xsec = 0.001364877636
    if "ttHJetTobb"                in samplename: xsec = 0.1279
    if "ttHJetToNonbb"             in samplename: xsec = 0.215
    if "TTTT"                      in samplename: xsec = 0.009103
    if "TTWW"                      in samplename: xsec = 0.0115
    if "TTWZ"                      in samplename: xsec = 0.003884
    if "TTZZ"                      in samplename: xsec = 0.001982
    if "TTWH"                      in samplename: xsec = 0.001582
    if "TTZH"                      in samplename: xsec = 0.001535
    if "WWW_4F"                    in samplename: xsec = 0.2086
    if "WWZ"                       in samplename: xsec = 0.1651
    if "WZG"                       in samplename: xsec = 0.04123
    if "WZZ"                       in samplename: xsec = 0.05565
    if "ZZZ"                       in samplename: xsec = 0.01398
    if "WWToLNuQQ"                 in samplename: xsec = 49.997
    if "WWTo2L2Nu"                 in samplename: xsec = 12.178
    if "Run201"                    in samplename: xsec = 0
    if xsec < 0:
        print("ERROR! Did not find xsec for {}".format(samplename))
        sys.exit(-1)
    else:
        return xsec

def get_group(**kwargs):
    samplename = kwargs.get("samplename")
    group = "none"
    if "WW"                        in samplename: group = "bosons"
    if "WZ"                        in samplename: group = "bosons"
    if "ZZ"                        in samplename: group = "bosons"
    if "tZq_ll_4f_ckm_NLO"         in samplename: group = "raretop"
    if "ST_s-channel_4f"           in samplename: group = "raretop"
    if "ST_t-channel_antitop_4f"   in samplename: group = "raretop"
    if "ST_t-channel_top_4f"       in samplename: group = "raretop"
    if "ST_tW_antitop_5f"          in samplename: group = "raretop"
    if "ST_tW_top_5f"              in samplename: group = "raretop"
    if "ST_tWll_5f_LO"             in samplename: group = "raretop"
    if "TWZToLL_tlept_Whad_5f_DR"  in samplename: group = "raretop"
    if "TWZToLL_thad_Wlept_5f_DR"  in samplename: group = "raretop"
    if "ZZTo4L"                    in samplename: group = "bosons"
    if "ZGToLLG"                   in samplename: group = "bosons"
    if "WGToLNuG"                  in samplename: group = "bosons"
    if "VHToNonbb"                 in samplename: group = "bosons"
    if "GluGluHToZZTo4L"           in samplename: group = "bosons"
    if "DYJetsToLL_M-10to50"       in samplename: group = "bosons"
    if "DYJetsToLL_M-50"           in samplename: group = "bosons"
    if "WJetsToLNu"                in samplename: group = "bosons"
    if "TTWJetsToLNu"              in samplename: group = "ttw"
    if "TTZToLLNuNu_M-10"          in samplename: group = "ttz"
    if "TTZToLL_M-1to10"           in samplename: group = "ttz"
    if "TTJets_DiLept"             in samplename: group = "tt2l"
    if "TTJets_SingleLeptFromT"    in samplename: group = "tt1l"
    if "TTJets_SingleLeptFromTbar" in samplename: group = "tt1l"
    if "TTTo2L2Nu"                 in samplename: group = "tt2lpowheg"
    if "TTToSemiLeptonic"          in samplename: group = "tt1lpowheg"
    if "WpWpJJ_EWK"                in samplename: group = "bosons"
    if "SSWW"                      in samplename: group = "bosons"
    if "WZTo3LNu"                  in samplename: group = "bosons"
    if "VBSWWHToLNuLNubb_C2V"      in samplename: group = "vbshwwc2v"
    if "VBSWWHToLNuLNubb_SM"       in samplename: group = "vbshwwsm" 
    if "VBSWWHToLNuLNubb_CV"       in samplename: group = "vbshwwcv"
    if "VBSWWHToLNuLNubb_C3"       in samplename: group = "vbshwwc3"
    if "ttHJetTobb"                in samplename: group = "raretop"
    if "ttHJetToNonbb"             in samplename: group = "raretop"
    if "TTTT"                      in samplename: group = "raretop"
    if "TTWW"                      in samplename: group = "raretop"
    if "TTWZ"                      in samplename: group = "raretop"
    if "TTZZ"                      in samplename: group = "raretop"
    if "TTWH"                      in samplename: group = "raretop"
    if "TTZH"                      in samplename: group = "raretop"
    if "WWW_4F"                    in samplename: group = "bosons"
    if "WWZ"                       in samplename: group = "bosons"
    if "WZG"                       in samplename: group = "bosons"
    if "WZZ"                       in samplename: group = "bosons"
    if "ZZZ"                       in samplename: group = "bosons"
    if "WWToLNuQQ"                 in samplename: group = "bosons"
    if "WWTo2L2Nu"                 in samplename: group = "bosons"
    if "Run201"                    in samplename: group = "data"
    if group == "none":
        print("ERROR! Did not find group for {}".format(samplename))
        sys.exit(-1)
    else:
        return group

def get_lumi(**kwargs):
    year = kwargs.get("year")
    if year == "2018": return 59.83
    elif year == "2017": return 41.48
    elif year == "2016": return 16.81
    elif year == "2016APV": return 19.52
    else:
        print("ERROR! did not recognize year to parse for lumi! year={year}".format(year=year))
        sys.exit(-1)

def get_samplenames(**kwargs):
    year = kwargs.get("year")
    isdata = kwargs.get("isdata")
    issignal = kwargs.get("issignal")
    sample_list = []
    if year == "2018":
        if isdata:
            sample_list = [
                    "DoubleMuon_Run2018A-UL2018",
                    "DoubleMuon_Run2018B-UL2018",
                    "DoubleMuon_Run2018C-UL2018",
                    "DoubleMuon_Run2018D-UL2018",
                    "EGamma_Run2018A-UL2018",
                    "EGamma_Run2018B-UL2018",
                    "EGamma_Run2018C-UL2018",
                    "EGamma_Run2018D-UL2018",
                    "MuonEG_Run2018A-UL2018",
                    "MuonEG_Run2018B-UL2018",
                    "MuonEG_Run2018C-UL2018",
                    "MuonEG_Run2018D-UL2018",
                    "SingleMuon_Run2018A-UL2018",
                    "SingleMuon_Run2018B-UL2018",
                    "SingleMuon_Run2018C-UL2018",
                    "SingleMuon_Run2018D-UL2018",
                    ]
        elif issignal:
            sample_list = [
                    "VBSWWHToLNuLNubb_C2V",
                    "VBSWWHToLNuLNubb_SM",
                    "VBSWWHToLNuLNubb_C3",
                    "VBSWWHToLNuLNubb_CV",
                    ]
        else:
            sample_list = [
                    "DYJetsToLL_M-10to50",
                    "DYJetsToLL_M-50",
                    "SSWW",
                    "WJetsToLNu",
                    "WW",
                    "WZTo3LNu_mllmin01_NNPDF31",
                    "ZZTo4L",
                    "TTTo2L2Nu",
                    "TTToSemiLeptonic",
                    "TTWJetsToLNu",
                    "TTZToLLNuNu_M-10",
                    "TWZToLL_thad_Wlept_5f_DR",
                    "TWZToLL_tlept_Whad_5f_DR",
                    "ttHJetToNonbb_M125",
                    "ttHJetTobb_M125",
                    "ST_s-channel_4f_leptonDecays",
                    "ST_t-channel_antitop_4f_InclusiveDecays",
                    "ST_t-channel_top_4f_InclusiveDecays",
                    "ST_tW_antitop_5f_NoFullyHadronicDecays",
                    "ST_tW_top_5f_NoFullyHadronicDecays",
                    "TTWW",
                    "TTWZ",
                    ]
    elif year == "2017":
        if isdata:
            sample_list = [
                    "DoubleEG_Run2017B-UL2017",
                    "DoubleEG_Run2017C-UL2017",
                    "DoubleEG_Run2017D-UL2017",
                    "DoubleEG_Run2017E-UL2017",
                    "DoubleEG_Run2017F-UL2017",
                    "DoubleMuon_Run2017B-UL2017",
                    "DoubleMuon_Run2017C-UL2017",
                    "DoubleMuon_Run2017D-UL2017",
                    "DoubleMuon_Run2017E-UL2017",
                    "DoubleMuon_Run2017F-UL2017",
                    "MuonEG_Run2017B-UL2017",
                    "MuonEG_Run2017C-UL2017",
                    "MuonEG_Run2017D-UL2017",
                    "MuonEG_Run2017E-UL2017",
                    "MuonEG_Run2017F-UL2017",
                    "SingleElectron_Run2017B-UL2017",
                    "SingleElectron_Run2017C-UL2017",
                    "SingleElectron_Run2017D-UL2017",
                    "SingleElectron_Run2017E-UL2017",
                    "SingleElectron_Run2017F-UL2017",
                    "SingleMuon_Run2017B-UL2017",
                    "SingleMuon_Run2017C-UL2017",
                    "SingleMuon_Run2017D-UL2017",
                    "SingleMuon_Run2017E-UL2017",
                    "SingleMuon_Run2017F-UL2017",
                    ]
        elif issignal:
            sample_list = [
                    "VBSWWHToLNuLNubb_C2V",
                    "VBSWWHToLNuLNubb_SM",
                    "VBSWWHToLNuLNubb_C3",
                    "VBSWWHToLNuLNubb_CV",
                    ]
        else:
            sample_list = [
                    "DYJetsToLL_M-10to50",
                    "DYJetsToLL_M-50",
                    "SSWW",
                    "WJetsToLNu",
                    "WW",
                    "WZTo3LNu_mllmin01_NNPDF31",
                    "ZZ",
                    "TTTo2L2Nu",
                    "TTToSemiLeptonic",
                    "TTWJetsToLNu",
                    "TTZToLLNuNu_M-10",
                    "TWZToLL_thad_Wlept_5f_DR",
                    "TWZToLL_tlept_Whad_5f_DR",
                    "ttHJetToNonbb_M125",
                    "ttHJetTobb_M125",
                    "ST_s-channel_4f_leptonDecays",
                    "ST_t-channel_antitop_4f_InclusiveDecays",
                    "ST_t-channel_top_4f_InclusiveDecays",
                    "ST_tW_antitop_5f_NoFullyHadronicDecays",
                    "ST_tW_top_5f_NoFullyHadronicDecays",
                    "TTWW",
                    "TTWZ",
                    ]
    elif year == "2016":
        if isdata:
            sample_list = [
                    "DoubleEG_Run2016F-UL2016",
                    "DoubleEG_Run2016G-UL2016",
                    "DoubleEG_Run2016H-UL2016",
                    "DoubleMuon_Run2016F-UL2016",
                    "DoubleMuon_Run2016G-UL2016",
                    "DoubleMuon_Run2016H-UL2016",
                    "MuonEG_Run2016F-UL2016",
                    "MuonEG_Run2016G-UL2016",
                    "MuonEG_Run2016H-UL2016",
                    "SingleElectron_Run2016F-UL2016",
                    "SingleElectron_Run2016G-UL2016",
                    "SingleElectron_Run2016H-UL2016",
                    "SingleMuon_Run2016F-UL2016",
                    "SingleMuon_Run2016G-UL2016",
                    "SingleMuon_Run2016H-UL2016",
                    ]
        elif issignal:
            sample_list = [
                    "VBSWWHToLNuLNubb_C2V",
                    "VBSWWHToLNuLNubb_SM",
                    "VBSWWHToLNuLNubb_C3",
                    "VBSWWHToLNuLNubb_CV",
                    ]
        else:
            sample_list = [
                    "DYJetsToLL_M-10to50",
                    "DYJetsToLL_M-50",
                    "SSWW",
                    "WJetsToLNu",
                    "WW",
                    "WZTo3LNu",
                    "ZZTo4L",
                    "TTTo2L2Nu",
                    "TTToSemiLeptonic",
                    "TTWJetsToLNu",
                    "TTZToLLNuNu_M-10",
                    "TWZToLL_thad_Wlept_5f_DR",
                    "TWZToLL_tlept_Whad_5f_DR",
                    "ttHJetToNonbb_M125",
                    "ttHJetTobb_M125",
                    "ST_s-channel_4f_leptonDecays",
                    "ST_t-channel_antitop_4f_InclusiveDecays",
                    "ST_t-channel_top_4f_InclusiveDecays",
                    "ST_tW_antitop_5f_NoFullyHadronicDecays",
                    "ST_tW_top_5f_NoFullyHadronicDecays",
                    "TTWW",
                    "TTWZ",
                    ]
    elif year == "2016APV":
        if isdata:
            sample_list = [
                    "DoubleEG_Run2016B-ver1_HIPM_UL2016",
                    "DoubleEG_Run2016B-ver2_HIPM_UL2016",
                    "DoubleEG_Run2016C-UL2016",
                    "DoubleEG_Run2016D-UL2016",
                    "DoubleEG_Run2016E-UL2016",
                    "DoubleEG_Run2016F-HIPM_UL2016",
                    "DoubleMuon_Run2016B-ver1_HIPM_UL2016",
                    "DoubleMuon_Run2016B-ver2_HIPM_UL2016",
                    "DoubleMuon_Run2016C-UL2016",
                    "DoubleMuon_Run2016D-UL2016",
                    "DoubleMuon_Run2016E-UL2016",
                    "DoubleMuon_Run2016F-HIPM_UL2016",
                    "MuonEG_Run2016B-ver1_HIPM_UL2016",
                    "MuonEG_Run2016B-ver2_HIPM_UL2016",
                    "MuonEG_Run2016C-UL2016",
                    "MuonEG_Run2016D-UL2016",
                    "MuonEG_Run2016E-UL2016",
                    "MuonEG_Run2016F-HIPM_UL2016",
                    "SingleElectron_Run2016B-ver1_HIPM_UL2016",
                    "SingleElectron_Run2016B-ver2_HIPM_UL2016",
                    "SingleElectron_Run2016C-UL2016",
                    "SingleElectron_Run2016D-UL2016",
                    "SingleElectron_Run2016E-UL2016",
                    "SingleElectron_Run2016F-HIPM_UL2016",
                    "SingleMuon_Run2016B-ver1_HIPM_UL2016",
                    "SingleMuon_Run2016B-ver2_HIPM_UL2016",
                    "SingleMuon_Run2016C-UL2016",
                    "SingleMuon_Run2016D-UL2016",
                    "SingleMuon_Run2016E-UL2016",
                    "SingleMuon_Run2016F-HIPM_UL2016",
                    ]
        elif issignal:
            sample_list = [
                    "VBSWWHToLNuLNubb_C2V",
                    "VBSWWHToLNuLNubb_SM",
                    "VBSWWHToLNuLNubb_C3",
                    "VBSWWHToLNuLNubb_CV",
                    ]
        else:
            sample_list = [
                    "DYJetsToLL_M-10to50",
                    "DYJetsToLL_M-50",
                    "SSWW",
                    "WJetsToLNu",
                    "WW",
                    "WZTo3LNu",
                    "ZZTo4L",
                    "TTTo2L2Nu",
                    "TTToSemiLeptonic",
                    "TTWJetsToLNu",
                    "TTZToLLNuNu_M-10",
                    "TWZToLL_thad_Wlept_5f_DR",
                    "TWZToLL_tlept_Whad_5f_DR",
                    "ttHJetToNonbb_M125",
                    "ttHJetTobb_M125",
                    "ST_s-channel_4f_leptonDecays",
                    "ST_t-channel_antitop_4f_InclusiveDecays",
                    "ST_t-channel_top_4f_InclusiveDecays",
                    "ST_tW_antitop_5f_NoFullyHadronicDecays",
                    "ST_tW_top_5f_NoFullyHadronicDecays",
                    "TTWW",
                    "TTWZ",
                    ]
    return sample_list

def get_samplenames_3L(**kwargs):
    year = kwargs.get("year")
    isdata = kwargs.get("isdata")
    issignal = kwargs.get("issignal")
    sample_list = []
    if year == "2018":
        if isdata:
            sample_list = [
                    "DoubleMuon_Run2018A-UL2018",
                    "DoubleMuon_Run2018B-UL2018",
                    "DoubleMuon_Run2018C-UL2018",
                    "DoubleMuon_Run2018D-UL2018",
                    "EGamma_Run2018A-UL2018",
                    "EGamma_Run2018B-UL2018",
                    "EGamma_Run2018C-UL2018",
                    "EGamma_Run2018D-UL2018",
                    "MuonEG_Run2018A-UL2018",
                    "MuonEG_Run2018B-UL2018",
                    "MuonEG_Run2018C-UL2018",
                    "MuonEG_Run2018D-UL2018",
                    ]
        elif issignal:
            sample_list = [
                    "VBSWWHToLNuLNubb_C2V",
                    "VBSWWHToLNuLNubb_SM",
                    "VBSWWHToLNuLNubb_C3",
                    "VBSWWHToLNuLNubb_CV",
                    ]
        else:
            sample_list = [
                    "DYJetsToLL_M-10to50",
                    "DYJetsToLL_M-50",
                    "WZTo3LNu_TuneCP5",
                    "TTZToLLNuNu_M-10",
                    "TTWJetsToLNu",
                    "TTTo2L2Nu",
                    "ZZTo4L",
                    "ZGToLLG",
                    "WGToLNuG",
                    "VHToNonbb",
                    "WW",
                    ]
    elif year == "2017":
        if isdata:
            sample_list = [
                    "DoubleEG_Run2017B-UL2017",
                    "DoubleEG_Run2017C-UL2017",
                    "DoubleEG_Run2017D-UL2017",
                    "DoubleEG_Run2017E-UL2017",
                    "DoubleEG_Run2017F-UL2017",
                    "DoubleMuon_Run2017B-UL2017",
                    "DoubleMuon_Run2017C-UL2017",
                    "DoubleMuon_Run2017D-UL2017",
                    "DoubleMuon_Run2017E-UL2017",
                    "DoubleMuon_Run2017F-UL2017",
                    "MuonEG_Run2017B-UL2017",
                    "MuonEG_Run2017C-UL2017",
                    "MuonEG_Run2017D-UL2017",
                    "MuonEG_Run2017E-UL2017",
                    "MuonEG_Run2017F-UL2017",
                    ]
        elif issignal:
            sample_list = [
                    "VBSWWHToLNuLNubb_C2V",
                    "VBSWWHToLNuLNubb_SM",
                    "VBSWWHToLNuLNubb_C3",
                    "VBSWWHToLNuLNubb_CV",
                    ]
        else:
            sample_list = [
                    "DYJetsToLL_M-10to50",
                    "DYJetsToLL_M-50",
                    "WZTo3LNu_TuneCP5",
                    "TTZToLLNuNu_M-10",
                    "TTWJetsToLNu",
                    "TTTo2L2Nu",
                    "ZZTo4L",
                    "ZGToLLG",
                    "WGToLNuG",
                    "VHToNonbb",
                    "WW",
                    ]
    elif year == "2016":
        if isdata:
            sample_list = [
                    "DoubleEG_Run2016F-UL2016",
                    "DoubleEG_Run2016G-UL2016",
                    "DoubleEG_Run2016H-UL2016",
                    "DoubleMuon_Run2016F-UL2016",
                    "DoubleMuon_Run2016G-UL2016",
                    "DoubleMuon_Run2016H-UL2016",
                    "MuonEG_Run2016F-UL2016",
                    "MuonEG_Run2016G-UL2016",
                    "MuonEG_Run2016H-UL2016",
                    ]
        elif issignal:
            sample_list = [
                    "VBSWWHToLNuLNubb_C2V",
                    "VBSWWHToLNuLNubb_SM",
                    "VBSWWHToLNuLNubb_C3",
                    "VBSWWHToLNuLNubb_CV",
                    ]
        else:
            sample_list = [
                    "DYJetsToLL_M-50",
                    "WZTo3LNu_TuneCP5",
                    "TTZToLLNuNu_M-10",
                    "TTWJetsToLNu",
                    "TTTo2L2Nu",
                    "ZZTo4L",
                    "ZGToLLG",
                    "WGToLNuG",
                    "VHToNonbb",
                    "WW",
                    ]
    elif year == "2016APV":
        if isdata:
            sample_list = [
                    "DoubleEG_Run2016B-ver1_HIPM_UL2016",
                    "DoubleEG_Run2016B-ver2_HIPM_UL2016",
                    "DoubleEG_Run2016C-HIPM_UL2016",
                    "DoubleEG_Run2016D-HIPM_UL2016",
                    "DoubleEG_Run2016E-HIPM_UL2016",
                    "DoubleEG_Run2016F-HIPM_UL2016",
                    "DoubleMuon_Run2016B-ver1_HIPM_UL2016",
                    "DoubleMuon_Run2016B-ver2_HIPM_UL2016",
                    "DoubleMuon_Run2016C-HIPM_UL2016",
                    "DoubleMuon_Run2016D-HIPM_UL2016",
                    "DoubleMuon_Run2016E-HIPM_UL2016",
                    "DoubleMuon_Run2016F-HIPM_UL2016",
                    "MuonEG_Run2016B-ver1_HIPM_UL2016",
                    "MuonEG_Run2016B-ver2_HIPM_UL2016",
                    "MuonEG_Run2016C-HIPM_UL2016",
                    "MuonEG_Run2016D-HIPM_UL2016",
                    "MuonEG_Run2016E-HIPM_UL2016",
                    "MuonEG_Run2016F-HIPM_UL2016",
                    ]
        elif issignal:
            sample_list = [
                    "VBSWWHToLNuLNubb_C2V",
                    "VBSWWHToLNuLNubb_SM",
                    "VBSWWHToLNuLNubb_C3",
                    "VBSWWHToLNuLNubb_CV",
                    ]
        else:
            sample_list = [
                    "DYJetsToLL_M-50",
                    "WZ_TuneCP5",
                    "TTZToLLNuNu_M-10",
                    "TTWJetsToLNu",
                    "TTTo2L2Nu",
                    "ZZTo4L",
                    # "ZGToLLG",
                    "WGToLNuG",
                    "VHToNonbb",
                    "WW",
                    ]
    return sample_list

def get_nanoaodtag(**kwargs):
    isdata = kwargs.get("isdata")
    year = kwargs.get("year")
    if "3L" not in kwargs.get("skimversion"):
        if isdata:              return "MiniAODv1_NanoAODv2"
        elif year == "2018":    return "UL18NanoAODv2"
        elif year == "2017":    return "UL17NanoAODv2"
        elif year == "2016":    return "UL16NanoAODv2"
        elif year == "2016APV": return "UL16NanoAODAPVv2"
    else:
        if isdata:              return "MiniAODv2_NanoAODv9"
        elif year == "2018":    return "UL18NanoAODv9"
        elif year == "2017":    return "UL17NanoAODv9"
        elif year == "2016":    return "UL16NanoAODv9"
        elif year == "2016APV": return "UL16NanoAODAPVv9"

def get_samplelist(skimversion="v2.6", minintup_tag="testV1", histogram_tag="v1", username="phchang"):
    samplelist = []
    for year in ["2018", "2017", "2016", "2016APV"]:
        for (isdata, issignal) in [(True, False), (False, True), (False, False)]:
            samplenames = get_samplenames(year=year, isdata=isdata, issignal=issignal)
            for s in samplenames:
                sample = Sample(
                        samplename=s,
                        isdata=isdata,
                        issignal=issignal,
                        skimversion=skimversion,
                        username=username,
                        year=year,
                        minintup_tag=minintup_tag,
                        histogram_tag=histogram_tag,
                        )
                samplelist.append(sample)
    return samplelist

def get_samplelist_3L(skimversion="v2.6_3L", minintup_tag="testV1", histogram_tag="v1", username="phchang"):
    samplelist = []
    for year in ["2018", "2017", "2016", "2016APV"]:
    # for year in ["2017", "2018"]:
    # for year in ["2017"]:
        for (isdata, issignal) in [(True, False), (False, False)]:
        # for (isdata, issignal) in [(True, False)]:
            samplenames = get_samplenames_3L(year=year, isdata=isdata, issignal=issignal)
            for s in samplenames:
                sample = Sample(
                        samplename=s,
                        isdata=isdata,
                        issignal=issignal,
                        skimversion=skimversion,
                        username=username,
                        year=year,
                        minintup_tag=minintup_tag,
                        histogram_tag=histogram_tag,
                        )
                samplelist.append(sample)
    return samplelist

def run_minintup(samplelist, resubmit=False):
    jobcmds = []
    for s in samplelist:
        if resubmit:
            jobcmds += s.info["minintup_jobcommands"]
        else:
            for (isf, cmd) in zip(s.info["minintup_isfinished"], s.info["minintup_jobcommands"]):
                if not isf:
                    jobcmds.append(cmd)
    f = open(".minintup.jobs", "w")
    f.write("\n".join(jobcmds))
    f.close()
    if len(jobcmds) > 0:
        os.system("xargs.sh .minintup.jobs")

def run_hadd(samplelist, resubmit=False):
    # take the first sample to get the various tags
    s = samplelist[0]
    skimversion = s.info["skimversion"]
    minintup_tag = s.info["minintup_tag"]
    jobcmds = []
    outputs = []
    for year in get_years():
        if year == "Run2":
            sourceyear = "201*"
        else:
            sourceyear = year
        hadd_odir = "outputs/minintuphadd/{skimversion}/{minintup_tag}/{year}/".format(
                skimversion=skimversion,
                minintup_tag=minintup_tag,
                year=year,
                )
        peryear_hadd_odir_pattern = "outputs/minintup/{skimversion}/{minintup_tag}/{sourceyear}/".format(
                skimversion=skimversion,
                minintup_tag=minintup_tag,
                sourceyear=sourceyear,
                )
        for group in get_groups():
            cmd = "mkdir -p {hadd_odir}; hadd -f {hadd_odir}/{group}.root {peryear_hadd_odir_pattern}/{group}*.root > {hadd_odir}/{group}.log 2>&1".format(
                    hadd_odir=hadd_odir,
                    group=group,
                    peryear_hadd_odir_pattern=peryear_hadd_odir_pattern,
                    )
            outputs.append("{hadd_odir}/{group}.root".format(hadd_odir=hadd_odir, group=group))
            if not len(glob.glob(outputs[-1])):
                jobcmds.append(cmd)
    f = open(".hadd.jobs", "w")
    f.write("\n".join(jobcmds))
    f.close()
    if len(jobcmds) > 0:
        os.system("xargs.sh .hadd.jobs")

def run_histogram(samplelist, resubmit=False, runallrewgt=False):
    # take the first sample to get the various tags
    s = samplelist[0]
    skimversion = s.info["skimversion"]
    minintup_tag = s.info["minintup_tag"]
    histogram_tag = s.info["histogram_tag"]
    jobcmds = []
    outputs = []
    for year in get_years():
        if year == "Run2":
            sourceyear = "201*"
        else:
            sourceyear = year
        hadd_odir = "outputs/minintuphadd/{skimversion}/{minintup_tag}/{year}/".format(
                skimversion=skimversion,
                minintup_tag=minintup_tag,
                year=year,
                )
        hist_odir = "outputs/histogram/{skimversion}/{minintup_tag}/{year}/{histogram_tag}".format(
                skimversion=skimversion,
                minintup_tag=minintup_tag,
                year=year,
                histogram_tag=histogram_tag,
                )
        for group in get_groups():
            idxs = []
            # If CV signal sample then the there is extra option to pass to set it to specific CV value.
            if group == "vbshwwc2v":
                if runallrewgt:
                    for i in range(40):
                        idxs.append(i)
                    idxs.append(-1)
                else:
                    idxs.append(-1)
            elif group == "vbshwwcv":
                if runallrewgt:
                    for i in range(41):
                        idxs.append(i)
                    idxs.append(-1)
                else:
                    idxs.append(34)
            elif group == "vbshwwc3":
                if runallrewgt:
                    for i in range(40):
                        idxs.append(i)
                    idxs.append(-1)
                else:
                    idxs.append(-1)
            elif group == "vbshwwsm":
                idxs = [20]
            else:
                idxs = [-1]
            for i in idxs:
                cmd = "mkdir -p {hist_odir}; minilooper/doAnalysis -t variable {extracmd} -i {hadd_odir}/{group}.root -o {hist_odir}/{groupwsuffix}.root > {hist_odir}/{groupwsuffix}.log 2>&1".format(
                        extracmd="-r {}".format(i),
                        hist_odir=hist_odir,
                        hadd_odir=hadd_odir,
                        group=group,
                        groupwsuffix=group if len(idxs) == 1 else group + "_i{}".format(str(i).replace("-","_")),
                        )
                outputs.append("{hist_odir}/{group}.root".format(hist_odir=hist_odir, group=group if len(idxs) == 1 else group + "_i{}".format(str(i).replace("-","_"))))
                if not len(glob.glob(outputs[-1])):
                    jobcmds.append(cmd)
    f = open(".histogram.jobs", "w")
    f.write("\n".join(jobcmds))
    f.close()
    if len(jobcmds) > 0:
        os.system("xargs.sh .histogram.jobs")

def hadd_bkg(samplelist, resubmit=False):
    # take the first sample to get the various tags
    s = samplelist[0]
    skimversion = s.info["skimversion"]
    minintup_tag = s.info["minintup_tag"]
    histogram_tag = s.info["histogram_tag"]
    jobcmds = []
    outputs = []
    for year in get_years():
        if year == "Run2":
            sourceyear = "201*"
        else:
            sourceyear = year
        hist_odir = "outputs/histogram/{skimversion}/{minintup_tag}/{year}/{histogram_tag}".format(
                skimversion=skimversion,
                minintup_tag=minintup_tag,
                year=year,
                histogram_tag=histogram_tag,
                )
        cmd = "mkdir -p {hist_odir}; hadd -f {hist_odir}/totalbkg.root {hist_odir}/bosons.root {hist_odir}/tt1lpowheg.root {hist_odir}/tt2lpowheg.root {hist_odir}/ttw.root {hist_odir}/ttz.root {hist_odir}/raretop.root  > {hist_odir}/totalbkg.log 2>&1".format(
                hist_odir=hist_odir,
                )
        outputs.append("{hist_odir}/totalbkg.root".format(hist_odir=hist_odir))
        if not len(glob.glob(outputs[-1])):
            jobcmds.append(cmd)
        cmd = "mkdir -p {hist_odir}; hadd -f {hist_odir}/topbkg.root {hist_odir}/tt1lpowheg.root {hist_odir}/tt2lpowheg.root {hist_odir}/ttw.root {hist_odir}/ttz.root {hist_odir}/raretop.root  > {hist_odir}/topbkg.log 2>&1".format(
                hist_odir=hist_odir,
                )
        outputs.append("{hist_odir}/topbkg.root".format(hist_odir=hist_odir))
        if not len(glob.glob(outputs[-1])):
            jobcmds.append(cmd)
    f = open(".haddbkg.jobs", "w")
    f.write("\n".join(jobcmds))
    f.close()
    if len(jobcmds) > 0:
        os.system("xargs.sh .haddbkg.jobs")

def run(samplelist, runallrewgt=False):
    resubmit=False
    run_minintup(samplelist, resubmit=resubmit)
    run_hadd(samplelist, resubmit=resubmit)
    run_histogram(samplelist, resubmit=resubmit, runallrewgt=runallrewgt)
    hadd_bkg(samplelist, resubmit=resubmit)

def print_samplelist(samplelist):
    samplelist[0].printheader()
    for s in samplelist:
        print(s)

class Sample:
    def __init__(self, **kwargs):
        self.info = {
                "samplename": kwargs.get("samplename", None),
                "isdata": kwargs.get("isdata", None),
                "issignal": kwargs.get("issignal", None),
                "skimversion": kwargs.get("skimversion", None),
                "year": kwargs.get("year", None),
                "username": kwargs.get("username"),
                "xsec": kwargs.get("xsec", None),
                "group": kwargs.get("group", None),
                "neffevents": kwargs.get("neffevents", None),
                "nevents": kwargs.get("nevents", None),
                "scale1fb": kwargs.get("scale1fb", None),
                "skimfilepath": kwargs.get("skimfilepath", None),
                "neventsinfofilepath": kwargs.get("neventsinfofilepath", None),
                "skimnevents": kwargs.get("skimnevents", None),
                "nanoaodtag": kwargs.get("nanoaodtag", None),
                "lumi": kwargs.get("lumi", None),
                "njobs": kwargs.get("njobs", 0),
                "minintup_tag": kwargs.get("minintup_tag", None),
                "minintup_nfinished": kwargs.get("minintup_nfinished", 0),
                "minintup_jobcommands": kwargs.get("minintup_jobcommands", []),
                "minintup_outputs": kwargs.get("minintup_outputs", []),
                "minintup_isfinished": kwargs.get("minintup_isfinished", []),
                "histogram_tag": kwargs.get("histogram_tag", None),
                "histogram_nfinished": kwargs.get("histogram_nfinished", 0),
                "histogram_jobcommands": kwargs.get("histogram_jobcommands", []),
                "histogram_outputs": kwargs.get("histogram_outputs", []),
                "histogram_isfinished": kwargs.get("histogram_isfinished", []),
                "hadd_jobcommand": kwargs.get("hadd_jobcommand", None),
                "hadd_output": kwargs.get("hadd_output", None),
                "hadd_status": kwargs.get("hadd_status", "N"),
                "ijecvar": kwargs.get("ijecvar", 0),
                }
        if self.info["samplename"] == None: raise TypeError("samplename not provided!")
        if self.info["isdata"] == None: raise TypeError("isdata not provided!")
        if self.info["issignal"] == None: raise TypeError("issignal not provided!")
        if self.info["skimversion"] == None: raise TypeError("skimversion not provided!")
        if self.info["year"] == None: raise TypeError("year not provided!")
        if self.info["username"] == None: raise TypeError("username not provided!")
        if self.info["minintup_tag"] == None: raise TypeError("minintup_tag not provided!")
        if self.info["histogram_tag"] == None: raise TypeError("histogram_tag not provided!")
        self.init()

    def init(self):
        #------------------------------------------------------------
        # parse few things first
        #------------------------------------------------------------
        self.info["xsec"] = get_xsec(**self.info)
        self.info["group"] = get_group(**self.info)
        self.info["nanoaodtag"] = get_nanoaodtag(**self.info)
        self.info["lumi"] = get_lumi(**self.info)
        if "3L" in self.info["skimversion"]:
            #------------------------------------------------------------
            # parse skim directory
            #------------------------------------------------------------
            fs = glob.glob("/nfs-7/userdata/{username}/VBSHWWNanoSkim_{skimversion}/{samplename}*{nanoaodtag}*/merged/merged.root".format(**self.info))
            if len(fs) != 1:
                print("ERROR! Found not equals to 1 number of samples in the skim nanoaod directory for sample={samplename} year={year} skimversion={skimversion} nanoaodtag={nanoaodtag} username={username}".format(**self.info))
                for d in fs:
                    print(d)
                sys.exit(-1)
            self.info["skimfilepath"] = fs[0]
            #------------------------------------------------------------
            # parse nevents
            #------------------------------------------------------------
            f = ROOT.TFile(self.info["skimfilepath"])
            self.info["skimnevents"] = f.Get("Events").GetEntries()
            h = f.Get("h_nevents")
            ntotal = h.GetBinContent(1)
            npos = h.GetBinContent(2)
            nneg = h.GetBinContent(3)
            #------------------------------------------------------------
            # parse real number of events
            #------------------------------------------------------------
            if self.info["isdata"]:
                self.info["nevents"] = int(ntotal)
                self.info["neffevents"] = int(ntotal)
            else:
                self.info["nevents"] = int(ntotal)
                self.info["neffevents"] = int(npos - nneg)
        else:
            #------------------------------------------------------------
            # parse skim directory
            #------------------------------------------------------------
            fs = glob.glob("/nfs-7/userdata/{username}/VBSHWWNanoSkim_{skimversion}/{samplename}*{nanoaodtag}*/merged/output.root".format(**self.info))
            if len(fs) != 1:
                print("ERROR! Found not equals to 1 number of samples in the skim nanoaod directory for sample={samplename} year={year} skimversion={skimversion} nanoaodtag={nanoaodtag} username={username}".format(**self.info))
                for d in fs:
                    print(d)
                sys.exit(-1)
            self.info["skimfilepath"] = fs[0]
            #------------------------------------------------------------
            # parse nevents
            #------------------------------------------------------------
            f = ROOT.TFile(self.info["skimfilepath"])
            self.info["skimnevents"] = f.Get("Events").GetEntries()
            #------------------------------------------------------------
            # parse real number of events
            #------------------------------------------------------------
            self.info["neventsinfofilepath"] = self.info["skimfilepath"].replace("output.root", "nevents.txt")
            f = open(self.info["neventsinfofilepath"])
            lines = f.readlines()
            self.info["nevents"] = int(lines[0].strip())
            self.info["neffevents"] = int(lines[-1].strip())
        #------------------------------------------------------------
        # parse njobs
        #------------------------------------------------------------
        njobs = self.info["skimnevents"] / 55000
        njobs += 1 if self.info["skimnevents"] % 55000 > 0 else 0
        self.info["njobs"] = njobs
        #------------------------------------------------------------
        # parse scale1fb
        #------------------------------------------------------------
        if self.info["isdata"]:
            self.info["scale1fb"] = 1
        else:
            self.info["scale1fb"] = float(self.info["xsec"]) * 1000.0 / float(self.info["neffevents"])
        #------------------------------------------------------------
        # parse minintup cmds
        #------------------------------------------------------------
        if "_jecUp" in self.info["minintup_tag"]: self.info["ijecvar"] = 1
        if "_jecDn" in self.info["minintup_tag"]: self.info["ijecvar"] =-1
        extracmd = ""
        if "3L" in self.info["minintup_tag"]: extracmd = "-3"
        if "2L" in self.info["minintup_tag"]: extracmd = "-2"
        minintup_nfinished = 0
        for idx in range(self.info["njobs"]):
            # Mini Ntuple creation command building
            minintup_odir = "outputs/minintup/{skimversion}/{minintup_tag}/{year}".format(**self.info)
            minintup_output = "{minintup_odir}/{group}_{samplename}_output_{idx}.root".format(minintup_odir=minintup_odir, idx=idx, **self.info)
            minintup_log = "{minintup_odir}/{group}_{samplename}_output_{idx}.log".format(minintup_odir=minintup_odir, idx=idx, **self.info)
            minintup_cmd = "mkdir -p {minintup_odir}/; rm -f {minintup_output}; studies/createMini/doAnalysis {extracmd} -t Events -o {minintup_output} -e {ijecvar} --scale1fb {scale1fb} -j {njobs} -I {idx} -i {skimfilepath} > {minintup_log} 2>&1".format(minintup_odir=minintup_odir, minintup_output=minintup_output, minintup_log=minintup_log, idx=idx, extracmd=extracmd, **self.info)
            # histogram_cmd = "mkdir -p {histogram_odir}/; rm -f {histogram_output}; minilooper/doAnalysis {extracmd} -t variable -o {histogram_output} -i {minintup_output} > {histogram_log} 2>&1".format(histogram_odir=histogram_odir, histogram_output=histogram_output, histogram_log=histogram_log, minintup_output=minintup_output, idx=idx, extracmd=extracmd,**self.info)
            self.info["minintup_jobcommands"].append(minintup_cmd)
            self.info["minintup_outputs"].append(minintup_output)
            minintup_ls = glob.glob(minintup_log)
            if len(minintup_ls) > 0:
                minintup_isfinished = int(subprocess.check_output("grep 'Who cares!' {} | wc -l".format(minintup_log), shell=True)) > 0
                self.info["minintup_isfinished"].append(minintup_isfinished)
                if minintup_isfinished:
                    minintup_nfinished += 1
            else:
                self.info["minintup_isfinished"].append(False)
        self.info["minintup_nfinished"] = minintup_nfinished

    def printheader(self):
        msg = "{year:9s} | {group:10s} | {samplename:40s} | {skimversion:10s} | {skimfilepath:230s} | {skimnevents:15s} | {nevents:15s} | {neffevents:15s} | {xsec:13s} | {scale1fb:15s} | {lumi:13s} | {minintup_tag:10s} | {jecvar:6s} | {minintupprogress:15s}".format(
                year="Year",
                group="group",
                samplename="Sample Name",
                skimversion="Skim Tag", 
                skimfilepath="Skim File Path", 
                skimnevents="N evt (skim)", 
                nevents="N evt (gen)", 
                neffevents="N evt (pos-neg)", 
                xsec="xsec", 
                scale1fb="scale1fb", 
                lumi="Lumi",
                minintup_tag="miniNT tag",
                jecvar="jecvar",
                minintupprogress="miniNT (N/Tot.)",
                # haddstatus="hadd",
                )
        print(msg)

    def __str__(self):
        msg = "{year:9s} | {group:10s} | {samplename:40s} | {skimversion:10s} | {skimfilepath:230s} | {skimnevents:15d} | {nevents:15d} | {neffevents:15d} | {xsec:10.5g} pb | {scale1fb:15f} | {lumi:10.4g}/fb | {minintup_tag:10s} | {ijecvar:6d} | {minintup_nfinished:7d}/{njobs:7d}".format(**self.info)
        return msg

if __name__ == "__main__":

    # samplelist = get_samplelist(skimversion="v2.6", minintup_tag="miniNtupV3", histogram_tag="HistV1")
    # print_samplelist(samplelist)
    # run(samplelist)
    # samplelist = get_samplelist(skimversion="v2.6", minintup_tag="miniNtupV1_jecUp", histogram_tag="HistV1")
    # print_samplelist(samplelist)
    # run(samplelist)
    # samplelist = get_samplelist(skimversion="v2.6", minintup_tag="miniNtupV1_jecDn", histogram_tag="HistV1")
    # print_samplelist(samplelist)
    # run(samplelist)

    samplelist = get_samplelist_3L(skimversion="v2.6_Excl3L", minintup_tag="v3_3L", histogram_tag="HistV1")
    print_samplelist(samplelist)
    run_minintup(samplelist)
    run_hadd(samplelist)
    # samplelist = get_samplelist_3L(skimversion="v2.6_3L", minintup_tag="v3_3L", histogram_tag="HistV1")
    # print_samplelist(samplelist)
    # run_minintup(samplelist)
    # run_hadd(samplelist)

    samplelist = get_samplelist_3L(skimversion="v2.6_Excl2L", minintup_tag="v1_2L", histogram_tag="HistV1")
    print_samplelist(samplelist)
    run_minintup(samplelist)
    run_hadd(samplelist)
