#include "lepScaleFactors.h"

float ttH::getElecTightSF(float eta, float pt, int year) {
    if (year == 2016) {
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 10 && pt < 15) return 0.755435;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 15 && pt < 20) return 0.823245;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 20 && pt < 25) return 0.829126;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 25 && pt < 30) return 0.83156;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 30 && pt < 35) return 0.831597;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 35 && pt < 40) return 0.837012;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 40 && pt < 45) return 0.84375;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 45 && pt < 60) return 0.855784;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 60 && pt < 80) return 0.87156;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 80) return 0.893871;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 10 && pt < 15) return 0.783626;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 15 && pt < 20) return 0.791667;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 20 && pt < 25) return 0.807611;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 25 && pt < 30) return 0.814394;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 30 && pt < 35) return 0.811828;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 35 && pt < 40) return 0.822496;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 40 && pt < 45) return 0.826014;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 45 && pt < 60) return 0.831667;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 60 && pt < 80) return 0.834448;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 80) return 0.856427;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 10 && pt < 15) return 0.8;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 15 && pt < 20) return 0.815884;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 20 && pt < 25) return 0.813514;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 25 && pt < 30) return 0.835267;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 30 && pt < 35) return 0.798283;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 35 && pt < 40) return 0.804082;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 40 && pt < 45) return 0.818356;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 45 && pt < 60) return 0.825368;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 60 && pt < 80) return 0.827094;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 80) return 0.864528;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 10 && pt < 15) return 1.02817;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 15 && pt < 20) return 0.966825;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 20 && pt < 25) return 0.896774;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 25 && pt < 30) return 0.883152;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 30 && pt < 35) return 0.879093;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 35 && pt < 40) return 0.863962;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 40 && pt < 45) return 0.883295;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 45 && pt < 60) return 0.872768;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 60 && pt < 80) return 0.861298;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 80) return 0.893519;
    }
    if (year == 2017) {
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 10 && pt < 15) return 0.751479;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 15 && pt < 20) return 0.820513;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 20 && pt < 25) return 0.837294;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 25 && pt < 30) return 0.842809;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 30 && pt < 35) return 0.851974;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 35 && pt < 40) return 0.870813;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 40 && pt < 45) return 0.872894;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 45 && pt < 60) return 0.881913;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 60 && pt < 80) return 0.886628;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 80) return 0.899859;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 10 && pt < 15) return 0.652482;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 15 && pt < 20) return 0.789189;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 20 && pt < 25) return 0.801572;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 25 && pt < 30) return 0.819277;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 30 && pt < 35) return 0.8203;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 35 && pt < 40) return 0.835218;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 40 && pt < 45) return 0.846875;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 45 && pt < 60) return 0.85559;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 60 && pt < 80) return 0.851501;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 80) return 0.855573;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 10 && pt < 15) return 0.516129;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 15 && pt < 20) return 0.64898;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 20 && pt < 25) return 0.675393;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 25 && pt < 30) return 0.714592;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 30 && pt < 35) return 0.718254;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 35 && pt < 40) return 0.745318;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 40 && pt < 45) return 0.768421;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 45 && pt < 60) return 0.798305;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 60 && pt < 80) return 0.81592;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 80) return 0.842105;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 10 && pt < 15) return 0.666667;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 15 && pt < 20) return 0.569767;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 20 && pt < 25) return 0.638989;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 25 && pt < 30) return 0.649171;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 30 && pt < 35) return 0.657895;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 35 && pt < 40) return 0.697727;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 40 && pt < 45) return 0.737069;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 45 && pt < 60) return 0.741201;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 60 && pt < 80) return 0.76342;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 80) return 0.846154;
    }
    if (year == 2018) {
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 10 && pt < 15) return 0.759259;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 15 && pt < 20) return 0.843658;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 20 && pt < 25) return 0.863043;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 25 && pt < 30) return 0.880157;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 30 && pt < 35) return 0.909441;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 35 && pt < 40) return 0.905967;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 40 && pt < 45) return 0.907216;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 45 && pt < 60) return 0.91162;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 60 && pt < 80) return 0.907975;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 80) return 0.921168;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 10 && pt < 15) return 0.813187;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 15 && pt < 20) return 0.86532;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 20 && pt < 25) return 0.869565;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 25 && pt < 30) return 0.881657;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 30 && pt < 35) return 0.890152;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 35 && pt < 40) return 0.901639;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 40 && pt < 45) return 0.912434;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 45 && pt < 60) return 0.913793;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 60 && pt < 80) return 0.916522;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 80) return 0.933798;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 10 && pt < 15) return 0.810811;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 15 && pt < 20) return 0.817708;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 20 && pt < 25) return 0.81875;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 25 && pt < 30) return 0.848259;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 30 && pt < 35) return 0.822171;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 35 && pt < 40) return 0.832618;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 40 && pt < 45) return 0.840319;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 45 && pt < 60) return 0.850575;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 60 && pt < 80) return 0.852941;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 80) return 0.874114;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 10 && pt < 15) return 1.04545;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 15 && pt < 20) return 1.0082;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 20 && pt < 25) return 0.955357;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 25 && pt < 30) return 0.966443;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 30 && pt < 35) return 0.935294;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 35 && pt < 40) return 0.901907;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 40 && pt < 45) return 0.905371;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 45 && pt < 60) return 0.871734;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 60 && pt < 80) return 0.924945;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 80) return 0.854772;
    }
    return 0.0;
}

float ttH::getElecTTHSFErrPt(float pt, int year) {
    if (year == 2016) {
        if (pt >= 0 && pt < 15) return 0.967409;
        if (pt >= 15 && pt < 30) return 0.953719;
        if (pt >= 30 && pt < 45) return 1.00114;
        if (pt >= 45 && pt < 60) return 0.998463;
        if (pt >= 60 && pt < 75) return 1.00979;
        if (pt >= 75 && pt < 90) return 0.993269;
        if (pt >= 90 && pt < 105) return 0.986654;
        if (pt >= 105 && pt < 120) return 0.988112;
        if (pt >= 120 && pt < 135) return 1.0086;
        if (pt >= 135) return 1.00871;
    }
    if (year == 2017) {
        if (pt >= 0 && pt < 15) return 1.02674;
        if (pt >= 15 && pt < 30) return 1.02898;
        if (pt >= 30 && pt < 45) return 1.04209;
        if (pt >= 45 && pt < 60) return 1.01939;
        if (pt >= 60 && pt < 75) return 1.02722;
        if (pt >= 75 && pt < 90) return 1.01655;
        if (pt >= 90 && pt < 105) return 1.01922;
        if (pt >= 105 && pt < 120) return 1.01626;
        if (pt >= 120 && pt < 135) return 1.0315;
        if (pt >= 135) return 1.02362;
    }
    if (year == 2018) {
        if (pt >= 0 && pt < 15) return 0.921124;
        if (pt >= 15 && pt < 30) return 0.96246;
        if (pt >= 30 && pt < 45) return 1.01475;
        if (pt >= 45 && pt < 60) return 1.03108;
        if (pt >= 60 && pt < 75) return 1.02545;
        if (pt >= 75 && pt < 90) return 1.00691;
        if (pt >= 90 && pt < 105) return 1.01313;
        if (pt >= 105 && pt < 120) return 1.02224;
        if (pt >= 120 && pt < 135) return 1.02086;
        if (pt >= 135) return 1.02304;
    }
    return 0.0;
}

float ttH::getElecTTHSFErrEta(float eta, int year) {
    if (year == 2016) {
        if (abs(eta) >= 0 && abs(eta) < 0.5) return 0.996286;
        if (abs(eta) >= 0.5 && abs(eta) < 1) return 0.999735;
        if (abs(eta) >= 1 && abs(eta) < 1.5) return 0.967856;
        if (abs(eta) >= 1.5 && abs(eta) < 2) return 0.97779;
        if (abs(eta) >= 2 && abs(eta) < 2.5) return 0.952787;
    }
    if (year == 2017) {
        if (abs(eta) >= 0 && abs(eta) < 0.5) return 1.02843;
        if (abs(eta) >= 0.5 && abs(eta) < 1) return 1.02338;
        if (abs(eta) >= 1 && abs(eta) < 1.5) return 1.03661;
        if (abs(eta) >= 1.5 && abs(eta) < 2) return 0.977512;
        if (abs(eta) >= 2 && abs(eta) < 2.5) return 0.997837;
    }
    if (year == 2018) {
        if (abs(eta) >= 0 && abs(eta) < 0.5) return 0.98397;
        if (abs(eta) >= 0.5 && abs(eta) < 1) return 1.00531;
        if (abs(eta) >= 1 && abs(eta) < 1.5) return 1.01501;
        if (abs(eta) >= 1.5 && abs(eta) < 2) return 0.985103;
        if (abs(eta) >= 2 && abs(eta) < 2.5) return 0.970617;
    }
    return 0.0;
}

float ttH::getElecTTHSFErr(float eta, float pt, int year, bool up) {
    float max_err = std::max(ttH::getElecTTHSFErrPt(pt, year), ttH::getElecTTHSFErrEta(eta, year));
    if (up)
    {
        // sf_up = sf*max_err 
        // --> (sf + err_up*sf) = sf*max_err --> err_up = max_err - 1
        return (max_err - 1);
    }
    else
    {
        // sf_up = sf/max_err 
        // --> (sf - err_down*sf) = sf/max_err --> err_down = 1 - 1/max_err
        return (1 - 1./max_err);
    }
}
float ttH::getMuonTightSF(float eta, float pt, int year) {
    if (year == 2016) {
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 10 && pt < 15) return 0.955882;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 15 && pt < 20) return 0.976574;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 20 && pt < 25) return 0.985401;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 25 && pt < 30) return 0.989933;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 30 && pt < 35) return 0.995731;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 35 && pt < 40) return 0.995851;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 40 && pt < 45) return 0.998979;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 45 && pt < 60) return 0.998987;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 60 && pt < 80) return 0.998992;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 80) return 1.00302;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 10 && pt < 15) return 0.957983;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 15 && pt < 20) return 0.974551;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 20 && pt < 25) return 0.987593;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 25 && pt < 30) return 0.992045;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 30 && pt < 35) return 0.993535;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 35 && pt < 40) return 0.994792;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 40 && pt < 45) return 0.996933;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 45 && pt < 60) return 0.998986;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 60 && pt < 80) return 0.998992;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 80) return 1.00403;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 10 && pt < 15) return 0.944134;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 15 && pt < 20) return 0.985099;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 20 && pt < 25) return 1;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 25 && pt < 30) return 1;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 30 && pt < 35) return 0.997802;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 35 && pt < 40) return 0.997888;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 40 && pt < 45) return 0.998969;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 45 && pt < 60) return 1;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 60 && pt < 80) return 1;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 80) return 1.00404;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 10 && pt < 15) return 0.9;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 15 && pt < 20) return 0.973029;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 20 && pt < 25) return 0.992816;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 25 && pt < 30) return 0.988875;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 30 && pt < 35) return 0.99319;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 35 && pt < 40) return 0.994595;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 40 && pt < 45) return 0.996849;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 45 && pt < 60) return 0.995859;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 60 && pt < 80) return 0.992828;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 80) return 1.01754;
    }
    if (year == 2017) {
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 10 && pt < 15) return 0.87218;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 15 && pt < 20) return 0.925373;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 20 && pt < 25) return 0.960591;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 25 && pt < 30) return 0.977427;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 30 && pt < 35) return 0.982796;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 35 && pt < 40) return 0.989572;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 40 && pt < 45) return 0.992828;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 45 && pt < 60) return 0.994924;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 60 && pt < 80) return 0.996973;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 80) return 1.00302;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 10 && pt < 15) return 0.909465;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 15 && pt < 20) return 0.946792;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 20 && pt < 25) return 0.968072;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 25 && pt < 30) return 0.975751;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 30 && pt < 35) return 0.983624;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 35 && pt < 40) return 0.988433;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 40 && pt < 45) return 0.992798;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 45 && pt < 60) return 0.995923;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 60 && pt < 80) return 0.995956;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 80) return 1.00202;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 10 && pt < 15) return 0.819149;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 15 && pt < 20) return 0.916239;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 20 && pt < 25) return 0.949865;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 25 && pt < 30) return 0.964029;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 30 && pt < 35) return 0.97433;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 35 && pt < 40) return 0.983957;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 40 && pt < 45) return 0.989605;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 45 && pt < 60) return 0.993846;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 60 && pt < 80) return 0.995939;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 80) return 1.00202;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 10 && pt < 15) return 0.776786;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 15 && pt < 20) return 0.898947;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 20 && pt < 25) return 0.934551;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 25 && pt < 30) return 0.956466;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 30 && pt < 35) return 0.971031;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 35 && pt < 40) return 0.980349;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 40 && pt < 45) return 0.987355;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 45 && pt < 60) return 0.991718;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 60 && pt < 80) return 0.993871;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 80) return 1.01328;
    }
    if (year == 2018) {
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 10 && pt < 15) return 0.830116;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 15 && pt < 20) return 0.895988;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 20 && pt < 25) return 0.934969;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 25 && pt < 30) return 0.960586;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 30 && pt < 35) return 0.97637;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 35 && pt < 40) return 0.984375;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 40 && pt < 45) return 0.990788;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 45 && pt < 60) return 0.993909;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 60 && pt < 80) return 0.995964;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 80) return 1.00201;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 10 && pt < 15) return 0.853448;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 15 && pt < 20) return 0.910356;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 20 && pt < 25) return 0.945776;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 25 && pt < 30) return 0.963303;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 30 && pt < 35) return 0.975;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 35 && pt < 40) return 0.98531;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 40 && pt < 45) return 0.989733;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 45 && pt < 60) return 0.993896;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 60 && pt < 80) return 0.99596;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 80) return 1.00202;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 10 && pt < 15) return 0.923077;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 15 && pt < 20) return 0.954003;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 20 && pt < 25) return 0.97043;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 25 && pt < 30) return 0.980907;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 30 && pt < 35) return 0.988827;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 35 && pt < 40) return 0.993576;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 40 && pt < 45) return 0.995833;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 45 && pt < 60) return 0.997947;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 60 && pt < 80) return 0.996954;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 80) return 1.00202;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 10 && pt < 15) return 1.03191;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 15 && pt < 20) return 1.02371;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 20 && pt < 25) return 0.995363;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 25 && pt < 30) return 1.00396;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 30 && pt < 35) return 1.00956;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 35 && pt < 40) return 1.00785;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 40 && pt < 45) return 1.00647;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 45 && pt < 60) return 1.00421;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 60 && pt < 80) return 0.998971;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 80) return 1.01336;
    }
    return 0.0;
}

float ttH::getMuonTTHSFErrPt(float pt, int year) {
    if (year == 2016) {
        if (pt >= 0 && pt < 15) return 0.944572;
        if (pt >= 15 && pt < 30) return 0.984619;
        if (pt >= 30 && pt < 45) return 1.00288;
        if (pt >= 45 && pt < 60) return 0.997416;
        if (pt >= 60 && pt < 75) return 1.00684;
        if (pt >= 75 && pt < 90) return 1.00068;
        if (pt >= 90 && pt < 105) return 0.988714;
        if (pt >= 105 && pt < 120) return 0.996859;
        if (pt >= 120 && pt < 135) return 1.00141;
        if (pt >= 135) return 0.990344;
    }
    if (year == 2017) {
        if (pt >= 0 && pt < 15) return 1.0035;
        if (pt >= 15 && pt < 30) return 0.9748;
        if (pt >= 30 && pt < 45) return 1.00079;
        if (pt >= 45 && pt < 60) return 0.998123;
        if (pt >= 60 && pt < 75) return 1.00255;
        if (pt >= 75 && pt < 90) return 1.00035;
        if (pt >= 90 && pt < 105) return 1.0018;
        if (pt >= 105 && pt < 120) return 0.998739;
        if (pt >= 120 && pt < 135) return 0.995682;
        if (pt >= 135) return 1.00276;
    }
    if (year == 2018) {
        if (pt >= 0 && pt < 15) return 0.992714;
        if (pt >= 15 && pt < 30) return 0.970142;
        if (pt >= 30 && pt < 45) return 0.990027;
        if (pt >= 45 && pt < 60) return 0.994844;
        if (pt >= 60 && pt < 75) return 1.00381;
        if (pt >= 75 && pt < 90) return 1.00145;
        if (pt >= 90 && pt < 105) return 0.996145;
        if (pt >= 105 && pt < 120) return 0.986428;
        if (pt >= 120 && pt < 135) return 0.990573;
        if (pt >= 135) return 1.00155;
    }
    return 0.0;
}

float ttH::getMuonTTHSFErrEta(float eta, int year) {
    if (year == 2016) {
        if (abs(eta) >= 0 && abs(eta) < 0.5) return 0.987079;
        if (abs(eta) >= 0.5 && abs(eta) < 1) return 1.0011;
        if (abs(eta) >= 1 && abs(eta) < 1.5) return 0.973398;
        if (abs(eta) >= 1.5 && abs(eta) < 2) return 0.995077;
        if (abs(eta) >= 2 && abs(eta) < 2.5) return 0.982187;
    }
    if (year == 2017) {
        if (abs(eta) >= 0 && abs(eta) < 0.5) return 0.988256;
        if (abs(eta) >= 0.5 && abs(eta) < 1) return 0.998026;
        if (abs(eta) >= 1 && abs(eta) < 1.5) return 0.992793;
        if (abs(eta) >= 1.5 && abs(eta) < 2) return 0.97602;
        if (abs(eta) >= 2 && abs(eta) < 2.5) return 0.946541;
    }
    if (year == 2018) {
        if (abs(eta) >= 0 && abs(eta) < 0.5) return 0.980775;
        if (abs(eta) >= 0.5 && abs(eta) < 1) return 0.977193;
        if (abs(eta) >= 1 && abs(eta) < 1.5) return 0.982292;
        if (abs(eta) >= 1.5 && abs(eta) < 2) return 0.986776;
        if (abs(eta) >= 2 && abs(eta) < 2.5) return 0.994179;
    }
    return 0.0;
}

