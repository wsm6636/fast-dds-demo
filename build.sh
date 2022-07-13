#!/bin/bash

mkdir build 
cd build
cmake .. -DCMAKE_PREFIX_PATH=~/Fast-DDS/install/
make
