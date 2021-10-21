#ifndef LEPSCALEFACTORS_H
#define LEPSCALEFACTORS_H
#include "Nano.h"
#include "Base.h"

namespace ttH {
    float getElecTightSF(float eta, float pt, int year);
    float getElecTTHSFErrPt(float eta, float pt, int year);
    float getElecTTHSFErrEta(float eta, float pt, int year);
    float getMuonTightSF(float eta, float pt, int year);
    float getMuonTTHSFErrPt(float eta, float pt, int year);
    float getMuonTTHSFErrEta(float eta, float pt, int year);
    float getElecLooseSF(float eta, float pt, int year);
    float getMuonLooseSF(float eta, float pt, int year);
    float getElecPOGLooseSF(float eta, float pt, int year);
    float getElecPOGLooseSFErr(float eta, float pt, int year);
    float getElecRecoEffSFUL(float eta, float pt, int year);
    float getElecRecoEffSFULErr(float eta, float pt, int year);
    float getElecRecoEffSF(float eta, float pt, int year);
    float getElecRecoEffSFErr(float eta, float pt, int year);
}

#endif
