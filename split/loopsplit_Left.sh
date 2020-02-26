#!/bin/tcsh -f
for i in `seq $1 $2`;
do
echo $i
sed -e s/fileN/$i/ _loopsplit_Left.sh  >loopsplit_Left_$i.sh
. loopsplit_Left_$i.sh
done
