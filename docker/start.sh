#!/bin/bash
cd diseasetrack
mv /tmp/privkey.key /diseasetrack/privkey.pem
mv /tmp/fullchain.crt /diseasetrack/fullchain.pem
./bazel-bin/apps/DaemonApp
