#include "Nano.h"
#include "rooutil.h"
#include "cxxopts.h"
#include "Base.h"
#include "ElectronSelections.h"
#include "MuonSelections.h"

#include "VBSHWW.h"

// ./process INPUTFILEPATH OUTPUTFILE [NEVENTS]
int main(int argc, char** argv)
{

    VBSHWW vbs(argc, argv);

    vbs.initSRCutflow();

    vbs.cutflow.removeCut("SSPreselection");

    vbs.cutflow.getCut("ObjectsSelection");

    //*****************************
    // - Opposite Sign Preselection
    //*****************************
    // Description: Pass events only when we have:
    //              - at least one light lepton (no ditau-had)
    //              - two loose
    //              - two tight
    //              - they are same sign
    //              - all pass pt > 25
    vbs.cutflow.addCutToLastActiveCut("OSPreselection",
        [&]()
        {

            // Only three loose leptons
            if (not (vbs.tx.getBranchLazy<vector<LV>>("good_leptons_p4").size() == 2))
                return false;

            int ntight = 0;
            for (auto& istight : vbs.tx.getBranch<vector<int>>("good_leptons_tight"))
            {
                if (istight)
                    ntight++;
            }

            // Select only two tight leptons
            if (not (ntight == 2))
                return false;

            float pt0 = vbs.tx.getBranchLazy<vector<LV>>("good_leptons_p4")[0].pt();
            float pt1 = vbs.tx.getBranchLazy<vector<LV>>("good_leptons_p4")[1].pt();

            if (not (pt0 > 40. and pt1 > 40.))
                return false;

            const int& trig_ee = vbs.tx.getBranch<int>("trig_ee");
            const int& trig_em = vbs.tx.getBranch<int>("trig_em");
            const int& trig_mm = vbs.tx.getBranch<int>("trig_mm");
            const int& pass_duplicate_ee_em_mm = vbs.tx.getBranch<int>("pass_duplicate_ee_em_mm");
            bool pass_trigger = trig_ee or trig_em or trig_mm;
            bool duplicate = nt.isData() ? pass_duplicate_ee_em_mm : 1.;
            return (pass_trigger and duplicate);

        },
        [&]() { return vbs.tx.getBranch<float>("lepsf"); } );

    vbs.cutflow.addCutToLastActiveCut("ComputeBTagSF",
        [&]()
        {
            // Compute b-tagging scale factor

            std::vector<float> pts;
            std::vector<float> etas;
            std::vector<float> scores;
            std::vector<int> flavors;

            for (unsigned int i = 0; i < vbs.tx.getBranchLazy<vector<LV>>("good_jets_p4").size(); ++i)
            {
                const LV& jet = vbs.tx.getBranchLazy<vector<LV>>("good_jets_p4")[i];
                if (fabs(jet.eta()) < 2.4)
                {
                    pts.push_back(jet.pt());
                    etas.push_back(jet.eta());
                    scores.push_back(vbs.tx.getBranchLazy<vector<float>>("good_jets_btag_score")[i]);
                    flavors.push_back(vbs.tx.getBranchLazy<vector<int>>("good_jets_flavor")[i]);
                }
            }

            vbs.setBTagSF(pts, etas, scores, flavors);
            std::cout <<  " vbs.tx.getBranch<float>('btagsf'): " << vbs.tx.getBranch<float>("btagsf") <<  std::endl;
            return true;
        }, UNITY);

    vbs.cutflow.addCutToLastActiveCut("BTagSF",
        [&]()
        {
            return true;
        },
        [&]()
        {
            return vbs.tx.getBranch<float>("btagsf");
        });


    vbs.cutflow.getCut("BTagSF");
    vbs.cutflow.addCutToLastActiveCut("OSEE", [&]() { return (vbs.tx.getBranchLazy<vector<int>>("good_leptons_pdgid")[0] * vbs.tx.getBranchLazy<vector<int>>("good_leptons_pdgid")[1] == -121); }, UNITY);
    vbs.cutflow.getCut("BTagSF");
    vbs.cutflow.addCutToLastActiveCut("OSEM", [&]() { return (vbs.tx.getBranchLazy<vector<int>>("good_leptons_pdgid")[0] * vbs.tx.getBranchLazy<vector<int>>("good_leptons_pdgid")[1] == -143); }, UNITY);
    vbs.cutflow.getCut("BTagSF");
    vbs.cutflow.addCutToLastActiveCut("OSMM", [&]() { return (vbs.tx.getBranchLazy<vector<int>>("good_leptons_pdgid")[0] * vbs.tx.getBranchLazy<vector<int>>("good_leptons_pdgid")[1] == -169); }, UNITY);

    vbs.cutflow.printCuts();

    RooUtil::Histograms tlhistograms;
    tlhistograms.addHistogram("OSLepPt0", 180, 0, 180, [&]() { return vbs.tx.getBranchLazy<vector<LV>>("good_leptons_p4")[0].pt(); } );
    tlhistograms.addHistogram("OSLepPt1", 180, 0, 180, [&]() { return vbs.tx.getBranchLazy<vector<LV>>("good_leptons_p4")[1].pt(); } );
    tlhistograms.addHistogram("OSLepEta0", 180, -3, 3, [&]() { return vbs.tx.getBranchLazy<vector<LV>>("good_leptons_p4")[0].eta(); } );
    tlhistograms.addHistogram("OSLepEta1", 180, -3, 3, [&]() { return vbs.tx.getBranchLazy<vector<LV>>("good_leptons_p4")[1].eta(); } );
    tlhistograms.addHistogram("OSMLL", 180, 0, 450, [&]() { return (vbs.tx.getBranchLazy<vector<LV>>("good_leptons_p4")[0]+vbs.tx.getBranchLazy<vector<LV>>("good_leptons_p4")[1]).mass(); } );
    tlhistograms.addHistogram("OSNBLoose", 5, 0, 5, [&]() { return vbs.tx.getBranchLazy<int>("nbloose"); } );
    tlhistograms.addHistogram("OSNBMedium", 5, 0, 5, [&]() { return vbs.tx.getBranchLazy<int>("nbmedium"); } );
    tlhistograms.addHistogram("OSNBTight", 5, 0, 5, [&]() { return vbs.tx.getBranchLazy<int>("nbtight"); } );
    tlhistograms.addHistogram("OSNJets", 10, 0, 10, [&]() { return vbs.tx.getBranchLazy<vector<LV>>("good_jets_p4").size(); } );
    tlhistograms.addHistogram("OSJetPt0", 180, 0, 180, [&]() { if (vbs.tx.getBranchLazy<vector<LV>>("good_jets_p4").size() > 0) return vbs.tx.getBranchLazy<vector<LV>>("good_jets_p4")[0].pt(); else return -999.f; } );
    tlhistograms.addHistogram("OSJetPt1", 180, 0, 180, [&]() { if (vbs.tx.getBranchLazy<vector<LV>>("good_jets_p4").size() > 1) return vbs.tx.getBranchLazy<vector<LV>>("good_jets_p4")[1].pt(); else return -999.f; } );
    tlhistograms.addHistogram("OSJetPt2", 180, 0, 180, [&]() { if (vbs.tx.getBranchLazy<vector<LV>>("good_jets_p4").size() > 2) return vbs.tx.getBranchLazy<vector<LV>>("good_jets_p4")[2].pt(); else return -999.f; } );
    tlhistograms.addHistogram("OSJetPt3", 180, 0, 180, [&]() { if (vbs.tx.getBranchLazy<vector<LV>>("good_jets_p4").size() > 3) return vbs.tx.getBranchLazy<vector<LV>>("good_jets_p4")[3].pt(); else return -999.f; } );
    tlhistograms.addHistogram("OSJetPt4", 180, 0, 180, [&]() { if (vbs.tx.getBranchLazy<vector<LV>>("good_jets_p4").size() > 4) return vbs.tx.getBranchLazy<vector<LV>>("good_jets_p4")[4].pt(); else return -999.f; } );
    tlhistograms.addHistogram("OSJetEta0", 180, -5, 5, [&]() { if (vbs.tx.getBranchLazy<vector<LV>>("good_jets_p4").size() > 0) return vbs.tx.getBranchLazy<vector<LV>>("good_jets_p4")[0].eta(); else return -999.f; } );
    tlhistograms.addHistogram("OSJetEta1", 180, -5, 5, [&]() { if (vbs.tx.getBranchLazy<vector<LV>>("good_jets_p4").size() > 1) return vbs.tx.getBranchLazy<vector<LV>>("good_jets_p4")[1].eta(); else return -999.f; } );
    tlhistograms.addHistogram("OSJetEta2", 180, -5, 5, [&]() { if (vbs.tx.getBranchLazy<vector<LV>>("good_jets_p4").size() > 2) return vbs.tx.getBranchLazy<vector<LV>>("good_jets_p4")[2].eta(); else return -999.f; } );
    tlhistograms.addHistogram("OSJetEta3", 180, -5, 5, [&]() { if (vbs.tx.getBranchLazy<vector<LV>>("good_jets_p4").size() > 3) return vbs.tx.getBranchLazy<vector<LV>>("good_jets_p4")[3].eta(); else return -999.f; } );
    tlhistograms.addHistogram("OSJetEta4", 180, -5, 5, [&]() { if (vbs.tx.getBranchLazy<vector<LV>>("good_jets_p4").size() > 4) return vbs.tx.getBranchLazy<vector<LV>>("good_jets_p4")[4].eta(); else return -999.f; } );

    vbs.cutflow.bookHistogramsForCutAndBelow(tlhistograms, "OSPreselection");
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

        vbs.process("OSPreselection");

    }

    // Writing output file
    vbs.cutflow.saveOutput();

    // Write the data structure to the root file
    vbs.tx.write();

    // Write out the "run:lumi:evt" of the events passing a certain cut into a text file
    // If the output.root is "output/path/dir/name.root"
    // then the text file will be named "output/path/dir/name_CutName.txt"
    vbs.writeEventList("OSPreselection");

    // The below can be sometimes crucial
    delete vbs.output_tfile;
}
