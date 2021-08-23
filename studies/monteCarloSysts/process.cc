#include "Nano.h"
#include "rooutil.h"
#include "cxxopts.h"
#include "Base.h"
#include "ElectronSelections.h"
#include "MuonSelections.h"

#include <iostream>
#include <fstream>

#include "VBSHWW.h"

#define VBSLV(name) vbs.tx.getBranchLazy<LV>(name)
#define VBSINT(name) vbs.tx.getBranchLazy<int>(name)
#define VBSVINT(name) vbs.tx.getBranchLazy<vector<int>>(name)

// ./process INPUTFILEPATH OUTPUTFILE [NEVENTS]
int main(int argc, char** argv)
{

    VBSHWW vbs(argc, argv);

    vbs.tx.createBranch<float>("LHE_muF0p5_muR0p5");
    vbs.tx.createBranch<float>("LHE_muF1p0_muR0p5");
    vbs.tx.createBranch<float>("LHE_muF2p0_muR0p5");
    vbs.tx.createBranch<float>("LHE_muF0p5_muR1p0");
    vbs.tx.createBranch<float>("LHE_muF2p0_muR1p0");
    vbs.tx.createBranch<float>("LHE_muF0p5_muR2p0");
    vbs.tx.createBranch<float>("LHE_muF1p0_muR2p0");
    vbs.tx.createBranch<float>("LHE_muF2p0_muR2p0");
    vbs.tx.createBranch<float>("LHE_pdf_wgt_up");
    vbs.tx.createBranch<float>("LHE_pdf_wgt_dn");

    vbs.initSRCutflow();

    vbs.cutflow.getCut("SelectSignalGenPart");
    vbs.cutflow.addCutToLastActiveCut(
        "LHEWeights",
        [&]()
        {
            if (nt.isData())
            {
                return true;
            }
            // Get scale weights
            if (vbs.hasLHEScaleWeight)
            {
                vector<float> scale_weights = nt.LHEScaleWeight();
                // Save scale weights
                // From Events->GetListOfBranches()->ls("LHEScaleWeights*"):
                //     LHE scale variation weights (w_var / w_nominal); 
                //     [0] is MUF="0.5" MUR="0.5"; 
                //     [1] is MUF="1.0" MUR="0.5"; 
                //     [2] is MUF="2.0" MUR="0.5"; 
                //     [3] is MUF="0.5" MUR="1.0"; 
                //     [4] is MUF="2.0" MUR="1.0"; 
                //     [5] is MUF="0.5" MUR="2.0"; 
                //     [6] is MUF="1.0" MUR="2.0"; 
                //     [7] is MUF="2.0" MUR="2.0";
                vbs.tx.setBranch<float>("LHE_muF0p5_muR0p5", scale_weights.at(0));
                vbs.tx.setBranch<float>("LHE_muF1p0_muR0p5", scale_weights.at(1));
                vbs.tx.setBranch<float>("LHE_muF2p0_muR0p5", scale_weights.at(2));
                vbs.tx.setBranch<float>("LHE_muF0p5_muR1p0", scale_weights.at(3));
                vbs.tx.setBranch<float>("LHE_muF2p0_muR1p0", scale_weights.at(4));
                vbs.tx.setBranch<float>("LHE_muF0p5_muR2p0", scale_weights.at(5));
                vbs.tx.setBranch<float>("LHE_muF1p0_muR2p0", scale_weights.at(6));
                vbs.tx.setBranch<float>("LHE_muF2p0_muR2p0", scale_weights.at(7));
            }
            // Get PDF weights
            vector<float> pdf_weights = nt.LHEPdfWeight();
            // Get average of PDF weights
            float pdf_wgt_avg = 0.;
            for (auto& pdf_wgt : pdf_weights)
            {
                pdf_wgt_avg += pdf_wgt;
            }
            pdf_wgt_avg /= pdf_weights.size();
            // Get std. of PDF weights
            float pdf_wgt_var = 0.;
            for (auto& pdf_wgt : pdf_weights)
            {
                pdf_wgt_var += std::pow(pdf_wgt - pdf_wgt_avg, 2);
            }
            float pdf_wgt_std = std::sqrt(pdf_wgt_var/(pdf_weights.size() - 1));
            // Save up/down variations of average PDF weight
            vbs.tx.setBranch<float>("LHE_pdf_wgt_up", pdf_wgt_avg + pdf_wgt_std);
            vbs.tx.setBranch<float>("LHE_pdf_wgt_dn", pdf_wgt_avg - pdf_wgt_std);
            return true;
        }, 
        UNITY
    );

    vbs.cutflow.bookCutflows();

    // Looping input file
    while (vbs.looper.nextEvent())
    {

        // If splitting jobs are requested then determine whether to process the event or not based on remainder
        if (vbs.job_index != -1 and vbs.nsplit_jobs > 0)
        {
            if (vbs.looper.getNEventsProcessed() % vbs.nsplit_jobs != (unsigned int) vbs.job_index)
                continue;
        }

        vbs.process("AK4CategPresel");
    }

    // Writing output file
    vbs.cutflow.saveOutput();

    // Write the data structure to the root file
    vbs.tx.write();

    // The below can be sometimes crucial
    delete vbs.output_tfile;
}
