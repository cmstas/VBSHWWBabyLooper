#!/bin/env python

import math
import ROOT as r
import sys
import os
from errors import E

#
#
# Background analysis python script
#
#

#_______________________________________________________________________________________________________________________________
# Command line parsing
def usage():

    print("Usage:")
    print("")
    print("")
    print("   > python {} YOURTAG [SKIMVERSION=v2.4_SS] [BABYVERSION=v2] [YEAR=Run2] [USERNAME=phchang]".format(sys.argv[0]))
    print("")
    print("")
    print("     YOURTAG       Minilooper run tag            (e.g. Date, name, or some specifier. Provide something you want to keep it unique)")
    print("     SKIMVERSION   Skim version                  (e.g. v2.4_SS                      [Default=v2.4_SS])")
    print("     BABYVERSION   Baby version                  (e.g. v2                           [Default=v2])")
    print("     YEAR          Year                          (e.g. 2016, 2017, 2018, or Run2    [Default=Run2])")
    print("     USERNAME      Username of histogram creator (e.g. phchang                      [Default=phchang] )")
    print("")
    sys.exit(-1)

try:
    YOURTAG=sys.argv[1]
except:
    usage()

try:
    SKIMVERSION=sys.argv[2]
except:
    SKIMVERSION="v2.4_SS"

try:
    BABYVERSION=sys.argv[3]
except:
    BABYVERSION="v2"

try:
    YEAR=sys.argv[4]
except:
    YEAR="Run2"

try:
    USERNAME=sys.argv[5]
except:
    USERNAME="phchang"


#_______________________________________________________________________________________________________________________________
# Defining base directory path where the histograms are saved after running mini looper
basedir = "/nfs-7/userdata/{}/VBSHWWResult/{}/{}/{}/{}".format(USERNAME, SKIMVERSION, BABYVERSION, YEAR, YOURTAG)

# List of top backgrounds
bkgs = ["tt1lpowheg", "tt2lpowheg", "raretop", "ttw", "ttz"]

# Opening up the ROOT TFile's of the top backgrounds that contain the histograms
topbkg_files = [ r.TFile("{}/{}.root".format(basedir, bkg)) for bkg in bkgs ]

# Opening up the data ROOT TFile
data_file = r.TFile("{}/data.root".format(basedir))

# Opening up the bosons (V/VV/VVV) background ROOT TFile
bosons_file = r.TFile("{}/bosons.root".format(basedir))

# Opening up the total background ROOT TFile
totalbkg_file = r.TFile("{}/totalbkg.root".format(basedir))

# List of systematics
systematics = ["LepSF", "BTagSF", "PURewgt"]

# List of composition systematics
comp_syst_variations = ["2xTT1L", "2xTT2L", "2xTTW", "2xTTZ", "2xRareTop"]

#_______________________________________________________________________________________________________________________________
# Get Tex format
def tex(value):
    return "{:.3g} $\pm$ {:.3g}\%".format(value.val, value.err / value.val * 100 if value.val != 0 else 0)

#_______________________________________________________________________________________________________________________________
# Get Tex format
def texerr(value):
    return "{:.3g}\%".format(value.err / value.val * 100 if value.val != 0 else 0)

#_______________________________________________________________________________________________________________________________
# Get composition systematics pretty print
def proc_pprint(comp_syst):
    rtn_str = ""
    if "TTW" in comp_syst: rtn_str += "\\TTW"
    if "TTZ" in comp_syst: rtn_str += "\\TTZ"
    if "TT1L" in comp_syst: rtn_str += "\\ttonel"
    if "TT2L" in comp_syst: rtn_str += "\\tttwol"
    if "RareTop" in comp_syst: rtn_str += "\\raretop"
    if "Dn" in comp_syst: rtn_str += "($\\times2$)"
    if "Up" in comp_syst: rtn_str += "($\\times1/2$)"
    return rtn_str

#_______________________________________________________________________________________________________________________________
# Move the overflow bin to last bin
def movein_overflow(h):
    bc = h.GetBinContent(h.GetNbinsX()+1)
    be = h.GetBinError(h.GetNbinsX()+1)
    lc = h.GetBinContent(h.GetNbinsX())
    le = h.GetBinError(h.GetNbinsX())
    nc = bc + lc
    ne = math.sqrt(be**2 + le**2)
    h.SetBinContent(h.GetNbinsX(), nc)
    h.SetBinError(h.GetNbinsX(), ne)
    h.SetBinContent(h.GetNbinsX()+1, 0)
    h.SetBinError(h.GetNbinsX()+1, 0)

