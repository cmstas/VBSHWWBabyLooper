#include "triggerScaleFactors.h"

float getTauChannelElecTriggerSF(float eta, float pt, int year) {
    // Electron_Ele25WPTight_eff.root
    if (year == 2016) {
        if (fabs(eta) < 1.48) {
            // ZMassEtaLt1p48_Data/ZMassEtaLt1p48_MC
            if (pt >= 10 && pt < 13) return 0.640075;
            if (pt >= 13 && pt < 16) return 0.640075;
            if (pt >= 16 && pt < 17) return 0.640075;
            if (pt >= 17 && pt < 18) return 0.640075;
            if (pt >= 18 && pt < 19) return 0.640075;
            if (pt >= 19 && pt < 20) return 0.640075;
            if (pt >= 20 && pt < 21) return 0.640075;
            if (pt >= 21 && pt < 22) return 0.640075;
            if (pt >= 22 && pt < 23) return 1.05276;
            if (pt >= 23 && pt < 24) return 0.733427;
            if (pt >= 24 && pt < 25) return 0.574785;
            if (pt >= 25 && pt < 26) return 0.69848;
            if (pt >= 26 && pt < 27) return 0.809285;
            if (pt >= 27 && pt < 28) return 0.844293;
            if (pt >= 28 && pt < 31) return 0.898106;
            if (pt >= 31 && pt < 34) return 0.963971;
            if (pt >= 34 && pt < 37) return 0.987391;
            if (pt >= 37 && pt < 40) return 0.997276;
            if (pt >= 40 && pt < 45) return 1.01045;
            if (pt >= 45 && pt < 50) return 1.00815;
            if (pt >= 50 && pt < 60) return 1.00376;
            if (pt >= 60 && pt < 70) return 0.99911;
            if (pt >= 70 && pt < 100) return 0.995693;
            if (pt >= 100 && pt < 200) return 0.991463;
            if (pt >= 200) return 0.984173;
        }
        if (fabs(eta) < 2.1 && fabs(eta) >= 1.48) {
            // ZMassEta1p48to2p1_Data/ZMassEta1p48to2p1_MC
            if (pt >= 10 && pt < 13) return 0.133615;
            if (pt >= 13 && pt < 16) return 0.133615;
            if (pt >= 16 && pt < 17) return 0.133615;
            if (pt >= 17 && pt < 18) return 0.133615;
            if (pt >= 18 && pt < 19) return 0.133615;
            if (pt >= 19 && pt < 20) return 0.133615;
            if (pt >= 20 && pt < 21) return 0.133615;
            if (pt >= 21 && pt < 22) return 0.473273;
            if (pt >= 22 && pt < 23) return 0.461825;
            if (pt >= 23 && pt < 24) return 0.327531;
            if (pt >= 24 && pt < 25) return 0.372219;
            if (pt >= 25 && pt < 26) return 0.578549;
            if (pt >= 26 && pt < 27) return 0.758031;
            if (pt >= 27 && pt < 28) return 0.839272;
            if (pt >= 28 && pt < 31) return 0.901959;
            if (pt >= 31 && pt < 34) return 0.945008;
            if (pt >= 34 && pt < 37) return 0.962914;
            if (pt >= 37 && pt < 40) return 0.972706;
            if (pt >= 40 && pt < 45) return 0.978497;
            if (pt >= 45 && pt < 50) return 0.978681;
            if (pt >= 50 && pt < 60) return 0.97276;
            if (pt >= 60 && pt < 70) return 0.96452;
            if (pt >= 70 && pt < 100) return 0.94858;
            if (pt >= 100 && pt < 200) return 0.953721;
            if (pt >= 200) return 0.946359;
        }
        if (fabs(eta) >= 2.1) {
            // ZMassEtaGt2p1_Data/ZMassEtaGt2p1_MC
            if (pt >= 10 && pt < 13) return 0.101253;
            if (pt >= 13 && pt < 16) return 0.101253;
            if (pt >= 16 && pt < 17) return 0.101253;
            if (pt >= 17 && pt < 18) return 0.101253;
            if (pt >= 18 && pt < 19) return 0.101253;
            if (pt >= 19 && pt < 20) return 0.101253;
            if (pt >= 20 && pt < 21) return 0.101253;
            if (pt >= 21 && pt < 22) return 0.101253;
            if (pt >= 22 && pt < 23) return 0.101253;
            if (pt >= 23 && pt < 24) return 0.177443;
            if (pt >= 24 && pt < 25) return 0.206307;
            if (pt >= 25 && pt < 26) return 0.402844;
            if (pt >= 26 && pt < 27) return 0.655335;
            if (pt >= 27 && pt < 28) return 0.760892;
            if (pt >= 28 && pt < 31) return 0.874912;
            if (pt >= 31 && pt < 34) return 0.944634;
            if (pt >= 34 && pt < 37) return 0.99409;
            if (pt >= 37 && pt < 40) return 1.0277;
            if (pt >= 40 && pt < 45) return 1.02254;
            if (pt >= 45 && pt < 50) return 1.0253;
            if (pt >= 50 && pt < 60) return 1.01161;
            if (pt >= 60 && pt < 70) return 0.975866;
            if (pt >= 70 && pt < 100) return 0.907483;
            if (pt >= 100 && pt < 200) return 1.05463;
            if (pt >= 200) return 0.857143;
        }
    }
    // Electron_Ele32orEle35_eff.root
    if (year == 2017) {
        if (fabs(eta) < 1.48) {
            // ZMassEtaLt1p48_Data/ZMassEtaLt1p48_MC
            if (pt >= 10 && pt < 12) return 0.0949295;
            if (pt >= 12 && pt < 14) return 0.0949295;
            if (pt >= 14 && pt < 16) return 0.0949295;
            if (pt >= 16 && pt < 18) return 0.0949295;
            if (pt >= 18 && pt < 20) return 0.0949295;
            if (pt >= 20 && pt < 22) return 0.0949295;
            if (pt >= 22 && pt < 24) return 0.0949295;
            if (pt >= 24 && pt < 26) return 0.0949295;
            if (pt >= 26 && pt < 28) return 0.0949295;
            if (pt >= 28 && pt < 30) return 0.0949295;
            if (pt >= 30 && pt < 32) return 0.0816766;
            if (pt >= 32 && pt < 34) return 0.295379;
            if (pt >= 34 && pt < 36) return 0.575033;
            if (pt >= 36 && pt < 38) return 0.860064;
            if (pt >= 38 && pt < 40) return 0.932596;
            if (pt >= 40 && pt < 45) return 0.956772;
            if (pt >= 45 && pt < 50) return 0.964757;
            if (pt >= 50) return 0.969752;
        }
        if (fabs(eta) < 2.1 && fabs(eta) >= 1.48) {
            // ZMassEta1p48to2p1_Data/ZMassEta1p48to2p1_MC
            if (pt >= 10 && pt < 12) return 0;
            if (pt >= 12 && pt < 14) return 0;
            if (pt >= 14 && pt < 16) return 0;
            if (pt >= 16 && pt < 18) return 0;
            if (pt >= 18 && pt < 20) return 0;
            if (pt >= 20 && pt < 22) return 0;
            if (pt >= 22 && pt < 24) return 0;
            if (pt >= 24 && pt < 26) return 0.285938;
            if (pt >= 26 && pt < 28) return 0.210596;
            if (pt >= 28 && pt < 30) return 0.394865;
            if (pt >= 30 && pt < 32) return 0.0835824;
            if (pt >= 32 && pt < 34) return 0.179206;
            if (pt >= 34 && pt < 36) return 0.450748;
            if (pt >= 36 && pt < 38) return 0.742629;
            if (pt >= 38 && pt < 40) return 0.866064;
            if (pt >= 40 && pt < 45) return 0.920261;
            if (pt >= 45 && pt < 50) return 0.943354;
            if (pt >= 50) return 0.946353;
        }
    }
    // Electron_Run2018_Ele32orEle35.root
    if (year == 2018) {
        if (fabs(eta) < 1.0) {
            // ZMassEtaLt1p0_Data/ZMassEtaLt1p0_MC
            if (pt >= 10 && pt < 12) return 0.42977;
            if (pt >= 12 && pt < 14) return 0.42977;
            if (pt >= 14 && pt < 16) return 0.42977;
            if (pt >= 16 && pt < 18) return 0.42977;
            if (pt >= 18 && pt < 20) return 0.42977;
            if (pt >= 20 && pt < 22) return 0.42977;
            if (pt >= 22 && pt < 24) return 0.42977;
            if (pt >= 24 && pt < 26) return 0.42977;
            if (pt >= 26 && pt < 28) return 0.42977;
            if (pt >= 28 && pt < 30) return 0.42977;
            if (pt >= 30 && pt < 32) return 0.42977;
            if (pt >= 32 && pt < 34) return 0.691522;
            if (pt >= 34 && pt < 36) return 0.92395;
            if (pt >= 36 && pt < 38) return 0.948947;
            if (pt >= 38 && pt < 40) return 0.956814;
            if (pt >= 40 && pt < 45) return 0.959166;
            if (pt >= 45 && pt < 50) return 0.957243;
            if (pt >= 50) return 0.960853;
        }
        if (fabs(eta) < 1.48 && fabs(eta) >= 1.0) {
            // ZMassEta1p0to1p48_Data/ZMassEta1p0to1p48_MC
            if (pt >= 10 && pt < 12) return 0.193087;
            if (pt >= 12 && pt < 14) return 0.193087;
            if (pt >= 14 && pt < 16) return 0.193087;
            if (pt >= 16 && pt < 18) return 0.193087;
            if (pt >= 18 && pt < 20) return 0.193087;
            if (pt >= 20 && pt < 22) return 0.193087;
            if (pt >= 22 && pt < 24) return 0.193087;
            if (pt >= 24 && pt < 26) return 0.193087;
            if (pt >= 26 && pt < 28) return 0.193087;
            if (pt >= 28 && pt < 30) return 0.193087;
            if (pt >= 30 && pt < 32) return 0.316897;
            if (pt >= 32 && pt < 34) return 0.536932;
            if (pt >= 34 && pt < 36) return 0.817198;
            if (pt >= 36 && pt < 38) return 0.90168;
            if (pt >= 38 && pt < 40) return 0.932492;
            if (pt >= 40 && pt < 45) return 0.95524;
            if (pt >= 45 && pt < 50) return 0.964128;
            if (pt >= 50) return 0.970461;
        }
        if (fabs(eta) < 1.65 && fabs(eta) >= 1.48) {
            // ZMassEta1p48to1p65_Data/ZMassEta1p48to1p65_MC
            if (pt >= 10 && pt < 12) return 0;
            if (pt >= 12 && pt < 14) return 0;
            if (pt >= 14 && pt < 16) return 0;
            if (pt >= 16 && pt < 18) return 0;
            if (pt >= 18 && pt < 20) return 0;
            if (pt >= 20 && pt < 22) return 0;
            if (pt >= 22 && pt < 24) return 0;
            if (pt >= 24 && pt < 26) return 0;
            if (pt >= 26 && pt < 28) return 0;
            if (pt >= 28 && pt < 30) return 0.220179;
            if (pt >= 30 && pt < 32) return 0.355059;
            if (pt >= 32 && pt < 34) return 0.576198;
            if (pt >= 34 && pt < 36) return 0.79922;
            if (pt >= 36 && pt < 38) return 0.879509;
            if (pt >= 38 && pt < 40) return 0.917458;
            if (pt >= 40 && pt < 45) return 0.947681;
            if (pt >= 45 && pt < 50) return 0.965108;
            if (pt >= 50) return 0.967061;
        }
        if (fabs(eta) < 2.1 && fabs(eta) >= 1.65) {
            // ZMassEta1p65to2p1_Data/ZMassEta1p65to2p1_MC
            if (pt >= 10 && pt < 12) return 0.248924;
            if (pt >= 12 && pt < 14) return 0.248924;
            if (pt >= 14 && pt < 16) return 0.248924;
            if (pt >= 16 && pt < 18) return 0.248924;
            if (pt >= 18 && pt < 20) return 0.248924;
            if (pt >= 20 && pt < 22) return 0.248924;
            if (pt >= 22 && pt < 24) return 0.248924;
            if (pt >= 24 && pt < 26) return 0.248924;
            if (pt >= 26 && pt < 28) return 0.248924;
            if (pt >= 28 && pt < 30) return 0.248924;
            if (pt >= 30 && pt < 32) return 0.279752;
            if (pt >= 32 && pt < 34) return 0.56177;
            if (pt >= 34 && pt < 36) return 0.887919;
            if (pt >= 36 && pt < 38) return 0.946728;
            if (pt >= 38 && pt < 40) return 0.961366;
            if (pt >= 40 && pt < 45) return 0.974264;
            if (pt >= 45 && pt < 50) return 0.982572;
            if (pt >= 50) return 0.986004;
        }
        if (fabs(eta) >= 2.1) {
            // ZMassEtaGt2p1_Data/ZMassEtaGt2p1_MC
            if (pt >= 10 && pt < 12) return 1;
            if (pt >= 12 && pt < 14) return 1;
            if (pt >= 14 && pt < 16) return 1;
            if (pt >= 16 && pt < 18) return 1;
            if (pt >= 18 && pt < 20) return 1;
            if (pt >= 20 && pt < 22) return 1;
            if (pt >= 22 && pt < 24) return 1;
            if (pt >= 24 && pt < 26) return 1;
            if (pt >= 26 && pt < 28) return 1;
            if (pt >= 28 && pt < 30) return 1;
            if (pt >= 30 && pt < 32) return 1;
            if (pt >= 32 && pt < 34) return 1;
            if (pt >= 34 && pt < 36) return 1;
            if (pt >= 36 && pt < 38) return 1;
            if (pt >= 38 && pt < 40) return 1;
            if (pt >= 40 && pt < 45) return 1;
            if (pt >= 45 && pt < 50) return 1;
            if (pt >= 50) return 1;
        }
    }
    return 0.0;
}

