#!/bin/bash



#r fijo, n creciente
function rfijo {
  for (( i=$2; i<=$1; i++ ))
  do
    ./a.out $i $2  1 >> data.txt
  done

}

#n fijo y r crece hasta r
function nfijo {
  for (( i=$2; i<=$1; i++ ))
  do
    ./a.out $1 $i  1 >> data.txt
  done
}

rfijo 100 3
#gnuplot -persist <<-EOFMarker
# set title "Tu hermana " font ",14" textcolor rgbcolor "royalblue"
#    plot "data.txt" using 1:2 with lines
#EOFMarker
#Para borrar todo
#echo -n "" > data.txt
# g++ main.cpp -lgmp