#_______________________________________________________________________________________________________________________________
# Total top background yield and error in signal or control region for top background (the five top backgrounds merged)
# Input:
#   - channel      = El, Mu, Tau, Neg, Lgt, LL, LT etc.
#   - region       = SR or CR
#   - analysis     = BDT or Cut
#   - systematics  = LepSFUp, BTagSFUp, ...
# Output:
#   - errors.E object type (this object holds yields and error)
def y_topbkg(channel, region, analysis, systematics=""):

    # Declare the total top bkg yield (bc) and total top bkg yield error (be)
    bc = 0
    be = 0

    # each histogram where we will retrieve the yields and error will have signal region yields in the second bin and the first bin will have the yields in the anchor region
    idx = 1 if region == "CR" else 2 # second bin is the "signal region" and the first bin is the "control region"

    # loop over top backgrounds and get histograms and get yields and errors
    for f in topbkg_files: # loop over top backgrounds and get histograms and get yields and errors

        # Get the histograms that contain the yield
        h = f.Get("LooseVR{}__{}SR{}".format(systematics, analysis, channel))

        # Get the yield and the error for this top bkg to sum it up later
        tmp_bc = h.GetBinContent(idx) # second bin is the "signal region"
        tmp_be = h.GetBinError(idx)
        if tmp_bc <= 0: # If a yield goes below zero we zero it out prior to summing all top backgrounds for stability
            tmp_bc = 1e-6

        # Now sum it up
        bc += tmp_bc
        be = math.sqrt(be**2 + tmp_be**2)

    # Return the total bkg yield and error
    return E(bc, be)

# Short hand functions wrapping y_topbkg for sr and cr
def bsrmc(channel, analysis, systematics=""): return y_topbkg(channel, "SR", analysis, systematics)
def bcrmc(channel, analysis, systematics=""): return y_topbkg(channel, "CR", analysis, systematics)

#_______________________________________________________________________________________________________________________________
# (Data - Bosons) yield and error in signal or control region. (Data-bosons = amount of top background in data)
# Input:
#   - channel   = El, Mu, Tau, Neg, or Lgt (Lgt = the table scrap in cut based. There is no Lgt for BDT)
#   - region    = SR or CR
#   - analysis  = BDT or Cut
#   - systematics  = LepSFUp, BTagSFUp, ...
# Output:
#   - errors.E object type (this object holds yields and error)
def y_dt(channel, region, analysis, systematics=""):
    # each histogram where we will retrieve the yields and error will have signal region yields in the second bin and the first bin will have the yields in the anchor region
    idx = 1 if region == "CR" else 2 # second bin is the "signal region" and the first bin is the "control region"

    # Get the data histogram
    data_h = data_file.Get("LooseVR{}__{}SR{}".format(systematics, analysis, channel))

    # Obtain the yield and error
    data_bc = data_h.GetBinContent(idx)
    data_be = data_h.GetBinError(idx)

    # Get the bosons bkg histogram
    bosons_h = bosons_file.Get("LooseVR{}__{}SR{}".format(systematics, analysis, channel))

    # Obtain the yield and error
    bosons_bc = bosons_h.GetBinContent(idx)
    bosons_be = bosons_h.GetBinError(idx)

    if bosons_bc <= 0: # If a yield goes below zero we zero it out
        bosons_bc = 1e-6

    # Subtract the non-top bkg (i.e. bosons) from the data to get the yield of top bkg in data
    bc = data_bc - bosons_bc
    be = math.sqrt(data_be**2 + bosons_be**2)

    # Return the total top bkg in data yield and error
    return E(bc, be)


# Short hand function wrapping y_dt for control region
def bcrdt(channel, analysis, systematics=""): return y_dt(channel, "CR", analysis, systematics="")

#_______________________________________________________________________________________________________________________________
# Extrapolation factor alpha
# Input:
#   - channel   = El, Mu, Tau, Neg, Lgt, LL, LT etc.
#   - analysis  = BDT or Cut
#   - systematics  = LepSFUp, BTagSFUp, ...
# Output:
#   - errors.E object type (this object holds alpha and statistical error of alpha)
def alpha(channel, analysis, systematics=""):
    bSRMC = bsrmc(channel, analysis, systematics)
    bCRMC = bcrmc(channel, analysis, systematics)
    alpha = bSRMC / bCRMC
    return alpha

