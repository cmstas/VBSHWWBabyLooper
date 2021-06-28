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
  echo
  exit
}

# Command-line opts
while getopts ":t:s:h" OPTION; do
  case $OPTION in
    s) STUDY=${OPTARG};;
    t) TAG=${OPTARG};;
    h) usage;;
    :) usage;;
  esac
done

if [ -z ${STUDY} ]; then usage; fi
if [ -z ${TAG} ]; then usage; fi

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
echo "================================================"

sh $DIR/exec_v3.sh ${STUDY} ${TAG}
sh $DIR/hadd_v3.sh ${STUDY} ${TAG}
