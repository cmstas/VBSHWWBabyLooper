#!/bin/bash

if [ -z $1 ]; then
    echo "Usage:"
    echo ""
    echo "  sh $0 YOURTAG [SKIMVERSION=v2.4_SS] [BABYVERSION=v3] [YEAR=Run2] [USERNAME=phchang]"
    echo ""
    echo "     YOURTAG       Minilooper run tag       (e.g. Date, name, or some specifier. Provide something you want to keep it unique)"
    echo "     SKIMVERSION   Skim version             (e.g. v2.4_SS                      [Default=v2.4_SS])"
    echo "     BABYVERSION   Baby version             (e.g. v3                           [Default=v3])"
    echo "     YEAR          Year                     (e.g. 2016, 2017, 2018, or Run2    [Default=Run2])"
    echo "     USERNAME      Username of baby creator (e.g. phchang                      [Default=phchang] )"
    echo ""
    exit
fi

YOURTAG=${1}
SKIMVERSION=${2}
BABYVERSION=${3}
YEAR=${4}
USERNAME=${5}
if [ -z ${SKIMVERSION} ]; then
    SKIMVERSION=v2.4_SS
fi
if [ -z ${BABYVERSION} ]; then
    BABYVERSION=v3
fi
if [ -z ${YEAR} ]; then
    YEAR=Run2
fi
if [ -z ${USERNAME} ]; then
    USERNAME=phchang
fi

HISTDIR=hists/${YOURTAG}/${SKIMVERSION}/${BABYVERSION}/${YEAR}

mkdir -p ${HISTDIR}

MINIDIR=/nfs-7/userdata/${USERNAME}/VBSHWWBaby/${SKIMVERSION}/${BABYVERSION}/createMini_${YEAR}

echo "============================"
echo "YOURTAG      : ${YOURTAG}"
echo "SKIMVERSION  : ${SKIMVERSION}"
echo "BABYVERSION  : ${BABYVERSION}"
echo "YEAR         : ${YEAR}"
echo "USERNAME     : ${USERNAME}"
echo "============================"

rm -f .jobs.txt
if [[ ${SKIMVERSION} == *"v2."* ]]; then
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
if [[ ${YEAR} == *"2016"* ]]; then
    :
else
    echo "rm -f ${HISTDIR}/vbshww_c2v_4p5.root   ; ./doAnalysis -t variable -i ${MINIDIR}/vbshww_c2v_4p5.root -o ${HISTDIR}/vbshww_c2v_4p5.root                    > ${HISTDIR}/vbshww_c2v_4p5.log       2>&1" >> .jobs.txt
    echo "rm -f ${HISTDIR}/vbshww_c2v_4.root     ; ./doAnalysis -t variable -i ${MINIDIR}/vbshww_c2v_4.root -o ${HISTDIR}/vbshww_c2v_4.root                        > ${HISTDIR}/vbshww_c2v_4.log       2>&1" >> .jobs.txt
    echo "rm -f ${HISTDIR}/vbshww_c2v_3.root     ; ./doAnalysis -t variable -i ${MINIDIR}/vbshww_c2v_3.root -o ${HISTDIR}/vbshww_c2v_3.root                        > ${HISTDIR}/vbshww_c2v_3.log       2>&1" >> .jobs.txt
    echo "rm -f ${HISTDIR}/vbshww_c2v_1.root     ; ./doAnalysis -t variable -i ${MINIDIR}/vbshww_c2v_1.root -o ${HISTDIR}/vbshww_c2v_1.root                        > ${HISTDIR}/vbshww_c2v_1.log       2>&1" >> .jobs.txt
    echo "rm -f ${HISTDIR}/vbshww_c2v_0.root     ; ./doAnalysis -t variable -i ${MINIDIR}/vbshww_c2v_0.root -o ${HISTDIR}/vbshww_c2v_0.root                        > ${HISTDIR}/vbshww_c2v_0.log       2>&1" >> .jobs.txt
    echo "rm -f ${HISTDIR}/vbshww_c2v_m1.root    ; ./doAnalysis -t variable -i ${MINIDIR}/vbshww_c2v_m1.root -o ${HISTDIR}/vbshww_c2v_m1.root                      > ${HISTDIR}/vbshww_c2v_m1.log       2>&1" >> .jobs.txt
    echo "rm -f ${HISTDIR}/vbshww_c2v_m2.root    ; ./doAnalysis -t variable -i ${MINIDIR}/vbshww_c2v_m2.root -o ${HISTDIR}/vbshww_c2v_m2.root                      > ${HISTDIR}/vbshww_c2v_m2.log       2>&1" >> .jobs.txt
    echo "rm -f ${HISTDIR}/vbshww_c2v_m2p5.root  ; ./doAnalysis -t variable -i ${MINIDIR}/vbshww_c2v_m2p5.root -o ${HISTDIR}/vbshww_c2v_m2p5.root                  > ${HISTDIR}/vbshww_c2v_m2p5.log       2>&1" >> .jobs.txt
fi

xargs.sh .jobs.txt

