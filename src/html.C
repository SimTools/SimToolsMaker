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

/*
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
*/

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

// JSFclass


   html.MakeClass("JSFSteer");

   html.MakeClass("JSFModule");
   html.MakeClass("JSFSteer");
   html.MakeClass("JSFSteerConf");
   html.MakeClass("JSFEventBuf");
   html.MakeClass("JSFDBS");
   html.MakeClass("JSFUtil");
   html.MakeClass("JSFEnv");
   html.MakeClass("JSFEnvRec");

   html.MakeClass("JSFSpring");
   html.MakeClass("JSFSpringBuf");
   html.MakeClass("JSFSpringParton");
   html.MakeClass("JSFBases");
   html.MakeClass("JSFBasesTempHist");

   html.MakeClass("JSFGenerator");
   html.MakeClass("JSFGeneratorBuf");
   html.MakeClass("JSFGeneratorParticle");
   html.MakeClass("JSFGeneratedProcessType");

   html.MakeClass("JSFLCFULL");
   html.MakeClass("JSFFULLGenerator");
   html.MakeClass("JSFHadronizer");


   html.MakeClass("PythiaGenerator");
   html.MakeClass("JSFReadGenerator");
   html.MakeClass("JSFReadGeneratorBuf");
   html.MakeClass("DebugGenerator");
   html.MakeClass("DebugWGenerator");
   html.MakeClass("JSFReadParton");
   html.MakeClass("JSFMergeEvent");

   html.MakeClass("JSFQuickSim");
   html.MakeClass("JSFQuickSimParam");
   html.MakeClass("JSFQuickSimBuf");
   html.MakeClass("JSFSIMDST");
   html.MakeClass("JSFSIMDSTBuf");
   html.MakeClass("JSFLTKCLTrack");
   html.MakeClass("JSFCDCTrack");
   html.MakeClass("JSFVTXHit");
   html.MakeClass("JSFCALHit");
   html.MakeClass("JSFEMCHit");
   html.MakeClass("JSFHDCHit");
   html.MakeClass("JSFCALGeoParam");

   html.MakeClass("JSFHelicalTrack");

   html.MakeClass("JSFVirtualFit");
   html.MakeClass("JSFGeoCFit");
   html.MakeClass("JSFVertexing");

   html.MakeClass("JSFEDProperty");
   html.MakeClass("JSFEDHelix");
   html.MakeClass("JSFEnvGUIFrame");
   html.MakeClass("JSFEventDisplay");
   html.MakeClass("JSFDemoDisplay");

 
   html.MakeClass("JSFZVTOP3");
   html.MakeClass("JSFZVTOP3Track");
   html.MakeClass("JSFZVTOP3Vertex");
   html.MakeClass("JSFVirtualVertex");
   html.MakeClass("JSFVirtualVertexing");
   html.MakeClass("JSFGeneratorVertex");
   html.MakeClass("JSFGeneratorVertexing");

   html.MakeClass("JSFBeamGeneration");
   html.MakeClass("JSFBeamGenerationCain");
 
//   html.MakeClass("JSFJETNET");

   html.MakeClass("JSFHEPRUP");
   html.MakeClass("JSFHEPEUP");
   html.MakeClass("JSFMEGenerator");
   html.MakeClass("JSFMEGeneratorBuf");
   html.MakeClass("JSFSHGenerator");
   html.MakeClass("JSFSHGeneratorBuf");
   html.MakeClass("JSFReadMEGenerator");
   html.MakeClass("JSFReadMEGeneratorBuf");
   html.MakeClass("JSFPythiaHadronizer");
   html.MakeClass("JSFPythiaHadronizerBuf");

/*
   html.MakeClass("ANL2DSpline");
   html.MakeClass("ANL2DVector");
   html.MakeClass("ANL3DVector");
   html.MakeClass("ANL4DVector");

   html.MakeClass("ANLCheatedJetFinder");
   html.MakeClass("ANLCheatedDurhamJetFinder");
   html.MakeClass("ANLCheatedJadeJetFinder");
   html.MakeClass("ANLCheatedJadeEJetFinder");
   html.MakeClass("ANLCheatedJetFinder");
   html.MakeClass("ANLDurhamJetFinder");
   html.MakeClass("ANLEventShape");
   html.MakeClass("ANLGVTXTagger");
   html.MakeClass("ANLJadeEJetFinder");
   html.MakeClass("ANLJadeJetFinder");
   html.MakeClass("ANLJet");
   html.MakeClass("ANLJetFinder");
   html.MakeClass("ANLPair");
   html.MakeClass("ANLPairCombiner");
   html.MakeClass("ANLTaggedJet");
   html.MakeClass("ANLVTXTagger");
   html.MakeClass("FlavourGetter");
   html.MakeClass("Lockable");
*/

   html.MakeClass("THerwigParticle");
   html.MakeClass("THerwig");
   html.MakeClass("HerwigGenerator");
   html.MakeClass("HerwigGenerator");

   html.MakeClass("ANLTrack");
   html.MakeClass("ANLVTXTagger");
   html.MakeClass("FlavourGetter");
   html.MakeClass("TTL4JFlavourGetter");
   html.MakeClass("ANLTaggedJet");
   html.MakeClass("ANLCheatedJetFinder");
   html.MakeClass("ANLCheatedJadeJetFinder");
   html.MakeClass("ANLCheatedJadeEJetFinder");
   html.MakeClass("ANLCheatedDurhamJetFinder");
   html.MakeClass("ANLGVTXTagger");
 
