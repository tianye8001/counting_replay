# Analyzer output definition file used by THaOutput class.
# See  http://hallaweb.jlab.org/root/THaOutput.html

begin epics
   hac_bcm_average
   IPM1H04A.XPOS
   IPM1H04A.YPOS
   IPM1H04E.XPOS
   IPM1H04E.YPOS
end epics


# THaScalerEvtHandler vars
#variable LeftTSbcmu1	
#variable LeftTSbcmu1r	
#variable RightTSbcmu1	
#variable RightTSbcmu1r	
#variable RightTSbcmu3	
#variable RightTSbcmu3r

# this makes a BIG output and slows the code
block L.*
block R.*

block *Raster*
#block L.BPMA*
#block L.BPMB*
#block R.BPMA*
#block R.BPMB*

block P.*

block EK_L.*
block EK_R.*
	
# Tracking variables
variable L.tr.n
variable L.tr.x
variable L.tr.y
variable L.tr.th
variable L.tr.ph
variable L.tr.d_x
variable L.tr.d_y
variable L.tr.d_th
variable L.tr.d_ph
variable L.tr.r_x
variable L.tr.r_y
variable L.tr.r_th
variable L.tr.r_ph
variable L.tr.tg_y
variable L.tr.tg_th
variable L.tr.tg_ph
variable L.tr.tg_dp
variable L.tr.p
variable L.gold.x
variable L.gold.y
variable L.gold.th
variable L.gold.ph
variable L.gold.dp
variable L.gold.ok
variable L.gold.p
formula L.sv.x L.gold.x+0.8*L.gold.th
formula L.sv.y L.gold.y+0.8*L.gold.ph
formula L.projx L.tr.x+0.8*L.tr.th
formula L.projy L.tr.y+0.8*L.tr.ph

variable R.tr.n
variable R.tr.x
variable R.tr.y
variable R.tr.th
variable R.tr.ph
variable R.tr.d_x
variable R.tr.d_y
variable R.tr.d_th
variable R.tr.d_ph
variable R.tr.r_x
variable R.tr.r_y
variable R.tr.r_th
variable R.tr.r_ph
variable R.tr.tg_y
variable R.tr.tg_th
variable R.tr.tg_ph
variable R.tr.tg_dp
variable R.gold.x
variable R.gold.y
variable R.gold.th
variable R.gold.ph
variable R.gold.dp
variable R.gold.ok
formula R.sv.x R.gold.x+0.8*R.gold.th
formula R.sv.y R.gold.y+0.8*R.gold.ph
formula R.projx R.tr.x+0.8*R.tr.th
formula R.projy R.tr.y+0.8*R.tr.ph

#  Beam position from unrastered beam, BPMA and BPMB
#variable urb.BPMA.x
#variable urb.BPMA.y
#variable urb.BPMB.x
#variable urb.BPMB.y


# ------------------------------------------------------------------
# DETECTOR CHECK OUT HISTOGRAMS 
# ------------------------------------------------------------------
#
# ------------------------------------------------------------------
# LEFT ARM DETECTORS 
# ------------------------------------------------------------------
#
# LEFT ARM S2 (used in APEX but not in PREX)

TH1F Ls2lt 'Left arm S2 L-PMT TDCs' L.s2.lt 750 1001 2500 L.s2.lt>0.
TH1F Ls2rt 'Left arm S2 R-PMT TDCs' L.s2.rt 750 1001 2500 L.s2.rt>0.

TH1F Ls2la 'Left arm S2 L-PMT ADCs' L.s2.la 150 281 880 L.s2.la>0.
TH1F Ls2ra 'Left arm S2 R-PMT ADCs' L.s2.ra 150 281 880 L.s2.ra>0.

#TH1F Ls2la_p 'Left arm S2 L-PMT ADCs (PedSub)' L.s2.la_p 150 -10 299 L.s2.la_p>0.
#TH1F Ls2ra_p 'Left arm S2 R-PMT ADCs (PedSub)' L.s2.ra_p 150 -10 299 L.s2.ra_p>0.

# ------------------------------------------------------------------
# LEFT ARM VDC wires and timing  :

TH1F Lvu1t 'L-arm VDC u1 time' L.vdc.u1.rawtime 200 401 3200 
TH1F Lvu2t 'L-arm VDC u2 time' L.vdc.u2.rawtime 200 401 3200 
TH1F Lvv1t 'L-arm VDC v1 time' L.vdc.v1.rawtime 200 401 3200 
TH1F Lvv2t 'L-arm VDC v2 time' L.vdc.v2.rawtime 200 401 3200 

