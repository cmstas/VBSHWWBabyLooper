#include "Nano.h"
#include "rooutil.h"
#include "cxxopts.h"
#include "Base.h"
#include "ElectronSelections.h"
#include "MuonSelections.h"

#include "VBSHWW.h"

#define VBSLV(name) vbs.tx.getBranchLazy<LV>(name)
#define VBSINT(name) vbs.tx.getBranchLazy<int>(name)
#define VBSVINT(name) vbs.tx.getBranchLazy<vector<int>>(name)

// ./process INPUTFILEPATH OUTPUTFILE [NEVENTS]
int main(int argc, char** argv)
{

    VBSHWW vbs(argc, argv);

    vbs.initSRCutflow();

    // Book the histograms
    vbs.cutflow.bookCutflows();
    vbs.cutflow.bookEventLists();

    // Looping input file
    while (vbs.looper.nextEvent())
    {

        // If splitting jobs are requested then determine whether to process the event or not based on remainder
        if (vbs.job_index != -1 and vbs.nsplit_jobs > 0)
        {
            if (vbs.looper.getNEventsProcessed() % vbs.nsplit_jobs != (unsigned int) vbs.job_index)
                continue;
        }

        vbs.process("AK4CategChannels");
    }

    // Writing output file
    vbs.cutflow.saveOutput();

    // Write the data structure to the root file
    vbs.tx.write();

    // Write out the "run:lumi:evt" of the events passing a certain cut into a text file
    // If the output.root is "output/path/dir/name.root"
    // then the text file will be named "output/path/dir/name_CutName.txt"
    vbs.writeEventList("Root");
    vbs.writeEventList("Weight");
    vbs.writeEventList("Preselection");
    vbs.writeEventList("SelectGenPart");
    vbs.writeEventList("GoodRunsList");
    vbs.writeEventList("EventFilters");
    vbs.writeEventList("SelectLeptons");
    vbs.writeEventList("SSPreselection");
    vbs.writeEventList("Trigger");
    vbs.writeEventList("SelectJets");
    vbs.writeEventList("AK4CategTagHiggsJets");
    vbs.writeEventList("AK4CategTagVBSJets");
    vbs.writeEventList("AK4CategPresel");

    // The below can be sometimes crucial
    delete vbs.output_tfile;
}
