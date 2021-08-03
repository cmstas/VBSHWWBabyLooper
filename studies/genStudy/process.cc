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

    RooUtil::HistMap hmap("/home/users/phchang/public_html/analysis/hwh/VBSHWWBabyLooper____/data/gen_reweight.root:signal_rewgt");

    vbs.cutflow.getCut("Root");
    vbs.cutflow.addCut("genStudy",
                       [&]()
                       {
                           if (vbs.looper.getCurrentFileName().Contains("VBSWWH_C2V_4p5") and vbs.looper.getCurrentFileName().Contains("RunIIAutumn18"))
                           {
                               vbs.processGenParticles_VBSWWH();
                           }
                           if (vbs.looper.getCurrentFileName().Contains("RunIISummer20UL18_VBSWWH_incl"))
                           {
                               vbs.processGenParticles_VBSWWH_UL();
                           }
                           return true;
                       },
                       [&]()
                       {
                           if (nt.isData())
                           {
                               vbs.tx.setBranch<float>("wgt", 1.);
                           }
                           else
                           {
                               float wgt = ((nt.Generator_weight() > 0) - (nt.Generator_weight() < 0)) * vbs.scale1fb;
                               vbs.tx.setBranch<float>("wgt", wgt * 137);
                           }
                           return vbs.tx.getBranch<float>("wgt");
                       });
    vbs.cutflow.addCutToLastActiveCut("isvbswwhlvlvbb",
                       [&]()
                       {
                           return vbs.tx.getBranch<int>("iswwhlvlvbb");
                       }, UNITY);
    vbs.cutflow.addCutToLastActiveCut("rewgt", UNITY,
                       [&]()
                       {
                           float rewgt = 1;
                           if (vbs.looper.getCurrentFileName().Contains("RunIISummer20UL18_VBSWWH_incl"))
                           {
                               // rewgt = hmap.eval(vbs.tx.getBranch<LV>("gen_lep1").pt());
                               // rewgt = hmap.eval(vbs.tx.getBranch<float>("gen_cosThetaStarA"), vbs.tx.getBranch<float>("gen_cosThetaStarB"));
                               rewgt  = hmap.eval(vbs.tx.getBranch<float>("gen_cosThetaStarA")) * hmap.eval(vbs.tx.getBranch<float>("gen_cosThetaStarB"));
                           }
                           vbs.tx.setBranch<float>("genrewgt", rewgt);
                           return rewgt;
                       });
    vbs.cutflow.addCutToLastActiveCut("leadlep",
                       [&]()
                       {
                           if (not (vbs.tx.getBranch<LV>("gen_lep0").pt() > 40.))
                               return false;
                           return true;
                       }, UNITY);
    vbs.cutflow.addCutToLastActiveCut("subllep",
                       [&]()
                       {
                           if (not (vbs.tx.getBranch<LV>("gen_lep1").pt() > 40.))
                               return false;
                           return true;
                       }, UNITY);
    vbs.cutflow.addCutToLastActiveCut("jets",
                       [&]()
                       {
                           if (not (vbs.tx.getBranch<LV>("gen_b0").pt() > 20. and vbs.tx.getBranch<LV>("gen_b1").pt() > 20.))
                               return false;
                           if (not (vbs.tx.getBranch<LV>("gen_jet0").pt() > 30. and vbs.tx.getBranch<LV>("gen_jet1").pt() > 30.))
                               return false;
                           return true;
                       }, UNITY);
    vbs.cutflow.getCut("rewgt");
    vbs.cutflow.addCutToLastActiveCut("pp",
                       [&]()
                       {
                           return vbs.tx.getBranch<int>("gen_sign") == 1;
                       }, UNITY);
    vbs.cutflow.getCut("rewgt");
    vbs.cutflow.addCutToLastActiveCut("mm",
                       [&]()
                       {
                           return vbs.tx.getBranch<int>("gen_sign") == 0;
                       }, UNITY);

    vbs.histograms.addHistogram("GenLepPt0"        , 180 , 0  , 1500 , [&]() { return vbs.tx.getBranch<LV>("gen_lep0").pt();  } );
    vbs.histograms.addHistogram("GenLepPt1"        , 180 , 0  , 1500 , [&]() { return vbs.tx.getBranch<LV>("gen_lep1").pt();  } );
    vbs.histograms.addHistogram("GenLepPt0Zoom"    , 180 , 0  , 400  , [&]() { return vbs.tx.getBranch<LV>("gen_lep0").pt();  } );
    vbs.histograms.addHistogram("GenLepPt1Zoom"    , 180 , 0  , 400  , [&]() { return vbs.tx.getBranch<LV>("gen_lep1").pt();  } );
    vbs.histograms.addHistogram("GenLepEta0"       , 180 , -6 , 6    , [&]() { return vbs.tx.getBranch<LV>("gen_lep0").eta(); } );
    vbs.histograms.addHistogram("GenLepEta1"       , 180 , -6 , 6    , [&]() { return vbs.tx.getBranch<LV>("gen_lep1").eta(); } );
    vbs.histograms.addHistogram("GenNuPt0"         , 180 , 0  , 1500 , [&]() { return vbs.tx.getBranch<LV>("gen_nu0").pt();   } );
    vbs.histograms.addHistogram("GenNuPt1"         , 180 , 0  , 1500 , [&]() { return vbs.tx.getBranch<LV>("gen_nu1").pt();   } );
    vbs.histograms.addHistogram("GenNuEta0"        , 180 , -6 , 6    , [&]() { return vbs.tx.getBranch<LV>("gen_nu0").eta();  } );
    vbs.histograms.addHistogram("GenNuEta1"        , 180 , -6 , 6    , [&]() { return vbs.tx.getBranch<LV>("gen_nu1").eta();  } );
    vbs.histograms.addHistogram("GenBPt0"          , 180 , 0  , 1500 , [&]() { return vbs.tx.getBranch<LV>("gen_b0").pt();    } );
    vbs.histograms.addHistogram("GenBPt1"          , 180 , 0  , 1500 , [&]() { return vbs.tx.getBranch<LV>("gen_b1").pt();    } );
    vbs.histograms.addHistogram("GenBEta0"         , 180 , -6 , 6    , [&]() { return vbs.tx.getBranch<LV>("gen_b0").eta();   } );
    vbs.histograms.addHistogram("GenBEta1"         , 180 , -6 , 6    , [&]() { return vbs.tx.getBranch<LV>("gen_b1").eta();   } );
    vbs.histograms.addHistogram("GenJPt0"          , 180 , 0  , 150  , [&]() { return vbs.tx.getBranch<LV>("gen_jet0").pt();  } );
    vbs.histograms.addHistogram("GenJPt1"          , 180 , 0  , 150  , [&]() { return vbs.tx.getBranch<LV>("gen_jet1").pt();  } );
    vbs.histograms.addHistogram("GenJEta0"         , 180 , -6 , 6    , [&]() { return vbs.tx.getBranch<LV>("gen_jet0").eta(); } );
    vbs.histograms.addHistogram("GenJEta1"         , 180 , -6 , 6    , [&]() { return vbs.tx.getBranch<LV>("gen_jet1").eta(); } );
    vbs.histograms.addHistogram("GenWPt0"          , 180 , 0  , 1500 , [&]() { return vbs.tx.getBranch<LV>("gen_w0").pt();    } );
    vbs.histograms.addHistogram("GenWPt1"          , 180 , 0  , 1500 , [&]() { return vbs.tx.getBranch<LV>("gen_w1").pt();    } );
    vbs.histograms.addHistogram("GenHPt"           , 180 , 0  , 1500 , [&]() { return vbs.tx.getBranch<LV>("gen_h").pt();     } );
    vbs.histograms.addHistogram("GenLT"            , 180 , 0  , 2500 , [&]() { return vbs.tx.getBranch<LV>("gen_lep0").pt()+vbs.tx.getBranch<LV>("gen_lep1").pt()+(vbs.tx.getBranch<LV>("gen_nu0")+vbs.tx.getBranch<LV>("gen_nu0")).pt();     } );
    vbs.histograms.addHistogram("GenST"            , 180 , 0  , 2500 , [&]() { return vbs.tx.getBranch<LV>("gen_b0").pt()+vbs.tx.getBranch<LV>("gen_b1").pt()+vbs.tx.getBranch<LV>("gen_lep0").pt()+vbs.tx.getBranch<LV>("gen_lep1").pt()+(vbs.tx.getBranch<LV>("gen_nu0")+vbs.tx.getBranch<LV>("gen_nu0")).pt();     } );
    vbs.histograms.addHistogram("GenWM0"           , 180 , 50 , 150  , [&]() { return vbs.tx.getBranch<LV>("gen_w0").mass();    } );
    vbs.histograms.addHistogram("GenWM1"           , 180 , 50 , 150  , [&]() { return vbs.tx.getBranch<LV>("gen_w1").mass();    } );
    vbs.histograms.addHistogram("GenHM"            , 180 , 50 , 150  , [&]() { return vbs.tx.getBranch<LV>("gen_h").mass();     } );
    vbs.histograms.addHistogram("GenDRbb"          , 180 , 0  , 10   , [&]() { return RooUtil::Calc::DeltaR(vbs.tx.getBranch<LV>("gen_b0"), vbs.tx.getBranch<LV>("gen_b1"));    } );
    vbs.histograms.addHistogram("GenDRll"          , 180 , 0  , 10   , [&]() { return RooUtil::Calc::DeltaR(vbs.tx.getBranch<LV>("gen_lep0"), vbs.tx.getBranch<LV>("gen_lep1"));    } );
    vbs.histograms.addHistogram("GenDRjj"          , 180 , 0  , 10   , [&]() { return RooUtil::Calc::DeltaR(vbs.tx.getBranch<LV>("gen_jet0"), vbs.tx.getBranch<LV>("gen_jet1"));    } );
    vbs.histograms.addHistogram("GenDEtajj"        , 180 , 0  , 10   , [&]() { return fabs(RooUtil::Calc::DeltaEta(vbs.tx.getBranch<LV>("gen_jet0"), vbs.tx.getBranch<LV>("gen_jet1")));    } );
    vbs.histograms.addHistogram("GenMjj"           , 180 , 0  , 3500 , [&]() { return (vbs.tx.getBranch<LV>("gen_jet0")+vbs.tx.getBranch<LV>("gen_jet1")).mass();    } );
    vbs.histograms.addHistogram("GenCosThetaStarA" , 180 , -1 , 1    , [&]() { return vbs.tx.getBranch<float>("gen_cosThetaStarA");    } );
    vbs.histograms.addHistogram("GenCosThetaStarB" , 180 , -1 , 1    , [&]() { return vbs.tx.getBranch<float>("gen_cosThetaStarB");    } );

    vbs.histograms.add2DHistogram("ThetaStar0", 7, -1.01, 1.01, "ThetaStar1", 7, -1.01, 1.01, [&]() { return vbs.tx.getBranch<float>("gen_cosThetaStarA"); }, [&]() { return vbs.tx.getBranch<float>("gen_cosThetaStarB"); });

    // Book the histograms
    vbs.cutflow.bookCutflows();
    // vbs.cutflow.bookEventLists();
    vbs.cutflow.bookHistogramsForCutAndBelow(vbs.histograms, "isvbswwhlvlvbb");

    // Looping input file
    while (vbs.looper.nextEvent())
    {

        // If splitting jobs are requested then determine whether to process the event or not based on remainder
        if (vbs.job_index != -1 and vbs.nsplit_jobs > 0)
        {
            if (vbs.looper.getNEventsProcessed() % vbs.nsplit_jobs != (unsigned int) vbs.job_index)
                continue;
        }

        vbs.process("genStudy");

    }
    // Writing output file
    vbs.cutflow.saveOutput();

    // Write the data structure to the root file
    vbs.tx.write();

    // The below can be sometimes crucial
    delete vbs.output_tfile;
}
