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
# BIN=2

ACCURACYOPTION="--rRelAcc=0.01 "
# ACCURACYOPTION="--rAbsAcc=0.01 --rRelAcc=0.03 " # Mario's options
# ACCURACYOPTION=""

MINIMIZEROPTION="--cminDefaultMinimizerStrategy 0" # 0=Hessian, 1=Minos (nothing = Migrad)
# MINIMIZEROPTION=""

rm -rf .statjobs.txt

# for C2V in ${C2VS}; do
for DATACARD in $(ls datacards/${ANALYSIS}_*.txt); do

    C2V=$(echo ${DATACARD} | sed 's|datacards/'${ANALYSIS}'_c2v||g' | sed 's|_combined.txt||g')

    mkdir -p limits/${TAG}/c2v_${C2V}

    LIMITDIR=limits/${TAG}/c2v_${C2V}

    echo "-----------------------------"
    echo "Booking limit jobs for C2V=${C2V}"

    DATACARD=${DIR}/${DATACARD}

    NTOYS=500
    CMD="combine -M HybridNew --LHCmode LHC-limits --seed -1 -T ${NTOYS} -v 0 ${ACCURACYOPTION} ${MINIMIZEROPTION} --expectedFromGrid=0.5 ${DATACARD}"
    echo "cd $LIMITDIR; $CMD > ${ANALYSIS}_exp.out 2>&1" >> .statjobs.txt

    CMD="combine -M HybridNew --LHCmode LHC-limits --seed -1 -T ${NTOYS} -v 0 ${ACCURACYOPTION} ${MINIMIZEROPTION} --expectedFromGrid=0.84 ${DATACARD}"
    echo "cd $LIMITDIR; $CMD > ${ANALYSIS}_1su.out 2>&1" >> .statjobs.txt

    CMD="combine -M HybridNew --LHCmode LHC-limits --seed -1 -T ${NTOYS} -v 0 ${ACCURACYOPTION} ${MINIMIZEROPTION} --expectedFromGrid=0.16 ${DATACARD}"
    echo "cd $LIMITDIR; $CMD > ${ANALYSIS}_1sd.out 2>&1" >> .statjobs.txt

    CMD="combine -M HybridNew --LHCmode LHC-limits --seed -1 -T ${NTOYS} -v 0 ${ACCURACYOPTION} ${MINIMIZEROPTION} --expectedFromGrid=0.975 ${DATACARD}"
    echo "cd $LIMITDIR; $CMD > ${ANALYSIS}_2su.out 2>&1" >> .statjobs.txt

    CMD="combine -M HybridNew --LHCmode LHC-limits --seed -1 -T ${NTOYS} -v 0 ${ACCURACYOPTION} ${MINIMIZEROPTION} --expectedFromGrid=0.025 ${DATACARD}"
    echo "cd $LIMITDIR; $CMD > ${ANALYSIS}_2sd.out 2>&1" >> .statjobs.txt

done
