# Help
usage()
{
  echo "ERROR - Usage:"
  echo
  echo "      sh $(basename $0) STUDYNAME ULTAG v7TAG BABYVERSION"
  echo
  exit
}

if [ -z ${1} ]; then usage; fi
STUDY=${1}
if [ -z ${2} ]; then usage; fi
ULTAG=${2}
if [ -z ${3} ]; then usage; fi
v7TAG=${3}
if [ -z ${4} ]; then usage; fi
BABYVERSION=${4}

rm .haddjobs.txt
HADDDIR=hadds/${ULTAG}/${BABYVERSION}/${STUDY}_Run2
mkdir -p ${HADDDIR}
echo "rm -f ${HADDDIR}/data.root            ; hadd -f ${HADDDIR}/data.root           hadds/${v7TAG}/${BABYVERSION}/${STUDY}_2016/data.root       hadds/${ULTAG}/${BABYVERSION}/${STUDY}_2017/data.root           hadds/${ULTAG}/${BABYVERSION}/${STUDY}_2018/data.root           > ${HADDDIR}/data.hadd.log           2>&1" >> .haddjobs.txt
echo "rm -f ${HADDDIR}/tt1lpowheg.root      ; hadd -f ${HADDDIR}/tt1lpowheg.root     hadds/${v7TAG}/${BABYVERSION}/${STUDY}_2016/tt1lpowheg.root hadds/${ULTAG}/${BABYVERSION}/${STUDY}_2017/tt1lpowheg.root     hadds/${ULTAG}/${BABYVERSION}/${STUDY}_2018/tt1lpowheg.root     > ${HADDDIR}/tt1lpowheg.hadd.log     2>&1" >> .haddjobs.txt
echo "rm -f ${HADDDIR}/tt2lpowheg.root      ; hadd -f ${HADDDIR}/tt2lpowheg.root     hadds/${v7TAG}/${BABYVERSION}/${STUDY}_2016/tt2lpowheg.root hadds/${ULTAG}/${BABYVERSION}/${STUDY}_2017/tt2lpowheg.root     hadds/${ULTAG}/${BABYVERSION}/${STUDY}_2018/tt2lpowheg.root     > ${HADDDIR}/tt2lpowheg.hadd.log     2>&1" >> .haddjobs.txt
echo "rm -f ${HADDDIR}/ttw.root             ; hadd -f ${HADDDIR}/ttw.root            hadds/${v7TAG}/${BABYVERSION}/${STUDY}_2016/ttw.root        hadds/${ULTAG}/${BABYVERSION}/${STUDY}_2017/ttw.root            hadds/${ULTAG}/${BABYVERSION}/${STUDY}_2018/ttw.root            > ${HADDDIR}/ttw.hadd.log            2>&1" >> .haddjobs.txt
echo "rm -f ${HADDDIR}/ttz.root             ; hadd -f ${HADDDIR}/ttz.root            hadds/${v7TAG}/${BABYVERSION}/${STUDY}_2016/ttz.root        hadds/${ULTAG}/${BABYVERSION}/${STUDY}_2017/ttz.root            hadds/${ULTAG}/${BABYVERSION}/${STUDY}_2018/ttz.root            > ${HADDDIR}/ttz.hadd.log            2>&1" >> .haddjobs.txt
echo "rm -f ${HADDDIR}/raretop.root         ; hadd -f ${HADDDIR}/raretop.root        hadds/${v7TAG}/${BABYVERSION}/${STUDY}_2016/raretop.root    hadds/${ULTAG}/${BABYVERSION}/${STUDY}_2017/raretop.root        hadds/${ULTAG}/${BABYVERSION}/${STUDY}_2018/raretop.root        > ${HADDDIR}/raretop.hadd.log        2>&1" >> .haddjobs.txt
echo "rm -f ${HADDDIR}/bosons.root          ; hadd -f ${HADDDIR}/bosons.root         hadds/${v7TAG}/${BABYVERSION}/${STUDY}_2016/bosons.root     hadds/${ULTAG}/${BABYVERSION}/${STUDY}_2017/bosons.root         hadds/${ULTAG}/${BABYVERSION}/${STUDY}_2018/bosons.root         > ${HADDDIR}/bosons.hadd.log         2>&1" >> .haddjobs.txt
echo "rm -f ${HADDDIR}/vbshwwlvlvbb_c2v.root; hadd -f ${HADDDIR}/vbshwwlvlvbb_c2v.root hadds/${v7TAG}/${BABYVERSION}/${STUDY}_2016/vbshwwlvlvbb_c2v.root hadds/${ULTAG}/${BABYVERSION}/${STUDY}_2017/vbshwwlvlvbb_c2v.root hadds/${ULTAG}/${BABYVERSION}/${STUDY}_2018/vbshwwlvlvbb_c2v.root  > ${HADDDIR}/vbshwwlvlvbb_c2v.hadd.log 2>&1" >> .haddjobs.txt
echo "rm -f ${HADDDIR}/vbshwwlvlvbb_cv.root ; hadd -f ${HADDDIR}/vbshwwlvlvbb_cv.root  hadds/${v7TAG}/${BABYVERSION}/${STUDY}_2016/vbshwwlvlvbb_cv.root  hadds/${ULTAG}/${BABYVERSION}/${STUDY}_2017/vbshwwlvlvbb_cv.root  hadds/${ULTAG}/${BABYVERSION}/${STUDY}_2018/vbshwwlvlvbb_cv.root   > ${HADDDIR}/vbshwwlvlvbb_cv.hadd.log 2>&1" >> .haddjobs.txt
echo "rm -f ${HADDDIR}/vbshwwlvlvbb_c3.root ; hadd -f ${HADDDIR}/vbshwwlvlvbb_c3.root  hadds/${v7TAG}/${BABYVERSION}/${STUDY}_2016/vbshwwlvlvbb_c3.root  hadds/${ULTAG}/${BABYVERSION}/${STUDY}_2017/vbshwwlvlvbb_c3.root  hadds/${ULTAG}/${BABYVERSION}/${STUDY}_2018/vbshwwlvlvbb_c3.root   > ${HADDDIR}/vbshwwlvlvbb_c3.hadd.log 2>&1" >> .haddjobs.txt
echo "rm -f ${HADDDIR}/vbshww_c2v_4p5.root  ; hadd -f ${HADDDIR}/vbshww_c2v_4p5.root   hadds/${ULTAG}/${BABYVERSION}/${STUDY}_2017/vbshww_c2v_4p5.root   hadds/${ULTAG}/${BABYVERSION}/${STUDY}_2018/vbshww_c2v_4p5.root    > ${HADDDIR}/vbshww_c2v_4p5.hadd.log 2>&1" >> .haddjobs.txt
echo "rm -f ${HADDDIR}/vbshww_c2v_4.root    ; hadd -f ${HADDDIR}/vbshww_c2v_4.root     hadds/${ULTAG}/${BABYVERSION}/${STUDY}_2017/vbshww_c2v_4.root     hadds/${ULTAG}/${BABYVERSION}/${STUDY}_2018/vbshww_c2v_4.root      > ${HADDDIR}/vbshww_c2v_4.hadd.log 2>&1" >> .haddjobs.txt
echo "rm -f ${HADDDIR}/vbshww_c2v_3.root    ; hadd -f ${HADDDIR}/vbshww_c2v_3.root     hadds/${ULTAG}/${BABYVERSION}/${STUDY}_2017/vbshww_c2v_3.root     hadds/${ULTAG}/${BABYVERSION}/${STUDY}_2018/vbshww_c2v_3.root      > ${HADDDIR}/vbshww_c2v_3.hadd.log 2>&1" >> .haddjobs.txt
echo "rm -f ${HADDDIR}/vbshww_c2v_1.root    ; hadd -f ${HADDDIR}/vbshww_c2v_1.root     hadds/${ULTAG}/${BABYVERSION}/${STUDY}_2017/vbshww_c2v_1.root     hadds/${ULTAG}/${BABYVERSION}/${STUDY}_2018/vbshww_c2v_1.root      > ${HADDDIR}/vbshww_c2v_1.hadd.log 2>&1" >> .haddjobs.txt
echo "rm -f ${HADDDIR}/vbshww_c2v_0.root    ; hadd -f ${HADDDIR}/vbshww_c2v_0.root     hadds/${ULTAG}/${BABYVERSION}/${STUDY}_2017/vbshww_c2v_0.root     hadds/${ULTAG}/${BABYVERSION}/${STUDY}_2018/vbshww_c2v_0.root      > ${HADDDIR}/vbshww_c2v_0.hadd.log 2>&1" >> .haddjobs.txt
echo "rm -f ${HADDDIR}/vbshww_c2v_m1.root   ; hadd -f ${HADDDIR}/vbshww_c2v_m1.root    hadds/${ULTAG}/${BABYVERSION}/${STUDY}_2017/vbshww_c2v_m1.root    hadds/${ULTAG}/${BABYVERSION}/${STUDY}_2018/vbshww_c2v_m1.root     > ${HADDDIR}/vbshww_c2v_m1.hadd.log 2>&1" >> .haddjobs.txt
echo "rm -f ${HADDDIR}/vbshww_c2v_m2.root   ; hadd -f ${HADDDIR}/vbshww_c2v_m2.root    hadds/${ULTAG}/${BABYVERSION}/${STUDY}_2017/vbshww_c2v_m2.root    hadds/${ULTAG}/${BABYVERSION}/${STUDY}_2018/vbshww_c2v_m2.root     > ${HADDDIR}/vbshww_c2v_m2.hadd.log 2>&1" >> .haddjobs.txt
echo "rm -f ${HADDDIR}/vbshww_c2v_m2p5.root ; hadd -f ${HADDDIR}/vbshww_c2v_m2p5.root  hadds/${ULTAG}/${BABYVERSION}/${STUDY}_2017/vbshww_c2v_m2p5.root  hadds/${ULTAG}/${BABYVERSION}/${STUDY}_2018/vbshww_c2v_m2p5.root   > ${HADDDIR}/vbshww_c2v_m2p5.hadd.log 2>&1" >> .haddjobs.txt
# echo "rm -f ${HADDDIR}/vbshww_c2v_4p5.root ; hadd -f ${HADDDIR}/vbshww_c2v_4p5.root hadds/${v7TAG}/${STUDY}_2018/vbshww_c2v_4p5.root                                                                                        > ${HADDDIR}/vbshww_c2v_4p5.hadd.log 2>&1" >> .haddjobs.txt

xargs.sh .haddjobs.txt
