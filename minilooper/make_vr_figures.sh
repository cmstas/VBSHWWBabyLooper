# python plot.py v2.3_SS Run2 Nominal "PreselMbbOff__VRsLT,Presel2MbbOff__VRsLT,Presel3MbbOff__VRsLT,LooseVRMbbOff__VRsLT"

rm -f .plotjobs.txt
echo 'python plot.py v2.3_SS Run2 Nominal VRPlots "LTMbbOff__STVarBin,LTMbbOff__LTVarBin,LTMbbOff__MJJVarBin,LTMbbOff__DEtaJJVarBin"         '       >> .plotjobs.txt
echo 'python plot.py v2.3_SS Run2 Nominal VRPlots "LLMbbOff__STVarBin,LLMbbOff__LTVarBin,LLMbbOff__MJJVarBin,LLMbbOff__DEtaJJVarBin"         '       >> .plotjobs.txt
echo 'python plot.py v2.3_SS Run2 Nominal VRPlots "PSLTMbbOff__STVarBin,PSLTMbbOff__LTVarBin,PSLTMbbOff__MJJVarBin,PSLTMbbOff__DEtaJJVarBin" '       >> .plotjobs.txt
echo 'python plot.py v2.3_SS Run2 Nominal VRPlots "PSLLMbbOff__STVarBin,PSLLMbbOff__LTVarBin,PSLLMbbOff__MJJVarBin,PSLLMbbOff__DEtaJJVarBin" '       >> .plotjobs.txt

echo 'python plot.py v2.3_SS Run2 Nominal VRPlots "LTMbbOff__LeptonPt0Zoom,LTMbbOff__LeptonPt1Zoom,LTMbbOff__BJetPt0,LTMbbOff__BJetPt1,LTMbbOff__MET" '       >> .plotjobs.txt
echo 'python plot.py v2.3_SS Run2 Nominal VRPlots "LLMbbOff__LeptonPt0Zoom,LLMbbOff__LeptonPt1Zoom,LLMbbOff__BJetPt0,LLMbbOff__BJetPt1,LLMbbOff__MET" '       >> .plotjobs.txt
echo 'python plot.py v2.3_SS Run2 Nominal VRPlots "PSLTMbbOff__LeptonPt0Zoom,PSLTMbbOff__LeptonPt1Zoom,PSLTMbbOff__BJetPt0,PSLTMbbOff__BJetPt1,PSLTMbbOff__MET" '       >> .plotjobs.txt
echo 'python plot.py v2.3_SS Run2 Nominal VRPlots "PSLLMbbOff__LeptonPt0Zoom,PSLLMbbOff__LeptonPt1Zoom,PSLLMbbOff__BJetPt0,PSLLMbbOff__BJetPt1,PSLLMbbOff__MET" '       >> .plotjobs.txt

xargs.sh .plotjobs.txt