float ttH::getMuonTTHSFErr(float eta, float pt, int year, bool up) {
    float max_err = max(ttH::getMuonTTHSFErrPt(pt, year), ttH::getMuonTTHSFErrEta(eta, year));
    if (up)
    {
        // sf_up = sf*max_err 
        // --> (sf + err_up*sf) = sf*max_err --> err_up = max_err - 1
        return (max_err - 1);
    }
    else
    {
        // sf_up = sf/max_err 
        // --> (sf - err_down*sf) = sf/max_err --> err_down = 1 - 1/max_err
        return (1 - 1./max_err);
    }
}
float ttH::getElecLooseSF(float eta, float pt, int year) {
    if (year == 2016) {
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 10 && pt < 15) return 0.993704;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 15 && pt < 20) return 0.991667;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 20 && pt < 25) return 0.990683;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 25 && pt < 30) return 0.989765;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 30 && pt < 35) return 0.991878;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 35 && pt < 40) return 0.991911;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 40 && pt < 45) return 0.990891;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 45 && pt < 60) return 0.989879;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 60 && pt < 80) return 0.987842;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 80) return 0.987854;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 10 && pt < 15) return 1.00836;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 15 && pt < 20) return 0.997921;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 20 && pt < 25) return 0.995863;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 25 && pt < 30) return 0.991812;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 30 && pt < 35) return 0.991853;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 35 && pt < 40) return 0.99187;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 40 && pt < 45) return 0.992901;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 45 && pt < 60) return 0.990881;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 60 && pt < 80) return 0.991886;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 80) return 0.992908;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 10 && pt < 15) return 1.01773;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 15 && pt < 20) return 1.01049;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 20 && pt < 25) return 1.00104;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 25 && pt < 30) return 0.988671;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 30 && pt < 35) return 0.998982;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 35 && pt < 40) return 0.997976;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 40 && pt < 45) return 0.998989;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 45 && pt < 60) return 0.99798;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 60 && pt < 80) return 0.997976;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 80) return 0.998987;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 10 && pt < 15) return 1.00508;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 15 && pt < 20) return 1.00508;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 20 && pt < 25) return 1.00711;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 25 && pt < 30) return 1.00608;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 30 && pt < 35) return 1.00303;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 35 && pt < 40) return 1.00302;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 40 && pt < 45) return 1.00302;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 45 && pt < 60) return 1.00403;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 60 && pt < 80) return 1.00607;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 80) return 1.01327;
    }
    if (year == 2017) {
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 10 && pt < 15) return 0.99789;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 15 && pt < 20) return 0.993737;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 20 && pt < 25) return 0.992731;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 25 && pt < 30) return 0.988718;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 30 && pt < 35) return 0.99187;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 35 && pt < 40) return 0.991911;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 40 && pt < 45) return 0.990909;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 45 && pt < 60) return 0.990909;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 60 && pt < 80) return 0.991911;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 80) return 0.993933;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 10 && pt < 15) return 1.0021;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 15 && pt < 20) return 0.997917;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 20 && pt < 25) return 0.991727;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 25 && pt < 30) return 0.998975;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 30 && pt < 35) return 0.992879;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 35 && pt < 40) return 0.992908;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 40 && pt < 45) return 0.991911;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 45 && pt < 60) return 0.992922;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 60 && pt < 80) return 0.992922;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 80) return 0.993939;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 10 && pt < 15) return 1.00731;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 15 && pt < 20) return 1.01466;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 20 && pt < 25) return 1.01356;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 25 && pt < 30) return 1.00827;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 30 && pt < 35) return 1.0041;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 35 && pt < 40) return 1.00102;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 40 && pt < 45) return 1;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 45 && pt < 60) return 1.00203;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 60 && pt < 80) return 1.0051;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 80) return 1.00819;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 10 && pt < 15) return 1.01131;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 15 && pt < 20) return 1.0186;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 20 && pt < 25) return 1.02174;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 25 && pt < 30) return 1.02596;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 30 && pt < 35) return 1.02277;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 35 && pt < 40) return 1.01852;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 40 && pt < 45) return 1.0185;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 45 && pt < 60) return 1.02482;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 60 && pt < 80) return 1.03692;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 80) return 1.04264;
    }
    if (year == 2018) {
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 10 && pt < 15) return 0.998952;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 15 && pt < 20) return 0.99375;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 20 && pt < 25) return 0.990674;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 25 && pt < 30) return 0.993846;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 30 && pt < 35) return 0.993909;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 35 && pt < 40) return 0.993939;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 40 && pt < 45) return 0.993939;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 45 && pt < 60) return 0.992929;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 60 && pt < 80) return 0.991919;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 80) return 0.993939;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 10 && pt < 15) return 1.01254;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 15 && pt < 20) return 0.997919;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 20 && pt < 25) return 0.996898;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 25 && pt < 30) return 0.993859;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 30 && pt < 35) return 0.992886;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 35 && pt < 40) return 0.993921;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 40 && pt < 45) return 0.993933;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 45 && pt < 60) return 0.994944;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 60 && pt < 80) return 0.992922;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 80) return 0.99495;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 10 && pt < 15) return 1.01769;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 15 && pt < 20) return 1.00832;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 20 && pt < 25) return 0.99793;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 25 && pt < 30) return 0.998972;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 30 && pt < 35) return 0.998982;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 35 && pt < 40) return 0.997976;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 40 && pt < 45) return 0.99798;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 45 && pt < 60) return 0.996973;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 60 && pt < 80) return 0.99697;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 80) return 0.995964;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 10 && pt < 15) return 1.00407;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 15 && pt < 20) return 0.996957;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 20 && pt < 25) return 0.99696;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 25 && pt < 30) return 0.993933;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 30 && pt < 35) return 0.995968;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 35 && pt < 40) return 0.995976;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 40 && pt < 45) return 0.996982;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 45 && pt < 60) return 0.996982;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 60 && pt < 80) return 0.992936;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 80) return 0.990909;
    }
    return 0.0;
}

float ttH::getMuonLooseSF(float eta, float pt, int year) {
    if (year == 2016) {
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 10 && pt < 15) return 0.994571;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 15 && pt < 20) return 0.990374;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 20 && pt < 25) return 0.991597;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 25 && pt < 30) return 0.991761;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 30 && pt < 35) return 0.994914;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 35 && pt < 40) return 0.993933;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 40 && pt < 45) return 0.993946;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 45 && pt < 60) return 0.994955;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 60 && pt < 80) return 0.99495;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 80) return 0.99798;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 10 && pt < 15) return 0.993562;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 15 && pt < 20) return 0.995736;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 20 && pt < 25) return 0.991579;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 25 && pt < 30) return 0.993814;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 30 && pt < 35) return 0.995931;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 35 && pt < 40) return 0.995951;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 40 && pt < 45) return 0.995964;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 45 && pt < 60) return 0.995968;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 60 && pt < 80) return 0.995968;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 80) return 0.996976;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 10 && pt < 15) return 1.00529;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 15 && pt < 20) return 1.00211;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 20 && pt < 25) return 0.998955;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 25 && pt < 30) return 1;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 30 && pt < 35) return 0.998983;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 35 && pt < 40) return 0.995951;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 40 && pt < 45) return 0.99697;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 45 && pt < 60) return 0.996973;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 60 && pt < 80) return 1;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 80) return 1.00304;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 10 && pt < 15) return 0.992265;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 15 && pt < 20) return 0.984649;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 20 && pt < 25) return 0.982609;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 25 && pt < 30) return 0.982888;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 30 && pt < 35) return 0.979894;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 35 && pt < 40) return 0.981092;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 40 && pt < 45) return 0.981191;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 45 && pt < 60) return 0.98123;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 60 && pt < 80) return 0.985356;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 80) return 0.995807;
    }
    if (year == 2017) {
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 10 && pt < 15) return 0.989119;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 15 && pt < 20) return 0.992465;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 20 && pt < 25) return 0.992608;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 25 && pt < 30) return 0.993802;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 30 && pt < 35) return 0.994908;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 35 && pt < 40) return 0.994934;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 40 && pt < 45) return 0.994944;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 45 && pt < 60) return 0.994944;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 60 && pt < 80) return 0.994944;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 80) return 0.996967;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 10 && pt < 15) return 1.00328;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 15 && pt < 20) return 0.996771;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 20 && pt < 25) return 0.997884;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 25 && pt < 30) return 0.99793;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 30 && pt < 35) return 0.995923;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 35 && pt < 40) return 0.99696;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 40 && pt < 45) return 0.99697;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 45 && pt < 60) return 0.99697;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 60 && pt < 80) return 0.995964;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 80) return 0.997982;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 10 && pt < 15) return 1.01399;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 15 && pt < 20) return 1.01174;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 20 && pt < 25) return 1.00948;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 25 && pt < 30) return 1.00414;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 30 && pt < 35) return 1.00205;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 35 && pt < 40) return 0.998984;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 40 && pt < 45) return 0.998987;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 45 && pt < 60) return 0.998988;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 60 && pt < 80) return 1.00203;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 80) return 1.00406;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 10 && pt < 15) return 1.00442;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 15 && pt < 20) return 1.00548;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 20 && pt < 25) return 1.00433;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 25 && pt < 30) return 1;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 30 && pt < 35) return 0.995789;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 35 && pt < 40) return 0.99267;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 40 && pt < 45) return 0.992693;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 45 && pt < 60) return 0.992708;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 60 && pt < 80) return 0.990615;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 80) return 0.994759;
    }
    if (year == 2018) {
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 10 && pt < 15) return 0.990217;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 15 && pt < 20) return 0.989259;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 20 && pt < 25) return 0.993678;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 25 && pt < 30) return 0.993808;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 30 && pt < 35) return 0.995927;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 35 && pt < 40) return 0.995951;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 40 && pt < 45) return 0.99596;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 45 && pt < 60) return 0.99596;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 60 && pt < 80) return 0.99596;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 80) return 0.99899;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 10 && pt < 15) return 0.995647;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 15 && pt < 20) return 0.994635;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 20 && pt < 25) return 0.992608;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 25 && pt < 30) return 0.994835;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 30 && pt < 35) return 0.994908;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 35 && pt < 40) return 0.994939;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 40 && pt < 45) return 0.99697;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 45 && pt < 60) return 0.995964;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 60 && pt < 80) return 0.995968;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 80) return 0.997984;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 10 && pt < 15) return 0.997875;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 15 && pt < 20) return 0.990516;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 20 && pt < 25) return 0.991658;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 25 && pt < 30) return 0.99384;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 30 && pt < 35) return 0.992893;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 35 && pt < 40) return 0.993933;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 40 && pt < 45) return 0.992944;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 45 && pt < 60) return 0.99496;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 60 && pt < 80) return 0.993958;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 80) return 0.995976;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 10 && pt < 15) return 0.976268;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 15 && pt < 20) return 0.96788;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 20 && pt < 25) return 0.965116;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 25 && pt < 30) return 0.970772;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 30 && pt < 35) return 0.973113;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 35 && pt < 40) return 0.973224;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 40 && pt < 45) return 0.972279;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 45 && pt < 60) return 0.974359;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 60 && pt < 80) return 0.975334;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.4 && pt >= 80) return 0.976337;
    }
    return 0.0;
}

float ttH::getElecPOGLooseSF(float eta, float pt, int year) {
    if (year == 2016) {
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 10 && pt < 20) return 0.968097;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 20 && pt < 25) return 0.971014;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 25 && pt < 30) return 0.990798;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 30 && pt < 35) return 0.991886;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 35 && pt < 40) return 0.992929;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 40 && pt < 45) return 0.993952;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 45 && pt < 60) return 0.993958;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 60 && pt < 80) return 0.994955;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 80) return 1.00202;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 10 && pt < 20) return 1.0426;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 20 && pt < 25) return 0.972746;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 25 && pt < 30) return 0.96701;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 30 && pt < 35) return 0.986748;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 35 && pt < 40) return 0.990863;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 40 && pt < 45) return 0.991903;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 45 && pt < 60) return 0.991911;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 60 && pt < 80) return 0.990872;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 80) return 0.997982;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 10 && pt < 20) return 1.02861;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 20 && pt < 25) return 0.961915;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 25 && pt < 30) return 0.967196;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 30 && pt < 35) return 0.977012;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 35 && pt < 40) return 0.984456;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 40 && pt < 45) return 0.986598;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 45 && pt < 60) return 0.988706;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 60 && pt < 80) return 0.993814;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 80) return 1;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 10 && pt < 20) return 1.04294;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 20 && pt < 25) return 1.00861;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 25 && pt < 30) return 1.00118;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 30 && pt < 35) return 0.988372;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 35 && pt < 40) return 0.998856;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 40 && pt < 45) return 1.00113;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 45 && pt < 60) return 0.995506;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 60 && pt < 80) return 0.991051;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 80) return 1.01341;
    }
    if (year == 2017) {
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 10 && pt < 20) return 0.969957;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 20 && pt < 25) return 0.980513;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 25 && pt < 30) return 0.985787;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 30 && pt < 35) return 0.991919;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 35 && pt < 40) return 0.990927;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 40 && pt < 45) return 0.990946;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 45 && pt < 60) return 0.992965;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 60 && pt < 80) return 0.992965;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 80) return 0.99799;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 10 && pt < 20) return 1.0349;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 20 && pt < 25) return 0.961777;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 25 && pt < 30) return 0.981651;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 30 && pt < 35) return 0.984787;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 35 && pt < 40) return 0.983822;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 40 && pt < 45) return 0.986882;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 45 && pt < 60) return 0.990927;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 60 && pt < 80) return 0.970796;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 80) return 0.998991;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 10 && pt < 20) return 1.01342;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 20 && pt < 25) return 0.950785;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 25 && pt < 30) return 0.968008;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 30 && pt < 35) return 0.974359;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 35 && pt < 40) return 0.970348;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 40 && pt < 45) return 0.97551;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 45 && pt < 60) return 0.979654;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 60 && pt < 80) return 0.981689;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 80) return 0.986775;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 10 && pt < 20) return 0.938316;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 20 && pt < 25) return 0.931818;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 25 && pt < 30) return 0.948773;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 30 && pt < 35) return 0.957761;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 35 && pt < 40) return 0.951681;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 40 && pt < 45) return 0.95283;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 45 && pt < 60) return 0.95929;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 60 && pt < 80) return 0.976092;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 80) return 0.974066;
    }
    if (year == 2018) {
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 10 && pt < 20) return 0.963895;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 20 && pt < 25) return 0.97936;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 25 && pt < 30) return 0.987768;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 30 && pt < 35) return 0.991903;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 35 && pt < 40) return 0.992944;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 40 && pt < 45) return 0.992958;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 45 && pt < 60) return 0.993964;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 60 && pt < 80) return 0.992944;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 80) return 0.998993;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 10 && pt < 20) return 1.04246;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 20 && pt < 25) return 0.975992;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 25 && pt < 30) return 0.983556;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 30 && pt < 35) return 0.988798;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 35 && pt < 40) return 0.990891;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 40 && pt < 45) return 0.991919;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 45 && pt < 60) return 0.990918;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 60 && pt < 80) return 0.991911;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 80) return 1;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 10 && pt < 20) return 1.04005;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 20 && pt < 25) return 0.957128;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 25 && pt < 30) return 0.964361;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 30 && pt < 35) return 0.963768;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 35 && pt < 40) return 0.98251;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 40 && pt < 45) return 0.983607;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 45 && pt < 60) return 0.985641;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 60 && pt < 80) return 0.9846;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 80) return 0.993865;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 10 && pt < 20) return 1.03594;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 20 && pt < 25) return 0.974099;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 25 && pt < 30) return 0.971522;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 30 && pt < 35) return 0.978425;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 35 && pt < 40) return 0.97861;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 40 && pt < 45) return 0.978769;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 45 && pt < 60) return 0.979852;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 60 && pt < 80) return 0.983033;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 80) return 1;
    }
    return 0.0;
}

float ttH::getElecPOGLooseSFErr(float eta, float pt, int year) {
    if (year == 2016) {
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 10 && pt < 20) return 0.0260101;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 20 && pt < 25) return 0.0445375;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 25 && pt < 30) return 0.0307089;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 30 && pt < 35) return 0.0102429;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 35 && pt < 40) return 0.00247423;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 40 && pt < 45) return 0.00174602;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 45 && pt < 60) return 0.00174426;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 60 && pt < 80) return 0.00174778;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 80) return 0.00174955;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 10 && pt < 20) return 0.00910767;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 20 && pt < 25) return 0.0297406;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 25 && pt < 30) return 0.0251259;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 30 && pt < 35) return 0.0143438;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 35 && pt < 40) return 0.00430725;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 40 && pt < 45) return 0.00822271;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 45 && pt < 60) return 0.00175132;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 60 && pt < 80) return 0.00633367;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 80) return 0.003191;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 10 && pt < 20) return 0.0304575;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 20 && pt < 25) return 0.0365135;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 25 && pt < 30) return 0.0329914;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 30 && pt < 35) return 0.00874253;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 35 && pt < 40) return 0.00358974;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 40 && pt < 45) return 0.00178562;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 45 && pt < 60) return 0.00205339;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 60 && pt < 80) return 0.00252525;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 80) return 0.00385341;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 10 && pt < 20) return 0.034208;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 20 && pt < 25) return 0.0193312;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 25 && pt < 30) return 0.0295874;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 30 && pt < 35) return 0.0108458;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 35 && pt < 40) return 0.0109744;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 40 && pt < 45) return 0.00358129;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 45 && pt < 60) return 0.00297275;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 60 && pt < 80) return 0.00994205;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 80) return 0.0177017;
    }
    if (year == 2017) {
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 10 && pt < 20) return 0.0238236;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 20 && pt < 25) return 0.0338927;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 25 && pt < 30) return 0.019449;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 30 && pt < 35) return 0.011248;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 35 && pt < 40) return 0.00174602;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 40 && pt < 45) return 0.00142275;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 45 && pt < 60) return 0.00142132;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 60 && pt < 80) return 0.00174075;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 80) return 0.0024618;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 10 && pt < 20) return 0.0266451;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 20 && pt < 25) return 0.0252624;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 25 && pt < 30) return 0.0272383;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 30 && pt < 35) return 0.0136069;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 35 && pt < 40) return 0.00175132;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 40 && pt < 45) return 0.00174778;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 45 && pt < 60) return 0.00174602;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 60 && pt < 80) return 0.024253;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 80) return 0.00247174;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 10 && pt < 20) return 0.0168529;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 20 && pt < 25) return 0.0236705;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 25 && pt < 30) return 0.0171447;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 30 && pt < 35) return 0.0234331;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 35 && pt < 40) return 0.00433808;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 40 && pt < 45) return 0.00144308;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 45 && pt < 60) return 0.001762;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 60 && pt < 80) return 0.00443428;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 80) return 0.00528601;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 10 && pt < 20) return 0.0199556;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 20 && pt < 25) return 0.0162698;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 25 && pt < 30) return 0.0186995;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 30 && pt < 35) return 0.0203667;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 35 && pt < 40) return 0.00406826;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 40 && pt < 45) return 0.00181557;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 45 && pt < 60) return 0.00651879;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 60 && pt < 80) return 0.0120779;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 80) return 0.00613701;
    }
    if (year == 2018) {
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 10 && pt < 20) return 0.0183729;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 20 && pt < 25) return 0.0320416;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 25 && pt < 30) return 0.0184334;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 30 && pt < 35) return 0.00632085;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 35 && pt < 40) return 0.00174602;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 40 && pt < 45) return 0.00174251;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 45 && pt < 60) return 0.00142275;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 60 && pt < 80) return 0.00174602;
        if (fabs(eta) >= 0 && fabs(eta) < 0.9 && pt >= 80) return 0.00174426;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 10 && pt < 20) return 0.0146108;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 20 && pt < 25) return 0.0292648;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 25 && pt < 30) return 0.0257553;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 30 && pt < 35) return 0.0052914;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 35 && pt < 40) return 0.00202429;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 40 && pt < 45) return 0.00174955;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 45 && pt < 60) return 0.00142706;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 60 && pt < 80) return 0.0145475;
        if (fabs(eta) >= 0.9 && fabs(eta) < 1.2 && pt >= 80) return 0.00175132;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 10 && pt < 20) return 0.0380212;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 20 && pt < 25) return 0.0269023;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 25 && pt < 30) return 0.0150812;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 30 && pt < 35) return 0.0185759;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 35 && pt < 40) return 0.00252005;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 40 && pt < 45) return 0.00144899;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 45 && pt < 60) return 0.00177646;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 60 && pt < 80) return 0.00177829;
        if (fabs(eta) >= 1.2 && fabs(eta) < 2.1 && pt >= 80) return 0.00445695;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 10 && pt < 20) return 0.0113373;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 20 && pt < 25) return 0.0156446;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 25 && pt < 30) return 0.0149779;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 30 && pt < 35) return 0.0120124;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 35 && pt < 40) return 0.00466192;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 40 && pt < 45) return 0.00367739;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 45 && pt < 60) return 0.00183675;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 60 && pt < 80) return 0.0104979;
        if (fabs(eta) >= 2.1 && fabs(eta) < 2.5 && pt >= 80) return 0.00959488;
    }
    return 0.0;
}