#_______________________________________________________________________________________________________________________________
# Function to compute the accumulated experimental systematics on the alpha value
# Input:
#   - channel   = El, Mu, Tau, Neg, Lgt, LL, LT etc.
#   - analysis  = BDT or Cut
# Output:
#   - errors.E object type (this object holds central alpha value +- expt. syst. to the alpha)
def alpha_expt_syst(channel, analysis):
    a = alpha(channel, analysis)
    accumulate_expt_syst = 0
    for syst in systematics:
        a_up = alpha(channel, analysis, "{}Up".format(syst))
        a_dn = alpha(channel, analysis, "{}Dn".format(syst))
        a_up /= a # Get fractional uncertainty
        a_dn /= a # Get fractional uncertainty
        symmetrized_syst_error = math.sqrt(abs((a_up-1).val)*abs((a_dn-1).val)) # Symmetrize the error. i.e. error = sqrt(|uperr|*|dnerr|)
        accumulate_expt_syst = math.sqrt(accumulate_expt_syst**2 + symmetrized_syst_error**2)
    err = a.val * accumulate_expt_syst
    return E(a.val, err)

#_______________________________________________________________________________________________________________________________
# Function to read off the largest modeling systematic error
# Input:
#   - channel   = El, Mu, Tau, Neg, Lgt, LL, LT etc.
#   - analysis  = BDT or Cut
# Output:
#   - errors.E object type (this object holds 1 +- largest modeling systematic error after looking through several variables)
def modeling_syst(channel, analysis):

    # Channel to read
    channel_to_read = channel

    # But if the channel is el or mu then we read the summed up Lgt
    if channel == "El" or channel == "Mu":
        channel_to_read = "Lgt"

    extra_suffix = "" # Extra suffix to the histogram needed only for BDT analysis

    # Cut analysis checks 4 variables
    if analysis == "Cut":
        # The variables to read
        variables = ["MJJVarBin", "DEtaJJVarBin", "STVarBin", "LTVarBin"]

        # But if the channel is "Lgt" then we read differnetly binned ST variable (because the stats run out otherwise
        if channel_to_read == "Lgt":
            variables = ["MJJVarBin", "DEtaJJVarBin", "STVarBin3", "LTVarBin"]
    # BDT analysis checks BDT variable
    else:
        # The variables to read
        variables = ["BDTBkg"]

        # But if the channel is "Lgt" then we read differnetly binned BDT variable (because the stats run out otherwise
        if channel_to_read == "Lgt":
            variables = ["BDTBkg2"]

        extra_suffix = "LowBDT" # BDT will look up histograms like e.g. "LgtMbbOffLowBDT__BDTBkg2"

    # Now loop over the variables and check the ratios between data/MC and pick up the largest change
    maxdiff = 0
    for variable in variables:
        # Get the histograms from data and MC
        h_data = data_file.Get("{}MbbOff{}__{}".format(channel_to_read, extra_suffix, variable))
        h_mc = totalbkg_file.Get("{}MbbOff{}__{}".format(channel_to_read, extra_suffix, variable))
        # if it is BDT analysis we re-bin the "BDTBkg" histograms to 3 bins
        if analysis == "BDT":
            h_data.Rebin(h_data.GetNbinsX() / 3)
            h_mc.Rebin(h_mc.GetNbinsX() / 3)
        # Scale the MC to match data yield and then compare
        mc_integral = h_mc.Integral(0, h_mc.GetNbinsX()+1)
        data_integral = h_data.Integral(0, h_data.GetNbinsX()+1)
        scale = data_integral / mc_integral
        h_mc.Scale(scale)
        # Move the overflow bins to last bin
        movein_overflow(h_data)
        movein_overflow(h_mc)
        # Now take the ratio
        h_ratio = h_data.Clone()
        h_ratio.Divide(h_mc)
        for i in range(1, h_ratio.GetNbinsX()+1):
            if h_ratio.GetBinContent(i) != 0:
                diff = abs(h_ratio.GetBinContent(i)-1)
                if maxdiff < diff:
                    maxdiff = diff
        # print(channel_to_read, variable)
        # h_ratio.Print("all")
    # print maxdiff

    return E(1, maxdiff)

#_______________________________________________________________________________________________________________________________
# Function to read off the largest modeling systematic error
# Also considers both cut and bdt and chooses the one that is more conservative
# Input:
#   - channel   = El, Mu, Tau, Neg, Lgt, LL, LT etc.
# Output:
#   - errors.E object type (this object holds 1 +- largest modeling systematic error after looking through several variables)
def modeling_syst_conservative(channel):
    cut_syst = modeling_syst(channel, "Cut")
    bdt_syst = modeling_syst(channel, "BDT")
    final_syst = cut_syst if cut_syst.err > bdt_syst.err else bdt_syst
    return final_syst