TH1F Lvu1w 'L-arm VDC u1 wires' L.vdc.u1.wire 400 1 400 
TH1F Lvu2w 'L-arm VDC u2 wires' L.vdc.u2.wire 400 1 400 
TH1F Lvv1w 'L-arm VDC v1 wires' L.vdc.v1.wire 400 1 400 
TH1F Lvv2w 'L-arm VDC v2 wires' L.vdc.v2.wire 400 1 400 

TH1F Lvu1nhit 'L-arm VDC u1 TDC channel hits ' L.vdc.u1.nthit 20 0 10
TH1F Lvu2nhit 'L-arm VDC u2 TDC channel hits ' L.vdc.u2.nthit 20 0 10
TH1F Lvv1nhit 'L-arm VDC v1 TDC channel hits ' L.vdc.v1.nthit 20 0 10
TH1F Lvv2nhit 'L-arm VDC v2 TDC channel hits ' L.vdc.v2.nthit 20 0 10

# ------------------------------------------------------------------
# RIGHT ARM DETECTORS 
# ------------------------------------------------------------------
#
# RIGHT ARM S2 (only since S1 removed)  ADC and TDC :

TH1F Rs2lt 'Right arm S2 L-PMT TDCs' R.s2.lt 1000 501 3000 R.s2.lt>0.
TH1F Rs2rt 'Right arm S2 R-PMT TDCs' R.s2.rt 1000 501 3000 R.s2.rt>0.

TH1F Rs2la 'Right arm S2 L-PMT ADCs' R.s2.la 150 200 880 R.s2.la>0.
TH1F Rs2ra 'Right arm S2 R-PMT ADCs' R.s2.ra 150 200 880 R.s2.ra>0.

#TH1F Rs2la_p 'Right arm S2 L-PMT ADCs (PedSub)' R.s2.la_p 150 -10 299 R.s2.la_p>0.
#TH1F Rs2ra_p 'Right arm S2 R-PMT ADCs (PedSub)' R.s2.ra_p 150 -10 299 R.s2.ra_p>0.


# ------------------------------------------------------------------
# RIGHT ARM VDC wires and timing  :

TH1F Rvu1t 'R-arm VDC u1 time' R.vdc.u1.rawtime 200 401 3200 
TH1F Rvu2t 'R-arm VDC u2 time' R.vdc.u2.rawtime 200 401 3200 
TH1F Rvv1t 'R-arm VDC v1 time' R.vdc.v1.rawtime 200 401 3200 
TH1F Rvv2t 'R-arm VDC v2 time' R.vdc.v2.rawtime 200 401 3200 

TH1F Rvu1w 'R-arm VDC u1 wires' R.vdc.u1.wire 400 1 400 
TH1F Rvu2w 'R-arm VDC u2 wires' R.vdc.u2.wire 400 1 400 
TH1F Rvv1w 'R-arm VDC v1 wires' R.vdc.v1.wire 400 1 400 
TH1F Rvv2w 'R-arm VDC v2 wires' R.vdc.v2.wire 400 1 400 

TH1F Rvu1nhit 'R-arm VDC u1 TDC channel hits ' R.vdc.u1.nthit 20 0 10
TH1F Rvu2nhit 'R-arm VDC u2 TDC channel hits ' R.vdc.u2.nthit 20 0 10
TH1F Rvv1nhit 'R-arm VDC v1 TDC channel hits ' R.vdc.v1.nthit 20 0 10
TH1F Rvv2nhit 'R-arm VDC v2 TDC channel hits ' R.vdc.v2.nthit 20 0 10


# TH2F BPMAxy 'Beam position from BPMA' urb.BPMA.x urb.BPMA.y 40 -0.005 0.005 40 -0.005 0.005 
# TH2F BPMBxy 'Beam position from BPMB' urb.BPMB.x urb.BPMB.y 40 -0.005 0.005 40 -0.005 0.005 

# ---------------------------------------------------------------------
# Single arm TRACK reconstruction plots :
#  NB: the cuts are defined in the cut file (onlana.cuts)
#  NB2: this is a merging of e04012 plots and optics.odef plots