// Leda class
  html.MakeClass("ANL2DVector");
  html.MakeClass("ANL3DVector");
  html.MakeClass("ANL4DVector");
  html.MakeClass("ANLPair");
  html.MakeClass("ANLPairCombiner");
  html.MakeClass("ANLJet");
  html.MakeClass("ANLJetFinder");
  html.MakeClass("ANLJadeJetFinder");
  html.MakeClass("ANLJadeEJetFinder");
  html.MakeClass("ANLDurhamJetFinder");
  html.MakeClass("ANLEventShape");
  html.MakeClass("ANL2DSpline");
  html.MakeClass("TCircle");
  html.MakeClass("TCylinder");
  html.MakeClass("TPlane");
  html.MakeClass("THype");
  html.MakeClass("TTube");
  html.MakeClass("THelicalTrack");
  html.MakeClass("TStraightTrack");
  html.MakeClass("TVCurve");
  html.MakeClass("TVSolid");
  html.MakeClass("TVSurface");
  html.MakeClass("TVTrack");
  html.MakeClass("TKalMatrix");
  html.MakeClass("TVKalSite");
  html.MakeClass("TVKalState");
  html.MakeClass("TVKalSystem");
  html.MakeClass("TVTrackHit");
  html.MakeClass("TVMeasLayer");
  html.MakeClass("TKalTrackSite");
  html.MakeClass("TKalTrackState");
  html.MakeClass("TKalTrack");
  html.MakeClass("TVKalDetector");
  html.MakeClass("TFFT");
  html.MakeClass("TH1E");
  html.MakeClass("TObjNum");
  html.MakeClass("TDim");
  html.MakeClass("TDynArray2");
  html.MakeClass("TDynArray3");
  html.MakeClass("TVAddress");
  html.MakeClass("TAttDrawable");
  html.MakeClass("TAttElement");
  html.MakeClass("TAttLockable");


//  Satellites class
  html.MakeClass("J42LCIO");
  html.MakeClass("JSFJ4");
  html.MakeClass("JSFJ4Buf");
  html.MakeClass("JSFJ4BufferMap");
  html.MakeClass("JSFJ4BufManager");
  html.MakeClass("S4PrimaryParticle");
  html.MakeClass("S4PrimaryVertex");
//  html.MakeClass("S4BabyMCTruth");
//  html.MakeClass("S4BabyMCTruthBuf");
//  html.MakeClass("S4BabyExactHit");
  html.MakeClass("S4CALExactHit");
  html.MakeClass("S4CALPreHit");
  html.MakeClass("S4CALPostHit");
  html.MakeClass("S4CALAddress");
  html.MakeClass("S4CALMCTruth");
  html.MakeClass("S4CALMCTruthBuf");
  html.MakeClass("S4CDCMCTruth");
  html.MakeClass("S4CDCMCTruthBuf");
  html.MakeClass("S4CDCExactHit");
  html.MakeClass("S4CTExactHit");
  html.MakeClass("S4ITMCTruth");
  html.MakeClass("S4ITMCTruthBuf");
  html.MakeClass("S4ITExactHit");
  html.MakeClass("S4VMCTruth");
  html.MakeClass("S4VMCTruthBuf");
  html.MakeClass("S4VExactHit");
  html.MakeClass("S4MUDExactHit");
  html.MakeClass("S4MUDPreHit");
  html.MakeClass("S4MUDMCTruth");
  html.MakeClass("S4MUDMCTruthBuf");
  html.MakeClass("S4TPCMCTruth");
  html.MakeClass("S4TPCMCTruthBuf");
  html.MakeClass("S4TPCExactHit");
  html.MakeClass("S4TPCPostHit");
  html.MakeClass("S4VTXMCTruth");
  html.MakeClass("S4VTXMCTruthBuf");
  html.MakeClass("S4VTXExactHit");
  html.MakeClass("S4CALAnalysis");
  html.MakeClass("S4CALCluster");
  html.MakeClass("S4CALClusterMaker");
  html.MakeClass("S4CALClusterMakerBuf");
