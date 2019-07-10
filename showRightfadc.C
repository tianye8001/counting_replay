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

  char ctrig1[200],ctrig1cut[200],ctrig2[200],ctrig3[200],ctrig4[200],ctrig5[200];
  char ccutUPQ[800],ccutDNQ[800];
 
  //sprintf(ccutUPQ,"fEvtHdr.fEvtType==1 && ((R.tr.x+R.tr.th*0.9)>-0.16 && (R.tr.x+R.tr.th*0.9)<0.16) && ((R.tr.y+R.tr.ph*0.9)>-0.04 && (R.tr.x+R.tr.th*0.9)<0.04)");

  //sprintf(ccutDNQ,"fEvtHdr.fEvtType==1 && ((R.tr.x+R.tr.th*1.05)>-0.16 && (R.tr.x+R.tr.th*1.05)<0.16) && ((R.tr.y+R.tr.ph*1.05)>-0.04 && (R.tr.x+R.tr.th*1.05)<0.04)");
  /*
    sprintf(ctrig,"P.evtype==1");
    sprintf(ctrig1,"(P.evtypebits&64)==64");
    sprintf(ctrig2,"(P.evtypebits&4)==4");
    sprintf(ctrig4,"(P.evtypebits&16)==16");
    sprintf(ctrig5,"(P.evtypebits&32)==32");
    sprintf(ctrig1cut,"(P.evtypebits&2)==2 && P.S0AtdcR>400");
  */
  sprintf(ctrig1,"");
  sprintf(ctrig2,"");
  sprintf(ctrig4,"");
  sprintf(ctrig5,"");
  sprintf(ctrig1cut,"");
  // TCanvas c0;

  // TH2F *scaler_S0A = new TH1F("scaler_S0A","S0A rate vs clock",400,300,700);
  // TH2F *scaler_S0B = new TH1F("scaler_S0B","S0B rate vs clock",1700,300,2000);
  // TH1F *FBADC_S0A = new TH1F("S0A","S0A",1700,300,2000); 
  T->Draw("P.S0BtdcR>>FBTDC_S0B",ctrig1);
  FBTDC_S0B = (TH1F *)gDirectory->Get("FBTDC_S0B");
  T->Draw("P.S0AtdcR>>FBTDC_S0A",ctrig1);
  FBTDC_S0A = (TH1F *)gDirectory->Get("FBTDC_S0A");
  T->Draw("P.S0BadcR>>FBADC_S0B",ctrig1);
  FBADC_S0B = (TH1F *)gDirectory->Get("FBADC_S0B");
  T->Draw("P.S0AadcR>>FBADC_S0A",ctrig1);
  FBADC_S0A = (TH1F *)gDirectory->Get("FBADC_S0A");

  T->Draw("P.fadcS0AR>>FADC_S0B",ctrig1);
  FADC_S0B = (TH1F *)gDirectory->Get("FADC_S0B");
  T->Draw("P.fadcS0BR>>FADC_S0A",ctrig1);
  FADC_S0A = (TH1F *)gDirectory->Get("FADC_S0A");


  T->Draw("P.S3tdcR>>FBTDC_S3",ctrig2);
  FBTDC_S3 = (TH1F *)gDirectory->Get("FBTDC_S3");
  T->Draw("P.S3adcR>>FBADC_S3",ctrig2);
  FBADC_S3 = (TH1F *)gDirectory->Get("FBADC_S3");

  T->Draw("P.QRIfadcS0B>>FADC_S0B",ctrig1);
  FADC_S0B = (TH1F *)gDirectory->Get("FADC_S0B");
  T->Draw("P.QRIfadcS0A>>FADC_S0A",ctrig1);
  FADC_S0A = (TH1F *)gDirectory->Get("FADC_S0A");

  T->Draw("P.QRIfadcS3>>FADC_S3",ctrig2);
  FADC_S3 = (TH1F *)gDirectory->Get("FADC_S3");
 
  T->Draw("P.upQtdcR>>FBTDC_UQ",ctrig4);
  FBTDC_UQ = (TH1F *)gDirectory->Get("FBTDC_UQ");
  T->Draw("P.loQtdcR>>FBTDC_DQ",ctrig5);
  FBTFBTDDC_DQ = (TH1F *)gDirectory->Get("FBTDC_DQ");
  T->Draw("P.upQadcR>>FBADC_UQ",ctrig4);
  FBADC_UQ = (TH1F *)gDirectory->Get("FBADC_UQ");
  T->Draw("P.loQadcR>>FBADC_DQ",ctrig5);
  FBADC_DQ = (TH1F *)gDirectory->Get("FBADC_DQ");

  T->Draw("P.QRIfadcup>>FADC_UP",ctrig4);
  FADC_UP = (TH1F *)gDirectory->Get("FADC_UP");
  T->Draw("P.QRIfadclo>>FADC_DN",ctrig5);
  FADC_DN = (TH1F *)gDirectory->Get("FADC_DN");


  T->Draw("P.upQtdcR>>FBTDC_UQ1",ctrig1);
  FBTDC_UQ1 = (TH1F *)gDirectory->Get("FBTDC_UQ1");
  T->Draw("P.loQtdcR>>FBTDC_DQ1",ctrig1);
  FBTDC_DQ1 = (TH1F *)gDirectory->Get("FBTDC_DQ1");
  T->Draw("P.upQadcR>>FBADC_UQ1",ctrig1);
  FBADC_UQ1 = (TH1F *)gDirectory->Get("FBADC_UQ1");
  T->Draw("P.loQadcR>>FBADC_DQ1",ctrig1);
  FBADC_DQ1 = (TH1F *)gDirectory->Get("FBADC_DQ1");

  T->Draw("P.QRIfadcup>>FADC_UP",ctrig4);
  FADC_UP = (TH1F *)gDirectory->Get("FADC_UP");
  T->Draw("P.QRIfadclo>>FADC_DN",ctrig5);
  FADC_DN = (TH1F *)gDirectory->Get("FADC_DN");

  T->Draw("P.QRIfadcup>>FADC_UP1",ctrig1);
  FADC_UP1 = (TH1F *)gDirectory->Get("FADC_UP1");
  T->Draw("P.QRIfadclo>>FADC_DN1",ctrig1);
  FADC_DN1 = (TH1F *)gDirectory->Get("FADC_DN1");

  T->Draw("P.atlQtdcR>>FBTDC_AI",ctrig4);
  FBTDC_AI = (TH1F *)gDirectory->Get("FBTDC_AI");
  T->Draw("P.atrQtdcR>>FBTDC_AO",ctrig4);
  FBTDC_AO = (TH1F *)gDirectory->Get("FBTDC_AO");
  T->Draw("P.atlQadcR>>FBADC_AI",ctrig4);
  FBADC_AI = (TH1F *)gDirectory->Get("FBADC_AI");
  T->Draw("P.atrQadcR>>FBADC_AO",ctrig4);
  FBADC_AO = (TH1F *)gDirectory->Get("FBADC_AO");

  T->Draw("P.ATRIfadc1>>FADC_AI",ctrig4);
  FADC_AI = (TH1F *)gDirectory->Get("FADC_AI");
  T->Draw("P.ATRIfadc2>>FADC_AO",ctrig4);
  FADC_AO = (TH1F *)gDirectory->Get("FADC_AO");

  T->Draw("P.ATRIftime1>>FTDC_AI",ctrig4);
  FTDC_AI = (TH1F *)gDirectory->Get("FTDC_AI");
  T->Draw("P.ATRIftime2>>FTDC_AO",ctrig4);
  FTDC_AO = (TH1F *)gDirectory->Get("FTDC_AO");

  T->Draw("P.QRIftimeup>>FTDC_UP",ctrig4);
  FTDC_UP = (TH1F *)gDirectory->Get("FTDC_UP");
  T->Draw("P.QRIftimelo>>FTDC_DN",ctrig5);
  FTDC_DN = (TH1F *)gDirectory->Get("FTDC_DN");
  T->Draw("P.QRIftimeS0A>>FTDC_S0A",ctrig1);
  FTDC_S0A = (TH1F *)gDirectory->Get("FTDC_S0A");
  T->Draw("P.QRIftimeS0B>>FTDC_S0B",ctrig1);
  FTDC_S0B = (TH1F *)gDirectory->Get("FTDC_S0B");

  T->Draw("P.QRIftimeS3>>FTDC_S3",ctrig2);
  FTDC_S3 = (TH1F *)gDirectory->Get("FTDC_S3");

  T->Draw("R.vdc.u1.wire:0.5*(P.S0AtdcR-P.S0BtdcR)>>VDC_u1_S0(50,-50,50,200,0,400)",ctrig1);
  VDC_u1_S0 = (TH2F *)gDirectory->Get("VDC_u1_S0");
  T->Draw("R.vdc.v1.wire:0.5*(P.S0AtdcR-P.S0BtdcR)>>VDC_v1_S0(50,-50,50,200,0,400)",ctrig1);
  VDC_v1_S0 = (TH2F *)gDirectory->Get("VDC_v1_S0");
  T->Draw("R.vdc.u2.wire:0.5*(P.S0AtdcR-P.S0BtdcR)>>VDC_u2_S0(50,-50,50,200,0,400)",ctrig1);
  VDC_u2_S0 = (TH2F *)gDirectory->Get("VDC_u2_S0");
  T->Draw("R.vdc.v2.wire:0.5*(P.S0AtdcR-P.S0BtdcR)>>VDC_v2_S0(50,-50,50,200,0,400)",ctrig1);
  VDC_v2_S0 = (TH2F *)gDirectory->Get("VDC_v2_S0");
  T->Draw("R.vdc.u1.wire>>VDChit_u1");
  VDChit_u1 = (TH1F *)gDirectory->Get("VDChit_u1");
  T->Draw("R.vdc.v1.wire>>VDChit_v1");
  VDChit_v1 = (TH1F *)gDirectory->Get("VDChit_v1");
  T->Draw("R.vdc.u2.wire>>VDChit_u2");
  VDChit_u2 = (TH1F *)gDirectory->Get("VDChit_u2");
  T->Draw("R.vdc.v2.wire>>VDChit_v2");
  VDChit_v2 = (TH1F *)gDirectory->Get("VDChit_v2");

  T->Draw("R.vdc.u1.rawtime>>VDCTDC_u1");
  VDCTDC_u1 = (TH1F *)gDirectory->Get("VDCTDC_u1");
  T->Draw("R.vdc.v1.rawtime>>VDCTDC_v1");
  VDCTDC_v1 = (TH1F *)gDirectory->Get("VDCTDC_v1");
  T->Draw("R.vdc.u2.rawtime>>VDCTDC_u2");
  VDCTDC_u2 = (TH1F *)gDirectory->Get("VDCTDC_u2");
  T->Draw("R.vdc.v2.rawtime>>VDCTDC_v2");
  VDCTDC_v2 = (TH1F *)gDirectory->Get("VDCTDC_v2");

  T->Draw("R.vdc.u1.wire:0.5*(P.S0AtdcR-P.S0BtdcR)>>VDC_u1_S0cut(50,-50,50,200,0,400)",ctrig1cut);
  VDC_u1_S0cut = (TH2F *)gDirectory->Get("VDC_u1_S0cut");
  T->Draw("R.vdc.v1.wire:0.5*(P.S0AtdcR-P.S0BtdcR)>>VDC_v1_S0cut(50,-50,50,200,0,400)",ctrig1cut);
  VDC_v1_S0cut = (TH2F *)gDirectory->Get("VDC_v1_S0cut");
  T->Draw("R.vdc.u2.wire:0.5*(P.S0AtdcR-P.S0BtdcR)>>VDC_u2_S0cut(50,-50,50,200,0,400)",ctrig1cut);
  VDC_u2_S0cut = (TH2F *)gDirectory->Get("VDC_u2_S0cut");
  T->Draw("R.vdc.v2.wire:0.5*(P.S0AtdcR-P.S0BtdcR)>>VDC_v2_S0cut(50,-50,50,200,0,400)",ctrig1cut);
  VDC_v2_S0cut = (TH2F *)gDirectory->Get("VDC_v2_S0cut");

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
  c9->cd(2);
  FBADC_S0B->SetTitle("FBS ADC_{S0B}");
  FBADC_S0B->GetXaxis()->SetTitleSize(0.05);
  FBADC_S0B->GetYaxis()->SetTitle("Event");
  FBADC_S0B->Draw();
  c9->cd(5);
  FADC_S0A->SetTitle("Flash ADC_{S0A}");
  FADC_S0A->GetXaxis()->SetTitleSize(0.05);
  FADC_S0A->GetYaxis()->SetTitle("Event");
  FADC_S0A->Draw(); 
  FBTDC_UQ1->Draw("same");
  c9->cd(6);
  FADC_S0B->SetTitle("Flash ADC_{S0B}");
  FADC_S0B->GetXaxis()->SetTitleSize(0.05);
  FADC_S0B->GetYaxis()->SetTitle("Event");
  FADC_S0B->Draw();

  c9->cd(7);
  FTDC_S0A->SetTitle("Flash time_{S0A}");
  FTDC_S0A->GetXaxis()->SetTitleSize(0.05);
  FTDC_S0A->GetYaxis()->SetTitle("Event");
  FTDC_S0A->Draw();
  c9->cd(8);
  FTDC_S0B->SetTitle("Flash time_{S0B}");
  FTDC_S0B->GetXaxis()->SetTitleSize(0.05);
  FTDC_S0B->GetYaxis()->SetTitle("Event");
  FTDC_S0B->Draw();
  c9->SaveAs("S0_event.pdf");


  TCanvas *c4 = new TCanvas("c4","c4",1000,1000);
  c4->Divide(2,3);
  c4->cd(3);
  FBTDC_UQ->SetTitle("FBS TDC_{UQ}");
  FBTDC_UQ->GetXaxis()->SetTitleSize(0.05);
  FBTDC_UQ->GetYaxis()->SetTitle("Event");
  FBTDC_UQ->GetXaxis()->SetRangeUser(0,1700);
  FBTDC_UQ->Draw();
  FBTDC_UQ1->SetLineColor(2);
  FBTDC_UQ1->Draw("same");
  c4->cd(4);
  FBTDC_DQ->SetTitle("FBS TDC_{DQ}");
  FBTDC_DQ->GetXaxis()->SetTitleSize(0.05);
  FBTDC_DQ->GetYaxis()->SetTitle("Event");
  FBTDC_DQ->GetXaxis()->SetRangeUser(0,1700);
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
  c4->cd(7);
  FTDC_UP->SetTitle("Flash time_{UP}");
  FTDC_UP->GetXaxis()->SetTitleSize(0.05);
  FTDC_UP->GetYaxis()->SetTitle("Event");
  FTDC_UP->Draw();
  gPad->SetLogy();
  c4->cd(8);
  FTDC_DN->SetTitle("Flash time_{DN}");
  FTDC_DN->GetXaxis()->SetTitleSize(0.05);
  FTDC_DN->GetYaxis()->SetTitle("Event");
  FTDC_DN->Draw();
  gPad->SetLogy();
  c4->SaveAs("Quartz_event.pdf");
 
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
  FBADC_S3->Draw();

  c3->cd(3);
  FADC_S3->SetTitle("Flash ADC_{S3}");
  FADC_S3->GetXaxis()->SetTitleSize(0.05);
  FADC_S3->GetYaxis()->SetTitle("Event");
  FADC_S3->Draw();

  c3->cd(4);
  FTDC_S3->SetTitle("Flash time_{S3}");
  FTDC_S3->GetXaxis()->SetTitleSize(0.05);
  FTDC_S3->GetYaxis()->SetTitle("Event");
  FTDC_S3->Draw();
  gPad->SetLogy();
  c3->SaveAs("S3_event.pdf");

  TCanvas *c2 = new TCanvas("c2","c2",1000,1000);
  c2->Divide(2,4);
  c2->cd(3);
  FBTDC_AI->SetTitle("FBS TDC_{AI}");
  FBTDC_AI->GetXaxis()->SetTitleSize(0.05);
  FBTDC_AI->GetYaxis()->SetTitle("Event");
  FBTDC_AI->Draw();
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
  FBADC_AI->Draw();
  c2->cd(2);
  FBADC_AO->SetTitle("FBS ADC_{AO}");
  FBADC_AO->GetXaxis()->SetTitleSize(0.05);
  FBADC_AO->GetYaxis()->SetTitle("Event");
  FBADC_AO->Draw();

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

  gSystem->Exec(Form("pdfunite *_event.pdf all.pdf"));
  gSystem->Exec(Form("rm -rf *_event.pdf"));
}
