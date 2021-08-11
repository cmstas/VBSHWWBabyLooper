#!/bin/bash

python write_datacards.py

for DIRSTR in $(ls -d datacards/cut_* | grep -v .txt); do
    combineCards.py -S \
        b1=${DIRSTR}/datacard_bin1.txt \
        b2=${DIRSTR}/datacard_bin2.txt \
        b3=${DIRSTR}/datacard_bin3.txt \
        b4=${DIRSTR}/datacard_bin4.txt \
        b5=${DIRSTR}/datacard_bin5.txt \
        > ${DIRSTR}_combined.txt
done

for DIRSTR in $(ls -d datacards/bdt_* | grep -v .txt); do
    combineCards.py -S \
        b1=${DIRSTR}/datacard_bin1.txt \
        b2=${DIRSTR}/datacard_bin2.txt \
        b3=${DIRSTR}/datacard_bin3.txt \
        b4=${DIRSTR}/datacard_bin4.txt \
        > ${DIRSTR}_combined.txt
done

echo "Cut-based analysis data card written here:"
echo "   datacards/cut_c2v*_combined.txt"
echo ""
echo "BDT-based analysis data card written here:"
echo "   datacards/bdt_c2v*_combined.txt"
echo ""
echo "To run limit do something like:"
echo "   sh run_limits.sh"
