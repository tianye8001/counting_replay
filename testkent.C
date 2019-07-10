{



  gROOT->Reset();

  gStyle->SetOptStat(0);
  gStyle->SetStatH(0.3);
  gStyle->SetStatW(0.3);
  gStyle->SetTitleH(0.09);
  gStyle->SetTitleW(0.3);
  gStyle->SetLabelSize(0.04,"x");
  gStyle->SetLabelSize(0.04,"y");
  gROOT->ForceStyle();

TString ctrig = "(fEvtHdr.fEvtType==1)";
TString vdccut = "(R.vdc.u1.nclust==1&&R.vdc.v1.nclust==1&&R.vdc.u2.nclust==1&&R.vdc.v2.nclust==1)";
TString trcut = "(R.tr.th[0]<0.05&&R.tr.th[0]>-0.2&&R.tr.ph[0]<0.1&&R.tr.ph[0]>-0.1)";
TString ccut = ctrig + "&&" + vdccut  + "&&" + trcut;

TString ydetstr = "R.tr.y[0]+0.9*R.tr.ph[0]";
TString xdetstr = "R.tr.x[0]+0.9*R.tr.th[0]";

 T->SetAlias("dety",ydetstr.Data());

} 
