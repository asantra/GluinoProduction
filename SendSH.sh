#! /bin/bash


sftp asantra@lxplus6.cern.ch << EOF
put MadGraphControl_SimplifiedModel_C1N2N1_GGMHino_Filter.py /afs/cern.ch/user/a/asantra/public/2LProduction/MC15JobOptions/common/MadGraph
put MadGraphControl_SimplifiedModelPostInclude.py /afs/cern.ch/user/a/asantra/public/2LProduction/MC15JobOptions/common/MadGraph
put param_card.SM.C1N2N1.GGMHinoZh50.dat /afs/cern.ch/user/a/asantra/public/2LProduction/MC15JobOptions/susycontrol
put param_card.SM.C1N2N1.GGMHinoZh50.dat /afs/cern.ch/user/a/asantra/public/2LProduction/MC15JobOptions/Run
put makePlots.C /afs/cern.ch/user/a/asantra/public/2LProduction/MC15JobOptions/Run
put logParser.py /afs/cern.ch/user/a/asantra/public/2LProduction/MC15JobOptions
put JobOptions/MC15.395398.MGPy8EG_A14N23LO_C1N2N1_GGMHinoZh50_150_2LT4.py /afs/cern.ch/user/a/asantra/public/2LProduction/MC15JobOptions/share/DSID395xxx
put JobOptions/MC15.395399.MGPy8EG_A14N23LO_C1N2N1_GGMHinoZh50_300_2LT4.py /afs/cern.ch/user/a/asantra/public/2LProduction/MC15JobOptions/share/DSID395xxx
put JobOptions/MC15.395400.MGPy8EG_A14N23LO_C1N2N1_GGMHinoZh50_600_2LT4.py /afs/cern.ch/user/a/asantra/public/2LProduction/MC15JobOptions/share/DSID395xxx
put JobOptions/MC15.395401.MGPy8EG_A14N23LO_C1N2N1_GGMHinoZh50_900_2LT4.py /afs/cern.ch/user/a/asantra/public/2LProduction/MC15JobOptions/share/DSID395xxx
EOF