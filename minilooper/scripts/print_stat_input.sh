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
    BABYVERSION=v3
fi
if [ -z ${YEAR} ]; then
    YEAR=Run2
fi

PLOTNAME=LooseVR__BDTSR
python ../rooutil/yield_for_keynote.py plots/${RUNTAG}/${TAG}/${BABYVERSION}/Run2/SRYield/${PLOTNAME}.txt | tr ',' ' ' | col 26 | tail -n 4 | head -n 4 | echo "sigs    = ["$(paste -d"," - - - -)"]"
python ../rooutil/yield_for_keynote.py plots/${RUNTAG}/${TAG}/${BABYVERSION}/Run2/SRYield/${PLOTNAME}.txt | tr ',' ' ' | col 28 | tail -n 4 | head -n 4 | echo "sigerrs = ["$(paste -d"," - - - -)"]"
python ../rooutil/yield_for_keynote.py plots/${RUNTAG}/${TAG}/${BABYVERSION}/Run2/SRYield/${PLOTNAME}.txt | tr ',' ' ' | col 20 | tail -n 4 | head -n 4 | echo "bkgs    = ["$(paste -d"," - - - -)"]"
python ../rooutil/yield_for_keynote.py plots/${RUNTAG}/${TAG}/${BABYVERSION}/Run2/SRYield/${PLOTNAME}.txt | tr ',' ' ' | col 22 | tail -n 4 | head -n 4 | echo "bkgerrs = ["$(paste -d"," - - - -)"]"

PLOTNAME=LooseVR__CutSR
python ../rooutil/yield_for_keynote.py plots/${RUNTAG}/${TAG}/${BABYVERSION}/Run2/SRYield/${PLOTNAME}.txt | tr ',' ' ' | col 26 | tail -n 5 | head -n 5 | echo "sigs    = ["$(paste -d"," - - - - -)"]"
python ../rooutil/yield_for_keynote.py plots/${RUNTAG}/${TAG}/${BABYVERSION}/Run2/SRYield/${PLOTNAME}.txt | tr ',' ' ' | col 28 | tail -n 5 | head -n 5 | echo "sigerrs = ["$(paste -d"," - - - - -)"]"
python ../rooutil/yield_for_keynote.py plots/${RUNTAG}/${TAG}/${BABYVERSION}/Run2/SRYield/${PLOTNAME}.txt | tr ',' ' ' | col 20 | tail -n 5 | head -n 5 | echo "bkgs    = ["$(paste -d"," - - - - -)"]"
python ../rooutil/yield_for_keynote.py plots/${RUNTAG}/${TAG}/${BABYVERSION}/Run2/SRYield/${PLOTNAME}.txt | tr ',' ' ' | col 22 | tail -n 5 | head -n 5 | echo "bkgerrs = ["$(paste -d"," - - - - -)"]"
