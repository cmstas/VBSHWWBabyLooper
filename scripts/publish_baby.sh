#!/bin/bash

#
# Put the baby into the nfs area
#

# $DIR is the path to the directory where this specific script is sitting
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

# Help
usage()
{
  echo "ERROR - Usage:"
  echo
  echo "      sh $(basename $0) SKIMVERSION BABYVERSION"
  echo
  echo "Arguments:"
  echo "  SKIMVERSION    (e.g. v2.4_SS, v2.4_OS, etc.)"
  echo "  BABYVERSION    (e.g. v1 v2 v3 etc.)"
  echo
  exit
}

if [ -z $1 ]; then usage; fi
if [ -z $2 ]; then usage; fi


SKIMVERSION=$1
BABYVERSION=$2
NFSAREA=/nfs-7/userdata/${USER}/VBSHWWBaby

# Verbose
date
echo "================================================"
echo "$(basename $0) $*"
echo "------------------------------------------------"
echo "SKIMVERSION    : ${SKIMVERSION}"
echo "BABYVERSION    : ${BABYVERSION}"
echo "================================================"

# Create the base directory if it doesn't exist
mkdir -p ${NFSAREA}/${SKIMVERSION}

# Locate the baby dir
BABYDIR=${DIR}/../hadds/${SKIMVERSION}/${BABYVERSION}

# Locate that there is no already baby sitting in nfs (to prevent from overwriting)
if [ -d ${NFSAREA}/${SKIMVERSION}/${BABYVERSION} ]; then
    echo "ERROR: SKIMVERSION=${SKIMVERSION} and BABYVERSION=${BABYVERSION} already exists in nfs area!"
    echo ""
    echo "> ls -l -d "${NFSAREA}/${SKIMVERSION}/${BABYVERSION}""
    ls -l -d "${NFSAREA}/${SKIMVERSION}/${BABYVERSION}"
    echo ""
    echo "If you want to overwrite please delete the directory and retry"
    exit
fi

if [ -d ${BABYDIR} ]; then
    echo "Copying ${BABYDIR} to NFS area"
else
    echo "ERROR: Did not find ${BABYDIR}!"
    echo "Check your SKIMVERSION and BABYVERSION argument!"
    usage
fi
    
cp -r ${BABYDIR} ${NFSAREA}/${SKIMVERSION}

echo "Done!"
