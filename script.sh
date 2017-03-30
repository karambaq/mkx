#!/bin/bash

filename=$1
g++ -std=c++14 counter.cpp
./a.out $1 && cat result.txt >> "$filename".txt
#cat "$filename".txt
sudo mv "$filename".txt results/
sudo rm result.txt ./a.out
exit 0