TH1F Rntrk 'R-arm number of tracks' R.tr.n 20 -1 9
TH1F Rtrx  'R-arm X distribution' R.tr.r_x 50 -1 1
TH2F Rxydet 'R-arm VDC ydet:xdet' R.tr.d_x R.tr.d_y 50 -1 1 50 -.2 .2 
TH2F Rxydet2 'R-arm VDC ydet:xdet' R.tr.d_x R.tr.d_y 50 -1 1 50 -.2 .2 
TH2F Rxyfp 'R-arm yfp:xfp' R.tr.x R.tr.y 50 -1 1 50 -.2 .2     
TH2F Rthphfp 'R-arm phfp:thfp' R.tr.th R.tr.ph 50 -.2 .2 50 -0.1 0.1 
TH2F Rxthfp 'R-arm thfp:xfp' R.tr.x R.tr.th 50 -1 1 50 -.2 .2     
TH2F Ryphfp 'R-arm phfp:yfp' R.tr.y R.tr.ph 50 -.2 .2 50 -0.1 0.1  
TH1F Rytg  'R-arm ytg'     R.gold.y  250 -0.1 0.1             
TH2F Rthphtg 'R-arm tgt th:ph' R.gold.ph R.gold.th 50 -0.04 0.04 50 -0.08 0.08
TH2F Rtga  'R-arm tgt theta-phi' R.tr.tg_ph R.tr.tg_th 50 -0.05 0.05 100 -0.1 0.1
TH2F Rxysv 'R-arm sieve y:x' R.sv.x R.sv.y 50 -.1 .1 50 -.1 .1  
TH1F Rdp   'R-arm delta'   R.gold.dp 1000 -0.06 0.06          
TH1F Rtgdp  'R-arm momentum' R.tr.tg_dp 100 -0.2 0.2
TH1F Rdpctr 'R-arm delta center hole' R.gold.dp 1000 -0.05 0.05  
TH1F Rmom  'R-arm momentum' R.gold.p 200 0 3.2         
TH2F Rdpphtg 'R-arm delta:ph_tg' R.gold.dp R.gold.ph 50 -0.06 0.06 50 -0.04 0.04
TH2F Rxfpphtg 'R-arm xfp:ph_tg' R.tr.x R.gold.ph 50 -1 1 50 -0.04 0.04
TH2F Ryrytg  'R-arm yrot:ytg'  R.gold.y R.tr.r_y 50 -0.05 0.05 50 -.1 .1 
TH2F Rphrytg 'R-arm phrot:ytg' R.gold.y R.tr.r_ph 50 -0.05 0.05 50 -0.05 0.05

TH1F Lntrk 'L-arm number of tracks' L.tr.n 20 -1 9
TH2F Ltga  'L-arm tgt theta-phi' L.tr.tg_ph L.tr.tg_th 50 -0.05 0.05 100 -0.1 0.1
TH1F Ltrn  'L-arm number of tracks' L.tr.n 20 -0.5 10.5
TH2F Lxydet 'L-arm VDC ydet:xdet' L.tr.d_x L.tr.d_y 50 -1 1 50 -.2 .2 
TH2F Lxyfp 'L-arm yfp:xfp' L.tr.x L.tr.y 50 -1 1 50 -.2 .2     
TH2F Lthphfp 'L-arm phfp:thfp' L.tr.th L.tr.ph 50 -.2 .2 50 -0.1 0.1
TH2F Lxthfp 'L-arm thfp:xfp' L.tr.x L.tr.th 50 -1 1 50 -.2 .2     
TH2F Lyphfp 'L-arm phfp:yfp' L.tr.y L.tr.ph 50 -.2 .2 50 -0.1 0.1 
TH1F Lytg  'L-arm ytg'     L.gold.y  250 -0.1 0.1             
TH2F Lthphtg 'L-arm tgt th:ph' L.gold.ph L.gold.th 50 -0.04 0.04 50 -0.08 0.08 
TH2F Lxysv 'L-arm sieve y:x' L.sv.x L.sv.y 50 -.1 .1 50 -.1 .1 
TH1F Ldp   'L-arm delta'   L.gold.dp 1000 -0.06 0.06         
TH1F Ltgdp  'L-arm momentum' L.tr.tg_dp 100 -0.2 0.2
TH1F Ldpctr 'L-arm delta center hole' L.gold.dp 1000 -0.05 0.05 

