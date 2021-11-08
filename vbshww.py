#!/bin/env python

import sys
import os
import ROOT
import glob

def get_xsec(**kwargs):
    samplename = kwargs.get("samplename")
    xsec = -999
    if "WW"                        in samplename: xsec = 118.71
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
    if "GluGluHToZZTo4L"           in samplename: xsec = 0.0082323
    if "DYJetsToLL_M-10to50"       in samplename: xsec = 20657.0
    if "DYJetsToLL_M-50"           in samplename: xsec = 6198.0
    if "WJetsToLNu"                in samplename: xsec = 61335.0
    if "TTWJetsToLNu"              in samplename: xsec = 0.2043
    if "TTZToLLNuNu_M-10"          in samplename: xsec = 0.2529
    if "TTZToLL_M-1to10"           in samplename: xsec = 0.2529
    if "TTJets_DiLept"             in samplename: xsec = 91.044
    if "TTJets_SingleLeptFromT"    in samplename: xsec = 182.96
    if "TTJets_SingleLeptFromTbar" in samplename: xsec = 182.96
    if "TTTo2L2Nu"                 in samplename: xsec = 87.315
    if "TTToSemiLeptonic"          in samplename: xsec = 365.34
    if "WpWpJJ_EWK"                in samplename: xsec = 0.0539
    if "SSWW"                      in samplename: xsec = 0.02794
    if "WZTo3LNu"                  in samplename: xsec = 4.4297
    if "VBSWWHToLNuLNubb_C2V"      in samplename: xsec = 0.0009246749816
    if "VBSWWHToLNuLNubb_CV"       in samplename: xsec = 0.0009246749816
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
                    "VBSWWHToLNuLNubb_C3",
                    "VBSWWHToLNuLNubb_CV",
                    ]
        else:
            sample_list = [
                    "DYJetsToLL_M-10to50",
                    "DYJetsToLL_M-50",
                    "SSWW",
                    "ST_s-channel_4f_leptonDecays",
                    "ST_t-channel_antitop_4f_InclusiveDecays",
                    "ST_t-channel_top_4f_InclusiveDecays",
                    "ST_tW_antitop_5f_NoFullyHadronicDecays",
                    "ST_tW_top_5f_NoFullyHadronicDecays",
                    "TTTo2L2Nu",
                    "TTToSemiLeptonic",
                    "TTWJetsToLNu",
                    "TTWW",
                    "TTWZ",
                    "TTZToLLNuNu_M-10",
                    "TWZToLL_thad_Wlept_5f_DR",
                    "TWZToLL_tlept_Whad_5f_DR",
                    "WJetsToLNu",
                    "WW",
                    "WZTo3LNu_mllmin01_NNPDF31",
                    "ZZTo4L",
                    "ttHJetToNonbb_M125",
                    "ttHJetTobb_M125",
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
                    "VBSWWHToLNuLNubb_C3",
                    "VBSWWHToLNuLNubb_CV",
                    ]
        else:
            sample_list = [
                    "DYJetsToLL_M-10to50",
                    "DYJetsToLL_M-50",
                    "SSWW",
                    "ST_s-channel_4f_leptonDecays",
                    "ST_t-channel_antitop_4f_InclusiveDecays",
                    "ST_t-channel_top_4f_InclusiveDecays",
                    "ST_tW_antitop_5f_NoFullyHadronicDecays",
                    "ST_tW_top_5f_NoFullyHadronicDecays",
                    "TTTo2L2Nu",
                    "TTToSemiLeptonic",
                    "TTWJetsToLNu",
                    "TTWW",
                    "TTWZ",
                    "TTZToLLNuNu_M-10",
                    "TWZToLL_thad_Wlept_5f_DR",
                    "TWZToLL_tlept_Whad_5f_DR",
                    "WJetsToLNu",
                    "WW",
                    "WZTo3LNu_mllmin01_NNPDF31",
                    "ZZ",
                    "ttHJetToNonbb_M125",
                    "ttHJetTobb_M125",
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
                    "VBSWWHToLNuLNubb_C3",
                    "VBSWWHToLNuLNubb_CV",
                    ]
        else:
            sample_list = [
                    "DYJetsToLL_M-10to50",
                    "DYJetsToLL_M-50",
                    "SSWW",
                    "ST_s-channel_4f_leptonDecays",
                    "ST_t-channel_antitop_4f_InclusiveDecays",
                    "ST_t-channel_top_4f_InclusiveDecays",
                    "ST_tW_antitop_5f_NoFullyHadronicDecays",
                    "ST_tW_top_5f_NoFullyHadronicDecays",
                    "TTTo2L2Nu",
                    "TTToSemiLeptonic",
                    "TTWJetsToLNu",
                    "TTWW",
                    "TTWZ",
                    "TTZToLLNuNu_M-10",
                    "TWZToLL_thad_Wlept_5f_DR",
                    "TWZToLL_tlept_Whad_5f_DR",
                    "WJetsToLNu",
                    "WW",
                    "WZTo3LNu",
                    "ZZTo4L",
                    "ttHJetToNonbb_M125",
                    "ttHJetTobb_M125",
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
                    "VBSWWHToLNuLNubb_C3",
                    "VBSWWHToLNuLNubb_CV",
                    ]
        else:
            sample_list = [
                    "DYJetsToLL_M-10to50",
                    "DYJetsToLL_M-50",
                    "SSWW",
                    "ST_s-channel_4f_leptonDecays",
                    "ST_t-channel_antitop_4f_InclusiveDecays",
                    "ST_t-channel_top_4f_InclusiveDecays",
                    "ST_tW_antitop_5f_NoFullyHadronicDecays",
                    "ST_tW_top_5f_NoFullyHadronicDecays",
                    "TTTo2L2Nu",
                    "TTToSemiLeptonic",
                    "TTWJetsToLNu",
                    "TTWW",
                    "TTWZ",
                    "TTZToLLNuNu_M-10",
                    "TWZToLL_thad_Wlept_5f_DR",
                    "TWZToLL_tlept_Whad_5f_DR",
                    "WJetsToLNu",
                    "WW",
                    "WZTo3LNu",
                    "ZZTo4L",
                    "ttHJetToNonbb_M125",
                    "ttHJetTobb_M125",
                    ]
    return sample_list

