#!/bin/bash

# $DIR is the path to the directory where this specific script is sitting
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

TAG=v1
YEAR=Run2
RUNTAG=Nominal
# RUNTAG=BkgCompStudyv2
SKIMTAG=v2.4_SS
# SYST=LgtTopBkgUp
SYST=

rm -f .plotjobs.txt

book_plot()
{
    PLOTDIR=$1
    REGIONS=$2
    MBBREG=$3
    VARS=$4
    for REGION in ${REGIONS}; do
        HISTNAMES=""
        for VAR in ${VARS}; do
            HISTNAMES="${HISTNAMES} ${REGION}${MBBREG}__${VAR}"
        done
        HISTNAMES=$(echo ${HISTNAMES} | tr ' ' ',')
        echo 'python '${DIR}'/plot.py '${SKIMTAG}' '${YEAR}' '${RUNTAG}' '${TAG}' '${PLOTDIR}' '"${HISTNAMES}"' ' >> .plotjobs.txt;
    done
}

book_plot_alpha()
{
    PLOTDIRS="BkgComp BkgCompIndivid"
    CHANNELS="El Mu Tau Neg Lgt"
    REGIONS="BDTSR BDTSR2 CutSR CutSR2"
# echo ' python scripts/plot_topbkg_compare.py v2.4_SS Run2 Nominal v1 BkgComp LooseVR__BDTSREl       ' >> .plot.jobs.txt
# echo ' python scripts/plot_topbkg_compare.py v2.4_SS Run2 Nominal v1 BkgComp LooseVR__BDTSRMu       ' >> .plot.jobs.txt
# echo ' python scripts/plot_topbkg_compare.py v2.4_SS Run2 Nominal v1 BkgComp LooseVR__BDTSRTau      ' >> .plot.jobs.txt
# echo ' python scripts/plot_topbkg_compare.py v2.4_SS Run2 Nominal v1 BkgComp LooseVR__BDTSRNeg      ' >> .plot.jobs.txt
# echo ' python scripts/plot_topbkg_compare.py v2.4_SS Run2 Nominal v1 BkgComp LooseVR__BDTSRLgt      ' >> .plot.jobs.txt

    for PLOTDIR in ${PLOTDIRS}; do
        for CHANNEL in ${CHANNELS}; do
            for REGION in ${REGIONS}; do
                echo ' python '${DIR}'/plot_topbkg_compare.py '${SKIMTAG}' '${YEAR}' '${RUNTAG}' '${TAG}' '${PLOTDIR}' LooseVR__'${REGION}${CHANNEL}'       ' >> .plot.jobs.txt
            done
        done
    done
}

book_plot VRVarBin    "Lgt Tau Neg"               MbbOff${SYST}     "STVarBin3 STVarBin LTVarBin MJJVarBin DEtaJJVarBin"
book_plot VRShatKine  "Lgt Tau Neg"               MbbOff${SYST}     "LeptonPt0Zoom LeptonPt1Zoom BJetPt0 BJetPt1 MET LT ST"
book_plot VRVBFKine   "Lgt Tau Neg"               MbbOff${SYST}     "MJJZoom DEtaJJ JetPt0 JetPt1 JetEta0 JetEta1"
book_plot VRBDT       "    Tau Neg"               MbbOff${SYST}     "BDTVarBin"
book_plot VRBDT       "Lgt"                       MbbOff${SYST}     "BDTVarBin4"
book_plot SRBDT       "El Mu Tau Neg"             ""${SYST}         "BDT"
book_plot SRYield     "LooseVR"                   ""${SYST}         "BDTSR BDTSR2"
book_plot SRYield     "LooseVR"                   ""${SYST}         "CutSR CutSR2"
book_plot SRBDTKine   "LooseVR"                   ""${SYST}         "ST LT MJJ DEtaJJ Mbb"
book_plot Alpha       "LooseVR"                   ""${SYST}         "CutSREl CutSR2El"
book_plot Alpha       "LooseVR"                   ""${SYST}         "CutSRMu CutSR2Mu"
book_plot Alpha       "LooseVR"                   ""${SYST}         "CutSRTau CutSR2Tau"
book_plot Alpha       "LooseVR"                   ""${SYST}         "CutSRNeg CutSR2Neg"
book_plot Alpha       "LooseVR"                   ""${SYST}         "CutSRLgt"
book_plot Alpha       "LooseVR"                   ""${SYST}         "BDTSREl BDTSR2El"
book_plot Alpha       "LooseVR"                   ""${SYST}         "BDTSRMu BDTSR2Mu"
book_plot Alpha       "LooseVR"                   ""${SYST}         "BDTSRTau BDTSR2Tau"
book_plot Alpha       "LooseVR"                   ""${SYST}         "BDTSRNeg BDTSR2Neg"
book_plot SRKine      "Presel"                    ""                "ST LT Ptbb MJJ DEtaJJ LeptonPt0 LeptonPt1 Mbb"
book_plot Fit         "LooseVR"                   ""${SYST}         "BDTSR"
book_plot Fit         "LooseVR"                   ""${SYST}         "CutSR"
book_plot_alpha

xargs.sh .plotjobs.txt

tar czf plots.tar.gz plots/${RUNTAG}/${SKIMTAG}/${TAG}/${YEAR}/
