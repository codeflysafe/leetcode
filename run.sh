#!/bin/bash

files=`find ./leetcode -name "$1*.cpp"`
#echo "files are $files"

for file in ${files[*]}
do
  echo "run $file";
  echo `g++ -std=c++11 -I ./include $file -o lc.o && ./lc.o`
  echo "$file end"
  rm -rf ./lc.o
done