float ttH::getElecRecoEffSFUL2016preVFP(float eta, float pt) {
    if (eta >= -2.5 && eta < -2 && pt >= 10 && pt < 20) return 1.01389;
    if (eta >= -2 && eta < -1.566 && pt >= 10 && pt < 20) return 0.990343;
    if (eta >= -1.566 && eta < -1.444 && pt >= 10 && pt < 20) return 1.2065;
    if (eta >= -1.444 && eta < -1 && pt >= 10 && pt < 20) return 1.01758;
    if (eta >= -1 && eta < 0 && pt >= 10 && pt < 20) return 1.05569;
    if (eta >= 0 && eta < 1 && pt >= 10 && pt < 20) return 1.05569;
    if (eta >= 1 && eta < 1.444 && pt >= 10 && pt < 20) return 1.01758;
    if (eta >= 1.444 && eta < 1.566 && pt >= 10 && pt < 20) return 1.2065;
    if (eta >= 1.566 && eta < 2 && pt >= 10 && pt < 20) return 0.990343;
    if (eta >= 2 && eta < 2.5 && pt >= 10 && pt < 20) return 1.01389;
    if (eta >= -2.5 && eta < -2 && pt >= 20 && pt < 45) return 0.996791;
    if (eta >= -2.5 && eta < -2 && pt >= 45 && pt < 75) return 0.991588;
    if (eta >= -2.5 && eta < -2 && pt >= 75 && pt < 100) return 0.988372;
    if (eta >= -2.5 && eta < -2 && pt >= 100) return 1.00958;
    if (eta >= -2 && eta < -1.566 && pt >= 20 && pt < 45) return 0.992723;
    if (eta >= -2 && eta < -1.566 && pt >= 45 && pt < 75) return 0.992769;
    if (eta >= -2 && eta < -1.566 && pt >= 75 && pt < 100) return 0.984631;
    if (eta >= -2 && eta < -1.566 && pt >= 100) return 1.01638;
    if (eta >= -1.566 && eta < -1.444 && pt >= 20 && pt < 45) return 0.957597;
    if (eta >= -1.566 && eta < -1.444 && pt >= 45 && pt < 75) return 0.962162;
    if (eta >= -1.566 && eta < -1.444 && pt >= 75 && pt < 100) return 1.01213;
    if (eta >= -1.566 && eta < -1.444 && pt >= 100) return 1.01438;
    if (eta >= -1.444 && eta < -1 && pt >= 20 && pt < 45) return 0.985597;
    if (eta >= -1.444 && eta < -1 && pt >= 45 && pt < 75) return 0.986721;
    if (eta >= -1.444 && eta < -1 && pt >= 75 && pt < 100) return 0.982776;
    if (eta >= -1.444 && eta < -1 && pt >= 100) return 0.979818;
    if (eta >= -1 && eta < -0.5 && pt >= 20 && pt < 45) return 0.979445;
    if (eta >= -1 && eta < -0.5 && pt >= 45 && pt < 75) return 0.981614;
    if (eta >= -1 && eta < -0.5 && pt >= 75 && pt < 100) return 0.976602;
    if (eta >= -1 && eta < -0.5 && pt >= 100) return 0.984864;
    if (eta >= -0.5 && eta < 0 && pt >= 20 && pt < 45) return 0.975258;
    if (eta >= -0.5 && eta < 0 && pt >= 45 && pt < 75) return 0.979529;
    if (eta >= -0.5 && eta < 0 && pt >= 75 && pt < 100) return 0.987743;
    if (eta >= -0.5 && eta < 0 && pt >= 100) return 0.989868;
    if (eta >= 0 && eta < 0.5 && pt >= 20 && pt < 45) return 0.986598;
    if (eta >= 0 && eta < 0.5 && pt >= 45 && pt < 75) return 0.987718;
    if (eta >= 0 && eta < 0.5 && pt >= 75 && pt < 100) return 0.987743;
    if (eta >= 0 && eta < 0.5 && pt >= 100) return 0.989868;
    if (eta >= 0.5 && eta < 1 && pt >= 20 && pt < 45) return 0.987705;
    if (eta >= 0.5 && eta < 1 && pt >= 45 && pt < 75) return 0.98778;
    if (eta >= 0.5 && eta < 1 && pt >= 75 && pt < 100) return 0.976602;
    if (eta >= 0.5 && eta < 1 && pt >= 100) return 0.984864;
    if (eta >= 1 && eta < 1.444 && pt >= 20 && pt < 45) return 0.989722;
    if (eta >= 1 && eta < 1.444 && pt >= 45 && pt < 75) return 0.988775;
    if (eta >= 1 && eta < 1.444 && pt >= 75 && pt < 100) return 0.982776;
    if (eta >= 1 && eta < 1.444 && pt >= 100) return 0.979818;
    if (eta >= 1.444 && eta < 1.566 && pt >= 20 && pt < 45) return 0.971564;
    if (eta >= 1.444 && eta < 1.566 && pt >= 45 && pt < 75) return 0.975135;
    if (eta >= 1.444 && eta < 1.566 && pt >= 75 && pt < 100) return 1.01213;
    if (eta >= 1.444 && eta < 1.566 && pt >= 100) return 1.01438;
    if (eta >= 1.566 && eta < 2 && pt >= 20 && pt < 45) return 0.993802;
    if (eta >= 1.566 && eta < 2 && pt >= 45 && pt < 75) return 0.99076;
    if (eta >= 1.566 && eta < 2 && pt >= 75 && pt < 100) return 0.984631;
    if (eta >= 1.566 && eta < 2 && pt >= 100) return 1.01638;
    if (eta >= 2 && eta < 2.5 && pt >= 20 && pt < 45) return 1;
    if (eta >= 2 && eta < 2.5 && pt >= 45 && pt < 75) return 0.992537;
    if (eta >= 2 && eta < 2.5 && pt >= 75 && pt < 100) return 0.988372;
    if (eta >= 2 && eta < 2.5 && pt >= 100) return 1.00958;
    return 0.0;
}

float ttH::getElecRecoEffSFUL2016postVFP(float eta, float pt) {
    if (eta >= -2.5 && eta < -2 && pt >= 10 && pt < 20) return 1.01524;
    if (eta >= -2 && eta < -1.566 && pt >= 10 && pt < 20) return 0.990312;
    if (eta >= -1.566 && eta < -1.444 && pt >= 10 && pt < 20) return 1.12956;
    if (eta >= -1.444 && eta < -1 && pt >= 10 && pt < 20) return 0.958561;
    if (eta >= -1 && eta < 0 && pt >= 10 && pt < 20) return 1.02404;
    if (eta >= 0 && eta < 1 && pt >= 10 && pt < 20) return 1.02404;
    if (eta >= 1 && eta < 1.444 && pt >= 10 && pt < 20) return 0.958561;
    if (eta >= 1.444 && eta < 1.566 && pt >= 10 && pt < 20) return 1.12956;
    if (eta >= 1.566 && eta < 2 && pt >= 10 && pt < 20) return 0.990312;
    if (eta >= 2 && eta < 2.5 && pt >= 10 && pt < 20) return 1.01524;
    if (eta >= -2.5 && eta < -2 && pt >= 20 && pt < 45) return 1.03536;
    if (eta >= -2.5 && eta < -2 && pt >= 45 && pt < 75) return 1.02047;
    if (eta >= -2.5 && eta < -2 && pt >= 75 && pt < 100) return 1;
    if (eta >= -2.5 && eta < -2 && pt >= 100) return 1.01053;
    if (eta >= -2 && eta < -1.566 && pt >= 20 && pt < 45) return 0.992693;
    if (eta >= -2 && eta < -1.566 && pt >= 45 && pt < 75) return 0.989627;
    if (eta >= -2 && eta < -1.566 && pt >= 75 && pt < 100) return 0.973279;
    if (eta >= -2 && eta < -1.566 && pt >= 100) return 0.996936;
    if (eta >= -1.566 && eta < -1.444 && pt >= 20 && pt < 45) return 0.989461;
    if (eta >= -1.566 && eta < -1.444 && pt >= 45 && pt < 75) return 0.959651;
    if (eta >= -1.566 && eta < -1.444 && pt >= 75 && pt < 100) return 0.991257;
    if (eta >= -1.566 && eta < -1.444 && pt >= 100) return 0.998899;
    if (eta >= -1.444 && eta < -1 && pt >= 20 && pt < 45) return 0.987642;
    if (eta >= -1.444 && eta < -1 && pt >= 45 && pt < 75) return 0.986735;
    if (eta >= -1.444 && eta < -1 && pt >= 75 && pt < 100) return 0.981744;
    if (eta >= -1.444 && eta < -1 && pt >= 100) return 0.991935;
    if (eta >= -1 && eta < -0.5 && pt >= 20 && pt < 45) return 0.98567;
    if (eta >= -1 && eta < -0.5 && pt >= 45 && pt < 75) return 0.985787;
    if (eta >= -1 && eta < -0.5 && pt >= 75 && pt < 100) return 0.976697;
    if (eta >= -1 && eta < -0.5 && pt >= 100) return 0.990927;
    if (eta >= -0.5 && eta < 0 && pt >= 20 && pt < 45) return 0.98359;
    if (eta >= -0.5 && eta < 0 && pt >= 45 && pt < 75) return 0.985743;
    if (eta >= -0.5 && eta < 0 && pt >= 75 && pt < 100) return 0.976673;
    if (eta >= -0.5 && eta < 0 && pt >= 100) return 0.986869;
    if (eta >= 0 && eta < 0.5 && pt >= 20 && pt < 45) return 0.98359;
    if (eta >= 0 && eta < 0.5 && pt >= 45 && pt < 75) return 0.984725;
    if (eta >= 0 && eta < 0.5 && pt >= 75 && pt < 100) return 0.976673;
    if (eta >= 0 && eta < 0.5 && pt >= 100) return 0.986869;
    if (eta >= 0.5 && eta < 1 && pt >= 20 && pt < 45) return 0.9857;
    if (eta >= 0.5 && eta < 1 && pt >= 45 && pt < 75) return 0.986802;
    if (eta >= 0.5 && eta < 1 && pt >= 75 && pt < 100) return 0.976697;
    if (eta >= 0.5 && eta < 1 && pt >= 100) return 0.990927;
    if (eta >= 1 && eta < 1.444 && pt >= 20 && pt < 45) return 0.9846;
    if (eta >= 1 && eta < 1.444 && pt >= 45 && pt < 75) return 0.985729;
    if (eta >= 1 && eta < 1.444 && pt >= 75 && pt < 100) return 0.981744;
    if (eta >= 1 && eta < 1.444 && pt >= 100) return 0.991935;
    if (eta >= 1.444 && eta < 1.566 && pt >= 20 && pt < 45) return 0.976387;
    if (eta >= 1.444 && eta < 1.566 && pt >= 45 && pt < 75) return 0.958963;
    if (eta >= 1.444 && eta < 1.566 && pt >= 75 && pt < 100) return 0.991257;
    if (eta >= 1.444 && eta < 1.566 && pt >= 100) return 0.998899;
    if (eta >= 1.566 && eta < 2 && pt >= 20 && pt < 45) return 0.988601;
    if (eta >= 1.566 && eta < 2 && pt >= 45 && pt < 75) return 0.988683;
    if (eta >= 1.566 && eta < 2 && pt >= 75 && pt < 100) return 0.973279;
    if (eta >= 1.566 && eta < 2 && pt >= 100) return 0.996936;
    if (eta >= 2 && eta < 2.5 && pt >= 20 && pt < 45) return 0.991416;
    if (eta >= 2 && eta < 2.5 && pt >= 45 && pt < 75) return 0.991588;
    if (eta >= 2 && eta < 2.5 && pt >= 75 && pt < 100) return 1;
    if (eta >= 2 && eta < 2.5 && pt >= 100) return 1.01053;
    return 0.0;
}

float ttH::getElecRecoEffSFUL(float eta, float pt, int year, bool isAPV) {
    if (year == 2016) {
        if (isAPV)
            return ttH::getElecRecoEffSFUL2016preVFP(eta, pt);
        else
            return ttH::getElecRecoEffSFUL2016postVFP(eta, pt);
        // return 0.45*ttH::getElecRecoEffSFUL2016preVFP(eta, pt) + 0.55*ttH::getElecRecoEffSFUL2016postVFP(eta, pt);
    }
    if (year == 2017) {
        if (eta >= -2.5 && eta < -2 && pt >= 10 && pt < 20) return 1.01368;
        if (eta >= -2 && eta < -1.566 && pt >= 10 && pt < 20) return 1.01262;
        if (eta >= -1.566 && eta < -1.444 && pt >= 10 && pt < 20) return 1.09234;
        if (eta >= -1.444 && eta < -1 && pt >= 10 && pt < 20) return 1.00332;
        if (eta >= -1 && eta < 0 && pt >= 10 && pt < 20) return 1.04762;
        if (eta >= 0 && eta < 1 && pt >= 10 && pt < 20) return 1.04762;
        if (eta >= 1 && eta < 1.444 && pt >= 10 && pt < 20) return 1.00332;
        if (eta >= 1.444 && eta < 1.566 && pt >= 10 && pt < 20) return 1.09234;
        if (eta >= 1.566 && eta < 2 && pt >= 10 && pt < 20) return 1.01262;
        if (eta >= 2 && eta < 2.5 && pt >= 10 && pt < 20) return 1.01368;
        if (eta >= -2.5 && eta < -2 && pt >= 20 && pt < 45) return 0.981462;
        if (eta >= -2.5 && eta < -2 && pt >= 45 && pt < 75) return 0.983623;
        if (eta >= -2.5 && eta < -2 && pt >= 75 && pt < 100) return 0.976434;
        if (eta >= -2.5 && eta < -2 && pt >= 100) return 0.978831;
        if (eta >= -2 && eta < -1.566 && pt >= 20 && pt < 45) return 0.986653;
        if (eta >= -2 && eta < -1.566 && pt >= 45 && pt < 75) return 0.986735;
        if (eta >= -2 && eta < -1.566 && pt >= 75 && pt < 100) return 1.00409;
        if (eta >= -2 && eta < -1.566 && pt >= 100) return 0.98783;
        if (eta >= -1.566 && eta < -1.444 && pt >= 20 && pt < 45) return 0.926143;
        if (eta >= -1.566 && eta < -1.444 && pt >= 45 && pt < 75) return 0.957402;
        if (eta >= -1.566 && eta < -1.444 && pt >= 75 && pt < 100) return 1.02404;
        if (eta >= -1.566 && eta < -1.444 && pt >= 100) return 1.04966;
        if (eta >= -1.444 && eta < -1 && pt >= 20 && pt < 45) return 0.980352;
        if (eta >= -1.444 && eta < -1 && pt >= 45 && pt < 75) return 0.982582;
        if (eta >= -1.444 && eta < -1 && pt >= 75 && pt < 100) return 0.988764;
        if (eta >= -1.444 && eta < -1 && pt >= 100) return 0.988753;
        if (eta >= -1 && eta < -0.5 && pt >= 20 && pt < 45) return 0.986667;
        if (eta >= -1 && eta < -0.5 && pt >= 45 && pt < 75) return 0.988798;
        if (eta >= -1 && eta < -0.5 && pt >= 75 && pt < 100) return 0.998976;
        if (eta >= -1 && eta < -0.5 && pt >= 100) return 0.994934;
        if (eta >= -0.5 && eta < 0 && pt >= 20 && pt < 45) return 0.987654;
        if (eta >= -0.5 && eta < 0 && pt >= 45 && pt < 75) return 0.988753;
        if (eta >= -0.5 && eta < 0 && pt >= 75 && pt < 100) return 0.984725;
        if (eta >= -0.5 && eta < 0 && pt >= 100) return 1.00102;
        if (eta >= 0 && eta < 0.5 && pt >= 20 && pt < 45) return 0.988648;
        if (eta >= 0 && eta < 0.5 && pt >= 45 && pt < 75) return 0.989754;
        if (eta >= 0 && eta < 0.5 && pt >= 75 && pt < 100) return 0.984725;
        if (eta >= 0 && eta < 0.5 && pt >= 100) return 1.00102;
        if (eta >= 0.5 && eta < 1 && pt >= 20 && pt < 45) return 0.991736;
        if (eta >= 0.5 && eta < 1 && pt >= 45 && pt < 75) return 0.99384;
        if (eta >= 0.5 && eta < 1 && pt >= 75 && pt < 100) return 0.998976;
        if (eta >= 0.5 && eta < 1 && pt >= 100) return 0.994934;
        if (eta >= 1 && eta < 1.444 && pt >= 20 && pt < 45) return 0.982218;
        if (eta >= 1 && eta < 1.444 && pt >= 45 && pt < 75) return 0.983437;
        if (eta >= 1 && eta < 1.444 && pt >= 75 && pt < 100) return 0.988764;
        if (eta >= 1 && eta < 1.444 && pt >= 100) return 0.988753;
        if (eta >= 1.444 && eta < 1.566 && pt >= 20 && pt < 45) return 0.978723;
        if (eta >= 1.444 && eta < 1.566 && pt >= 45 && pt < 75) return 0.98174;
        if (eta >= 1.444 && eta < 1.566 && pt >= 75 && pt < 100) return 1.02404;
        if (eta >= 1.444 && eta < 1.566 && pt >= 100) return 1.04966;
        if (eta >= 1.566 && eta < 2 && pt >= 20 && pt < 45) return 0.987654;
        if (eta >= 1.566 && eta < 2 && pt >= 45 && pt < 75) return 0.989775;
        if (eta >= 1.566 && eta < 2 && pt >= 75 && pt < 100) return 1.00409;
        if (eta >= 1.566 && eta < 2 && pt >= 100) return 0.98783;
        if (eta >= 2 && eta < 2.5 && pt >= 20 && pt < 45) return 0.986653;
        if (eta >= 2 && eta < 2.5 && pt >= 45 && pt < 75) return 0.986735;
        if (eta >= 2 && eta < 2.5 && pt >= 75 && pt < 100) return 0.976434;
        if (eta >= 2 && eta < 2.5 && pt >= 100) return 0.978831;
    }
    if (year == 2018) {
        if (eta >= -2.5 && eta < -2 && pt >= 10 && pt < 20) return 0.998952;
        if (eta >= -2 && eta < -1.566 && pt >= 10 && pt < 20) return 0.998952;
        if (eta >= -1.566 && eta < -1.444 && pt >= 10 && pt < 20) return 1.14365;
        if (eta >= -1.444 && eta < -1 && pt >= 10 && pt < 20) return 0.988889;
        if (eta >= -1 && eta < 0 && pt >= 10 && pt < 20) return 1.07683;
        if (eta >= 0 && eta < 1 && pt >= 10 && pt < 20) return 1.07683;
        if (eta >= 1 && eta < 1.444 && pt >= 10 && pt < 20) return 0.988889;
        if (eta >= 1.444 && eta < 1.566 && pt >= 10 && pt < 20) return 1.14365;
        if (eta >= 1.566 && eta < 2 && pt >= 10 && pt < 20) return 0.998952;
        if (eta >= 2 && eta < 2.5 && pt >= 10 && pt < 20) return 0.998952;
        if (eta >= -2.5 && eta < -2 && pt >= 20 && pt < 45) return 0.983539;
        if (eta >= -2.5 && eta < -2 && pt >= 45 && pt < 75) return 0.986708;
        if (eta >= -2.5 && eta < -2 && pt >= 75 && pt < 100) return 0.996926;
        if (eta >= -2.5 && eta < -2 && pt >= 100) return 0.998983;
        if (eta >= -2 && eta < -1.566 && pt >= 20 && pt < 45) return 0.988718;
        if (eta >= -2 && eta < -1.566 && pt >= 45 && pt < 75) return 0.988787;
        if (eta >= -2 && eta < -1.566 && pt >= 75 && pt < 100) return 0.993902;
        if (eta >= -2 && eta < -1.566 && pt >= 100) return 1.00713;
        if (eta >= -1.566 && eta < -1.444 && pt >= 20 && pt < 45) return 0.975439;
        if (eta >= -1.566 && eta < -1.444 && pt >= 45 && pt < 75) return 0.965921;
        if (eta >= -1.566 && eta < -1.444 && pt >= 75 && pt < 100) return 1.03384;
        if (eta >= -1.566 && eta < -1.444 && pt >= 100) return 1.0308;
        if (eta >= -1.444 && eta < -1 && pt >= 20 && pt < 45) return 0.982383;
        if (eta >= -1.444 && eta < -1 && pt >= 45 && pt < 75) return 0.983539;
        if (eta >= -1.444 && eta < -1 && pt >= 75 && pt < 100) return 0.99793;
        if (eta >= -1.444 && eta < -1 && pt >= 100) return 0.993827;
        if (eta >= -1 && eta < -0.5 && pt >= 20 && pt < 45) return 0.988683;
        if (eta >= -1 && eta < -0.5 && pt >= 45 && pt < 75) return 0.987743;
        if (eta >= -1 && eta < -0.5 && pt >= 75 && pt < 100) return 0.989733;
        if (eta >= -1 && eta < -0.5 && pt >= 100) return 0.99591;
        if (eta >= -0.5 && eta < 0 && pt >= 20 && pt < 45) return 0.98657;
        if (eta >= -0.5 && eta < 0 && pt >= 45 && pt < 75) return 0.987692;
        if (eta >= -0.5 && eta < 0 && pt >= 75 && pt < 100) return 0.989754;
        if (eta >= -0.5 && eta < 0 && pt >= 100) return 0.995906;
        if (eta >= 0 && eta < 0.5 && pt >= 20 && pt < 45) return 0.986458;
        if (eta >= 0 && eta < 0.5 && pt >= 45 && pt < 75) return 0.985507;
        if (eta >= 0 && eta < 0.5 && pt >= 75 && pt < 100) return 0.989754;
        if (eta >= 0 && eta < 0.5 && pt >= 100) return 0.995906;
        if (eta >= 0.5 && eta < 1 && pt >= 20 && pt < 45) return 0.987526;
        if (eta >= 0.5 && eta < 1 && pt >= 45 && pt < 75) return 0.988613;
        if (eta >= 0.5 && eta < 1 && pt >= 75 && pt < 100) return 0.989733;
        if (eta >= 0.5 && eta < 1 && pt >= 100) return 0.99591;
        if (eta >= 1 && eta < 1.444 && pt >= 20 && pt < 45) return 0.979101;
        if (eta >= 1 && eta < 1.444 && pt >= 45 && pt < 75) return 0.980311;
        if (eta >= 1 && eta < 1.444 && pt >= 75 && pt < 100) return 0.99793;
        if (eta >= 1 && eta < 1.444 && pt >= 100) return 0.993827;
        if (eta >= 1.444 && eta < 1.566 && pt >= 20 && pt < 45) return 0.987013;
        if (eta >= 1.444 && eta < 1.566 && pt >= 45 && pt < 75) return 0.974194;
        if (eta >= 1.444 && eta < 1.566 && pt >= 75 && pt < 100) return 1.03384;
        if (eta >= 1.444 && eta < 1.566 && pt >= 100) return 1.0308;
        if (eta >= 1.566 && eta < 2 && pt >= 20 && pt < 45) return 0.987705;
        if (eta >= 1.566 && eta < 2 && pt >= 45 && pt < 75) return 0.988787;
        if (eta >= 1.566 && eta < 2 && pt >= 75 && pt < 100) return 0.993902;
        if (eta >= 1.566 && eta < 2 && pt >= 100) return 1.00713;
        if (eta >= 2 && eta < 2.5 && pt >= 20 && pt < 45) return 0.98668;
        if (eta >= 2 && eta < 2.5 && pt >= 45 && pt < 75) return 0.988787;
        if (eta >= 2 && eta < 2.5 && pt >= 75 && pt < 100) return 0.996926;
        if (eta >= 2 && eta < 2.5 && pt >= 100) return 0.998983;
    }
    return 0.0;
}