#_______________________________________________________________________________________________________________________________
# Function to obtain the composition systematics
# Input:
#   - channel   = El, Mu, Tau, Neg, Lgt, LL, LT etc.
# Output:
#   - errors.E object type (this object holds 1 += largest composition systematic error in upward direction only after looking through several variations)
def composition_syst_conservative(channel):
    cut_syst = composition_syst(channel, "Cut")
    bdt_syst = composition_syst(channel, "BDT")
    final_syst = cut_syst if cut_syst.err > bdt_syst.err else bdt_syst
    return final_syst

#_______________________________________________________________________________________________________________________________
# Function to obtain the composition systematics
# Input:
#   - channel   = El, Mu, Tau, Neg, Lgt, LL, LT etc.
#   - analysis  = BDT or Cut
# Output:
#   - errors.E object type (this object holds 1 += largest composition systematic error in upward direction only after looking through several variations)
def composition_syst(channel, analysis):
    # The channel to read is same as the channel
    # Except for El and Mu
    channel_to_read = channel
    if channel == "El" or channel == "Mu": 
        channel_to_read = "Lgt"
    max_pos_diff, max_pos_type, max_pos_alpha, max_neg_diff, max_neg_type, max_neg_alpha = composition_syst_max(channel_to_read, analysis)
    max_diff = max_pos_diff if max_pos_diff > max_neg_diff else max_neg_diff
    return E(1, max_diff)

#_______________________________________________________________________________________________________________________________
# Function to obtain the alpha with composition varied
# Input:
#   - channel   = El, Mu, Tau, Neg, Lgt, LL, LT etc.
#   - analysis  = BDT or Cut
#   - syst      = TT1L, TT2L, TTW, TTZ, RareTop
# Output:
#   - errors.E object type (this object holds alpha with the systematics varied
def alpha_comp_syst_up(channel, analysis, systematic):
    return alpha("2"+channel, analysis, systematic+"Up")

#_______________________________________________________________________________________________________________________________
# Function to obtain the alpha with composition varied
# Input:
#   - channel   = El, Mu, Tau, Neg, Lgt, LL, LT etc.
#   - analysis  = BDT or Cut
#   - syst      = TT1L, TT2L, TTW, TTZ, RareTop
# Output:
#   - errors.E object type (this object holds alpha with the systematics varied
def alpha_comp_syst_dn(channel, analysis, systematic):
    return alpha("2"+channel, analysis, systematic+"Dn")

#_______________________________________________________________________________________________________________________________
# Function to obtain the composition systematics
# Input:
#   - channel   = El, Mu, Tau, Neg, Lgt, LL, LT etc.
#   - analysis  = BDT or Cut
# Output:
#   - errors.E object type (this object holds 1 += largest composition systematic error after looking through several variations)
def composition_syst_max(channel, analysis):
    max_pos_diff = 0
    max_pos_type = 0
    max_pos_alpha = E(0, 0)
    max_neg_diff = 0
    max_neg_type = 0
    max_neg_alpha = E(0, 0)
    anom = alpha("2"+channel, analysis) # "2" prefix is needed to access the histograms of type LooseVR__CutSR2El
    for compsyst in comp_syst_variations:
        # print(channel, analysis, compsyst)
        auporig = alpha_comp_syst_up(channel, analysis, compsyst)
        aup = auporig / anom
        aup_err = (aup-1).val
        # print(channel, analysis, compsyst)
        adnorig = alpha_comp_syst_dn(channel, analysis, compsyst)
        adn = adnorig / anom
        adn_err = (adn-1).val
        if max_neg_diff > adn_err:
            max_neg_diff = adn_err
            max_neg_type = compsyst+"Dn"
            max_neg_alpha = adnorig
        if max_neg_diff > aup_err:
            max_neg_diff = aup_err
            max_neg_type = compsyst+"Up"
            max_neg_alpha = auporig
        if max_pos_diff < adn_err:
            max_pos_diff = adn_err
            max_pos_type = compsyst+"Dn"
            max_pos_alpha = adnorig
        if max_pos_diff < aup_err:
            max_pos_diff = aup_err
            max_pos_type = compsyst+"Up"
            max_pos_alpha = auporig
        # print(adn, adn)
    return max_neg_diff, max_neg_type, max_neg_alpha, max_pos_diff, max_pos_type, max_pos_alpha

