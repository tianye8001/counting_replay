{

  T->Draw("R.tr.x[0]+2*R.tr.th[0]:R.tr.y[0]+2*R.tr.ph[0]>>h(200,-0.05,0.1,100,-0.05,0.1)","(abs(R.tr.y[0]+0.2*R.tr.ph[0])<0.02 && abs(R.tr.x[0]+0.2*R.tr.th[0])<0.1)*R.tr.tg_th[0]","colz");


}
