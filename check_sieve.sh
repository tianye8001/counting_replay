#!/bin/bash

run=$1

analyzer -x -q "setup2.C(${run},50000)"

root -b<<EOF
.x scanPlots.C(${run})
EOF

evince sieve_check.pdf &
