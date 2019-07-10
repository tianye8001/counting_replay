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

// Trigger choice : 
//   T1 = scintillator S0 trigger
//   T5 = upper scintillator (above quartz) 

 sprintf(ctrig1,"fEvtHdr.fEvtType==%d",1);
 sprintf(ctrig5,"fEvtHdr.fEvtType==%d",5);

// HRS = R.* or L.*

// only one cluster in each VDC plane
sprintf(vdccut,"R.vdc.u1.nclust==1&&R.vdc.v1.nclust==1&&R.vdc.u2.nclust==1&&R.vdc.v2.nclust==1");

// track points to target; avoid wildly wrong tracks
sprintf(tgtcut,"R.gold.th>-0.08&&R.gold.th<0.08&&R.gold.ph>-0.05&&R.gold.ph<0.05");

sprintf(cand,"&&");

// Build the total cut1 and cut5 

strcpy(ccut1,ctrig1);
strcat(ccut1,cand);
strcat(ccut1,vdccut);
strcat(ccut1,cand);
strcat(ccut1,tgtcut);

strcpy(ccut5,ctrig5);
strcat(ccut5,cand);
strcat(ccut5,vdccut);
strcat(ccut5,cand);
strcat(ccut5,tgtcut);

cout << "Cuts available : "<<endl;
cout << ccut1<<endl;
cout << ccut5<<endl;

// We are more interested in trigger 5 for PREX

 TH1F *hqsq = new TH1F("hqsq","Right HRS Qsq for trigger 5",100,0,0.025);
 T->Draw("EK_R.Q2>>hqsq",ccut1);

}
