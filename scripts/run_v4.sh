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
  echo "  -t    skim ntup tag          (Skimmed ntuple tag e.g. v20, v30, v40)"
  echo "  -a    baby ntup version tag  (This round of baby ntup version tag)"
  echo "  -S    Run specific sample    (Specific sample)"
  echo "  -d    Debug run              (Runs only a subset of the events)"
  echo
  exit
}

# Command-line opts
while getopts ":a:t:s:S:dh" OPTION; do
  case $OPTION in
    s) STUDY=${OPTARG};;
    S) SPECIFICSAMPLE=${OPTARG};;
    t) TAG=${OPTARG};;
    a) BABYVERSION=${OPTARG};;
    d) DEBUG=true;;
    h) usage;;
    :) usage;;
  esac
done

if [ -z ${STUDY} ]; then usage; fi
if [ -z ${TAG} ]; then usage; fi
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
echo "TAG            : ${TAG}"
echo "BABYVERSION    : ${BABYVERSION}"
echo "DEBUG          : ${DEBUG}"
echo "SPECIFICSAMPLE : ${SPECIFICSAMPLE}"
echo "================================================"

sh $DIR/exec_v4.sh ${STUDY} ${TAG} ${BABYVERSION} ${SPECIFICSAMPLE} ${DEBUG}
sh $DIR/hadd_v4.sh ${STUDY} ${TAG} ${BABYVERSION}