#_______________________________________________________________________________________________________________________________
#TODO write a function to parse the error from modeling systematics and composition systematics
# Function to compute the alpha with full systematics
# Input:
#   - channel   = El, Mu, Tau, Neg, Lgt, LL, LT etc.
#   - analysis  = BDT or Cut
# Output:
#   - errors.E object type (this object holds central alpha value +- expt. syst. to the alpha)
def alpha_full_syst(channel, analysis):
    a = alpha(channel, analysis)
    aexp = alpha_expt_syst(channel, analysis)
    amodel = modeling_syst_conservative(channel) * E(a.val, 0)
    acomp = composition_syst_conservative(channel) * E(a.val, 0)
    full_syst = math.sqrt(a.err**2 + aexp.err**2 + amodel.err**2 + acomp.err**2)
    return E(a.val, full_syst)

#_______________________________________________________________________________________________________________________________
#TODO error term lacks systematics
# Function to actually extrapolate the yields in control region to the signal region using the extrapolation method
# Input:
#   - channel   = El, Mu, Tau, Neg, Lgt, LL, LT etc.
#   - analysis  = BDT or Cut
#   - systematics  = LepSFUp, BTagSFUp, ...
# Output:
#   - errors.E object type (this object holds the final yield and statistical error of final yield)
def bsrdt(channel, analysis):
    return bcrdt(channel, analysis) * alpha_full_syst(channel, analysis)

#_______________________________________________________________________________________________________________________________
# Function to get the row data for the extrapolation
# Input:
#   - channel   = El, Mu, Tau, Neg, Lgt, LL, LT etc.
#   - analysis  = BDT or Cut
# Output:
#   - B^SR_MC, B^CR_MC, alpha, MC stat, modeling syst, composition syst, expt syst, B^CR_data, B^SR_data
def getRowNumbers(channel, analysis):
    print("------------------")
    print(channel, analysis)
    print("------------------")
    print(tex(bsrmc(channel, analysis)))
    print(tex(bcrmc(channel, analysis)))
    print(tex(alpha(channel, analysis)))
    print("MCstat", texerr(alpha(channel, analysis)))
    print("model", texerr(modeling_syst_conservative(channel)))
    print("comp", texerr(composition_syst_conservative(channel)))
    print("expt", texerr(alpha_expt_syst(channel, analysis)))
    print("full", texerr(alpha_full_syst(channel, analysis)))
    print(tex(bcrdt(channel, analysis)))
    print(tex(bsrdt(channel, analysis)))

#_______________________________________________________________________________________________________________________________
# Function to print the relevant numbers for a given extrapolation and systematics
# Input:
#   - channel   = El, Mu, Tau, Neg, Lgt, LL, LT etc.
#   - analysis  = BDT or Cut
#   - systematics  = LepSFUp, BTagSFUp, ...
# Output:
#   - B^SR_MC, B^CR_MC, alphc, MC stat, modeling syst, composition syst, expt syst, B^CR_data, B^SR_data
def printNumbers(channel, analysis, systematics=""):
    print("------------------")
    print(channel, analysis, systematics)
    print("Type   ", "numbers")
    print("------------------")
    print("B_SR_MC", tex(bsrmc(channel, analysis, systematics)))
    print("B_CR_MC", tex(bcrmc(channel, analysis, systematics)))
    print("Alpha  ", tex(alpha(channel, analysis, systematics)))
    print("B_CR_DT", tex(bcrdt(channel, analysis, systematics)))
    print("B_SR_DT", tex(bsrdt(channel, analysis, systematics)))