float ttH::getElecRecoEffSFULErr2016preVFP(float eta, float pt) {
    if (eta >= -2.5 && eta < -2 && pt >= 10 && pt < 20) return 0.0199128;
    if (eta >= -2 && eta < -1.566 && pt >= 10 && pt < 20) return 0.0139072;
    if (eta >= -1.566 && eta < -1.444 && pt >= 10 && pt < 20) return 0.483377;
    if (eta >= -1.444 && eta < -1 && pt >= 10 && pt < 20) return 0.0365457;
    if (eta >= -1 && eta < 0 && pt >= 10 && pt < 20) return 0.0819944;
    if (eta >= 0 && eta < 1 && pt >= 10 && pt < 20) return 0.0819944;
    if (eta >= 1 && eta < 1.444 && pt >= 10 && pt < 20) return 0.0365457;
    if (eta >= 1.444 && eta < 1.566 && pt >= 10 && pt < 20) return 0.483377;
    if (eta >= 1.566 && eta < 2 && pt >= 10 && pt < 20) return 0.0139072;
    if (eta >= 2 && eta < 2.5 && pt >= 10 && pt < 20) return 0.0199128;
    if (eta >= -2.5 && eta < -2 && pt >= 20 && pt < 45) return 0.00337567;
    if (eta >= -2.5 && eta < -2 && pt >= 45 && pt < 75) return 0.00605904;
    if (eta >= -2.5 && eta < -2 && pt >= 75 && pt < 100) return 0.0140636;
    if (eta >= -2.5 && eta < -2 && pt >= 100) return 0.0175638;
    if (eta >= -2 && eta < -1.566 && pt >= 20 && pt < 45) return 0.00315169;
    if (eta >= -2 && eta < -1.566 && pt >= 45 && pt < 75) return 0.00218468;
    if (eta >= -2 && eta < -1.566 && pt >= 75 && pt < 100) return 0.0227034;
    if (eta >= -2 && eta < -1.566 && pt >= 100) return 0.00862451;
    if (eta >= -1.566 && eta < -1.444 && pt >= 20 && pt < 45) return 0.0177692;
    if (eta >= -1.566 && eta < -1.444 && pt >= 45 && pt < 75) return 0.00618677;
    if (eta >= -1.566 && eta < -1.444 && pt >= 75 && pt < 100) return 0.0307724;
    if (eta >= -1.566 && eta < -1.444 && pt >= 100) return 0.026801;
    if (eta >= -1.444 && eta < -1 && pt >= 20 && pt < 45) return 0.00224108;
    if (eta >= -1.444 && eta < -1 && pt >= 45 && pt < 75) return 0.0021047;
    if (eta >= -1.444 && eta < -1 && pt >= 75 && pt < 100) return 0.00934098;
    if (eta >= -1.444 && eta < -1 && pt >= 100) return 0.00596981;
    if (eta >= -1 && eta < -0.5 && pt >= 20 && pt < 45) return 0.00261622;
    if (eta >= -1 && eta < -0.5 && pt >= 45 && pt < 75) return 0.00310187;
    if (eta >= -1 && eta < -0.5 && pt >= 75 && pt < 100) return 0.0148469;
    if (eta >= -1 && eta < -0.5 && pt >= 100) return 0.00676913;
    if (eta >= -0.5 && eta < 0 && pt >= 20 && pt < 45) return 0.00257732;
    if (eta >= -0.5 && eta < 0 && pt >= 45 && pt < 75) return 0.00393099;
    if (eta >= -0.5 && eta < 0 && pt >= 75 && pt < 100) return 0.00722275;
    if (eta >= -0.5 && eta < 0 && pt >= 100) return 0.00687166;
    if (eta >= 0 && eta < 0.5 && pt >= 20 && pt < 45) return 0.00257732;
    if (eta >= 0 && eta < 0.5 && pt >= 45 && pt < 75) return 0.00393099;
    if (eta >= 0 && eta < 0.5 && pt >= 75 && pt < 100) return 0.00722275;
    if (eta >= 0 && eta < 0.5 && pt >= 100) return 0.00687166;
    if (eta >= 0.5 && eta < 1 && pt >= 20 && pt < 45) return 0.00261622;
    if (eta >= 0.5 && eta < 1 && pt >= 45 && pt < 75) return 0.00310187;
    if (eta >= 0.5 && eta < 1 && pt >= 75 && pt < 100) return 0.0148469;
    if (eta >= 0.5 && eta < 1 && pt >= 100) return 0.00676913;
    if (eta >= 1 && eta < 1.444 && pt >= 20 && pt < 45) return 0.00224108;
    if (eta >= 1 && eta < 1.444 && pt >= 45 && pt < 75) return 0.0021047;
    if (eta >= 1 && eta < 1.444 && pt >= 75 && pt < 100) return 0.00934098;
    if (eta >= 1 && eta < 1.444 && pt >= 100) return 0.00596981;
    if (eta >= 1.444 && eta < 1.566 && pt >= 20 && pt < 45) return 0.0177692;
    if (eta >= 1.444 && eta < 1.566 && pt >= 45 && pt < 75) return 0.00618677;
    if (eta >= 1.444 && eta < 1.566 && pt >= 75 && pt < 100) return 0.0307724;
    if (eta >= 1.444 && eta < 1.566 && pt >= 100) return 0.026801;
    if (eta >= 1.566 && eta < 2 && pt >= 20 && pt < 45) return 0.00315169;
    if (eta >= 1.566 && eta < 2 && pt >= 45 && pt < 75) return 0.00218468;
    if (eta >= 1.566 && eta < 2 && pt >= 75 && pt < 100) return 0.0227034;
    if (eta >= 1.566 && eta < 2 && pt >= 100) return 0.00862451;
    if (eta >= 2 && eta < 2.5 && pt >= 20 && pt < 45) return 0.00337567;
    if (eta >= 2 && eta < 2.5 && pt >= 45 && pt < 75) return 0.00605904;
    if (eta >= 2 && eta < 2.5 && pt >= 75 && pt < 100) return 0.0140636;
    if (eta >= 2 && eta < 2.5 && pt >= 100) return 0.0175638;
    return 0.0;
}

float ttH::getElecRecoEffSFULErr2016postVFP(float eta, float pt) {
    if (eta >= -2.5 && eta < -2 && pt >= 10 && pt < 20) return 0.0185732;
    if (eta >= -2 && eta < -1.566 && pt >= 10 && pt < 20) return 0.0224248;
    if (eta >= -1.566 && eta < -1.444 && pt >= 10 && pt < 20) return 0.308;
    if (eta >= -1.444 && eta < -1 && pt >= 10 && pt < 20) return 0.0372055;
    if (eta >= -1 && eta < 0 && pt >= 10 && pt < 20) return 0.0796087;
    if (eta >= 0 && eta < 1 && pt >= 10 && pt < 20) return 0.0796087;
    if (eta >= 1 && eta < 1.444 && pt >= 10 && pt < 20) return 0.0372055;
    if (eta >= 1.444 && eta < 1.566 && pt >= 10 && pt < 20) return 0.308;
    if (eta >= 1.566 && eta < 2 && pt >= 10 && pt < 20) return 0.0224248;
    if (eta >= 2 && eta < 2.5 && pt >= 10 && pt < 20) return 0.0185732;
    if (eta >= -2.5 && eta < -2 && pt >= 20 && pt < 45) return 0.00356965;
    if (eta >= -2.5 && eta < -2 && pt >= 45 && pt < 75) return 0.00344904;
    if (eta >= -2.5 && eta < -2 && pt >= 75 && pt < 100) return 0.0186584;
    if (eta >= -2.5 && eta < -2 && pt >= 100) return 0.0179257;
    if (eta >= -2 && eta < -1.566 && pt >= 20 && pt < 45) return 0.00352695;
    if (eta >= -2 && eta < -1.566 && pt >= 45 && pt < 75) return 0.00178931;
    if (eta >= -2 && eta < -1.566 && pt >= 75 && pt < 100) return 0.0213119;
    if (eta >= -2 && eta < -1.566 && pt >= 100) return 0.0103666;
    if (eta >= -1.566 && eta < -1.444 && pt >= 20 && pt < 45) return 0.026133;
    if (eta >= -1.566 && eta < -1.444 && pt >= 45 && pt < 75) return 0.00381748;
    if (eta >= -1.566 && eta < -1.444 && pt >= 75 && pt < 100) return 0.0225571;
    if (eta >= -1.566 && eta < -1.444 && pt >= 100) return 0.0323346;
    if (eta >= -1.444 && eta < -1 && pt >= 20 && pt < 45) return 0.0026216;
    if (eta >= -1.444 && eta < -1 && pt >= 45 && pt < 75) return 0.00161258;
    if (eta >= -1.444 && eta < -1 && pt >= 75 && pt < 100) return 0.0103428;
    if (eta >= -1.444 && eta < -1 && pt >= 100) return 0.00825136;
    if (eta >= -1 && eta < -0.5 && pt >= 20 && pt < 45) return 0.00177101;
    if (eta >= -1 && eta < -0.5 && pt >= 45 && pt < 75) return 0.00209295;
    if (eta >= -1 && eta < -0.5 && pt >= 75 && pt < 100) return 0.0183493;
    if (eta >= -1 && eta < -0.5 && pt >= 100) return 0.00629536;
    if (eta >= -0.5 && eta < 0 && pt >= 20 && pt < 45) return 0.00223533;
    if (eta >= -0.5 && eta < 0 && pt >= 45 && pt < 75) return 0.0017638;
    if (eta >= -0.5 && eta < 0 && pt >= 75 && pt < 100) return 0.0141988;
    if (eta >= -0.5 && eta < 0 && pt >= 100) return 0.00685084;
    if (eta >= 0 && eta < 0.5 && pt >= 20 && pt < 45) return 0.00223533;
    if (eta >= 0 && eta < 0.5 && pt >= 45 && pt < 75) return 0.0017638;
    if (eta >= 0 && eta < 0.5 && pt >= 75 && pt < 100) return 0.0141988;
    if (eta >= 0 && eta < 0.5 && pt >= 100) return 0.00685084;
    if (eta >= 0.5 && eta < 1 && pt >= 20 && pt < 45) return 0.00177101;
    if (eta >= 0.5 && eta < 1 && pt >= 45 && pt < 75) return 0.00209295;
    if (eta >= 0.5 && eta < 1 && pt >= 75 && pt < 100) return 0.0183493;
    if (eta >= 0.5 && eta < 1 && pt >= 100) return 0.00629536;
    if (eta >= 1 && eta < 1.444 && pt >= 20 && pt < 45) return 0.0026216;
    if (eta >= 1 && eta < 1.444 && pt >= 45 && pt < 75) return 0.00161258;
    if (eta >= 1 && eta < 1.444 && pt >= 75 && pt < 100) return 0.0103428;
    if (eta >= 1 && eta < 1.444 && pt >= 100) return 0.00825136;
    if (eta >= 1.444 && eta < 1.566 && pt >= 20 && pt < 45) return 0.026133;
    if (eta >= 1.444 && eta < 1.566 && pt >= 45 && pt < 75) return 0.00387489;
    if (eta >= 1.444 && eta < 1.566 && pt >= 75 && pt < 100) return 0.0225571;
    if (eta >= 1.444 && eta < 1.566 && pt >= 100) return 0.0323346;
    if (eta >= 1.566 && eta < 2 && pt >= 20 && pt < 45) return 0.00352695;
    if (eta >= 1.566 && eta < 2 && pt >= 45 && pt < 75) return 0.00178931;
    if (eta >= 1.566 && eta < 2 && pt >= 75 && pt < 100) return 0.0213119;
    if (eta >= 1.566 && eta < 2 && pt >= 100) return 0.0103666;
    if (eta >= 2 && eta < 2.5 && pt >= 20 && pt < 45) return 0.00356965;
    if (eta >= 2 && eta < 2.5 && pt >= 45 && pt < 75) return 0.00344904;
    if (eta >= 2 && eta < 2.5 && pt >= 75 && pt < 100) return 0.0186584;
    if (eta >= 2 && eta < 2.5 && pt >= 100) return 0.0179257;
    return 0.0;
}

