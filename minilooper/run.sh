
TAG=v40

HISTDIR=hists/${TAG}

mkdir -p ${HISTDIR}

MINIDIR=../hadds/${TAG}/createMini_Run2

rm -f .jobs.txt
echo "rm -f ${HISTDIR}/tt1l.root          ; ./doAnalysis -t variable -i ${MINIDIR}/tt1l.root           -o ${HISTDIR}/tt1l.root           > ${HISTDIR}/tt1l.log                 2>&1" >> .jobs.txt
echo "rm -f ${HISTDIR}/tt2l_0.root        ; ./doAnalysis -t variable -i ${MINIDIR}/tt2l.root           -o ${HISTDIR}/tt2l_0.root         -j 10 -I 0 > ${HISTDIR}/tt2l_0.log               2>&1" >> .jobs.txt
echo "rm -f ${HISTDIR}/tt2l_1.root        ; ./doAnalysis -t variable -i ${MINIDIR}/tt2l.root           -o ${HISTDIR}/tt2l_1.root         -j 10 -I 1 > ${HISTDIR}/tt2l_1.log               2>&1" >> .jobs.txt
echo "rm -f ${HISTDIR}/tt2l_2.root        ; ./doAnalysis -t variable -i ${MINIDIR}/tt2l.root           -o ${HISTDIR}/tt2l_2.root         -j 10 -I 2 > ${HISTDIR}/tt2l_2.log               2>&1" >> .jobs.txt
echo "rm -f ${HISTDIR}/tt2l_3.root        ; ./doAnalysis -t variable -i ${MINIDIR}/tt2l.root           -o ${HISTDIR}/tt2l_3.root         -j 10 -I 3 > ${HISTDIR}/tt2l_3.log               2>&1" >> .jobs.txt
echo "rm -f ${HISTDIR}/tt2l_4.root        ; ./doAnalysis -t variable -i ${MINIDIR}/tt2l.root           -o ${HISTDIR}/tt2l_4.root         -j 10 -I 4 > ${HISTDIR}/tt2l_4.log               2>&1" >> .jobs.txt
echo "rm -f ${HISTDIR}/tt2l_5.root        ; ./doAnalysis -t variable -i ${MINIDIR}/tt2l.root           -o ${HISTDIR}/tt2l_5.root         -j 10 -I 5 > ${HISTDIR}/tt2l_5.log               2>&1" >> .jobs.txt
echo "rm -f ${HISTDIR}/tt2l_6.root        ; ./doAnalysis -t variable -i ${MINIDIR}/tt2l.root           -o ${HISTDIR}/tt2l_6.root         -j 10 -I 6 > ${HISTDIR}/tt2l_6.log               2>&1" >> .jobs.txt
echo "rm -f ${HISTDIR}/tt2l_7.root        ; ./doAnalysis -t variable -i ${MINIDIR}/tt2l.root           -o ${HISTDIR}/tt2l_7.root         -j 10 -I 7 > ${HISTDIR}/tt2l_7.log               2>&1" >> .jobs.txt
echo "rm -f ${HISTDIR}/tt2l_8.root        ; ./doAnalysis -t variable -i ${MINIDIR}/tt2l.root           -o ${HISTDIR}/tt2l_8.root         -j 10 -I 8 > ${HISTDIR}/tt2l_8.log               2>&1" >> .jobs.txt
echo "rm -f ${HISTDIR}/tt2l_9.root        ; ./doAnalysis -t variable -i ${MINIDIR}/tt2l.root           -o ${HISTDIR}/tt2l_9.root         -j 10 -I 9 > ${HISTDIR}/tt2l_9.log               2>&1" >> .jobs.txt
echo "rm -f ${HISTDIR}/tt1lpowheg.root    ; ./doAnalysis -t variable -i ${MINIDIR}/tt1lpowheg.root     -o ${HISTDIR}/tt1lpowheg.root     > ${HISTDIR}/tt1lpowheg.log         2>&1" >> .jobs.txt
echo "rm -f ${HISTDIR}/tt2lpowheg_0.root  ; ./doAnalysis -t variable -i ${MINIDIR}/tt2lpowheg.root     -o ${HISTDIR}/tt2lpowheg_0.root   -j 10 -I 0 > ${HISTDIR}/tt2lpowheg_0.log         2>&1" >> .jobs.txt
echo "rm -f ${HISTDIR}/tt2lpowheg_1.root  ; ./doAnalysis -t variable -i ${MINIDIR}/tt2lpowheg.root     -o ${HISTDIR}/tt2lpowheg_1.root   -j 10 -I 1 > ${HISTDIR}/tt2lpowheg_1.log         2>&1" >> .jobs.txt
echo "rm -f ${HISTDIR}/tt2lpowheg_2.root  ; ./doAnalysis -t variable -i ${MINIDIR}/tt2lpowheg.root     -o ${HISTDIR}/tt2lpowheg_2.root   -j 10 -I 2 > ${HISTDIR}/tt2lpowheg_2.log         2>&1" >> .jobs.txt
echo "rm -f ${HISTDIR}/tt2lpowheg_3.root  ; ./doAnalysis -t variable -i ${MINIDIR}/tt2lpowheg.root     -o ${HISTDIR}/tt2lpowheg_3.root   -j 10 -I 3 > ${HISTDIR}/tt2lpowheg_3.log         2>&1" >> .jobs.txt
echo "rm -f ${HISTDIR}/tt2lpowheg_4.root  ; ./doAnalysis -t variable -i ${MINIDIR}/tt2lpowheg.root     -o ${HISTDIR}/tt2lpowheg_4.root   -j 10 -I 4 > ${HISTDIR}/tt2lpowheg_4.log         2>&1" >> .jobs.txt
echo "rm -f ${HISTDIR}/tt2lpowheg_5.root  ; ./doAnalysis -t variable -i ${MINIDIR}/tt2lpowheg.root     -o ${HISTDIR}/tt2lpowheg_5.root   -j 10 -I 5 > ${HISTDIR}/tt2lpowheg_5.log         2>&1" >> .jobs.txt
echo "rm -f ${HISTDIR}/tt2lpowheg_6.root  ; ./doAnalysis -t variable -i ${MINIDIR}/tt2lpowheg.root     -o ${HISTDIR}/tt2lpowheg_6.root   -j 10 -I 6 > ${HISTDIR}/tt2lpowheg_6.log         2>&1" >> .jobs.txt
echo "rm -f ${HISTDIR}/tt2lpowheg_7.root  ; ./doAnalysis -t variable -i ${MINIDIR}/tt2lpowheg.root     -o ${HISTDIR}/tt2lpowheg_7.root   -j 10 -I 7 > ${HISTDIR}/tt2lpowheg_7.log         2>&1" >> .jobs.txt
echo "rm -f ${HISTDIR}/tt2lpowheg_8.root  ; ./doAnalysis -t variable -i ${MINIDIR}/tt2lpowheg.root     -o ${HISTDIR}/tt2lpowheg_8.root   -j 10 -I 8 > ${HISTDIR}/tt2lpowheg_8.log         2>&1" >> .jobs.txt
echo "rm -f ${HISTDIR}/tt2lpowheg_9.root  ; ./doAnalysis -t variable -i ${MINIDIR}/tt2lpowheg.root     -o ${HISTDIR}/tt2lpowheg_9.root   -j 10 -I 9 > ${HISTDIR}/tt2lpowheg_9.log         2>&1" >> .jobs.txt
echo "rm -f ${HISTDIR}/ttw_0.root         ; ./doAnalysis -t variable -i ${MINIDIR}/ttw.root            -o ${HISTDIR}/ttw_0.root          -j 6 -I 0 > ${HISTDIR}/ttw_0.log      2>&1" >> .jobs.txt
echo "rm -f ${HISTDIR}/ttw_1.root         ; ./doAnalysis -t variable -i ${MINIDIR}/ttw.root            -o ${HISTDIR}/ttw_1.root          -j 6 -I 1 > ${HISTDIR}/ttw_1.log      2>&1" >> .jobs.txt
echo "rm -f ${HISTDIR}/ttw_2.root         ; ./doAnalysis -t variable -i ${MINIDIR}/ttw.root            -o ${HISTDIR}/ttw_2.root          -j 6 -I 2 > ${HISTDIR}/ttw_2.log      2>&1" >> .jobs.txt
echo "rm -f ${HISTDIR}/ttw_3.root         ; ./doAnalysis -t variable -i ${MINIDIR}/ttw.root            -o ${HISTDIR}/ttw_3.root          -j 6 -I 3 > ${HISTDIR}/ttw_3.log      2>&1" >> .jobs.txt
echo "rm -f ${HISTDIR}/ttw_4.root         ; ./doAnalysis -t variable -i ${MINIDIR}/ttw.root            -o ${HISTDIR}/ttw_4.root          -j 6 -I 4 > ${HISTDIR}/ttw_4.log      2>&1" >> .jobs.txt
echo "rm -f ${HISTDIR}/ttw_5.root         ; ./doAnalysis -t variable -i ${MINIDIR}/ttw.root            -o ${HISTDIR}/ttw_5.root          -j 6 -I 5 > ${HISTDIR}/ttw_5.log      2>&1" >> .jobs.txt
echo "rm -f ${HISTDIR}/ttz_0.root         ; ./doAnalysis -t variable -i ${MINIDIR}/ttz.root            -o ${HISTDIR}/ttz_0.root          -j 3 -I 0 > ${HISTDIR}/ttz_0.log      2>&1" >> .jobs.txt
echo "rm -f ${HISTDIR}/ttz_1.root         ; ./doAnalysis -t variable -i ${MINIDIR}/ttz.root            -o ${HISTDIR}/ttz_1.root          -j 3 -I 1 > ${HISTDIR}/ttz_1.log      2>&1" >> .jobs.txt
echo "rm -f ${HISTDIR}/ttz_2.root         ; ./doAnalysis -t variable -i ${MINIDIR}/ttz.root            -o ${HISTDIR}/ttz_2.root          -j 3 -I 2 > ${HISTDIR}/ttz_2.log      2>&1" >> .jobs.txt
echo "rm -f ${HISTDIR}/raretop_0.root     ; ./doAnalysis -t variable -i ${MINIDIR}/raretop.root        -o ${HISTDIR}/raretop_0.root      -j 10 -I 0 > ${HISTDIR}/raretop_0.log 2>&1" >> .jobs.txt
echo "rm -f ${HISTDIR}/raretop_1.root     ; ./doAnalysis -t variable -i ${MINIDIR}/raretop.root        -o ${HISTDIR}/raretop_1.root      -j 10 -I 1 > ${HISTDIR}/raretop_1.log 2>&1" >> .jobs.txt
echo "rm -f ${HISTDIR}/raretop_2.root     ; ./doAnalysis -t variable -i ${MINIDIR}/raretop.root        -o ${HISTDIR}/raretop_2.root      -j 10 -I 2 > ${HISTDIR}/raretop_2.log 2>&1" >> .jobs.txt
echo "rm -f ${HISTDIR}/raretop_3.root     ; ./doAnalysis -t variable -i ${MINIDIR}/raretop.root        -o ${HISTDIR}/raretop_3.root      -j 10 -I 3 > ${HISTDIR}/raretop_3.log 2>&1" >> .jobs.txt
echo "rm -f ${HISTDIR}/raretop_4.root     ; ./doAnalysis -t variable -i ${MINIDIR}/raretop.root        -o ${HISTDIR}/raretop_4.root      -j 10 -I 4 > ${HISTDIR}/raretop_4.log 2>&1" >> .jobs.txt
echo "rm -f ${HISTDIR}/raretop_5.root     ; ./doAnalysis -t variable -i ${MINIDIR}/raretop.root        -o ${HISTDIR}/raretop_5.root      -j 10 -I 5 > ${HISTDIR}/raretop_5.log 2>&1" >> .jobs.txt
echo "rm -f ${HISTDIR}/raretop_6.root     ; ./doAnalysis -t variable -i ${MINIDIR}/raretop.root        -o ${HISTDIR}/raretop_6.root      -j 10 -I 6 > ${HISTDIR}/raretop_6.log 2>&1" >> .jobs.txt
echo "rm -f ${HISTDIR}/raretop_7.root     ; ./doAnalysis -t variable -i ${MINIDIR}/raretop.root        -o ${HISTDIR}/raretop_7.root      -j 10 -I 7 > ${HISTDIR}/raretop_7.log 2>&1" >> .jobs.txt
echo "rm -f ${HISTDIR}/raretop_8.root     ; ./doAnalysis -t variable -i ${MINIDIR}/raretop.root        -o ${HISTDIR}/raretop_8.root      -j 10 -I 8 > ${HISTDIR}/raretop_8.log 2>&1" >> .jobs.txt
echo "rm -f ${HISTDIR}/raretop_9.root     ; ./doAnalysis -t variable -i ${MINIDIR}/raretop.root        -o ${HISTDIR}/raretop_9.root      -j 10 -I 9 > ${HISTDIR}/raretop_9.log 2>&1" >> .jobs.txt
echo "rm -f ${HISTDIR}/bosons.root        ; ./doAnalysis -t variable -i ${MINIDIR}/bosons.root         -o ${HISTDIR}/bosons.root         > ${HISTDIR}/bosons.log               2>&1" >> .jobs.txt
echo "rm -f ${HISTDIR}/data.root          ; ./doAnalysis -t variable -i ${MINIDIR}/data.root           -o ${HISTDIR}/data.root           > ${HISTDIR}/data.log                 2>&1" >> .jobs.txt
# echo "rm -f ${HISTDIR}/vbshww.root        ; ./doAnalysis -t variable -i ${MINIDIR}/vbshww.root         -o ${HISTDIR}/vbshww.root         > ${HISTDIR}/vbshww.log               2>&1" >> .jobs.txt
echo "rm -f ${HISTDIR}/vbshww_c2v_3.root  ; ./doAnalysis -t variable -i ${MINIDIR}/vbshww_c2v_3.root   -o ${HISTDIR}/vbshww_c2v_3.root   > ${HISTDIR}/vbshww_c2v_3.log         2>&1" >> .jobs.txt
echo "rm -f ${HISTDIR}/vbshww_c2v_4p5.root; ./doAnalysis -t variable -i ${MINIDIR}/vbshww_c2v_4p5.root -o ${HISTDIR}/vbshww_c2v_4p5.root > ${HISTDIR}/vbshww_c2v_4p5.log       2>&1" >> .jobs.txt
echo "rm -f ${HISTDIR}/vbshww_c2v_6.root  ; ./doAnalysis -t variable -i ${MINIDIR}/vbshww_c2v_6.root   -o ${HISTDIR}/vbshww_c2v_6.root   > ${HISTDIR}/vbshww_c2v_6.log         2>&1" >> .jobs.txt
echo "rm -f ${HISTDIR}/vbshww_c2v_m2.root ; ./doAnalysis -t variable -i ${MINIDIR}/vbshww_c2v_m2.root  -o ${HISTDIR}/vbshww_c2v_m2.root  > ${HISTDIR}/vbshww_c2v_m2.log        2>&1" >> .jobs.txt

