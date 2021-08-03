#!/bin/env python

import plottery_wrapper as p

histxaxislabeloptions = {
        "GenDEtajj"           : {"xaxis_label": "#Delta#eta_{jj}"         , "xaxis_ndivisions" : 505, "nbins": 30, "signal_scale":   "auto"},
        "GenMjj"              : {"xaxis_label": "m_{jj} [GeV]"            , "xaxis_ndivisions" : 505, "nbins": 30, "signal_scale":   "auto"},
        "GenJEta0"            : {"xaxis_label": "#eta_{lead-VBF-jet}"     , "xaxis_ndivisions" : 505, "nbins": 30, "signal_scale":   "auto"},
        "GenJEta1"            : {"xaxis_label": "#eta_{sublead-VBF-jet}"  , "xaxis_ndivisions" : 505, "nbins": 30, "signal_scale":   "auto"},
        "GenWPt0"             : {"xaxis_label": "p_{T,lead-W} [GeV]"      , "xaxis_ndivisions" : 503, "nbins": 30, "signal_scale":   "auto"},
        "GenWPt1"             : {"xaxis_label": "p_{T,sublead-W} [GeV]"   , "xaxis_ndivisions" : 503, "nbins": 30, "signal_scale":   "auto"},
        "GenHPt"              : {"xaxis_label": "p_{T,higgs} [GeV]"       , "xaxis_ndivisions" : 503, "nbins": 30, "signal_scale":   "auto"},
        "GenST"               : {"xaxis_label": "S_{T} [GeV]"             , "xaxis_ndivisions" : 503, "nbins": 30, "signal_scale":   "auto"},
        "GenLT"               : {"xaxis_label": "L_{T} [GeV]"             , "xaxis_ndivisions" : 503, "nbins": 30, "signal_scale":   "auto"},
        "GenCosThetaStarA"    : {"xaxis_label": "cos(#theta^{*})"         , "xaxis_ndivisions" : 505, "nbins": 30, "signal_scale":   "auto"},
        "GenLepPt1Zoom"       : {"xaxis_label": "p_{T,sublead-lep} [GeV]" , "xaxis_ndivisions" : 503, "nbins": 30, "signal_scale":   "auto"},
        }


p.dump_plot(
        fnames=["c2v_1.root"],
        legend_labels=["C_{2V}=1 (SM)"],
        sig_fnames=[
            "c2v_0.root",
            "c2v_3.root",
            "c2v_m1.root",
            ],
        signal_labels=[
            "C_{2V}=0",
            "C_{2V}=3",
            "C_{2V}=-1",
            ],
        dirname="signal_kinematic_distributions",
        filter_pattern="rewgt__,isvbswwhlvlvbb__,pp__,mm__",
        dogrep=True,
        extraoptions={
            "nbins":30,
            "yaxis_label": "a.u.",
            "signal_scale": "auto",
            "lumi_value": -1,
            },
        skip2d=True,
        histxaxislabeloptions=histxaxislabeloptions,
        )
