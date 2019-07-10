#!/bin/bash

while read line
do

if [ $line 

analyzer -b <<EOF
gSystem->Load("libraries/FadcRasteredBeam/libTriFadcRasteredBeam.so");
gSystem->Load("../ParityData/libParity_LHRS.so");
.x sanghwa_setup.C($line, 100000)
EOF

#analyzer -b $file <<EOF
#.x showSieveLeft_ciprian.C
#EOF

done <$1
