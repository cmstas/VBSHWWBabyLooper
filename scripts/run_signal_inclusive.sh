mkdir -p signal_kinematics/
rm -f .signal_jobs.txt
echo "rm -f signal_kinematics/c2v_0.root; ./studies/genStudy/doAnalysis -o signal_kinematics/c2v_0.root -t Events -i /hadoop/cms/store/user/phchang/VBSHWWSignalGeneration/RunIISummer20UL18_VBSWWH_incl_v2_C2V_0_Azure/merged/ -s 1 > signal_kinematics/c2v_0.log 2>&1" >> .signal_jobs.txt
echo "rm -f signal_kinematics/c2v_1.root; ./studies/genStudy/doAnalysis -o signal_kinematics/c2v_1.root -t Events -i /hadoop/cms/store/user/phchang/VBSHWWSignalGeneration/RunIISummer20UL18_VBSWWH_incl_v2_C2V_1_Azure/merged/ -s 1 > signal_kinematics/c2v_1.log 2>&1" >> .signal_jobs.txt
echo "rm -f signal_kinematics/c2v_3.root; ./studies/genStudy/doAnalysis -o signal_kinematics/c2v_3.root -t Events -i /hadoop/cms/store/user/phchang/VBSHWWSignalGeneration/RunIISummer20UL18_VBSWWH_incl_v2_C2V_3_Azure/merged/ -s 1 > signal_kinematics/c2v_3.log 2>&1" >> .signal_jobs.txt
echo "rm -f signal_kinematics/c2v_4.root; ./studies/genStudy/doAnalysis -o signal_kinematics/c2v_4.root -t Events -i /hadoop/cms/store/user/phchang/VBSHWWSignalGeneration/RunIISummer20UL18_VBSWWH_incl_v2_C2V_4_Azure/merged/ -s 1 > signal_kinematics/c2v_4.log 2>&1" >> .signal_jobs.txt
echo "rm -f signal_kinematics/c2v_4p5.root; ./studies/genStudy/doAnalysis -o signal_kinematics/c2v_4p5.root -t Events -i /hadoop/cms/store/user/phchang/VBSHWWSignalGeneration/RunIISummer20UL18_VBSWWH_incl_v2_C2V_4p5_Azure/merged/ -s 1 > signal_kinematics/c2v_4p5.log 2>&1" >> .signal_jobs.txt
echo "rm -f signal_kinematics/c2v_m1.root; ./studies/genStudy/doAnalysis -o signal_kinematics/c2v_m1.root -t Events -i /hadoop/cms/store/user/phchang/VBSHWWSignalGeneration/RunIISummer20UL18_VBSWWH_incl_v2_C2V_m1_Azure/merged/ -s 1 > signal_kinematics/c2v_m1.log 2>&1" >> .signal_jobs.txt
echo "rm -f signal_kinematics/c2v_m2.root; ./studies/genStudy/doAnalysis -o signal_kinematics/c2v_m2.root -t Events -i /hadoop/cms/store/user/phchang/VBSHWWSignalGeneration/RunIISummer20UL18_VBSWWH_incl_v2_C2V_m2_Azure/merged/ -s 1 > signal_kinematics/c2v_m2.log 2>&1" >> .signal_jobs.txt
echo "rm -f signal_kinematics/c2v_m2p5.root; ./studies/genStudy/doAnalysis -o signal_kinematics/c2v_m2p5.root -t Events -i /hadoop/cms/store/user/phchang/VBSHWWSignalGeneration/RunIISummer20UL18_VBSWWH_incl_v2_C2V_m2p5_Azure/merged/ -s 1 > signal_kinematics/c2v_m2p5.log 2>&1" >> .signal_jobs.txt
xargs.sh .signal_jobs.txt
