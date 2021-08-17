#!/bin/env python

# Comparing different top background key kinematic shapes

import plottery_wrapper as p
import sys

def usage():
    print("Usage:")
    print("")
    print("   python {} VERSION YEAR RUNTAG BABYVERSION USERNAME PLOTSUBDIR [PLOTNAMES]".format(sys.argv[0]))
    print("")
    print("    VERSION       Skim versions               (e.g. v40)")
    print("    YEAR          Year                        (e.g. 2016, 2017, 2018, or Run2)")
    print("    RUNTAG        Run tag                     (e.g. Nominal, date, or whatever)")
    print("    BABYVERSION   Baby version                (e.g. Baby version)")
    print("    USERNAME      User of histogram creator   (e.g. Baby version)")
    print("    PLOTSUBDIR    Sub dir name                (e.g. VRPlots)")
    print("")
    sys.exit()

try:
    tag = sys.argv[1]
except:
    usage()

try:
    year = sys.argv[2]
except:
    usage()

try:
    runtag = sys.argv[3]
except:
    usage()

try:
    babyversion = sys.argv[4]
except:
    usage()

try:
    username = sys.argv[5]
except:
    usage()

try:
    subdir = sys.argv[6]
except:
    usage()

try:
    cutname_to_plot = sys.argv[7]
except:
    cutname_to_plot = ""

import ROOT as r
r.gROOT.SetBatch(True)

