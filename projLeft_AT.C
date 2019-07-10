{

  T->Draw("L.tr.x[0]+2*L.tr.th[0]:L.tr.y[0]+2*L.tr.ph[0]>>h(200,-0.1,0,100,-0.05,0.1)","(abs(L.tr.y[0]+0.2*L.tr.ph[0])<0.02 && abs(L.tr.x[0]+0.2*L.tr.th[0])<0.1)*L.tr.tg_th[0]","colz");

}
