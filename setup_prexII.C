using namespace std;
void setup(Int_t runNo=0){
  //  R. Michaels, May 2014
  //  Steering script for Hall A analyzer
 /* int runNo, hrs;
  char infile[300];
  cout<<"Run number please (-1 to exit):";
  cin>>runNo;
  cout<<"HRS? (1 Left, 2 Right) ";
  cin>>hrs;*/
  
  /*if(runNo<20000){
    gSystem->Load("../ParityData/libParity_LHRS.so"); 
  }else{
    gSystem->Load("../ParityData/libParity_RHRS.so");
   }*/
  char infile[300];
  //static const char* replay_dir_prefix = "./%s";
  THaApparatus* HRSR = new THaHRS("R","Right arm HRS");
  gHaApps->Add( HRSR );

  THaApparatus* HRSL = new THaHRS("L","Left arm HRS");
  gHaApps->Add( HRSL );
 //   HRSL->AddDetector( new TriFadcXscin("s0","s0 scintillator",kFALSE) );
 //   HRSL->AddDetector( new THaVDC("vdc", "Vertical Drift Chamber"));
  
  // add detectors that are not in the default config  
  //  HRSL->AddDetector( new THaScintillator("s0","Scintillator S0"));


  // done in rootlogon.C:  gSystem->Load("libParity.so");
  gHaApps->Add(new ParityData("P","HAPPEX Data"));



  // e-p scattering
  Double_t amu = 931.494*1.e-3;  // amu to GeV
  Double_t he4 = 4*amu;
  
  Double_t mass_tg  = he4; // Helium

  // Electron kinematics
  THaPhysicsModule* EK_r = new THaElectronKine("EK_R",
					       "Electron kinematics in HRS-R",
					       "R",mass_tg);
  THaPhysicsModule* EK_l = new THaElectronKine("EK_L",
					       "Electron kinematics in HRS-L",
					       "L",mass_tg);
  
  gHaPhysics->Add( EK_r );
  gHaPhysics->Add( EK_l );

  gHaPhysics->Add( new THaGoldenTrack( "R.gold", "HRS-R Golden Track", "R" ));
  gHaPhysics->Add( new THaGoldenTrack( "L.gold", "HRS-L Golden Track", "L" ));


  THaScalerEvtHandler *lscaler = new THaScalerEvtHandler("Left","HA scaler event type 140");
  lscaler->SetDebugFile("LeftScaler.txt");
  gHaEvtHandlers->Add (lscaler);

  THaScalerEvtHandler *rscaler = new THaScalerEvtHandler("Right","HA scaler event type 140");
  rscaler->SetDebugFile("RightScaler.txt");
  gHaEvtHandlers->Add (rscaler);


  THaAnalyzer* analyzer = new THaAnalyzer;
  
  THaEvent* event = new THaEvent;
  for (Int_t nsplit=0;nsplit<1;nsplit++){  
  if(runNo>20000)
  sprintf(infile,"/adaq1/data1/prexRHRS_%d.dat.%d",runNo,nsplit);
  else
  sprintf(infile,"/adaq1/data1/prexLHRS_%d.dat.%d",runNo,nsplit);
  cout<<"replay: Try file "<<infile<<endl;
  THaRun *run;
  run = new THaRun(infile);
 // run->SetDataRequired( THaRunBase::kDate );
  TDatime now;
  run->SetDate( now );
  run->SetDataRequired( 0 );  // it was: ( THaRunBase::kDate );

  analyzer->EnableBenchmarks();
  analyzer->SetEvent( event );
  char outname[300];
  if(runNo>20000)
  sprintf(outname,"./prexRHRS_%d.root",runNo);
  else
  sprintf(outname,"./prexLHRS_%d.root",runNo);
  analyzer->SetOutFile( outname );
  analyzer->SetCutFile("onlana.cuts");
  analyzer->SetOdefFile("output.def");
   analyzer->SetSummaryFile("summary_example.log"); // optional
//
  run->SetLastEvent(-1);   // Number of events to process
  analyzer->Process(*run);
  }
}
