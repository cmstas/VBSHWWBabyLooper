#ifndef LEPSCALEFACTORS_H
#define LEPSCALEFACTORS_H
#include "Nano.h"
#include "Base.h"

namespace ttH {
    float getElecTightSF(float eta, float pt, int year);
    float getElecLooseSF(float eta, float pt, int year);
    float getElecTTHSFErrPt(float pt, int year);
    float getElecTTHSFErrEta(float eta, int year);
    float getElecTTHSFErr(float eta, float pt, int year, bool up);

    float getMuonTightSF(float eta, float pt, int year);
    float getMuonLooseSF(float eta, float pt, int year);
    float getMuonTTHSFErrPt(float pt, int year);
    float getMuonTTHSFErrEta(float eta, int year);
    float getMuonTTHSFErr(float eta, float pt, int year, bool up);

    float getElecPOGLooseSF(float eta, float pt, int year);
    float getElecPOGLooseSFErr(float eta, float pt, int year);

    float getElecRecoEffSF(float eta, float pt, int year);
    float getElecRecoEffSFErr(float eta, float pt, int year);
    float getElecRecoEffSFUL(float eta, float pt, int year);
    float getElecRecoEffSFULErr(float eta, float pt, int year);
    float getElecRecoEffSFUL2016preVFP(float eta, float pt);
    float getElecRecoEffSFULErr2016preVFP(float eta, float pt);
    float getElecRecoEffSFUL2016postVFP(float eta, float pt);
    float getElecRecoEffSFULErr2016postVFP(float eta, float pt);
}

#endif
