{ 
  // Macro to plot sieve pattern
  // make projection for diff z
  bool show_thph = false;
  bool do_cip_thing = false;

  gROOT->Reset();

  gStyle->SetOptStat(0);
  gStyle->SetStatH(0.2);
  gStyle->SetStatW(0.2);
  gStyle->SetTitleH(0.09);
  gStyle->SetTitleW(0.3);
  gStyle->SetLabelSize(0.04,"x");
  gStyle->SetLabelSize(0.04,"y");
  gROOT->ForceStyle();

  // "gold" track is at the target.  For more info, see
  // http://hallaweb/podd/doc/variables.html

  char ctrig[50],vdccut[200],tgtcut[200],tgty[200],ccut[800],cand[5];
  char trcut[300];

  Int_t runnum;
  runnum = (int)T->GetMaximum("fEvtHdr.fRun");

  int itrig = 5;
  // sprintf(ctrig,"fEvtHdr.fEvtType==%d",itrig);
  //  sprintf(ctrig,"fEvtHdr.fEvtNum<50000 && fEvtHdr.fEvtType==1");
  sprintf(ctrig,"fEvtHdr.fEvtType==1");

  // HRS = R.* or L.*

  // only one cluster in each VDC plane
  sprintf(vdccut,"L.vdc.u1.nclust==1&&L.vdc.v1.nclust==1&&L.vdc.u2.nclust==1&&L.vdc.v2.nclust==1");
  sprintf(trcut,"(L.tr.th[0]<0.05&&L.tr.th[0]>-0.2&&L.tr.ph[0]<0.1&&L.tr.ph[0]>-0.1)");
  sprintf(cand,"&&");

  // Build the total cut

  // data was taken only with T1, remove evttype cut for now (Sanghwa)
  strcpy(ccut,ctrig);
  strcat(ccut,cand);
  strcat(ccut,trcut);
  strcat(ccut,cand);
  strcat(ccut,vdccut);

  cout << "Cuts used : "<<endl;
  cout << ccut << endl;


  if(show_thph)
    {
      TCanvas c1;

      TH2F *htgthph = new TH2F("htgthph","LHRS Target theta-phi (theta vertical)",200,-0.03,0.03,200,-0.07,0.07);
      T->Draw("L.gold.th:L.gold.ph>>htgthph",ccut);

    }
  gStyle->SetOptStat(1);
  gStyle->SetOptFit(1111);

  TCanvas* c2 = new TCanvas("c2", "c2", 1400, 1000);
  c2->Divide(3,2);
  c2->cd(1);
  TH1F* hprojy = new TH1F("hprojy", "Y Projection LHRS", 300, -0.12, 0.12);
  T->Project(hprojy->GetName(),"L.tr.y[0]+0.9*L.tr.ph[0]", ccut);

  float qWidth = 0.24/300 * 0.035;
  int binWidth = int(0.035/0.24*300);
  double binA(0), integ(0);
  for(int i=1;i<=300 - binWidth;i++){
    double dummy = hprojy->Integral(i,i+binWidth);
    if(dummy > integ){
      integ = dummy;
      binA = i;
    }
  }
  cout<<"Maximum:\t"<<integ/hprojy->Integral()<<"\t starting at\t"<<hprojy->GetBinCenter(binA)
      <<"\t ending at\t"<<hprojy->GetBinCenter(binA+binWidth)<<endl;
  cout<<"\tcenter at\t"<<hprojy->GetBinCenter(binA+binWidth/2)<<endl;
  double xx[2] = {hprojy->GetBinCenter(binA),hprojy->GetBinCenter(binA)};
  double yy[2] = {0,hprojy->GetMaximum()*1.1};
  string result = Form("%6.3f<>%6.3f Integ %5.3f ;y projection[m]",hprojy->GetBinCenter(binA),hprojy->GetBinCenter(binA+binWidth/2),integ/hprojy->Integral());
  hprojy->SetTitle(result.c_str());
  hprojy->DrawCopy();

  TGraph redLineYa(2,xx,yy);
  redLineYa.SetLineWidth(2);
  redLineYa.SetLineColor(2);
  xx[0] = hprojy->GetBinCenter(binA + binWidth);
  xx[1] = hprojy->GetBinCenter(binA + binWidth);
  TGraph redLineYb(2,xx,yy);
  redLineYb.SetLineWidth(2);
  redLineYb.SetLineColor(2);
  redLineYa.Draw("L");
  redLineYb.Draw("L");

  c2->cd(4);
  TH1F* htrth = new TH1F("htrth", "tr.th", 200, -1, 1);
  TH1F* htrth_cut = new TH1F("htrth_cut", "tr.th with cut", 200, -1, 1);
  T->Project(htrth->GetName(), "L.tr.th[0]", Form("%s && %s", ctrig, vdccut));
  htrth->SetLineColor(kBlue);
  htrth->Draw();
  T->Project(htrth_cut->GetName(), "L.tr.th[0]", Form("%s && %s && L.tr.th[0]<0.05&&L.tr.th[0]>-0.2", ctrig, vdccut), "same");
  htrth_cut->SetLineColor(kRed);
  htrth_cut->Draw("same");
  gPad->SetLogy(1);

  c2->cd(5);
  TH1F* htrph = new TH1F("htrph", "tr.ph", 200, -1, 1);
  TH1F* htrph_cut = new TH1F("htrph_cut", "tr.ph with cut", 200, -1, 1);
  T->Project(htrph->GetName(), "L.tr.ph[0]", Form("%s && %s", ctrig, vdccut));
  htrph->SetLineColor(kBlue);
  htrph->Draw();
  T->Project(htrph_cut->GetName(), "L.tr.ph[0]", Form("%s && %s && L.tr.th[0]>-0.2&&L.tr.ph[0]<0.1&&L.tr.ph[0]>-0.1", ctrig, vdccut), "same");
  htrph_cut->SetLineColor(kRed);
  htrph_cut->Draw("same");
  gPad->SetLogy(1);
 
  c2->cd(3);
  T->Draw("(L.tr.x+0.9*L.tr.th):L.tr.th", 
	  Form("%s && %s && L.tr.th[0]>-0.2&&L.tr.ph[0]<0.1&&L.tr.ph[0]>-0.1 && abs(L.tr.th)<0.05 && abs(L.tr.x)<0.1", ctrig, vdccut));
  gPad->SetGridx(1);
  gPad->SetGridy(1);

  c2->cd(6);
  T->Draw("(L.tr.y+0.9*L.tr.ph):L.tr.ph", 
	  Form("%s && %s && L.tr.th[0]>-0.2&&L.tr.ph[0]<0.1&&L.tr.ph[0]>-0.1 && abs(L.tr.ph)<0.05 && abs(L.tr.y-0.02)<0.1", ctrig, vdccut));
  gPad->SetGridx(1);
  gPad->SetGridy(1);


  if(do_cip_thing)
    {
      TH1D *hP[16];
      TCanvas *c5=new TCanvas("c5","c5",1000,1000);
      c5->Divide(4,4);
      float vdc2q[16]={0.32,0.36,0.40,0.44,0.48,0.52,0.56,0.60,0.64,0.70,0.74,0.78,0.82,0.86,0.94,0.98};
      for(int i=0;i<16;i++){
	hP[i]=new TH1D(Form("hP%d",i),Form("vdc2q %4.2f",vdc2q[i]),300,-0.12,0.12);
	T->Project(hP[i]->GetName(),Form("L.tr.y[0]+%f*L.tr.ph[0]",vdc2q[i]),
		   Form("abs(L.tr.y[0]+%f*L.tr.ph[0])<0.1",vdc2q[i]));
	binA=0;
	integ=0;
	for(int j=1;j<=300 - binWidth;j++){
	  double dummy = hP[i]->Integral(j,j+binWidth);
	  if(dummy > integ){
	    integ = dummy;
	    binA = j;
	  }
	}    
	cout<<"quartz "<<vdc2q[i]<<" m away from vdc"<<endl;
	cout<<"\tMaximum:\t"<<integ/hP[i]->Integral()<<"\t starting at\t"<<hP[i]->GetBinCenter(binA)
	    <<"\t ending at\t"<<hP[i]->GetBinCenter(binA+binWidth)<<endl;
	cout<<"\tcenter at\t"<<hP[i]->GetBinCenter(binA+binWidth/2)<<endl;
	c5->cd(i+1);
	hP[i]->SetTitle(Form("%s %5.3f",hP[i]->GetTitle(),integ/hP[i]->Integral()));
	hP[i]->DrawCopy();
      }
    }


  c2->cd(2);
  TH1F* hprojx = new TH1F("hprojx", "X Projection LHRS", 300, -0.12, 0.12);
  T->Project(hprojx->GetName(),"L.tr.x[0]+0.9*L.tr.th[0]", "abs(L.tr.x[0]+0.9*L.tr.th[0])<0.1 && fEvtHdr.fEvtType==1");

  hprojx->Fit("gaus");

  gPad->SetGridx(1);
  gPad->SetGridy(1);

  c2->Print(Form("OUTPUT/proj_LHRS_%d.pdf", runnum ));
  c2->Print(Form("OUTPUT/proj_LHRS_%d.png", runnum ));
 
/*
Possible cuts: (tail cleanup)
abs(L.tr.th_y[0])<0.2 (in meters)
abs(L.tr.tg_y[0])<0.05
L.tr.pz[0]<5 && L.tr.pz[0]>-100
abs(L.tr.tg_dp[0])<1e2
L.tr.flag[0]<1.2e5 << seems to cut most of the events that we excluded .. what can it be?!
L.tr.chi2[0]<0.004

*/

}
