#!/bin/bash

print_help()
{
    echo "Usage:"
    echo ""
    echo "  sh get_hists.sh [--fresh] [--debug] [--cert=/path/to/cert.p12]"
    echo ""
    exit 0
}

DEBUG=false
FRESH=false
CERT="${HOME}/private/${USER}.p12"
# Parse arguments
for arg in "$@"; do
    key=$(echo $arg | cut -f1 -d=)
    val=$(echo $arg | cut -f2 -d=)   
    case "$key" in
        -h) print_help;;
        --debug) DEBUG=true;;
        --fresh) FRESH=true;;
        --cert) CERT="${val/#\~/$HOME}";;
    esac
done

years="
2016
2017
2018
"

if [[ "$FRESH" == "true" ]]; then
    for year in $years; do 
        if [[ -d "$year" ]]; then rm -rf $year; fi
    done
fi

# Muon loose POG sfs (not on lxplus!)
if [[ ! -f ~/private/cert.pem || ! -f ~/private/cert.key ]]; then
    if [[ ! -f "$CERT" ]]; then
        echo "ERROR: No cert.p12 file provided, and $CERT does not exist. "
        echo "       Please re-run get_hists.sh with --cert=/path/to/cert.p12"
        echo "       Your CERN certificate is needed to downloaed the Muon POG sfs."
        exit 0
    fi
    echo ""
    echo "NOTE: "
    echo "Muon POG scale factors need to be downloaded from CERN's "
    echo "gitlab area. As such, you must provide your VO credentials; "
    echo "please proceed."
    echo ""
    echo "Extracting cert.pem from $CERT"
    openssl pkcs12 -clcerts -nokeys -in "$CERT" -out ~/private/cert.pem
    echo "Extracting cert.tmp.key from $CERT"
    openssl pkcs12 -nocerts -in "$CERT" -out ~/private/cert.tmp.key
    echo "Extracting cert.key from cert.tmp.key"
    openssl rsa -in ~/private/cert.tmp.key -out ~/private/cert.key
    rm ~/private/cert.tmp.key
    chmod 644 ~/private/cert.pem
    chmod 400 ~/private/cert.key
    echo "Done. New cert.pem and cert.key files have been saved to ${HOME}/private"
fi
baseurl="https://gitlab.cern.ch/cms-muonPOG/muonefficiencies/-/raw/master/Run2"
cern-get-sso-cookie --cert ~/private/cert.pem --key ~/private/cert.key -r -u https://gitlab.cern.ch/cms-muonPOG/muonefficiencies/-/blob/master/Run2/ -o ~/private/ssocookie.txt
for year in $years; do
    mkdir -p ${year}/muons/pog
    if [[ "${year}" == "2016" ]]; then
        tocurl="${baseurl}/UL/2016_postVFP/2016_postVFP_Z/Efficiencies_muon_generalTracks_Z_Run2016_UL_ID.root"
        echo "Fetching ${tocurl}"
        curl --cookie ~/private/ssocookie.txt -L $tocurl -o ${year}/muons/pog/Run${year}_postVFP_UL_ID.root
        tocurl="${baseurl}/UL/2016_preVFP/2016_preVFP_Z/Efficiencies_muon_generalTracks_Z_Run2016_UL_HIPM_ID.root"
        echo "Fetching ${tocurl}"
        curl --cookie ~/private/ssocookie.txt -L $tocurl -o ${year}/muons/pog/Run${year}_preVFP_UL_HIPM_ID.root
    elif [[ "${year}" == "2017" || "${year}" == "2018" ]]; then
        tocurl="${baseurl}/UL/${year}/${year}_Z/Efficiencies_muon_generalTracks_Z_Run${year}_UL_ID.root"
        echo "Fetching ${tocurl}"
        curl --cookie ~/private/ssocookie.txt -L $tocurl -o ${year}/muons/pog/Run${year}_UL_ID.root
    fi
done

scpcommands=()
function newscpcommand() {
    mkdir -p ${2}
    scpcommands+=("echo 'Fetching ${1}'")
    scpcommands+=("scp ${1} ${USER}@uaf-10.t2.ucsd.edu:${PWD}/${2}")
}

# Everything else
odysei="/eos/user/o/odysei/shared/ttH/leptons/data"
veelken="/afs/cern.ch/user/v/veelken/public/ttHAnalysis/leptonSF"
balvarez="/afs/cern.ch/user/b/balvarez/work/public/ttHAnalysis"
for year in $years; do
    # Electron reco sfs
    if [[ "$year" == "2016" ]]; then
        newscpcommand ${veelken}/${year}/el_scaleFactors_gsf_ptLt20.root ${year}/electrons/pog/
        newscpcommand ${veelken}/${year}/el_scaleFactors_gsf_ptGt20.root ${year}/electrons/pog/
    elif [[ "$year" == "2017" ]]; then
        newscpcommand ${odysei}/${year}/SF/ID/el_scaleFactors_gsf_ptLt20.root ${year}/electrons/pog/
        newscpcommand ${odysei}/${year}/SF/ID/el_scaleFactors_gsf_ptGt20.root ${year}/electrons/pog/
    elif [[ "$year" == "2018" ]]; then
        newscpcommand ${veelken}/${year}/el_scaleFactors_gsf.root ${year}/electrons/pog/
    fi
    # Electron loose POG sfs
    newscpcommand ${balvarez}/TnP_loose_ele_${year}.root ${year}/electrons/pog/
    # Electron loose ttH sfs
    newscpcommand ${balvarez}/TnP_loosettH_ele_${year}.root ${year}/electrons/loose/
    # Electron tight ttH sfs
    newscpcommand ${balvarez}/TnP_ttH_ele_${year}_2lss/passttH/egammaEffi.txt_EGM2D.root ${year}/electrons/tight/sf/
    newscpcommand ${balvarez}/error/SFttbar_${year}_ele_pt.root ${year}/electrons/tight/err/
    newscpcommand ${balvarez}/error/SFttbar_${year}_ele_eta.root ${year}/electrons/tight/err/

    # Muon loose ttH sfs
    newscpcommand ${balvarez}/TnP_loose_muon_${year}.root ${year}/muons/loose/
    # Muon tight ttH sfs
    newscpcommand ${balvarez}/TnP_ttH_muon_${year}_2lss/passttH/egammaEffi.txt_EGM2D.root ${year}/muons/tight/sf/
    newscpcommand ${balvarez}/error/SFttbar_${year}_muon_pt.root ${year}/muons/tight/err/
    newscpcommand ${balvarez}/error/SFttbar_${year}_muon_eta.root ${year}/muons/tight/err/
done

if [[ "$DEBUG" == "true" ]]; then
    echo "[DEBUG] I would have run the following commands on ${USER}@lxplus.cern.ch:"
    for scpcmd in "${scpcommands[@]}"; do echo "$scpcmd"; done
    exit 0
fi

echo ""
echo "NOTE: "
echo "ttH scale factor files need to be downloaded from lxplus. "
echo "As such, you will be promped provide your credentials "
echo "for ${USER}@lxplus.cern.ch; please proceed."
echo ""

ssh ${USER}@lxplus.cern.ch << EOM
$(for scpcmd in "${scpcommands[@]}"; do echo "$scpcmd"; done)
EOM