#_______________________________________________________________________________________________________________________________
# Get tex table with the alpha extrapolations
def get_str_cut():
    vals = [
            "($B^\\textrm{{SR}}_\\textrm{{MC}}$\\quad\\quad /",
            "$B^\\textrm{{CR}}_\\textrm{{MC}}$ =",
            "$\\alpha_\\textrm{{exp}}$(MC Stat. $\\oplus$ Modeling Syst. $\\oplus$ Composition Syst. $\\oplus$ Expt. Syst.))\\quad\\quad $\\times$ ",
            "$B^\\textrm{{CR}}_\\textrm{{data}}$  \\quad\\quad=",
            "$B^\\textrm{{SR}}_\\textrm{{data}}$",
            ]
    analysis = "Cut"
    for channel in ["El", "Mu", "Tau", "Neg", "Lgt"]:
        vals.append(tex(bsrmc(channel, analysis)))
        vals.append(tex(bcrmc(channel, analysis)))
        vals.append(tex(E(alpha(channel, analysis).val, alpha_full_syst(channel, analysis).err)))
        vals.append(texerr(alpha(channel, analysis))) # MC stat
        vals.append(texerr(modeling_syst_conservative(channel))) # modeling
        vals.append(texerr(composition_syst_conservative(channel))) # composition
        vals.append(texerr(alpha_expt_syst(channel, analysis))) # expt syst
        vals.append(tex(bcrdt(channel, analysis)))
        vals.append(tex(bsrdt(channel, analysis)))

    result = """
\\begin{{sidewaystable}}
\\centering
\\resizebox{{\\columnwidth}}{{!}}{{%
\\begin{{tabular}}{{@{{\\extracolsep{{4pt}}}}lccccc@{{}}}}
\\hline\\hline
  Channels                 & {} & {} & {} & {} & {} \\\\
  \\hline
  $e^{{+}}l^{{+}}$         & {} & {} & {} (={} $\\oplus$ {} $\\oplus$ {} $\\oplus$ {}) & {} & {} \\\\
  $\\mu^{{+}}l^{{+}}$      & {} & {} & {} (={} $\\oplus$ {} $\\oplus$ {} $\\oplus$ {}) & {} & {} \\\\
  $\\tau^{{+}}l^{{+}}$     & {} & {} & {} (={} $\\oplus$ {} $\\oplus$ {} $\\oplus$ {}) & {} & {} \\\\
  $(--)$                   & {} & {} & {} (={} $\\oplus$ {} $\\oplus$ {} $\\oplus$ {}) & {} & {} \\\\
  $\\ell^{{+}}\\ell^{{+}}$ & {} & {} & {} (={} $\\oplus$ {} $\\oplus$ {} $\\oplus$ {}) & {} & {} \\\\
\\hline\\hline
\\end{{tabular}}
}}
\\caption{{\\label{{tab:extrapolationCut}} Extrapolation factors summary for cut-based analysis}}
\\end{{sidewaystable}}
    """.format(*vals)
    return result

#_______________________________________________________________________________________________________________________________
# Get tex table with the alpha extrapolations
def get_str_bdt():
    vals = [
            "($B^\\textrm{{SR}}_\\textrm{{MC}}$\\quad\\quad /",
            "$B^\\textrm{{CR}}_\\textrm{{MC}}$ =",
            "$\\alpha_\\textrm{{exp}}$(MC Stat. $\\oplus$ Modeling Syst. $\\oplus$ Composition Syst. $\\oplus$ Expt. Syst.))\\quad\\quad $\\times$ ",
            "$B^\\textrm{{CR}}_\\textrm{{data}}$  \\quad\\quad=",
            "$B^\\textrm{{SR}}_\\textrm{{data}}$",
            ]
    analysis = "BDT"
    for channel in ["El", "Mu", "Tau", "Neg"]:
        vals.append(tex(bsrmc(channel, analysis)))
        vals.append(tex(bcrmc(channel, analysis)))
        vals.append(tex(E(alpha(channel, analysis).val, alpha_full_syst(channel, analysis).err)))
        vals.append(texerr(alpha(channel, analysis))) # MC stat
        vals.append(texerr(modeling_syst_conservative(channel))) # modeling
        vals.append(texerr(composition_syst_conservative(channel))) # composition
        vals.append(texerr(alpha_expt_syst(channel, analysis))) # expt syst
        vals.append(tex(bcrdt(channel, analysis)))
        vals.append(tex(bsrdt(channel, analysis)))

    result = """
\\begin{{sidewaystable}}
\\centering
\\resizebox{{\\columnwidth}}{{!}}{{%
\\begin{{tabular}}{{@{{\\extracolsep{{4pt}}}}lccccc@{{}}}}
\\hline\\hline
  Channels                 & {} & {} & {} & {} & {} \\\\
  \\hline
  $e^{{+}}l^{{+}}$         & {} & {} & {} (={} $\\oplus$ {} $\\oplus$ {} $\\oplus$ {}) & {} & {} \\\\
  $\\mu^{{+}}l^{{+}}$      & {} & {} & {} (={} $\\oplus$ {} $\\oplus$ {} $\\oplus$ {}) & {} & {} \\\\
  $\\tau^{{+}}l^{{+}}$     & {} & {} & {} (={} $\\oplus$ {} $\\oplus$ {} $\\oplus$ {}) & {} & {} \\\\
  $(--)$                   & {} & {} & {} (={} $\\oplus$ {} $\\oplus$ {} $\\oplus$ {}) & {} & {} \\\\
\\hline\\hline
\\end{{tabular}}
}}
\\caption{{\\label{{tab:extrapolationBDT}} Extrapolation factors summary for BDT-based analysis}}
\\end{{sidewaystable}}
    """.format(*vals)
    return result

