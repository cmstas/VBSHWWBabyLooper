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

    sh run.sh v2                     # v2 is the tag provided by the user

Save the ntuples to nfs area

    sh scripts/publish_baby.sh v2    # v2 is the tag you just used to run

In case you chage something, here is how one can run a test job where each job is limited to 50000 events only

    sh testrun.sh

# Running MiniLooper

    git clone --recursive git@github.com:cmstas/VBSHWWBabyLooper.git
    cd VBSHWWBabyLooper
    source setup.sh
    cd minilooper
    make clean
    make -j
    sh scripts/run.sh Nominal           # Nominal is the tag you provide
    sh scripts/make_figures.sh Nominal  # Nominal is the tag you provided

If you wish to create a new baby ntuple and loop over a new baby ntuple

    sh scripts/run.sh Nominal SKIMVERSION BABYVERSION YEAR USERNAME
    sh scripts/make_figure.sh Nominal SKIMVERSION BABYVERSION YEAR

# Running HiggsCombine

Start with a different terminal

    cd combine
    source /cvmfs/cms.cern.ch/cmsset_default.sh

Following line has to be done once. Once setup next time one can skip. 

    source install_higgs_combine.sh # Only have to do this once

And then proceed to setup rooutil and do the limite calculation

    source setup.sh
    sh make_cards.sh
    sh run_limits.sh

