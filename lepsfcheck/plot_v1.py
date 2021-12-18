#!/bin/env python

import plottery_wrapper as p
import sys

histxaxislabeloptions = {
    "DEtall" : {"xaxis_label" : "#Delta#eta_{ll}"         , "xaxis_ndivisions" : 505},
    "DPhill" : {"xaxis_label" : "#Delta#phi_{ll}"         , "xaxis_ndivisions" : 505},
    "Mll"    : {"xaxis_label" : "m_{ll} [GeV]"            , "xaxis_ndivisions" : 505},
    "Ptll"   : {"xaxis_label" : "p_{T,ll} [GeV]"          , "xaxis_ndivisions" : 505},
    "Eta0"   : {"xaxis_label" : "#eta_{lead-lep}"         , "xaxis_ndivisions" : 505},
    "Eta1"   : {"xaxis_label" : "#eta_{sublead-lep}"      , "xaxis_ndivisions" : 505},
    "Phi0"   : {"xaxis_label" : "#phi_{lead-lep}"         , "xaxis_ndivisions" : 505},
    "Phi1"   : {"xaxis_label" : "#phi_{sublead-lep}"      , "xaxis_ndivisions" : 505},
    "Pt0"    : {"xaxis_label" : "p_{T,lead-lep} [GeV]"    , "xaxis_ndivisions" : 505},
    "Pt1"    : {"xaxis_label" : "p_{T,sublead-lep} [GeV]" , "xaxis_ndivisions" : 505},
    "Njet"   : {"xaxis_label" : "n_{jets}"                , "xaxis_ndivisions" : 505},
    "nbtight": {"xaxis_label" : "n_{b-jets,tight}"        , "xaxis_ndivisions" : 505},
}

colors = [
        4021,
        2001,
        2005,
        4023,
        4024,
        6004,
        ]

def plot(flavor, year):

    if flavor == "ee": flavorcap = "EEPt10"
    if flavor == "em": flavorcap = "EM"
    if flavor == "mm": flavorcap = "MMPt10"

    flavordata = flavor
    if flavor == "ee" and year == "2018": flavordata = "eg"

    p.dump_plot(
        fnames=[
            "outputs/dy_{year}.root".format(year=year),
            "outputs/ww_{year}.root".format(year=year),
            "outputs/tt2l_{year}.root".format(year=year),
            "outputs/hww_{year}.root".format(year=year),
            ],
        data_fname="outputs/data_{flavordata}_{year}.root".format(year=year, flavordata=flavordata),
        usercolors=colors,
        dogrep=True,
        filter_pattern="{flavorcap}__".format(flavorcap=flavorcap),
        dirname="plots/plots_{year}_{flavor}_v2".format(year=year, flavor=flavor),
        legend_labels=["DY","WW","t#bar{t}(2l)","H(WW)"],
        extraoptions={
            "nbins":30,
            "ratio_range":[0., 2.],
            "print_yield":True,
            "lumi_value":19.5,
            "legend_scalex":1.8,
            "yaxis_log":True,
            },
        histxaxislabeloptions=histxaxislabeloptions,
        )

if __name__ == "__main__":
    plot("ee", "2016APV")
    plot("ee", "2016")
    plot("ee", "2017")
    plot("ee", "2018")
    plot("ee", "Run2")

    plot("mm", "2016APV")
    plot("mm", "2016")
    plot("mm", "2017")
    plot("mm", "2018")
    plot("mm", "Run2")

    plot("em", "2016APV")
    plot("em", "2016")
    plot("em", "2017")
    plot("em", "2018")
    plot("em", "Run2")
