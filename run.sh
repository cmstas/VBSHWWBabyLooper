#!/bin/bash

if [ -z ${1} ]; then
    echo "Usage:"
    echo ""
    echo "   sh $0 BABYVERSIONTAG"
    echo ""
    exit
fi

rm -f run.log

# Run the ReReco 2016
time sh scripts/run_v4.sh -a ${1} -s createMini -t v2.4_SS | tee -a run.log 2>&1
# Run the ReReco 2017/2018
time sh scripts/run_UL.sh -a ${1} -s createMini -t v2.4_SS -T v2.4_SS | tee -a run.log 2>&1

# # Run the ReReco 2016
# time sh scripts/run_v4.sh -a ${1} -s createMini -t v2.4_OS | tee -a run.log 2>&1
# # Run the ReReco 2017/2018
# time sh scripts/run_UL.sh -a ${1} -s createMini -t v2.4_OS -T v2.4_OS | tee -a run.log 2>&1
