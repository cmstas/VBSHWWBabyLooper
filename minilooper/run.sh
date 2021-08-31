RUNTAG=Final
SKIMVERSION=v2.6_SS
USERNAME=jguiang
YEAR=Run2

BABYVERSIONS="v2_jecUp
v2_jecDn
v2"

for BABYVERSION in ${BABYVERSIONS}; do
    # Run minilooper
    sh scripts/run.sh ${RUNTAG} ${SKIMVERSION} ${BABYVERSION} ${YEAR} ${USERNAME}
    rm -rf /nfs-7/userdata/${USERNAME}/VBSHWWResult/${SKIMVERSION}/${BABYVERSION}/${YEAR}/${RUNTAG}
    sh scripts/publish_result.sh ${RUNTAG} ${SKIMVERSION} ${BABYVERSION} ${YEAR}
    if [[ "$BABYVERSION" == "v2" ]]; then
        # Run everything else
        python scripts/alpha_exp_study.py ${RUNTAG} ${SKIMVERSION} ${BABYVERSION} ${YEAR} ${USERNAME}
        sh scripts/make_figures.sh ${RUNTAG} ${SKIMVERSION} ${BABYVERSION} ${YEAR} ${USERNAME}
        ln -fs /nfs-7/userdata/${USERNAME}/VBSHWWResult/${SKIMVERSION}/${BABYVERSION}/${YEAR}/${RUNTAG}/plots plots
        ln -fs /nfs-7/userdata/${USERNAME}/VBSHWWResult/${SKIMVERSION}/${BABYVERSION}/${YEAR}/${RUNTAG}/topbkgstudy topbkgstudy
    fi
done

