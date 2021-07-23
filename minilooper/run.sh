#!/bin/bash

if [ -z $1 ]; then
    echo "Usage:"
    echo ""
    echo "  sh $0 VERSION YEAR"
    echo ""
    echo "     VERSION       Skim version   (e.g. v40)"
    echo "     YEAR          Year           (e.g. 2016, 2017, 2018, or Run2)"
    echo "     RUNTAG        Run tag        (e.g. Date, name, or some specifier)"
    echo "     BABYVERSION   Baby version   (e.g. v1)"
    echo ""
    exit
fi

TAG=${1}
YEAR=${2}
RUNTAG=${3}
BABYVERSION=${4}

HISTDIR=hists/${RUNTAG}/${TAG}/${BABYVERSION}/${YEAR}

mkdir -p ${HISTDIR}

MINIDIR=../hadds/${TAG}/${BABYVERSION}/createMini_${YEAR}

echo "============================"
echo "YEAR      : ${YEAR}"
echo "TAG       : ${TAG}"
echo "RUNTAG    : ${RUNTAG}"
echo "============================"

rm -f .jobs.txt
if [[ ${TAG} == *"v2."* ]]; then
    :
else
    NJOBS=3
    for i in $(seq 0 $((NJOBS-1))); do
        echo "rm -f ${HISTDIR}/tt1l_${i}.root     ; ./doAnalysis -t variable -i ${MINIDIR}/tt1l.root           -o ${HISTDIR}/tt1l_${i}.root         -j ${NJOBS} -I ${i} > ${HISTDIR}/tt1l_${i}.log            2>&1" >> .jobs.txt
    done
    NJOBS=30
    for i in $(seq 0 $((NJOBS-1))); do
        echo "rm -f ${HISTDIR}/tt2l_${i}.root     ; ./doAnalysis -t variable -i ${MINIDIR}/tt2l.root           -o ${HISTDIR}/tt2l_${i}.root         -j ${NJOBS} -I ${i} > ${HISTDIR}/tt2l_${i}.log            2>&1" >> .jobs.txt
    done
fi
NJOBS=3
for i in $(seq 0 $((NJOBS-1))); do
    echo "rm -f ${HISTDIR}/tt1lpowheg_${i}.root   ; ./doAnalysis -t variable -i ${MINIDIR}/tt1lpowheg.root     -o ${HISTDIR}/tt1lpowheg_${i}.root   -j ${NJOBS} -I ${i} > ${HISTDIR}/tt1lpowheg_${i}.log      2>&1" >> .jobs.txt
done
NJOBS=30
for i in $(seq 0 $((NJOBS-1))); do
    echo "rm -f ${HISTDIR}/tt2lpowheg_${i}.root   ; ./doAnalysis -t variable -i ${MINIDIR}/tt2lpowheg.root     -o ${HISTDIR}/tt2lpowheg_${i}.root   -j ${NJOBS} -I ${i} > ${HISTDIR}/tt2lpowheg_${i}.log      2>&1" >> .jobs.txt
done
NJOBS=10
for i in $(seq 0 $((NJOBS-1))); do
    echo "rm -f ${HISTDIR}/ttw_${i}.root          ; ./doAnalysis -t variable -i ${MINIDIR}/ttw.root            -o ${HISTDIR}/ttw_${i}.root          -j ${NJOBS} -I ${i} > ${HISTDIR}/ttw_${i}.log             2>&1" >> .jobs.txt
done
NJOBS=10
for i in $(seq 0 $((NJOBS-1))); do
    echo "rm -f ${HISTDIR}/ttz_${i}.root          ; ./doAnalysis -t variable -i ${MINIDIR}/ttz.root            -o ${HISTDIR}/ttz_${i}.root          -j ${NJOBS} -I ${i} > ${HISTDIR}/ttz_${i}.log             2>&1" >> .jobs.txt
done
NJOBS=20
for i in $(seq 0 $((NJOBS-1))); do
    echo "rm -f ${HISTDIR}/raretop_${i}.root      ; ./doAnalysis -t variable -i ${MINIDIR}/raretop.root        -o ${HISTDIR}/raretop_${i}.root      -j ${NJOBS} -I ${i} > ${HISTDIR}/raretop_${i}.log         2>&1" >> .jobs.txt
