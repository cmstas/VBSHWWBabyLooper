#!/bin/bash

TAG=v2
YEAR=2016
RUNTAG=NominalXsecSF

rm -f .plotjobs.txt
echo 'python plot.py v2.3_SS '${YEAR}' '${RUNTAG}' '${TAG}' VRVarBin "LTMbbOff__STVarBin,LTMbbOff__LTVarBin,LTMbbOff__MJJVarBin,LTMbbOff__DEtaJJVarBin"         '                              >> .plotjobs.txt
echo 'python plot.py v2.3_SS '${YEAR}' '${RUNTAG}' '${TAG}' VRVarBin "LLMbbOff__STVarBin,LLMbbOff__LTVarBin,LLMbbOff__MJJVarBin,LLMbbOff__DEtaJJVarBin"         '                              >> .plotjobs.txt
echo 'python plot.py v2.3_SS '${YEAR}' '${RUNTAG}' '${TAG}' VRVarBin "PSLTMbbOff__STVarBin,PSLTMbbOff__LTVarBin,PSLTMbbOff__MJJVarBin,PSLTMbbOff__DEtaJJVarBin" '                              >> .plotjobs.txt
echo 'python plot.py v2.3_SS '${YEAR}' '${RUNTAG}' '${TAG}' VRVarBin "PSLLMbbOff__STVarBin,PSLLMbbOff__LTVarBin,PSLLMbbOff__MJJVarBin,PSLLMbbOff__DEtaJJVarBin" '                              >> .plotjobs.txt

echo 'python plot.py v2.3_SS '${YEAR}' '${RUNTAG}' '${TAG}' VRShatKine "LTMbbOff__LeptonPt0Zoom,LTMbbOff__LeptonPt1Zoom,LTMbbOff__BJetPt0,LTMbbOff__BJetPt1,LTMbbOff__MET" '                   >> .plotjobs.txt
echo 'python plot.py v2.3_SS '${YEAR}' '${RUNTAG}' '${TAG}' VRShatKine "LLMbbOff__LeptonPt0Zoom,LLMbbOff__LeptonPt1Zoom,LLMbbOff__BJetPt0,LLMbbOff__BJetPt1,LLMbbOff__MET" '                   >> .plotjobs.txt
echo 'python plot.py v2.3_SS '${YEAR}' '${RUNTAG}' '${TAG}' VRShatKine "PSLTMbbOff__LeptonPt0Zoom,PSLTMbbOff__LeptonPt1Zoom,PSLTMbbOff__BJetPt0,PSLTMbbOff__BJetPt1,PSLTMbbOff__MET" '         >> .plotjobs.txt
echo 'python plot.py v2.3_SS '${YEAR}' '${RUNTAG}' '${TAG}' VRShatKine "PSLLMbbOff__LeptonPt0Zoom,PSLLMbbOff__LeptonPt1Zoom,PSLLMbbOff__BJetPt0,PSLLMbbOff__BJetPt1,PSLLMbbOff__MET" '         >> .plotjobs.txt

echo 'python plot.py v2.3_SS '${YEAR}' '${RUNTAG}' '${TAG}' VRVBFKine "LTMbbOff__MJJZoom,LTMbbOff__DEtaJJ,LTMbbOff__JetPt0,LTMbbOff__JetPt1,LTMbbOff__JetEta0,LTMbbOff__JetEta1" '             >> .plotjobs.txt
echo 'python plot.py v2.3_SS '${YEAR}' '${RUNTAG}' '${TAG}' VRVBFKine "LLMbbOff__MJJZoom,LLMbbOff__DEtaJJ,LLMbbOff__JetPt0,LLMbbOff__JetPt1,LLMbbOff__JetEta0,LLMbbOff__JetEta1" '             >> .plotjobs.txt
echo 'python plot.py v2.3_SS '${YEAR}' '${RUNTAG}' '${TAG}' VRVBFKine "PSLTMbbOff__MJJZoom,PSLTMbbOff__DEtaJJ,PSLTMbbOff__JetPt0,PSLTMbbOff__JetPt1,PSLTMbbOff__JetEta0,PSLTMbbOff__JetEta1" ' >> .plotjobs.txt
echo 'python plot.py v2.3_SS '${YEAR}' '${RUNTAG}' '${TAG}' VRVBFKine "PSLLMbbOff__MJJZoom,PSLLMbbOff__DEtaJJ,PSLLMbbOff__JetPt0,PSLLMbbOff__JetPt1,PSLLMbbOff__JetEta0,PSLLMbbOff__JetEta1" ' >> .plotjobs.txt

echo 'python plot.py v2.3_SS '${YEAR}' '${RUNTAG}' '${TAG}' VRBDT "LTMbbOff__BDTVarBin" '   >> .plotjobs.txt
echo 'python plot.py v2.3_SS '${YEAR}' '${RUNTAG}' '${TAG}' VRBDT "LLMbbOff__BDTVarBin" '   >> .plotjobs.txt
echo 'python plot.py v2.3_SS '${YEAR}' '${RUNTAG}' '${TAG}' VRBDT "PSLTMbbOff__BDTVarBin2" ' >> .plotjobs.txt
echo 'python plot.py v2.3_SS '${YEAR}' '${RUNTAG}' '${TAG}' VRBDT "PSLLMbbOff__BDTVarBin2" ' >> .plotjobs.txt

echo 'python plot.py v2.3_SS '${YEAR}' '${RUNTAG}' '${TAG}' SRBDT "ElMbbAll__BDT" '  >> .plotjobs.txt
echo 'python plot.py v2.3_SS '${YEAR}' '${RUNTAG}' '${TAG}' SRBDT "MuMbbAll__BDT" '  >> .plotjobs.txt
echo 'python plot.py v2.3_SS '${YEAR}' '${RUNTAG}' '${TAG}' SRBDT "TauMbbAll__BDT" ' >> .plotjobs.txt
echo 'python plot.py v2.3_SS '${YEAR}' '${RUNTAG}' '${TAG}' SRBDT "NegMbbAll__BDT" ' >> .plotjobs.txt

echo 'python plot.py v2.3_SS '${YEAR}' '${RUNTAG}' '${TAG}' SRYield "LooseVRMbbAllSRB__Channels4Bins,LooseVRMbbOnSRA__Channels5Bins" ' >> .plotjobs.txt
echo 'python plot.py v2.3_SS '${YEAR}' '${RUNTAG}' '${TAG}' SRKine "LooseVRMbbOnSRA__ST,LooseVRMbbOnSRA__LT,LooseVRMbbOnSRA__MJJ,LooseVRMbbOnSRA__DEtaJJ,LooseVRMbbOnSRA__Mbb,LooseVRMbbOnSRA__*" ' >> .plotjobs.txt
echo 'python plot.py v2.3_SS '${YEAR}' '${RUNTAG}' '${TAG}' SRBDTKine "LooseVRMbbAllSRB__ST,LooseVRMbbAllSRB__LT,LooseVRMbbAllSRB__MJJ,LooseVRMbbAllSRB__DEtaJJ,LooseVRMbbAllSRB__Mbb,LooseVRMbbAllSRB__*" ' >> .plotjobs.txt

xargs.sh .plotjobs.txt
