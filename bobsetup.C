{
  //  R. Michaels, May 2014
  //  Steering script for Hall A analyzer

  THaApparatus* HRSR = new THaHRS("R","Right arm HRS");
  gHaApps->Add( HRSR );

  THaApparatus* HRSL = new THaHRS("L","Left arm HRS");
  gHaApps->Add( HRSL );
  
  // add detectors that are not in the default config  
  //  HRSL->AddDetector( new THaScintillator("s0","Scintillator S0"));


  // done in rootlogon.C:  gSystem->Load("libParity.so");
  gHaApps->Add(new ParityData("P","HAPPEX Data"));

  // e-p scattering
  Double_t amu = 931.494*1.e-3;  // amu to GeV
  Double_t Pb208 = 208*amu;
  
  Double_t mass_tg  = Pb208; // Lead

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



  THaAnalyzer* analyzer = new THaAnalyzer;
  
  THaEvent* event = new THaEvent;
  
  THaRun* run = new THaRun( "run.dat" );

  // For filesplit files give the date "now" and don't require any data
  TDatime now;
  run->SetDate( now );
  run->SetDataRequired( 0 );  // it was: ( THaRunBase::kDate );


  //  analyzer->SetCodaVersion(2);
  analyzer->EnableBenchmarks();
  analyzer->SetEvent( event );
  analyzer->SetOutFile( "Afile.root" );
  analyzer->SetCutFile("onlana.cuts");
  analyzer->SetOdefFile("output.def");

  analyzer->SetSummaryFile("summary_example.log"); // optional
  
  run->SetLastEvent( 50000 );   

}
