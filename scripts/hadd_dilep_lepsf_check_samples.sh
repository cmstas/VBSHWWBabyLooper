#!/bin/bash

DIR=dilep_v1
DIR=dilep_v2

hadd -f ${DIR}/data_ee_2016APV.root ${DIR}/data_ee_2016APV_*.root
hadd -f ${DIR}/data_ee_2016.root ${DIR}/data_ee_2016_*.root
hadd -f ${DIR}/data_ee_2017.root ${DIR}/data_ee_2017_*.root
hadd -f ${DIR}/data_eg_2018.root ${DIR}/data_eg_2018_*.root
hadd -f ${DIR}/data_ee_Run2.root ${DIR}/data_ee_2016APV.root ${DIR}/data_ee_2016.root ${DIR}/data_ee_2017.root ${DIR}/data_eg_2018.root

hadd -f ${DIR}/data_em_2016APV.root ${DIR}/data_em_2016APV_*.root
hadd -f ${DIR}/data_em_2016.root ${DIR}/data_em_2016_*.root
hadd -f ${DIR}/data_em_2017.root ${DIR}/data_em_2017_*.root
hadd -f ${DIR}/data_em_2018.root ${DIR}/data_em_2018_*.root
hadd -f ${DIR}/data_em_Run2.root ${DIR}/data_em_2016APV.root ${DIR}/data_em_2016.root ${DIR}/data_em_2017.root ${DIR}/data_em_2018.root

hadd -f ${DIR}/data_mm_2016APV.root ${DIR}/data_mm_2016APV_*.root
hadd -f ${DIR}/data_mm_2016.root ${DIR}/data_mm_2016_*.root
hadd -f ${DIR}/data_mm_2017.root ${DIR}/data_mm_2017_*.root
hadd -f ${DIR}/data_mm_2018.root ${DIR}/data_mm_2018_*.root
hadd -f ${DIR}/data_mm_Run2.root ${DIR}/data_mm_2016APV.root ${DIR}/data_mm_2016.root ${DIR}/data_mm_2017.root ${DIR}/data_mm_2018.root

hadd -f ${DIR}/ww_2016APV.root ${DIR}/ww_2016APV_*.root
hadd -f ${DIR}/ww_2016.root ${DIR}/ww_2016_*.root
hadd -f ${DIR}/ww_2017.root ${DIR}/ww_2017_*.root
hadd -f ${DIR}/ww_2018.root ${DIR}/ww_2018_*.root
hadd -f ${DIR}/ww_Run2.root ${DIR}/ww_2016APV.root ${DIR}/ww_2016.root ${DIR}/ww_2017.root ${DIR}/ww_2018.root

hadd -f ${DIR}/dy_2016APV.root ${DIR}/dy_2016APV_*.root
hadd -f ${DIR}/dy_2016.root ${DIR}/dy_2016_*.root
hadd -f ${DIR}/dy_2017.root ${DIR}/dy_2017_*.root
hadd -f ${DIR}/dy_2018.root ${DIR}/dy_2018_*.root
hadd -f ${DIR}/dy_Run2.root ${DIR}/dy_2016APV.root ${DIR}/dy_2016.root ${DIR}/dy_2017.root ${DIR}/dy_2018.root

hadd -f ${DIR}/tt2l_2016APV.root ${DIR}/tt2l_2016APV_*.root
hadd -f ${DIR}/tt2l_2016.root ${DIR}/tt2l_2016_*.root
hadd -f ${DIR}/tt2l_2017.root ${DIR}/tt2l_2017_*.root
hadd -f ${DIR}/tt2l_2018.root ${DIR}/tt2l_2018_*.root
hadd -f ${DIR}/tt2l_Run2.root ${DIR}/tt2l_2016APV.root ${DIR}/tt2l_2016.root ${DIR}/tt2l_2017.root ${DIR}/tt2l_2018.root

hadd -f ${DIR}/hww_2016APV.root ${DIR}/hww_2016APV_*.root
hadd -f ${DIR}/hww_2016.root ${DIR}/hww_2016_*.root
hadd -f ${DIR}/hww_2017.root ${DIR}/hww_2017_*.root
hadd -f ${DIR}/hww_2018.root ${DIR}/hww_2018_*.root
hadd -f ${DIR}/hww_Run2.root ${DIR}/hww_2016APV.root ${DIR}/hww_2016.root ${DIR}/hww_2017.root ${DIR}/hww_2018.root