//  html.MakeClass("S4CALCalibration");
//  html.MakeClass("PFStudy");
//  html.MakeClass("S4CALSample");
  html.MakeClass("S4CALHit");
  html.MakeClass("S4CALHitMaker");
  html.MakeClass("S4CALHitBuf");
//  html.MakeClass("S4EMCClusterMaker");
//  html.MakeClass("S4EMCClusterMakerBuf");
//  html.MakeClass("S4EMCTrackCellMatch");
//  html.MakeClass("S4EMCTrackCellMatchBuf");
//  html.MakeClass("S4HDCNeutralClusterMaker");
//  html.MakeClass("S4HDCNeutralClusterMakerBuf");
//  html.MakeClass("S4CALCellCalibration");
//  html.MakeClass("S4CALCellCalibrationBuf");
//  html.MakeClass("S4EMCElectronFinder");
//  html.MakeClass("S4EMCElectronFinderBuf");
//  html.MakeClass("S4ExactPFOMaker");
//  html.MakeClass("S4ExactPFOMakerBuf");
//  html.MakeClass("S4HDCTrackCellMatch");
//  html.MakeClass("S4HDCTrackCellMatchBuf");
//  html.MakeClass("S4CALHitMaker");
//  html.MakeClass("S4CALHitMakerBuf");
//  html.MakeClass("S4EMCNeutralClusterMaker");
//  html.MakeClass("S4EMCNeutralClusterMakerBuf");
//  html.MakeClass("S4HDCClusterMaker");
//  html.MakeClass("S4HDCClusterMakerBuf");
//  html.MakeClass("S4MuonFinder");
//  html.MakeClass("S4MuonFinderBuf");

//  html.MakeClass("S4CDCAnalysis");
//  html.MakeClass("S4CDCHit");
//  html.MakeClass("S4CDCHitWire");
//  html.MakeClass("S4CDCHitMaker");
//  html.MakeClass("S4CDCHitMakerBuf");
//  html.MakeClass("S4CDCTrackHit");
//  html.MakeClass("S4CDCVectorHit");
//  html.MakeClass("S4CDCTrack");
//  html.MakeClass("S4CDCTrackMaker");
//  html.MakeClass("S4CDCTrackMakerBuf");

  html.MakeClass("S4HYBTrack");
  html.MakeClass("S4HYBTrackMaker");
  html.MakeClass("S4HYBTrackMakerBuf");
  html.MakeClass("S4ITAnalysis");
  html.MakeClass("S4ITHit");
  html.MakeClass("S4ITHitMaker");
  html.MakeClass("S4ITHitMakerBuf");
  html.MakeClass("S4ITTrack");
  html.MakeClass("S4ITTrackHit");
  html.MakeClass("S4ITTrackMakerBuf");
  html.MakeClass("S4ITTrackMaker");
  html.MakeClass("S4JetAnalysis");
  html.MakeClass("S4Jet");
  html.MakeClass("S4JetSet");
  html.MakeClass("S4JetMaker");
  html.MakeClass("S4JetMakerBuf");
  html.MakeClass("S4VHit");
  html.MakeClass("S4VTrack");
  html.MakeClass("S4PFOAnalysis");
  html.MakeClass("S4PFObject");
  html.MakeClass("S4PFOFilter");
  html.MakeClass("S4PFOMaker");
  html.MakeClass("S4PFOMakerBuf");
  html.MakeClass("S4TPCAnalysis");
  html.MakeClass("S4TPCPadHit");
  html.MakeClass("S4TPCHitMaker");
  html.MakeClass("S4TPCHitMakerBuf");
  html.MakeClass("S4TPCTrack");
  html.MakeClass("S4TPCTrackHit");
  html.MakeClass("S4TPCTrackMakerBuf");
  html.MakeClass("S4TPCTrackMaker");
  html.MakeClass("S4VTXAnalysis");
  html.MakeClass("S4VTXHit");
  html.MakeClass("S4VTXHitMaker");
  html.MakeClass("S4VTXHitMakerBuf");
  html.MakeClass("S4VTXTrack");
  html.MakeClass("S4VTXTrackHit");
  html.MakeClass("S4VTXTrackMakerBuf");
  html.MakeClass("S4VTXTrackMaker");


