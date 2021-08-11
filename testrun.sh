#!/bin/bash

rm -f testrun.log

#---------------------
# Mini Ntuple creation
#---------------------
# Run the ReReco 2016
time sh scripts/run_v4.sh -d -a testrun -s createMini -t v2.4_SS | tee -a testrun.log 2>&1
# Run the Ultra-Legacy 2017/2018
time sh scripts/run_UL.sh -d -a testrun -s createMini -t v2.4_SS | tee -a testrun.log 2>&1
# Merge ReReco2016 with UL 2017/2018
time sh scripts/merge_all_years.sh -d -a testrun -s createMini -t v2.4_SS -T v2.4_SS | tee -a testrun.log 2>&1
