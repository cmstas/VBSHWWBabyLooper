#!/bin/env python

#==================
#
#
# Writing datacards
#
#
#==================

import datacard_writer as dw # if giving error run   $ source ../rooutil/thisrooutil.sh
import ROOT as r
from get_systs import get_systs

def run(doBDT, idx, coupling):

    #_____________________________________________________________________________________
    # Toggle options
    Tag = "v2.6"
    BabyVersion = "miniNtupV3"
    inputHistBaseDir = "../outputs/histogram"
    HistVersion = "HistV2"
    inputHistDir = "{}/{}/{}/Run2/{}".format(inputHistBaseDir, Tag, BabyVersion, HistVersion)

    #_____________________________________________________________________________________
    # Computing the correct c2v values
    if coupling == "c2v":
        if idx <= 33 and idx >= 0:
            coupl_mod = str(-4 + idx * 0.25)
        elif idx >= 34:
            coupl_mod = str(-4 + (idx+1) * 0.25)
        elif idx < 0:
            coupl_mod = str(4.5)
        coupl_mod = coupl_mod.replace(".", "p")
        coupl_mod = coupl_mod.replace("-", "m")
        suffix = "_i_1" if idx < 0 else "_i{}".format(idx)
    if coupling == "cv":
        coupl_mod = str(-2 + idx * 0.1)
        coupl_mod = coupl_mod.replace(".", "p")
        coupl_mod = coupl_mod.replace("-", "m")
        suffix = "_i{}".format(idx)
    if coupling == "c3":
        if idx <= 34 and idx >= 0:
            coupl_mod = str(-80 + idx * 4)
        elif idx >= 35:
            coupl_mod = str(-80 + (idx+1) * 4)
        elif idx < 0:
            coupl_mod = str(60)
        coupl_mod = coupl_mod.replace(".", "p")
        coupl_mod = coupl_mod.replace("-", "m")
        suffix = "_i_1" if idx < 0 else "_i{}".format(idx)




    ######################################################################################
    #
    # Defining the search regions
    #
    ######################################################################################

    if doBDT:
        # BDT
        nbins = 4
        histname = "LooseVR__BDTSR"
    else:
        # Cutbased
        nbins = 5
        histname = "LooseVR__CutSR"

    ######################################################################################
    #
    # Getting the inputs from histograms that contains the yields from the looper
    #
    ######################################################################################

    # Define list of processes
    # topbkgs    = ["tt1lpowheg", "tt2lpowheg", "ttw", "ttz", "raretop", ]
    topbkgs    = ["topbkgfit"]
    nontopbkgs = ["bosons", ]
    sigs       = ["vbshww{}{}".format(coupling, suffix), ]
    bkgs       = topbkgs + nontopbkgs
    processes  = bkgs + sigs

    # Opening up all the TFiles
    files = {}
    for process in processes:
        files[process] = r.TFile("{}/{}.root".format(inputHistDir, process))

    # Opening up all the TH1F's containing the signal region yields
    hists = {}
    for process in processes:
        hists[process] = files[process].Get("{}".format(histname))

        # The "Title" of the histogram must be set to a specific process name
        # That's how the DataCardWriter tool book keeps the processes
        hists[process].SetTitle(process)

        # If signal scale it up to 137/fb because we are missing 2016 signal (FIXME)
        # if process in sigs:
        #     hists[process].Scale(137/(59.97+41.3))
        #     hists[process].Scale(20)

    ######################################################################################
    #
    # Defining the systematics on the processes
    #
    ######################################################################################

    # Systematics
    # Supported types of input are
    #    1. [TH1, TH1] # up and down variation
    #    2. TH1
    #    3. [float, float] # up and down variation
    #    4. float
    #    5. str         # direct input
    #    6. [str, ... ] # direct input per bin
    #    7. None
    # All of the yields on these are expected to be the YIELDS AFTER SYST IS APPLIED. (i.e. NOT FRACTIONS)
    # You can mix and match

    # Grand object that will hold list of systematic definitions
    systs = []
    # Hand-made systematics
    systs.append(("lumiSyst", "lnN", [], {sigs[0]:2.5, "topbkgfit": 2.5, "bosons": 2.5}))
    # Factory-made systematics from LaTeX tables
    systs += get_systs(sigs[0], doBDT=doBDT)
    # Turn X% errors into 1+X/100
    fix_percent = lambda p: 1+p/100. if p != 0 else p
    fix_percents = lambda percents: [fix_percent(p) for p in percents]
    _systs = []
    for name, syst_type, empty_list, syst_map in systs:
        _syst_map = {}
        for key, val in syst_map.iteritems():
            if type(val) == list:
                _syst_map[key] = [str(v) if v != 0 else "-" for v in fix_percents(val)]
            else:
                _syst_map[key] = str(fix_percent(val)) if val != 0 else "-"
        _systs.append((name, syst_type, empty_list, _syst_map))
    systs = _systs

    # create the data card writer tool
    d = dw.DataCardWriter(
            sig=hists[sigs[0]],
            bgs=[ hists[bkg] for bkg in bkgs ],
            data=None,
            systs=systs,
            # no_stat_procs=["bkg2"]
            )

    # Loop over the bins in the histogram (i.e. the signal regions) and write the datacards
    for i in xrange(1, nbins+1):
        d.set_bin(i)
        d.set_region_name("bin{}".format(i))
        d.write("datacards/{}_{}{}/datacard_bin{}.txt".format("bdt" if doBDT else "cut", coupling, coupl_mod, i))

if __name__ == "__main__":

    # -1 is the default value which is set to 4.5
    run(doBDT=True,  idx=-1, coupling="c2v")
    run(doBDT=False, idx=-1, coupling="c2v")

    # Then loop over other values
    for i in xrange(40):
        run(doBDT=True,  idx=i, coupling="c2v")
        run(doBDT=False, idx=i, coupling="c2v")

    # Then loop over other values
    for i in xrange(41):
        run(doBDT=True,  idx=i, coupling="cv")
        run(doBDT=False, idx=i, coupling="cv")

    # -1 is the default value which is set to 4.5
    run(doBDT=True,  idx=-1, coupling="c3")
    run(doBDT=False, idx=-1, coupling="c3")

    # Then loop over other values
    for i in xrange(40):
        run(doBDT=True,  idx=i, coupling="c3")
        run(doBDT=False, idx=i, coupling="c3")
