{ 
// Macro to plot left scaler plots

   gROOT->Reset();

   gStyle->SetOptStat(0);
   gStyle->SetStatH(0.3);
   gStyle->SetStatW(0.3);


   gStyle->SetTitleH(0.1);
   gStyle->SetTitleW(0.3);
   gStyle->SetLabelSize(0.08,"x");
   gStyle->SetLabelSize(0.08,"y");
   gROOT->ForceStyle();

 char ctrig1[200],ctrig1cut[200],ctrig2[200],ctrig3[199],ctrig4[200],ctrig5[200];
 char ccutUPQ[799],ccutDNQ[800];

  sprintf(ccutUPQ,"fEvtHdr.fEvtType==1 && P.upQadcL>500 && ((L.tr.x+L.tr.th*0.9)>-0.16 && (L.tr.x+L.tr.th*0.9)<0.16) && ((L.tr.y+L.tr.ph*0.9)>-0.04 && (L.tr.x+L.tr.th*0.9)<0.04)");

  sprintf(ccutDNQ,"fEvtHdr.fEvtType==1 && P.loQadcL>>600 && ((L.tr.x+L.tr.th*1.05)>-0.16 && (L.tr.x+L.tr.th*1.05)<0.16) && ((L.tr.y+L.tr.ph*1.05)>-0.04 && (L.tr.x+L.tr.th*1.05)<0.04)");

// sprintf(ctrig,"P.evtype==1");
sprintf(ctrig1,"(P.evtypebits&2)==2");
sprintf(ctrig2,"(P.evtypebits&4)==4");
sprintf(ctrig4,"(P.evtypebits&16)==16");
sprintf(ctrig5,"(P.evtypebits&32)==32");
sprintf(ctrig1cut,"(P.evtypebits&2)==2 && P.S0AtdcL>400");

// TCanvas c0;

// TH2F *scaler_S0A = new TH1F("scaler_S0A","S0A rate vs clock",400,300,700);
// TH2F *scaler_S0B = new TH1F("scaler_S0B","S0B rate vs clock",1700,300,2000);
// TH1F *FBADC_S0A = new TH1F("S0A","S0A",1700,300,2000); 
 T->Draw("P.S0BtdcL>>FBTDC_S0B(500,0,3500)",ctrig1);
 FBTDC_S0B = (TH1F *)gDirectory->Get("FBTDC_S0B");
 T->Draw("P.S0AtdcL>>FBTDC_S0A(500,0,3500)",ctrig1);
 FBTDC_S0A = (TH1F *)gDirectory->Get("FBTDC_S0A");
 T->Draw("P.S0BadcL>>FBADC_S0B(500,0,14000)",ctrig1);
 FBADC_S0B = (TH1F *)gDirectory->Get("FBADC_S0B");
 T->Draw("P.S0AadcL>>FBADC_S0A(500,0,14000)",ctrig1);
 FBADC_S0A = (TH1F *)gDirectory->Get("FBADC_S0A");

 T->Draw("P.fadcS0AL>>FADC_S0A(500,0,70000)",ctrig1);
 FADC_S0A = (TH1F *)gDirectory->Get("FADC_S0A");
 T->Draw("P.fadcS0BL>>FADC_S0B(500,0,70000)",ctrig1);
 FADC_S0B = (TH1F *)gDirectory->Get("FADC_S0B");


 T->Draw("P.S3tdcL>>FBTDC_S3(500,0,3500)",ctrig2);
 FBTDC_S3 = (TH1F *)gDirectory->Get("FBTDC_S3");
 T->Draw("P.S3adcL>>FBADC_S3(500,0,7000)",ctrig2);
 FBADC_S3 = (TH1F *)gDirectory->Get("FBADC_S3");

 T->Draw("P.QLIfadcS0B>>FADC_S0B(500,0,70000)",ctrig1);
 FADC_S0B = (TH1F *)gDirectory->Get("FADC_S0B");
 T->Draw("P.QLIfadcS0A>>FADC_S0A(500,0,70000)",ctrig1);
 FADC_S0A = (TH1F *)gDirectory->Get("FADC_S0A");

 T->Draw("P.QLIfadcS3>>FADC_S3(500,0,70000)",ctrig2);
 FADC_S3 = (TH1F *)gDirectory->Get("FADC_S3");
 
 T->Draw("P.upQtdcL>>FBTDC_UQ",ctrig4);
 FBTDC_UQ = (TH1F *)gDirectory->Get("FBTDC_UQ");
 T->Draw("P.loQtdcL>>FBTDC_DQ",ctrig5);
 FBTFBTDDC_DQ = (TH1F *)gDirectory->Get("FBTDC_DQ");
 T->Draw("P.upQadcL>>FBADC_UQ(500,0,2000)",ctrig4);
 FBADC_UQ = (TH1F *)gDirectory->Get("FBADC_UQ");
 T->Draw("P.loQadcL>>FBADC_DQ(500,0,2000)",ctrig5);
 FBADC_DQ = (TH1F *)gDirectory->Get("FBADC_DQ");

 T->Draw("P.QLIfadcup>>FADC_UP(500,0,25000)",ctrig4);
 FADC_UP = (TH1F *)gDirectory->Get("FADC_UP");
 T->Draw("P.QLIfadclo>>FADC_DN(500,0,25000)",ctrig5);
 FADC_DN = (TH1F *)gDirectory->Get("FADC_DN");


 T->Draw("P.upQtdcL>>FBTDC_UQ1",ctrig1);
 FBTDC_UQ1 = (TH1F *)gDirectory->Get("FBTDC_UQ1");
 T->Draw("P.loQtdcL>>FBTDC_DQ1",ctrig1);
 FBTDC_DQ1 = (TH1F *)gDirectory->Get("FBTDC_DQ1");
 T->Draw("P.upQadcL>>FBADC_UQ1",ctrig1);
 FBADC_UQ1 = (TH1F *)gDirectory->Get("FBADC_UQ1");
 T->Draw("P.loQadcL>>FBADC_DQ1",ctrig1);
 FBADC_DQ1 = (TH1F *)gDirectory->Get("FBADC_DQ1");

 T->Draw("P.QLIfadcup>>FADC_UP",ctrig4);
 FADC_UP = (TH1F *)gDirectory->Get("FADC_UP");
 T->Draw("P.QLIfadclo>>FADC_DN",ctrig5);
 FADC_DN = (TH1F *)gDirectory->Get("FADC_DN");

 T->Draw("P.QLIfadcup>>FADC_UP1",ctrig1);
 FADC_UP1 = (TH1F *)gDirectory->Get("FADC_UP1");
 T->Draw("P.QLIfadclo>>FADC_DN1",ctrig1);
 FADC_DN1 = (TH1F *)gDirectory->Get("FADC_DN1");

 T->Draw("P.atlQtdcL>>FBTDC_AI",ctrig4);
 FBTDC_AI = (TH1F *)gDirectory->Get("FBTDC_AI");
 T->Draw("P.atrQtdcL>>FBTDC_AO",ctrig4);
 FBTDC_AO = (TH1F *)gDirectory->Get("FBTDC_AO");
 T->Draw("P.atlQadcL>>FBADC_AI",ctrig4);
 FBADC_AI = (TH1F *)gDirectory->Get("FBADC_AI");
 T->Draw("P.atrQadcL>>FBADC_AO",ctrig4);
 FBADC_AO = (TH1F *)gDirectory->Get("FBADC_AO");

 T->Draw("P.ATRIfadc1>>FADC_AI",ctrig4);
 FADC_AI = (TH1F *)gDirectory->Get("FADC_AI");
 T->Draw("P.ATRIfadc2>>FADC_AO",ctrig4);
 FADC_AO = (TH1F *)gDirectory->Get("FADC_AO");

 T->Draw("P.ATRIftime1>>FTDC_AI",ctrig4);
 FTDC_AI = (TH1F *)gDirectory->Get("FTDC_AI");
 T->Draw("P.ATRIftime2>>FTDC_AO",ctrig4);
 FTDC_AO = (TH1F *)gDirectory->Get("FTDC_AO");

 T->Draw("P.QLIftimeup>>FTDC_UP",ctrig4);
 FTDC_UP = (TH1F *)gDirectory->Get("FTDC_UP");
 T->Draw("P.QLIftimelo>>FTDC_DN",ctrig5);
 FTDC_DN = (TH1F *)gDirectory->Get("FTDC_DN");
 T->Draw("P.QLIftimeS0A>>FTDC_S0A",ctrig1);
 FTDC_S0A = (TH1F *)gDirectory->Get("FTDC_S0A");
 T->Draw("P.QLIftimeS0B>>FTDC_S0B",ctrig1);
 FTDC_S0B = (TH1F *)gDirectory->Get("FTDC_S0B");

 T->Draw("P.QLIftimeS3>>FTDC_S3",ctrig2);
 FTDC_S3 = (TH1F *)gDirectory->Get("FTDC_S3");

 T->Draw("L.vdc.u1.wire:0.5*(P.S0AtdcL-P.S0BtdcL)>>VDC_u1_S0(50,-50,50,200,0,400)",ctrig1);
 VDC_u1_S0 = (TH2F *)gDirectory->Get("VDC_u1_S0");
 T->Draw("L.vdc.v1.wire:0.5*(P.S0AtdcL-P.S0BtdcL)>>VDC_v1_S0(50,-50,50,200,0,400)",ctrig1);
 VDC_v1_S0 = (TH2F *)gDirectory->Get("VDC_v1_S0");
 T->Draw("L.vdc.u2.wire:0.5*(P.S0AtdcL-P.S0BtdcL)>>VDC_u2_S0(50,-50,50,200,0,400)",ctrig1);
 VDC_u2_S0 = (TH2F *)gDirectory->Get("VDC_u2_S0");
 T->Draw("L.vdc.v2.wire:0.5*(P.S0AtdcL-P.S0BtdcL)>>VDC_v2_S0(50,-50,50,200,0,400)",ctrig1);
 VDC_v2_S0 = (TH2F *)gDirectory->Get("VDC_v2_S0");
 T->Draw("L.vdc.u1.wire>>VDChit_u1");
 VDChit_u1 = (TH1F *)gDirectory->Get("VDChit_u1");
 T->Draw("L.vdc.v1.wire>>VDChit_v1");
 VDChit_v1 = (TH1F *)gDirectory->Get("VDChit_v1");
 T->Draw("L.vdc.u2.wire>>VDChit_u2");
 VDChit_u2 = (TH1F *)gDirectory->Get("VDChit_u2");
 T->Draw("L.vdc.v2.wire>>VDChit_v2");
 VDChit_v2 = (TH1F *)gDirectory->Get("VDChit_v2");

 T->Draw("L.vdc.u1.rawtime>>VDCTDC_u1");
 VDCTDC_u1 = (TH1F *)gDirectory->Get("VDCTDC_u1");
 T->Draw("L.vdc.v1.rawtime>>VDCTDC_v1");
 VDCTDC_v1 = (TH1F *)gDirectory->Get("VDCTDC_v1");
 T->Draw("L.vdc.u2.rawtime>>VDCTDC_u2");
 VDCTDC_u2 = (TH1F *)gDirectory->Get("VDCTDC_u2");
 T->Draw("L.vdc.v2.rawtime>>VDCTDC_v2");
 VDCTDC_v2 = (TH1F *)gDirectory->Get("VDCTDC_v2");

 T->Draw("L.vdc.u1.wire:0.5*(P.S0AtdcL-P.S0BtdcL)>>VDC_u1_S0cut(50,-50,50,200,0,400)",ctrig1cut);
 VDC_u1_S0cut = (TH2F *)gDirectory->Get("VDC_u1_S0cut");
 T->Draw("L.vdc.v1.wire:0.5*(P.S0AtdcL-P.S0BtdcL)>>VDC_v1_S0cut(50,-50,50,200,0,400)",ctrig1cut);
 VDC_v1_S0cut = (TH2F *)gDirectory->Get("VDC_v1_S0cut");
 T->Draw("L.vdc.u2.wire:0.5*(P.S0AtdcL-P.S0BtdcL)>>VDC_u2_S0cut(50,-50,50,200,0,400)",ctrig1cut);
 VDC_u2_S0cut = (TH2F *)gDirectory->Get("VDC_u2_S0cut");
 T->Draw("L.vdc.v2.wire:0.5*(P.S0AtdcL-P.S0BtdcL)>>VDC_v2_S0cut(50,-50,50,200,0,400)",ctrig1cut);
 VDC_v2_S0cut = (TH2F *)gDirectory->Get("VDC_v2_S0cut");
 

 T->Draw("L.tr.y+L.tr.ph*0.9:L.tr.x+L.tr.th*0.9>>UPQProj(100,-0.05,0.05,200,-0.1,0.2)",ccutUPQ);
 //T->Draw("L.tr.y+L.tr.ph*0.9:L.tr.x+L.tr.th*0.9>>UPQProj(100,-0.05,0.05,200,-0.1,0.2)",ccutUPQ,"P.upQadcL");
 UPQProj = (TH2F *)gDirectory->Get("UPQProj");
 T->Draw("L.tr.y+L.tr.ph*1.05:L.tr.x+L.tr.th*1.05>>DNQProj(100,-0.05,0.05,200,-0.1,0.2)",ccutDNQ);
 //T->Draw("L.tr.y+L.tr.ph*1.05:L.tr.x+L.tr.th*1.05>>DNQProj(100,-0.05,0.05,200,-0.1,0.2)",ccutDNQ,"P.loQadcL");
 DNQProj = (TH2F *)gDirectory->Get("DNQProj");

 TCanvas *c10 = new TCanvas("c10","c10",1000,1000);
 c10->Divide(1,2);
 c10->cd(1);
 UPQProj->SetTitle("LHRS: Projection of VDC track on UPQ Plane");
 UPQProj->GetYaxis()->SetTitle("Dispersive direction (m)");
 UPQProj->GetXaxis()->SetTitle("Nondispersive direction (m)");
 UPQProj->Draw("COLZ");
 c10->cd(2);
 DNQProj->SetTitle("LHRS: Projection of VDC track on DNQ plane");
 DNQProj->GetYaxis()->SetTitle("Dispersive direction (m)");
 DNQProj->GetXaxis()->SetTitle("Nondispersive direction (m)");
 DNQProj->Draw("COLZ");
 c10->SaveAs("Proj_event.pdf");

 TCanvas *c9 = new TCanvas("c9","c9",1000,1000);
 c9->Divide(2,4);
 c9->cd(3);
 FBTDC_S0A->SetTitle("FBS TDC_{S0A}");
 FBTDC_S0A->GetXaxis()->SetTitleSize(0.05);
 FBTDC_S0A->GetYaxis()->SetTitle("Event");
 FBTDC_S0A->Draw();
 gPad->SetLogy();
 c9->cd(4);
 FBTDC_S0B->SetTitle("FBS TDC_{S0B}");
 FBTDC_S0B->GetXaxis()->SetTitleSize(0.05);
 FBTDC_S0B->GetYaxis()->SetTitle("Event");
 FBTDC_S0B->Draw();
 gPad->SetLogy();
 c9->cd(1);
 FBADC_S0A->SetTitle("FBS ADC_{S0A}");
 FBADC_S0A->GetXaxis()->SetTitleSize(0.05);
 FBADC_S0A->GetYaxis()->SetTitle("Event");
 FBADC_S0A->Draw();
gPad->SetLogy();
 c9->cd(2);
 FBADC_S0B->SetTitle("FBS ADC_{S0B}");
 FBADC_S0B->GetXaxis()->SetTitleSize(0.05);
 FBADC_S0B->GetYaxis()->SetTitle("Event");
 FBADC_S0B->Draw();
gPad->SetLogy();
 c9->cd(5);
 FADC_S0A->SetTitle("Flash ADC_{S0A}");
 FADC_S0A->GetXaxis()->SetTitleSize(0.05);
 FADC_S0A->GetYaxis()->SetTitle("Event");
 FADC_S0A->Draw(); 
 FBTDC_UQ1->Draw("same");
gPad->SetLogy();
 c9->cd(6);
 FADC_S0B->SetTitle("Flash ADC_{S0B}");
 FADC_S0B->GetXaxis()->SetTitleSize(0.05);
 FADC_S0B->GetYaxis()->SetTitle("Event");
 FADC_S0B->Draw();
gPad->SetLogy();

 c9->cd(7);
 FTDC_S0A->SetTitle("Flash time_{S0A}");
 FTDC_S0A->GetXaxis()->SetTitleSize(0.05);
 FTDC_S0A->GetYaxis()->SetTitle("Event");
 FTDC_S0A->Draw();
gPad->SetLogy();
 c9->cd(8);
 FTDC_S0B->SetTitle("Flash time_{S0B}");
 FTDC_S0B->GetXaxis()->SetTitleSize(0.05);
 FTDC_S0B->GetYaxis()->SetTitle("Event");
 FTDC_S0B->Draw();
gPad->SetLogy();
c9->SaveAs("S0_event.pdf");


TCanvas *c4 = new TCanvas("c4","c4",1000,1000);
 c4->Divide(2,3);
 c4->cd(3);
 FBTDC_UQ->SetTitle("FBS TDC_{UQ}");
 FBTDC_UQ->GetXaxis()->SetTitleSize(0.05);
 FBTDC_UQ->GetYaxis()->SetTitle("Event");
 FBTDC_UQ->GetXaxis()->SetRangeUser(0,1700);
gPad->SetLogy();
 FBTDC_UQ->Draw();
 FBTDC_UQ1->SetLineColor(2);
 FBTDC_UQ1->Draw("same");
gPad->SetLogy();
 c4->cd(4);
 FBTDC_DQ->SetTitle("FBS TDC_{DQ}");
 FBTDC_DQ->GetXaxis()->SetTitleSize(0.05);
 FBTDC_DQ->GetYaxis()->SetTitle("Event");
 FBTDC_DQ->GetXaxis()->SetRangeUser(0,1700);
gPad->SetLogy();
 FBTDC_DQ->Draw();
 FBTDC_DQ1->SetLineColor(2);
 FBTDC_DQ1->Draw("same");
gPad->SetLogy();
 c4->cd(1);
 FBADC_UQ->SetTitle("FBS ADC_{UQ}");
 FBADC_UQ->GetXaxis()->SetTitleSize(0.05);
 FBADC_UQ->GetYaxis()->SetTitle("Event");
 FBADC_UQ->Draw();
 FBADC_UQ1->SetLineColor(2);
 FBADC_UQ1->Draw("same");
gPad->SetLogy();
 c4->cd(2);
 FBADC_DQ->SetTitle("FBS ADC_{DQ}");
 FBADC_DQ->GetXaxis()->SetTitleSize(0.05);
 FBADC_DQ->GetYaxis()->SetTitle("Event");
 FBADC_DQ->Draw();
 FBADC_DQ1->SetLineColor(2);
 FBADC_DQ1->Draw("same");
gPad->SetLogy();
c4->cd(5);
 FADC_UP->SetTitle("Flash ADC_{UQ}");
 FADC_UP->GetXaxis()->SetTitleSize(0.05);
 FADC_UP->GetYaxis()->SetTitle("Event");
 FADC_UP->Draw();
 FADC_UP1->SetLineColor(2);
gPad->SetLogy();
 FADC_UP1->Draw("same");

gPad->SetLogy();
c4->cd(6);
 FADC_DN->SetTitle("Flash ADC_{DQ}");
 FADC_DN->GetXaxis()->SetTitleSize(0.05);
 FADC_DN->GetYaxis()->SetTitle("Event");
 FADC_DN->Draw();
 FADC_DN1->SetLineColor(2);
 FADC_DN1->Draw("same");
gPad->SetLogy();
c4->SaveAs("Quartz_event.pdf");
/* c4->cd(7);
 FTDC_UP->SetTitle("Flash time_{UP}");
 FTDC_UP->GetXaxis()->SetTitleSize(0.05);
 FTDC_UP->GetYaxis()->SetTitle("Event");
 FTDC_UP->Draw();
 c4->cd(8);
 FTDC_DN->SetTitle("Flash time_{DN}");
 FTDC_DN->GetXaxis()->SetTitleSize(0.05);
 FTDC_DN->GetYaxis()->SetTitle("Event");
 FTDC_DN->Draw();*/
 
TCanvas *c3 = new TCanvas("c3","c3",1000,1000);
 c3->Divide(2,2);
 c3->cd(2);
 
 FBTDC_S3->SetTitle("FBS TDC_{S3}");
 FBTDC_S3->GetXaxis()->SetTitleSize(0.05);
 FBTDC_S3->GetYaxis()->SetTitle("Event");
 FBTDC_S3->Draw();
gPad->SetLogy();
c3->cd(1);

 FBADC_S3->SetTitle("FBS ADC_{S3}");
 FBADC_S3->GetXaxis()->SetTitleSize(0.05);
 FBADC_S3->GetYaxis()->SetTitle("Event");
gPad->SetLogy();
 FBADC_S3->Draw();

c3->cd(3);
 FADC_S3->SetTitle("Flash ADC_{S3}");
 FADC_S3->GetXaxis()->SetTitleSize(0.05);
 FADC_S3->GetYaxis()->SetTitle("Event");
gPad->SetLogy();
 FADC_S3->Draw();

 c3->cd(4);
 FTDC_S3->SetTitle("Flash time_{S3}");
 FTDC_S3->GetXaxis()->SetTitleSize(0.05);
 FTDC_S3->GetYaxis()->SetTitle("Event");
gPad->SetLogy();
 FTDC_S3->Draw();
c3->SaveAs("S3_event.pdf");

TCanvas *c2 = new TCanvas("c2","c2",1000,1000);
 c2->Divide(2,4);
 c2->cd(3);
 FBTDC_AI->SetTitle("FBS TDC_{AI}");
 FBTDC_AI->GetXaxis()->SetTitleSize(0.05);
 FBTDC_AI->GetYaxis()->SetTitle("Event");
 FBTDC_AI->Draw();
gPad->SetLogy();
gPad->SetLogy();
 c2->cd(4);
 FBTDC_AO->SetTitle("FBS TDC_{AO}");
 FBTDC_AO->GetXaxis()->SetTitleSize(0.05);
 FBTDC_AO->GetYaxis()->SetTitle("Event");
 FBTDC_AO->Draw();
gPad->SetLogy();
 c2->cd(1);
 FBADC_AI->SetTitle("FBS ADC_{AI}");
 FBADC_AI->GetXaxis()->SetTitleSize(0.05);
 FBADC_AI->GetYaxis()->SetTitle("Event");
gPad->SetLogy();
 FBADC_AI->Draw();
 c2->cd(2);
 FBADC_AO->SetTitle("FBS ADC_{AO}");
 FBADC_AO->GetXaxis()->SetTitleSize(0.05);
 FBADC_AO->GetYaxis()->SetTitle("Event");
 FBADC_AO->Draw();
gPad->SetLogy();

 c2->cd(5);
 FADC_AI->SetTitle("Flash ADC_{AI}");
 FADC_AI->GetXaxis()->SetTitleSize(0.05);
 FADC_AI->GetYaxis()->SetTitle("Event");
 FADC_AI->Draw();
gPad->SetLogy();
 c2->cd(6);
 FADC_AO->SetTitle("Flash ADC_{AO}");
 FADC_AO->GetXaxis()->SetTitleSize(0.05);
 FADC_AO->GetYaxis()->SetTitle("Event");
 FADC_AO->Draw();
gPad->SetLogy();
 c2->cd(7);
 FTDC_AI->SetTitle("Flash time_{AI}");
 FTDC_AI->GetXaxis()->SetTitleSize(0.05);
 FTDC_AI->GetYaxis()->SetTitle("Event");
 FTDC_AI->Draw();
gPad->SetLogy();
 c2->cd(8);
 FTDC_AO->SetTitle("Flash time_{AO}");
 FTDC_AO->GetXaxis()->SetTitleSize(0.05);
 FTDC_AO->GetYaxis()->SetTitle("Event");
 FTDC_AO->Draw();
gPad->SetLogy();
c2->SaveAs("AT_event.pdf");
/* TCanvas *c5 = new TCanvas("c5","c5",1000,1000);
 c5->Divide(2,2);
 c5->cd(1);
 VDC_u1_S0->SetTitle("VDC u1 wire:0.5*FBS(TDC_{S0A}-TDC_{S0B})");
 VDC_u1_S0->GetYaxis()->SetTitle("VDC u1 wire");
 VDC_u1_S0->GetXaxis()->SetTitle("0.5*FBS(TDC_{S0A}-TDC_{S0B})");
 VDC_u1_S0->Draw("COLZ");
 c5->cd(2);
 VDC_v1_S0->SetTitle("VDC v1 wire:0.5*FBS(TDC_{S0A}-TDC_{S0B})");
 VDC_v1_S0->GetYaxis()->SetTitle("VDC v1 wire");
 VDC_v1_S0->GetXaxis()->SetTitle("0.5*FBS(TDC_{S0A}-TDC_{S0B})");
 VDC_v1_S0->Draw("COLZ");
 c5->cd(3);
 VDC_u2_S0->SetTitle("VDC u2 wire:0.5*FBS(TDC_{S0A}-TDC_{S0B})");
 VDC_u2_S0->GetYaxis()->SetTitle("VDC u2 wire");
 VDC_u2_S0->GetXaxis()->SetTitle("0.5*FBS(TDC_{S0A}-TDC_{S0B})");
 VDC_u2_S0->Draw("COLZ");
 c5->cd(4);
 VDC_v2_S0->SetTitle("VDC v2 wire:0.5*FBS(TDC_{S0A}-TDC_{S0B})");
 VDC_v2_S0->GetYaxis()->SetTitle("VDC v2 wire");
 VDC_v2_S0->GetXaxis()->SetTitle("0.5*FBS(TDC_{S0A}-TDC_{S0B})");
 VDC_v2_S0->Draw("COLZ");*/

 TCanvas *c6 = new TCanvas("c6","c6",1000,1000);
 c6->Divide(2,2);
 c6->cd(1);
 VDChit_u1->Draw();
 c6->cd(2);
 VDChit_v1->Draw();
 c6->cd(3);
 VDChit_u2->Draw();
 c6->cd(4);
 VDChit_v2->Draw();
c6->SaveAs("VDCWIRE_event.pdf");
// c2->SaveAs("LeftTriggers_rate.pdf");

 TCanvas *c7 = new TCanvas("c7","c7",1000,1000);
 c7->Divide(2,2);
 c7->cd(1);
 VDCTDC_u1->Draw();
 c7->cd(2);
 VDCTDC_v1->Draw();
 c7->cd(3);
 VDCTDC_u2->Draw();
 c7->cd(4);
 VDCTDC_v2->Draw();
c7->SaveAs("VDCTIME_event.pdf");


 TCanvas *c8 = new TCanvas("c8","c8",1000,1000);
 c8->Divide(2,2);
 c8->cd(1);
 VDC_u1_S0cut->SetTitle("VDC u1 wire:0.5*FBS(TDC_{S0A}-TDC_{S0B})");
 VDC_u1_S0cut->GetYaxis()->SetTitle("VDC u1 wire");
 VDC_u1_S0cut->GetXaxis()->SetTitle("0.5*FBS(TDC_{S0A}-TDC_{S0B})");
 VDC_u1_S0cut->Draw("COLZ");
 c8->cd(2);
 VDC_v1_S0cut->SetTitle("VDC v1 wire:0.5*FBS(TDC_{S0A}-TDC_{S0B})");
 VDC_v1_S0cut->GetYaxis()->SetTitle("VDC v1 wire");
 VDC_v1_S0cut->GetXaxis()->SetTitle("0.5*FBS(TDC_{S0A}-TDC_{S0B})");
 VDC_v1_S0cut->Draw("COLZ");
 c8->cd(3);
 VDC_u2_S0cut->SetTitle("VDC u2 wire:0.5*FBS(TDC_{S0A}-TDC_{S0B})");
 VDC_u2_S0cut->GetYaxis()->SetTitle("VDC u2 wire");
 VDC_u2_S0cut->GetXaxis()->SetTitle("0.5*FBS(TDC_{S0A}-TDC_{S0B})");
 VDC_u2_S0cut->Draw("COLZ");
 c8->cd(4);
 VDC_v2_S0cut->SetTitle("VDC v2 wire:0.5*FBS(TDC_{S0A}-TDC_{S0B})");
 VDC_v2_S0cut->GetYaxis()->SetTitle("VDC v2 wire");
 VDC_v2_S0cut->GetXaxis()->SetTitle("0.5*FBS(TDC_{S0A}-TDC_{S0B})");
 VDC_v2_S0cut->Draw("COLZ");
c8->SaveAs("VDCcorr_event.pdf");
 gSystem->Exec("pdfunite *_event.pdf all.pdf");
 gSystem->Exec("rm -rf *_event.pdf");


}
