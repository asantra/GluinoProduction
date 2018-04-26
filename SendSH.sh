#! /bin/bash

previousArea='/afs/cern.ch/user/a/asantra/public/2LProduction'
newArea='/afs/cern.ch/work/a/asantra/public/Generate2LJets'
areaToSend=$previousArea
sftp asantra@lxplus6.cern.ch << EOF
put MadGraphControl_SimplifiedModel_C1N2N1_GGMHino_Filter.py $areaToSend/MC15JobOptions/common/MadGraph
put MadGraphControl_SimplifiedModelPostInclude.py $areaToSend/MC15JobOptions/common/MadGraph
put param_card.SM.C1N2N1.GGMHinoZh50.dat $areaToSend/MC15JobOptions/susycontrol
put param_card.SM.C1N2N1.GGMHinoZh50.dat $areaToSend/MC15JobOptions/Run
#put makePlots.C $areaToSend/MC15JobOptions/Run
put logParser.py $areaToSend/MC15JobOptions
put JobOptions/MC15.395398.MGPy8EG_A14N23LO_C1N2N1_GGMHinoZh50_150_2L3.py $areaToSend/MC15JobOptions/share/DSID395xxx
put JobOptions/MC15.395399.MGPy8EG_A14N23LO_C1N2N1_GGMHinoZh50_300_2L3.py $areaToSend/MC15JobOptions/share/DSID395xxx
put JobOptions/MC15.395400.MGPy8EG_A14N23LO_C1N2N1_GGMHinoZh50_600_2L3.py $areaToSend/MC15JobOptions/share/DSID395xxx
put JobOptions/MC15.395401.MGPy8EG_A14N23LO_C1N2N1_GGMHinoZh50_900_2L3.py $areaToSend/MC15JobOptions/share/DSID395xxx
EOF