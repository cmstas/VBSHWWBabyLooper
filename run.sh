#!/bin/bash

rm -f run.log

# Run the ReReco 2016
time sh scripts/run_v4.sh -s createMini -t v2.3_SS >> run.log 2>&1
# Run the ReReco 2017/2018
time sh scripts/run_UL.sh -s createMini -t v2.3_SS -T v2.3_SS >> run.log 2>&1
