#!/bin/bash

EXE=a.out

if [ $! -eq 0 ]; then


exit
a=`ls`

echo $a

for f in $a; do
echo $f
done



exit

if [ -e $EXE ]; then
rm $EXE
fi
g++ vector.cpp matrix.cpp solver.cpp main.cpp

if [ -e $EXE ]; then
./$EXE
fi
