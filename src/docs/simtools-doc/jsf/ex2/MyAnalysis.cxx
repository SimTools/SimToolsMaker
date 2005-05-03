//*LastUpdate : v.01.01 undefined by undefined
//*-- Author  : undefined undefined

///////////////////////////////////////////////////////////////////
//
//  MyAnalysis
//
//  Sample program
//
//$Id: 
//  
//////////////////////////////////////////////////////////////////


#include "JSFSteer.h"
#include "JSFSIMDST.h"
#include "MyAnalysis.h"

#include "TH1.h"

//  <<+EMAnal>>
TH1F *hEsum;
//  <<-EMAnal>>

ClassImp(MyAnalysis)
ClassImp(MyAnalysisBuf)

//_____________________________________________________________________________
  MyAnalysis::MyAnalysis(const char *name, const char *title)
       : JSFModule(name,title)
{
  fEventBuf = new MyAnalysisBuf("MyAnalysisBuf", 
	 "MyAnalysis event uffer",this);

//  <<+EMAnal>>
  //  Example to get parameter  
  fFlag = gJSF->Env()->GetValue("MyAnalysis.Flag",3);
  sscanf(gJSF->Env()->GetValue("MyAnalysis.Parameter","3.14"),"%g",&fParameter);
//  <<-EMAnal>>

}

//_____________________________________________________________________________
MyAnalysis::~MyAnalysis()
{
}

//_____________________________________________________________________________
Bool_t MyAnalysis::Initialize()
{
  // Initialize

//  <<+EMAnal>>
  // Put histogram defiition here, if needed.
  hEsum=new TH1F("hEsum","Calorimter toal enegy",100,0,200);
//  <<-EMAnal>>

  return kTRUE;
}

//_____________________________________________________________________________
Bool_t MyAnalysis::Process(Int_t nev)
{
// 

//  <<+EMAnal>>
  JSFSIMDST *sim=(JSFSIMDST*)gJSF->FindModule("JSFSIMDST");
  JSFSIMDSTBuf *sb=(JSFSIMDSTBuf*)sim->EventBuf();

  TClonesArray *emc=sb->GetEMCHits();

  Int_t nemc=sb->GetNEMCHits();
  Float_t emsum=0;
  for(Int_t ie=0;ie<nemc;ie++){
    JSFCALHit *ch=(JSFCALHit*)emc->UncheckedAt(ie);
    emsum+=ch->GetEnergy();
  }
  hEsum->Fill(emsum);
//  <<-EMAnal>>

  return kTRUE;
}

//_____________________________________________________________________________
Bool_t MyAnalysis::BeginRun(Int_t nrun)
{
  return kTRUE;
}

//_____________________________________________________________________________
Bool_t MyAnalysis::EndRun()
{
  return kTRUE;
}

//_____________________________________________________________________________
Bool_t MyAnalysis::Terminate()
{
  return kTRUE;
}

//_____________________________________________________________________________
MyAnalysisBuf::MyAnalysisBuf(const char *name, const char *title,
  	     JSFModule *module) : JSFEventBuf(name, title, module)
{
}

//_____________________________________________________________________________
MyAnalysisBuf::~MyAnalysisBuf()
{
}




