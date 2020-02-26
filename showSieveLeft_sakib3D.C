{ 
// Macro to plot sieve pattern

// Need to modify these two variables to find all peaks  if necessary
   Double_t sigma= 2.5; // Resolve this much width around peak
   Double_t threshhold=4; // Relative height of peak to highest peak.  Cut off everything below this.
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
// HRS = R.* or L.*

// only one cluster in each VDC plane
TCut ctrig="fEvtHdr.fEvtNum<200000  && fEvtHdr.fEvtType==1"; // cut on event number and trigger
TCut vdccut="L.vdc.u1.nclust==1&&L.vdc.v1.nclust==1&&L.vdc.u2.nclust==1&&L.vdc.v2.nclust==1"; // cut on number of clusters
TCut hutcut="L.tr.x[0]>=-0.05 && L.tr.x[0]<=0.1  && L.tr.y[0]<=0.02 && L.tr.y[0]>=-0.05&& L.tr.th[0]>=-0.02 && L.tr.th[0]<=0.02 && L.tr.ph[0]>=-0.04 && L.tr.ph[0]<=0.03"; //cut on transport coordinates in detector hut
TCut totalcut=ctrig && vdccut && hutcut;
cout << "Cuts used : "<<  endl;
cout << totalcut <<endl;

std::map<TString, Float_t> x;
std::map<TString, Float_t> y;
std::map<TString, Float_t> integral;
std::map<TString, TCut> cut;
std::vector<TH2F*> h;
std::vector<TCanvas*> c;


TCanvas c1("c1","c1", 1200,900);
c1.SetLogz();
TH2F *htgthph= new TH2F("htgthph","",200,-0.04,0.04,200,-0.1,0.05);
T->Draw("L.gold.th[0]:L.gold.ph[0]>>htgthph", totalcut, "colz");
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
Int_t nfound=s.SearchHighRes(source,dest,200,200,2.5,4,kTRUE,3,kFALSE,3);

s.Print();
TCanvas c2("c2","c2",1200,900);
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
h.push_back(new TH2F(Form("h%i",i),Form("h%i",i), 200,-0.04,0.04,200, -0.1,0.05));
T->Draw(Form("L.gold.th[0]:L.gold.ph>>h%i",i), totalcut && Form("sqrt((L.gold.ph[0]-(%f))^2+(L.gold.th[0]-(%f))^2)<0.004",fPositionX[i], fPositionY[i]),"colz"); 
TLatex *l=new TLatex(1.02*fPositionX[i],1.02*fPositionY[i], Form("(%1.3f,%1.3f)",fPositionX[i], fPositionY[i]));
l->SetTextSize(0.025);
htgthph->GetListOfFunctions()->Add(l);
std::cout<<  "Phi: "<<fPositionX[i]<< "\t Theta:"<<fPositionY[i]<<"\t Integral:"<< h[i]->Integral()<< std::endl;
}

TPolyMarker * pm = (TPolyMarker*)htgthph->GetListOfFunctions()->FindObject("TPolyMarker");
if (pm) {
      htgthph->GetListOfFunctions()->Remove(pm);
      delete pm;
}
pm = new TPolyMarker(nfound, fPositionX, fPositionY);
htgthph->GetListOfFunctions()->Add(pm);
pm->SetMarkerStyle(23);
pm->SetMarkerColor(kRed);
pm->SetMarkerSize(1.3);
c1.cd();
htgthph->Draw("colz");

}