float ttH::getElecRecoEffSFULErr(float eta, float pt, int year) {
    if (year == 2016) {
        return 0.45*ttH::getElecRecoEffSFULErr2016preVFP(eta, pt) + 0.55*ttH::getElecRecoEffSFULErr2016postVFP(eta, pt);
    }
    if (year == 2017) {
        if (eta >= -2.5 && eta < -2 && pt >= 10 && pt < 20) return 0.0131052;
        if (eta >= -2 && eta < -1.566 && pt >= 10 && pt < 20) return 0.0163579;
        if (eta >= -1.566 && eta < -1.444 && pt >= 10 && pt < 20) return 0.24443;
        if (eta >= -1.444 && eta < -1 && pt >= 10 && pt < 20) return 0.0176146;
        if (eta >= -1 && eta < 0 && pt >= 10 && pt < 20) return 0.072287;
        if (eta >= 0 && eta < 1 && pt >= 10 && pt < 20) return 0.072287;
        if (eta >= 1 && eta < 1.444 && pt >= 10 && pt < 20) return 0.0176146;
        if (eta >= 1.444 && eta < 1.566 && pt >= 10 && pt < 20) return 0.24443;
        if (eta >= 1.566 && eta < 2 && pt >= 10 && pt < 20) return 0.0163579;
        if (eta >= 2 && eta < 2.5 && pt >= 10 && pt < 20) return 0.0131052;
        if (eta >= -2.5 && eta < -2 && pt >= 20 && pt < 45) return 0.00451155;
        if (eta >= -2.5 && eta < -2 && pt >= 45 && pt < 75) return 0.0034278;
        if (eta >= -2.5 && eta < -2 && pt >= 75 && pt < 100) return 0.020234;
        if (eta >= -2.5 && eta < -2 && pt >= 100) return 0.0119276;
        if (eta >= -2 && eta < -1.566 && pt >= 20 && pt < 45) return 0.00576823;
        if (eta >= -2 && eta < -1.566 && pt >= 45 && pt < 75) return 0.00388957;
        if (eta >= -2 && eta < -1.566 && pt >= 75 && pt < 100) return 0.0128657;
        if (eta >= -2 && eta < -1.566 && pt >= 100) return 0.00772391;
        if (eta >= -1.566 && eta < -1.444 && pt >= 20 && pt < 45) return 0.0376462;
        if (eta >= -1.566 && eta < -1.444 && pt >= 45 && pt < 75) return 0.0118856;
        if (eta >= -1.566 && eta < -1.444 && pt >= 75 && pt < 100) return 0.0310852;
        if (eta >= -1.566 && eta < -1.444 && pt >= 100) return 0.0439021;
        if (eta >= -1.444 && eta < -1 && pt >= 20 && pt < 45) return 0.00406149;
        if (eta >= -1.444 && eta < -1 && pt >= 45 && pt < 75) return 0.00392161;
        if (eta >= -1.444 && eta < -1 && pt >= 75 && pt < 100) return 0.0113744;
        if (eta >= -1.444 && eta < -1 && pt >= 100) return 0.00700987;
        if (eta >= -1 && eta < -0.5 && pt >= 20 && pt < 45) return 0.00272337;
        if (eta >= -1 && eta < -0.5 && pt >= 45 && pt < 75) return 0.0048231;
        if (eta >= -1 && eta < -0.5 && pt >= 75 && pt < 100) return 0.0070913;
        if (eta >= -1 && eta < -0.5 && pt >= 100) return 0.00496351;
        if (eta >= -0.5 && eta < 0 && pt >= 20 && pt < 45) return 0.00252395;
        if (eta >= -0.5 && eta < 0 && pt >= 45 && pt < 75) return 0.0035824;
        if (eta >= -0.5 && eta < 0 && pt >= 75 && pt < 100) return 0.00899365;
        if (eta >= -0.5 && eta < 0 && pt >= 100) return 0.00518193;
        if (eta >= 0 && eta < 0.5 && pt >= 20 && pt < 45) return 0.00252395;
        if (eta >= 0 && eta < 0.5 && pt >= 45 && pt < 75) return 0.0035824;
        if (eta >= 0 && eta < 0.5 && pt >= 75 && pt < 100) return 0.00899365;
        if (eta >= 0 && eta < 0.5 && pt >= 100) return 0.00518193;
        if (eta >= 0.5 && eta < 1 && pt >= 20 && pt < 45) return 0.00272337;
        if (eta >= 0.5 && eta < 1 && pt >= 45 && pt < 75) return 0.0048231;
        if (eta >= 0.5 && eta < 1 && pt >= 75 && pt < 100) return 0.0070913;
        if (eta >= 0.5 && eta < 1 && pt >= 100) return 0.00496351;
        if (eta >= 1 && eta < 1.444 && pt >= 20 && pt < 45) return 0.00406149;
        if (eta >= 1 && eta < 1.444 && pt >= 45 && pt < 75) return 0.00392161;
        if (eta >= 1 && eta < 1.444 && pt >= 75 && pt < 100) return 0.0113744;
        if (eta >= 1 && eta < 1.444 && pt >= 100) return 0.00700987;
        if (eta >= 1.444 && eta < 1.566 && pt >= 20 && pt < 45) return 0.0376462;
        if (eta >= 1.444 && eta < 1.566 && pt >= 45 && pt < 75) return 0.0118856;
        if (eta >= 1.444 && eta < 1.566 && pt >= 75 && pt < 100) return 0.0310852;
        if (eta >= 1.444 && eta < 1.566 && pt >= 100) return 0.0439021;
        if (eta >= 1.566 && eta < 2 && pt >= 20 && pt < 45) return 0.00576823;
        if (eta >= 1.566 && eta < 2 && pt >= 45 && pt < 75) return 0.00388957;
        if (eta >= 1.566 && eta < 2 && pt >= 75 && pt < 100) return 0.0128657;
        if (eta >= 1.566 && eta < 2 && pt >= 100) return 0.00772391;
        if (eta >= 2 && eta < 2.5 && pt >= 20 && pt < 45) return 0.00451155;
        if (eta >= 2 && eta < 2.5 && pt >= 45 && pt < 75) return 0.0034278;
        if (eta >= 2 && eta < 2.5 && pt >= 75 && pt < 100) return 0.020234;
        if (eta >= 2 && eta < 2.5 && pt >= 100) return 0.0119276;
    }
    if (year == 2018) {
        if (eta >= -2.5 && eta < -2 && pt >= 10 && pt < 20) return 0.00994427;
        if (eta >= -2 && eta < -1.566 && pt >= 10 && pt < 20) return 0.023227;
        if (eta >= -1.566 && eta < -1.444 && pt >= 10 && pt < 20) return 0.400145;
        if (eta >= -1.444 && eta < -1 && pt >= 10 && pt < 20) return 0.0349956;
        if (eta >= -1 && eta < 0 && pt >= 10 && pt < 20) return 0.0615823;
        if (eta >= 0 && eta < 1 && pt >= 10 && pt < 20) return 0.0615823;
        if (eta >= 1 && eta < 1.444 && pt >= 10 && pt < 20) return 0.0349956;
        if (eta >= 1.444 && eta < 1.566 && pt >= 10 && pt < 20) return 0.400145;
        if (eta >= 1.566 && eta < 2 && pt >= 10 && pt < 20) return 0.023227;
        if (eta >= 2 && eta < 2.5 && pt >= 10 && pt < 20) return 0.00994427;
        if (eta >= -2.5 && eta < -2 && pt >= 20 && pt < 45) return 0.00359343;
        if (eta >= -2.5 && eta < -2 && pt >= 45 && pt < 75) return 0.00532941;
        if (eta >= -2.5 && eta < -2 && pt >= 75 && pt < 100) return 0.00851089;
        if (eta >= -2.5 && eta < -2 && pt >= 100) return 0.00747555;
        if (eta >= -2 && eta < -1.566 && pt >= 20 && pt < 45) return 0.00339992;
        if (eta >= -2 && eta < -1.566 && pt >= 45 && pt < 75) return 0.00391496;
        if (eta >= -2 && eta < -1.566 && pt >= 75 && pt < 100) return 0.00476668;
        if (eta >= -2 && eta < -1.566 && pt >= 100) return 0.0070552;
        if (eta >= -1.566 && eta < -1.444 && pt >= 20 && pt < 45) return 0.00466349;
        if (eta >= -1.566 && eta < -1.444 && pt >= 45 && pt < 75) return 0.00874272;
        if (eta >= -1.566 && eta < -1.444 && pt >= 75 && pt < 100) return 0.0190658;
        if (eta >= -1.566 && eta < -1.444 && pt >= 100) return 0.0237226;
        if (eta >= -1.444 && eta < -1 && pt >= 20 && pt < 45) return 0.00316481;
        if (eta >= -1.444 && eta < -1 && pt >= 45 && pt < 75) return 0.0055363;
        if (eta >= -1.444 && eta < -1 && pt >= 75 && pt < 100) return 0.00815115;
        if (eta >= -1.444 && eta < -1 && pt >= 100) return 0.00756015;
        if (eta >= -1 && eta < -0.5 && pt >= 20 && pt < 45) return 0.00365619;
        if (eta >= -1 && eta < -0.5 && pt >= 45 && pt < 75) return 0.00621236;
        if (eta >= -1 && eta < -0.5 && pt >= 75 && pt < 100) return 0.00801874;
        if (eta >= -1 && eta < -0.5 && pt >= 100) return 0.00531304;
        if (eta >= -0.5 && eta < 0 && pt >= 20 && pt < 45) return 0.00381145;
        if (eta >= -0.5 && eta < 0 && pt >= 45 && pt < 75) return 0.00624645;
        if (eta >= -0.5 && eta < 0 && pt >= 75 && pt < 100) return 0.00396822;
        if (eta >= -0.5 && eta < 0 && pt >= 100) return 0.00639201;
        if (eta >= 0 && eta < 0.5 && pt >= 20 && pt < 45) return 0.00381145;
        if (eta >= 0 && eta < 0.5 && pt >= 45 && pt < 75) return 0.00624645;
        if (eta >= 0 && eta < 0.5 && pt >= 75 && pt < 100) return 0.00396822;
        if (eta >= 0 && eta < 0.5 && pt >= 100) return 0.00639201;
        if (eta >= 0.5 && eta < 1 && pt >= 20 && pt < 45) return 0.00365619;
        if (eta >= 0.5 && eta < 1 && pt >= 45 && pt < 75) return 0.00621236;
        if (eta >= 0.5 && eta < 1 && pt >= 75 && pt < 100) return 0.00801874;
        if (eta >= 0.5 && eta < 1 && pt >= 100) return 0.00531304;
        if (eta >= 1 && eta < 1.444 && pt >= 20 && pt < 45) return 0.00316481;
        if (eta >= 1 && eta < 1.444 && pt >= 45 && pt < 75) return 0.0055363;
        if (eta >= 1 && eta < 1.444 && pt >= 75 && pt < 100) return 0.00815115;
        if (eta >= 1 && eta < 1.444 && pt >= 100) return 0.00756015;
        if (eta >= 1.444 && eta < 1.566 && pt >= 20 && pt < 45) return 0.00466349;
        if (eta >= 1.444 && eta < 1.566 && pt >= 45 && pt < 75) return 0.00874272;
        if (eta >= 1.444 && eta < 1.566 && pt >= 75 && pt < 100) return 0.0190658;
        if (eta >= 1.444 && eta < 1.566 && pt >= 100) return 0.0237226;
        if (eta >= 1.566 && eta < 2 && pt >= 20 && pt < 45) return 0.00339992;
        if (eta >= 1.566 && eta < 2 && pt >= 45 && pt < 75) return 0.00391496;
        if (eta >= 1.566 && eta < 2 && pt >= 75 && pt < 100) return 0.00476668;
        if (eta >= 1.566 && eta < 2 && pt >= 100) return 0.0070552;
        if (eta >= 2 && eta < 2.5 && pt >= 20 && pt < 45) return 0.00359343;
        if (eta >= 2 && eta < 2.5 && pt >= 45 && pt < 75) return 0.00532941;
        if (eta >= 2 && eta < 2.5 && pt >= 75 && pt < 100) return 0.00851089;
        if (eta >= 2 && eta < 2.5 && pt >= 100) return 0.00747555;
    }
    return 0.0;
}

float ttH::getElecRecoEffSF(float eta, float pt, int year) {
    if (year == 2016) {
        if (eta >= -2.5 && eta < -2 && pt >= 10 && pt < 20) return 1.0423;
        if (eta >= -2 && eta < -1.566 && pt >= 10 && pt < 20) return 0.974386;
        if (eta >= -1.566 && eta < -1.444 && pt >= 10 && pt < 20) return 1.42773;
        if (eta >= -1.444 && eta < -1 && pt >= 10 && pt < 20) return 0.98935;
        if (eta >= -1 && eta < 0 && pt >= 10 && pt < 20) return 0.981953;
        if (eta >= 0 && eta < 1 && pt >= 10 && pt < 20) return 0.981953;
        if (eta >= 1 && eta < 1.444 && pt >= 10 && pt < 20) return 0.98935;
        if (eta >= 1.444 && eta < 1.566 && pt >= 10 && pt < 20) return 1.42773;
        if (eta >= 1.566 && eta < 2 && pt >= 10 && pt < 20) return 0.974386;
        if (eta >= 2 && eta < 2.5 && pt >= 10 && pt < 20) return 1.0423;
        if (eta >= -2.5 && eta < -2 && pt >= 20 && pt < 45) return 1.01641;
        if (eta >= -2.5 && eta < -2 && pt >= 45 && pt < 75) return 1.00213;
        if (eta >= -2.5 && eta < -2 && pt >= 75 && pt < 100) return 1.01803;
        if (eta >= -2.5 && eta < -2 && pt >= 100) return 0.98431;
        if (eta >= -2 && eta < -1.566 && pt >= 20 && pt < 45) return 0.997925;
        if (eta >= -2 && eta < -1.566 && pt >= 45 && pt < 75) return 0.996907;
        if (eta >= -2 && eta < -1.566 && pt >= 75 && pt < 100) return 1.01542;
        if (eta >= -2 && eta < -1.566 && pt >= 100) return 1;
        if (eta >= -1.566 && eta < -1.444 && pt >= 20 && pt < 45) return 0.990773;
        if (eta >= -1.566 && eta < -1.444 && pt >= 45 && pt < 75) return 0.962244;
        if (eta >= -1.566 && eta < -1.444 && pt >= 75 && pt < 100) return 1.03289;
        if (eta >= -1.566 && eta < -1.444 && pt >= 100) return 1.00218;
        if (eta >= -1.444 && eta < -1 && pt >= 20 && pt < 45) return 0.991786;
        if (eta >= -1.444 && eta < -1 && pt >= 45 && pt < 75) return 0.991845;
        if (eta >= -1.444 && eta < -1 && pt >= 75 && pt < 100) return 1.00811;
        if (eta >= -1.444 && eta < -1 && pt >= 100) return 0.986882;
        if (eta >= -1 && eta < -0.5 && pt >= 20 && pt < 45) return 0.986721;
        if (eta >= -1 && eta < -0.5 && pt >= 45 && pt < 75) return 0.987817;
        if (eta >= -1 && eta < -0.5 && pt >= 75 && pt < 100) return 1.00508;
        if (eta >= -1 && eta < -0.5 && pt >= 100) return 0.993939;
        if (eta >= -0.5 && eta < 0 && pt >= 20 && pt < 45) return 0.98359;
        if (eta >= -0.5 && eta < 0 && pt >= 45 && pt < 75) return 0.986762;
        if (eta >= -0.5 && eta < 0 && pt >= 75 && pt < 100) return 0.996945;
        if (eta >= -0.5 && eta < 0 && pt >= 100) return 0.98583;
        if (eta >= 0 && eta < 0.5 && pt >= 20 && pt < 45) return 0.98359;
        if (eta >= 0 && eta < 0.5 && pt >= 45 && pt < 75) return 0.986762;
        if (eta >= 0 && eta < 0.5 && pt >= 75 && pt < 100) return 0.996945;
        if (eta >= 0 && eta < 0.5 && pt >= 100) return 0.98583;
        if (eta >= 0.5 && eta < 1 && pt >= 20 && pt < 45) return 0.986721;
        if (eta >= 0.5 && eta < 1 && pt >= 45 && pt < 75) return 0.987817;
        if (eta >= 0.5 && eta < 1 && pt >= 75 && pt < 100) return 1.00508;
        if (eta >= 0.5 && eta < 1 && pt >= 100) return 0.993939;
        if (eta >= 1 && eta < 1.444 && pt >= 20 && pt < 45) return 0.991786;
        if (eta >= 1 && eta < 1.444 && pt >= 45 && pt < 75) return 0.991845;
        if (eta >= 1 && eta < 1.444 && pt >= 75 && pt < 100) return 1.00811;
        if (eta >= 1 && eta < 1.444 && pt >= 100) return 0.986882;
        if (eta >= 1.444 && eta < 1.566 && pt >= 20 && pt < 45) return 0.990773;
        if (eta >= 1.444 && eta < 1.566 && pt >= 45 && pt < 75) return 0.962244;
        if (eta >= 1.444 && eta < 1.566 && pt >= 75 && pt < 100) return 1.03289;
        if (eta >= 1.444 && eta < 1.566 && pt >= 100) return 1.00218;
        if (eta >= 1.566 && eta < 2 && pt >= 20 && pt < 45) return 0.997925;
        if (eta >= 1.566 && eta < 2 && pt >= 45 && pt < 75) return 0.996907;
        if (eta >= 1.566 && eta < 2 && pt >= 75 && pt < 100) return 1.01542;
        if (eta >= 1.566 && eta < 2 && pt >= 100) return 1;
        if (eta >= 2 && eta < 2.5 && pt >= 20 && pt < 45) return 1.01641;
        if (eta >= 2 && eta < 2.5 && pt >= 45 && pt < 75) return 1.00213;
        if (eta >= 2 && eta < 2.5 && pt >= 75 && pt < 100) return 1.01803;
        if (eta >= 2 && eta < 2.5 && pt >= 100) return 0.98431;
    }
    if (year == 2017) {
        if (eta >= -2.5 && eta < -2 && pt >= 10 && pt < 20) return 0.982328;
        if (eta >= -2 && eta < -1.566 && pt >= 10 && pt < 20) return 0.988577;
        if (eta >= -1.566 && eta < -1.444 && pt >= 10 && pt < 20) return 1;
        if (eta >= -1.444 && eta < -1 && pt >= 10 && pt < 20) return 0.976471;
        if (eta >= -1 && eta < 0 && pt >= 10 && pt < 20) return 0.969312;
        if (eta >= 0 && eta < 1 && pt >= 10 && pt < 20) return 0.969312;
        if (eta >= 1 && eta < 1.444 && pt >= 10 && pt < 20) return 0.976471;
        if (eta >= 1.444 && eta < 1.566 && pt >= 10 && pt < 20) return 1;
        if (eta >= 1.566 && eta < 2 && pt >= 10 && pt < 20) return 0.988577;
        if (eta >= 2 && eta < 2.5 && pt >= 10 && pt < 20) return 0.982328;
        if (eta >= -2.5 && eta < -2 && pt >= 20 && pt < 45) return 0.977482;
        if (eta >= -2.5 && eta < -2 && pt >= 45 && pt < 75) return 0.983673;
        if (eta >= -2.5 && eta < -2 && pt >= 75 && pt < 100) return 0.996951;
        if (eta >= -2.5 && eta < -2 && pt >= 100) return 0.989909;
        if (eta >= -2 && eta < -1.566 && pt >= 20 && pt < 45) return 0.981614;
        if (eta >= -2 && eta < -1.566 && pt >= 45 && pt < 75) return 0.981707;
        if (eta >= -2 && eta < -1.566 && pt >= 75 && pt < 100) return 0.996954;
        if (eta >= -2 && eta < -1.566 && pt >= 100) return 0.989889;
        if (eta >= -1.566 && eta < -1.444 && pt >= 20 && pt < 45) return 0.948352;
        if (eta >= -1.566 && eta < -1.444 && pt >= 45 && pt < 75) return 0.970619;
        if (eta >= -1.566 && eta < -1.444 && pt >= 75 && pt < 100) return 1.00323;
        if (eta >= -1.566 && eta < -1.444 && pt >= 100) return 1.00959;
        if (eta >= -1.444 && eta < -1 && pt >= 20 && pt < 45) return 0.969262;
        if (eta >= -1.444 && eta < -1 && pt >= 45 && pt < 75) return 0.975535;
        if (eta >= -1.444 && eta < -1 && pt >= 75 && pt < 100) return 0.995902;
        if (eta >= -1.444 && eta < -1 && pt >= 100) return 0.984725;
        if (eta >= -1 && eta < -0.5 && pt >= 20 && pt < 45) return 0.976555;
        if (eta >= -1 && eta < -0.5 && pt >= 45 && pt < 75) return 0.979695;
        if (eta >= -1 && eta < -0.5 && pt >= 75 && pt < 100) return 0.991895;
        if (eta >= -1 && eta < -0.5 && pt >= 100) return 0.987891;
        if (eta >= -0.5 && eta < 0 && pt >= 20 && pt < 45) return 0.970378;
        if (eta >= -0.5 && eta < 0 && pt >= 45 && pt < 75) return 0.979654;
        if (eta >= -0.5 && eta < 0 && pt >= 75 && pt < 100) return 0.991903;
        if (eta >= -0.5 && eta < 0 && pt >= 100) return 0.993933;
        if (eta >= 0 && eta < 0.5 && pt >= 20 && pt < 45) return 0.970348;
        if (eta >= 0 && eta < 0.5 && pt >= 45 && pt < 75) return 0.97762;
        if (eta >= 0 && eta < 0.5 && pt >= 75 && pt < 100) return 0.991903;
        if (eta >= 0 && eta < 0.5 && pt >= 100) return 0.993933;
        if (eta >= 0.5 && eta < 1 && pt >= 20 && pt < 45) return 0.972421;
        if (eta >= 0.5 && eta < 1 && pt >= 45 && pt < 75) return 0.97868;
        if (eta >= 0.5 && eta < 1 && pt >= 75 && pt < 100) return 0.991895;
        if (eta >= 0.5 && eta < 1 && pt >= 100) return 0.987891;
        if (eta >= 1 && eta < 1.444 && pt >= 20 && pt < 45) return 0.969917;
        if (eta >= 1 && eta < 1.444 && pt >= 45 && pt < 75) return 0.977366;
        if (eta >= 1 && eta < 1.444 && pt >= 75 && pt < 100) return 0.995902;
        if (eta >= 1 && eta < 1.444 && pt >= 100) return 0.984725;
        if (eta >= 1.444 && eta < 1.566 && pt >= 20 && pt < 45) return 0.957965;
        if (eta >= 1.444 && eta < 1.566 && pt >= 45 && pt < 75) return 0.963945;
        if (eta >= 1.444 && eta < 1.566 && pt >= 75 && pt < 100) return 1.00323;
        if (eta >= 1.444 && eta < 1.566 && pt >= 100) return 1.00959;
        if (eta >= 1.566 && eta < 2 && pt >= 20 && pt < 45) return 0.979592;
        if (eta >= 1.566 && eta < 2 && pt >= 45 && pt < 75) return 0.982741;
        if (eta >= 1.566 && eta < 2 && pt >= 75 && pt < 100) return 0.996954;
        if (eta >= 1.566 && eta < 2 && pt >= 100) return 0.989889;
        if (eta >= 2 && eta < 2.5 && pt >= 20 && pt < 45) return 0.979592;
        if (eta >= 2 && eta < 2.5 && pt >= 45 && pt < 75) return 0.98374;
        if (eta >= 2 && eta < 2.5 && pt >= 75 && pt < 100) return 0.996951;
        if (eta >= 2 && eta < 2.5 && pt >= 100) return 0.989909;
    }
    if (year == 2018) {
        if (fabs(eta) >= -2.5 && fabs(eta) < -2 && pt >= 20 && pt < 45) return 0.977482;
        if (fabs(eta) >= -2.5 && fabs(eta) < -2 && pt >= 45 && pt < 75) return 0.983673;
        if (fabs(eta) >= -2.5 && fabs(eta) < -2 && pt >= 75 && pt < 100) return 0.996951;
        if (fabs(eta) >= -2.5 && fabs(eta) < -2 && pt >= 100) return 0.989909;
        if (fabs(eta) >= -2 && fabs(eta) < -1.566 && pt >= 20 && pt < 45) return 0.981614;
        if (fabs(eta) >= -2 && fabs(eta) < -1.566 && pt >= 45 && pt < 75) return 0.981707;
        if (fabs(eta) >= -2 && fabs(eta) < -1.566 && pt >= 75 && pt < 100) return 0.996954;
        if (fabs(eta) >= -2 && fabs(eta) < -1.566 && pt >= 100) return 0.989889;
        if (fabs(eta) >= -1.566 && fabs(eta) < -1.444 && pt >= 20 && pt < 45) return 0.948352;
        if (fabs(eta) >= -1.566 && fabs(eta) < -1.444 && pt >= 45 && pt < 75) return 0.970619;
        if (fabs(eta) >= -1.566 && fabs(eta) < -1.444 && pt >= 75 && pt < 100) return 1.00323;
        if (fabs(eta) >= -1.566 && fabs(eta) < -1.444 && pt >= 100) return 1.00959;
        if (fabs(eta) >= -1.444 && fabs(eta) < -1 && pt >= 20 && pt < 45) return 0.969262;
        if (fabs(eta) >= -1.444 && fabs(eta) < -1 && pt >= 45 && pt < 75) return 0.975535;
        if (fabs(eta) >= -1.444 && fabs(eta) < -1 && pt >= 75 && pt < 100) return 0.995902;
        if (fabs(eta) >= -1.444 && fabs(eta) < -1 && pt >= 100) return 0.984725;
        if (fabs(eta) >= -1 && fabs(eta) < -0.5 && pt >= 20 && pt < 45) return 0.976555;
        if (fabs(eta) >= -1 && fabs(eta) < -0.5 && pt >= 45 && pt < 75) return 0.979695;
        if (fabs(eta) >= -1 && fabs(eta) < -0.5 && pt >= 75 && pt < 100) return 0.991895;
        if (fabs(eta) >= -1 && fabs(eta) < -0.5 && pt >= 100) return 0.987891;
        if (fabs(eta) >= -0.5 && fabs(eta) < 0 && pt >= 20 && pt < 45) return 0.970378;
        if (fabs(eta) >= -0.5 && fabs(eta) < 0 && pt >= 45 && pt < 75) return 0.979654;
        if (fabs(eta) >= -0.5 && fabs(eta) < 0 && pt >= 75 && pt < 100) return 0.991903;
        if (fabs(eta) >= -0.5 && fabs(eta) < 0 && pt >= 100) return 0.993933;
        if (fabs(eta) >= 0 && fabs(eta) < 0.5 && pt >= 20 && pt < 45) return 0.970348;
        if (fabs(eta) >= 0 && fabs(eta) < 0.5 && pt >= 45 && pt < 75) return 0.97762;
        if (fabs(eta) >= 0 && fabs(eta) < 0.5 && pt >= 75 && pt < 100) return 0.991903;
        if (fabs(eta) >= 0 && fabs(eta) < 0.5 && pt >= 100) return 0.993933;
        if (fabs(eta) >= 0.5 && fabs(eta) < 1 && pt >= 20 && pt < 45) return 0.972421;
        if (fabs(eta) >= 0.5 && fabs(eta) < 1 && pt >= 45 && pt < 75) return 0.97868;
        if (fabs(eta) >= 0.5 && fabs(eta) < 1 && pt >= 75 && pt < 100) return 0.991895;
        if (fabs(eta) >= 0.5 && fabs(eta) < 1 && pt >= 100) return 0.987891;
        if (fabs(eta) >= 1 && fabs(eta) < 1.444 && pt >= 20 && pt < 45) return 0.969917;
        if (fabs(eta) >= 1 && fabs(eta) < 1.444 && pt >= 45 && pt < 75) return 0.977366;
        if (fabs(eta) >= 1 && fabs(eta) < 1.444 && pt >= 75 && pt < 100) return 0.995902;
        if (fabs(eta) >= 1 && fabs(eta) < 1.444 && pt >= 100) return 0.984725;
        if (fabs(eta) >= 1.444 && fabs(eta) < 1.566 && pt >= 20 && pt < 45) return 0.957965;
        if (fabs(eta) >= 1.444 && fabs(eta) < 1.566 && pt >= 45 && pt < 75) return 0.963945;
        if (fabs(eta) >= 1.444 && fabs(eta) < 1.566 && pt >= 75 && pt < 100) return 1.00323;
        if (fabs(eta) >= 1.444 && fabs(eta) < 1.566 && pt >= 100) return 1.00959;
        if (fabs(eta) >= 1.566 && fabs(eta) < 2 && pt >= 20 && pt < 45) return 0.979592;
        if (fabs(eta) >= 1.566 && fabs(eta) < 2 && pt >= 45 && pt < 75) return 0.982741;
        if (fabs(eta) >= 1.566 && fabs(eta) < 2 && pt >= 75 && pt < 100) return 0.996954;
        if (fabs(eta) >= 1.566 && fabs(eta) < 2 && pt >= 100) return 0.989889;
        if (fabs(eta) >= 2 && fabs(eta) < 2.5 && pt >= 20 && pt < 45) return 0.979592;
        if (fabs(eta) >= 2 && fabs(eta) < 2.5 && pt >= 45 && pt < 75) return 0.98374;
        if (fabs(eta) >= 2 && fabs(eta) < 2.5 && pt >= 75 && pt < 100) return 0.996951;
        if (fabs(eta) >= 2 && fabs(eta) < 2.5 && pt >= 100) return 0.989909;
    }
    return 0.0;
}