rm -f .haddjobs.txt
echo "hadd -f ${HISTDIR}/raretop.root ${HISTDIR}/raretop_*.root > ${HISTDIR}/raretop.log 2>&1" >> .haddjobs.txt
echo "hadd -f ${HISTDIR}/ttw.root ${HISTDIR}/ttw_*.root > ${HISTDIR}/ttw.log 2>&1" >> .haddjobs.txt
echo "hadd -f ${HISTDIR}/ttz.root ${HISTDIR}/ttz_*.root > ${HISTDIR}/ttz.log 2>&1" >> .haddjobs.txt
echo "hadd -f ${HISTDIR}/bosons.root ${HISTDIR}/bosons_*.root > ${HISTDIR}/bosons.log 2>&1" >> .haddjobs.txt
echo "hadd -f ${HISTDIR}/data.root ${HISTDIR}/data_*.root > ${HISTDIR}/data.log 2>&1" >> .haddjobs.txt
if [[ ${SKIMVERSION} == *"v2."* ]]; then
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
echo "hadd -f ${HISTDIR}/topbkg_mttw.root ${HISTDIR}/raretop.root ${HISTDIR}/ttz.root ${HISTDIR}/tt1lpowheg.root ${HISTDIR}/tt2lpowheg.root > ${HISTDIR}/totalbkg.log 2>&1" >> .haddjobs.txt
echo "hadd -f ${HISTDIR}/topbkg_pttw.root ${HISTDIR}/raretop.root ${HISTDIR}/ttw.root ${HISTDIR}/ttw.root ${HISTDIR}/ttz.root ${HISTDIR}/tt1lpowheg.root ${HISTDIR}/tt2lpowheg.root > ${HISTDIR}/totalbkg.log 2>&1" >> .haddjobs.txt
echo "hadd -f ${HISTDIR}/topbkg_mttz.root ${HISTDIR}/raretop.root ${HISTDIR}/ttw.root ${HISTDIR}/tt1lpowheg.root ${HISTDIR}/tt2lpowheg.root > ${HISTDIR}/totalbkg.log 2>&1" >> .haddjobs.txt
echo "hadd -f ${HISTDIR}/topbkg_pttz.root ${HISTDIR}/raretop.root ${HISTDIR}/ttz.root ${HISTDIR}/ttz.root ${HISTDIR}/ttw.root ${HISTDIR}/tt1lpowheg.root ${HISTDIR}/tt2lpowheg.root > ${HISTDIR}/totalbkg.log 2>&1" >> .haddjobs.txt
echo "hadd -f ${HISTDIR}/topbkg_mtt1l.root ${HISTDIR}/raretop.root ${HISTDIR}/ttw.root ${HISTDIR}/ttz.root ${HISTDIR}/tt2lpowheg.root > ${HISTDIR}/totalbkg.log 2>&1" >> .haddjobs.txt
echo "hadd -f ${HISTDIR}/topbkg_ptt1l.root ${HISTDIR}/raretop.root ${HISTDIR}/ttw.root ${HISTDIR}/ttz.root ${HISTDIR}/tt1lpowheg.root ${HISTDIR}/tt1lpowheg.root ${HISTDIR}/tt2lpowheg.root > ${HISTDIR}/totalbkg.log 2>&1" >> .haddjobs.txt
echo "hadd -f ${HISTDIR}/topbkg_mtt2l.root ${HISTDIR}/raretop.root ${HISTDIR}/ttw.root ${HISTDIR}/ttz.root ${HISTDIR}/tt1lpowheg.root > ${HISTDIR}/totalbkg.log 2>&1" >> .haddjobs.txt
echo "hadd -f ${HISTDIR}/topbkg_ptt2l.root ${HISTDIR}/raretop.root ${HISTDIR}/ttw.root ${HISTDIR}/ttz.root ${HISTDIR}/tt1lpowheg.root ${HISTDIR}/tt2lpowheg.root ${HISTDIR}/tt2lpowheg.root > ${HISTDIR}/totalbkg.log 2>&1" >> .haddjobs.txt
echo "hadd -f ${HISTDIR}/topbkg_mraretop.root ${HISTDIR}/ttw.root ${HISTDIR}/ttz.root ${HISTDIR}/tt1lpowheg.root ${HISTDIR}/tt2lpowheg.root > ${HISTDIR}/totalbkg.log 2>&1" >> .haddjobs.txt
echo "hadd -f ${HISTDIR}/topbkg_praretop.root ${HISTDIR}/raretop.root ${HISTDIR}/raretop.root ${HISTDIR}/ttw.root ${HISTDIR}/ttz.root ${HISTDIR}/tt1lpowheg.root ${HISTDIR}/tt2lpowheg.root > ${HISTDIR}/totalbkg.log 2>&1" >> .haddjobs.txt
echo "hadd -f ${HISTDIR}/topbkg.root ${HISTDIR}/raretop.root ${HISTDIR}/ttw.root ${HISTDIR}/ttz.root ${HISTDIR}/tt1lpowheg.root ${HISTDIR}/tt2lpowheg.root > ${HISTDIR}/topbkg.log 2>&1" >> .haddjobs.txt
echo "hadd -f ${HISTDIR}/statbkg.root ${HISTDIR}/raretop.root ${HISTDIR}/ttw.root ${HISTDIR}/ttz.root > ${HISTDIR}/statbkg.log 2>&1" >> .haddjobs.txt
echo "hadd -f ${HISTDIR}/lowstatbkg.root ${HISTDIR}/tt1l.root ${HISTDIR}/tt2l.root > ${HISTDIR}/lowstatbkg.log 2>&1" >> .haddjobs.txt

xargs.sh .haddjobs.txt

