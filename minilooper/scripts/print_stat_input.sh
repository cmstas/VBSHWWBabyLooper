#!/bin/bash

TAG=v2.4_SS
RUNTAG=Nominal
BABYVERSION=v1

PLOTNAME=LooseVRMbbAllSRB__Channels4Bins
python ../rooutil/yield_for_keynote.py plots/${RUNTAG}/${TAG}/${BABYVERSION}/Run2/SRYield/${PLOTNAME}.txt | tr ',' ' ' | col 29 | tail -n 5 | head -n 4 | echo "sigs    = ["$(paste -d"," - - - -)"]"
python ../rooutil/yield_for_keynote.py plots/${RUNTAG}/${TAG}/${BABYVERSION}/Run2/SRYield/${PLOTNAME}.txt | tr ',' ' ' | col 31 | tail -n 5 | head -n 4 | echo "sigerrs = ["$(paste -d"," - - - -)"]"
python ../rooutil/yield_for_keynote.py plots/${RUNTAG}/${TAG}/${BABYVERSION}/Run2/SRYield/${PLOTNAME}.txt | tr ',' ' ' | col 20 | tail -n 5 | head -n 4 | echo "bkgs    = ["$(paste -d"," - - - -)"]"
python ../rooutil/yield_for_keynote.py plots/${RUNTAG}/${TAG}/${BABYVERSION}/Run2/SRYield/${PLOTNAME}.txt | tr ',' ' ' | col 22 | tail -n 5 | head -n 4 | echo "bkgerrs = ["$(paste -d"," - - - -)"]"

PLOTNAME=LooseVRMbbOnSRA__Channels5Bins
python ../rooutil/yield_for_keynote.py plots/${RUNTAG}/${TAG}/${BABYVERSION}/Run2/SRYield/${PLOTNAME}.txt | tr ',' ' ' | col 29 | tail -n 6 | head -n 5 | echo "sigs    = ["$(paste -d"," - - - - -)"]"
python ../rooutil/yield_for_keynote.py plots/${RUNTAG}/${TAG}/${BABYVERSION}/Run2/SRYield/${PLOTNAME}.txt | tr ',' ' ' | col 31 | tail -n 6 | head -n 5 | echo "sigerrs = ["$(paste -d"," - - - - -)"]"
python ../rooutil/yield_for_keynote.py plots/${RUNTAG}/${TAG}/${BABYVERSION}/Run2/SRYield/${PLOTNAME}.txt | tr ',' ' ' | col 20 | tail -n 6 | head -n 5 | echo "bkgs    = ["$(paste -d"," - - - - -)"]"
python ../rooutil/yield_for_keynote.py plots/${RUNTAG}/${TAG}/${BABYVERSION}/Run2/SRYield/${PLOTNAME}.txt | tr ',' ' ' | col 22 | tail -n 6 | head -n 5 | echo "bkgerrs = ["$(paste -d"," - - - - -)"]"