done
NJOBS=4
for i in $(seq 0 $((NJOBS-1))); do
    echo "rm -f ${HISTDIR}/bosons_${i}.root       ; ./doAnalysis -t variable -i ${MINIDIR}/bosons.root         -o ${HISTDIR}/bosons_${i}.root       -j ${NJOBS} -I ${i} > ${HISTDIR}/bosons_${i}.log          2>&1" >> .jobs.txt
done
NJOBS=10
for i in $(seq 0 $((NJOBS-1))); do
    echo "rm -f ${HISTDIR}/data_${i}.root         ; ./doAnalysis -t variable -i ${MINIDIR}/data.root           -o ${HISTDIR}/data_${i}.root         -j ${NJOBS} -I ${i} > ${HISTDIR}/data_${i}.log            2>&1" >> .jobs.txt
done
if [[ ${TAG} == *"v2."* ]] || [[ ${TAG}_${YEAR} == *"v70_SS_Run2"* ]]; then
    echo "rm -f ${HISTDIR}/vbshww_c2v_4p5.root    ; ./doAnalysis -t variable -i ${MINIDIR}/vbshww_c2v_4p5.root -o ${HISTDIR}/vbshww_c2v_4p5.root                        > ${HISTDIR}/vbshww_c2v_4p5.log       2>&1" >> .jobs.txt
fi

xargs.sh .jobs.txt

rm -f .haddjobs.txt
echo "hadd -f ${HISTDIR}/raretop.root ${HISTDIR}/raretop_*.root > ${HISTDIR}/raretop.log 2>&1" >> .haddjobs.txt
echo "hadd -f ${HISTDIR}/ttw.root ${HISTDIR}/ttw_*.root > ${HISTDIR}/ttw.log 2>&1" >> .haddjobs.txt
echo "hadd -f ${HISTDIR}/ttz.root ${HISTDIR}/ttz_*.root > ${HISTDIR}/ttz.log 2>&1" >> .haddjobs.txt
echo "hadd -f ${HISTDIR}/bosons.root ${HISTDIR}/bosons_*.root > ${HISTDIR}/bosons.log 2>&1" >> .haddjobs.txt
echo "hadd -f ${HISTDIR}/data.root ${HISTDIR}/data_*.root > ${HISTDIR}/data.log 2>&1" >> .haddjobs.txt
if [[ ${TAG} == *"v2."* ]]; then
    :
else
    echo "hadd -f ${HISTDIR}/tt1l.root ${HISTDIR}/tt1l_*.root > ${HISTDIR}/tt1l.log 2>&1" >> .haddjobs.txt
    echo "hadd -f ${HISTDIR}/tt2l.root ${HISTDIR}/tt2l_*.root > ${HISTDIR}/tt2l.log 2>&1" >> .haddjobs.txt
fi
echo "hadd -f ${HISTDIR}/tt1lpowheg.root ${HISTDIR}/tt1lpowheg_*.root > ${HISTDIR}/tt1lpowheg.log 2>&1" >> .haddjobs.txt
echo "hadd -f ${HISTDIR}/tt2lpowheg.root ${HISTDIR}/tt2lpowheg_*.root > ${HISTDIR}/tt2lpowheg.log 2>&1" >> .haddjobs.txt

xargs.sh .haddjobs.txt

rm -f .haddjobs.txt
echo "hadd -f ${HISTDIR}/totalbkg.root ${HISTDIR}/raretop.root ${HISTDIR}/ttw.root ${HISTDIR}/ttz.root ${HISTDIR}/tt1lpowheg.root ${HISTDIR}/tt2lpowheg.root ${HISTDIR}/bosons.root > ${HISTDIR}/totalbkg.log 2>&1" >> .haddjobs.txt
echo "hadd -f ${HISTDIR}/statbkg.root ${HISTDIR}/raretop.root ${HISTDIR}/ttw.root ${HISTDIR}/ttz.root > ${HISTDIR}/statbkg.log 2>&1" >> .haddjobs.txt
echo "hadd -f ${HISTDIR}/lowstatbkg.root ${HISTDIR}/tt1l.root ${HISTDIR}/tt2l.root > ${HISTDIR}/lowstatbkg.log 2>&1" >> .haddjobs.txt

xargs.sh .haddjobs.txt

