#ifndef __MyAnalysis__
#define __MyAnalysis___

///////////////////////////////////////////////////////////////////////
//
//  MyAnalysis
//
//  Sample program
//
//$Id:
//
///////////////////////////////////////////////////////////////////////

#include <TObject.h>
#include "JSFModule.h"

class MyAnalysisBuf : public JSFEventBuf 
{
protected:

public:
  MyAnalysisBuf(const char *name="MyAnalysisBuf", 
	     const char *title="MyAnalysis buffer",
		  JSFModule *module=NULL);
  virtual ~MyAnalysisBuf();

  // add your own function here

  ClassDef(MyAnalysisBuf,1)  // MyAnalysis event data buffer
};



// *******************************************************
class MyAnalysis : public JSFModule 
{
 protected:
  Int_t   fFlag;      // An example of Int_t parameter
  Float_t fParameter; // An example of Float_t parameter

 public:
  MyAnalysis(const char *name="MyAnalysis", 
		  const char *title="MyAnalysis");
  virtual ~MyAnalysis();

  virtual Bool_t Initialize();
  virtual Bool_t BeginRun(Int_t runno=1);
  virtual Bool_t EndRun();
  virtual Bool_t Terminate();
  virtual Bool_t Process(Int_t ev=1);
  
  ClassDef(MyAnalysis, 1)  // MyAnalysis class

};

#endif










