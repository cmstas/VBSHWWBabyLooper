#!/bin/bash

rm -rf .jobs.txt
for i in $(condor_q -af ClusterId ProcId | tr ' ' '.'); do
    echo "sh run_condor_job_locally.sh ${i} > logs/${i}.log" >> .jobs.txt
done

xargs.sh .jobs.txt
