#ifndef LEPSCALEFACTORS_H
#define LEPSCALEFACTORS_H
#include "Nano.h"
#include "Base.h"

namespace ttH {
    float getElecPOGLooseSFErr(float eta, float pt, int year);
    float getMuonTightSFErr(float eta, float pt, int year);
    float getElecLooseSF(float eta, float pt, int year);
    float getMuonLooseSFErr(float eta, float pt, int year);
    float getMuonTightSF(float eta, float pt, int year);
    float getElecTightSFErr(float eta, float pt, int year);
    float getMuonLooseSF(float eta, float pt, int year);
    float getElecPOGLooseSF(float eta, float pt, int year);
    float getElecTightSF(float eta, float pt, int year);
    float getElecLooseSFErr(float eta, float pt, int year);
    float getElecRecoEffSFErr(float eta, float pt, int year);
    float getElecRecoEffSF(float eta, float pt, int year);
}

#endif
