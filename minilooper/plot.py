#!/bin/env python

histxaxislabeloptions = {
"ElChannel__Mbb"         : {"xaxis_label"      : "m_{bb} [GeV]"            , "xaxis_ndivisions" : 505, "nbins": 10, "signal_scale": 1, "blind": False },
"MuChannel__Mbb"         : {"xaxis_label"      : "m_{bb} [GeV]"            , "xaxis_ndivisions" : 505, "nbins": 10, "signal_scale": 1, "blind": False },
"TauChannel__Mbb"        : {"xaxis_label"      : "m_{bb} [GeV]"            , "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": 1, "blind": False },
"NegChannel__Mbb"        : {"xaxis_label"      : "m_{bb} [GeV]"            , "xaxis_ndivisions" : 505, "nbins": 20, "signal_scale": 1, "blind": False },
}


import plottery_wrapper as p
import sys
def usage():
    print("Usage:")
    print("")
    print("   python {} VERSION YEAR [PLOTNAMES]".format(sys.argv[0]))
    print("")
    print("    VERSION       Skim versions (e.g. v40)")
    print("    YEAR          Year          (e.g. 2016, 2017, 2018, or Run2)")
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
    cutname_to_plot = sys.argv[3]
except:
    cutname_to_plot = ""

import ROOT as r
r.gROOT.SetBatch(True)

hadd_dir = "hists/{}/{}/".format(tag, year)

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
        2003,
        ]

sigs = [
        # "{}/vbshww_c2v_6.root".format(hadd_dir),
        "{}/vbshww_c2v_4p5.root".format(hadd_dir),
        # "{}/vbshww_c2v_3.root".format(hadd_dir),
        # "{}/vbshww_c2v_m2.root".format(hadd_dir),
        ]

signal_labels = [
        # "C_{2V}=6",
        "C_{2V}=4.5",
        # "C_{2V}=3",
        # "C_{2V}=-2",
        ]

if "Run2" not in hadd_dir:
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

# cutflow
p.dump_plot(
    fnames=bkgs,
    sig_fnames=sigs,
    data_fname=data_fname,
    legend_labels=bkg_labels,
    signal_labels=signal_labels,
    dirname="cutscans/{}/{}".format(tag, year) if do_cut_scan else "plots/{}/{}".format(tag, year),
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
        # "ratio_range": [0., 2.],
        "ratio_range": [0.7, 1.3],
        # "yield_prec": 4,
        # "blind": True,
        # "yaxis_range": [0., 45.],
        },
    histxaxislabeloptions=histxaxislabeloptions,
    skip2d=True,
    _plotter=p.plot_cut_scan if do_cut_scan else p.plot_hist,
    )