def get_nanoaodtag(**kwargs):
    isdata = kwargs.get("isdata")
    year = kwargs.get("year")
    if isdata:              return "MiniAODv1_NanoAODv2"
    elif year == "2018":    return "UL18NanoAODv2"
    elif year == "2017":    return "UL17NanoAODv2"
    elif year == "2016":    return "UL16NanoAODv2"
    elif year == "2016APV": return "UL16NanoAODAPVv2"

def get_samplelist(skimversion="v2.6", username="phchang"):
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
                        )
                samplelist.append(sample)
    return samplelist

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
                "neffevents": kwargs.get("neffevents", None),
                "nevents": kwargs.get("nevents", None),
                "scale1fb": kwargs.get("scale1fb", None),
                "skimfilepath": kwargs.get("skimfilepath", None),
                "neventsinfofilepath": kwargs.get("neventsinfofilepath", None),
                "skimnevents": kwargs.get("skimnevents", None),
                "nanoaodtag": kwargs.get("nanoaodtag", None),
                "lumi": kwargs.get("lumi", None),
                }
        if self.info["samplename"] == None: raise TypeError("samplename not provided!")
        if self.info["isdata"] == None: raise TypeError("isdata not provided!")
        if self.info["issignal"] == None: raise TypeError("issignal not provided!")
        if self.info["skimversion"] == None: raise TypeError("skimversion not provided!")
        if self.info["year"] == None: raise TypeError("year not provided!")
        if self.info["username"] == None: raise TypeError("username not provided!")
        self.init()

    def init(self):
        # parse few things first
        self.info["xsec"] = get_xsec(**self.info)
        self.info["nanoaodtag"] = get_nanoaodtag(**self.info)
        self.info["lumi"] = get_lumi(**self.info)
        # parse skim directory
        fs = glob.glob("/nfs-7/userdata/{username}/VBSHWWNanoSkim_{skimversion}/{samplename}*{nanoaodtag}*/merged/output.root".format(**self.info))
        if len(fs) != 1:
            print("ERROR! Found not equals to 1 number of samples in the skim nanoaod directory for sample={samplename} year={year} skimversion={skimversion} nanoaodtag={nanoaodtag} username={username}".format(**self.info))
            for d in fs:
                print(d)
            sys.exit(-1)
        self.info["skimfilepath"] = fs[0]
        # parse nevents
        f = ROOT.TFile(self.info["skimfilepath"])
        self.info["skimnevents"] = f.Get("Events").GetEntries()
        # parse real number of events
        self.info["neventsinfofilepath"] = self.info["skimfilepath"].replace("output.root", "nevents.txt")
        f = open(self.info["neventsinfofilepath"])
        lines = f.readlines()
        self.info["nevents"] = int(lines[0].strip())
        self.info["neffevents"] = int(lines[-1].strip())
        # parse scale1fb
        self.info["scale1fb"] = float(self.info["xsec"]) * 1000.0 / float(self.info["neffevents"]) if not self.info["isdata"] else 1

    def printheader(self):
        msg = "{samplename:40s} | {skimversion:10s} | {skimfilepath:230s} | {skimnevents:15s} | {nevents:15s} | {neffevents:15s} | {xsec:13s} | {scale1fb:15s} | {lumi:10s}   ".format(
                samplename="Sample Name",
                skimversion="Skim Tag", 
                skimfilepath="Skim File Path", 
                skimnevents="N evt (skim)", 
                nevents="N evt (gen)", 
                neffevents="N evt (pos-neg)", 
                xsec="xsec", 
                scale1fb="scale1fb", 
                lumi="Lumi"
                )
        print(msg)

    def __str__(self):
        msg = "{samplename:40s} | {skimversion:10s} | {skimfilepath:230s} | {skimnevents:15d} | {nevents:15d} | {neffevents:15d} | {xsec:10.5g} pb | {scale1fb:15f} | {lumi:10.4g}/fb".format(**self.info)
        return msg

if __name__ == "__main__":
    samplelist = get_samplelist(skimversion="v2.6")
    samplelist[0].printheader()
    for s in samplelist:
        print(s)