float ttH::getElecRecoEffSFErr(float eta, float pt, int year) {
    if (year == 2016) {
        if (eta >= -2.5 && eta < -2 && pt >= 10 && pt < 20) return 0.0142472;
        if (eta >= -2 && eta < -1.566 && pt >= 10 && pt < 20) return 0.010292;
        if (eta >= -1.566 && eta < -1.444 && pt >= 10 && pt < 20) return 0.116351;
        if (eta >= -1.444 && eta < -1 && pt >= 10 && pt < 20) return 0.018991;
        if (eta >= -1 && eta < 0 && pt >= 10 && pt < 20) return 0.0226441;
        if (eta >= 0 && eta < 1 && pt >= 10 && pt < 20) return 0.0226441;
        if (eta >= 1 && eta < 1.444 && pt >= 10 && pt < 20) return 0.018991;
        if (eta >= 1.444 && eta < 1.566 && pt >= 10 && pt < 20) return 0.116351;
        if (eta >= 1.566 && eta < 2 && pt >= 10 && pt < 20) return 0.010292;
        if (eta >= 2 && eta < 2.5 && pt >= 10 && pt < 20) return 0.0142472;
        if (eta >= -2.5 && eta < -2 && pt >= 20 && pt < 45) return 0.0039448;
        if (eta >= -2.5 && eta < -2 && pt >= 45 && pt < 75) return 0.00638298;
        if (eta >= -2.5 && eta < -2 && pt >= 75 && pt < 100) return 0.0122297;
        if (eta >= -2.5 && eta < -2 && pt >= 100) return 0.0174407;
        if (eta >= -2 && eta < -1.566 && pt >= 20 && pt < 45) return 0.00274456;
        if (eta >= -2 && eta < -1.566 && pt >= 45 && pt < 75) return 0.00449371;
        if (eta >= -2 && eta < -1.566 && pt >= 75 && pt < 100) return 0.0106807;
        if (eta >= -2 && eta < -1.566 && pt >= 100) return 0.0101529;
        if (eta >= -1.566 && eta < -1.444 && pt >= 20 && pt < 45) return 0.0798684;
        if (eta >= -1.566 && eta < -1.444 && pt >= 45 && pt < 75) return 0.0229852;
        if (eta >= -1.566 && eta < -1.444 && pt >= 75 && pt < 100) return 0.0441465;
        if (eta >= -1.566 && eta < -1.444 && pt >= 100) return 0.0465362;
        if (eta >= -1.444 && eta < -1 && pt >= 20 && pt < 45) return 0.00271638;
        if (eta >= -1.444 && eta < -1 && pt >= 45 && pt < 75) return 0.00529679;
        if (eta >= -1.444 && eta < -1 && pt >= 75 && pt < 100) return 0.005555;
        if (eta >= -1.444 && eta < -1 && pt >= 100) return 0.00684393;
        if (eta >= -1 && eta < -0.5 && pt >= 20 && pt < 45) return 0.00250203;
        if (eta >= -1 && eta < -0.5 && pt >= 45 && pt < 75) return 0.00351685;
        if (eta >= -1 && eta < -0.5 && pt >= 75 && pt < 100) return 0.00465236;
        if (eta >= -1 && eta < -0.5 && pt >= 100) return 0.00580259;
        if (eta >= -0.5 && eta < 0 && pt >= 20 && pt < 45) return 0.00271359;
        if (eta >= -0.5 && eta < 0 && pt >= 45 && pt < 75) return 0.0035276;
        if (eta >= -0.5 && eta < 0 && pt >= 75 && pt < 100) return 0.00644048;
        if (eta >= -0.5 && eta < 0 && pt >= 100) return 0.00686471;
        if (eta >= 0 && eta < 0.5 && pt >= 20 && pt < 45) return 0.00271359;
        if (eta >= 0 && eta < 0.5 && pt >= 45 && pt < 75) return 0.0035276;
        if (eta >= 0 && eta < 0.5 && pt >= 75 && pt < 100) return 0.00644048;
        if (eta >= 0 && eta < 0.5 && pt >= 100) return 0.00686471;
        if (eta >= 0.5 && eta < 1 && pt >= 20 && pt < 45) return 0.00250203;
        if (eta >= 0.5 && eta < 1 && pt >= 45 && pt < 75) return 0.00351685;
        if (eta >= 0.5 && eta < 1 && pt >= 75 && pt < 100) return 0.00465236;
        if (eta >= 0.5 && eta < 1 && pt >= 100) return 0.00580259;
        if (eta >= 1 && eta < 1.444 && pt >= 20 && pt < 45) return 0.00271638;
        if (eta >= 1 && eta < 1.444 && pt >= 45 && pt < 75) return 0.00529679;
        if (eta >= 1 && eta < 1.444 && pt >= 75 && pt < 100) return 0.005555;
        if (eta >= 1 && eta < 1.444 && pt >= 100) return 0.00684393;
        if (eta >= 1.444 && eta < 1.566 && pt >= 20 && pt < 45) return 0.0798684;
        if (eta >= 1.444 && eta < 1.566 && pt >= 45 && pt < 75) return 0.0229852;
        if (eta >= 1.444 && eta < 1.566 && pt >= 75 && pt < 100) return 0.0441465;
        if (eta >= 1.444 && eta < 1.566 && pt >= 100) return 0.0465362;
        if (eta >= 1.566 && eta < 2 && pt >= 20 && pt < 45) return 0.00274456;
        if (eta >= 1.566 && eta < 2 && pt >= 45 && pt < 75) return 0.00449371;
        if (eta >= 1.566 && eta < 2 && pt >= 75 && pt < 100) return 0.0106807;
        if (eta >= 1.566 && eta < 2 && pt >= 100) return 0.0101529;
        if (eta >= 2 && eta < 2.5 && pt >= 20 && pt < 45) return 0.0039448;
        if (eta >= 2 && eta < 2.5 && pt >= 45 && pt < 75) return 0.00638298;
        if (eta >= 2 && eta < 2.5 && pt >= 75 && pt < 100) return 0.0122297;
        if (eta >= 2 && eta < 2.5 && pt >= 100) return 0.0174407;
    }
    if (year == 2017) {
        if (eta >= -2.5 && eta < -2 && pt >= 10 && pt < 20) return 0.0595608;
        if (eta >= -2 && eta < -1.566 && pt >= 10 && pt < 20) return 0.0201089;
        if (eta >= -1.566 && eta < -1.444 && pt >= 10 && pt < 20) return 0.0307087;
        if (eta >= -1.444 && eta < -1 && pt >= 10 && pt < 20) return 0.0826095;
        if (eta >= -1 && eta < 0 && pt >= 10 && pt < 20) return 0.0544845;
        if (eta >= 0 && eta < 1 && pt >= 10 && pt < 20) return 0.0544845;
        if (eta >= 1 && eta < 1.444 && pt >= 10 && pt < 20) return 0.0826095;
        if (eta >= 1.444 && eta < 1.566 && pt >= 10 && pt < 20) return 0.0307087;
        if (eta >= 1.566 && eta < 2 && pt >= 10 && pt < 20) return 0.0201089;
        if (eta >= 2 && eta < 2.5 && pt >= 10 && pt < 20) return 0.0595608;
        if (eta >= -2.5 && eta < -2 && pt >= 20 && pt < 45) return 0.00757915;
        if (eta >= -2.5 && eta < -2 && pt >= 45 && pt < 75) return 0.00370678;
        if (eta >= -2.5 && eta < -2 && pt >= 75 && pt < 100) return 0.0150393;
        if (eta >= -2.5 && eta < -2 && pt >= 100) return 0.00962603;
        if (eta >= -2 && eta < -1.566 && pt >= 20 && pt < 45) return 0.00260287;
        if (eta >= -2 && eta < -1.566 && pt >= 45 && pt < 75) return 0.00386784;
        if (eta >= -2 && eta < -1.566 && pt >= 75 && pt < 100) return 0.00779812;
        if (eta >= -2 && eta < -1.566 && pt >= 100) return 0.00484917;
        if (eta >= -1.566 && eta < -1.444 && pt >= 20 && pt < 45) return 0.0139352;
        if (eta >= -1.566 && eta < -1.444 && pt >= 45 && pt < 75) return 0.0139269;
        if (eta >= -1.566 && eta < -1.444 && pt >= 75 && pt < 100) return 0.0408191;
        if (eta >= -1.566 && eta < -1.444 && pt >= 100) return 0.0491216;
        if (eta >= -1.444 && eta < -1 && pt >= 20 && pt < 45) return 0.00502412;
        if (eta >= -1.444 && eta < -1 && pt >= 45 && pt < 75) return 0.00437481;
        if (eta >= -1.444 && eta < -1 && pt >= 75 && pt < 100) return 0.00787003;
        if (eta >= -1.444 && eta < -1 && pt >= 100) return 0.00627741;
        if (eta >= -1 && eta < -0.5 && pt >= 20 && pt < 45) return 0.00478614;
        if (eta >= -1 && eta < -0.5 && pt >= 45 && pt < 75) return 0.00263764;
        if (eta >= -1 && eta < -0.5 && pt >= 75 && pt < 100) return 0.00248175;
        if (eta >= -1 && eta < -0.5 && pt >= 100) return 0.00494347;
        if (eta >= -0.5 && eta < 0 && pt >= 20 && pt < 45) return 0.00681741;
        if (eta >= -0.5 && eta < 0 && pt >= 45 && pt < 75) return 0.00264301;
        if (eta >= -0.5 && eta < 0 && pt >= 75 && pt < 100) return 0.00392002;
        if (eta >= -0.5 && eta < 0 && pt >= 100) return 0.00175132;
        if (eta >= 0 && eta < 0.5 && pt >= 20 && pt < 45) return 0.00681741;
        if (eta >= 0 && eta < 0.5 && pt >= 45 && pt < 75) return 0.00264301;
        if (eta >= 0 && eta < 0.5 && pt >= 75 && pt < 100) return 0.00392002;
        if (eta >= 0 && eta < 0.5 && pt >= 100) return 0.00175132;
        if (eta >= 0.5 && eta < 1 && pt >= 20 && pt < 45) return 0.00478614;
        if (eta >= 0.5 && eta < 1 && pt >= 45 && pt < 75) return 0.00263764;
        if (eta >= 0.5 && eta < 1 && pt >= 75 && pt < 100) return 0.00248175;
        if (eta >= 0.5 && eta < 1 && pt >= 100) return 0.00494347;
        if (eta >= 1 && eta < 1.444 && pt >= 20 && pt < 45) return 0.00502412;
        if (eta >= 1 && eta < 1.444 && pt >= 45 && pt < 75) return 0.00437481;
        if (eta >= 1 && eta < 1.444 && pt >= 75 && pt < 100) return 0.00787003;
        if (eta >= 1 && eta < 1.444 && pt >= 100) return 0.00627741;
        if (eta >= 1.444 && eta < 1.566 && pt >= 20 && pt < 45) return 0.0139352;
        if (eta >= 1.444 && eta < 1.566 && pt >= 45 && pt < 75) return 0.0139544;
        if (eta >= 1.444 && eta < 1.566 && pt >= 75 && pt < 100) return 0.0408191;
        if (eta >= 1.444 && eta < 1.566 && pt >= 100) return 0.0491216;
        if (eta >= 1.566 && eta < 2 && pt >= 20 && pt < 45) return 0.00260287;
        if (eta >= 1.566 && eta < 2 && pt >= 45 && pt < 75) return 0.00386784;
        if (eta >= 1.566 && eta < 2 && pt >= 75 && pt < 100) return 0.00779812;
        if (eta >= 1.566 && eta < 2 && pt >= 100) return 0.00484917;
        if (eta >= 2 && eta < 2.5 && pt >= 20 && pt < 45) return 0.00757915;
        if (eta >= 2 && eta < 2.5 && pt >= 45 && pt < 75) return 0.00370678;
        if (eta >= 2 && eta < 2.5 && pt >= 75 && pt < 100) return 0.0150393;
        if (eta >= 2 && eta < 2.5 && pt >= 100) return 0.00962603;
    }
    if (year == 2018) {
        if (fabs(eta) >= -2.5 && fabs(eta) < -2 && pt >= 20 && pt < 45) return 0.00757915;
        if (fabs(eta) >= -2.5 && fabs(eta) < -2 && pt >= 45 && pt < 75) return 0.00370678;
        if (fabs(eta) >= -2.5 && fabs(eta) < -2 && pt >= 75 && pt < 100) return 0.0150393;
        if (fabs(eta) >= -2.5 && fabs(eta) < -2 && pt >= 100) return 0.00962603;
        if (fabs(eta) >= -2 && fabs(eta) < -1.566 && pt >= 20 && pt < 45) return 0.00260287;
        if (fabs(eta) >= -2 && fabs(eta) < -1.566 && pt >= 45 && pt < 75) return 0.00386784;
        if (fabs(eta) >= -2 && fabs(eta) < -1.566 && pt >= 75 && pt < 100) return 0.00779812;
        if (fabs(eta) >= -2 && fabs(eta) < -1.566 && pt >= 100) return 0.00484917;
        if (fabs(eta) >= -1.566 && fabs(eta) < -1.444 && pt >= 20 && pt < 45) return 0.0139352;
        if (fabs(eta) >= -1.566 && fabs(eta) < -1.444 && pt >= 45 && pt < 75) return 0.0139269;
        if (fabs(eta) >= -1.566 && fabs(eta) < -1.444 && pt >= 75 && pt < 100) return 0.0408191;
        if (fabs(eta) >= -1.566 && fabs(eta) < -1.444 && pt >= 100) return 0.0491216;
        if (fabs(eta) >= -1.444 && fabs(eta) < -1 && pt >= 20 && pt < 45) return 0.00502412;
        if (fabs(eta) >= -1.444 && fabs(eta) < -1 && pt >= 45 && pt < 75) return 0.00437481;
        if (fabs(eta) >= -1.444 && fabs(eta) < -1 && pt >= 75 && pt < 100) return 0.00787003;
        if (fabs(eta) >= -1.444 && fabs(eta) < -1 && pt >= 100) return 0.00627741;
        if (fabs(eta) >= -1 && fabs(eta) < -0.5 && pt >= 20 && pt < 45) return 0.00478614;
        if (fabs(eta) >= -1 && fabs(eta) < -0.5 && pt >= 45 && pt < 75) return 0.00263764;
        if (fabs(eta) >= -1 && fabs(eta) < -0.5 && pt >= 75 && pt < 100) return 0.00248175;
        if (fabs(eta) >= -1 && fabs(eta) < -0.5 && pt >= 100) return 0.00494347;
        if (fabs(eta) >= -0.5 && fabs(eta) < 0 && pt >= 20 && pt < 45) return 0.00681741;
        if (fabs(eta) >= -0.5 && fabs(eta) < 0 && pt >= 45 && pt < 75) return 0.00264301;
        if (fabs(eta) >= -0.5 && fabs(eta) < 0 && pt >= 75 && pt < 100) return 0.00392002;
        if (fabs(eta) >= -0.5 && fabs(eta) < 0 && pt >= 100) return 0.00175132;
        if (fabs(eta) >= 0 && fabs(eta) < 0.5 && pt >= 20 && pt < 45) return 0.00681741;
        if (fabs(eta) >= 0 && fabs(eta) < 0.5 && pt >= 45 && pt < 75) return 0.00264301;
        if (fabs(eta) >= 0 && fabs(eta) < 0.5 && pt >= 75 && pt < 100) return 0.00392002;
        if (fabs(eta) >= 0 && fabs(eta) < 0.5 && pt >= 100) return 0.00175132;
        if (fabs(eta) >= 0.5 && fabs(eta) < 1 && pt >= 20 && pt < 45) return 0.00478614;
        if (fabs(eta) >= 0.5 && fabs(eta) < 1 && pt >= 45 && pt < 75) return 0.00263764;
        if (fabs(eta) >= 0.5 && fabs(eta) < 1 && pt >= 75 && pt < 100) return 0.00248175;
        if (fabs(eta) >= 0.5 && fabs(eta) < 1 && pt >= 100) return 0.00494347;
        if (fabs(eta) >= 1 && fabs(eta) < 1.444 && pt >= 20 && pt < 45) return 0.00502412;
        if (fabs(eta) >= 1 && fabs(eta) < 1.444 && pt >= 45 && pt < 75) return 0.00437481;
        if (fabs(eta) >= 1 && fabs(eta) < 1.444 && pt >= 75 && pt < 100) return 0.00787003;
        if (fabs(eta) >= 1 && fabs(eta) < 1.444 && pt >= 100) return 0.00627741;
        if (fabs(eta) >= 1.444 && fabs(eta) < 1.566 && pt >= 20 && pt < 45) return 0.0139352;
        if (fabs(eta) >= 1.444 && fabs(eta) < 1.566 && pt >= 45 && pt < 75) return 0.0139544;
        if (fabs(eta) >= 1.444 && fabs(eta) < 1.566 && pt >= 75 && pt < 100) return 0.0408191;
        if (fabs(eta) >= 1.444 && fabs(eta) < 1.566 && pt >= 100) return 0.0491216;
        if (fabs(eta) >= 1.566 && fabs(eta) < 2 && pt >= 20 && pt < 45) return 0.00260287;
        if (fabs(eta) >= 1.566 && fabs(eta) < 2 && pt >= 45 && pt < 75) return 0.00386784;
        if (fabs(eta) >= 1.566 && fabs(eta) < 2 && pt >= 75 && pt < 100) return 0.00779812;
        if (fabs(eta) >= 1.566 && fabs(eta) < 2 && pt >= 100) return 0.00484917;
        if (fabs(eta) >= 2 && fabs(eta) < 2.5 && pt >= 20 && pt < 45) return 0.00757915;
        if (fabs(eta) >= 2 && fabs(eta) < 2.5 && pt >= 45 && pt < 75) return 0.00370678;
        if (fabs(eta) >= 2 && fabs(eta) < 2.5 && pt >= 75 && pt < 100) return 0.0150393;
        if (fabs(eta) >= 2 && fabs(eta) < 2.5 && pt >= 100) return 0.00962603;
    }
    return 0.0;
}

