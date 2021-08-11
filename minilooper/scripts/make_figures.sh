#!/bin/bash

# $DIR is the path to the directory where this specific script is sitting
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

if [ -z $1 ]; then
    echo "Usage:"
    echo ""
    echo "  sh $0 YOURTAG [SKIMVERSION=v2.4_SS] [BABYVERSION=v3] [YEAR=Run2]"
    echo ""
    echo "     YOURTAG       Minilooper run tag       (e.g. Date, name, or some specifier. Provide something you want to keep it unique)"
    echo "     SKIMVERSION   Skim version             (e.g. v2.4_SS                      [Default=v2.4_SS])"
    echo "     BABYVERSION   Baby version             (e.g. v3                           [Default=v3])"
    echo "     YEAR          Year                     (e.g. 2016, 2017, 2018, or Run2    [Default=Run2])"
    echo "     USERNAME      User name                (e.g. phchang                      [Default=phchang])"
    echo ""
    exit
fi

YOURTAG=${1}
SKIMVERSION=${2}
BABYVERSION=${3}
YEAR=${4}
USERNAME=${5}
if [ -z ${SKIMVERSION} ]; then
    SKIMVERSION=v2.4_SS
fi
if [ -z ${BABYVERSION} ]; then
    BABYVERSION=v3
fi
if [ -z ${YEAR} ]; then
    YEAR=Run2
fi
if [ -z ${USERNAME} ]; then
    USERNAME=phchang
fi

NFSDIR=/nfs-7/userdata/${USERNAME}/VBSHWWResult/${SKIMVERSION}/${BABYVERSION}/${YEAR}/${YOURTAG}/plots
mkdir -p ${NFSDIR}

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
        echo 'python '${DIR}'/plot.py '${YOURTAG}' '${SKIMVERSION}' '${BABYVERSION}' '${YEAR}' '${USERNAME}' '${PLOTDIR}' '"${HISTNAMES}"' > '${NFSDIR}/${PLOTDIR}.log'' >> .plotjobs.txt;
    done
}

book_plot_alpha()
{
    PLOTDIRS="BkgComp BkgCompIndivid"
    CHANNELS="El Mu Tau Neg Lgt"
    REGIONS="BDTSR BDTSR2 CutSR CutSR2"
    for PLOTDIR in ${PLOTDIRS}; do
        for CHANNEL in ${CHANNELS}; do
            for REGION in ${REGIONS}; do
                echo ' python '${DIR}'/plot_topbkg_compare.py '${SKIMVERSION}' '${YEAR}' '${YOURTAG}' '${BABYVERSION}' '${USERNAME}' '${PLOTDIR}' LooseVR__'${REGION}${CHANNEL}'       '' > '${NFSDIR}/${PLOTDIR}.log'' >> .plotjobs.txt
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
book_plot AnchorYield "MbbOff"                    ""${SYST}         "Channel"
book_plot SRYield     "LooseVR"                   ""${SYST}         "BDTSR BDTSR2"
book_plot SRYield     "LooseVR"                   ""${SYST}         "CutSR CutSR2"
book_plot SRBDTKine   "LL"                        MbbOff${SYST}     "STZoom LTZoom MJJ DEtaJJ Mbb PtbbZoom DEtabb DRbb DPhibb BJetPt0 BJetPt1 DRJJ PtJJ JetE0 JetE1 Mll DPhill DRll Ptll LeptonPt0Zoom LeptonPt1Zoom MET MTVVH"
book_plot SRBDTKine   "LT"                        MbbOff${SYST}     "STZoom LTZoom MJJ DEtaJJ Mbb PtbbZoom DEtabb DRbb DPhibb BJetPt0 BJetPt1 DRJJ PtJJ JetE0 JetE1 Mll DPhill DRll Ptll LeptonPt0Zoom LeptonPt1Zoom MET MTVVH"
book_plot Alpha       "LooseVR"                   ""${SYST}         "CutSREl CutSR2El"
book_plot Alpha       "LooseVR"                   ""${SYST}         "CutSRMu CutSR2Mu"
book_plot Alpha       "LooseVR"                   ""${SYST}         "CutSRTau CutSR2Tau"
book_plot Alpha       "LooseVR"                   ""${SYST}         "CutSRNeg CutSR2Neg"
book_plot Alpha       "LooseVR"                   ""${SYST}         "CutSRLgt"
book_plot Alpha       "LooseVR"                   ""${SYST}         "BDTSREl BDTSR2El"
book_plot Alpha       "LooseVR"                   ""${SYST}         "BDTSRMu BDTSR2Mu"
book_plot Alpha       "LooseVR"                   ""${SYST}         "BDTSRTau BDTSR2Tau"
book_plot Alpha       "LooseVR"                   ""${SYST}         "BDTSRNeg BDTSR2Neg"
book_plot SRKine      "Presel"                    ""                "ST LT Ptbb MJJ DEtaJJ LeptonPt0 LeptonPt1 Mbb MbbZoom"
book_plot Fit         "LooseVR"                   ""${SYST}         "BDTSR"
book_plot Fit         "LooseVR"                   ""${SYST}         "CutSR"
book_plot_alpha

xargs.sh .plotjobs.txt

cd /nfs-7/userdata/phchang/VBSHWWResult/${SKIMVERSION}/${BABYVERSION}/${YEAR}/${YOURTAG}/
tar czf plots.tar.gz plots/
cd - > /dev/null
cp /nfs-7/userdata/phchang/VBSHWWResult/${SKIMVERSION}/${BABYVERSION}/${YEAR}/${YOURTAG}/plots.tar.gz .

echo "Plots are here: /nfs-7/userdata/phchang/VBSHWWResult/${SKIMVERSION}/${BABYVERSION}/${YEAR}/${YOURTAG}/"
echo "Tarball of the plots are here: plots.tar.gz"
