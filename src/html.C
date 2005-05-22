JSFSteer *gJSF=0;
THtml html; 

int html()
{
//$id$

  gEnv->SetValue("Root.Html.Root",
                 "http://www-jlc.kek.jp/subg/offl/jsf/RootHtmlDoc/html");
  gEnv->SetValue("Root.Html.HomePage",
                 "http://www-jlc.kek.jp/subg/offl/jsf/RootHtmlDoc/html");

  jsf  = new JSFSteer();
  gJSF = jsf;
  gSystem->Load("libJSFGUI.so");

  gROOT->LoadMacro("$(SATELLITESROOT)/macros/S4Macros.C");
  gROOT->ProcessLine("ConstructS4Modules();");

  gSystem->Load("libJSFME2SHGenerator.so");
  gSystem->Load("libJSFZVTOP3.so");
  gSystem->Load("libTHerwig.so");
  gSystem->Load("libS4CTMCTruth.so");
  gSystem->Load("libJSFAnlib.so"); 
  gROOT->LoadMacro("makeclass.C");

  html.SetOutputDir("htmldoc");
  TString srcdir("./:$(JSFROOT)/src/kern:$(JSFROOT)/include");
  srcdir += ":$(ROOTSYS)/src:$(JSFROOT)/src/generators/bases/src";
  srcdir += ":$(JSFROOT)/src/tools";
  srcdir += ":$(JSFROOT)/src/gui";
  srcdir += ":$(JSFROOT)/src/opts/Anlib/src:$(JSFROOT)/src/opts/lcio";
  srcdir += ":$(JSFROOT)/src/opts/stdhep:$(JSFROOT)/src/opts/zvtop/src";
  srcdir += ":$(JSFROOT)/src/opts/zvtop/example";
  srcdir += ":$(JSFROOT)/src/generators/bsgen:$(JSFROOT)/src/generators/jsfgen";
  srcdir += ":$(JSFROOT)/src/generators/herwig:$(JSFROOT)/src/generators/pythia6";
  srcdir += ":$(JSFROOT)/src/generators/me2shgen";


  srcdir += ":$(JSFROOT)/src/lclibdep/quicksim:$(JSFROOT)/src/lclibdep/jsfpythia6";

  srcdir += ":$(LEDAROOT)/src/anlib:$(LEDAROOT)/src/geomlib";
  srcdir += ":$(LEDAROOT)/src/kallib:$(LEDAROOT)/src/kaltracklib";
  srcdir += ":$(LEDAROOT)/src/utils";


  srcdir += ":$(SATELLITESROOT)/src/io/j42lcio:$(SATELLITESROOT)/src/io/jsfj4/kern";
  srcdir += ":$(SATELLITESROOT)/src/io/mctruth/cal:$(SATELLITESROOT)/src/io/mctruth/cdc";
  srcdir += ":$(SATELLITESROOT)/src/io/mctruth/ct:$(SATELLITESROOT)/src/io/mctruth/it";
  srcdir += ":$(SATELLITESROOT)/src/io/mctruth/kern:$(SATELLITESROOT)/src/io/mctruth/mud";
  srcdir += ":$(SATELLITESROOT)/src/io/mctruth/vtx:$(SATELLITESROOT)/src/io/mctruth/tpc";
  srcdir += ":$(SATELLITESROOT)/src/io/mctruth/gen";
  srcdir += ":$(SATELLITESROOT)/src/metis/cal/analysis";
  srcdir += ":$(SATELLITESROOT)/src/metis/cal/clustermaker";
  srcdir += ":$(SATELLITESROOT)/src/metis/cal/hitmaker";
  srcdir += ":$(SATELLITESROOT)/src/metis/cdc/analysis";
  srcdir += ":$(SATELLITESROOT)/src/metis/cdc/hitmaker";
  srcdir += ":$(SATELLITESROOT)/src/metis/hybt/hybtrackmaker";
  srcdir += ":$(SATELLITESROOT)/src/metis/it/trackmaker";
  srcdir += ":$(SATELLITESROOT)/src/metis/it/hitmaker";
  srcdir += ":$(SATELLITESROOT)/src/metis/it/analysis";
  srcdir += ":$(SATELLITESROOT)/src/metis/jet/jetmaker";
  srcdir += ":$(SATELLITESROOT)/src/metis/jet/analysis";
  srcdir += ":$(SATELLITESROOT)/src/metis/kern";
  srcdir += ":$(SATELLITESROOT)/src/metis/pfo/pfomaker";
  srcdir += ":$(SATELLITESROOT)/src/metis/pfo/analysis";
  srcdir += ":$(SATELLITESROOT)/src/metis/tpc/trackmaker";
  srcdir += ":$(SATELLITESROOT)/src/metis/tpc/hitmaker";
  srcdir += ":$(SATELLITESROOT)/src/metis/tpc/analysis";
  srcdir += ":$(SATELLITESROOT)/src/metis/vtx/trackmaker";
  srcdir += ":$(SATELLITESROOT)/src/metis/vtx/hitmaker";
  srcdir += ":$(SATELLITESROOT)/src/metis/vtx/analysis";
//
//  srcdir += ":$(URANUSROOT)/src/cdc/clustermaker";
//  srcdir += ":$(URANUSROOT)/src/cdc/hitmaker";
//  srcdir += ":$(URANUSROOT)/src/cdc/trackmaker";
//  srcdir += ":$(URANUSROOT)/src/cdc/detconfig";
//  srcdir += ":$(URANUSROOT)/src/cdc/unpacker";
  srcdir += ":$(URANUSROOT)/src/hybt/hybtrackmaker";
  srcdir += ":$(URANUSROOT)/src/tpc/hitmaker";
  srcdir += ":$(URANUSROOT)/src/tpc/trackmaker";
  srcdir += ":$(URANUSROOT)/src/tpc/detconfig";
  srcdir += ":$(URANUSROOT)/src/vtx/hitmaker";
  srcdir += ":$(URANUSROOT)/src/vtx/trackmaker";
  srcdir += ":$(URANUSROOT)/src/vtx/detconfig";
  srcdir += ":$(URANUSROOT)/src/it/hitmaker";
  srcdir += ":$(URANUSROOT)/src/it/trackmaker";
  srcdir += ":$(URANUSROOT)/src/it/detconfig";
  srcdir += ":$(URANUSROOT)/src/kern/analysis";
  srcdir += ":$(URANUSROOT)/src/kern/hitmaker";
  srcdir += ":$(URANUSROOT)/src/kern/kaldet";
  srcdir += ":$(URANUSROOT)/src/kern/trackmaker";

  

  srcdir += ":$(LCBASEDIR)/include:$(LEDAROOT)/src";  
  html.SetSourceDir(srcdir.Data());

// JSFclass

  gROOT->ProcessLine("makeclass();");


   html.MakeIndex();

   Char_t *cmd="cd htmldoc ; mv USER_Index.html JSFMain_Index.html";
   gSystem->Exec(cmd);
   gSystem->Exec("mkdir -p htmldoc/scripts");
//

  char *cname[][2]={ {"../macro/gui.C","Main script for JSF"},
   {"../macro/GUIMainMacro.C","Main script for JSF"},
   {"../macro/InitPythia.C","Set Parameter of Pythia Generator"},
   {"../examples/JSF_QuickSim/exam01/UserAnalysis.C","QuickSim/Example01"}};

  for(Int_t i=0;i<4;i++) {
    html.Convert(cname[i][0], cname[i][1], "htmldoc/scripts");
  }

}


