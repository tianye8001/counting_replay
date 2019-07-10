{ 
// Macro to plot sieve pattern

   gROOT->Reset();

   gStyle->SetOptStat(0);
   gStyle->SetStatH(0.3);
   gStyle->SetStatW(0.3);


   gStyle->SetTitleH(0.09);
   gStyle->SetTitleW(0.3);
   gStyle->SetLabelSize(0.04,"x");
   gStyle->SetLabelSize(0.04,"y");
   gROOT->ForceStyle();

// "gold" track is at the target.  For more info, see
// http://hallaweb/podd/doc/variables.html

 char ctrig[50],vdccut[200],tgtcut[200],tgty[200],ccut[800],cand[5];

// Trigger choice : scintillator trigger
//  HAPPEXII want T1(R-HRS) or T3(L-HRS)
//  HAPPEXIII want T2
//  PREX  want T5 but we'd probably rather use T1 -- it is S0 trigger
//  GMp run 21283 or 21284 wants T1

// int itrig = 5;
 // sprintf(ctrig,"fEvtHdr.fEvtType==%d",itrig);
 //sprintf(ctrig,"fEvtHdr.fEvtNum<20000&&(fEvtHdr.fEvtType==1||fEvtHdr.fEvtType==5)");
 sprintf(ctrig,"fEvtHdr.fEvtNum<200000  && fEvtHdr.fEvtType==1");
// HRS = R.* or L.*

// only one cluster in each VDC plane
sprintf(vdccut,"L.vdc.u1.nclust==1&&L.vdc.v1.nclust==1&&L.vdc.u2.nclust==1&&L.vdc.v2.nclust==1");

sprintf(cand,"&&");

// Build the total cut

// data was taken only with T1, remove evttype cut for now (Sanghwa)
strcpy(ccut,ctrig);
strcat(ccut,cand);
strcat(ccut,vdccut);

cout << "Cuts used : "<<endl;

 TCanvas c0;

cout << ccut << endl;

 TH2F *htgthph = new TH2F("htgthph","Target theta-phi (theta vertical)",200,-0.03,0.035,200,-0.07,0.07);



T->Draw("L.gold.th:L.gold.ph>>htgthph",ccut,"colz");
//htgthph->Draw("colz");

 TCanvas c2;

 TCut cut1= "abs(L.tr.y[0]+1.0*L.tr.ph[0]+0.03)<0.07 && abs(L.tr.y[0]+0.0*L.tr.ph[0]-0.03)<0.15 && abs(L.tr.x[0])<0.2 &&  abs(L.tr.x[0]-0.02)<0.2  &&abs(L.tr.ph[0])<0.1";
cout << ccut << endl;

 TH2F *hsieve = new TH2F("hsieve","",200,-0.05,0.0,200,-0.04,0.08);
 //TH2F *htgthph = new TH2F("htgthph","Target theta-phi (theta vertical)",200,-0.01,0.035,200,-0.04,0.04);


T->Draw("L.tr.x[0]+0.2*L.tr.th[0]:L.tr.y[0]+0.2*L.tr.ph[0]>>hsieve",cut1,"colz");
hsieve->Draw("colz");
}