float ttH::getMuonTightSFRederived(float eta, float pt, int year, bool isAPV, int syst)
{
    if (year == 2016 and isAPV)
    {
        if (pt >= 40 and pt < 45)
        {
            if (fabs(eta) >= 0.0 and fabs(eta) < 0.9)
            {
                return (syst == 0 ? 0.993029182885 : (syst == 1 ? 0.994297527216 : 0.991760838553));
            }
            else if (fabs(eta) >= 0.9 and fabs(eta) < 1.2)
            {
                return (syst == 0 ? 0.991588101886 : (syst == 1 ? 0.993843745648 : 0.989332458124));
            }
            else if (fabs(eta) >= 1.2 and fabs(eta) < 2.1)
            {
                return (syst == 0 ? 0.99382189308 : (syst == 1 ? 0.995321701257 : 0.992322084904));
            }
            else if (fabs(eta) >= 2.1)
            {
                return (syst == 0 ? 0.987137696461 : (syst == 1 ? 0.990502752075 : 0.983772640848));
            }
            else
            {
                return 1; // No SF computed for this phase-space
            }
        }
        else if (pt >= 45 and pt < 55)
        {
            if (fabs(eta) >= 0.0 and fabs(eta) < 0.9)
            {
                return (syst == 0 ? 0.994008235011 : (syst == 1 ? 0.995376726864 : 0.992639743158));
            }
            else if (fabs(eta) >= 0.9 and fabs(eta) < 1.2)
            {
                return (syst == 0 ? 0.992546435581 : (syst == 1 ? 0.994952038355 : 0.990140832807));
            }
            else if (fabs(eta) >= 1.2 and fabs(eta) < 2.1)
            {
                return (syst == 0 ? 0.992953885301 : (syst == 1 ? 0.994506300123 : 0.991401470478));
            }
            else if (fabs(eta) >= 2.1)
            {
                return (syst == 0 ? 0.986406038949 : (syst == 1 ? 0.989937584352 : 0.982874493546));
            }
            else
            {
                return 1; // No SF computed for this phase-space
            }
        }
        else if (pt >= 55 and pt < 80)
        {
            if (fabs(eta) >= 0.0 and fabs(eta) < 0.9)
            {
                return (syst == 0 ? 0.991823242964 : (syst == 1 ? 0.994490412162 : 0.989156073766));
            }
            else if (fabs(eta) >= 0.9 and fabs(eta) < 1.2)
            {
                return (syst == 0 ? 0.990658463843 : (syst == 1 ? 0.995388366087 : 0.985928561598));
            }
            else if (fabs(eta) >= 1.2 and fabs(eta) < 2.1)
            {
                return (syst == 0 ? 0.988535205098 : (syst == 1 ? 0.991610484036 : 0.985459926161));
            }
            else if (fabs(eta) >= 2.1)
            {
                return (syst == 0 ? 0.976148241582 : (syst == 1 ? 0.983061618068 : 0.969234865095));
            }
            else
            {
                return 1; // No SF computed for this phase-space
            }
        }
        else if (pt >= 80)
        {
            if (fabs(eta) >= 0.0 and fabs(eta) < 0.9)
            {
                return (syst == 0 ? 0.991494761519 : (syst == 1 ? 0.997853578305 : 0.985135944733));
            }
            else if (fabs(eta) >= 0.9 and fabs(eta) < 1.2)
            {
                return (syst == 0 ? 0.990229415956 : (syst == 1 ? 1.00169848975 : 0.978760342163));
            }
            else if (fabs(eta) >= 1.2 and fabs(eta) < 2.1)
            {
                return (syst == 0 ? 0.988422461097 : (syst == 1 ? 0.996178855341 : 0.980666066853));
            }
            else if (fabs(eta) >= 2.1)
            {
                return (syst == 0 ? 0.969961986659 : (syst == 1 ? 0.988429989718 : 0.951493983601));
            }
            else
            {
                return 1; // No SF computed for this phase-space
            }
        }
        else
        {
            if (fabs(eta) >= 0.0 and fabs(eta) < 0.9)
            {
                return 1; // No SF computed for this phase-space
            }
            else if (fabs(eta) >= 0.9 and fabs(eta) < 1.2)
            {
                return 1; // No SF computed for this phase-space
            }
            else if (fabs(eta) >= 1.2 and fabs(eta) < 2.1)
            {
                return 1; // No SF computed for this phase-space
            }
            else if (fabs(eta) >= 2.1)
            {
                return 1; // No SF computed for this phase-space
            }
            else
            {
                return 1; // No SF computed for this phase-space
            }
        }
    }
    else if (year == 2016 and not isAPV)
    {
        if (pt >= 40 and pt < 45)
        {
            if (fabs(eta) >= 0.0 and fabs(eta) < 0.9)
            {
                return (syst == 0 ? 0.98920017212 : (syst == 1 ? 0.990700960452 : 0.987699383789));
            }
            else if (fabs(eta) >= 0.9 and fabs(eta) < 1.2)
            {
                return (syst == 0 ? 0.989363880677 : (syst == 1 ? 0.992035933146 : 0.986691828209));
            }
            else if (fabs(eta) >= 1.2 and fabs(eta) < 2.1)
            {
                return (syst == 0 ? 0.986392931211 : (syst == 1 ? 0.988149781396 : 0.984636081026));
            }
            else if (fabs(eta) >= 2.1)
            {
                return (syst == 0 ? 0.963808019007 : (syst == 1 ? 0.967613284772 : 0.960002753241));
            }
            else
            {
                return 1; // No SF computed for this phase-space
            }
        }
        else if (pt >= 45 and pt < 55)
        {
            if (fabs(eta) >= 0.0 and fabs(eta) < 0.9)
            {
                return (syst == 0 ? 0.991538093033 : (syst == 1 ? 0.993114972765 : 0.989961213301));
            }
            else if (fabs(eta) >= 0.9 and fabs(eta) < 1.2)
            {
                return (syst == 0 ? 0.991291906411 : (syst == 1 ? 0.994070734496 : 0.988513078326));
            }
            else if (fabs(eta) >= 1.2 and fabs(eta) < 2.1)
            {
                return (syst == 0 ? 0.989410522213 : (syst == 1 ? 0.991191388459 : 0.987629655966));
            }
            else if (fabs(eta) >= 2.1)
            {
                return (syst == 0 ? 0.967616210835 : (syst == 1 ? 0.971539470665 : 0.963692951004));
            }
            else
            {
                return 1; // No SF computed for this phase-space
            }
        }
        else if (pt >= 55 and pt < 80)
        {
            if (fabs(eta) >= 0.0 and fabs(eta) < 0.9)
            {
                return (syst == 0 ? 0.989610987979 : (syst == 1 ? 0.992272461722 : 0.986949514236));
            }
            else if (fabs(eta) >= 0.9 and fabs(eta) < 1.2)
            {
                return (syst == 0 ? 0.990293682353 : (syst == 1 ? 0.99501404668 : 0.985573318026));
            }
            else if (fabs(eta) >= 1.2 and fabs(eta) < 2.1)
            {
                return (syst == 0 ? 0.988506963194 : (syst == 1 ? 0.991558808004 : 0.985455118384));
            }
            else if (fabs(eta) >= 2.1)
            {
                return (syst == 0 ? 0.962031757921 : (syst == 1 ? 0.968746183236 : 0.955317332605));
            }
            else
            {
                return 1; // No SF computed for this phase-space
            }
        }
        else if (pt >= 80)
        {
            if (fabs(eta) >= 0.0 and fabs(eta) < 0.9)
            {
                return (syst == 0 ? 0.987777153212 : (syst == 1 ? 0.993574562498 : 0.981979743927));
            }
            else if (fabs(eta) >= 0.9 and fabs(eta) < 1.2)
            {
                return (syst == 0 ? 0.986058947156 : (syst == 1 ? 0.996428375963 : 0.975689518349));
            }
            else if (fabs(eta) >= 1.2 and fabs(eta) < 2.1)
            {
                return (syst == 0 ? 0.988517567152 : (syst == 1 ? 0.995493890785 : 0.98154124352));
            }
            else if (fabs(eta) >= 2.1)
            {
                return (syst == 0 ? 0.963334159813 : (syst == 1 ? 0.979464479111 : 0.947203840515));
            }
            else
            {
                return 1; // No SF computed for this phase-space
            }
        }
        else
        {
            if (fabs(eta) >= 0.0 and fabs(eta) < 0.9)
            {
                return 1; // No SF computed for this phase-space
            }
            else if (fabs(eta) >= 0.9 and fabs(eta) < 1.2)
            {
                return 1; // No SF computed for this phase-space
            }
            else if (fabs(eta) >= 1.2 and fabs(eta) < 2.1)
            {
                return 1; // No SF computed for this phase-space
            }
            else if (fabs(eta) >= 2.1)
            {
                return 1; // No SF computed for this phase-space
            }
            else
            {
                return 1; // No SF computed for this phase-space
            }
        }
    }
    else if (year == 2017)
    {
        if (pt >= 40 and pt < 45)
        {
            if (fabs(eta) >= 0.0 and fabs(eta) < 0.9)
            {
                return (syst == 0 ? 0.986489668309 : (syst == 1 ? 0.987542827935 : 0.985436508683));
            }
            else if (fabs(eta) >= 0.9 and fabs(eta) < 1.2)
            {
                return (syst == 0 ? 0.986734398946 : (syst == 1 ? 0.988616611466 : 0.984852186425));
            }
            else if (fabs(eta) >= 1.2 and fabs(eta) < 2.1)
            {
                return (syst == 0 ? 0.988300184197 : (syst == 1 ? 0.989547453717 : 0.987052914677));
            }
            else if (fabs(eta) >= 2.1)
            {
                return (syst == 0 ? 0.98970749149 : (syst == 1 ? 0.992479862743 : 0.986935120236));
            }
            else
            {
                return 1; // No SF computed for this phase-space
            }
        }
        else if (pt >= 45 and pt < 55)
        {
            if (fabs(eta) >= 0.0 and fabs(eta) < 0.9)
            {
                return (syst == 0 ? 0.988765272254 : (syst == 1 ? 0.98991020867 : 0.987620335838));
            }
            else if (fabs(eta) >= 0.9 and fabs(eta) < 1.2)
            {
                return (syst == 0 ? 0.98944824852 : (syst == 1 ? 0.991475131899 : 0.987421365141));
            }
            else if (fabs(eta) >= 1.2 and fabs(eta) < 2.1)
            {
                return (syst == 0 ? 0.990559333361 : (syst == 1 ? 0.991864116993 : 0.98925454973));
            }
            else if (fabs(eta) >= 2.1)
            {
                return (syst == 0 ? 0.992210102521 : (syst == 1 ? 0.995156056895 : 0.989264148148));
            }
            else
            {
                return 1; // No SF computed for this phase-space
            }
        }
        else if (pt >= 55 and pt < 80)
        {
            if (fabs(eta) >= 0.0 and fabs(eta) < 0.9)
            {
                return (syst == 0 ? 0.989112171824 : (syst == 1 ? 0.991390836406 : 0.986833507243));
            }
            else if (fabs(eta) >= 0.9 and fabs(eta) < 1.2)
            {
                return (syst == 0 ? 0.990048418292 : (syst == 1 ? 0.994122033117 : 0.985974803468));
            }
            else if (fabs(eta) >= 1.2 and fabs(eta) < 2.1)
            {
                return (syst == 0 ? 0.991261485341 : (syst == 1 ? 0.993914441869 : 0.988608528812));
            }
            else if (fabs(eta) >= 2.1)
            {
                return (syst == 0 ? 0.995134128122 : (syst == 1 ? 1.00115752154 : 0.989110734705));
            }
            else
            {
                return 1; // No SF computed for this phase-space
            }
        }
        else if (pt >= 80)
        {
            if (fabs(eta) >= 0.0 and fabs(eta) < 0.9)
            {
                return (syst == 0 ? 0.987360985344 : (syst == 1 ? 0.992824319851 : 0.981897650836));
            }
            else if (fabs(eta) >= 0.9 and fabs(eta) < 1.2)
            {
                return (syst == 0 ? 0.988804478571 : (syst == 1 ? 0.998707902462 : 0.97890105468));
            }
            else if (fabs(eta) >= 1.2 and fabs(eta) < 2.1)
            {
                return (syst == 0 ? 0.991298092962 : (syst == 1 ? 0.998060297634 : 0.98453588829));
            }
            else if (fabs(eta) >= 2.1)
            {
                return (syst == 0 ? 0.995499542171 : (syst == 1 ? 1.0118627086 : 0.979136375745));
            }
            else
            {
                return 1; // No SF computed for this phase-space
            }
        }
        else
        {
            if (fabs(eta) >= 0.0 and fabs(eta) < 0.9)
            {
                return 1; // No SF computed for this phase-space
            }
            else if (fabs(eta) >= 0.9 and fabs(eta) < 1.2)
            {
                return 1; // No SF computed for this phase-space
            }
            else if (fabs(eta) >= 1.2 and fabs(eta) < 2.1)
            {
                return 1; // No SF computed for this phase-space
            }
            else if (fabs(eta) >= 2.1)
            {
                return 1; // No SF computed for this phase-space
            }
            else
            {
                return 1; // No SF computed for this phase-space
            }
        }
    }
    else // if (year == 2018)
    {
        if (pt >= 40 and pt < 45)
        {
            if (fabs(eta) >= 0.0 and fabs(eta) < 0.9)
            {
                return (syst == 0 ? 0.988305988079 : (syst == 1 ? 0.989315459067 : 0.987296517091));
            }
            else if (fabs(eta) >= 0.9 and fabs(eta) < 1.2)
            {
                return (syst == 0 ? 0.985663483177 : (syst == 1 ? 0.987456653341 : 0.983870313014));
            }
            else if (fabs(eta) >= 1.2 and fabs(eta) < 2.1)
            {
                return (syst == 0 ? 0.982505776519 : (syst == 1 ? 0.983685602553 : 0.981325950486));
            }
            else if (fabs(eta) >= 2.1)
            {
                return (syst == 0 ? 0.965530232791 : (syst == 1 ? 0.968085536718 : 0.962974928865));
            }
            else
            {
                return 1; // No SF computed for this phase-space
            }
        }
        else if (pt >= 45 and pt < 55)
        {
            if (fabs(eta) >= 0.0 and fabs(eta) < 0.9)
            {
                return (syst == 0 ? 0.990344749278 : (syst == 1 ? 0.991444467841 : 0.989245030715));
            }
            else if (fabs(eta) >= 0.9 and fabs(eta) < 1.2)
            {
                return (syst == 0 ? 0.988443800122 : (syst == 1 ? 0.990381343624 : 0.986506256619));
            }
            else if (fabs(eta) >= 1.2 and fabs(eta) < 2.1)
            {
                return (syst == 0 ? 0.986097381958 : (syst == 1 ? 0.987334317752 : 0.984860446165));
            }
            else if (fabs(eta) >= 2.1)
            {
                return (syst == 0 ? 0.971310322818 : (syst == 1 ? 0.974041541702 : 0.968579103934));
            }
            else
            {
                return 1; // No SF computed for this phase-space
            }
        }
        else if (pt >= 55 and pt < 80)
        {
            if (fabs(eta) >= 0.0 and fabs(eta) < 0.9)
            {
                return (syst == 0 ? 0.989973800735 : (syst == 1 ? 0.992166414253 : 0.987781187217));
            }
            else if (fabs(eta) >= 0.9 and fabs(eta) < 1.2)
            {
                return (syst == 0 ? 0.988365566352 : (syst == 1 ? 0.992269979464 : 0.98446115324));
            }
            else if (fabs(eta) >= 1.2 and fabs(eta) < 2.1)
            {
                return (syst == 0 ? 0.987085267642 : (syst == 1 ? 0.989606590719 : 0.984563944565));
            }
            else if (fabs(eta) >= 2.1)
            {
                return (syst == 0 ? 0.974480634737 : (syst == 1 ? 0.980115514469 : 0.968845755005));
            }
            else
            {
                return 1; // No SF computed for this phase-space
            }
        }
        else if (pt >= 80)
        {
            if (fabs(eta) >= 0.0 and fabs(eta) < 0.9)
            {
                return (syst == 0 ? 0.988363703303 : (syst == 1 ? 0.993648810335 : 0.983078596271));
            }
            else if (fabs(eta) >= 0.9 and fabs(eta) < 1.2)
            {
                return (syst == 0 ? 0.987602731635 : (syst == 1 ? 0.997114140114 : 0.978091323156));
            }
            else if (fabs(eta) >= 1.2 and fabs(eta) < 2.1)
            {
                return (syst == 0 ? 0.987736926723 : (syst == 1 ? 0.994173961389 : 0.981299892057));
            }
            else if (fabs(eta) >= 2.1)
            {
                return (syst == 0 ? 0.964244098842 : (syst == 1 ? 0.979057324282 : 0.949430873401));
            }
            else
            {
                return 1; // No SF computed for this phase-space
            }
        }
        else
        {
            if (fabs(eta) >= 0.0 and fabs(eta) < 0.9)
            {
                return 1; // No SF computed for this phase-space
            }
            else if (fabs(eta) >= 0.9 and fabs(eta) < 1.2)
            {
                return 1; // No SF computed for this phase-space
            }
            else if (fabs(eta) >= 1.2 and fabs(eta) < 2.1)
            {
                return 1; // No SF computed for this phase-space
            }
            else if (fabs(eta) >= 2.1)
            {
                return 1; // No SF computed for this phase-space
            }
            else
            {
                return 1; // No SF computed for this phase-space
            }
        }
    }
}

