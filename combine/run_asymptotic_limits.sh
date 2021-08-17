#!/bin/bash

usage()
{
    echo "Usage:"
    echo ""
    echo "   > $0 TAG"
    echo ""
    echo ""
    exit
}

if [ -z $1 ]; then
    usage
fi

TAG=$1

# $DIR is the path to the directory where this specific script is sitting
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

ANALYSIS=bdt
BIN=Combined
COUPLING=c2v

# ACCURACYOPTION="--rAbsAcc=0.01 --rRelAcc=0.03 "
ACCURACYOPTION=""

# MINIMIZEROPTION="--cminDefaultMinimizerStrategy 0" # 0=Hessian, 1=Minos (nothing = Migrad)
MINIMIZEROPTION=""

for DATACARD in $(ls datacards/${ANALYSIS}_${COUPLING}*.txt); do

    COUPL_MOD=$(echo ${DATACARD} | sed 's|datacards/'${ANALYSIS}'_'${COUPLING}'||g' | sed 's|_combined.txt||g')

    mkdir -p limits/${TAG}/${COUPLING}_${COUPL_MOD}

    cd limits/${TAG}/${COUPLING}_${COUPL_MOD}

    echo "-----------------------------"
    echo "Running limits for COUPLING=${COUPLING} and COUPL_MOD=${COUPL_MOD}"

    if [[ "${BIN}" == *"Combined"* ]]; then
        DATACARDS=${DIR}/datacards/${ANALYSIS}_${COUPLING}${COUPL_MOD}_combined.txt
    else
        DATACARDS=${DIR}/datacards/${ANALYSIS}_${COUPLING}${COUPL_MOD}/datacard_bin${BIN}.txt
    fi

    # Example from Mario
    # https://github.com/hardikroutray/displacedscouting_fitscountlimits/blob/master/cleanscripts/cal_limits_vfinal_hzd_toys.py#L321-L335

    # combine -M HybridNew --frequentist --testStat LHC --LHCmode LHC-limits --seed -1 -T 200 -v 0 --fork 15 ${MINIMIZEROPTION}  ${DATACARDS} > com_mass{}_ctau{}_obs.out
    CMD="combine -M AsymptoticLimits ${DATACARDS}"
    echo $CMD
    $CMD > ${ANALYSIS}_exp.out

    cd ../../../

done
