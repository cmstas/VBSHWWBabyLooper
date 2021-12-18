EXE=studies/createMini/doAnalysis
COMMONOPT=" -t Events -2"
DIR=dilep_v2/

print_jobs() {
    YEAR=${1}
    PREFIX=${2}
    PATTERN=${3}
    IDX=0
    for i in $(ls /hadoop/cms/store/user/phchang/VBSHWWNanoSkim/v2.6_Excl2L/${PATTERN}/output_*.root); do
        OUTPUT=${DIR}/${PREFIX}${YEAR}${IDX}.root
        OUTLOG=${DIR}/${PREFIX}${YEAR}${IDX}.log
        echo "mkdir -p ${DIR}; rm -f ${OUTPUT}; ${EXE} ${COMMONOPT} -i $i -o ${OUTPUT} > ${OUTLOG} 2>&1"
        IDX=$((IDX + 1))
    done
}

print_jobs_mc() {
    YEAR=${1}
    PREFIX=${2}
    PATTERN=${3}
    XSEC=${4}
    MAXNEVENT=${5}
    TOTALEFFNEVENT=0
    FILESTORUNOVER=""
    for i in $(ls /hadoop/cms/store/user/phchang/VBSHWWNanoSkim/v2.6_Excl2L/${PATTERN}/output_*.root); do
        if [ ${TOTALEFFNEVENT} -gt ${MAXNEVENT} ]; then break; fi
        NEVENTSFILE=${i/.root/_nevents.txt}
        POSNEVENT=$(tail -n 2 ${NEVENTSFILE} | head -n 1)
        NEGNEVENT=$(tail -n 1 ${NEVENTSFILE} | head -n 1)
        EFFNEVENT=$(echo ${POSNEVENT}-${NEGNEVENT} | bc)
        FILESTORUNOVER="${FILESTORUNOVER} ${i}"
        TOTALEFFNEVENT=$((${TOTALEFFNEVENT} + ${EFFNEVENT}))
    done
    SCALE1FB=$(echo "${XSEC} * 1000.0 / (${TOTALEFFNEVENT}*1.0)" | bc -l)
    IDX=0
    for i in ${FILESTORUNOVER}; do
        OUTPUT=${DIR}/${PREFIX}${YEAR}${IDX}.root
        OUTLOG=${DIR}/${PREFIX}${YEAR}${IDX}.log
        echo "mkdir -p ${DIR}; rm -f ${OUTPUT}; ${EXE} ${COMMONOPT} -s ${SCALE1FB} -i $i -o ${OUTPUT} > ${OUTLOG} 2>&1"
        IDX=$((IDX + 1))
    done
}
    # if "TTTo2L2Nu"                 in samplename: xsec = 87.315
    # if "DYJetsToLL_M-50"           in samplename: xsec = 6198.0
    # if "WW"                        in samplename: xsec = 118.71

print_jobs 2016APV_ data_ee_ DoubleEG_Run2016*HIPM*
print_jobs 2016APV_ data_mm_ DoubleMuon_Run2016*HIPM*
print_jobs 2016APV_ data_em_ MuonEG_Run2016*HIPM*

print_jobs 2016_ data_ee_ DoubleEG_Run2016*-UL2016*
print_jobs 2016_ data_mm_ DoubleMuon_Run2016*-UL2016*
print_jobs 2016_ data_em_ MuonEG_Run2016*-UL2016*

print_jobs 2017_ data_ee_ DoubleEG_Run2017*
print_jobs 2017_ data_mm_ DoubleMuon_Run2017*
print_jobs 2017_ data_em_ MuonEG_Run2017*

print_jobs 2018_ data_eg_ EGamma_Run2018*
print_jobs 2018_ data_mm_ DoubleMuon_Run2018*
print_jobs 2018_ data_em_ MuonEG_Run2018*

print_jobs_mc 2018_ dy_ DY*M-50*UL18NanoAODv9* 6198.0 15000000
print_jobs_mc 2017_ dy_ DY*M-50*UL17NanoAODv9* 6198.0 15000000
print_jobs_mc 2016_ dy_ DY*M-50*UL16NanoAODv9* 6198.0 15000000
print_jobs_mc 2016APV_ dy_ DY*M-50*UL16NanoAODAPVv9* 6198.0 15000000

print_jobs_mc 2018_ ww_ WW_TuneCP5*UL18NanoAODv9* 118.71 1500000
print_jobs_mc 2017_ ww_ WW_TuneCP5*UL17NanoAODv9* 118.71 1500000
print_jobs_mc 2016_ ww_ WW_TuneCP5*UL16NanoAODv9* 118.71 1500000
print_jobs_mc 2016APV_ ww_ WW_TuneCP5*UL16NanoAODAPVv9* 118.71 1500000

print_jobs_mc 2018_    tt2l_ TTTo2L2Nu_TuneCP5*UL18NanoAODv9*    87.315 1500000
print_jobs_mc 2017_    tt2l_ TTTo2L2Nu_TuneCP5*UL17NanoAODv9*    87.315 1500000
print_jobs_mc 2016_    tt2l_ TTTo2L2Nu_TuneCP5*UL16NanoAODv9*    87.315 1500000
print_jobs_mc 2016APV_ tt2l_ TTTo2L2Nu_TuneCP5*UL16NanoAODAPVv9* 87.315 1500000

print_jobs_mc 2018_    hww_ GluGluHToWW*UL18NanoAODv9*    0.9913 1500000
print_jobs_mc 2017_    hww_ GluGluHToWW*UL17NanoAODv9*    0.9913 1500000
print_jobs_mc 2016_    hww_ GluGluHToWW*UL16NanoAODv9*    0.9913 1500000
print_jobs_mc 2016APV_ hww_ GluGluHToWW*UL16NanoAODAPVv9* 0.9913 1500000
