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
  echo "  -d    nano skim dir          (Path to the NanoSkim outputs)"
  echo
  exit
}

# Command-line opts
while getopts ":d:h" OPTION; do
  case $OPTION in
    d) NANOSKIMDIR=${OPTARG};;
    h) usage;;
    :) usage;;
  esac
done

if [ -z ${NANOSKIMDIR} ]; then usage; fi

# to shift away the parsed options
shift $(($OPTIND - 1))

# Verbose
date
echo "================================================"
echo "$(basename $0) $*"
echo "$(basename $0) $*" >> $DIR/.$(basename $0).history
echo "------------------------------------------------"
echo "NANOSKIMDIR    : ${NANOSKIMDIR}"
echo "================================================"

TAG=$(basename $NANOSKIMDIR)
NFSDIR=/nfs-7/userdata/phchang/VBSHWWNanoSkim_${TAG}/
NSAMPLES=$(ls -d ${NANOSKIMDIR}/* | wc -l)

IDX=1
for SAMPLEDIR in $(ls -d ${NANOSKIMDIR}/*); do
    SAMPLENAME=$(basename ${SAMPLEDIR})
    MERGEDDIR=${NFSDIR}/${SAMPLENAME}/merged/
    mkdir -p ${MERGEDDIR}
    echo "Processing ... ${IDX} / ${NSAMPLES} samples (dataset=${SAMPLENAME})"
    if [ ! -f ${MERGEDDIR}/nevents.txt ]; then
        TOTALNEVENTS=0
        TOTALNEFFEVENTS=0
        for NEVENTSFILE in $(ls $SAMPLEDIR/*_nevents.txt); do
            POSWEIGHTS=$(tail -n 2 $NEVENTSFILE | head -n 1)
            NEGWEIGHTS=$(tail -n 1 $NEVENTSFILE)
            TOTALNEVENTS=$((TOTALNEVENTS + ${POSWEIGHTS}))
            TOTALNEVENTS=$((TOTALNEVENTS + ${NEGWEIGHTS}))
            TOTALNEFFEVENTS=$((TOTALNEFFEVENTS + ${POSWEIGHTS}))
            TOTALNEFFEVENTS=$((TOTALNEFFEVENTS - ${NEGWEIGHTS}))
            # echo ${POSWEIGHTS} ${NEGWEIGHTS}
        done
        echo ${TOTALNEVENTS} > ${MERGEDDIR}/nevents.txt
        echo ${TOTALNEFFEVENTS} >> ${MERGEDDIR}/nevents.txt
    fi
    # hadding
    if [ ! -f ${MERGEDDIR}/output.root ]; then
        CMD="python ${DIR}/haddnano.py ${MERGEDDIR}/output.root ${SAMPLEDIR}/*.root"
        $CMD > ${MERGEDDIR}/output_hadd.log 2>&1
        EXITCODE=$?
        if [ $EXITCODE -ne 0 ]; then
            echo $CMD
            echo "ERROR - Fail to process $SAMPLEDIR"
            exit
        fi
        # rsync -ah --progress output.root ${SAMPLEDIR}/merged/output.root
        # cp -v output.root ${SAMPLEDIR}/merged/output.root
        # SAMPLEDIRPATHNEW=$(echo ${SAMPLEDIR} | sed 's/^.*\(\/store.*\).*$/\1/')
        # COPY_SRC="file://`pwd`/output.root"
        # COPY_DEST="davs://redirector.t2.ucsd.edu:1094/${SAMPLEDIRPATHNEW}/merged/output.root"
        # echo "gfal-copy -p -f -t 4200 --verbose --checksum ADLER32 ${COPY_SRC} ${COPY_DEST}"
        # break
    fi
    IDX=$((IDX + 1))
done
