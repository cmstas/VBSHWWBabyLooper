# Help
usage()
{
  echo "ERROR - Usage:"
  echo
  echo "      sh $(basename $0) STUDYNAME TAG [DEBUG]"
  echo
  exit
}

if [ -z ${1} ]; then usage; fi
STUDY=${1}
if [ -z ${2} ]; then usage; fi
TAG=${2}
# Third argument is debug
DEBUG=${3}

# YEARS="2016 2017 2018"
YEARS="2017 2018"

EXECUTABLE=./studies/${STUDY}/doAnalysis

SAMPLES="TTJets_DiLept \
TTJets_SingleLeptFromT \
TTJets_SingleLeptFromTbar \
TTTo2L2Nu \
TTToSemiLeptonic \
TTWJetsToLNu \
TTZToLLNuNu_M-10 \
TTZToLL_M-1to10 \
WZTo3LNu \
ZZTo4L \
GluGluHToZZTo4L \
DYJetsToLL_M-50 \
DYJetsToLL_M-10to50 \
WpWpJJ_EWK-QCD \
ttHToNonbb \
ttHTobb \
WJetsToLNu \
tZq_ll_4f_ckm_NLO \
ST_tWll_5f_LO \
TTTT \
TTWH \
TTWW \
TTWZ \
TTZH \
TTZZ \
WWW_4F \
WWZ \
WZG \
WZZ \
ZZZ \
WWToLNuQQ \
WWTo2L2Nu \
ST_s-channel_4f \
ST_t-channel_antitop_4f \
ST_t-channel_top_4f \
ST_tW_antitop_5f \
ST_tW_top_5f \
VBSWmpWmpHToLNuLNu_C2V_6_TuneCP5 \
VBSWmpWmpHToLNuLNu_C2V_3_TuneCP5 \
VBSWmpWmpHToLNuLNu_C2V_4p5_TuneCP5 \
VBSWmpWmpHToLNuLNu_C2V_m2_TuneCP5 \
DoubleEG_Run2016 \
DoubleMuon_Run2016 \
MuonEG_Run2016 \
SingleElectron_Run2016 \
SingleMuon_Run2016 \
DoubleEG_Run2017 \
DoubleMuon_Run2017 \
MuonEG_Run2017 \
SingleElectron_Run2017 \
SingleMuon_Run2017 \
EGamma_Run2018 \
DoubleMuon_Run2018 \
MuonEG_Run2018 \
SingleMuon_Run2018"

SAMPLES="TTTo2L2Nu \
TTToSemiLeptonic \
ST_tW_antitop_5f \
ST_tW_top_5f \
ST_s-channel_4f \
ST_t-channel_antitop_4f \
ST_t-channel_top_4f \
TTWJetsToLNu \
TTZToLLNuNu_M-10 \
DYJetsToLL_M-50 \
DYJetsToLL_M-10to50 \
WJetsToLNu \
SSWW \
WW \
WZTo3LNu \
ZZTo4L \
ZZ \
ttHJetToNonbb \
ttHJetTobb \
TWZToLL_thad_Wlept_5f_DR \
TWZToLL_tlept_Whad_5f_DR \
TTWW \
TTWZ \
VBSWmpWmpHToLNuLNu_C2V_4p5_TuneCP5 \
DoubleEG_Run2017 \
DoubleMuon_Run2017 \
MuonEG_Run2017 \
SingleElectron_Run2017 \
SingleMuon_Run2017 \
EGamma_Run2018 \
DoubleMuon_Run2018 \
MuonEG_Run2018 \
SingleMuon_Run2018"

# VBSWmpWmpHToLNuLNu_TuneCP5 \

NANOSKIMDIR=/nfs-7/userdata/phchang/VBSHWWNanoSkim_${TAG}/

rm -f .jobs.txt

