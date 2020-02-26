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

 char ctrig[200],vdccut[200],tgtcut[200],tgty[200],ccut[800],cand[5];

 Int_t runnum;
 runnum = (int)T->GetMaximum("fEvtHdr.fRun");


 sprintf(ctrig,"fEvtHdr.fEvtNum<600000");
 // sprintf(ctrig,"(fEvtHdr.fEvtType==1||fEvtHdr.fEvtType==5)");

// HRS = R.* or L.*

// only one cluster in each VDC plane
sprintf(vdccut,"R.vdc.u1.nclust==1&&R.vdc.v1.nclust==1&&R.vdc.u2.nclust==1&&R.vdc.v2.nclust==1");

sprintf(cand,"&&");

// Build the total cut

strcpy(ccut,ctrig);
strcat(ccut,cand);
strcat(ccut,vdccut);

cout << "Cuts used : "<<endl;

cout << ccut << endl;

double scale,Q1scale;

 cout << "Septum scale (%), Q1 scale (%)?" << endl;
 cin >> scale >> Q1scale;

//TH2F *htgthph = new TH2F("htgthph","Target theta-phi (theta vertical)",100,-0.06,0.06,100,-0.1,0.1);

 TCanvas c1;
 TH2F *htgthph = new TH2F("htgthph",Form("Target theta-phi (theta vertical) (Run %i) Septum %.1f Percent, Q1 %.1f Percent",runnum,scale,Q1scale),200,-0.03,0.03,200,-0.07,0.07);

 T->Draw("R.gold.th:R.gold.ph>>htgthph",ccut,"COLZ");

 gPad->SetGridx(1);
 gPad->SetGridy(1);
 c1.SaveAs(Form("RightSieve_%i.pdf",runnum));

 // TCanvas c2;
 // TH1F* hproj = new TH1F("hproj", "Projection on the quartz plane", 300, -0.15, 0.15);
 // T->Draw("R.tr.y[0]+0.9*R.tr.ph[0]", "abs(R.tr.y[0]+0.9*R.tr.ph[0])<0.1");

 TCut cut1="abs(R.tr.y[0]+1.0*R.tr.ph[0])<0.12 && abs(R.tr.y[0]+0.0*R.tr.ph[0])<0.12 && abs(R.tr.x[0])<0.1 && abs(R.tr.x[0]-0.02)<0.1 && abs(R.tr.ph[0])<0.01";

 TCanvas c3("c3","c3", 1000, 400);
 c3.Divide(2,1);
 c3.cd(1);
 TH2F *hsieve = new TH2F("hsieve","R.tr.x[0]+0.2*R.tr.th[0]:R.tr.y[0]+0.2*R.tr.ph[0]",200,-0.05,0.05,200,-0.15,0.15);
 T->Draw("R.tr.x[0]+0.2*R.tr.th[0]:R.tr.y[0]+0.2*R.tr.ph[0]>>hsieve",cut1,"colz");
 gPad->SetGridx(1);
 gPad->SetGridy(1);

 c3.cd(2);
 hsieve->Draw();
 gPad->SetGridx(1);
 gPad->SetGridy(1);

}
