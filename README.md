# Running code

    make cleanall
    make clean
    make -j
    python python/vbshww.py # At the bottom configured
    python python/topest.py HistV1 v2.6 miniNtupV1 Run2
    sh python/make_figures.sh HistV1 v2.6 miniNtupV1 Run2 phchang

# Running HiggsCombine

Start with a different terminal

    cd combine
    source /cvmfs/cms.cern.ch/cmsset_default.sh

Following line has to be done once. Once setup next time one can skip. 

    source install_higgs_combine.sh # Only have to do this once

Next time, just run the following to setup it up:

    source setup.sh

Now write the data cards

    sh make_cards.sh

The output of the data cards are located in ```datacards/```  
For example, ```datacards/bdt_c2v4p5_combined.txt``` contains the 4 bin fit of the BDT anlysis for c2v = 4.5.  
```datacards/bdt_c2v4p5/``` directory contains the individual bin's data cards.  

Now to run the asymptotic limits, run the following:

    sh run_asymptotic_limits.sh run_1

The script is not parallelized although it is easily doable.  
Take a look at the script to see how they are configured.
Currently it is configured to run over ```bdt``` analysis.
It will take about 5 mins to run all.  

Then to print out the limits in each c2v coupling points, use the following script.  
Also take a look at the script to see how they are ocnfigured.
Currently it is configured to print the limit value obtained from running ```bdt``` limits from previous step.

    sh print_asymptotic_limits.sh run_1 # Same tag value. e.g. 'run_1'

This will parse and write the results into a python script in ```limits/run_1_asymptotic_results.py```

To plot the result

    python plot.py run_1 # Same tag value e.g. 'run_1'

The output will be in ```limit.pdf/png```


## To run toys

To run toys, instead of running ```sh run_asymptotic_limits.sh``` command one runs ```sh run_toy_limits.sh```.  
The script is provided, but have not obtained a stable results yet.  




