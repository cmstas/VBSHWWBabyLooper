#ifndef TRIGGERSCALEFACTORS_H
#define TRIGGERSCALEFACTORS_H
#include <math.h>

float get2MuonTriggerEffSF(float pt, int year);
float get2MuonTriggerEffSFErr(int year);
float getMuonElecTriggerEffSF(float pt, int year);
float getMuonElecTriggerEffSFErr(int year);
float get2ElecTriggerEffSF(float pt, int year);
float get2ElecTriggerEffSFErr(int year);

float getTauChannelElecTriggerSF(float eta, float pt, int year);

float getTauChannelElecTriggerSFErr();

float getTauChannelMuonTriggerSF(float eta, float pt, int year);

float getTauChannelMuonTriggerSFErr();

#endif