float ttH::getElecTightSFRederived(float eta, float pt, int year, bool isAPV, int syst)
{
    if (year == 2016 and isAPV)
    {
        if (pt >= 40 and pt < 45)
        {
            if (fabs(eta) >= 0.0 and fabs(eta) < 0.9)
            {
                return (syst == 0 ? 1.04528748695 : (syst == 1 ? 1.04754080963 : 1.04303416427));
            }
            else if (fabs(eta) >= 0.9 and fabs(eta) < 1.2)
            {
                return (syst == 0 ? 1.02855519243 : (syst == 1 ? 1.03256472613 : 1.02454565872));
            }
            else if (fabs(eta) >= 1.2 and fabs(eta) < 2.1)
            {
                return (syst == 0 ? 0.985019444983 : (syst == 1 ? 0.987753890182 : 0.982284999783));
            }
            else if (fabs(eta) >= 2.1)
            {
                return (syst == 0 ? 1.04869496629 : (syst == 1 ? 1.05521172041 : 1.04217821217));
            }
            else
            {
                return 1; // No SF computed for this phase-space
            }
        }
        else if (pt >= 45 and pt < 55)
        {
            if (fabs(eta) >= 0.0 and fabs(eta) < 0.9)
            {
                return (syst == 0 ? 1.03731843347 : (syst == 1 ? 1.03983146877 : 1.03480539817));
            }
            else if (fabs(eta) >= 0.9 and fabs(eta) < 1.2)
            {
                return (syst == 0 ? 1.02383787322 : (syst == 1 ? 1.02845940113 : 1.01921634532));
            }
            else if (fabs(eta) >= 1.2 and fabs(eta) < 2.1)
            {
                return (syst == 0 ? 0.996056860735 : (syst == 1 ? 0.999213134819 : 0.992900586652));
            }
            else if (fabs(eta) >= 2.1)
            {
                return (syst == 0 ? 1.05106191199 : (syst == 1 ? 1.05811093629 : 1.04401288769));
            }
            else
            {
                return 1; // No SF computed for this phase-space
            }
        }
        else if (pt >= 55 and pt < 80)
        {
            if (fabs(eta) >= 0.0 and fabs(eta) < 0.9)
            {
                return (syst == 0 ? 1.00546396237 : (syst == 1 ? 1.01163724618 : 0.999290678556));
            }
            else if (fabs(eta) >= 0.9 and fabs(eta) < 1.2)
            {
                return (syst == 0 ? 1.00379542021 : (syst == 1 ? 1.01533715958 : 0.992253680829));
            }
            else if (fabs(eta) >= 1.2 and fabs(eta) < 2.1)
            {
                return (syst == 0 ? 0.975404132043 : (syst == 1 ? 0.983288353334 : 0.967519910751));
            }
            else if (fabs(eta) >= 2.1)
            {
                return (syst == 0 ? 1.0301602235 : (syst == 1 ? 1.04888736071 : 1.01143308629));
            }
            else
            {
                return 1; // No SF computed for this phase-space
            }
        }
        else if (pt >= 80)
        {
            if (fabs(eta) >= 0.0 and fabs(eta) < 0.9)
            {
                return (syst == 0 ? 0.984894365397 : (syst == 1 ? 0.995171536635 : 0.974617194159));
            }
            else if (fabs(eta) >= 0.9 and fabs(eta) < 1.2)
            {
                return (syst == 0 ? 1.02684477902 : (syst == 1 ? 1.04780107309 : 1.00588848496));
            }
            else if (fabs(eta) >= 1.2 and fabs(eta) < 2.1)
            {
                return (syst == 0 ? 0.987181776544 : (syst == 1 ? 1.00177976665 : 0.972583786439));
            }
            else if (fabs(eta) >= 2.1)
            {
                return (syst == 0 ? 1.06570236893 : (syst == 1 ? 1.10505014121 : 1.02635459664));
            }
            else
            {
                return 1; // No SF computed for this phase-space
            }
        }
        else
        {
            if (fabs(eta) >= 0.0 and fabs(eta) < 0.9)
            {
                return 1; // No SF computed for this phase-space
            }
            else if (fabs(eta) >= 0.9 and fabs(eta) < 1.2)
            {
                return 1; // No SF computed for this phase-space
            }
            else if (fabs(eta) >= 1.2 and fabs(eta) < 2.1)
            {
                return 1; // No SF computed for this phase-space
            }
            else if (fabs(eta) >= 2.1)
            {
                return 1; // No SF computed for this phase-space
            }
            else
            {
                return 1; // No SF computed for this phase-space
            }
        }
    }
    else if (year == 2016 and not isAPV)
    {
        if (pt >= 40 and pt < 45)
        {
            if (fabs(eta) >= 0.0 and fabs(eta) < 0.9)
            {
                return (syst == 0 ? 0.942488793727 : (syst == 1 ? 0.944825860347 : 0.940151727107));
            }
            else if (fabs(eta) >= 0.9 and fabs(eta) < 1.2)
            {
                return (syst == 0 ? 0.936340174699 : (syst == 1 ? 0.940562208355 : 0.932118141043));
            }
            else if (fabs(eta) >= 1.2 and fabs(eta) < 2.1)
            {
                return (syst == 0 ? 0.913394312254 : (syst == 1 ? 0.916356859999 : 0.91043176451));
            }
            else if (fabs(eta) >= 2.1)
            {
                return (syst == 0 ? 0.941433695496 : (syst == 1 ? 0.948342350399 : 0.934525040593));
            }
            else
            {
                return 1; // No SF computed for this phase-space
            }
        }
        else if (pt >= 45 and pt < 55)
        {
            if (fabs(eta) >= 0.0 and fabs(eta) < 0.9)
            {
                return (syst == 0 ? 0.942585549955 : (syst == 1 ? 0.9451506335 : 0.94002046641));
            }
            else if (fabs(eta) >= 0.9 and fabs(eta) < 1.2)
            {
                return (syst == 0 ? 0.934141107726 : (syst == 1 ? 0.938854745348 : 0.929427470105));
            }
            else if (fabs(eta) >= 1.2 and fabs(eta) < 2.1)
            {
                return (syst == 0 ? 0.927701494764 : (syst == 1 ? 0.930978151215 : 0.924424838313));
            }
            else if (fabs(eta) >= 2.1)
            {
                return (syst == 0 ? 0.966021211569 : (syst == 1 ? 0.973503498126 : 0.958538925011));
            }
            else
            {
                return 1; // No SF computed for this phase-space
            }
        }
        else if (pt >= 55 and pt < 80)
        {
            if (fabs(eta) >= 0.0 and fabs(eta) < 0.9)
            {
                return (syst == 0 ? 0.933608603248 : (syst == 1 ? 0.939038850587 : 0.928178355909));
            }
            else if (fabs(eta) >= 0.9 and fabs(eta) < 1.2)
            {
                return (syst == 0 ? 0.930708057978 : (syst == 1 ? 0.940829527313 : 0.920586588642));
            }
            else if (fabs(eta) >= 1.2 and fabs(eta) < 2.1)
            {
                return (syst == 0 ? 0.909434869504 : (syst == 1 ? 0.916367343737 : 0.902502395271));
            }
            else if (fabs(eta) >= 2.1)
            {
                return (syst == 0 ? 0.960835747417 : (syst == 1 ? 0.97769742421 : 0.943974070625));
            }
            else
            {
                return 1; // No SF computed for this phase-space
            }
        }
        else if (pt >= 80)
        {
            if (fabs(eta) >= 0.0 and fabs(eta) < 0.9)
            {
                return (syst == 0 ? 0.944713364706 : (syst == 1 ? 0.953476836185 : 0.935949893228));
            }
            else if (fabs(eta) >= 0.9 and fabs(eta) < 1.2)
            {
                return (syst == 0 ? 0.950127720884 : (syst == 1 ? 0.967332808909 : 0.932922632859));
            }
            else if (fabs(eta) >= 1.2 and fabs(eta) < 2.1)
            {
                return (syst == 0 ? 0.931573412106 : (syst == 1 ? 0.943719751712 : 0.919427072499));
            }
            else if (fabs(eta) >= 2.1)
            {
                return (syst == 0 ? 0.954565036057 : (syst == 1 ? 0.985252467306 : 0.923877604807));
            }
            else
            {
                return 1; // No SF computed for this phase-space
            }
        }
        else
        {
            if (fabs(eta) >= 0.0 and fabs(eta) < 0.9)
            {
                return 1; // No SF computed for this phase-space
            }
            else if (fabs(eta) >= 0.9 and fabs(eta) < 1.2)
            {
                return 1; // No SF computed for this phase-space
            }
            else if (fabs(eta) >= 1.2 and fabs(eta) < 2.1)
            {
                return 1; // No SF computed for this phase-space
            }
            else if (fabs(eta) >= 2.1)
            {
                return 1; // No SF computed for this phase-space
            }
            else
            {
                return 1; // No SF computed for this phase-space
            }
        }
    }
    else if (year == 2017)
    {
        if (pt >= 40 and pt < 45)
        {
            if (fabs(eta) >= 0.0 and fabs(eta) < 0.9)
            {
                return (syst == 0 ? 0.878787818916 : (syst == 1 ? 0.880262232841 : 0.87731340499));
            }
            else if (fabs(eta) >= 0.9 and fabs(eta) < 1.2)
            {
                return (syst == 0 ? 0.898815332354 : (syst == 1 ? 0.901540930082 : 0.896089734627));
            }
            else if (fabs(eta) >= 1.2 and fabs(eta) < 2.1)
            {
                return (syst == 0 ? 0.841895516725 : (syst == 1 ? 0.843701951183 : 0.840089082267));
            }
            else if (fabs(eta) >= 2.1)
            {
                return (syst == 0 ? 0.870877223834 : (syst == 1 ? 0.874967998111 : 0.866786449557));
            }
            else
            {
                return 1; // No SF computed for this phase-space
            }
        }
        else if (pt >= 45 and pt < 55)
        {
            if (fabs(eta) >= 0.0 and fabs(eta) < 0.9)
            {
                return (syst == 0 ? 0.882212863137 : (syst == 1 ? 0.883896087704 : 0.88052963857));
            }
            else if (fabs(eta) >= 0.9 and fabs(eta) < 1.2)
            {
                return (syst == 0 ? 0.899896499124 : (syst == 1 ? 0.903058903133 : 0.896734095115));
            }
            else if (fabs(eta) >= 1.2 and fabs(eta) < 2.1)
            {
                return (syst == 0 ? 0.851364386239 : (syst == 1 ? 0.853424200648 : 0.849304571829));
            }
            else if (fabs(eta) >= 2.1)
            {
                return (syst == 0 ? 0.879739961113 : (syst == 1 ? 0.884157186252 : 0.875322735975));
            }
            else
            {
                return 1; // No SF computed for this phase-space
            }
        }
        else if (pt >= 55 and pt < 80)
        {
            if (fabs(eta) >= 0.0 and fabs(eta) < 0.9)
            {
                return (syst == 0 ? 0.886375626673 : (syst == 1 ? 0.890792800638 : 0.881958452708));
            }
            else if (fabs(eta) >= 0.9 and fabs(eta) < 1.2)
            {
                return (syst == 0 ? 0.887414109229 : (syst == 1 ? 0.895605542592 : 0.879222675865));
            }
            else if (fabs(eta) >= 1.2 and fabs(eta) < 2.1)
            {
                return (syst == 0 ? 0.84915749387 : (syst == 1 ? 0.854533698667 : 0.843781289074));
            }
            else if (fabs(eta) >= 2.1)
            {
                return (syst == 0 ? 0.874165107963 : (syst == 1 ? 0.886169860259 : 0.862160355667));
            }
            else
            {
                return 1; // No SF computed for this phase-space
            }
        }
        else if (pt >= 80)
        {
            if (fabs(eta) >= 0.0 and fabs(eta) < 0.9)
            {
                return (syst == 0 ? 0.90983741606 : (syst == 1 ? 0.917656381485 : 0.902018450636));
            }
            else if (fabs(eta) >= 0.9 and fabs(eta) < 1.2)
            {
                return (syst == 0 ? 0.898401005881 : (syst == 1 ? 0.913513628872 : 0.88328838289));
            }
            else if (fabs(eta) >= 1.2 and fabs(eta) < 2.1)
            {
                return (syst == 0 ? 0.866260727637 : (syst == 1 ? 0.876550935793 : 0.855970519482));
            }
            else if (fabs(eta) >= 2.1)
            {
                return (syst == 0 ? 0.906843678487 : (syst == 1 ? 0.932210954641 : 0.881476402333));
            }
            else
            {
                return 1; // No SF computed for this phase-space
            }
        }
        else
        {
            if (fabs(eta) >= 0.0 and fabs(eta) < 0.9)
            {
                return 1; // No SF computed for this phase-space
            }
            else if (fabs(eta) >= 0.9 and fabs(eta) < 1.2)
            {
                return 1; // No SF computed for this phase-space
            }
            else if (fabs(eta) >= 1.2 and fabs(eta) < 2.1)
            {
                return 1; // No SF computed for this phase-space
            }
            else if (fabs(eta) >= 2.1)
            {
                return 1; // No SF computed for this phase-space
            }
            else
            {
                return 1; // No SF computed for this phase-space
            }
        }
    }
    else // if (year == 2018)
    {
        if (pt >= 40 and pt < 45)
        {
            if (fabs(eta) >= 0.0 and fabs(eta) < 0.9)
            {
                return (syst == 0 ? 0.892774496694 : (syst == 1 ? 0.894216648856 : 0.891332344532));
            }
            else if (fabs(eta) >= 0.9 and fabs(eta) < 1.2)
            {
                return (syst == 0 ? 0.898499601967 : (syst == 1 ? 0.901095633007 : 0.895903570928));
            }
            else if (fabs(eta) >= 1.2 and fabs(eta) < 2.1)
            {
                return (syst == 0 ? 0.823930136395 : (syst == 1 ? 0.825575572434 : 0.822284700356));
            }
            else if (fabs(eta) >= 2.1)
            {
                return (syst == 0 ? 0.8228387946 : (syst == 1 ? 0.826390704179 : 0.81928688502));
            }
            else
            {
                return 1; // No SF computed for this phase-space
            }
        }
        else if (pt >= 45 and pt < 55)
        {
            if (fabs(eta) >= 0.0 and fabs(eta) < 0.9)
            {
                return (syst == 0 ? 0.889245540945 : (syst == 1 ? 0.890880662295 : 0.887610419595));
            }
            else if (fabs(eta) >= 0.9 and fabs(eta) < 1.2)
            {
                return (syst == 0 ? 0.895345767541 : (syst == 1 ? 0.898350852023 : 0.892340683058));
            }
            else if (fabs(eta) >= 1.2 and fabs(eta) < 2.1)
            {
                return (syst == 0 ? 0.829590094156 : (syst == 1 ? 0.831450311061 : 0.827729877251));
            }
            else if (fabs(eta) >= 2.1)
            {
                return (syst == 0 ? 0.843534842822 : (syst == 1 ? 0.847375433157 : 0.839694252486));
            }
            else
            {
                return 1; // No SF computed for this phase-space
            }
        }
        else if (pt >= 55 and pt < 80)
        {
            if (fabs(eta) >= 0.0 and fabs(eta) < 0.9)
            {
                return (syst == 0 ? 0.887217547034 : (syst == 1 ? 0.891508606309 : 0.88292648776));
            }
            else if (fabs(eta) >= 0.9 and fabs(eta) < 1.2)
            {
                return (syst == 0 ? 0.883409382635 : (syst == 1 ? 0.891218755001 : 0.875600010268));
            }
            else if (fabs(eta) >= 1.2 and fabs(eta) < 2.1)
            {
                return (syst == 0 ? 0.83186821831 : (syst == 1 ? 0.836797542979 : 0.826938893642));
            }
            else if (fabs(eta) >= 2.1)
            {
                return (syst == 0 ? 0.853359663893 : (syst == 1 ? 0.864096336729 : 0.842622991057));
            }
            else
            {
                return 1; // No SF computed for this phase-space
            }
        }
        else if (pt >= 80)
        {
            if (fabs(eta) >= 0.0 and fabs(eta) < 0.9)
            {
                return (syst == 0 ? 0.898369656488 : (syst == 1 ? 0.905840549274 : 0.890898763702));
            }
            else if (fabs(eta) >= 0.9 and fabs(eta) < 1.2)
            {
                return (syst == 0 ? 0.895171683424 : (syst == 1 ? 0.909631528878 : 0.880711837969));
            }
            else if (fabs(eta) >= 1.2 and fabs(eta) < 2.1)
            {
                return (syst == 0 ? 0.848975421068 : (syst == 1 ? 0.858474195661 : 0.839476646474));
            }
            else if (fabs(eta) >= 2.1)
            {
                return (syst == 0 ? 0.901022016068 : (syst == 1 ? 0.923872879544 : 0.878171152593));
            }
            else
            {
                return 1; // No SF computed for this phase-space
            }
        }
        else
        {
            if (fabs(eta) >= 0.0 and fabs(eta) < 0.9)
            {
                return 1; // No SF computed for this phase-space
            }
            else if (fabs(eta) >= 0.9 and fabs(eta) < 1.2)
            {
                return 1; // No SF computed for this phase-space
            }
            else if (fabs(eta) >= 1.2 and fabs(eta) < 2.1)
            {
                return 1; // No SF computed for this phase-space
            }
            else if (fabs(eta) >= 2.1)
            {
                return 1; // No SF computed for this phase-space
            }
            else
            {
                return 1; // No SF computed for this phase-space
            }
        }
    }
}
