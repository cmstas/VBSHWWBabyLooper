RUNTAG=Nominal
SKIMVERSION=v2.6_SS
BABYVERSION=v10
USERNAME=phchang
YEAR=Run2
# sh scripts/run.sh ${RUNTAG} ${SKIMVERSION} ${BABYVERSION} ${YEAR} ${USERNAME}
# rm -rf /nfs-7/userdata/${USERNAME}/VBSHWWResult/${SKIMVERSION}/${BABYVERSION}/${YEAR}/${RUNTAG}
# sh scripts/publish_result.sh ${RUNTAG} ${SKIMVERSION} ${BABYVERSION} ${YEAR}
python scripts/alpha_exp_study.py ${RUNTAG} ${SKIMVERSION} ${BABYVERSION} ${YEAR} ${USERNAME}
sh scripts/make_figures.sh ${RUNTAG} ${SKIMVERSION} ${BABYVERSION} ${YEAR} ${USERNAME}
ln -fs /nfs-7/userdata/${USERNAME}/VBSHWWResult/${SKIMVERSION}/${BABYVERSION}/${YEAR}/${RUNTAG}/plots plots
ln -fs /nfs-7/userdata/${USERNAME}/VBSHWWResult/${SKIMVERSION}/${BABYVERSION}/${YEAR}/${RUNTAG}/topbkgstudy topbkgstudy
