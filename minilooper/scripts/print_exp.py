#!/bin/env python

import math
import ROOT as r
import sys

def usage():

    print("Usage:")
    print("")
    print("")
    print("   > python {} YOURTAG [SKIMVERSION=v2.4_SS] [BABYVERSION=v3] [YEAR=Run2] [USERNAME=phchang]".format(sys.argv[0]))
    print("")
    print("")
    print("     YOURTAG       Minilooper run tag       (e.g. Date, name, or some specifier. Provide something you want to keep it unique)")
    print("     SKIMVERSION   Skim version             (e.g. v2.4_SS                      [Default=v2.4_SS])")
    print("     BABYVERSION   Baby version             (e.g. v3                           [Default=v3])")
    print("     YEAR          Year                     (e.g. 2016, 2017, 2018, or Run2    [Default=Run2])")
    print("     USERNAME      Username of baby creator (e.g. phchang                      [Default=phchang] )")
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
    BABYVERSION="v6"

try:
    YEAR=sys.argv[4]
except:
    YEAR="Run2"

try:
    USERNAME=sys.argv[5]
except:
    USERNAME="phchang"

basedir = "/nfs-7/userdata/{}/VBSHWWResult/{}/{}/{}/{}".format(USERNAME, SKIMVERSION, BABYVERSION, YEAR, YOURTAG)

def bc(proc, channel, region, analysis):
    f = r.TFile("{}/{}.root".format(basedir, proc))
    h = f.Get("LooseVR__{}SR{}".format(analysis, channel))
    if region == "SR":
        return h.GetBinContent(2)
    if region == "CR":
        return h.GetBinContent(1)
    sys.exit("region must be either SR or CR")


def be(proc, channel, region, analysis):
    f = r.TFile("{}/{}.root".format(basedir, proc))
    h = f.Get("LooseVR__{}SR{}".format(analysis, channel))
    if region == "SR":
        return h.GetBinError(2)
    if region == "CR":
        return h.GetBinError(1)
    sys.exit("region must be either SR or CR")

def bsrmc(channel, analysis): return bc("topbkg", channel, "SR", analysis)
def esrmc(channel, analysis): return be("topbkg", channel, "SR", analysis)
def bcrmc(channel, analysis): return bc("topbkg", channel, "CR", analysis)
def ecrmc(channel, analysis): return be("topbkg", channel, "CR", analysis)

def alpha(channel, analysis):
    bSRMC = bsrmc(channel, analysis)
    eSRMC = esrmc(channel, analysis)
    bCRMC = bcrmc(channel, analysis)
    eCRMC = ecrmc(channel, analysis)
    alpha = bSRMC / bCRMC
    return alpha

def error(channel, analysis):
    bSRMC = bsrmc(channel, analysis)
    eSRMC = esrmc(channel, analysis)
    bCRMC = bcrmc(channel, analysis)
    eCRMC = ecrmc(channel, analysis)
    error = math.sqrt((eSRMC / bSRMC)**2 + (eCRMC / bCRMC)**2) * alpha(channel, analysis)
    return error

def bcrdt(channel, analysis): return bc("data", channel, "CR", analysis) - bc("bosons", channel, "CR", analysis)
def ecrdt(channel, analysis): return math.sqrt(be("data", channel, "CR", analysis)**2 + be("bosons", channel, "CR", analysis)**2)

def bsrdt(channel, analysis): return bcrdt(channel, analysis) * alpha(channel, analysis)
def esrdt(channel, analysis):
    percent_error = math.sqrt((ecrdt(channel, analysis) / bcrdt(channel, analysis))**2 + (error(channel, analysis) / alpha(channel, analysis))**2)
    Syst1 = syst1(channel, analysis)
    Syst2 = syst2(channel, analysis)
    return math.sqrt(percent_error**2 + Syst1**2 + Syst2**2) * bsrdt(channel, analysis)

def syst1(channel, analysis):
    syst1 = 0.01
    syst2 = 0.01
    if analysis == "Cut":
        if channel == "El":
            syst1 = 0.25
            syst2 = 0.11
        elif channel == "Mu":
            syst1 = 0.25
            syst2 = 0.11
        elif channel == "Tau":
            syst1 = 0.45
            syst2 = 0.12
        elif channel == "Neg":
            syst1 = 0.70
            syst2 = 0.16
        elif channel == "Lgt":
            syst1 = 0.25
            syst2 = 0.11
    else:
        if channel == "El":
            syst1 = 0.32
            syst2 = 0.11
        elif channel == "Mu":
            syst1 = 0.32
            syst2 = 0.11
        elif channel == "Tau":
            syst1 = 0.45
            syst2 = 0.12
        elif channel == "Neg":
            syst1 = 0.70
            syst2 = 0.16
    return syst1

