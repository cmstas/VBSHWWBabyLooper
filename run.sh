#!/bin/bash

# $DIR is the path to the directory where this specific script is sitting
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

# Help
usage()
{
  echo "ERROR - Usage:"
  echo
  echo "      sh $(basename $0) OPTIONSTRINGS ..."
  echo
  echo "Options with arguments:"
  echo "  -h    Help                                          (Display this message)"
  echo "  -t    skim ntup version tag                         (Skimmed ntuple tag e.g. v2.5_SS)"
  echo "  -a    baby ntup version tag                         (Baby ntuple version tag)"
  echo ""
  echo "Optional options with arguments:"
  echo "  -s    study name               [DEFAULT=createMini] (Name of the studiy in studies/ e.g. mainAnalysis, extraJets, philipSR, etc.)"
  echo "  -S    Run specific sample ONLY [DEFAULT=all]        (Specific sample)"
  echo ""
  echo "Optional options with no arguments:"
  echo "  -d    Debug run                                     (Runs only a subset of the events)"
  echo
  exit
}

# Command-line opts
while getopts ":a:t:S:s:dh" OPTION; do
  case $OPTION in
    s) STUDY=${OPTARG};;
    S) SPECIFICSAMPLE=${OPTARG};;
    t) SKIMVERSION=${OPTARG};;
    a) BABYVERSION=${OPTARG};;
    d) DEBUG=true;;
    h) usage;;
    :) usage;;
  esac
done

if [ -z ${STUDY} ]; then STUDY=createMini; fi
if [ -z ${SKIMVERSION} ]; then usage; fi
if [ -z ${BABYVERSION} ]; then usage; fi
if [ -z ${SPECIFICSAMPLE} ]; then SPECIFICSAMPLE=all; fi

# to shift away the parsed options
shift $(($OPTIND - 1))

# Verbose
date
echo "================================================"
echo "$(basename $0) $*"
echo "$(basename $0) $*" >> $DIR/.$(basename $0).history
echo "------------------------------------------------"
echo "STUDY          : ${STUDY}"
echo "SKIMVERSION    : ${SKIMVERSION}"
echo "BABYVERSION    : ${BABYVERSION}"
echo "DEBUG          : ${DEBUG}"
echo "SPECIFICSAMPLE : ${SPECIFICSAMPLE}"
echo "================================================"

EXTRA=${SPECIFICSAMPLE}
EXTRA="-S ${SPECIFICSAMPLE}"

if [[ ${DEBUG} == *"true"* ]]; then
    EXTRA="-d ${EXTRA}"
fi

rm -f run.log

#---------------------
# Mini Ntuple creation
#---------------------
# Run the ReReco 2016
time sh scripts/run_v4.sh -a ${BABYVERSION} -s ${STUDY} -t ${SKIMVERSION} ${EXTRA} | tee -a run.log 2>&1
# Run the Ultra-Legacy 2017/2018
time sh scripts/run_UL.sh -a ${BABYVERSION} -s ${STUDY} -t ${SKIMVERSION} ${EXTRA} | tee -a run.log 2>&1
# Merge ReReco2016 with UL 2017/2018
time sh scripts/merge_all_years.sh -a ${BABYVERSION} -s ${STUDY} -t ${SKIMVERSION} -T ${SKIMVERSION} | tee -a run.log 2>&1
