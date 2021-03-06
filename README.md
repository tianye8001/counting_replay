Brief instructions on running the Podd analyzer
This file: /adaqfs/home/a-onl/happexsp/prex/README

R. Michaels, May 3, 2019
Ye Tian, Jun 19, 2019

I. Set up
==========

Type "goprex" on a-onl account on aonl1 or aonl2 to go to the
working directory and set the environment.

We're using the ''official'' (Ole's) analyzer at the moment, but 
with the ParityData class plugin.  I also have a secret version of 
the full software on another account, but we'll try to use 
Ole's version because it will be better supported.

The database is $DB_DIR = ./DB which is a link.  e.g. a link to 
PREXI or PREXII databases.   PREXI is there for test purposes,
while DB_PREXII is linked to DB, which is the current database. 

Our detectors are defined in db_P.dat in the $DB_DIR.
Which variables are written to the root output are defined
in output.def

Input data files are located in the directory:
/adaq1/data1/
prexLHRS_*.dat.* for LHRS run
prexRHRS_*.dat.* for RHRS run

dddImportant files:

db_run.dat -- defines kinematics
db_cratemap.dat -- cratemap.  aprexII map 
onlana.cuts -- cuts file, see Podd documentation
output.def -- output definition, see Podd documentation
rootlogon.C -- loads the libParity_*.so, since the flashadc 
located in different crates, slots for both arms, so we have two libParity_*.so files
for analyzing the data. 
if we want to analyze the LHRS run, we need to load 
 gSystem->Load("../ParityData/libParity_LHRS.so");
if we want to analyze the RHRS run, we need to load
 gSystem->Load("../ParityData/libParity_RHRS.so");

setup.C -- sets up the analyzer (see example below)
show*.C -- various macro examples. (showRight/Leftfadc.C s)
bob.txt -- debug output.  May want to turn off debugging

/***********************************************************************************************/
Running the analyzer, type "analyzer"
[a-onl@aonl1]$ goprex
[a-onl@aonl1 prex]$ pwd
/adaqfs/home/a-onl/happexsp/prex
[a-onl@aonl1 prex]$ vi rootlogon.C  (gSystem->Load("../ParityData/libParity_LHRS.so"); for LHRS
                                     gSystem->Load("../ParityData/libParity_RHRS.so"); for RHRS) 
[a-onl@aonl1 prex]$ analyzer
  ************************************************
  *                                              *
  *            W E L C O M E  to  the            *
  *       H A L L A   C++  A N A L Y Z E R       *
  *                                              *
  *  Release            1.6.6        Apr 25 2019 *
  *  Based on ROOT  6.16/00          Jan 23 2019 *
  *                                              *
  *            For information visit             *
  *        http://hallaweb.jlab.org/podd/        *
  *                                              *
  ************************************************
analyzer [0] .x setup.C(runnumber)  //you need to change the nsplit number to handle more than one split file. prexLHRS_runnumber.dat.0, 1, 2......  
analyzer [1] .x show*.C (analysis scripts. 
"showLeftfadc.C" plots fastbus ADC, fastbus TDC,flash ADC, time-over-threshold of flash ADC distributions for all detectors, VDC hit wires and VDC raw time, and S0 and VDC correlation ) 

***prexRHRS/LHRS_*.root -- the root output. They are located in the directory: /chafs1/work1/prex_counting/  

/***********************************************************************************************/



III. Working with ParityData
=============================
see README_old


IV. Scalers
============
see README_old





