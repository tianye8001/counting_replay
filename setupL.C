R__LOAD_LIBRARY(../ParityData/libParity.so)

using namespace std;
void setupL(Int_t runNo=0, Int_t lastevt=-1){
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

  THaApparatus* HRSL = new THaHRS("L","Left arm HRS");
  gHaApps->Add( HRSL );

  // done in rootlogon.C:  gSystem->Load("libParity.so");
  gHaApps->Add(new ParityData("P","HAPPEX Data"));



  // e-p scattering
  Double_t amu = 931.494*1.e-3;  // amu to GeV
  //Double_t he4 = 4*amu;
  Double_t pb208 = 208*amu;
  
  //Double_t mass_tg  = he4; // Helium
  Double_t mass_tg  = pb208; // Helium

  // Electron kinematics
  THaPhysicsModule* EK_l = new THaElectronKine("EK_L",
					       "Electron kinematics in HRS-L",
					       "L",mass_tg);
  
  gHaPhysics->Add( EK_l );

  gHaPhysics->Add( new THaGoldenTrack( "L.gold", "HRS-L Golden Track", "L" ));


  THaScalerEvtHandler *lscaler = new THaScalerEvtHandler("Left","HA scaler event type 140");
  lscaler->SetDebugFile("LeftScaler.txt");
  gHaEvtHandlers->Add (lscaler);



  THaAnalyzer* analyzer = new THaAnalyzer;
  
  THaEvent* event = new THaEvent;
  for (Int_t nsplit=0;nsplit<6;nsplit++){  
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
  sprintf(outname,"/chafs1/work1/prex_counting/prexLHRS_%d_%d.root",runNo, lastevt);
  analyzer->SetOutFile( outname );
  analyzer->SetCutFile("onlana.cuts");
  analyzer->SetOdefFile("output.def");
   analyzer->SetSummaryFile("summary_example.log"); // optional
//
  run->SetLastEvent(lastevt);   // Number of events to process
//  run->SetLastEvent(100);   // Number of events to process
  analyzer->Process(*run);
  }
}
