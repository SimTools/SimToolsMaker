{
//$id$

  gEnv->SetValue("Root.Html.Root",
                 "http://www-jlc.kek.jp/subg/offl/jsf/RootHtmlDoc/html");
  gEnv->SetValue("Root.Html.HomePage",
                 "http://www-jlc.kek.jp/subg/offl/jsf/RootHtmlDoc/html");

   gSystem->Load("libJSF.so");
   gSystem->Load("libJSFGenerator.so");
   gSystem->Load("libBasesSpring.so");
   gSystem->Load("libJSFBeamGeneration.so");
   gSystem->Load("libJSFTools.so");
   gSystem->Load("libJSFQuickSim.so");

  gSystem->Load("libEG.so");

  gSystem->Load("libS4Utils.so");
  gSystem->Load("libAnlib.so");
  gSystem->Load("libS4Geom.so");
  gSystem->Load("libS4Kalman.so");
  gSystem->Load("libS4KalTrack.so");

    gSystem->Load("libPythia6.so");
    gSystem->Load("libEGPythia6.so");
    gSystem->Load("libJSFPythia6.so");
    gSystem->Load("libJSFAnlib.so");
    gSystem->Load("libJSFME2SHGenerator.so");
    gSystem->Load("libJSFZVTOP3.so");
    gSystem->Load("libTHerwig.so");


  gSystem->Load("libJSFGUI.so");

  gSystem->Load("libS4Utils.so");
  gSystem->Load("libS4MCTruth.so");
  gSystem->Load("libS4VTXMCTruth.so"); 
  gSystem->Load("libS4ITMCTruth.so");
  gSystem->Load("libS4CTMCTruth.so");
  gSystem->Load("libS4TPCMCTruth.so");
  gSystem->Load("libS4CDCMCTruth.so");
  gSystem->Load("libS4CALMCTruth.so");
  gSystem->Load("libS4MUDMCTruth.so");
  gSystem->Load("libJSFJ4.so");
  gSystem->Load("libS4Kalman.so");
  gSystem->Load("libS4Geom.so");
  gSystem->Load("libS4KalTrack.so");
  gSystem->Load("libU4VHitMaker.so");
  gSystem->Load("libU4KalDetector.so");
  gSystem->Load("libU4VTXKalDetector.so");
  gSystem->Load("libU4ITKalDetector.so");
  gSystem->Load("libU4TPCKalDetector.so");
  gSystem->Load("libU4TPCHitMaker.so");
  gSystem->Load("libS4TPCHitMaker.so");
  gSystem->Load("libU4ITHitMaker.so");
  gSystem->Load("libS4ITHitMaker.so");
  gSystem->Load("libU4VTXHitMaker.so");
  gSystem->Load("libS4VTXHitMaker.so");
  gSystem->Load("libU4VTrackMaker.so");
  gSystem->Load("libS4Kern.so");
  gSystem->Load("libU4TPCTrackMaker.so");
  gSystem->Load("libS4TPCTrackMaker.so");
  gSystem->Load("libU4ITTrackMaker.so");
  gSystem->Load("libS4ITTrackMaker.so");
  gSystem->Load("libU4VTXTrackMaker.so");
  gSystem->Load("libS4VTXTrackMaker.so");
  gSystem->Load("libU4HYBTrackMaker.so");
  gSystem->Load("libS4HYBTrackMaker.so");
  gSystem->Load("libS4TPCAnalysis.so");
  gSystem->Load("libS4ITAnalysis.so");
  gSystem->Load("libS4VTXAnalysis.so");
  gSystem->Load("libS4CALHitMaker.so");
  gSystem->Load("libS4CALClusterMaker.so");
  gSystem->Load("libS4CALAnalysis.so");
  gSystem->Load("libAnlib.so");
  gSystem->Load("libS4PFOMaker.so");
  gSystem->Load("libS4PFOAnalysis.so");
  gSystem->Load("libJSF2LCIO.so");
  gSystem->Load("libJ42LCIO.so");
  gSystem->Load("libS4JetMaker.so");
  gSystem->Load("libS4JetAnalysis.so");
  gSystem->Load("libU4VAnalysis.so");


  THtml html; 
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

//
//   html.Convert("../macro/gui.C","Main script for JSF","");
//   html.Convert("../macro/GUIMainMacro.C","Main script for JSF","");
//   html.Convert("../macro/InitPythia.C","Set Parameter of Pythia Generator","");

   html.Convert("../examples/JSF_QuickSim/exam01/UserAnalysis.C",
                "JSF_QuickSim/Example01","htmldoc/scripts");
   Char_t *cmd="cd htmldoc/scripts ; mv UserAnalysis.C.html JSF_QuickSim_Example01_UserAnalysis.C.html";
   gSystem->Exec(cmd);

   html.Convert("../examples/JSF_QuickSim/exam01/UserAnalysis.C",
                "JSF_QuickSim/Example01","htmldoc/scripts");
   Char_t *cmd="cd htmldoc/scripts ; mv UserAnalysis.C.html JSF_QuickSim_Example01_UserAnalysis.C.html";
   gSystem->Exec(cmd);



   

}


