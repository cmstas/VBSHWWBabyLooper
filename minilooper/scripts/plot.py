#!/bin/env python

import plottery_wrapper as p
import sys
def usage():
    print("Usage:")
    print("")
    print("   python {} VERSION YEAR RUNTAG BABYVERSION PLOTSUBDIR [PLOTNAMES]".format(sys.argv[0]))
    print("")
    print("    VERSION       Skim versions (e.g. v40)")
    print("    YEAR          Year          (e.g. 2016, 2017, 2018, or Run2)")
    print("    RUNTAG        Run tag       (e.g. Nominal, date, or whatever)")
    print("    BABYVERSION   Baby version  (e.g. Baby version)")
    print("    PLOTSUBDIR    Sub dir name  (e.g. VRPlots)")
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
    subdir = sys.argv[5]
except:
    usage()

try:
    cutname_to_plot = sys.argv[6]
except:
    cutname_to_plot = ""

import ROOT as r
r.gROOT.SetBatch(True)

hadd_dir = "hists/{}/{}/{}/{}/".format(runtag, tag, babyversion, year)

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
        # "{}/tt1l.root".format(hadd_dir),
        # "{}/tt2l.root".format(hadd_dir),
        "{}/ttw.root".format(hadd_dir),
        "{}/ttz.root".format(hadd_dir),
        "{}/raretop.root".format(hadd_dir),
        "{}/bosons.root".format(hadd_dir),
        ]
bkg_labels = [
        "t#bar{t}(1l)",
        "t#bar{t}(2l)",
        "t#bar{t}W",
        "t#bar{t}Z",
        "Rare t#bar{t}+X(Y)",
        "V/VV/VVV",
        ]
colors = [
        4020,
        4023,
        4021,
        4024,
        2001,
        6004,
        ]
# colors = [
#         6006,
#         6008,
#         6007,
#         6003,
#         6005,
#         6001,
#         ]

sigs = [
        "{}/vbshww_c2v_3.root".format(hadd_dir),
        "{}/vbshww_c2v_4p5.root".format(hadd_dir),
        "{}/vbshww_c2v_0.root".format(hadd_dir),
        "{}/vbshww_c2v_1.root".format(hadd_dir),
        ]

signal_labels = [
        "C_{2V}=3",
        "C_{2V}=4.5",
        "C_{2V}=0",
        "C_{2V}=1",
        # "C_{2V}=-2",
        ]

bkg_labels_tex = [
        "\\Nttonel",
        "\\Ntttwol",
        "\\NTTW",
        "\\NTTZ",
        "\\Nraretop",
        "\\NBOSONS",
        ]
signal_labels_tex = [
        "\\CTWOV=3",
        "\\CTWOV=4.5",
        "\\CTWOV=0",
        "\\CTWOV=1",
        ]

bkg_labels_fit_tex = [
        "\\NTTX",
        "\\NBOSONS",
        ]

if "2016" in hadd_dir:
    sigs = []
    signal_labels = None

if "LooseVR" in cutname_to_plot and "MbbOff" in cutname_to_plot and "Channels4Bins" in cutname_to_plot:
    sigs = []
    signal_labels = None

data_fname = "{}/data.root".format(hadd_dir)

lumi = -1
if "2016" in hadd_dir: lumi = 35.9
if "2017" in hadd_dir: lumi = 41.5
if "2018" in hadd_dir: lumi = 59.97
if "Run2" in hadd_dir: lumi = 137

ChannelsMbbMerged_bin_labels = [
"T-ee",
"T-e#mu",
"T-#mu#mu",
"L-ee",
"L-e#mu",
"L-#mu#mu",
"T-e#tau",
"T-#mu#tau",
]

sig_run2 = 137. / (59.97+41.3)

blind = False
signal_scale = 1
if year == "Run2" and tag == "v2.4_SS":
    signal_scale = 137. / (59.97+41.3)

