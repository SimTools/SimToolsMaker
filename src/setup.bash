##
##  Setup environments to run root/jsf/Geant4
##  Environment parameter for LC studies
##
##  30-April-2005 A.Miyamoto Prepared for 1.11 release/SimTools-1.01

#if defined(SIMTOOLS)
#########################################################
## Modify following three lines according to your environment
#########################################################
export SIMTOOLS_DIR=/home/soft/SimTools
export LC_RELEASE_DIR=$SIMTOOLS_DIR/tools
export ROOTSYS=/home/root/root-4.03.04
export G4INSTALL=/home/soft/Geant4/geant4.7.0p1

## ##################################################
## Modify folowing lines if you want to compile package
## Those who use only binaries are not need to set them
## ##################################################
export LCIO=/home/soft/lcio/v01-04
export JDK_HOME=/home/soft/JDK/j2sdk1.4.2_06
export CLHEP_BASE_DIR=$LC_RELEASE_DIR/clhep
export CLHEP_INCLUDE_DIR=$CLHEP_BASE_DIR/include

#elif defined(BUILD)
#########################################################
## Setup to build SimTools binary at jlclogin
#########################################################
export LC_RELEASE=1.16
export SIMTOOLS_DIR=`pwd`/../SimTools
export LC_RELEASE_DIR=$SIMTOOLS_DIR/tools
export ROOTSYS=/proj/soft/Release/$LC_RELEASE/root
export G4INSTALL=/proj/soft/Release/$LC_RELEASE/G4

export LCIO=/proj/soft/Release/$LC_RELEASE/lcio
export JDK_HOME=/proj/soft/Release/$LC_RELEASE/JDK
export CLHEP_BASE_DIR=/proj/soft/Release/$LC_RELEASE/clhep
export CLHEP_INCLUDE_DIR=$CLHEP_BASE_DIR/include

#else
#######################################################
##
##  Setup for JLCLOGIN
##
#######################################################
export LC_RELEASE=1.16
export LC_RELEASE_DIR=/proj/soft/Release/$LC_RELEASE
export ROOTSYS=$LC_RELEASE_DIR/root
export G4INSTALL=$LC_RELEASE_DIR/G4
export LCIO=$LC_RELEASE_DIR/lcio
export JDK_HOME=$LC_RELEASE_DIR/JDK/j2sdk
export CERN_ROOT=/cern/pro

export CLHEP_BASE_DIR=$LC_RELEASE_DIR/clhep
export CLHEP_INCLUDE_DIR=$CLHEP_BASE_DIR/include

#endif

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
export G4DATA=$G4INSTALL/../share/data
export G4LEVELGAMMADATA=$G4DATA/PhotonEvaporation

## ========== 2. UI
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
export GVRMLFILE_VIEWER=vrwave

export G4WORKDIR=$G4INSTALL
export G4INCLUDE=$G4INSTALL/include

######### end of Geant4 setup ##################################

## Set command path
LCPATH=$LCBASEDIR/bin:$JSFROOT/bin:$ROOTSYS/bin:$CERN_ROOT/bin:$LCLIBROOT/bin:$JLCSIMROOT/bin
J4PATH=$JUPITERROOT/bin/$G4SYSTEM:$G4INSTALL/bin/$G4SYSTEM
LCIOPATH=$LCIO/tools:$LCIO/bin:$JDK_HOME/bin
export PATH=.:~/bin:$LCPATH:$J4PATH:$LCIOPATH:$PATH
unset LCPATH
unset J4PATH
unset LCIOPATH

## Set LD Library Path
export LD_LIBRARY_PATH=$JSFROOT/lib:$ROOTSYS/lib:$LEDAROOT/lib
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$JUPITERROOT/lib/$G4SYSTEM:$G4INSTALL/lib/$G4SYSTEM:$SATELLITESROOT/lib:$URANUSROOT/lib
export IMAKEINCLUDE="-I$LCBASEDIR -I$KFLIBROOT -I$LCLIBROOT"