# hadd -f dilep_v1/data_ee_2016.root dilep_v1/data_ee_2016_*.root
# hadd -f dilep_v1/data_em_2016.root dilep_v1/data_em_2016_*.root
# hadd -f dilep_v1/data_mm_2016.root dilep_v1/data_mm_2016_*.root

# hadd -f dilep_v1/data_ee_2016APV.root dilep_v1/data_ee_2016APV_*.root
# hadd -f dilep_v1/data_em_2016APV.root dilep_v1/data_em_2016APV_*.root
# hadd -f dilep_v1/data_mm_2016APV.root dilep_v1/data_mm_2016APV_*.root

# hadd -f dilep_v1/data_ee_2017.root dilep_v1/data_ee_2017_*.root
# hadd -f dilep_v1/data_em_2017.root dilep_v1/data_em_2017_*.root
# hadd -f dilep_v1/data_mm_2017.root dilep_v1/data_mm_2017_*.root

# hadd -f dilep_v1/data_eg_2018.root dilep_v1/data_eg_2018_*.root
# hadd -f dilep_v1/data_em_2018.root dilep_v1/data_em_2018_*.root
# hadd -f dilep_v1/data_mm_2018.root dilep_v1/data_mm_2018_*.root

# hadd -f dilep_v1/data_2017.root dilep_v1/data_ee_2017.root dilep_v1/data_em_2017.root dilep_v1/data_mm_2017.root

# hadd -f dilep_v1/ww_2016APV.root dilep_v1/ww_2016APV_*.root
# hadd -f dilep_v1/ww_2016.root dilep_v1/ww_2016_*.root
# hadd -f dilep_v1/ww_2017.root dilep_v1/ww_2017_*.root
# hadd -f dilep_v1/ww_2018.root dilep_v1/ww_2018_*.root

# hadd -f dilep_v1/dy_2016APV.root dilep_v1/dy_2016APV_*.root
# hadd -f dilep_v1/dy_2016.root dilep_v1/dy_2016_*.root
# hadd -f dilep_v1/dy_2017.root dilep_v1/dy_2017_*.root
# hadd -f dilep_v1/dy_2018.root dilep_v1/dy_2018_*.root

# hadd -f dilep_v1/tt2l_2016APV.root dilep_v1/tt2l_2016APV_*.root
# hadd -f dilep_v1/tt2l_2016.root dilep_v1/tt2l_2016_*.root
# hadd -f dilep_v1/tt2l_2017.root dilep_v1/tt2l_2017_*.root
# hadd -f dilep_v1/tt2l_2018.root dilep_v1/tt2l_2018_*.root

# hadd -f dilep_v1/tt2l_Run2.root dilep_v1/tt2l_2016APV.root dilep_v1/tt2l_2016.root dilep_v1/tt2l_2017.root dilep_v1/tt2l_2018.root
# hadd -f dilep_v1/dy_Run2.root dilep_v1/dy_2016APV.root dilep_v1/dy_2016.root dilep_v1/dy_2017.root dilep_v1/dy_2018.root
# hadd -f dilep_v1/ww_Run2.root dilep_v1/ww_2016APV.root dilep_v1/ww_2016.root dilep_v1/ww_2017.root dilep_v1/ww_2018.root
# hadd -f dilep_v1/data_ee_Run2.root dilep_v1/data_ee_2016APV.root dilep_v1/data_ee_2016.root dilep_v1/data_ee_2017.root dilep_v1/data_eg_2018.root
# hadd -f dilep_v1/data_em_Run2.root dilep_v1/data_em_2016APV.root dilep_v1/data_em_2016.root dilep_v1/data_em_2017.root dilep_v1/data_em_2018.root
# hadd -f dilep_v1/data_mm_Run2.root dilep_v1/data_mm_2016APV.root dilep_v1/data_mm_2016.root dilep_v1/data_mm_2017.root dilep_v1/data_mm_2018.root
# hadd -f dilep_v1/data_Run2.root dilep_v1/data_ee_2016APV.root dilep_v1/data_ee_2016.root dilep_v1/data_ee_2017.root dilep_v1/data_eg_2018.root dilep_v1/data_em_2016APV.root dilep_v1/data_em_2016.root dilep_v1/data_em_2017.root dilep_v1/data_em_2018.root dilep_v1/data_mm_2016APV.root dilep_v1/data_mm_2016.root dilep_v1/data_mm_2017.root dilep_v1/data_mm_2018.root
# hadd -f dilep_v1/data_Run2.root dilep_v1/data_em_2016APV.root dilep_v1/data_em_2016.root dilep_v1/data_em_2017.root dilep_v1/data_em_2018.root
