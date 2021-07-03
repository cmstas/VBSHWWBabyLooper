#ifndef LEPSCALEFACTORS_H
#define LEPSCALEFACTORS_H
#include "Nano.h"
#include "Base.h"

namespace ttH {
    float getElecTightSF(float eta, float pt, int year);
    float getMuonTightSF(float eta, float pt, int year);
    float getElecLooseSF(float eta, float pt, int year);
    float getMuonLooseSF(float eta, float pt, int year);
    float getElecPOGLooseSF(float eta, float pt, int year);
    float getElecRecoEffSF(float eta, float pt, int year);
    float getMuonPOGMediumSF2016GH(float eta, float pt);
    float getMuonPOGMediumSF2016BCDEF(float eta, float pt);
    float getMuonPOGMediumSF(float eta, float pt, int year);
}

#endif