def make_final_background_histograms():
    rootpath = "{}/topbkgest.root".format(basedir)
    f = r.TFile(rootpath, "recreate")
    h_cut = r.TH1F("LooseVR__CutSR", "", 5, 0, 5)
    h_cut.Sumw2()
    h_cut.SetBinContent(1, bsrdt("El", "Cut").val)
    h_cut.SetBinError  (1, bsrdt("El", "Cut").err)
    h_cut.SetBinContent(2, bsrdt("Mu", "Cut").val)
    h_cut.SetBinError  (2, bsrdt("Mu", "Cut").err)
    h_cut.SetBinContent(3, bsrdt("Tau", "Cut").val)
    h_cut.SetBinError  (3, bsrdt("Tau", "Cut").err)
    h_cut.SetBinContent(4, bsrdt("Neg", "Cut").val)
    h_cut.SetBinError  (4, bsrdt("Neg", "Cut").err)
    h_cut.SetBinContent(5, bsrdt("Lgt", "Cut").val)
    h_cut.SetBinError  (5, bsrdt("Lgt", "Cut").err)
    h_bdt = r.TH1F("LooseVR__BDTSR", "", 4, 0, 4)
    h_bdt.Sumw2()
    h_bdt.SetBinContent(1, bsrdt("El", "BDT").val)
    h_bdt.SetBinError  (1, bsrdt("El", "BDT").err)
    h_bdt.SetBinContent(2, bsrdt("Mu", "BDT").val)
    h_bdt.SetBinError  (2, bsrdt("Mu", "BDT").err)
    h_bdt.SetBinContent(3, bsrdt("Tau", "BDT").val)
    h_bdt.SetBinError  (3, bsrdt("Tau", "BDT").err)
    h_bdt.SetBinContent(4, bsrdt("Neg", "BDT").val)
    h_bdt.SetBinError  (4, bsrdt("Neg", "BDT").err)
    f.cd()
    h_cut.Write()
    h_bdt.Write()
    f.Close()
    print("Saved to {}".format(rootpath))

def make_final_background_histograms_only_MCstatError():
    rootpath = "{}/topbkgfit.root".format(basedir)
    f = r.TFile(rootpath, "recreate")
    h_cut = r.TH1F("LooseVR__CutSR", "", 5, 0, 5)
    h_cut.Sumw2()
    h_cut.SetBinContent(1, bsrdt("El", "Cut").val)
    h_cut.SetBinError  (1, bsrdt("El", "Cut").val * alpha("El", "Cut").err / alpha("El", "Cut").val)
    h_cut.SetBinContent(2, bsrdt("Mu", "Cut").val)
    h_cut.SetBinError  (2, bsrdt("Mu", "Cut").val * alpha("Mu", "Cut").err / alpha("Mu", "Cut").val)
    h_cut.SetBinContent(3, bsrdt("Tau", "Cut").val)
    h_cut.SetBinError  (3, bsrdt("Tau", "Cut").val * alpha("Tau", "Cut").err / alpha("Tau", "Cut").val)
    h_cut.SetBinContent(4, bsrdt("Neg", "Cut").val)
    h_cut.SetBinError  (4, bsrdt("Neg", "Cut").val * alpha("Neg", "Cut").err / alpha("Neg", "Cut").val)
    h_cut.SetBinContent(5, bsrdt("Lgt", "Cut").val)
    h_cut.SetBinError  (5, bsrdt("Lgt", "Cut").val * alpha("Lgt", "Cut").err / alpha("Lgt", "Cut").val)
    h_bdt = r.TH1F("LooseVR__BDTSR", "", 4, 0, 4)
    h_bdt.Sumw2()
    h_bdt.SetBinContent(1, bsrdt("El", "BDT").val)
    h_bdt.SetBinError  (1, bsrdt("El", "BDT").val * alpha("El", "BDT").err / alpha("El", "BDT").val)
    h_bdt.SetBinContent(2, bsrdt("Mu", "BDT").val)
    h_bdt.SetBinError  (2, bsrdt("Mu", "BDT").val * alpha("Mu", "BDT").err / alpha("Mu", "BDT").val)
    h_bdt.SetBinContent(3, bsrdt("Tau", "BDT").val)
    h_bdt.SetBinError  (3, bsrdt("Tau", "BDT").val * alpha("Tau", "BDT").err / alpha("Tau", "BDT").val)
    h_bdt.SetBinContent(4, bsrdt("Neg", "BDT").val)
    h_bdt.SetBinError  (4, bsrdt("Neg", "BDT").val * alpha("Neg", "BDT").err / alpha("Neg", "BDT").val)
    f.cd()
    h_cut.Write()
    h_bdt.Write()
    f.Close()
    print("Saved to {}".format(rootpath))

