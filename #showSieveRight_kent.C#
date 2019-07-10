{ 
  // Macro to plot sieve pattern

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

  char ctrig[200],vdccut[200],tgtcut[200],tgty[200],ccut[800],cand[5],trcut[200];

  //  sprintf(ctrig,"fEvtHdr.fEvtNum<200000&&(fEvtHdr.fEvtType==1||fEvtHdr.fEvtType==5)");
  sprintf(ctrig,"(fEvtHdr.fEvtType==1)");
  // sprintf(ctrig,"(fEvtHdr.fEvtType==1||fEvtHdr.fEvtType==5)");

  // HRS = R.* or L.*

  // only one cluster in each VDC plane

  sprintf(vdccut,"(R.vdc.u1.nclust==1&&R.vdc.v1.nclust==1&&R.vdc.u2.nclust==1&&R.vdc.v2.nclust==1)");

  // Cut for crap tracks

  sprintf(trcut,"(R.tr.th[0]<0.05&&R.tr.th[0]>-0.2&&R.tr.ph[0]<0.1&&R.tr.ph[0]>-0.1)");


  sprintf(cand,"&&");

  // Build the total cut

  strcpy(ccut,ctrig);
  strcat(ccut,cand);
  strcat(ccut,vdccut);
  strcat(ccut,cand);
  strcat(ccut,trcut);

  cout << "Cuts used : "<<endl;

  TCanvas c0;

  cout << ccut << endl;

  //TH2F *htgthph = new TH2F("htgthph","Target theta-phi (theta vertical)",100,-0.06,0.06,100,-0.1,0.1);

  TH2F *htgthph = new TH2F("htgthph","RHRS Target theta-phi (theta vertical)",200,-0.03,0.03,200,-0.07,0.07);

  T->Draw("R.gold.th:R.gold.ph>>htgthph",ccut);

  TCanvas c1;
  // c1->Divide(2,1);
  // c1->cd(1);
  htgthph->Draw();
  c1.SaveAs("RightSieve.pdf");

  gStyle->SetOptStat(1);
  gStyle->SetOptFit(1111);
  gPad->SetGridx(1);
  gPad->SetGridy(1);
  TCanvas* c2 = new TCanvas("c2", "c2", 1200, 700);
  c2->Divide(2,1);
  c2->cd(1);
  TH1F* hprojy = new TH1F("hprojy", "Y Projection RHSR", 300, -0.12, 0.12);
  //  T->Project(hprojy->GetName(),"R.tr.y[0]+0.9*R.tr.ph[0]", "abs(R.tr.y[0]+0.9*R.tr.ph[0])<0.1");
  T->Project(hprojy->GetName(),"R.tr.y[0]+0.9*R.tr.ph[0]", ccut);
  //  hprojy->Fit("gaus");

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

  TH1D *hP[4];
  TCanvas *c5=new TCanvas("c5","c5",1000,1000);
  c5->Divide(2,2);
  float vdc2q[4]={0.82,0.86,0.94,0.98};
  for(int i=0;i<4;i++){
    hP[i]=new TH1D(Form("hP%d",i),Form("vdc2q %4.2f",vdc2q[i]),300,-0.12,0.12);
    T->Project(hP[i]->GetName(),Form("R.tr.y[0]+%f*R.tr.ph[0]",vdc2q[i]),
	       Form("abs(R.tr.y[0]+%f*R.tr.ph[0])<0.1",vdc2q[i]));
    c5->cd(i+1);
    hP[i]->DrawCopy();
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
  }

  //  TCanvas c3;
  c2->cd(2);
  TH1F* hprojx = new TH1F("hprojx", "X Projection RHRS", 300, -0.12, 0.12);
  T->Project(hprojx->GetName(),"R.tr.x[0]+0.9*R.tr.th[0]", "abs(R.tr.x[0]+0.9*R.tr.th[0])<0.1");
  //  T->Draw("R.tr.x[0]+0.9*R.tr.th[0]", "abs(R.tr.x[0]+0.9*R.tr.th[0])<0.1");
  hprojx->Fit("gaus");

  gPad->SetGridx(1);
  gPad->SetGridy(1);


  c2->Print("proj_RHRS_kent.pdf");


  TFile* fout = new TFile("out_kent.root","RECREATE");
  fout->cd();
  htgthph->Write();
  hprojy->Write();
  hprojx->Write();
  fout->Close();


}
