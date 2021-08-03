#!/bin/bash

TAG=v2.4_SS
RUNTAG=Nominal
BABYVERSION=v1

PLOTNAME=LooseVRMbbAll__BDTSR
python ../rooutil/yield_for_keynote.py plots/${RUNTAG}/${TAG}/${BABYVERSION}/Run2/SRYield/${PLOTNAME}.txt | tr ',' ' ' | col 26 | tail -n 4 | head -n 4 | echo "sigs    = ["$(paste -d"," - - - -)"]"
python ../rooutil/yield_for_keynote.py plots/${RUNTAG}/${TAG}/${BABYVERSION}/Run2/SRYield/${PLOTNAME}.txt | tr ',' ' ' | col 28 | tail -n 4 | head -n 4 | echo "sigerrs = ["$(paste -d"," - - - -)"]"
python ../rooutil/yield_for_keynote.py plots/${RUNTAG}/${TAG}/${BABYVERSION}/Run2/SRYield/${PLOTNAME}.txt | tr ',' ' ' | col 20 | tail -n 4 | head -n 4 | echo "bkgs    = ["$(paste -d"," - - - -)"]"
python ../rooutil/yield_for_keynote.py plots/${RUNTAG}/${TAG}/${BABYVERSION}/Run2/SRYield/${PLOTNAME}.txt | tr ',' ' ' | col 22 | tail -n 4 | head -n 4 | echo "bkgerrs = ["$(paste -d"," - - - -)"]"

PLOTNAME=LooseVRMbbAll__CutSR
python ../rooutil/yield_for_keynote.py plots/${RUNTAG}/${TAG}/${BABYVERSION}/Run2/SRYield/${PLOTNAME}.txt | tr ',' ' ' | col 26 | tail -n 5 | head -n 5 | echo "sigs    = ["$(paste -d"," - - - - -)"]"
python ../rooutil/yield_for_keynote.py plots/${RUNTAG}/${TAG}/${BABYVERSION}/Run2/SRYield/${PLOTNAME}.txt | tr ',' ' ' | col 28 | tail -n 5 | head -n 5 | echo "sigerrs = ["$(paste -d"," - - - - -)"]"
python ../rooutil/yield_for_keynote.py plots/${RUNTAG}/${TAG}/${BABYVERSION}/Run2/SRYield/${PLOTNAME}.txt | tr ',' ' ' | col 20 | tail -n 5 | head -n 5 | echo "bkgs    = ["$(paste -d"," - - - - -)"]"
python ../rooutil/yield_for_keynote.py plots/${RUNTAG}/${TAG}/${BABYVERSION}/Run2/SRYield/${PLOTNAME}.txt | tr ',' ' ' | col 22 | tail -n 5 | head -n 5 | echo "bkgerrs = ["$(paste -d"," - - - - -)"]"

PLOTNAME=LooseVRMbbAll__BDTSR2
python ../rooutil/yield_for_keynote.py plots/${RUNTAG}/${TAG}/${BABYVERSION}/Run2/SRYield/${PLOTNAME}.txt | tr ',' ' ' | col 26 | tail -n 4 | head -n 4 | echo "sigs    = ["$(paste -d"," - - - -)"]"
python ../rooutil/yield_for_keynote.py plots/${RUNTAG}/${TAG}/${BABYVERSION}/Run2/SRYield/${PLOTNAME}.txt | tr ',' ' ' | col 28 | tail -n 4 | head -n 4 | echo "sigerrs = ["$(paste -d"," - - - -)"]"
python ../rooutil/yield_for_keynote.py plots/${RUNTAG}/${TAG}/${BABYVERSION}/Run2/SRYield/${PLOTNAME}.txt | tr ',' ' ' | col 20 | tail -n 4 | head -n 4 | echo "bkgs    = ["$(paste -d"," - - - -)"]"
python ../rooutil/yield_for_keynote.py plots/${RUNTAG}/${TAG}/${BABYVERSION}/Run2/SRYield/${PLOTNAME}.txt | tr ',' ' ' | col 22 | tail -n 4 | head -n 4 | echo "bkgerrs = ["$(paste -d"," - - - -)"]"

PLOTNAME=LooseVRMbbAll__CutSR2
python ../rooutil/yield_for_keynote.py plots/${RUNTAG}/${TAG}/${BABYVERSION}/Run2/SRYield/${PLOTNAME}.txt | tr ',' ' ' | col 26 | tail -n 4 | head -n 4 | echo "sigs    = ["$(paste -d"," - - - -)"]"
python ../rooutil/yield_for_keynote.py plots/${RUNTAG}/${TAG}/${BABYVERSION}/Run2/SRYield/${PLOTNAME}.txt | tr ',' ' ' | col 28 | tail -n 4 | head -n 4 | echo "sigerrs = ["$(paste -d"," - - - -)"]"
python ../rooutil/yield_for_keynote.py plots/${RUNTAG}/${TAG}/${BABYVERSION}/Run2/SRYield/${PLOTNAME}.txt | tr ',' ' ' | col 20 | tail -n 4 | head -n 4 | echo "bkgs    = ["$(paste -d"," - - - -)"]"
python ../rooutil/yield_for_keynote.py plots/${RUNTAG}/${TAG}/${BABYVERSION}/Run2/SRYield/${PLOTNAME}.txt | tr ',' ' ' | col 22 | tail -n 4 | head -n 4 | echo "bkgerrs = ["$(paste -d"," - - - -)"]"
