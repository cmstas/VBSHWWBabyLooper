#!/bin/bash

if [ -z ${1} ]; then
    echo "Usage:"
    echo ""
    echo "   sh $0 BABYVERSION"
    echo ""
    exit
fi

EXTRA=${2}

if [ -n ${EXTRA} ]; then
    EXTRA="-S ${EXTRA}"
fi

rm -f run.log

#---------------------
# Mini Ntuple creation
#---------------------
# Run the ReReco 2016
time sh scripts/run_v4.sh -a ${1} -s createMini -t v2.4_SS ${EXTRA} | tee -a run.log 2>&1
# Run the Ultra-Legacy 2017/2018
time sh scripts/run_UL.sh -a ${1} -s createMini -t v2.4_SS ${EXTRA} | tee -a run.log 2>&1
# Merge ReReco2016 with UL 2017/2018
time sh scripts/merge_all_years.sh -a ${1} -s createMini -t v2.4_SS -T v2.4_SS | tee -a run.log 2>&1
