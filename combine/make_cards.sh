#!/bin/bash

python write_datacards.py

combineCards.py \
    b1=datacards/cut/datacard_bin1.txt \
    b2=datacards/cut/datacard_bin2.txt \
    b3=datacards/cut/datacard_bin3.txt \
    b4=datacards/cut/datacard_bin4.txt \
    b5=datacards/cut/datacard_bin5.txt \
    > datacards/cut_combined.txt

combineCards.py \
    b1=datacards/bdt/datacard_bin1.txt \
    b2=datacards/bdt/datacard_bin2.txt \
    b3=datacards/bdt/datacard_bin3.txt \
    b4=datacards/bdt/datacard_bin4.txt \
    > datacards/bdt_combined.txt

echo "Cut-based analysis data card written here:"
echo "   datacards/cut_combined.txt"
echo ""
echo "BDT-based analysis data card written here:"
echo "   datacards/bdt_combined.txt"
echo ""
echo "To run limit do something like:"
echo "   combine -M AsymptoticLimits datacards/bdt_combined.txt"
