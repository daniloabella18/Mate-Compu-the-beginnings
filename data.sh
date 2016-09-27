#!/bin/bash

r=2
g++ main.cpp -lgmp
for i in {4..100}
do
  ./a.out $i $r  1
done
