#!/bin/sh
./downloadassets.sh
make -C src/ SWITCH=1 clean
make -C src/ SWITCH=1