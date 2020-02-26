{

// Macro to Qsq 

   gROOT->Reset();

   gStyle->SetOptStat(1);
   gStyle->SetStatH(0.3);
   gStyle->SetStatW(0.3);
   gStyle->SetTitleH(0.09);
   gStyle->SetTitleW(0.3);
   gStyle->SetLabelSize(0.04,"x");
   gStyle->SetLabelSize(0.04,"y");
   gROOT->ForceStyle();

// "gold" track is at the target.  For more info, see
// http://hallaweb/podd/doc/variables.html

   char ctrig1[50],ctrig5[50];
   char vdccut[200],tgtcut[200],tgty[200];
   char ccut1[800],ccut5[800],cand[5];
   char qtz[200],momc[200];

// Trigger choice : 
//   T1 = scintillator S0 trigger
//   T2 = upper scintillator (above quartz) 

 sprintf(ctrig1,"fEvtHdr.fEvtType==%d",1);

// HRS = R.* or L.*
   //TFile *_file0 = TFile::Open("AfileL.root");

// only one cluster in each VDC plane
sprintf(vdccut,"L.vdc.u1.nclust==1&&L.vdc.v1.nclust==1&&L.vdc.u2.nclust==1&&L.vdc.v2.nclust==1");

// track points to target; avoid wildly wrong tracks
sprintf(tgtcut,"L.gold.th>-0.08&&L.gold.th<0.08&&L.gold.ph>-0.05&&L.gold.ph<0.05");

// Quartz cut 
sprintf(qtz,"P.loQadcL>640");
sprintf(momc,"L.gold.dp>-0.006&&L.gold.dp<-0.002");

sprintf(cand,"&&");

// Build the total cut1 and cut2 

strcpy(ccut1,ctrig1);
strcat(ccut1,cand);
strcat(ccut1,vdccut);
strcat(ccut1,cand);
strcat(ccut1,tgtcut);
strcat(ccut1,cand);
strcat(ccut1,qtz);
strcat(ccut1,cand);
strcat(ccut1,momc);

cout << "Cut  : "<<endl;
cout << ccut1<<endl;

// We are more interested in trigger 1 for PREX-II

 TH1F *hqsq = new TH1F("hqsq","Left HRS Qsq",200,0.0012,0.026);

 //  T->Draw("P.q2L>>hqsq",ccut1);

    T->Draw("EK_L.Q2>>hqsq",ccut1);

}
