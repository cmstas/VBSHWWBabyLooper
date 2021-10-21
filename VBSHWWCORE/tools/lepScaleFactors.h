#ifndef LEPSCALEFACTORS_H
#define LEPSCALEFACTORS_H

float ttH::getElecTightSF(float eta, float pt, int year);
float ttH::getElecLooseSF(float eta, float pt, int year);
float ttH::getElecTTHSFErrPt(float pt, int year);
float ttH::getElecTTHSFErrEta(float eta, int year);
float ttH::getElecTTHSFErr(float eta, float pt, int year, bool up);

float ttH::getMuonTightSF(float eta, float pt, int year);
float ttH::getMuonLooseSF(float eta, float pt, int year);
float ttH::getMuonTTHSFErrPt(float pt, int year);
float ttH::getMuonTTHSFErrEta(float eta, int year);
float ttH::getMuonTTHSFErr(float eta, float pt, int year, bool up);


float ttH::getElecPOGLooseSF(float eta, float pt, int year);
float ttH::getElecPOGLooseSFErr(float eta, float pt, int year);

float ttH::getElecRecoEffSF(float eta, float pt, int year);
float ttH::getElecRecoEffSFErr(float eta, float pt, int year);
float ttH::getElecRecoEffSFUL(float eta, float pt, int year);
float ttH::getElecRecoEffSFULErr(float eta, float pt, int year);
float ttH::getElecRecoEffSFUL2016preVFP(float eta, float pt);
float ttH::getElecRecoEffSFULErr2016preVFP(float eta, float pt);
float ttH::getElecRecoEffSFUL2016postVFP(float eta, float pt);
float ttH::getElecRecoEffSFULErr2016postVFP(float eta, float pt);
#endif