signal_scale = 1
blind=False
sig_run2 = 1
histxaxislabeloptions = {
"LT"                      : {"xaxis_label"      : "L_{T} [GeV]",              "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "blind": blind},
"ST"                      : {"xaxis_label"      : "S_{T} [GeV]",              "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "blind": blind},
"LTVarBin"                : {"xaxis_label"      : "L_{T} [GeV]",              "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "blind": blind},
"STVarBin"                : {"xaxis_label"      : "S_{T} [GeV]",              "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "blind": blind},
"LTZoom"                  : {"xaxis_label"      : "L_{T} [GeV]",              "xaxis_ndivisions" : 505, "nbins": 10, "signal_scale": signal_scale, "blind": blind},
"STZoom"                  : {"xaxis_label"      : "S_{T} [GeV]",              "xaxis_ndivisions" : 505, "nbins": 10, "signal_scale": signal_scale, "blind": blind},
"BDT"                     : {"xaxis_label"      : "BDT",                      "xaxis_ndivisions" : 505, "nbins": 10, "signal_scale": signal_scale, "blind": blind},
"BDTPassFail"             : {"xaxis_label"      : "BDT",                      "xaxis_ndivisions" : 505, "nbins":  2, "signal_scale": signal_scale, "blind": blind},
"BDTBkg"                  : {"xaxis_label"      : "BDT",                      "xaxis_ndivisions" : 505, "nbins":  5, "signal_scale": signal_scale, "blind": blind},
"BDTMD"                   : {"xaxis_label"      : "BDT (m_{bb}=125 GeV)",     "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "blind": blind},
"LeptonPt0"               : {"xaxis_label"      : "p_{T,lead-lep} [GeV]",     "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "blind": blind},
"LeptonPt1"               : {"xaxis_label"      : "p_{T,sublead-lep} [GeV]",  "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "blind": blind},
"LeptonPt0Zoom"           : {"xaxis_label"      : "p_{T,lead-lep} [GeV]",     "xaxis_ndivisions" : 505, "nbins": 10, "signal_scale": signal_scale, "blind": blind},
"LeptonPt1Zoom"           : {"xaxis_label"      : "p_{T,sublead-lep} [GeV]",  "xaxis_ndivisions" : 505, "nbins": 10, "signal_scale": signal_scale, "blind": blind},
"LeptonEta0"              : {"xaxis_label"      : "#eta_{lead-lep} [GeV]",    "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "blind": blind},
"LeptonEta1"              : {"xaxis_label"      : "#eta_{sublead-lep} [GeV]", "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "blind": blind},
"MJJ"                     : {"xaxis_label"      : "m_{jj} [GeV]",             "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "blind": blind},
"MJJZoom"                 : {"xaxis_label"      : "m_{jj} [GeV]",             "xaxis_ndivisions" : 505, "nbins": 10, "signal_scale": signal_scale, "blind": blind},
"MJJVarBin"               : {"xaxis_label"      : "m_{jj} [GeV]",             "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "blind": blind},
"DEtaJJ"                  : {"xaxis_label"      : "#Delta#eta_{jj} [GeV]",    "xaxis_ndivisions" : 505, "nbins": 10, "signal_scale": signal_scale, "blind": blind},
"DEtaJJVarBin"            : {"xaxis_label"      : "#Delta#eta_{jj} [GeV]",    "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "blind": blind},
"JetEta0"                 : {"xaxis_label"      : "p_{T,lead-jet} [GeV]",     "xaxis_ndivisions" : 505, "nbins": 10, "signal_scale": signal_scale, "blind": blind},
"JetEta1"                 : {"xaxis_label"      : "p_{T,sublead-jet} [GeV]",  "xaxis_ndivisions" : 505, "nbins": 10, "signal_scale": signal_scale, "blind": blind},
"JetPt0"                  : {"xaxis_label"      : "p_{T,lead-jet} [GeV]",     "xaxis_ndivisions" : 505, "nbins": 10, "signal_scale": signal_scale, "blind": blind},
"JetPt1"                  : {"xaxis_label"      : "p_{T,sublead-jet} [GeV]",  "xaxis_ndivisions" : 505, "nbins": 10, "signal_scale": signal_scale, "blind": blind},
"BJetPt0"                 : {"xaxis_label"      : "p_{T,lead-b} [GeV]",       "xaxis_ndivisions" : 505, "nbins": 10, "signal_scale": signal_scale, "blind": blind},
"BJetPt1"                 : {"xaxis_label"      : "p_{T,sublead-b} [GeV]",    "xaxis_ndivisions" : 505, "nbins": 10, "signal_scale": signal_scale, "blind": blind},
"MET"                     : {"xaxis_label"      : "MET [GeV]",                "xaxis_ndivisions" : 505, "nbins": 10, "signal_scale": signal_scale, "blind": blind},
"MbbZoom"                 : {"xaxis_label"      : "m_{bb} [GeV]",             "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "blind": blind},
"Mbb"                     : {"xaxis_label"      : "m_{bb} [GeV]",             "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "blind": blind},
"Channels4Bins"           : {"xaxis_label"      : "Channel",                  "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "blind": blind, "bin_labels": ["e^{+}l^{+}", "#mu^{+}l^{+}", "#tau^{+}l^{+}", "(--)"]},
"Channels5Bins"           : {"xaxis_label"      : "Channel",                  "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "blind": blind},
"Yield"                   : {"xaxis_label"      : "Yield",                    "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "blind": blind},
"VRs"                     : {"xaxis_label"      : "Yield",                    "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "blind": blind},
"SRs"                     : {"xaxis_label"      : "Yield",                    "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "blind": blind},
"LTMbbOff__BDTBkg"        : {"xaxis_label"      : "BDT",                      "xaxis_ndivisions" : 505, "nbins":  5, "signal_scale": signal_scale, "blind": blind, "yaxis_log":True},
"PSLTMbbOff__BDTBkg"      : {"xaxis_label"      : "BDT",                      "xaxis_ndivisions" : 505, "nbins":  5, "signal_scale": signal_scale, "blind": blind, "yaxis_log":True},
"PreselMbbAll__LT"        : {"xaxis_label"      : "L_{T} [GeV]",              "xaxis_ndivisions" : 505, "nbins": 30, "signal_scale": sig_run2,     "blind": blind, "yaxis_log":True},
"PreselMbbAll__ST"        : {"xaxis_label"      : "S_{T} [GeV]",              "xaxis_ndivisions" : 505, "nbins": 30, "signal_scale": sig_run2,     "blind": blind, "yaxis_log":True},
"PreselMbbAll__Ptbb"      : {"xaxis_label"      : "p_{T,bb} [GeV]",           "xaxis_ndivisions" : 505, "nbins": 30, "signal_scale": sig_run2,     "blind": blind, "yaxis_log":True},
"PreselMbbAll__MJJ"       : {"xaxis_label"      : "m_{jj} [GeV]",             "xaxis_ndivisions" : 505, "nbins": 30, "signal_scale": sig_run2,     "blind": blind, "yaxis_log":True},
"PreselMbbAll__DEtaJJ"    : {"xaxis_label"      : "#Delta#eta_{jj}",          "xaxis_ndivisions" : 505, "nbins": 30, "signal_scale": sig_run2,     "blind": blind, "yaxis_log":True},
"PreselMbbAll__LeptonPt0" : {"xaxis_label"      : "p_{T,lead-lep} [GeV]",     "xaxis_ndivisions" : 505, "nbins": 30, "signal_scale": sig_run2,     "blind": blind, "yaxis_log":True},
"PreselMbbAll__LeptonPt1" : {"xaxis_label"      : "p_{T,sublead-lep} [GeV]",  "xaxis_ndivisions" : 505, "nbins": 30, "signal_scale": sig_run2,     "blind": blind, "yaxis_log":True},
}

# hadd_dir = "hists/{}/{}/{}/{}/".format(runtag, tag, babyversion, year)
hadd_dir = "/nfs-7/userdata/{}/VBSHWWResult/{}/{}/{}/{}/".format(username, tag, babyversion, year, runtag)

bkgs_fit = [
        "{}/topbkg.root".format(hadd_dir),
        "{}/bosons.root".format(hadd_dir),
        ]
bkg_labels_fit = [
        "t#bar{t}(+XY)",
        "V/VV/VVV",
        ]
colors_fit = [
        6002,
        6004,
        ]

bkgs = [
        "{}/tt1lpowheg.root".format(hadd_dir),
        "{}/tt2lpowheg.root".format(hadd_dir),
        "{}/ttw.root".format(hadd_dir),
        "{}/ttz.root".format(hadd_dir),
        "{}/raretop.root".format(hadd_dir),
        "{}/bosons.root".format(hadd_dir),
        "{}/topbkg.root".format(hadd_dir),
        "{}/topbkg_mttw.root".format(hadd_dir),
        "{}/topbkg_pttw.root".format(hadd_dir),
        ]
bkg_labels = [
        "t#bar{t}(1l)",
        "t#bar{t}(2l)",
        "t#bar{t}W",
        "t#bar{t}Z",
        "Rare t#bar{t}+X(Y)",
        "V/VV/VVV",
        "t#bar{t}(+X)",
        "ttW(0x)",
        "ttW(2x)",
        ]
colors = [
        4020,
        4023,
        4021,
        4024,
        2001,
        2003,
        2003,
        4021,
        4021,
        ]

plot_dir = "{}/topbkgstudy/{}".format(hadd_dir, subdir)

dogrep = False
if len(cutname_to_plot) == 0:
    filter_pattern = ",".join(histxaxislabeloptions.keys())
    dogrep = False
else:
    filter_pattern = ""
    if "," in cutname_to_plot:
        filter_patterns = []
        for cn in cutname_to_plot.split(","):
            if "__" in cn:
                filter_patterns.append("{}".format(cn))
            else:
                filter_patterns.append("{}__".format(cn))
        filter_pattern = ",".join(filter_patterns)
    else:
        if "__" in cutname_to_plot:
            filter_pattern = "{}".format(cutname_to_plot)
        else:
            filter_pattern = "{}__".format(cutname_to_plot)

if "*" in filter_pattern:
    dogrep = True

prefix = cutname_to_plot[:3]
prefix = "2x"

systs=[
        None,
        "{}TT1LUp".format(prefix),
        "{}TT1LDn".format(prefix),
        "{}TT2LUp".format(prefix),
        "{}TT2LDn".format(prefix),
        "{}TTWUp".format(prefix),
        "{}TTWDn".format(prefix),
        "{}TTZUp".format(prefix),
        "{}TTZDn".format(prefix),
        "{}RareTopUp".format(prefix),
        "{}RareTopDn".format(prefix),
        ]

for syst in systs:

    if "Individ" in subdir:
        bkgs_ = bkgs
        bkg_labels_ = bkg_labels
        colors_ = colors
        nproc = 5
        idx = 6
    else:
        bkgs_ = bkgs_fit
        bkg_labels_ = bkg_labels_fit
        colors_ = colors_fit
        nproc = 1
        idx = 0

    p.dump_plot(
            fnames=[bkgs_[i] for i in xrange(nproc)],
            data_fname=bkgs_[idx],
            legend_labels=[bkg_labels_[i] for i in xrange(nproc)],
            usercolors=[colors_[i] for i in xrange(nproc)],
            filter_pattern=filter_pattern,
            dogrep=dogrep,
            dirname=plot_dir,
            extraoptions={
                "print_yield": True,
                "nbins": 20,
                # "signal_scale": 10,
                "legend_ncolumns": 2,
                "legend_scalex": 2.0,
                "lumi_value": -1,
                "ratio_range": [0., 2.],
                # "remove_overflow": True,
                "yield_prec": 3,
                # "blind": True,
                # "yaxis_range": [0., 80.],
                "yaxis_log": True,
                # "divide_by_bin_width": True,
                # "divide_by_first_bin": True,
                "fit_bkg": True,
                "extra_text_xpos":  0.3,
                "extra_text_ypos":  0.65,
                "legend_datalabel": "Top bkg",
                "ratio_name": "Nominal / Variation",
                },
            histxaxislabeloptions=histxaxislabeloptions,
            bkg_syst=syst,
            )
