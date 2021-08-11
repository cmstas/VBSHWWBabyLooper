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

def run(doBDT, idx, coupling):

    #_____________________________________________________________________________________
    # Toggle options
    Tag = "v2.4_SS"
    BabyVersion = "v6"
    inputHistBaseDir = "/nfs-7/userdata/phchang/VBSHWWResult/"
    inputHistDir = "{}/{}/{}/Run2/Nominal".format(inputHistBaseDir, Tag, BabyVersion)

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
    sigs       = ["s_{}{}".format(coupling, suffix), ]
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
        if process in sigs:
            hists[process].Scale(137/(59.97+41.3))
            # hists[process].Scale(20)

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

    # 60% symmetric error on all top backgrounds
    flat60pSyst = 0.6 # 60%
    flat60pSystMap = {}
    for process in processes:
        if process in topbkgs:
            flat60pSystMap[process] = "{}".format(1. + flat60pSyst)
        else:
            flat60pSystMap[process] = 0
    # Add the 60% systematics to the grand systs list
    systs.append( ("flat60pSyst", "lnN", [], flat60pSystMap) )

    # 20% symmetric error on signal
    flat20pSyst = 0.2 # 20%
    flat20pSystMap = {}
    for process in processes:
        if process in sigs:
            flat20pSystMap[process] = "{}".format(1. + flat20pSyst)
        else:
            flat20pSystMap[process] = 0
    # Add the 20% systematics to the grand systs list
    systs.append( ("flat20pSyst", "lnN", [], flat20pSystMap) )

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

    # run(doBDT=True,  c2v="4p5")
    # run(doBDT=False, c2v="4p5")
    # run(doBDT=True,  c2v="4")
    # run(doBDT=False, c2v="4")
    # run(doBDT=True,  c2v="3")
    # run(doBDT=False, c2v="3")
    # run(doBDT=True,  c2v="1")
    # run(doBDT=False, c2v="1")
    # run(doBDT=True,  c2v="0")
    # run(doBDT=False, c2v="0")
    # run(doBDT=True,  c2v="m1")
    # run(doBDT=False, c2v="m1")
    # run(doBDT=True,  c2v="m2")
    # run(doBDT=False, c2v="m2")
    # run(doBDT=True,  c2v="m2p5")
    # run(doBDT=False, c2v="m2p5")
