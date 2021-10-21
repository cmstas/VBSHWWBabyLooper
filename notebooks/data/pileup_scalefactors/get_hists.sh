baseurl="https://raw.githubusercontent.com/cms-nanoAOD/nanoAOD-tools/master/python/postprocessing/data/pileup"

hists="
mcPileupUL2016.root
mcPileupUL2017.root
mcPileupUL2018.root
PileupHistogram-UL2016-100bins_withVar.root
PileupHistogram-UL2017-100bins_withVar.root
PileupHistogram-UL2018-100bins_withVar.root
"

for hist in $hists; do
    tocurl="${baseurl}/${hist}"
    echo "Fetching $tocurl"
    curl -O -L "$tocurl"
done
