#!/bin/bash

python write_datacards.py

C2VS="0 1 3 4 4p5 m1 m2 m2p5"

for C2V in ${C2VS}; do
    combineCards.py -S \
        b1=datacards/cut_c2v${C2V}/datacard_bin1.txt \
        b2=datacards/cut_c2v${C2V}/datacard_bin2.txt \
        b3=datacards/cut_c2v${C2V}/datacard_bin3.txt \
        b4=datacards/cut_c2v${C2V}/datacard_bin4.txt \
        b5=datacards/cut_c2v${C2V}/datacard_bin5.txt \
        > datacards/cut_c2v${C2V}_combined.txt
    combineCards.py -S \
        b1=datacards/bdt_c2v${C2V}/datacard_bin1.txt \
        b2=datacards/bdt_c2v${C2V}/datacard_bin2.txt \
        b3=datacards/bdt_c2v${C2V}/datacard_bin3.txt \
        b4=datacards/bdt_c2v${C2V}/datacard_bin4.txt \
        > datacards/bdt_c2v${C2V}_combined.txt
done

echo "Cut-based analysis data card written here:"
echo "   datacards/cut_c2v*_combined.txt"
echo ""
echo "BDT-based analysis data card written here:"
echo "   datacards/bdt_c2v*_combined.txt"
echo ""
echo "To run limit do something like:"
echo "   sh run_limits.sh"
