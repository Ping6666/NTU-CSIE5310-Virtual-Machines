#!/bin/bash

# Test netperf

echo "Test netperf"

cd ~/
kvmperf/cmdline_tests/netperf.sh 192.168.0.105

# Test apache

echo "Test apache"

cd ~/
kvmperf/cmdline_tests/apache.sh 192.168.0.105 3

echo "Done"
