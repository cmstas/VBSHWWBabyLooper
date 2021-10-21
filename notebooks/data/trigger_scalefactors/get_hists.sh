# From ttH docs: https://gitlab.cern.ch/ttH_leptons/doc/-/blob/master/Legacy/data_to_mc_corrections.md#trigger-efficiency-scale-factors-in-1l1tau-and-1l2tau
baseurl="https://raw.githubusercontent.com/HEP-KBFI/tth-htt/master/data/triggerSF"

years="
2016
2017
2018
"

hists2016="
Electron_Ele25WPTight_eff.root 
Muon_Mu22OR_eta2p1_eff.root
"

hists2017="
Electron_Ele32orEle35_eff.root
Muon_IsoMu24orIsoMu27_eff.root
"

hists2018="
Electron_Run2018_Ele32orEle35.root
Muon_Run2018_IsoMu24orIsoMu27.root
"

for year in $years; do
    hists=""
    if [[ "$year" == "2016" ]]; then
        hists=$hists2016
    elif [[ "$year" == "2017" ]]; then
        hists=$hists2017
    elif [[ "$year" == "2018" ]]; then
        hists=$hists2018
    fi
    for hist in $hists; do
        tocurl="${baseurl}/${hist}"
        echo "Fetching $tocurl"
        curl -O -L "$tocurl"
    done
done