def syst2(channel, analysis):
    syst1 = 0.01
    syst2 = 0.01
    if analysis == "Cut":
        if channel == "El":
            syst1 = 0.25
            syst2 = 0.11
        elif channel == "Mu":
            syst1 = 0.25
            syst2 = 0.11
        elif channel == "Tau":
            syst1 = 0.45
            syst2 = 0.12
        elif channel == "Neg":
            syst1 = 0.70
            syst2 = 0.16
        elif channel == "Lgt":
            syst1 = 0.25
            syst2 = 0.11
    else:
        if channel == "El":
            syst1 = 0.32
            syst2 = 0.11
        elif channel == "Mu":
            syst1 = 0.32
            syst2 = 0.11
        elif channel == "Tau":
            syst1 = 0.45
            syst2 = 0.12
        elif channel == "Neg":
            syst1 = 0.70
            syst2 = 0.16
    return syst2

def get(channel, analysis):
    bSRMC = bsrmc(channel, analysis)
    eSRMC = esrmc(channel, analysis)
    bCRMC = bcrmc(channel, analysis)
    eCRMC = ecrmc(channel, analysis)
    Alpha = alpha(channel, analysis)
    Error = error(channel, analysis)
    bCRDT = bcrdt(channel, analysis)
    eCRDT = ecrdt(channel, analysis)
    bSRDT = bsrdt(channel, analysis)
    eSRDT = esrdt(channel, analysis)
    fSRDT = eSRDT / bSRDT
    return [bSRMC, eSRMC, bCRMC, eCRMC, Alpha, (Error/Alpha)* 100, syst1(channel, analysis)*100, syst2(channel, analysis)*100, 999, bCRDT, eCRDT, bSRDT, eSRDT, fSRDT*100,]


def get_str_cut():
    numbers = get("El", "Cut") + get("Mu", "Cut") + get("Tau", "Cut") + get("Neg", "Cut") + get("Lgt", "Cut")
    result = """
\\begin{{table}}[H]
\\centering
\\resizebox{{\\columnwidth}}{{!}}{{%
\\begin{{tabular}}{{@{{\\extracolsep{{4pt}}}}lccccc@{{}}}}
\\hline\\hline
  Channels                 & ($B^\\textrm{{SR}}_\\textrm{{MC}}$\\quad\\quad / & $B^\\textrm{{CR}}_\\textrm{{MC}}$ = & $\\alpha_\\textrm{{exp}}$(MC Stat. $\\oplus$ Modeling Syst. $\\oplus$ Composition Syst. $\\oplus$ Expt. Syst.))\\quad\\quad $\\times$      & $B^\\textrm{{CR}}_\\textrm{{data}}$  \\quad\\quad= & $B^\\textrm{{SR}}_\\textrm{{data}}$       \\\\
  \\hline
  $e^{{+}}l^{{+}}$         & {:.3g} $\\pm$ {:.3g}                             & {:.3g} $\\pm$ {:.3g}                & {:.3g} $\\pm$ ({:.3g}\\% $\\oplus$ {:.3g}\\% $\\oplus$ {:.3g}\\% $\\oplus$ {:.3g}\\%) & {:.3g} $\\pm$ {:.3g}                               & {:.3g} $\\pm$ {:.3g} (={:.3g}\\%)                 \\\\
  $\\mu^{{+}}l^{{+}}$      & {:.3g} $\\pm$ {:.3g}                             & {:.3g} $\\pm$ {:.3g}                & {:.3g} $\\pm$ ({:.2g}\\% $\\oplus$ {:.3g}\\% $\\oplus$ {:.3g}\\% $\\oplus$ {:.3g}\\%) & {:.3g} $\\pm$ {:.3g}                               & {:.3g} $\\pm$ {:.3g} (={:.3g}\\%)                 \\\\
  $\\tau^{{+}}l^{{+}}$     & {:.3g} $\\pm$ {:.3g}                             & {:.3g} $\\pm$ {:.3g}                & {:.3g} $\\pm$ ({:.2g}\\% $\\oplus$ {:.3g}\\% $\\oplus$ {:.3g}\\% $\\oplus$ {:.3g}\\%) & {:.3g} $\\pm$ {:.3g}                               & {:.3g} $\\pm$ {:.3g} (={:.3g}\\%)                 \\\\
  $(--)$                   & {:.3g} $\\pm$ {:.3g}                             & {:.3g} $\\pm$ {:.3g}                & {:.3g} $\\pm$ ({:.2g}\\% $\\oplus$ {:.3g}\\% $\\oplus$ {:.3g}\\% $\\oplus$ {:.3g}\\%) & {:.3g} $\\pm$ {:.3g}                               & {:.3g} $\\pm$ {:.3g} (={:.3g}\\%)                 \\\\
  $\\ell^{{+}}\\ell^{{+}}$ & {:.3g} $\\pm$ {:.3g}                             & {:.3g} $\\pm$ {:.3g}                & {:.3g} $\\pm$ ({:.2g}\\% $\\oplus$ {:.3g}\\% $\\oplus$ {:.3g}\\% $\\oplus$ {:.3g}\\%) & {:.3g} $\\pm$ {:.3g}                               & {:.3g} $\\pm$ {:.3g} (={:.3g}\\%)                 \\\\
\\hline\\hline
\\end{{tabular}}
}}
\\caption{{\\label{{tab:extrapolationCut}} Extrapolation factors summary for cut-based analysis}}
\\end{{table}}
    """.format(*numbers)
    return result

