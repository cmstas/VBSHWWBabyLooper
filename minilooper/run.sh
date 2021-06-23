
mkdir -p hists/

MINIDIR=../hadds/createMini_Run2

rm -f .jobs.txt
echo "rm -f hists/tt1l.root          ; ./doAnalysis -t variable -i ${MINIDIR}/tt1l.root           -o hists/tt1l.root           > hists/tt1l.log                 2>&1" >> .jobs.txt
echo "rm -f hists/tt2l.root          ; ./doAnalysis -t variable -i ${MINIDIR}/tt2l.root           -o hists/tt2l.root           > hists/tt2l.log                 2>&1" >> .jobs.txt
echo "rm -f hists/tt1lpowheg.root    ; ./doAnalysis -t variable -i ${MINIDIR}/tt1lpowheg.root     -o hists/tt1lpowheg.root     > hists/tt1lpowheg.log           2>&1" >> .jobs.txt
echo "rm -f hists/tt2lpowheg.root    ; ./doAnalysis -t variable -i ${MINIDIR}/tt2lpowheg.root     -o hists/tt2lpowheg.root     > hists/tt2lpowheg.log           2>&1" >> .jobs.txt
echo "rm -f hists/ttw_0.root         ; ./doAnalysis -t variable -i ${MINIDIR}/ttw.root            -o hists/ttw_0.root          -j 6 -I 0 > hists/ttw_0.log      2>&1" >> .jobs.txt
echo "rm -f hists/ttw_1.root         ; ./doAnalysis -t variable -i ${MINIDIR}/ttw.root            -o hists/ttw_1.root          -j 6 -I 1 > hists/ttw_1.log      2>&1" >> .jobs.txt
echo "rm -f hists/ttw_2.root         ; ./doAnalysis -t variable -i ${MINIDIR}/ttw.root            -o hists/ttw_2.root          -j 6 -I 2 > hists/ttw_2.log      2>&1" >> .jobs.txt
echo "rm -f hists/ttw_3.root         ; ./doAnalysis -t variable -i ${MINIDIR}/ttw.root            -o hists/ttw_3.root          -j 6 -I 3 > hists/ttw_3.log      2>&1" >> .jobs.txt
echo "rm -f hists/ttw_4.root         ; ./doAnalysis -t variable -i ${MINIDIR}/ttw.root            -o hists/ttw_4.root          -j 6 -I 4 > hists/ttw_4.log      2>&1" >> .jobs.txt
echo "rm -f hists/ttw_5.root         ; ./doAnalysis -t variable -i ${MINIDIR}/ttw.root            -o hists/ttw_5.root          -j 6 -I 5 > hists/ttw_5.log      2>&1" >> .jobs.txt
echo "rm -f hists/ttz_0.root         ; ./doAnalysis -t variable -i ${MINIDIR}/ttz.root            -o hists/ttz_0.root          -j 3 -I 0 > hists/ttz_0.log      2>&1" >> .jobs.txt
echo "rm -f hists/ttz_1.root         ; ./doAnalysis -t variable -i ${MINIDIR}/ttz.root            -o hists/ttz_1.root          -j 3 -I 1 > hists/ttz_1.log      2>&1" >> .jobs.txt
echo "rm -f hists/ttz_2.root         ; ./doAnalysis -t variable -i ${MINIDIR}/ttz.root            -o hists/ttz_2.root          -j 3 -I 2 > hists/ttz_2.log      2>&1" >> .jobs.txt
echo "rm -f hists/raretop_0.root     ; ./doAnalysis -t variable -i ${MINIDIR}/raretop.root        -o hists/raretop_0.root      -j 10 -I 0 > hists/raretop_0.log 2>&1" >> .jobs.txt
echo "rm -f hists/raretop_1.root     ; ./doAnalysis -t variable -i ${MINIDIR}/raretop.root        -o hists/raretop_1.root      -j 10 -I 1 > hists/raretop_1.log 2>&1" >> .jobs.txt
echo "rm -f hists/raretop_2.root     ; ./doAnalysis -t variable -i ${MINIDIR}/raretop.root        -o hists/raretop_2.root      -j 10 -I 2 > hists/raretop_2.log 2>&1" >> .jobs.txt
echo "rm -f hists/raretop_3.root     ; ./doAnalysis -t variable -i ${MINIDIR}/raretop.root        -o hists/raretop_3.root      -j 10 -I 3 > hists/raretop_3.log 2>&1" >> .jobs.txt
echo "rm -f hists/raretop_4.root     ; ./doAnalysis -t variable -i ${MINIDIR}/raretop.root        -o hists/raretop_4.root      -j 10 -I 4 > hists/raretop_4.log 2>&1" >> .jobs.txt
echo "rm -f hists/raretop_5.root     ; ./doAnalysis -t variable -i ${MINIDIR}/raretop.root        -o hists/raretop_5.root      -j 10 -I 5 > hists/raretop_5.log 2>&1" >> .jobs.txt
echo "rm -f hists/raretop_6.root     ; ./doAnalysis -t variable -i ${MINIDIR}/raretop.root        -o hists/raretop_6.root      -j 10 -I 6 > hists/raretop_6.log 2>&1" >> .jobs.txt
echo "rm -f hists/raretop_7.root     ; ./doAnalysis -t variable -i ${MINIDIR}/raretop.root        -o hists/raretop_7.root      -j 10 -I 7 > hists/raretop_7.log 2>&1" >> .jobs.txt
echo "rm -f hists/raretop_8.root     ; ./doAnalysis -t variable -i ${MINIDIR}/raretop.root        -o hists/raretop_8.root      -j 10 -I 8 > hists/raretop_8.log 2>&1" >> .jobs.txt
echo "rm -f hists/raretop_9.root     ; ./doAnalysis -t variable -i ${MINIDIR}/raretop.root        -o hists/raretop_9.root      -j 10 -I 9 > hists/raretop_9.log 2>&1" >> .jobs.txt
echo "rm -f hists/bosons.root        ; ./doAnalysis -t variable -i ${MINIDIR}/bosons.root         -o hists/bosons.root         > hists/bosons.log               2>&1" >> .jobs.txt
echo "rm -f hists/data.root          ; ./doAnalysis -t variable -i ${MINIDIR}/data.root           -o hists/data.root           > hists/data.log                 2>&1" >> .jobs.txt
echo "rm -f hists/vbshww.root        ; ./doAnalysis -t variable -i ${MINIDIR}/vbshww.root         -o hists/vbshww.root         > hists/vbshww.log               2>&1" >> .jobs.txt
echo "rm -f hists/vbshww_c2v_3.root  ; ./doAnalysis -t variable -i ${MINIDIR}/vbshww_c2v_3.root   -o hists/vbshww_c2v_3.root   > hists/vbshww_c2v_3.log         2>&1" >> .jobs.txt
echo "rm -f hists/vbshww_c2v_4p5.root; ./doAnalysis -t variable -i ${MINIDIR}/vbshww_c2v_4p5.root -o hists/vbshww_c2v_4p5.root > hists/vbshww_c2v_4p5.log       2>&1" >> .jobs.txt
echo "rm -f hists/vbshww_c2v_6.root  ; ./doAnalysis -t variable -i ${MINIDIR}/vbshww_c2v_6.root   -o hists/vbshww_c2v_6.root   > hists/vbshww_c2v_6.log         2>&1" >> .jobs.txt
echo "rm -f hists/vbshww_c2v_m2.root ; ./doAnalysis -t variable -i ${MINIDIR}/vbshww_c2v_m2.root  -o hists/vbshww_c2v_m2.root  > hists/vbshww_c2v_m2.log        2>&1" >> .jobs.txt

xargs.sh .jobs.txt

rm -f .haddjobs.txt
echo "hadd -f hists/raretop.root hists/raretop_*.root" >> .haddjobs.txt
echo "hadd -f hists/ttw.root hists/ttw_*.root" >> .haddjobs.txt
echo "hadd -f hists/ttz.root hists/ttz_*.root" >> .haddjobs.txt

xargs.sh .haddjobs.txt

hadd -f hists/totalbkg.root hists/raretop.root hists/ttw.root hists/ttz.root hists/tt1l.root hists/tt2l.root hists/bosons.root
hadd -f hists/statbkg.root hists/raretop.root hists/ttw.root hists/ttz.root
hadd -f hists/lowstatbkg.root hists/tt1l.root hists/tt2l.root

