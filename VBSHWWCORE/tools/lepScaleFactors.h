#ifndef LEPSCALEFACTORS_H
#define LEPSCALEFACTORS_H
#include "Nano.h"
#include "Base.h"

namespace ttH {
    // Electron ttH ID sfs
    float getElecTightSF(float eta, float pt, int year);
    float getElecLooseSF(float eta, float pt, int year);
    float getElecTTHSFErrPt(float pt, int year);
    float getElecTTHSFErrEta(float eta, int year);
    float getElecTTHSFErr(float eta, float pt, int year, bool up); // Note: use this one!
    // Electron POG loose-WP sfs (using files from ttH, loose WP not available from POG)
    float getElecPOGLooseSF(float eta, float pt, int year);
    float getElecPOGLooseSFErr(float eta, float pt, int year);
    // Electron reco eff sfs
    float getElecRecoEffSF(float eta, float pt, int year);
    float getElecRecoEffSFErr(float eta, float pt, int year);
    float getElecRecoEffSFUL(float eta, float pt, int year);
    float getElecRecoEffSFULErr(float eta, float pt, int year);
    // Muon ttH ID sfs
    float getMuonTightSF(float eta, float pt, int year);
    float getMuonLooseSF(float eta, float pt, int year);
    float getMuonTTHSFErrPt(float pt, int year);
    float getMuonTTHSFErrEta(float eta, int year);
    float getMuonTTHSFErr(float eta, float pt, int year, bool up); // Note: use this one!
    // Muon POG medium-WP sfs
    float getMuonPOGMediumSF2016GH(float eta, float pt);
    float getMuonPOGMediumSF2016BCDEF(float eta, float pt);
    float getMuonPOGMediumSF(float eta, float pt, int year);
    float getMuonPOGMediumSFErr2016GH(float eta, float pt);
    float getMuonPOGMediumSFErr2016BCDEF(float eta, float pt);
    float getMuonPOGMediumSFErr(float eta, float pt, int year);
    float getMuonPOGMediumSFUL(float eta, float pt, int year);
    float getMuonPOGMediumSFULErr(float eta, float pt, int year);
}

#endif
