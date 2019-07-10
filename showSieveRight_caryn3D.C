{ 
// Macro to plot sieve pattern

// Need to modify these two variables to find all peaks  if necessary
   Double_t sigma= 3.5; // Resolve this much width around peak
   Double_t threshhold=3; // Relative height of peak to highest peak.  Cut off everything below this.
   Int_t np=200;
   Int_t nt=200;
   Float_t p1=-0.055;
   Float_t p2=0.025;
   Float_t t1=-0.06;
   Float_t t2=0.06;
   Int_t run;
//
   gROOT->Reset();

   gStyle->SetOptStat(0);
   gStyle->SetStatH(0.3);
   gStyle->SetStatW(0.3);


   gStyle->SetTitleH(0.09);
   gStyle->SetTitleW(0.3);
   gStyle->SetLabelSize(0.04,"x");
   gStyle->SetLabelSize(0.04,"y");
   gROOT->ForceStyle();
   gStyle->SetPalette(kInvertedDarkBodyRadiator);
// "gold" track is at the target.  For more info, see
// http://hallaweb/podd/doc/variables.html


// Trigger choice : scintillator trigger
//  HAPPEXII want T1(R-HRS) or T3(L-HRS)
//  HAPPEXIII want T2
//  PREX  want T5 but we'd probably rather use T1 -- it is S0 trigger
//  GMp run 21283 or 21284 wants T1

// int itrig = 5;
 // sprintf(ctrig,"fEvtHdr.fEvtType==%d",itrig);
 //sprintf(ctrig,"fEvtHdr.fEvtNum<20000&&(fEvtHdr.fEvtType==1||fEvtHdr.fEvtType==5)");
// sprintf(ctrig,"fEvtHdr.fEvtNum<200000  && fEvtHdr.fEvtType==1");
// HRS = R.* or R.*

// only one cluster in each VDC plane
TCut ctrig="fEvtHdr.fEvtNum<200000  && fEvtHdr.fEvtType==1"; // cut on event number and trigger
TCut vdccut="R.vdc.u1.nclust==1&&R.vdc.v1.nclust==1&&R.vdc.u2.nclust==1&&R.vdc.v2.nclust==1"; // cut on number of clusters
//TCut hutcut="R.tr.x[0]>=-0.05 && R.tr.x[0]<=0.1  && R.tr.y[0]<=0.02 && R.tr.y[0]>=-0.05&& R.tr.th[0]>=-0.02 && R.tr.th[0]<=0.02 && R.tr.ph[0]>=-0.04 && R.tr.ph[0]<=0.03"; //cut on transport coordinates in detector hut
//TCut tgcut=""; //cut on transport coordinates in target
TCut totalcut=ctrig && vdccut ;
cout << "Cuts used : \n"<< totalcut <<endl;

std::map<TString, Float_t> x;
std::map<TString, Float_t> y;
std::vector<TH2F*> h;


TCanvas c1("c1","c1", 1200,900);
c1.SetLogz();
TH2F *htgthph= new TH2F("htgthph","",np,p1,p2,nt,t1,t2);
T->Draw("R.gold.th[0]:R.gold.ph[0]>>htgthph", totalcut, "colz");
TH2F* htgthph1=(TH2F *)htgthph->Clone("");
htgthph1->SetName("htgthph1");

TSpectrum2 s(80);
Double_t** source =new Double_t*[200];
Double_t** dest= new Double_t*[200];

for (int i=0;i<200;i++){
	source[i]=new Double_t[200];
        dest[i]=new Double_t[200];
}
for (int i=0;i<200;i++){
	for (int j=0;j<200;j++){
	source[i][j]=htgthph->GetBinContent(i+1,j+1);
}
}
Int_t nfound=s.SearchHighRes(source,dest,200,200,sigma,threshhold,kTRUE,3,kFALSE,3);

s.Print();
TCanvas c2("c2","c2",1400,1100);
Float_t fPositionX[80];
Float_t fPositionY[80];
Double_t *xpeaks= s.GetPositionX();
Double_t *ypeaks= s.GetPositionY();
for(int i=0;i<nfound;i++){
Int_t xbins= 1+Int_t(xpeaks[i]+0.5);
Int_t ybins= 1+Int_t(ypeaks[i]+0.5);
fPositionX[i]=htgthph->GetXaxis()->GetBinCenter(xbins);
fPositionY[i]=htgthph->GetYaxis()->GetBinCenter(ybins);
c2.SetLogz();
h.push_back(new TH2F(Form("h%i",i),Form("h%i",i), np,p1,p2,nt, t1,t2));
T->Draw(Form("R.gold.th[0]:R.gold.ph>>h%i",i), totalcut && Form("sqrt((R.gold.ph[0]-(%f))^2+(R.gold.th[0]-(%f))^2)<0.004",fPositionX[i], fPositionY[i]),"colz"); 
Float_t fraction=100*h[i]->Integral()/htgthph->Integral();
TLatex *l=new TLatex(1.02*fPositionX[i],1.02*fPositionY[i], Form("(%1.3f,%1.3f)",fPositionX[i], fPositionY[i]));
TLatex *l1=new TLatex(1.02*fPositionX[i],1.02*fPositionY[i], Form("%1.2f ",fraction));
l->SetTextSize(0.023);
l->SetTextColor(kBlue);
l1->SetTextSize(0.023);
l1->SetTextColor(kBlue);
htgthph->GetListOfFunctions()->Add(l);
htgthph1->GetListOfFunctions()->Add(l1);
printf("Phi: %1.3f, Theta: %1.3f, Integral: %1.1f\n", fPositionX[i],fPositionY[i],fraction);
}






TPolyMarker * pm = (TPolyMarker*)htgthph->GetListOfFunctions()->FindObject("TPolyMarker");
if (pm) {
      htgthph->GetListOfFunctions()->Remove(pm);
      delete pm;
}
pm = new TPolyMarker(nfound, fPositionX, fPositionY);
htgthph->GetListOfFunctions()->Add(pm);
htgthph1->GetListOfFunctions()->Add(pm);
pm->SetMarkerStyle(23);
pm->SetMarkerColor(kRed);
pm->SetMarkerSize(1.3);
c1.cd();
//delete c1;
htgthph->Draw("colz");
c2.cd();
htgthph1->Draw("colz");



}
