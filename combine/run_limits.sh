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

# ACCURACYOPTION="--rAbsAcc=0.01 --rRelAcc=0.03 "
ACCURACYOPTION=""

# MINIMIZEROPTION="--cminDefaultMinimizerStrategy 0" # 0=Hessian, 1=Minos (nothing = Migrad)
MINIMIZEROPTION=""

# C2Vs to fit
C2VS="0 1 3 4 4p5 m1 m2 m2p5"

for C2V in ${C2VS}; do

    mkdir -p limits/${TAG}/c2v_${C2V}

    cd limits/${TAG}/c2v_${C2V}

    echo "-----------------------------"
    echo "Running limits for C2V=${C2V}"

    if [[ "${BIN}" == *"Combined"* ]]; then
        DATACARDS=${DIR}/datacards/${ANALYSIS}_c2v${C2V}_combined.txt
    else
        DATACARDS=${DIR}/datacards/${ANALYSIS}_c2v${C2V}/datacard_bin${BIN}.txt
    fi

    # Example from Mario
    # https://github.com/hardikroutray/displacedscouting_fitscountlimits/blob/master/cleanscripts/cal_limits_vfinal_hzd_toys.py#L321-L335

    # combine -M HybridNew --frequentist --testStat LHC --LHCmode LHC-limits --seed -1 -T 200 -v 0 --fork 15 ${MINIMIZEROPTION}  ${DATACARDS} > com_mass{}_ctau{}_obs.out
    CMD="combine -M HybridNew --frequentist --testStat LHC --LHCmode LHC-limits --seed -1 -T 200 -v 0 ${ACCURACYOPTION} --fork 15 ${MINIMIZEROPTION} --expectedFromGrid=0.5 ${DATACARDS}"
    echo $CMD
    $CMD > ${ANALYSIS}_exp.out

    CMD="combine -M HybridNew --frequentist --testStat LHC --LHCmode LHC-limits --seed -1 -T 200 -v 0 ${ACCURACYOPTION} --fork 15 ${MINIMIZEROPTION} --expectedFromGrid=0.84 ${DATACARDS}"
    echo $CMD
    $CMD > ${ANALYSIS}_1su.out

    CMD="combine -M HybridNew --frequentist --testStat LHC --LHCmode LHC-limits --seed -1 -T 200 -v 0 ${ACCURACYOPTION} --fork 15 ${MINIMIZEROPTION} --expectedFromGrid=0.16 ${DATACARDS}"
    echo $CMD
    $CMD > ${ANALYSIS}_1sd.out

    CMD="combine -M HybridNew --frequentist --testStat LHC --LHCmode LHC-limits --seed -1 -T 200 -v 0 ${ACCURACYOPTION} --fork 15 ${MINIMIZEROPTION} --expectedFromGrid=0.975 ${DATACARDS}"
    echo $CMD
    $CMD > ${ANALYSIS}_2su.out

    CMD="combine -M HybridNew --frequentist --testStat LHC --LHCmode LHC-limits --seed -1 -T 200 -v 0 ${ACCURACYOPTION} --fork 15 ${MINIMIZEROPTION} --expectedFromGrid=0.025 ${DATACARDS}"
    echo $CMD
    $CMD > ${ANALYSIS}_2sd.out

    cd ../../../

done
