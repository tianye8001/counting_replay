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
 
 TSRight->Draw("RightS0A_r:RightLclock>>scaler_S0A","evcount>5");
 scaler_S0A = (TH2F *)gDirectory->Get("scaler_S0A");
 TSRight->Draw("RightS0B_r:RightLclock>>scaler_S0B","evcount>5");
 scaler_S0B = (TH2F *)gDirectory->Get("scaler_S0B");
 TSRight->Draw("RightS3_r:RightLclock>>scaler_S3","evcount>5");
 scaler_S3 = (TH2F *)gDirectory->Get("scaler_S3");
 TSRight->Draw("RightUQ_r:RightLclock>>scaler_UQ","evcount>5");
 scaler_UQ = (TH2F *)gDirectory->Get("scaler_UQ");
 TSRight->Draw("RightDQ_r:RightLclock>>scaler_DQ","evcount>5");
 scaler_DQ = (TH2F *)gDirectory->Get("scaler_DQ");
 TSRight->Draw("RightAT1_r:RightLclock>>scaler_AT1","evcount>5");
 scaler_UQ = (TH2F *)gDirectory->Get("scaler_AT1");
 TSRight->Draw("RightAT2_r:RightLclock>>scaler_AT2","evcount>5");
 scaler_DQ = (TH2F *)gDirectory->Get("scaler_AT2");

 TSRight->Draw("RightT1_r:RightLclock>>scaler_T1","evcount>5");
 scaler_T1 = (TH2F *)gDirectory->Get("scaler_T1");
 TSRight->Draw("RightT2_r:RightLclock>>scaler_T2","evcount>5");
 scaler_T2 = (TH2F *)gDirectory->Get("scaler_T2");
 TSRight->Draw("RightT3_r:RightLclock>>scaler_T3","evcount>5");
 scaler_T3 = (TH2F *)gDirectory->Get("scaler_T3");
 TSRight->Draw("RightT4_r:RightLclock>>scaler_T4","evcount>5");
 scaler_T4 = (TH2F *)gDirectory->Get("scaler_T4");
 TSRight->Draw("RightT5_r:RightLclock>>scaler_T5","evcount>5");
 scaler_T5 = (TH2F *)gDirectory->Get("scaler_T5");
 TSRight->Draw("RightT6_r:RightLclock>>scaler_T6","evcount>5");
 scaler_T6 = (TH2F *)gDirectory->Get("scaler_T6");
 TSRight->Draw("RightLclock_r:RightLclock>>scaler_T8","evcount>5");
 scaler_T7 = (TH2F *)gDirectory->Get("scaler_T8");



 TCanvas *c1 = new TCanvas("c1","c1",1000,1000);
 c1->Divide(2,4);
 c1->cd(1);
 scaler_S0A->SetMarkerStyle(20);
 scaler_S0A->SetMarkerSize(2);
 scaler_S0A->Draw("p*");
 scaler_S0A->GetYaxis()->SetTitle("Hz");
 c1->cd(2);
 scaler_S0B->SetMarkerStyle(20);
 scaler_S0B->SetMarkerSize(2);
 scaler_S0B->Draw("p*");

 c1->cd(3);
 scaler_S3->SetMarkerStyle(20);
 scaler_S3->SetMarkerSize(2);
 scaler_S3->Draw("p*");
 c1->cd(4);
 scaler_UQ->SetMarkerStyle(20);
 scaler_UQ->SetMarkerSize(2);
 scaler_UQ->Draw("p*");
 c1->cd(5);
 scaler_DQ->SetMarkerStyle(20);
 scaler_DQ->SetMarkerSize(2);
 scaler_DQ->Draw("p*");
 c1->cd(6);
 scaler_AT1->SetMarkerStyle(20);
 scaler_AT1->SetMarkerSize(2);
 scaler_AT1->Draw("p*");
 c1->cd(7);
 scaler_AT2->SetMarkerStyle(20);
 scaler_AT2->SetMarkerSize(2);
 scaler_AT2->Draw("p*");
 c1->SaveAs("RightDetectors_rate.pdf");

 TCanvas *c2 = new TCanvas("c2","c2",1000,1000);
 c2->Divide(2,3);
 c2->cd(1);
 scaler_T1->SetMarkerStyle(20);
 scaler_T1->SetMarkerSize(2);
 scaler_T1->Draw("p*");
 c2->cd(2);
 scaler_T2->SetMarkerStyle(20);
 scaler_T2->SetMarkerSize(2);
 scaler_T2->Draw("p*");

 c2->cd(3);
 scaler_T3->SetMarkerStyle(20);
 scaler_T3->SetMarkerSize(2);
 scaler_T3->Draw("p*");
 c2->cd(4);
 scaler_T4->SetMarkerStyle(20);
 scaler_T4->SetMarkerSize(2);
 scaler_T4->Draw("p*");
 c2->cd(5);
 scaler_T5->SetMarkerStyle(20);
 scaler_T5->SetMarkerSize(2);
 scaler_T5->Draw("p*");
 c2->cd(6);
 scaler_T6->SetMarkerStyle(20);
 scaler_T6->SetMarkerSize(2);
 scaler_T6->Draw("p*");
 c2->SaveAs("RightTriggers_rate.pdf");

}
