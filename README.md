# Producing baby ntuple

Download the code

    git clone --recursive git@github.com:cmstas/VBSHWWBabyLooper.git
    cd VBSHWWBabyLooper

Download JECs

    cd NanoTools/NanoCORE/Tools/jetcorr/data/
    sh download_jecs.sh
    cd -

Compile the code

    source setup.sh
    make clean
    make -j

Run the code

    sh run.sh -a v2       -t v2.5_SS [-S VBSWWHToLNuLNubb_C2V]  # v2 is the tag provided by the user
    sh run.sh -a v2_jecUp -t v2.5_SS [-S VBSWWHToLNuLNubb_C2V]  # _jecUp recognizes that it is to run jecUp variation
    sh run.sh -a v2_jecDn -t v2.5_SS [-S VBSWWHToLNuLNubb_C2V]  # _jecDn recognizes that it is to run jecDn variation

Save the ntuples to nfs area

    sh scripts/publish_baby.sh v2          # Saving v2 to nfs area
    sh scripts/publish_baby.sh v2_jecUp    # Saving v2_jecUp to nfs area
    sh scripts/publish_baby.sh v2_jecDn    # Saving v2_jecDn to nfs area

In case you change something, here is how one can run a test job where each job is limited to 50000 events only

    sh testrun.sh

# Running MiniLooper

First download the code

    git clone --recursive git@github.com:cmstas/VBSHWWBabyLooper.git
    cd VBSHWWBabyLooper

Set up the environment

    source setup.sh

Then compile the code

    cd minilooper
    make clean
    make -j

Run the minilooper

    sh scripts/run.sh Nominal    v2.4_SS    v2    Run2    jguiang # Nominal is the tag you provide

                      ^^^^^^^    ^^^^^^^    ^^    ^^^^    ^^^^^^^
                      |||||||    |||||||    ||    ||||    |||||||
                      Yourtag    NanoSkim  Baby   Year    Username of the nfs-area where the baby is saved

Copy the histogram outputs from the minilooper to your nfs area

    sh scripts/publish_result.sh Nominal v2.4_SS v2 Run2 # Nominal is the tag you provide

Run the extrapolation factor study on the output

    python scripts/alpha_exp.py Nominal    v2.4_SS    v2    Run2    yxiang  # Nominal is the tag you provide

                                ^^^^^^^    ^^^^^^^    ^^    ^^^^    ^^^^^^
                                |||||||    |||||||    ||    ||||    ||||||
                                Yourtag    NanoSkim  Baby   Year    Username of the nfs-area where the histograms are saved

Run the plotter to create a bunch of plots

    sh scripts/make_figures.sh Nominal    v2.4_SS    v2    Run2    yxiang   

                               ^^^^^^^    ^^^^^^^    ^^    ^^^^    ^^^^^^
                               |||||||    |||||||    ||    ||||    ||||||
                               Yourtag    NanoSkim  Baby   Year    Username of the nfs-area where the histograms are saved

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






