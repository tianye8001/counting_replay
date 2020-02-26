{ 
// Macro to plot several variables

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
//  PREX  want T5
//  GMp run 21283 or 21284 wants T1

 int itrig = 5;
 sprintf(ctrig,"fEvtHdr.fEvtType==%d",itrig);

// HRS = R.* or L.*

// only one cluster in each VDC plane
sprintf(vdccut,"L.vdc.u1.nclust==1&&L.vdc.v1.nclust==1&&L.vdc.u2.nclust==1&&L.vdc.v2.nclust==1");

// track points to target; avoid wildly wrong tracks
sprintf(tgtcut,"L.gold.th>-0.08&&L.gold.th<0.08&&L.gold.ph>-0.05&&L.gold.ph<0.05");

// Target Y cuts
sprintf(tgty,"L.tr.tg_y>-0.05&&L.tr.tg_y<0.01");

sprintf(cand,"&&");

// Build the total cut

strcpy(ccut,ctrig);
strcat(ccut,cand);
strcat(ccut,vdccut);
strcat(ccut,cand);
strcat(ccut,tgtcut);
strcat(ccut,cand);
strcat(ccut,tgty);

cout << "Cuts used : "<<endl;

 TCanvas c0;

cout << ccut << endl;

TH2F *htgthph = new TH2F("htgthph","Target theta-phi (theta vertical)",100,-0.06,0.06,100,-0.1,0.1);

T->Draw("L.gold.th:L.gold.ph>>htgthph",ccut);

TH1F *htgth = new TH1F("htgth","Target theta (vert)",100,-0.08,0.08);
T->Draw("L.gold.th>>htgth",ccut);

TH1F *htgph = new TH1F("htgph","Target phi (horiz)",100,-0.04,0.04);
T->Draw("L.gold.ph>>htgph",ccut);

TH1F *hfpx = new TH1F("hfpx","Focal plane X (vert)",100,-1,1);
T->Draw("L.tr.x>>hfpx",ccut);

TH1F *hfpy = new TH1F("hfpy","Focal plane Y (horiz)",100,-0.1,0.1);
T->Draw("L.tr.y>>hfpy",ccut);

TH1F *hfpdp = new TH1F("hdp","Fractional momentum dP",100,-0.1,0.04);
T->Draw("L.gold.dp>>hdp",ccut);

TH1F *htgty = new TH1F("htgty","Target Y distribution",100,-0.1,0.1);
T->Draw("L.tr.tg_y>>htgty",tgtcut);


 TCanvas c1;

 c1->Divide(2,2);
 c1->cd(1);

 htgthph->Draw();

 c1->cd(2);
 htgth->Draw();

 c1->cd(3);
 htgph->Draw();

 c1->cd(4);
 hfpx->Draw();

 TCanvas c2;

 c2->Divide(2,2);
 c2->cd(1);

 hfpy->Draw();

 c2->cd(2);
 hdp->Draw();

 c2->cd(3);
 htgty->Draw();


}
