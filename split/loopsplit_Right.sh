#!/bin/tcsh -f
for i in `seq $1 $2`;
do
echo $i
sed -e s/fileN/$i/ _loopsplit_Right.sh  >loopsplit_Right_$i.sh
. loopsplit_Right_$i.sh
done