for SAMPLE in ${SAMPLES}; do

    XSEC=""

    for YEAR in ${YEARS}; do

        HISTDIR=hists/${TAG}/${STUDY}_${YEAR}
        mkdir -p ${HISTDIR}

        # if [[ ${YEAR} == *"2016"* ]]; then NANOTAG=RunIISummer16NanoAOD*; fi
        if [[ ${YEAR} == *"2017"* ]]; then NANOTAG=RunIISummer*UL17NanoAODv2*; fi
        if [[ ${YEAR} == *"2018"* ]]; then NANOTAG=RunIISummer*UL18NanoAODv2*; fi

        if [[ ${SAMPLE} == *"Run201"* ]]; then NANOTAG=""; fi

        if [[ ${SAMPLE} == *"WW"* ]]; then XSEC=118.71; fi # This line needs to be at the front
        if [[ ${SAMPLE} == *"ZZ"* ]]; then XSEC=10.32; fi # This line needs to be at the front
        if [[ ${SAMPLE} == *"tZq_ll_4f_ckm_NLO"* ]]; then XSEC=0.0758; fi
        if [[ ${SAMPLE} == *"ST_s-channel_4f"* ]]; then XSEC=3.74; fi
        if [[ ${SAMPLE} == *"ST_t-channel_antitop_4f"* ]]; then XSEC=80.95; fi
        if [[ ${SAMPLE} == *"ST_t-channel_top_4f"* ]]; then XSEC=136.02; fi
        if [[ ${SAMPLE} == *"ST_tW_antitop_5f"* ]]; then XSEC=19.559; fi
        if [[ ${SAMPLE} == *"ST_tW_top_5f"* ]]; then XSEC=19.559; fi
        if [[ ${SAMPLE} == *"ST_tWll_5f_LO"* ]]; then XSEC=0.01123; fi
        if [[ ${SAMPLE} == *"TWZToLL_tlept_Whad_5f_DR"* ]]; then XSEC=0.003004; fi
        if [[ ${SAMPLE} == *"TWZToLL_thad_Wlept_5f_DR"* ]]; then XSEC=0.003004; fi
        if [[ ${SAMPLE} == *"ZZTo4L"* ]]; then XSEC=1.256; fi
        if [[ ${SAMPLE} == *"GluGluHToZZTo4L"* ]]; then XSEC=0.0082323; fi
        if [[ ${SAMPLE} == *"DYJetsToLL_M-10to50"* ]]; then XSEC=20657.0; fi
        if [[ ${SAMPLE} == *"DYJetsToLL_M-50"* ]]; then XSEC=6198.0; fi
        if [[ ${SAMPLE} == *"WJetsToLNu"* ]]; then XSEC=61335.0; fi
        if [[ ${SAMPLE} == *"TTWJetsToLNu"* ]]; then XSEC=0.2043; fi
        if [[ ${SAMPLE} == *"TTZToLLNuNu_M-10"* ]]; then XSEC=0.2529; fi
        if [[ ${SAMPLE} == *"TTZToLL_M-1to10"* ]]; then XSEC=0.2529; fi
        if [[ ${SAMPLE} == *"TTJets_DiLept"* ]]; then XSEC=91.044; fi
        if [[ ${SAMPLE} == *"TTJets_SingleLeptFromT"* ]]; then XSEC=182.96; fi
        if [[ ${SAMPLE} == *"TTJets_SingleLeptFromTbar"* ]]; then XSEC=182.96; fi
        if [[ ${SAMPLE} == *"TTTo2L2Nu"* ]]; then XSEC=87.315; fi
        if [[ ${SAMPLE} == *"TTToSemiLeptonic"* ]]; then XSEC=365.34; fi
        if [[ ${SAMPLE} == *"WpWpJJ_EWK"* ]]; then XSEC=0.0539; fi
        if [[ ${SAMPLE} == *"SSWW"* ]]; then XSEC=0.02794; fi
        if [[ ${SAMPLE} == *"WZTo3LNu"* ]]; then XSEC=4.4297; fi
        # if [[ ${SAMPLE} == *"VBSWmpWmpHToLNuLNu_TuneCP5"* ]]; then XSEC=0.00001708; fi
        # if [[ ${SAMPLE} == *"VBSWmpWmpHToLNuLNu_C2V_6_TuneCP5"* ]]; then XSEC=0.00116*137/59.97; fi
        # if [[ ${SAMPLE} == *"VBSWmpWmpHToLNuLNu_C2V_3_TuneCP5"* ]]; then XSEC=0.000203237376*137/59.97; fi
        if [[ ${SAMPLE} == *"VBSWmpWmpHToLNuLNu_C2V_4p5_TuneCP5"* ]]; then XSEC=0.01021; fi
        if [[ ${SAMPLE} == *"VBSWmpWmpHToLNuLNu_C2V_4p5_TuneCP5"* ]]; then XSEC=0.01021; fi
        # if [[ ${SAMPLE} == *"VBSWmpWmpHToLNuLNu_C2V_m2_TuneCP5"* ]]; then XSEC=0.000418440192*137/59.97; fi
        if [[ ${SAMPLE} == *"ttHJetTobb"* ]]; then XSEC=0.1279; fi
        if [[ ${SAMPLE} == *"ttHJetToNonbb"* ]]; then XSEC=0.215; fi
        if [[ ${SAMPLE} == *"TTTT"* ]]; then XSEC=0.009103; fi
        if [[ ${SAMPLE} == *"TTWW"* ]]; then XSEC=0.0115; fi
        if [[ ${SAMPLE} == *"TTWZ"* ]]; then XSEC=0.003884; fi
        if [[ ${SAMPLE} == *"TTZZ"* ]]; then XSEC=0.001982; fi
        if [[ ${SAMPLE} == *"TTWH"* ]]; then XSEC=0.001582; fi
        if [[ ${SAMPLE} == *"TTZH"* ]]; then XSEC=0.001535; fi
        if [[ ${SAMPLE} == *"WWW_4F"* ]]; then XSEC=0.2086; fi
        if [[ ${SAMPLE} == *"WWZ"* ]]; then XSEC=0.1651; fi
        if [[ ${SAMPLE} == *"WZG"* ]]; then XSEC=0.04123; fi
        if [[ ${SAMPLE} == *"WZZ"* ]]; then XSEC=0.05565; fi
        if [[ ${SAMPLE} == *"ZZZ"* ]]; then XSEC=0.01398; fi
        if [[ ${SAMPLE} == *"WWToLNuQQ"* ]]; then XSEC=49.997; fi
        if [[ ${SAMPLE} == *"WWTo2L2Nu"* ]]; then XSEC=12.178; fi
        if [[ ${SAMPLE} == *"Run201"* ]]; then XSEC=1; fi # data

        if [[ -z "${XSEC}" ]]; then
            echo ${SAMPLE} cross section missing!
            echo "here is my guess"
            grep ${SAMPLE} NanoTools/NanoCORE/datasetinfo/scale1fbs.txt | awk '{print $1, $5}'
            exit
        fi

        if [[ ${SAMPLE} == *"Run201"* ]]; then
            if [[ ${SAMPLE} == *"${YEAR}"* ]]; then
                :
            else
                continue
            fi
        fi

        if [[ ${SAMPLE}_${YEAR} == *"VBSWmpWmpHToLNuLNu_TuneCP5_2016"* ]]; then continue; fi
        if [[ ${SAMPLE}_${YEAR} == *"VBSWmpWmpHToLNuLNu_TuneCP5_2018"* ]]; then continue; fi

        if [[ ${SAMPLE}_${YEAR} == *"VBSWmpWmpHToLNuLNu_C2V_6_TuneCP5_2016"* ]]; then continue; fi
        if [[ ${SAMPLE}_${YEAR} == *"VBSWmpWmpHToLNuLNu_C2V_6_TuneCP5_2017"* ]]; then continue; fi

        if [[ ${SAMPLE}_${YEAR} == *"VBSWmpWmpHToLNuLNu_C2V_3_TuneCP5_2016"* ]]; then continue; fi
        if [[ ${SAMPLE}_${YEAR} == *"VBSWmpWmpHToLNuLNu_C2V_3_TuneCP5_2017"* ]]; then continue; fi

        if [[ ${SAMPLE}_${YEAR} == *"VBSWmpWmpHToLNuLNu_C2V_4p5_TuneCP5_2016"* ]]; then continue; fi
        # if [[ ${SAMPLE}_${YEAR} == *"VBSWmpWmpHToLNuLNu_C2V_4p5_TuneCP5_2017"* ]]; then continue; fi

        if [[ ${SAMPLE}_${YEAR} == *"VBSWmpWmpHToLNuLNu_C2V_m2_TuneCP5_2016"* ]]; then continue; fi
        if [[ ${SAMPLE}_${YEAR} == *"VBSWmpWmpHToLNuLNu_C2V_m2_TuneCP5_2017"* ]]; then continue; fi

        if [[ ${SAMPLE}_${YEAR} == *"ZZ_2018"* ]]; then continue; fi
        if [[ ${SAMPLE}_${YEAR} == *"ZZTo4L_2017"* ]]; then continue; fi

        if [[ ${STUDY} == "os" ]]; then
            if [[ ${SAMPLE}_${YEAR} == *"SingleElectron_Run2016_2016"* ]]; then continue; fi  #   803.8
            if [[ ${SAMPLE}_${YEAR} == *"SingleElectron_Run2017_2017"* ]]; then continue; fi  #   971.4
            if [[ ${SAMPLE}_${YEAR} == *"SingleMuon_Run2016_2016"* ]]; then continue; fi      #   1751.2
            if [[ ${SAMPLE}_${YEAR} == *"SingleMuon_Run2017_2017"* ]]; then continue; fi      #   2026.6
            if [[ ${SAMPLE}_${YEAR} == *"SingleMuon_Run2018_2018"* ]]; then continue; fi      #   2765.8
        fi

        EXTRATAG=""
        # if [[ ${SAMPLE} == *"VBSWmpWmpHToLNuLNu_C2V_4p5_TuneCP5"* ]]; then EXTRATAG=ext1; fi
        # if [[ ${SAMPLE}_${YEAR} == *"TTToSemiLeptonic_2018"* ]]; then EXTRATAG=ext3; fi
        # if [[ ${SAMPLE}_${YEAR} == *"TTToSemiLeptonic_2017"* ]]; then EXTRATAG=ext1; fi

        # Last bit modification
        if [[ ${SAMPLE} == *"Run201"* ]]; then
            XSEC=1;
            SAMPLEWITHUNDERSCORE=${SAMPLE} # Data does not get the underscore
        else
            # If it is not data then the SAMPLE string gets a "_" subscript in order to loop over them
            SAMPLEWITHUNDERSCORE=${SAMPLE}_
        fi

        NEVENTSINFOFILE=${NANOSKIMDIR}/${SAMPLEWITHUNDERSCORE}*${NANOTAG}*${EXTRATAG}*/merged/nevents.txt
        NFILES_NEVENTSINFOFILE=$(ls ${NEVENTSINFOFILE} | wc -l)
        if [[ ${SAMPLE} == *"Run201"* ]]; then
            NTOTALEVENTS=1
            NEFFEVENTS=1
            SCALE1FB=1
        else
            if [ "${NFILES_NEVENTSINFOFILE}" -gt "1" ]; then
                NTOTALEVENTS=0
                NEFFEVENTS=0
                for i in $(ls ${NEVENTSINFOFILE}); do
                    TMPNTOTALEVENTS=$(head -n1 ${i})
                    TMPNEFFEVENTS=$(tail -n1 ${i})
                    NTOTALEVENTS=$(($NTOTALEVENTS + $TMPNTOTALEVENTS))
                    NEFFEVENTS=$(($NEFFEVENTS + $TMPNEFFEVENTS))
                done
                SCALE1FB=$(echo "${XSEC} / ${NEFFEVENTS} * 1000" | bc -l)
            else
                NTOTALEVENTS=$(head -n1 ${NEVENTSINFOFILE})
                NEFFEVENTS=$(tail -n1 ${NEVENTSINFOFILE})
                SCALE1FB=$(echo "${XSEC} / ${NEFFEVENTS} * 1000" | bc -l)
            fi
        fi

        echo ""
        echo "=========================================================================================="
        echo "Preparing command lines to process ..."
        echo "Sample                            :" ${SAMPLE}
        echo "Year                              :" ${YEAR}
        echo "Nano tag                          :" ${NANOTAG}
        echo "N events information file         :" ${NEVENTSINFOFILE}
        echo "N total events                    :" ${NTOTALEVENTS}
        echo "N eff total events (i.e. pos-neg) :" ${NEFFEVENTS}
        echo "Cross section (pb)                :" ${XSEC}
        echo "Scale1fb                          :" ${SCALE1FB}
        echo ""

        #
        # More than 1 jobs
        #
        NJOBS=1
        if [[ ${SAMPLE}_${YEAR} == *"ttHToNonbb_2016"* ]]; then NJOBS=2; fi
        if [[ ${SAMPLE}_${YEAR} == *"ttHToNonbb_2017"* ]]; then NJOBS=2; fi
        if [[ ${SAMPLE}_${YEAR} == *"ttHToNonbb_2018"* ]]; then NJOBS=2; fi
        if [[ ${SAMPLE}_${YEAR} == *"TTWJetsToLNu_2016"* ]]; then NJOBS=6; fi
        if [[ ${SAMPLE}_${YEAR} == *"TTWJetsToLNu_2017"* ]]; then NJOBS=6; fi
        if [[ ${SAMPLE}_${YEAR} == *"TTWJetsToLNu_2018"* ]]; then NJOBS=6; fi
        if [[ ${SAMPLE}_${YEAR} == *"WZTo3LNu_2016"* ]]; then NJOBS=1; fi
        if [[ ${SAMPLE}_${YEAR} == *"WZTo3LNu_2017"* ]]; then NJOBS=6; fi
        if [[ ${SAMPLE}_${YEAR} == *"WZTo3LNu_2018"* ]]; then NJOBS=6; fi
        if [[ ${SAMPLE}_${YEAR} == *"tZq_ll_4f_ckm_NLO_2016"* ]]; then NJOBS=7; fi
        if [[ ${SAMPLE}_${YEAR} == *"tZq_ll_4f_ckm_NLO_2017"* ]]; then NJOBS=7; fi
        if [[ ${SAMPLE}_${YEAR} == *"tZq_ll_4f_ckm_NLO_2018"* ]]; then NJOBS=7; fi
        if [[ ${SAMPLE}_${YEAR} == *"TTZToLLNuNu_M-10_2016"* ]]; then NJOBS=7; fi
        if [[ ${SAMPLE}_${YEAR} == *"TTZToLLNuNu_M-10_2017"* ]]; then NJOBS=5; fi
        if [[ ${SAMPLE}_${YEAR} == *"TTZToLLNuNu_M-10_2018"* ]]; then NJOBS=7; fi
        if [[ ${SAMPLE}_${YEAR} == *"TTTT_2017"* ]]; then NJOBS=2; fi
        if [[ ${SAMPLE}_${YEAR} == *"TTTT_2018"* ]]; then NJOBS=7; fi
        if [[ ${SAMPLE}_${YEAR} == *"ZZTo4L_2016"* ]]; then NJOBS=2; fi
        if [[ ${SAMPLE}_${YEAR} == *"ZZTo4L_2017"* ]]; then NJOBS=20; fi
        if [[ ${SAMPLE}_${YEAR} == *"ZZTo4L_2018"* ]]; then NJOBS=20; fi

        if [[ ${STUDY} == "os" ]]; then
            if [[ ${SAMPLE}_${YEAR} == *"DYJetsToLL_M-50_2016"* ]]; then NJOBS=10; fi        #   1886.3
            if [[ ${SAMPLE}_${YEAR} == *"DYJetsToLL_M-50_2016"* ]]; then NJOBS=10; fi        #   1900.1
            if [[ ${SAMPLE}_${YEAR} == *"DYJetsToLL_M-50_2016"* ]]; then NJOBS=5; fi         #   946.1
            if [[ ${SAMPLE}_${YEAR} == *"DoubleEG_Run2016_2016"* ]]; then NJOBS=5; fi        #   1031.0
            if [[ ${SAMPLE}_${YEAR} == *"DoubleEG_Run2017_2017"* ]]; then NJOBS=6; fi        #   1201.3
            if [[ ${SAMPLE}_${YEAR} == *"EGamma_Run2018_2018"* ]]; then NJOBS=9; fi          #   1831.5
            if [[ ${SAMPLE}_${YEAR} == *"DoubleMuon_Run2016_2016"* ]]; then NJOBS=11; fi     #   2208.1
            if [[ ${SAMPLE}_${YEAR} == *"DoubleMuon_Run2017_2017"* ]]; then NJOBS=12; fi     #   2449.8
            if [[ ${SAMPLE}_${YEAR} == *"DoubleMuon_Run2018_2018"* ]]; then NJOBS=35; fi     #   3474.0
            # if [[ ${SAMPLE}_${YEAR} == *"SingleElectron_Run2016_2016"* ]]; then NJOBS=4; fi  #   803.8
            # if [[ ${SAMPLE}_${YEAR} == *"SingleElectron_Run2017_2017"* ]]; then NJOBS=5; fi  #   971.4
            # if [[ ${SAMPLE}_${YEAR} == *"SingleMuon_Run2016_2016"* ]]; then NJOBS=9; fi      #   1751.2
            # if [[ ${SAMPLE}_${YEAR} == *"SingleMuon_Run2017_2017"* ]]; then NJOBS=10; fi     #   2026.6
            # if [[ ${SAMPLE}_${YEAR} == *"SingleMuon_Run2018_2018"* ]]; then NJOBS=10; fi     #   2765.8
            if [[ ${SAMPLE}_${YEAR} == *"TTJets_DiLept_2016"* ]]; then NJOBS=2; fi           #   247.9
            if [[ ${SAMPLE}_${YEAR} == *"TTJets_DiLept_2017"* ]]; then NJOBS=5; fi           #   930.3
            if [[ ${SAMPLE}_${YEAR} == *"TTJets_DiLept_2018"* ]]; then NJOBS=5; fi           #   968.1
        fi

        if [[ ${STUDY} == "createMini" ]]; then
            if [[ ${SAMPLE}_${YEAR} == *"DYJetsToLL_M-50_2016"* ]]; then NJOBS=10; fi        #   1886.3
            if [[ ${SAMPLE}_${YEAR} == *"DYJetsToLL_M-50_2016"* ]]; then NJOBS=10; fi        #   1900.1
            if [[ ${SAMPLE}_${YEAR} == *"DYJetsToLL_M-50_2016"* ]]; then NJOBS=10; fi         #   946.1
            if [[ ${SAMPLE}_${YEAR} == *"DoubleEG_Run2016_2016"* ]]; then NJOBS=10; fi        #   1031.0
            if [[ ${SAMPLE}_${YEAR} == *"DoubleEG_Run2017_2017"* ]]; then NJOBS=10; fi        #   1201.3
            if [[ ${SAMPLE}_${YEAR} == *"EGamma_Run2018_2018"* ]]; then NJOBS=10; fi          #   1831.5
            if [[ ${SAMPLE}_${YEAR} == *"DoubleMuon_Run2016_2016"* ]]; then NJOBS=11; fi     #   2208.1
            if [[ ${SAMPLE}_${YEAR} == *"DoubleMuon_Run2017_2017"* ]]; then NJOBS=12; fi     #   2449.8
            if [[ ${SAMPLE}_${YEAR} == *"DoubleMuon_Run2018_2018"* ]]; then NJOBS=35; fi     #   3474.0
            if [[ ${SAMPLE}_${YEAR} == *"SingleElectron_Run2016_2016"* ]]; then NJOBS=10; fi  #   803.8
            if [[ ${SAMPLE}_${YEAR} == *"SingleElectron_Run2017_2017"* ]]; then NJOBS=10; fi  #   971.4
            if [[ ${SAMPLE}_${YEAR} == *"SingleMuon_Run2016_2016"* ]]; then NJOBS=10; fi      #   1751.2
            if [[ ${SAMPLE}_${YEAR} == *"SingleMuon_Run2017_2017"* ]]; then NJOBS=10; fi     #   2026.6
            if [[ ${SAMPLE}_${YEAR} == *"SingleMuon_Run2018_2018"* ]]; then NJOBS=10; fi     #   2765.8
            if [[ ${SAMPLE}_${YEAR} == *"TTJets_DiLept_2016"* ]]; then NJOBS=10; fi           #   247.9
            if [[ ${SAMPLE}_${YEAR} == *"TTJets_DiLept_2017"* ]]; then NJOBS=10; fi           #   930.3
            if [[ ${SAMPLE}_${YEAR} == *"TTJets_DiLept_2018"* ]]; then NJOBS=10; fi           #   968.1
            if [[ ${SAMPLE}_${YEAR} == *"TTTo2L2Nu_2016"* ]]; then NJOBS=30; fi           #   247.9
            if [[ ${SAMPLE}_${YEAR} == *"TTTo2L2Nu_2017"* ]]; then NJOBS=30; fi           #   930.3
            if [[ ${SAMPLE}_${YEAR} == *"TTTo2L2Nu_2018"* ]]; then NJOBS=30; fi           #   968.1
        fi

        NJOBSMAXIDX=$((NJOBS - 1))

        FILELIST=$(ls ${NANOSKIMDIR}/${SAMPLEWITHUNDERSCORE}*${NANOTAG}*${EXTRATAG}*/merged/output.root | tr '\n' ',')
        FILENAME=output
        for IJOB in $(seq 0 ${NJOBSMAXIDX}); do
            if [ -z "${DEBUG}" ]; then
                echo "rm -f ${HISTDIR}/${SAMPLE}_${FILENAME}_${IJOB}.root; ${EXECUTABLE} -t Events -o ${HISTDIR}/${SAMPLE}_${FILENAME}_${IJOB}.root --scale1fb ${SCALE1FB} -j ${NJOBS} -I ${IJOB} -i ${FILELIST} > ${HISTDIR}/${SAMPLE}_${FILENAME}_${IJOB}.log 2>&1" >> .jobs.txt
            else
                echo "rm -f ${HISTDIR}/${SAMPLE}_${FILENAME}_${IJOB}.root; ${EXECUTABLE} -n 50000 -t Events -o ${HISTDIR}/${SAMPLE}_${FILENAME}_${IJOB}.root --scale1fb ${SCALE1FB} -j ${NJOBS} -I ${IJOB} -i ${FILELIST} > ${HISTDIR}/${SAMPLE}_${FILENAME}_${IJOB}.log 2>&1" >> .jobs.txt
            fi
        done


    done

done

xargs.sh .jobs.txt
