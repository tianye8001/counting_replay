{ 
// Macro to plot right scaler plots

   gROOT->Reset();

   gStyle->SetOptStat(0);
   gStyle->SetStatH(0.3);
   gStyle->SetStatW(0.3);

   gStyle->SetTitleH(0.1);
   gStyle->SetTitleW(0.3);
   gROOT->ForceStyle();

   // TString cut_t1 = "fEvtHdr,fEvtType==1";
   // TString cut_clock = TCanvas;

   // " *c2 = new TCanvas("c2","c2",1200,600);
   // c2->Divide(2,1);
   // c2->cd(1);
   // T->Draw("P.upQadcR",cut_1);

   // T->Draw("P.upQadcR",cut_clock,"same");

   // c2->cd(2);
   // T->Draw("P.loQadcR");
   // T->Draw("P.upQadcR","","same");

   // TCanvas *c3 = new TCanvas("c3","c3",1200,600);
   // c3->Divide(2,1);
   // c3->cd(1);
   // T->Draw("P.fadcUQR");
   // c3->cd(2);
   // T->Draw("P.fadcDQR");

   
   char ctrig[200],vdccut[200],tgtcut[200],tgty[200],ccut[800],ccut1[800],cand[5];
   char trcut[200];
   char adccut[200];

  sprintf(ctrig,"fEvtHdr.fEvtNum<200000&&(fEvtHdr.fEvtType==1)");
  // HRS = R.* or L.*

  // only one cluster in each VDC plane
  sprintf(vdccut,"L.vdc.u1.nclust==1&&L.vdc.v1.nclust==1&&L.vdc.u2.nclust==1&&L.vdc.v2.nclust==1");
  sprintf(cand,"&&");
  sprintf(trcut,"(L.tr.th[0]<0.05&&L.tr.th[0]>-0.2&&L.tr.ph[0]<0.1&&L.tr.ph[0]>-0.1)");
  sprintf(adccut,"P.fadcUQL>24300&&P.upQadcL>510");
  // Build the total cut
  strcpy(ccut,ctrig);
  strcat(ccut,cand);
  strcat(ccut,vdccut);
  strcat(ccut,cand);
  strcat(ccut,trcut);

  strcat(ccut1,ccut);
  strcat(ccut1,cand);
  strcat(ccut1,adccut);
  
  TCanvas *c1 = new TCanvas("c1","c1",1200,600);
  c1->Divide(2,1);
  c1->cd(1);
  T->Draw("L.tr.y[0]+0.9*L.tr.ph[0]", ccut); 
  T->Draw("L.tr.y[0]+0.9*L.tr.ph[0]", ccut1, "same"); 


  c1->cd(2);
  T->Draw("L.tr.x[0]+0.9*L.tr.th[0]", ccut); 
  T->Draw("L.tr.x[0]+0.9*L.tr.th[0]", ccut1, "same"); 
  // TH1D* h2_buff = (TH1D*)gDirectory->FindObject("htemp");
  // h2_buff->SetLineColor(kRed);

  TCanvas *c2 = new TCanvas("c2","c2",1200,600);
  c2->Divide(2,1);
  c2->cd(1);
  T->Draw("L.tr.x[0]+0.9*L.tr.th[0]:L.tr.y[0]+0.9*L.tr.ph[0]>>h(100,-.035,-.005,-.2,.1)", ccut1,"colz"); 
  c2->cd(2);



}