def get_str_bdt():
    numbers = get("El", "BDT") + get("Mu", "BDT") + get("Tau", "BDT") + get("Neg", "BDT")
    result = """
\\begin{{table}}[H]
\\centering
\\resizebox{{\\columnwidth}}{{!}}{{%
\\begin{{tabular}}{{@{{\\extracolsep{{4pt}}}}lccccc@{{}}}}
\\hline\\hline
  Channels                 & ($B^\\textrm{{SR}}_\\textrm{{MC}}$\\quad\\quad / & $B^\\textrm{{CR}}_\\textrm{{MC}}$ = & $\\alpha_\\textrm{{exp}}$(MC Stat. $\\oplus$ Modeling Syst. $\\oplus$ Composition Syst. $\\oplus$ Expt. Syst.))\\quad\\quad $\\times$      & $B^\\textrm{{CR}}_\\textrm{{data}}$  \\quad\\quad= & $B^\\textrm{{SR}}_\\textrm{{data}}$       \\\\
  \\hline
  $e^{{+}}l^{{+}}$         & {:.3g} $\\pm$ {:.3g}                             & {:.3g} $\\pm$ {:.3g}                & {:.3g} $\\pm$ ({:.2g}\\% $\\oplus$ {:.3g}\\% $\\oplus$ {:.3g}\\% $\\oplus$ {:.3g}\\%) & {:.3g} $\\pm$ {:.3g}                               & {:.3g} $\\pm$ {:.3g} (={:.3g}\\%)                 \\\\
  $\\mu^{{+}}l^{{+}}$      & {:.3g} $\\pm$ {:.3g}                             & {:.3g} $\\pm$ {:.3g}                & {:.3g} $\\pm$ ({:.2g}\\% $\\oplus$ {:.3g}\\% $\\oplus$ {:.3g}\\% $\\oplus$ {:.3g}\\%) & {:.3g} $\\pm$ {:.3g}                               & {:.3g} $\\pm$ {:.3g} (={:.3g}\\%)                 \\\\
  $\\tau^{{+}}l^{{+}}$     & {:.3g} $\\pm$ {:.3g}                             & {:.3g} $\\pm$ {:.3g}                & {:.3g} $\\pm$ ({:.2g}\\% $\\oplus$ {:.3g}\\% $\\oplus$ {:.3g}\\% $\\oplus$ {:.3g}\\%) & {:.3g} $\\pm$ {:.3g}                               & {:.3g} $\\pm$ {:.3g} (={:.3g}\\%)                 \\\\
  $(--)$                   & {:.3g} $\\pm$ {:.3g}                             & {:.3g} $\\pm$ {:.3g}                & {:.3g} $\\pm$ ({:.2g}\\% $\\oplus$ {:.3g}\\% $\\oplus$ {:.3g}\\% $\\oplus$ {:.3g}\\%) & {:.3g} $\\pm$ {:.3g}                               & {:.3g} $\\pm$ {:.3g} (={:.3g}\\%)                 \\\\
\\hline\\hline
\\end{{tabular}}
}}
\\caption{{\\label{{tab:extrapolationBDT}} Extrapolation factors summary for BDT-based analysis}}
\\end{{table}}
    """.format(*numbers)
    return result

