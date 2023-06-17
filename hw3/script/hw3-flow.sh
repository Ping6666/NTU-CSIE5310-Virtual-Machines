#!/bin/bash

# Test hackbench

echo "Test hackbench"

cd ~/
./hackbench 50 process 50

# Test kernbench

echo "Test kernbench"

cd linux-5.15
../kernbench -M -H -f -n 1 | tee >(grep 'Elapsed' | awk '{print $3 }' >> kernbench.txt)

echo "Done"