//  Uranus Class
//  html.MakeClass("U4BabyAnalysis");
//  html.MakeClass("BabyDisplay");
//  html.MakeClass("VUserAnalysis");
//  html.MakeClass("UserAnalysis");
//  html.MakeClass("BabyDisplay");
//  html.MakeClass("VUserAnalysis");
//  html.MakeClass("UserAnalysis");
//  html.MakeClass("BabyDisplay");
//  html.MakeClass("VUserAnalysis");
//  html.MakeClass("UserAnalysis");
//  html.MakeClass("U4BabyTrack");
//  html.MakeClass("U4BabyTrackMaker");
//  html.MakeClass("U4BabyTrackMakerBuf");
//  html.MakeClass("U4CDCClusterMaker");
//  html.MakeClass("U4CDCClusterBuf");
//  html.MakeClass("U4CDCFADCCalibration");
//  html.MakeClass("U4CDCCluster");
//  html.MakeClass("U4CDCMeasLayer");
//  html.MakeClass("U4CDCKalDetector");
//  html.MakeClass("U4CDCKalHit");
//  html.MakeClass("U4CDCHitMaker");
//  html.MakeClass("U4CDCHitMakerBuf");
//  html.MakeClass("U4CDCHitLayer");
//  html.MakeClass("U4CDCHitCell");
//  html.MakeClass("U4CDCHitWire");
//  html.MakeClass("U4CDCHit");
//  html.MakeClass("U4CDCTimeToXRelation");
//  html.MakeClass("U4CDCXTDatum");
//  html.MakeClass("CalibDatum");
//  html.MakeClass("U4CDCTrack");
//  html.MakeClass("U4CDCTrackHit");
//  html.MakeClass("U4CDCTrackMakerBuf");
//  html.MakeClass("U4CDCTrackMaker");
//  html.MakeClass("U4CDCVectorHit");
//  html.MakeClass("U4CDCRawData");
//  html.MakeClass("U4CDCUniversalRecordHeader");
//  html.MakeClass("U4CDCRawGPIBDatum");
//  html.MakeClass("U4CDCRawScalerDatum");
//  html.MakeClass("U4CDCRawADCDatum");
//  html.MakeClass("U4CDCRawDataBuf");
//  html.MakeClass("U4CDCRawDataBuf");
//  html.MakeClass("U4CDCChannel");
//  html.MakeClass("U4CDCHardwareMap");
//  html.MakeClass("U4CDCBeginRunBuf");
//  html.MakeClass("U4CDCEndRunBuf");
//  html.MakeClass("U4CDCRawHist");

  html.MakeClass("U4HYBTrack");
  html.MakeClass("U4HYBTrackMakerBuf");
  html.MakeClass("U4HYBTrackMaker");
  html.MakeClass("U4ITKalHit");
  html.MakeClass("U4ITMeasLayer");
  html.MakeClass("U4ITKalDetector");
  html.MakeClass("U4ITHitMaker");
  html.MakeClass("U4ITHitMakerBuf");
  html.MakeClass("U4ITHit");
  html.MakeClass("U4ITTrack");
  html.MakeClass("U4ITTrackHit");
  html.MakeClass("U4ITTrackMakerBuf");
  html.MakeClass("U4ITTrackMaker");
  html.MakeClass("U4VAnalysis");
  html.MakeClass("U4VHitMaker");
  html.MakeClass("U4VHitMakerBuf");
  html.MakeClass("U4VKalDetector");
  html.MakeClass("U4KalDetector");
  html.MakeClass("U4VTrackHit");
  html.MakeClass("U4VTrack");
  html.MakeClass("U4VTrackMaker");
  html.MakeClass("U4VTrackMakerBuf");
  html.MakeClass("U4TPCHit");
  html.MakeClass("U4TPCMeasLayer");
  html.MakeClass("U4TPCKalDetector");
  html.MakeClass("U4TPCHitMaker");
  html.MakeClass("U4TPCHitMakerBuf");
  html.MakeClass("U4TPCPadHit");
  html.MakeClass("U4TPCTrack");
  html.MakeClass("U4TPCTrackHit");
  html.MakeClass("U4TPCTrackMakerBuf");
  html.MakeClass("U4TPCTrackMaker");
  html.MakeClass("U4VTXKalHit");
  html.MakeClass("U4VTXMeasLayer");
  html.MakeClass("U4VTXKalDetector");
  html.MakeClass("U4VTXHitMaker");
  html.MakeClass("U4VTXHitMakerBuf");
  html.MakeClass("U4VTXHit");
  html.MakeClass("U4VTXTrack");
  html.MakeClass("U4VTXTrackHit");
  html.MakeClass("U4VTXTrackMakerBuf");
  html.MakeClass("U4VTXTrackMaker");



   html.MakeIndex();

   Char_t *cmd="cd htmldoc ; mv USER_Index.html JSFMain_Index.html";
   gSystem->Exec(cmd);
//
   html.Convert("../macro/gui.C","Main script for JSF","htmldoc");
   html.Convert("../macro/GUIMainMacro.C","Main script for JSF","htmldoc");
   html.Convert("../macro/InitPythia.C","Set Parameter of Pythia Generator","htmldoc");

   html.Convert("../examples/JSF_QuickSim/exam01/UserAnalysis.C",
                "QuickSim/Example01","htmldoc");

   

}


