# Help
usage()
{
  echo "ERROR - Usage:"
  echo
  echo "      sh $(basename $0) STUDYNAME TAG BABYVERSION"
  echo
  exit
}

if [ -z ${1} ]; then usage; fi
STUDY=${1}
if [ -z ${2} ]; then usage; fi
TAG=${2}
if [ -z ${3} ]; then usage; fi
BABYVERSION=${3}

# YEARS="2016 2017 2018 Run2"
YEARS="2017 2018"

rm .haddjobs.txt

for YEAR in ${YEARS}; do

    HADDDIR=hadds/${TAG}/${BABYVERSION}/${STUDY}_${YEAR}

    if [[ ${YEAR} == *"Run2"* ]]; then
        HISTDIR="hists/${TAG}/${BABYVERSION}/${STUDY}_*"
    else
        HISTDIR=hists/${TAG}/${BABYVERSION}/${STUDY}_${YEAR}
    fi

    mkdir -p ${HADDDIR}

    echo "rm -f ${HADDDIR}/data.root;hadd -f ${HADDDIR}/data.root ${HISTDIR}/*Run2*.root > ${HADDDIR}/data.hadd.log 2>&1" >> .haddjobs.txt
    # echo "rm -f ${HADDDIR}/tt1l.root;hadd -f ${HADDDIR}/tt1l.root ${HISTDIR}/TTJets_Sing*.root > ${HADDDIR}/tt1l.hadd.log 2>&1" >> .haddjobs.txt
    # echo "rm -f ${HADDDIR}/tt2l.root;hadd -f ${HADDDIR}/tt2l.root ${HISTDIR}/TTJets_Di*.root > ${HADDDIR}/tt2l.hadd.log 2>&1" >> .haddjobs.txt
    echo "rm -f ${HADDDIR}/tt1lpowheg.root;hadd -f ${HADDDIR}/tt1lpowheg.root ${HISTDIR}/TTToSemi*.root > ${HADDDIR}/tt1lpowheg.hadd.log 2>&1" >> .haddjobs.txt
    echo "rm -f ${HADDDIR}/tt2lpowheg.root;hadd -f ${HADDDIR}/tt2lpowheg.root ${HISTDIR}/TTTo2L2Nu*.root > ${HADDDIR}/tt2lpowheg.hadd.log 2>&1" >> .haddjobs.txt
    echo "rm -f ${HADDDIR}/ttw.root;hadd -f ${HADDDIR}/ttw.root ${HISTDIR}/TTWJets*.root > ${HADDDIR}/ttw.hadd.log 2>&1" >> .haddjobs.txt
    echo "rm -f ${HADDDIR}/ttz.root;hadd -f ${HADDDIR}/ttz.root ${HISTDIR}/TTZToLL*.root > ${HADDDIR}/ttz.hadd.log 2>&1" >> .haddjobs.txt
    echo "rm -f ${HADDDIR}/raretop.root;hadd -f ${HADDDIR}/raretop.root ${HISTDIR}/ttHJetToNonbb*.root ${HISTDIR}/ttHJetTobb*.root ${HISTDIR}/ST_tW_top_*.root ${HISTDIR}/ST_tW_antitop_*.root ${HISTDIR}/ST_s-channel_4f*.root ${HISTDIR}/ST_t-channel_top_*.root ${HISTDIR}/ST_t-channel_antitop_*.root ${HISTDIR}/TWZToLL_tlept_Whad_5f_DR*.root ${HISTDIR}/TWZToLL_thad_Wlept_5f_DR*.root ${HISTDIR}/TTWW*.root ${HISTDIR}/TTWZ*.root > ${HADDDIR}/raretop.hadd.log 2>&1" >> .haddjobs.txt
    if [[ ${YEAR} == *"2017"* ]]; then
        echo "rm -f ${HADDDIR}/bosons.root;hadd -f ${HADDDIR}/bosons.root ${HISTDIR}/WJetsTo*.root ${HISTDIR}/DY*.root ${HISTDIR}/WW_*.root ${HISTDIR}/SSWW*.root ${HISTDIR}/WZTo3LNu*.root ${HISTDIR}/ZZ*.root > ${HADDDIR}/bosons.hadd.log 2>&1" >> .haddjobs.txt
    elif [[ ${YEAR} == *"2018"* ]]; then
        echo "rm -f ${HADDDIR}/bosons.root;hadd -f ${HADDDIR}/bosons.root ${HISTDIR}/WJetsTo*.root ${HISTDIR}/DY*.root ${HISTDIR}/WW_*.root ${HISTDIR}/SSWW*.root ${HISTDIR}/WZTo3LNu*.root ${HISTDIR}/ZZTo4L*.root > ${HADDDIR}/bosons.hadd.log 2>&1" >> .haddjobs.txt
    elif [[ ${YEAR} == *"Run2"* ]]; then
        echo "rm -f ${HADDDIR}/bosons.root;hadd -f ${HADDDIR}/bosons.root ${HISTDIR}/WJetsTo*.root ${HISTDIR}/DY*.root ${HISTDIR}/WW_*.root ${HISTDIR}/SSWW*.root ${HISTDIR}/WZTo3LNu*.root hists/${TAG}/${BABYVERSION}/${STUDY}_2017/ZZ*.root hists/${TAG}/${BABYVERSION}/${STUDY}_2018/ZZTo4L*.root > ${HADDDIR}/bosons.hadd.log 2>&1" >> .haddjobs.txt
    fi
    echo "rm -f ${HADDDIR}/vbshwwlvlvbb_c2v.root;hadd -f ${HADDDIR}/vbshwwlvlvbb_c2v.root ${HISTDIR}/VBSWWHToLNuLNubb_C2V*.root > ${HADDDIR}/vbshwwlvlvbb_c2v.hadd.log 2>&1" >> .haddjobs.txt
    echo "rm -f ${HADDDIR}/vbshwwlvlvbb_cv.root;hadd -f ${HADDDIR}/vbshwwlvlvbb_cv.root ${HISTDIR}/VBSWWHToLNuLNubb_CV*.root > ${HADDDIR}/vbshwwlvlvbb_cv.hadd.log 2>&1" >> .haddjobs.txt
    echo "rm -f ${HADDDIR}/vbshwwlvlvbb_c3.root;hadd -f ${HADDDIR}/vbshwwlvlvbb_c3.root ${HISTDIR}/VBSWWHToLNuLNubb_C3*.root > ${HADDDIR}/vbshwwlvlvbb_c3.hadd.log 2>&1" >> .haddjobs.txt
    echo "rm -f ${HADDDIR}/vbshww_c2v_4p5.root;hadd -f ${HADDDIR}/vbshww_c2v_4p5.root ${HISTDIR}/VBSWmpWmpH_C2V_4p5_TuneCP5*.root > ${HADDDIR}/vbshww_c2v_4p5.hadd.log 2>&1" >> .haddjobs.txt
    echo "rm -f ${HADDDIR}/vbshww_c2v_4.root;hadd -f ${HADDDIR}/vbshww_c2v_4.root ${HISTDIR}/VBSWmpWmpH_C2V_4_TuneCP5*.root > ${HADDDIR}/vbshww_c2v_4.hadd.log 2>&1" >> .haddjobs.txt
    echo "rm -f ${HADDDIR}/vbshww_c2v_3.root;hadd -f ${HADDDIR}/vbshww_c2v_3.root ${HISTDIR}/VBSWmpWmpH_C2V_3_TuneCP5*.root > ${HADDDIR}/vbshww_c2v_3.hadd.log 2>&1" >> .haddjobs.txt
    echo "rm -f ${HADDDIR}/vbshww_c2v_1.root;hadd -f ${HADDDIR}/vbshww_c2v_1.root ${HISTDIR}/VBSWmpWmpH_C2V_1_TuneCP5*.root > ${HADDDIR}/vbshww_c2v_1.hadd.log 2>&1" >> .haddjobs.txt
    echo "rm -f ${HADDDIR}/vbshww_c2v_0.root;hadd -f ${HADDDIR}/vbshww_c2v_0.root ${HISTDIR}/VBSWmpWmpH_C2V_0_TuneCP5*.root > ${HADDDIR}/vbshww_c2v_0.hadd.log 2>&1" >> .haddjobs.txt
    echo "rm -f ${HADDDIR}/vbshww_c2v_m1.root;hadd -f ${HADDDIR}/vbshww_c2v_m1.root ${HISTDIR}/VBSWmpWmpH_C2V_m1_TuneCP5*.root > ${HADDDIR}/vbshww_c2v_m1.hadd.log 2>&1" >> .haddjobs.txt
    echo "rm -f ${HADDDIR}/vbshww_c2v_m2.root;hadd -f ${HADDDIR}/vbshww_c2v_m2.root ${HISTDIR}/VBSWmpWmpH_C2V_m2_TuneCP5*.root > ${HADDDIR}/vbshww_c2v_m2.hadd.log 2>&1" >> .haddjobs.txt
    echo "rm -f ${HADDDIR}/vbshww_c2v_m2p5.root;hadd -f ${HADDDIR}/vbshww_c2v_m2p5.root ${HISTDIR}/VBSWmpWmpH_C2V_m2p5_TuneCP5*.root > ${HADDDIR}/vbshww_c2v_m2p5.hadd.log 2>&1" >> .haddjobs.txt

done

xargs.sh .haddjobs.txt
