#!/bin/bash

# $DIR is the path to the directory where this specific script is sitting
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

if [ -z $1 ]; then
    echo "Usage:"
    echo ""
    echo "  sh $0 YOURTAG [SKIMVERSION=v2.4_SS] [BABYVERSION=v2] [YEAR=Run2]"
    echo ""
    echo "     YOURTAG       Minilooper run tag       (e.g. Date, name, or some specifier. Provide something you want to keep it unique)"
    echo "     SKIMVERSION   Skim version             (e.g. v2.4_SS                      [Default=v2.4_SS])"
    echo "     BABYVERSION   Baby version             (e.g. v2                           [Default=v2])"
    echo "     YEAR          Year                     (e.g. 2016, 2017, 2018, or Run2    [Default=Run2])"
    echo ""
    exit
fi

YOURTAG=${1}
SKIMVERSION=${2}
BABYVERSION=${3}
YEAR=${4}
if [ -z ${SKIMVERSION} ]; then
    SKIMVERSION=v2.4_SS
fi
if [ -z ${BABYVERSION} ]; then
    BABYVERSION=v2
fi
if [ -z ${YEAR} ]; then
    YEAR=Run2
fi

NFSAREA=/nfs-7/userdata/${USER}/VBSHWWResult/${SKIMVERSION}/${BABYVERSION}/${YEAR}

mkdir -p ${NFSAREA}

if [ -d ${NFSAREA}/${YOURTAG} ]; then
    echo "ERROR: SKIMVERSION=${SKIMVERSION}, BABYVERSION=${BABYVERSION}, YEAR=${YEAR}, and YOURTAG=${YOURTAG} already exists in nfs area!"
    echo ""
    echo "> ls -l -d "${NFSAREA}/${YOURTAG}""
    ls -l -d "${NFSAREA}/${YOURTAG}"
    echo ""
    echo "If you want to overwrite please delete the directory and retry"
    exit
fi

RESULTDIR=${DIR}/../hists/${SKIMVERSION}/${BABYVERSION}/${YEAR}/${YOURTAG}

if [ -d ${RESULTDIR} ]; then
    echo "Copying ${RESULTDIR} to the nfs area"
else
    echo "ERROR! Could not find ${RESULTDIR} check your arguments"
    exit
fi

cp -r ${RESULTDIR}/ ${NFSAREA}/${YOURTAG}
cd ${NFSAREA}/${YOURTAG}

rm ttz_*
rm ttw_*
rm tt2lpowheg_*
rm tt1lpowheg_*
rm raretop_*
rm data_*
rm bosons_*
rm *.log

echo "Done copying to ${NFSAREA}/${YOURTAG}"
