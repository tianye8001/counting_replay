{ 
// Macro to plot left scaler plots

   gROOT->Reset();

   gStyle->SetOptStat(0);
   gStyle->SetStatH(0.3);
   gStyle->SetStatW(0.3);


   gStyle->SetTitleH(0.09);
   gStyle->SetTitleW(0.3);
   gStyle->SetLabelSize(0.04,"x");
   gStyle->SetLabelSize(0.04,"y");
   gROOT->ForceStyle();

// TCanvas c0;

// TH2F *scaler_S0A = new TH1F("scaler_S0A","S0A rate vs clock",400,300,700);
// TH2F *scaler_S0B = new TH1F("scaler_S0B","S0B rate vs clock",1700,300,2000);
 
 T->Draw("P.upScitdcR>>FBTDC_S0A");
 FBTDC_S0A = (TH1F *)gDirectory->Get("FBTDC_S0A");
 T->Draw("P.loScitdcR>>FBTDC_S0B");
 FBTDC_S0B = (TH1F *)gDirectory->Get("FBTDC_S0B");
 T->Draw("P.upSciadcR>>FBADC_S0A");
 FBADC_S0A = (TH1F *)gDirectory->Get("FBADC_S0A");
 T->Draw("P.loSciadcR>>FBADC_S0B");
 FBADC_S0B = (TH1F *)gDirectory->Get("FBADC_S0B");
 T->Draw("P.upSciadcR:0.5*(P.upScitdcR-P.loScitdcR)>>FBS0A_ADCDiffTDC");
 FBS0A_ADCDiffTDC = (TH2F *)gDirectory->Get("FBS0A_ADCDiffTDC");
 T->Draw("P.loSciadcR:0.5*(P.upScitdcR-P.loScitdcR)>>FBS0B_ADCDiffTDC");
 FBS0B_ADCDiffTDC = (TH2F *)gDirectory->Get("FBS0B_ADCDiffTDC");
 T->Draw("0.5*(P.upScitdcR-P.loScitdcR)>>FBS0_DiffTDC");
 FBS0_DiffTDC = (TH1F *)gDirectory->Get("FBS0_DiffTDC");

 T->Draw("R.vdc.u1.time:R.vdc.u1.wire>>VDC_u1");
 VDC_u1 = (TH2F *)gDirectory->Get("VDC_u1");
 T->Draw("R.vdc.v1.time:R.vdc.v1.wire>>VDC_v1");
 VDC_v1 = (TH2F *)gDirectory->Get("VDC_v1");
 T->Draw("R.vdc.u2.time:R.vdc.u2.wire>>VDC_u2");
 VDC_u2 = (TH2F *)gDirectory->Get("VDC_u2");
 T->Draw("R.vdc.v2.time:R.vdc.v2.wire>>VDC_v2");
 VDC_v2 = (TH2F *)gDirectory->Get("VDC_v2");

 T->Draw("R.vdc.u1.wire>>VDChit_u1");
 VDChit_u1 = (TH1F *)gDirectory->Get("VDChit_u1");
 T->Draw("R.vdc.v1.wire>>VDChit_v1");
 VDChit_v1 = (TH1F *)gDirectory->Get("VDChit_v1");
 T->Draw("R.vdc.u2.wire>>VDChit_u2");
 VDChit_u2 = (TH1F *)gDirectory->Get("VDChit_u2");
 T->Draw("R.vdc.v2.wire>>VDChit_v2");
 VDChit_v2 = (TH1F *)gDirectory->Get("VDChit_v2");

 T->Draw("R.vdc.u1.time>>VDCTDC_u1");
 VDCTDC_u1 = (TH1F *)gDirectory->Get("VDCTDC_u1");
 T->Draw("R.vdc.v1.time>>VDCTDC_v1");
 VDCTDC_v1 = (TH1F *)gDirectory->Get("VDCTDC_v1");
 T->Draw("R.vdc.u2.time>>VDCTDC_u2");
 VDCTDC_u2 = (TH1F *)gDirectory->Get("VDCTDC_u2");
 T->Draw("R.vdc.v2.time>>VDCTDC_v2");
 VDCTDC_v2 = (TH1F *)gDirectory->Get("VDCTDC_v2");


 T->Draw("R.vdc.u1.time:0.5*(P.upScitdcR-P.loScitdcR)>>VDC_u1_S0");
 VDC_u1_S0 = (TH2F *)gDirectory->Get("VDC_u1_S0");
 T->Draw("R.vdc.v1.time:0.5*(P.upScitdcR-P.loScitdcR)>>VDC_v1_S0");
 VDC_v1_S0 = (TH2F *)gDirectory->Get("VDC_v1_S0");
 T->Draw("R.vdc.u2.time:0.5*(P.upScitdcR-P.loScitdcR)>>VDC_u2_S0");
 VDC_u2_S0 = (TH2F *)gDirectory->Get("VDC_u2_S0");
 T->Draw("R.vdc.v2.time:0.5*(P.upScitdcR-P.loScitdcR)>>VDC_v2_S0");
 VDC_v2_S0 = (TH2F *)gDirectory->Get("VDC_v2_S0");


 TCanvas *c1 = new TCanvas("c1","c1",1000,1000);
 c1->Divide(2,3);
 c1->cd(3);
 FBTDC_S0A->Draw();
 c1->cd(4);
 FBTDC_S0B->Draw();
 c1->cd(1);
 FBADC_S0A->Draw();
 c1->cd(2);
 FBADC_S0B->Draw();
 c1->cd(5);
 FBS0_DiffTDC->Draw();
 TCanvas *c11 = new TCanvas("c11","c11",1000,1000);
 c11->Divide(1,2);
 c11->cd(1);
 FBS0A_ADCDiffTDC->Draw("COLZ");
 c11->cd(2);
 FBS0B_ADCDiffTDC->Draw("COLZ");

 TCanvas *c2 = new TCanvas("c2","c2",1000,1000);
 c2->Divide(2,2);
 c2->cd(1);
 VDChit_u1->Draw();
 c2->cd(2);
 VDChit_v1->Draw();
 c2->cd(3);
 VDChit_u2->Draw();
 c2->cd(4);
 VDChit_v2->Draw();
// c2->SaveAs("ReftTriggers_rate.pdf");

 TCanvas *c3 = new TCanvas("c3","c3",1000,1000);
 c3->Divide(2,2);
 c3->cd(1);
 VDCTDC_u1->Draw();
 c3->cd(2);
 VDCTDC_v1->Draw();
 c3->cd(3);
 VDCTDC_u2->Draw();
 c3->cd(4);
 VDCTDC_v2->Draw();

 TCanvas *c4 = new TCanvas("c4","c4",1000,1000);
 c4->Divide(1,4);
 c4->cd(1);
 VDC_u1->Draw();
 c4->cd(2);
 VDC_v1->Draw();
 c4->cd(3);
 VDC_u2->Draw();
 c4->cd(4);
 VDC_v2->Draw();

 TCanvas *c5 = new TCanvas("c5","c5",1000,1000);
 c5->Divide(2,2);
 c5->cd(1);
 VDC_u1_S0->Draw("COLZ");
 c5->cd(2);
 VDC_v1_S0->Draw("COLZ");
 c5->cd(3);
 VDC_u2_S0->Draw("COLZ");
 c5->cd(4);
 VDC_v2_S0->Draw("COLZ");


}