def make_final_background_histograms():
    f = r.TFile("{}/topbkgest.root".format(basedir), "recreate")
    h_cut = r.TH1F("LooseVR__CutSR", "", 5, 0, 5)
    h_cut.Sumw2()
    h_cut.SetBinContent(1, get("El", "Cut")[-3])
    h_cut.SetBinError  (1, get("El", "Cut")[-2])
    h_cut.SetBinContent(2, get("Mu", "Cut")[-3])
    h_cut.SetBinError  (2, get("Mu", "Cut")[-2])
    h_cut.SetBinContent(3, get("Tau", "Cut")[-3])
    h_cut.SetBinError  (3, get("Tau", "Cut")[-2])
    h_cut.SetBinContent(4, get("Neg", "Cut")[-3])
    h_cut.SetBinError  (4, get("Neg", "Cut")[-2])
    h_cut.SetBinContent(5, get("Lgt", "Cut")[-3])
    h_cut.SetBinError  (5, get("Lgt", "Cut")[-2])
    h_bdt = r.TH1F("LooseVR__BDTSR", "", 4, 0, 4)
    h_bdt.Sumw2()
    h_bdt.SetBinContent(1, get("El", "BDT")[-3])
    h_bdt.SetBinError  (1, get("El", "BDT")[-2])
    h_bdt.SetBinContent(2, get("Mu", "BDT")[-3])
    h_bdt.SetBinError  (2, get("Mu", "BDT")[-2])
    h_bdt.SetBinContent(3, get("Tau", "BDT")[-3])
    h_bdt.SetBinError  (3, get("Tau", "BDT")[-2])
    h_bdt.SetBinContent(4, get("Neg", "BDT")[-3])
    h_bdt.SetBinError  (4, get("Neg", "BDT")[-2])
    f.cd()
    h_cut.Write()
    h_bdt.Write()
    f.Close()

def make_final_background_histograms_only_MCstatError():
    f = r.TFile("{}/topbkgfit.root".format(basedir), "recreate")
    h_cut = r.TH1F("LooseVR__CutSR", "", 5, 0, 5)
    h_cut.Sumw2()
    h_cut.SetBinContent(1, get("El", "Cut")[-3])
    h_cut.SetBinError  (1, get("El", "Cut")[-3] * get("El", "Cut")[5] / 100)
    h_cut.SetBinContent(2, get("Mu", "Cut")[-3])
    h_cut.SetBinError  (2, get("Mu", "Cut")[-3] * get("Mu", "Cut")[5] / 100)
    h_cut.SetBinContent(3, get("Tau", "Cut")[-3])
    h_cut.SetBinError  (3, get("Tau", "Cut")[-3] * get("Tau", "Cut")[5] / 100)
    h_cut.SetBinContent(4, get("Neg", "Cut")[-3])
    h_cut.SetBinError  (4, get("Neg", "Cut")[-3] * get("Neg", "Cut")[5] / 100)
    h_cut.SetBinContent(5, get("Lgt", "Cut")[-3])
    h_cut.SetBinError  (5, get("Lgt", "Cut")[-3] * get("Lgt", "Cut")[5] / 100)
    h_bdt = r.TH1F("LooseVR__BDTSR", "", 4, 0, 4)
    h_bdt.Sumw2()
    h_bdt.SetBinContent(1, get("El", "BDT")[-3])
    h_bdt.SetBinError  (1, get("El", "BDT")[-3] * get("El", "BDT")[5] / 100)
    h_bdt.SetBinContent(2, get("Mu", "BDT")[-3])
    h_bdt.SetBinError  (2, get("Mu", "BDT")[-3] * get("Mu", "BDT")[5] / 100)
    h_bdt.SetBinContent(3, get("Tau", "BDT")[-3])
    h_bdt.SetBinError  (3, get("Tau", "BDT")[-3] * get("Tau", "BDT")[5] / 100)
    h_bdt.SetBinContent(4, get("Neg", "BDT")[-3])
    h_bdt.SetBinError  (4, get("Neg", "BDT")[-3] * get("Neg", "BDT")[5] / 100)
    f.cd()
    h_cut.Write()
    h_bdt.Write()
    f.Close()

if __name__ == "__main__":

    print(get_str_cut())
    print(get_str_bdt())

    make_final_background_histograms()
    make_final_background_histograms_only_MCstatError()
