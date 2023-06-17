#!/bin/bash

# Test hackbench

echo "Test hackbench"

cd ~/
./hackbench 50 process 50

# Test kernbench

echo "Test kernbench"

cd linux-5.15
../kernbench -M -H -f -n 1 | tee >(grep 'Elapsed' | awk '{print $3 }' >> kernbench.txt)

# Test netperf

echo "Test netperf"

cd ~/
kvmperf/cmdline_tests/netperf.sh 192.168.0.101

# Test apache

echo "Test apache"

cd ~/
kvmperf/cmdline_tests/apache.sh 192.168.0.101 3

echo "Done"
