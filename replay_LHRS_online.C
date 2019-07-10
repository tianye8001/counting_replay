R__LOAD_LIBRARY(../ParityData/libParity.so)
R__LOAD_LIBRARY(libraries/FadcRasteredBeam/libTriFadcRasteredBeam.so)
R__LOAD_LIBRARY(libraries/TriVDCeff/libTriVDCeff.so)

using namespace std;
void replay_LHRS_online(Int_t runNo=0, Int_t lastevt=-1){

  /*
  bool LeftArm = false;
  bool RightArm = false;

  if(runNo > 20000)
      RightArm = true;
  else
      LeftArm = true;
  */

  // e-p scattering
  Double_t amu = 931.494*1.e-3;  // amu to GeV
  //Double_t he4 = 4*amu;
  Double_t pb208 = 208*amu;
  
  //Double_t mass_tg  = he4; // Helium
  Double_t mass_tg  = pb208; // Helium

  // LHRS Detectors
  THaApparatus* HRSL = new THaHRS("L","Left arm HRS");
  gHaApps->Add( HRSL );

  //Parity Data
  gHaApps->Add(new ParityData("P","HAPPEX Data"));
      
  TriFadcRasteredBeam* Lrb = new TriFadcRasteredBeam("Lrb", "Rastered beam to LHRS");
  gHaApps->Add(Lrb);   

  THaPhysicsModule* EK_l = new THaElectronKine("EK_L",
					       "Electron kinematics in HRS-L",
					       "L",mass_tg);
  gHaPhysics->Add( EK_l );
  gHaPhysics->Add( new THaGoldenTrack( "L.gold", "HRS-L Golden Track", "L" ));


  // VDC efficiency module for OnlineGUI
  THaPhysicsModule *Lvdceff = new TriVDCeff("L.vdceff" ,"Left vdc efficiency");
  gHaPhysics->Add( Lvdceff );

  THaScalerEvtHandler *lscaler = new THaScalerEvtHandler("Left","HA scaler event type 140");
  lscaler->SetDebugFile("LeftScaler.txt");
  gHaEvtHandlers->Add (lscaler);

  THaAnalyzer* analyzer = new THaAnalyzer;
      
  THaEvent* event = new THaEvent;
  for (Int_t nsplit=0;nsplit<1;nsplit++){  

    char infile[300];
    sprintf(infile,"/adaq1/data1/prexLHRS_%d.dat.%d",runNo,nsplit);
    cout << "replay: Try file "<< infile << endl;

    THaRun *run;
    run = new THaRun(infile);
    // run->SetDataRequired( THaRunBase::kDate );
    TDatime now;
    run->SetDate( now );
    run->SetDataRequired( 0 );  // it was: ( THaRunBase::kDate );

    analyzer->EnableBenchmarks();
    analyzer->SetEvent( event );

    char outname[300];
    sprintf(outname,"/chafs1/work1/prex_counting/prexLHRS_%d_%d.root",runNo, lastevt);

    analyzer->SetOutFile( outname );
    analyzer->SetCutFile("onlana.cuts");
    analyzer->SetOdefFile("output_online.def");
    analyzer->SetSummaryFile("summary_example.log"); // optional

    run->SetLastEvent(lastevt);   // Number of events to process
    analyzer->Process(*run);
  }    

  return;
}