# Podd thinks P.upQadcL is a vector.  but this works.  same loQadcL.
TH1F upQadcL  'L-arm upper main Quartz' P.upQadcL[0] 100 0  2000
TH1F loQadcL  'L-arm lower main Quartz' P.loQadcL 100 0  2000
TH1F atlQadcL 'L-arm left A_T Quartz'  P.atlQadcL 100 0  2000
TH1F atrQadcL 'L-arm right A_T Quartz' P.atlQadcL 100 0  2000
TH1F upfadcQL  'L-arm upper main Quartz (FADC)' P.fadcUQL 1000 20000 35000
TH1F lofadcQL  'L-arm upper main Quartz (FADC)' P.fadcDQL 1000 20000 35000

TH1F upQadcR 'R-arm upper main Quartz' P.upQadcR 100 0  2000
TH1F loQadcR 'R-arm lower main Quartz' P.upQadcR 100 0  2000
TH1F atlQadcR 'R-arm left A_T Quartz'  P.atlQadcR 100 0  2000
TH1F atrQadcR 'R-arm right A_T Quartz' P.atlQadcR 100 0  2000
TH1F upfadcQR  'R-arm upper main Quartz (FADC)' P.fadcUQR 1000 7000 20000
TH1F lofadcQR  'R-arm upper main Quartz (FADC)' P.fadcDQR 1000 7000 20000

TH1F S0AtdcL 'L-arm S0A TDC ' P.S0AtdcL 100 0 2200
TH1F S0BtdcL 'L-arm S0B TDC ' P.S0BtdcL 100 0 2200
TH1F S0AadcL 'L-arm S0A ADC ' P.S0AadcL 100 0 6000
TH1F S0BadcL 'L-arm S0B ADC ' P.S0BadcL 100 0 6000

TH1F S0AtdcR 'R-arm S0A TDC ' P.S0AtdcR 100 0 2200
TH1F S0BtdcR 'R-arm S0B TDC ' P.S0BtdcR 100 0 2200
TH1F S0AadcR 'R-arm S0A ADC ' P.S0AadcR 100 0 6000
TH1F S0BadcR 'R-arm S0B ADC ' P.S0BadcR 100 0 6000

# can also do S3

#---------------------------RASTER PLOTS---------------------------------
# Left arm Raster current x and y
TH2F LrbRasterMap 'Lrb.Raster2.rawcur.y:x ' Lrb.Raster2.rawcur.x Lrb.Raster2.rawcur.y 250 0 100e3 250 0 100e3
TH1F LrbRaster2CurrentX 'Lrb.Raster2.rawcur.x ' Lrb.Raster2.rawcur.x 250 0 100e3
TH1F LrbRaster2CurrentY 'Lrb.Raster2.rawcur.y ' Lrb.Raster2.rawcur.y 250 0 100e3

# Right arm Raster current x and y
TH2F RrbRasterMap 'Rrb.Raster2.rawcur.x:y ' Rrb.Raster2.rawcur.y Rrb.Raster2.rawcur.x 250 0 100e3 250 0 100e3
TH1F RrbRaster2CurrentY 'Rrb.Raster2.rawcur.y ' Rrb.Raster2.rawcur.y 250 0 100e3
TH1F RrbRaster2CurrentX 'Rrb.Raster2.rawcur.x ' Rrb.Raster2.rawcur.x 250 0 100e3


#---------------------------Track XY and Projection PLOTS---------------------------------
# Left arm
TH2F tr_xyL 'Left track x vs y' L.tr.x L.tr.y  100, -0.05, 0.05, 100, -0.05, 0.05
TH2F tr_projxyL 'Left track x vs y projection at Quartz' L.projx L.projy  100, -0.05, 0.05, 100, -0.05, 0.05
TH2F tr_projxthL 'Left track projx vs th at Quartz' L.tr.th L.projx 100, -0.05, 0.05, 100, -0.05, 0.05
TH2F tr_projythL 'Left track projy vs ph at Quartz' L.tr.ph L.projy 100, -0.05, 0.05, 100, -0.05, 0.05

# Right arm
TH2F tr_xyR 'Right track x vs y' R.tr.x R.tr.y  100, -0.05, 0.05, 100, -0.05, 0.05
TH2F tr_projxyR 'Right track x vs y projection at Quartz' R.projx R.projy  100, -0.05, 0.05, 100, -0.05, 0.05
TH2F tr_projxthR 'Right track projx vs th at Quartz' R.tr.th R.projx 100, -0.05, 0.05, 100, -0.05, 0.05
TH2F tr_projythR 'Right track projy vs ph at Quartz' R.tr.ph R.projy 100, -0.05, 0.05, 100, -0.05, 0.05