if "_SS" in tag:
    if ("MbbOn" in cutname_to_plot and "SR" not in cutname_to_plot) or ("Presel" in cutname_to_plot and "MbbOff" not in cutname_to_plot):
        signal_scale = "auto"
        blind = True
    if ("MbbOn" in cutname_to_plot and "__SRs" in cutname_to_plot):
        signal_scale = 137. / (59.97+41.3)
        blind = True
    if ("MbbAll" in cutname_to_plot and "__BDT" in cutname_to_plot):
        signal_scale = 137. / (59.97+41.3)
        blind = True

histxaxislabeloptions = {
"LT"                              : {"xaxis_label"      : "L_{T} [GeV]",              "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "blind": blind},
"ST"                              : {"xaxis_label"      : "S_{T} [GeV]",              "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "blind": blind},
"LTVarBin"                        : {"xaxis_label"      : "L_{T} [GeV]",              "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "blind": blind},
"STVarBin"                        : {"xaxis_label"      : "S_{T} [GeV]",              "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "blind": blind},
"STVarBin3"                       : {"xaxis_label"      : "S_{T} [GeV]",              "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "blind": blind},
"LTZoom"                          : {"xaxis_label"      : "L_{T} [GeV]",              "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "blind": blind},
"STZoom"                          : {"xaxis_label"      : "S_{T} [GeV]",              "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "blind": blind},
"BDT"                             : {"xaxis_label"      : "BDT",                      "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "blind": blind},
"BDTVarBin"                       : {"xaxis_label"      : "BDT",                      "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "blind": blind},
"BDTBkg"                          : {"xaxis_label"      : "BDT",                      "xaxis_ndivisions" : 505, "nbins":  5, "signal_scale": signal_scale, "blind": blind},
"BDTMD"                           : {"xaxis_label"      : "BDT (m_{bb}=125 GeV)",     "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "blind": blind},
"LeptonPt0"                       : {"xaxis_label"      : "p_{T,lead-lep} [GeV]",     "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "blind": blind},
"LeptonPt1"                       : {"xaxis_label"      : "p_{T,sublead-lep} [GeV]",  "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "blind": blind},
"LeptonPt0Zoom"                   : {"xaxis_label"      : "p_{T,lead-lep} [GeV]",     "xaxis_ndivisions" : 505, "nbins": 10, "signal_scale": signal_scale, "blind": blind},
"LeptonPt1Zoom"                   : {"xaxis_label"      : "p_{T,sublead-lep} [GeV]",  "xaxis_ndivisions" : 505, "nbins": 10, "signal_scale": signal_scale, "blind": blind},
"LeptonEta0"                      : {"xaxis_label"      : "#eta_{lead-lep} [GeV]",    "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "blind": blind},
"LeptonEta1"                      : {"xaxis_label"      : "#eta_{sublead-lep} [GeV]", "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "blind": blind},
"MJJ"                             : {"xaxis_label"      : "m_{jj} [GeV]",             "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "blind": blind},
"MJJZoom"                         : {"xaxis_label"      : "m_{jj} [GeV]",             "xaxis_ndivisions" : 505, "nbins": 10, "signal_scale": signal_scale, "blind": blind},
"MJJVarBin"                       : {"xaxis_label"      : "m_{jj} [GeV]",             "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "blind": blind},
"DEtaJJ"                          : {"xaxis_label"      : "#Delta#eta_{jj} [GeV]",    "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "blind": blind},
"DEtaJJVarBin"                    : {"xaxis_label"      : "#Delta#eta_{jj} [GeV]",    "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "blind": blind},
"JetEta0"                         : {"xaxis_label"      : "p_{T,lead-jet} [GeV]",     "xaxis_ndivisions" : 505, "nbins": 10, "signal_scale": signal_scale, "blind": blind},
"JetEta1"                         : {"xaxis_label"      : "p_{T,sublead-jet} [GeV]",  "xaxis_ndivisions" : 505, "nbins": 10, "signal_scale": signal_scale, "blind": blind},
"JetPt0"                          : {"xaxis_label"      : "p_{T,lead-jet} [GeV]",     "xaxis_ndivisions" : 505, "nbins": 10, "signal_scale": signal_scale, "blind": blind},
"JetPt1"                          : {"xaxis_label"      : "p_{T,sublead-jet} [GeV]",  "xaxis_ndivisions" : 505, "nbins": 10, "signal_scale": signal_scale, "blind": blind},
"BJetPt0"                         : {"xaxis_label"      : "p_{T,lead-b} [GeV]",       "xaxis_ndivisions" : 505, "nbins": 10, "signal_scale": signal_scale, "blind": blind},
"BJetPt1"                         : {"xaxis_label"      : "p_{T,sublead-b} [GeV]",    "xaxis_ndivisions" : 505, "nbins": 10, "signal_scale": signal_scale, "blind": blind},
"MET"                             : {"xaxis_label"      : "MET [GeV]",                "xaxis_ndivisions" : 505, "nbins": 10, "signal_scale": signal_scale, "blind": blind},
"MbbZoom"                         : {"xaxis_label"      : "m_{bb} [GeV]",             "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "blind": blind},
"Mbb"                             : {"xaxis_label"      : "m_{bb} [GeV]",             "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "blind": blind},
"Channels4Bins"                   : {"xaxis_label"      : "Channel",                  "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "blind": True, "bin_labels": ["e^{+}l^{+}", "#mu^{+}l^{+}", "#tau^{+}l^{+}", "(--)"]},
"Channels5Bins"                   : {"xaxis_label"      : "Channel",                  "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "blind": True, "bin_labels": ["e^{+}l^{+}", "#mu^{+}l^{+}", "#tau^{+}l^{+}", "(--)", "(e/#mu)^{+}l^{+}"]},
"BDTSR"                           : {"xaxis_label"      : "Channel",                  "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "blind": True, "bin_labels": ["e^{+}l^{+}", "#mu^{+}l^{+}", "#tau^{+}l^{+}", "(--)"]},
"CutSR"                           : {"xaxis_label"      : "Channel",                  "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "blind": True, "bin_labels": ["e^{+}l^{+}", "#mu^{+}l^{+}", "#tau^{+}l^{+}", "(--)", "(e/#mu)^{+}l^{+}"]},
"BDTSR2"                          : {"xaxis_label"      : "Channel",                  "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "blind": True, "bin_labels": ["e^{+}l^{+}", "#mu^{+}l^{+}", "#tau^{+}l^{+}", "(--)"]},
"CutSR2"                          : {"xaxis_label"      : "Channel",                  "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "blind": True, "bin_labels": ["e^{+}l^{+}", "#mu^{+}l^{+}", "#tau^{+}l^{+}", "(--)"]},
"Yield"                           : {"xaxis_label"      : "Yield",                    "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "blind": blind},
"VRs"                             : {"xaxis_label"      : "Yield",                    "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "blind": blind},
"SRs"                             : {"xaxis_label"      : "Yield",                    "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "blind": blind},
"LTMbbOff__BDTBkg"                : {"xaxis_label"      : "BDT",                      "xaxis_ndivisions" : 505, "nbins":  5, "signal_scale": signal_scale, "blind": blind, "yaxis_log":True},
"PSLTMbbOff__BDTBkg"              : {"xaxis_label"      : "BDT",                      "xaxis_ndivisions" : 505, "nbins":  5, "signal_scale": signal_scale, "blind": blind, "yaxis_log":True},
"Presel__LT"                      : {"xaxis_label"      : "L_{T} [GeV]",              "xaxis_ndivisions" : 505, "nbins": 30, "signal_scale": sig_run2,     "blind": blind, "yaxis_log":True},
"Presel__ST"                      : {"xaxis_label"      : "S_{T} [GeV]",              "xaxis_ndivisions" : 505, "nbins": 30, "signal_scale": sig_run2,     "blind": blind, "yaxis_log":True},
"Presel__Ptbb"                    : {"xaxis_label"      : "p_{T,bb} [GeV]",           "xaxis_ndivisions" : 505, "nbins": 30, "signal_scale": sig_run2,     "blind": blind, "yaxis_log":True},
"Presel__Mbb"                     : {"xaxis_label"      : "m_{bb} [GeV]",             "xaxis_ndivisions" : 505, "nbins": 30, "signal_scale": sig_run2,     "blind": blind, "yaxis_log":True},
"Presel__MJJ"                     : {"xaxis_label"      : "m_{jj} [GeV]",             "xaxis_ndivisions" : 505, "nbins": 30, "signal_scale": sig_run2,     "blind": blind, "yaxis_log":True},
"Presel__DEtaJJ"                  : {"xaxis_label"      : "#Delta#eta_{jj}",          "xaxis_ndivisions" : 505, "nbins": 30, "signal_scale": sig_run2,     "blind": blind, "yaxis_log":True},
"Presel__LeptonPt0"               : {"xaxis_label"      : "p_{T,lead-lep} [GeV]",     "xaxis_ndivisions" : 505, "nbins": 30, "signal_scale": sig_run2,     "blind": blind, "yaxis_log":True},
"Presel__LeptonPt1"               : {"xaxis_label"      : "p_{T,sublead-lep} [GeV]",  "xaxis_ndivisions" : 505, "nbins": 30, "signal_scale": sig_run2,     "blind": blind, "yaxis_log":True},
"El__BDT"                         : {"xaxis_label"      : "BDT",                      "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": "auto",       "blind": True},
"Mu__BDT"                         : {"xaxis_label"      : "BDT",                      "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": "auto",       "blind": True},
"Tau__BDT"                        : {"xaxis_label"      : "BDT",                      "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": "auto",       "blind": True},
"Neg__BDT"                        : {"xaxis_label"      : "BDT",                      "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": "auto",       "blind": True},
"LooseVRMbbAllSRB__Channels4Bins" : {"xaxis_label"      : "Channel",                  "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "blind": True,  "bin_labels": ["e^{+}l^{+}", "#mu^{+}l^{+}", "#tau^{+}l^{+}", "(--)"]},
"LooseVRMbbOnSRA__Channels5Bins"  : {"xaxis_label"      : "Channel",                  "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": signal_scale, "blind": True,  "bin_labels": ["e^{+}l^{+}", "#mu^{+}l^{+}", "#tau^{+}l^{+}", "(--)", "(e/#mu)^{+}l^{+}"]},
}

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

do_cut_scan = True
do_cut_scan = False


fitbkg = True if "MbbOff" in cutname_to_plot else False
fitbkg = False if "LooseVRMbbOff__Channels4Bins" in cutname_to_plot else fitbkg
fitbkg = False if "LooseVRMbbOff__Alpha" in cutname_to_plot else fitbkg
fitbkg = False if "AnchorYield" in subdir else fitbkg

if subdir == "Fit":
    bkgs = bkgs_fit
    bkg_labels = bkg_labels_fit
    bkg_labels_tex = bkg_labels_fit_tex
    colors = colors_fit

# cutflow
p.dump_plot(
    fnames=bkgs,
    sig_fnames=sigs,
    data_fname=data_fname,
    legend_labels=bkg_labels,
    legend_labels_tex=bkg_labels_tex,
    signal_labels=signal_labels,
    signal_labels_tex=signal_labels_tex,
    dirname="cutscans/{}/{}/{}/{}/{}".format(runtag, tag, babyversion, year, subdir) if do_cut_scan else "plots/{}/{}/{}/{}/{}".format(runtag, tag, babyversion, year, subdir),
    filter_pattern=filter_pattern,
    dogrep=dogrep,
    usercolors=colors,
    extraoptions={
        "print_yield": True,
        "nbins": 20,
        # "signal_scale": 10,
        "legend_ncolumns": 3,
        "legend_scalex": 2.0,
        "lumi_value": lumi,
        "ratio_range": [0., 2.],
        # "remove_overflow": True,
        "yield_prec": 3,
        # "blind": True,
        # "yaxis_range": [0., 80.],
        # "yaxis_log": True,
        # "divide_by_bin_width": True,
        # "divide_by_first_bin": True,
        "fit_bkg": fitbkg,
        "extra_text_xpos":  0.3,
        "extra_text_ypos":  0.65,
        "hide_signal_scale": True,
        },
    histxaxislabeloptions=histxaxislabeloptions,
    skip2d=True,
    _plotter=p.plot_cut_scan if do_cut_scan else p.plot_hist,
    )
