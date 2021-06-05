#!/bin/bash

usage()
{
    echo "Usage:"
    echo ""
    echo "   $ $0 CONDORJOBID"
    echo ""
    echo ""
    exit
}

CONDORJOBID=$1

if [ -z ${CONDORJOBID} ]; then
    usage
fi

CONDOR_JOB_DIR=/tmp/phchang/condor_job_ad_${CONDORJOBID}/

mkdir -p ${CONDOR_JOB_DIR}

CONDOR_JOB_AD=${CONDOR_JOB_DIR}/${CONDORJOBID}.jobad

condor_q -long ${CONDORJOBID} > ${CONDOR_JOB_AD}

function getjobad {
    condor_q -long $2 | grep -i "^$1 =" | cut -d= -f2- | xargs echo
}

cd ${CONDOR_JOB_DIR}

ARGS=$(getjobad Args ${CONDORJOBID})
CMD=$(getjobad Cmd ${CONDORJOBID})
TRANSFERINPUT=$(getjobad TransferInput ${CONDORJOBID})

chmod 755 ${CMD}

echo ${TRANSFERINPUT}

cp ${TRANSFERINPUT} .

_CONDOR_JOB_AD=${CONDOR_JOB_AD} X509_USER_PROXY=/tmp/x509up_u$(id -u ${USER}) $CMD $ARGS

rm -rf ${CONDOR_JOB_DIR}

condor_rm ${CONDORJOBID}
