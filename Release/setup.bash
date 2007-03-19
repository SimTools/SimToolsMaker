##
##  Setup environments to run root/jsf/Geant4
##  Environment parameter for LC studies
##
#######################################################
##
##  Setup for JLCLOGIN2
##
#######################################################
#export LC_RELEASE=1.35
export LC_RELEASE_DIR=/home/miyamoto/distri/simtools-1.04
export ROOTSYS=/home/miyamoto/distri/ext/root/5.15.02
export G4INSTALL=/home/miyamoto/distri/ext/g4/geant4.8.2.p01
export LCIO=/home/miyamoto/distri/ext/v01-07
export JDK_HOME=/usr/java/j2sdk1.4.2_12
# export CERN_ROOT=/proj/soft/ext/cernlib/2005

export CLHEP_BASE_DIR=/home/miyamoto/distri/ext/clhep/2.0.3.1
export CLHEP_INCLUDE_DIR=$CLHEP_BASE_DIR/include

export LCBASEDIR=$LC_RELEASE_DIR/lcbase
export LEDAROOT=$LC_RELEASE_DIR/Leda
export LCLIBROOT=$LC_RELEASE_DIR/lclib
export JSFROOT=$LC_RELEASE_DIR/jsf
export KFLIBROOT=$LC_RELEASE_DIR/physsim

export JUPITERROOT=$LC_RELEASE_DIR/Jupiter
export SATELLITESROOT=$LC_RELEASE_DIR/Satellites
export URANUSROOT=$LC_RELEASE_DIR/Uranus
export SOSYMLINK=true


##### Geatn4 setup ##############
export G4SYSTEM=Linux-g++
export G4USE_STL=1
export G4DATA=$G4INSTALL/data
export G4LEVELGAMMADATA=$G4DATA/PhotonEvaporation2.0
# export G4ELASTICDATA=$G4DATA/G4ELASTIC1.1
export G4RADIOACTIVEDATA=$G4DATA/RadiativeDecay3.1
export G4LEDATA=$G4DATA/G4EMLOW4.2
export NeutronHPCrossSections=$G4DATA/G4NDL3.10

export G4DEBUG=1
export G4OPTIMIZE=0

# #========== 2. UI

## ---------- 2-1. Selection of (G)UI in installation of libraries
export G4UI_BUILD_TERMINAL_SESSION=1
export G4UI_BUILD_GAG_SESSION=1
## ---------- 2-2. Selection of (G)UI in compiling executables
export G4UI_USE_TERMINAL=1
export G4UI_USE_GAG=1

## ========== 3. Visualization
export G4VRMLFILE_VIEWER=vrwave
## ---------- 3-1. Home directory of Mesa
export OGLHOME=/usr/X11R6
## ---------- 3-2. Selection of visualization drivers
export G4VIS_BUILD_DAWNFILE_DRIVER=1
export G4VIS_BUILD_OPENGLX_DRIVER=1
export G4VIS_BUILD_VRMLFILE_DRIVER=1
## ---------- 3-3. Selection of visualization drivers
export G4VIS_USE_DAWNFILE=1
export G4VIS_USE_OPENGLX=1
export G4VIS_USE_VRMLFILE=1
## ========== Selection of viewer

export G4WORKDIR=$G4INSTALL
export G4INCLUDE=$G4INSTALL/include

######### end of Geant4 setup ##################################

## Set command path
LCPATH=$LCBASEDIR/bin:$JSFROOT/bin:$ROOTSYS/bin:$CERN_ROOT/bin:$LCLIBROOT/bin:$JLCSIMROOT/bin:$CLHEP_BASE_DIR/bin
J4PATH=$JUPITERROOT/bin/$G4SYSTEM:$G4INSTALL/bin/$G4SYSTEM
LCIOPATH=$LCIO/tools:$LCIO/bin:$JDK_HOME/bin
export PATH=.:~/bin:$LCPATH:$J4PATH:$LCIOPATH:$PATH
unset LCPATH
unset J4PATH
unset LCIOPATH

## Set LD Library Path
export LD_LIBRARY_PATH=$JSFROOT/lib:$ROOTSYS/lib:$LEDAROOT/lib:$CLHEP_BASE_DIR/lib
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$JUPITERROOT/lib/$G4SYSTEM:$G4INSTALL/lib/$G4SYSTEM:$SATELLITESROOT/lib:$URANUSROOT/lib
export IMAKEINCLUDE="-I$LCBASEDIR -I$KFLIBROOT -I$LCLIBROOT"


