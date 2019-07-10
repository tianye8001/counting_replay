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
TString vdccut = "(L.vdc.u1.nclust==1&&L.vdc.v1.nclust==1&&L.vdc.u2.nclust==1&&L.vdc.v2.nclust==1)";
TString trcut = "(L.tr.th[0]<0.05&&L.tr.th[0]>-0.2&&L.tr.ph[0]<0.1&&L.tr.ph[0]>-0.1)";
 TString tgcut = "(L.tr.tg_th[0]<0.06&&L.tr.tg_th[0]>-0.05&&L.tr.tg_ph[0]>-0.005&&L.tr.tg_ph[0]<0.03)";

TString ccut = ctrig + "&&" + vdccut  + "&&" + trcut + "&&" + tgcut;

TString ydetstr = "L.tr.y[0]+0.9*L.tr.ph[0]";
TString xdetstr = "L.tr.x[0]+0.9*L.tr.th[0]";

 T->SetAlias("dety",ydetstr.Data());
 T->SetAlias("detx",xdetstr.Data());

} 
