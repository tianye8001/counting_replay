#!/bin/tcsh -f
for i in `seq $1 $2`;
do
echo $i
sed -e s/fileN/$i/ _loopsplit_2144.sh  >loopsplit_2144_$i.sh
. loopsplit_2144_$i.sh
done