def get_str_comp():
    vals = [
            "\\aexp (Nominal)",
            "\\aexp (Lowest variation)",
            "$\\Delta\\aexp$",
            "Process varied",
            "\\aexp (Highest variation)",
            "$\\Delta\\aexp$",
            "Process varied",
            ]
    analysis = "Cut"
    for channel in ["Lgt", "Tau", "Neg"]:
        aph = alpha("2"+channel, analysis)
        max_neg_diff, max_neg_type, max_neg_alpha, max_pos_diff, max_pos_type, max_pos_alpha = composition_syst_max(channel, analysis)
        vals.append(tex(aph))
        vals.append("{:.3g}".format(max_neg_alpha.val))
        vals.append("{:.3g}\\%".format((max_neg_alpha.val / aph.val - 1)*100.))
        vals.append("{}".format(proc_pprint(max_neg_type)))
        vals.append("{:.3g}".format(max_pos_alpha.val))
        vals.append("{:.3g}\\%".format((max_pos_alpha.val / aph.val - 1)*100.))
        vals.append("{}".format(proc_pprint(max_pos_type)))
    analysis = "BDT"
    for channel in ["Lgt", "Tau", "Neg"]:
        aph = alpha("2"+channel, analysis)
        max_neg_diff, max_neg_type, max_neg_alpha, max_pos_diff, max_pos_type, max_pos_alpha = composition_syst_max(channel, analysis)
        vals.append(tex(aph))
        vals.append("{:.3g}".format(max_neg_alpha.val))
        vals.append("{:.3g}\\%".format((max_neg_alpha.val / aph.val - 1)*100.))
        vals.append("{}".format(proc_pprint(max_neg_type)))
        vals.append("{:.3g}".format(max_pos_alpha.val))
        vals.append("{:.3g}\\%".format((max_pos_alpha.val / aph.val - 1)*100.))
        vals.append("{}".format(proc_pprint(max_pos_type)))
    result = """\\begin{{sidewaystable}}
\\centering
\\resizebox{{\\columnwidth}}{{!}}{{%
\\begin{{tabular}}{{@{{\\extracolsep{{4pt}}}}lcccccccc@{{}}}}
\\hline\\hline
                & {} & {} & {} & {} & {} & {} & {} \\\\
\\hline
Cut & & & \\\\
~~~~~~\\lgtchan & {} & {} & {} & {} & {} & {} & {} \\\\
~~~~~~\\tauchan & {} & {} & {} & {} & {} & {} & {} \\\\
~~~~~~\\negchan & {} & {} & {} & {} & {} & {} & {} \\\\
BDT & & & \\\\
~~~~~~\\lgtchan & {} & {} & {} & {} & {} & {} & {} \\\\
~~~~~~\\tauchan & {} & {} & {} & {} & {} & {} & {} \\\\
~~~~~~\\negchan & {} & {} & {} & {} & {} & {} & {} \\\\
\\hline\\hline
\\end{{tabular}}   
}}
\\caption{{\\label{{tab:aexpComposition}} Comparing \\aexp values with maximally different \\aexp obtained when varying $\\ttbar+X$ process being varied.  The specific process that led to the largest variations are noted.}}
\\end{{sidewaystable}}
""".format(*vals)
    return result

if __name__ == "__main__":

    plotdir = "{}/plots".format(basedir)
    if not os.path.exists(plotdir):
        os.makedirs(plotdir)

    texpath = "{}/plots/aexp.tex".format(basedir)
    aexp_tex = open(texpath, "w")

    cut_str = get_str_cut()
    bdt_str = get_str_bdt()

    aexp_tex.write(cut_str)
    aexp_tex.write(bdt_str)

    print(cut_str)
    print(bdt_str)

    print("Saved to {}".format(texpath))

    comp_str = get_str_comp()

    texpath = "{}/plots/acomp.tex".format(basedir)
    acomp_tex = open(texpath, "w")

    acomp_tex.write(comp_str)

    print(comp_str)

    print("Saved to {}".format(texpath))

    make_final_background_histograms()
    make_final_background_histograms_only_MCstatError()

    for channel in ["Lgt", "Tau", "Neg"]:
        print(channel, "Cut", modeling_syst(channel, "Cut"))
        print(channel, "BDT", modeling_syst(channel, "BDT"))

