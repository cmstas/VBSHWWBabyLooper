#!/bin/env python

import plottery_wrapper as p

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
        filter_pattern="rewgt__,isvbswwhlvlvbb__",
        dogrep=True,
        extraoptions={
            "nbins":30,
            "yaxis_label": "a.u.",
            "signal_scale": "auto",
            "lumi_value": -1,
            },
        skip2d=True,
        )
