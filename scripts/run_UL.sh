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
  echo "  -h    Help                   (Display this message)"
  echo "  -s    study name             (Name of the studiy in studies/ e.g. mainAnalysis, extraJets, philipSR, etc.)"
  echo "  -a    baby ntup version tag  (Baby ntuple version tag)"
  echo "  -t    skim ntup tag UL       (Skimmed ntuple tag e.g. v2.0_SS)"
  echo "  -S    Run specific sample    (Specific sample)"
  echo "  -d    Debug run              (Runs only a subset of the events)"
  echo
  exit
}

# Command-line opts
while getopts ":a:t:S:s:dh" OPTION; do
  case $OPTION in
    s) STUDY=${OPTARG};;
    S) SPECIFICSAMPLE=${OPTARG};;
    t) ULTAG=${OPTARG};;
    a) BABYVERSION=${OPTARG};;
    d) DEBUG=true;;
    h) usage;;
    :) usage;;
  esac
done

if [ -z ${STUDY} ]; then usage; fi
if [ -z ${ULTAG} ]; then usage; fi
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
echo "ULTAG          : ${ULTAG}"
echo "BABYVERSION    : ${BABYVERSION}"
echo "DEBUG          : ${DEBUG}"
echo "SPECIFICSAMPLE : ${SPECIFICSAMPLE}"
echo "================================================"

sh $DIR/exec_UL.sh ${STUDY} ${ULTAG} ${BABYVERSION} ${SPECIFICSAMPLE} ${DEBUG}
sh $DIR/hadd_UL.sh ${STUDY} ${ULTAG} ${BABYVERSION}
