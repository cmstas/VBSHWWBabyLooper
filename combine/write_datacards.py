#!/bin/env python

#==================
#
#
# Writing datacards
#
#
#==================

import datacard_writer as dw
import ROOT as r

#_____________________________________________________________________________________
# Toggle options
doBDT = False
Tag = "v2.3_SS"
BabyVersion = "v5"
inputHistBaseDir = "/home/users/phchang/public_html/analysis/hwh/VBSHWWBabyLooper____/minilooper/"
inputHistDir = "{}/hists/Nominal/{}/{}/Run2/".format(inputHistBaseDir, Tag, BabyVersion)





######################################################################################
#
# Defining the search regions
#
######################################################################################

if doBDT:
    # BDT
    nbins = 4
    histname = "LooseVRMbbAllSRB__Channels4Bins"
else:
    # Cutbased
    nbins = 5
    histname = "LooseVRMbbOnSRA__Channels5Bins"

######################################################################################
#
# Getting the inputs from histograms that contains the yields from the looper
#
######################################################################################

# Define list of processes
topbkgs    = ["tt1lpowheg", "tt2lpowheg", "ttw", "ttz", "raretop", ]
nontopbkgs = ["bosons", ]
sigs       = ["vbshww_c2v_4p5", ]
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
syst = 0.6 # 60%
flat60pSystHists = {}
for process in processes:
    if process in topbkgs:
        flat60pSystHists[process] = "{}".format(1. + syst)
    else:
        flat60pSystHists[process] = 0
# Add the 60% systematics to the grand systs list
systs.append( ("flat60pSystHists", "lnN", [], flat60pSystHists) )

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
    d.write("test/datacard_bin{}.txt".format(i))
