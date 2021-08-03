# Example from Mario
# https://github.com/hardikroutray/displacedscouting_fitscountlimits/blob/master/cleanscripts/cal_limits_vfinal_hzd_toys.py#L321-L335

ANALYSIS=bdt
BIN=Combined

if [[ "${BIN}" == *"Combined"* ]]; then
    DATACARDS=datacards/${ANALYSIS}_combined.txt
else
    DATACARDS=datacards/${ANALYSIS}/datacard_bin${BIN}.txt
fi

# ACCURACYOPTION="--rAbsAcc=0.01 --rRelAcc=0.03 "
ACCURACYOPTION=""

# MINIMIZEROPTION="--cminDefaultMinimizerStrategy 0" # 0=Hessian, 1=Minos (nothing = Migrad)
MINIMIZEROPTION=""

# combine -M HybridNew --frequentist --testStat LHC --LHCmode LHC-limits --seed -1 -T 200 -v 0 --fork 15 ${MINIMIZEROPTION}  ${DATACARDS} > com_mass{}_ctau{}_obs.out
CMD="combine -M HybridNew --frequentist --testStat LHC --LHCmode LHC-limits --seed -1 -T 200 -v 0 ${ACCURACYOPTION} --fork 15 ${MINIMIZEROPTION} --expectedFromGrid=0.5 ${DATACARDS}"
echo $CMD
# $CMD > ${ANALYSIS}_exp.out

CMD="combine -M HybridNew --frequentist --testStat LHC --LHCmode LHC-limits --seed -1 -T 200 -v 0 ${ACCURACYOPTION} --fork 15 ${MINIMIZEROPTION} --expectedFromGrid=0.84 ${DATACARDS}"
echo $CMD
# $CMD > ${ANALYSIS}_1su.out

CMD="combine -M HybridNew --frequentist --testStat LHC --LHCmode LHC-limits --seed -1 -T 200 -v 0 ${ACCURACYOPTION} --fork 15 ${MINIMIZEROPTION} --expectedFromGrid=0.16 ${DATACARDS}"
echo $CMD
# $CMD > ${ANALYSIS}_1sd.out

CMD="combine -M HybridNew --frequentist --testStat LHC --LHCmode LHC-limits --seed -1 -T 200 -v 0 ${ACCURACYOPTION} --fork 15 ${MINIMIZEROPTION} --expectedFromGrid=0.975 ${DATACARDS}"
echo $CMD
$CMD > ${ANALYSIS}_2su.out

CMD="combine -M HybridNew --frequentist --testStat LHC --LHCmode LHC-limits --seed -1 -T 200 -v 0 ${ACCURACYOPTION} --fork 15 ${MINIMIZEROPTION} --expectedFromGrid=0.025 ${DATACARDS}"
echo $CMD
# $CMD > ${ANALYSIS}_2sd.out