float getTauChannelMuonTriggerSF(float eta, float pt, int year) {
    // Muon_Mu22OR_eta2p1_eff.root
    if (year == 2016) {
        if (fabs(eta) < 0.9) {
            // ZMassEtaLt0p9_Data/ZMassEtaLt0p9_MC
            if (pt >= 10 && pt < 13) return 52.9405;
            if (pt >= 13 && pt < 16) return 52.9405;
            if (pt >= 16 && pt < 17) return 52.9405;
            if (pt >= 17 && pt < 18) return 52.9405;
            if (pt >= 18 && pt < 19) return 52.9405;
            if (pt >= 19 && pt < 20) return 14.2855;
            if (pt >= 20 && pt < 21) return 10.3281;
            if (pt >= 21 && pt < 22) return 1.53321;
            if (pt >= 22 && pt < 23) return 0.964619;
            if (pt >= 23 && pt < 24) return 0.982188;
            if (pt >= 24 && pt < 25) return 0.983313;
            if (pt >= 25 && pt < 26) return 0.979165;
            if (pt >= 26 && pt < 27) return 0.98908;
            if (pt >= 27 && pt < 28) return 0.984278;
            if (pt >= 28 && pt < 31) return 0.984978;
            if (pt >= 31 && pt < 34) return 0.985259;
            if (pt >= 34 && pt < 37) return 0.985161;
            if (pt >= 37 && pt < 40) return 0.985399;
            if (pt >= 40 && pt < 45) return 0.985135;
            if (pt >= 45 && pt < 50) return 0.985045;
            if (pt >= 50 && pt < 60) return 0.984419;
            if (pt >= 60 && pt < 70) return 0.982902;
            if (pt >= 70 && pt < 100) return 0.980477;
            if (pt >= 100 && pt < 200) return 0.980061;
            if (pt >= 200) return 0.993292;
        }
        if (fabs(eta) < 1.2 && fabs(eta) >= 0.9) {
            // ZMassEta0p9to1p2_Data/ZMassEta0p9to1p2_MC
            if (pt >= 10 && pt < 13) return 23.5346;
            if (pt >= 13 && pt < 16) return 23.5346;
            if (pt >= 16 && pt < 17) return 23.5346;
            if (pt >= 17 && pt < 18) return 23.5346;
            if (pt >= 18 && pt < 19) return 8.60465;
            if (pt >= 19 && pt < 20) return 3.87637;
            if (pt >= 20 && pt < 21) return 5.7962;
            if (pt >= 21 && pt < 22) return 1.39413;
            if (pt >= 22 && pt < 23) return 0.937629;
            if (pt >= 23 && pt < 24) return 0.960262;
            if (pt >= 24 && pt < 25) return 0.963112;
            if (pt >= 25 && pt < 26) return 0.960697;
            if (pt >= 26 && pt < 27) return 0.961071;
            if (pt >= 27 && pt < 28) return 0.965981;
            if (pt >= 28 && pt < 31) return 0.966201;
            if (pt >= 31 && pt < 34) return 0.969566;
            if (pt >= 34 && pt < 37) return 0.968024;
            if (pt >= 37 && pt < 40) return 0.966219;
            if (pt >= 40 && pt < 45) return 0.966745;
            if (pt >= 45 && pt < 50) return 0.96631;
            if (pt >= 50 && pt < 60) return 0.965709;
            if (pt >= 60 && pt < 70) return 0.962231;
            if (pt >= 70 && pt < 100) return 0.961169;
            if (pt >= 100 && pt < 200) return 0.945384;
            if (pt >= 200) return 0.930896;
        }
        if (fabs(eta) < 2.1 && fabs(eta) >= 1.2) {
            // ZMassEta1p2to2p1_Data/ZMassEta1p2to2p1_MC
            if (pt >= 10 && pt < 13) return 29.0228;
            if (pt >= 13 && pt < 16) return 29.0228;
            if (pt >= 16 && pt < 17) return 29.0228;
            if (pt >= 17 && pt < 18) return 29.0228;
            if (pt >= 18 && pt < 19) return 29.0228;
            if (pt >= 19 && pt < 20) return 5.18607;
            if (pt >= 20 && pt < 21) return 4.7413;
            if (pt >= 21 && pt < 22) return 1.49164;
            if (pt >= 22 && pt < 23) return 0.968631;
            if (pt >= 23 && pt < 24) return 0.98687;
            if (pt >= 24 && pt < 25) return 0.986627;
            if (pt >= 25 && pt < 26) return 0.988597;
            if (pt >= 26 && pt < 27) return 0.993482;
            if (pt >= 27 && pt < 28) return 0.993848;
            if (pt >= 28 && pt < 31) return 1.00056;
            if (pt >= 31 && pt < 34) return 1.00168;
            if (pt >= 34 && pt < 37) return 1.0035;
            if (pt >= 37 && pt < 40) return 1.00391;
            if (pt >= 40 && pt < 45) return 1.00438;
            if (pt >= 45 && pt < 50) return 1.00522;
            if (pt >= 50 && pt < 60) return 1.00381;
            if (pt >= 60 && pt < 70) return 1.00273;
            if (pt >= 70 && pt < 100) return 1.00428;
            if (pt >= 100 && pt < 200) return 0.996411;
            if (pt >= 200) return 0.998758;
        }
    }
    // Muon_IsoMu24orIsoMu27_eff.root
    if (year == 2017) {
        if (fabs(eta) < 0.9) {
            // ZMassEtaLt0p9_Data/ZMassEtaLt0p9_MC
            if (pt >= 10 && pt < 12) return 0.0862147;
            if (pt >= 12 && pt < 14) return 0.0862147;
            if (pt >= 14 && pt < 16) return 1.78034;
            if (pt >= 16 && pt < 18) return 0;
            if (pt >= 18 && pt < 20) return 0.101279;
            if (pt >= 20 && pt < 22) return 0.66427;
            if (pt >= 22 && pt < 24) return 1.19233;
            if (pt >= 24 && pt < 26) return 0.873149;
            if (pt >= 26 && pt < 28) return 0.929448;
            if (pt >= 28 && pt < 30) return 0.974389;
            if (pt >= 30 && pt < 32) return 0.977951;
            if (pt >= 32 && pt < 34) return 0.977332;
            if (pt >= 34 && pt < 36) return 0.97672;
            if (pt >= 36 && pt < 38) return 0.978761;
            if (pt >= 38 && pt < 40) return 0.976077;
            if (pt >= 40 && pt < 45) return 0.971922;
            if (pt >= 45 && pt < 50) return 0.973202;
            if (pt >= 50) return 0.966981;
        }
        if (fabs(eta) < 1.2 && fabs(eta) >= 0.9) {
            // ZMassEta0p9to1p2_Data/ZMassEta0p9to1p2_MC
            if (pt >= 10 && pt < 12) return 0.0947332;
            if (pt >= 12 && pt < 14) return 0.0947332;
            if (pt >= 14 && pt < 16) return 0.999235;
            if (pt >= 16 && pt < 18) return 0.0920406;
            if (pt >= 18 && pt < 20) return 0.0476326;
            if (pt >= 20 && pt < 22) return 0.163763;
            if (pt >= 22 && pt < 24) return 0.94942;
            if (pt >= 24 && pt < 26) return 0.877235;
            if (pt >= 26 && pt < 28) return 0.933473;
            if (pt >= 28 && pt < 30) return 0.966429;
            if (pt >= 30 && pt < 32) return 0.968243;
            if (pt >= 32 && pt < 34) return 0.962388;
            if (pt >= 34 && pt < 36) return 0.959626;
            if (pt >= 36 && pt < 38) return 0.96353;
            if (pt >= 38 && pt < 40) return 0.960151;
            if (pt >= 40 && pt < 45) return 0.956908;
            if (pt >= 45 && pt < 50) return 0.95635;
            if (pt >= 50) return 0.946155;
        }
        if (fabs(eta) < 2.1 && fabs(eta) >= 1.2) {
            // ZMassEta1p2to2p1_Data/ZMassEta1p2to2p1_MC
            if (pt >= 10 && pt < 12) return 0.337276;
            if (pt >= 12 && pt < 14) return 0.337276;
            if (pt >= 14 && pt < 16) return 0.0535547;
            if (pt >= 16 && pt < 18) return 0.0425471;
            if (pt >= 18 && pt < 20) return 0.115037;
            if (pt >= 20 && pt < 22) return 0.835923;
            if (pt >= 22 && pt < 24) return 1.03804;
            if (pt >= 24 && pt < 26) return 0.920362;
            if (pt >= 26 && pt < 28) return 0.97242;
            if (pt >= 28 && pt < 30) return 1.01745;
            if (pt >= 30 && pt < 32) return 1.0232;
            if (pt >= 32 && pt < 34) return 1.02469;
            if (pt >= 34 && pt < 36) return 1.02665;
            if (pt >= 36 && pt < 38) return 1.02333;
            if (pt >= 38 && pt < 40) return 1.01694;
            if (pt >= 40 && pt < 45) return 1.01223;
            if (pt >= 45 && pt < 50) return 1.00813;
            if (pt >= 50) return 1.00067;
        }
        if (fabs(eta) >= 2.1) {
            // ZMassEtaGt2p1_Data/ZMassEtaGt2p1_MC
            if (pt >= 10 && pt < 12) return 10.9589;
            if (pt >= 12 && pt < 14) return 2.96873;
            if (pt >= 14 && pt < 16) return 0.50187;
            if (pt >= 16 && pt < 18) return 0.429631;
            if (pt >= 18 && pt < 20) return 1.07881;
            if (pt >= 20 && pt < 22) return 1.7122;
            if (pt >= 22 && pt < 24) return 0.910598;
            if (pt >= 24 && pt < 26) return 0.771119;
            if (pt >= 26 && pt < 28) return 0.837024;
            if (pt >= 28 && pt < 30) return 0.90683;
            if (pt >= 30 && pt < 32) return 0.932217;
            if (pt >= 32 && pt < 34) return 0.933818;
            if (pt >= 34 && pt < 36) return 0.946891;
            if (pt >= 36 && pt < 38) return 0.951022;
            if (pt >= 38 && pt < 40) return 0.951832;
            if (pt >= 40 && pt < 45) return 0.955109;
            if (pt >= 45 && pt < 50) return 0.96264;
            if (pt >= 50) return 0.960673;
        }
    }
    // Muon_Run2018_IsoMu24orIsoMu27.root
    if (year == 2018) {
        if (fabs(eta) < 0.9) {
            // ZMassEtaLt0p9_Data/ZMassEtaLt0p9_MC
            if (pt >= 10 && pt < 12) return 1.42306;
            if (pt >= 12 && pt < 14) return 1.42306;
            if (pt >= 14 && pt < 16) return 1.42306;
            if (pt >= 16 && pt < 18) return 1.42306;
            if (pt >= 18 && pt < 20) return 1.42306;
            if (pt >= 20 && pt < 22) return 1.42306;
            if (pt >= 22 && pt < 24) return 1.42306;
            if (pt >= 24 && pt < 26) return 0.950742;
            if (pt >= 26 && pt < 28) return 0.967759;
            if (pt >= 28 && pt < 30) return 0.970653;
            if (pt >= 30 && pt < 32) return 0.975024;
            if (pt >= 32 && pt < 34) return 0.973638;
            if (pt >= 34 && pt < 36) return 0.974572;
            if (pt >= 36 && pt < 38) return 0.976473;
            if (pt >= 38 && pt < 40) return 0.975198;
            if (pt >= 40 && pt < 45) return 0.975775;
            if (pt >= 45 && pt < 50) return 0.975913;
            if (pt >= 50) return 0.974574;
        }
        if (fabs(eta) < 1.2 && fabs(eta) >= 0.9) {
            // ZMassEta0p9to1p2_Data/ZMassEta0p9to1p2_MC
            if (pt >= 10 && pt < 12) return 6.68534;
            if (pt >= 12 && pt < 14) return 6.68534;
            if (pt >= 14 && pt < 16) return 6.68534;
            if (pt >= 16 && pt < 18) return 6.68534;
            if (pt >= 18 && pt < 20) return 6.68534;
            if (pt >= 20 && pt < 22) return 6.68534;
            if (pt >= 22 && pt < 24) return 1.2544;
            if (pt >= 24 && pt < 26) return 0.931516;
            if (pt >= 26 && pt < 28) return 0.951054;
            if (pt >= 28 && pt < 30) return 0.956191;
            if (pt >= 30 && pt < 32) return 0.958891;
            if (pt >= 32 && pt < 34) return 0.961487;
            if (pt >= 34 && pt < 36) return 0.965626;
            if (pt >= 36 && pt < 38) return 0.965622;
            if (pt >= 38 && pt < 40) return 0.966137;
            if (pt >= 40 && pt < 45) return 0.966908;
            if (pt >= 45 && pt < 50) return 0.96649;
            if (pt >= 50) return 0.964976;
        }
        if (fabs(eta) < 2.1 && fabs(eta) >= 1.2) {
            // ZMassEta1p2to2p1_Data/ZMassEta1p2to2p1_MC
            if (pt >= 10 && pt < 12) return 1.45711;
            if (pt >= 12 && pt < 14) return 1.45711;
            if (pt >= 14 && pt < 16) return 1.45711;
            if (pt >= 16 && pt < 18) return 1.45711;
            if (pt >= 18 && pt < 20) return 1.45711;
            if (pt >= 20 && pt < 22) return 1.45711;
            if (pt >= 22 && pt < 24) return 1.45711;
            if (pt >= 24 && pt < 26) return 0.982165;
            if (pt >= 26 && pt < 28) return 0.998148;
            if (pt >= 28 && pt < 30) return 1.00241;
            if (pt >= 30 && pt < 32) return 1.0033;
            if (pt >= 32 && pt < 34) return 1.00255;
            if (pt >= 34 && pt < 36) return 1.004;
            if (pt >= 36 && pt < 38) return 1.00157;
            if (pt >= 38 && pt < 40) return 1.00168;
            if (pt >= 40 && pt < 45) return 1.00111;
            if (pt >= 45 && pt < 50) return 1.00046;
            if (pt >= 50) return 0.997188;
        }
        if (fabs(eta) >= 2.1) {
            // ZMassEtaGt2p1_Data/ZMassEtaGt2p1_MC
            if (pt >= 10 && pt < 12) return 2.289;
            if (pt >= 12 && pt < 14) return 2.289;
            if (pt >= 14 && pt < 16) return 2.289;
            if (pt >= 16 && pt < 18) return 2.289;
            if (pt >= 18 && pt < 20) return 2.289;
            if (pt >= 20 && pt < 22) return 2.289;
            if (pt >= 22 && pt < 24) return 1.26222;
            if (pt >= 24 && pt < 26) return 0.92533;
            if (pt >= 26 && pt < 28) return 0.958186;
            if (pt >= 28 && pt < 30) return 0.980501;
            if (pt >= 30 && pt < 32) return 0.980444;
            if (pt >= 32 && pt < 34) return 0.988364;
            if (pt >= 34 && pt < 36) return 0.992348;
            if (pt >= 36 && pt < 38) return 0.997338;
            if (pt >= 38 && pt < 40) return 0.997535;
            if (pt >= 40 && pt < 45) return 1.00177;
            if (pt >= 45 && pt < 50) return 1.00673;
            if (pt >= 50) return 1.00649;
        }
    }
    return 0.0;
}
