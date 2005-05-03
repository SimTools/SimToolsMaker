//****************************************************
//*
//*  Dummy UserAnalysis Script to be used with gui.C 
//*  Functions in this scripts are called by GUIMainMacro.C  
//*  
//*  In this script, global functions, UserInitialize() nad UserAnalysis()
//*  Must be defined.  UserInitialize() is called at job initialization 
//*  to initialize histograms, etc.  It is also called when reset historgam
//*  menu is selected from JSF Control Panel.  UserAnalysis() is called 
//*  during the event loop after executing Process functions of JSF modules
//*  and display event daia but before display histogram.  See GetEvent()
//*  function in GUIMainMacro.C, where UserAnalysis() is called.
//*
//*  UserSetOptions() and UserTerminate() may be defined in this file.
//*  UserSetOptions() are called before declaration of JSF modules.
//*  It can be used to set parameters optional for user analsis.
//*  UserTerminate() is called during the JSF termination process.
//*
//*  When runmode=4, UserModuleDefine() must be defined in this file.
//*  It is used to define JSF modules specific to user analysis.  
//*  
//*$Id$
//*
//****************************************************

TCanvas *cHist;
TH1F *hNCDC;
TH1F *hNVTX;

//_________________________________________________________
void UserInitialize()
{
  // Called once at Job initialization to initialize job parameters
  hNCDC=new TH1F("hNCDC","Number of CDC Tracks",100, 0, 100);
  hNVTX=new TH1F("hNVTX","Number of VTX Hiits", 100, 0, 100);
}

//_________________________________________________________
void UserAnalysis()
{
  // This function is called when the processing of one event is completed.
  // Any data processing of the event can be performed in this function.
  // 

  // Get pointers to SIMDST module
  JSFSIMDST *simdst=(JSFSIMDST*)jsf->FindModule("JSFSIMDST");

  // Get pointers to event buf corresponding SIMDSTBuf
  JSFSIMDSTBuf *buf=(JSFSIMDSTBuf*)simdst->EventBuf();

  // Get Number of CDC tracks and number of VTX hits
  Int_t ncdc=buf->GetNCDCTracks();
  Int_t nvtx=buf->GetNVTXHits();

  // Fill into histogram
  hNCDC->Fill((Float_t)ncdc);
  hNVTX->Fill((Float_t)nvtx);

}

//_________________________________________________________
void DrawHist()
{
  //  Example to draw histograms in each events

  TDirectory *old=gDirectory;
  // if Canvas is not defined yet, create and devide to 2.

  if( !cHist ) {
    cHist=new TCanvas("cHist","Canvas 1",100, 100, 400, 400);
    cHist->Divide(2,1);  // Divide canvas horizontally.
  } 
  
  cHist->cd(1) ;     hNCDC->Draw();

  cHist->cd(2) ;     hNVTX->Draw();

  cHist->Update();  // Update Canvas
  old->cd();        // Back to old directory

}





