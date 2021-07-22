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
  echo "  -t    skim ntup tag UL       (Skimmed ntuple tag e.g. v2.0_SS)"
  echo "  -T    skim ntup tag non-UL   (Skimmed ntuple tag e.g. v70_SS)"
  echo "  -d    Debug run              (Runs only a subset of the events)"
  echo
  exit
}

# Command-line opts
while getopts ":t:T:s:dh" OPTION; do
  case $OPTION in
    s) STUDY=${OPTARG};;
    t) ULTAG=${OPTARG};;
    T) v7TAG=${OPTARG};;
    d) DEBUG=true;;
    h) usage;;
    :) usage;;
  esac
done

if [ -z ${STUDY} ]; then usage; fi
if [ -z ${ULTAG} ]; then usage; fi
if [ -z ${v7TAG} ]; then usage; fi

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
echo "v7TAG          : ${v7TAG}"
echo "DEBUG          : ${DEBUG}"
echo "================================================"

sh $DIR/exec_UL.sh ${STUDY} ${ULTAG} ${DEBUG}
sh $DIR/hadd_UL.sh ${STUDY} ${ULTAG}
sh $DIR/special_hadd_UL.sh ${STUDY} ${ULTAG} ${v7TAG}