xargs.sh .jobs.txt

rm -f .haddjobs.txt
echo "hadd -f ${HISTDIR}/raretop.root ${HISTDIR}/raretop_*.root" >> .haddjobs.txt
echo "hadd -f ${HISTDIR}/ttw.root ${HISTDIR}/ttw_*.root" >> .haddjobs.txt
echo "hadd -f ${HISTDIR}/ttz.root ${HISTDIR}/ttz_*.root" >> .haddjobs.txt
echo "hadd -f ${HISTDIR}/tt2l.root ${HISTDIR}/tt2l_*.root" >> .haddjobs.txt
echo "hadd -f ${HISTDIR}/tt2lpowheg.root ${HISTDIR}/tt2lpowheg_*.root" >> .haddjobs.txt

xargs.sh .haddjobs.txt

rm -f .haddjobs.txt
echo "hadd -f ${HISTDIR}/totalbkg.root ${HISTDIR}/raretop.root ${HISTDIR}/ttw.root ${HISTDIR}/ttz.root ${HISTDIR}/tt1l.root ${HISTDIR}/tt2l.root ${HISTDIR}/bosons.root" >> .haddjobs.txt
echo "hadd -f ${HISTDIR}/statbkg.root ${HISTDIR}/raretop.root ${HISTDIR}/ttw.root ${HISTDIR}/ttz.root" >> .haddjobs.txt
echo "hadd -f ${HISTDIR}/lowstatbkg.root ${HISTDIR}/tt1l.root ${HISTDIR}/tt2l.root" >> .haddjobs.txt

xargs.sh .haddjobs.txt

