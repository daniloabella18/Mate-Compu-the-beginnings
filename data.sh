#!/bin/bash
#g++ main.cpp -lgmp && ./a.out 4 3 1

#n fijo y r crece hasta r
function nfijo {
  for (( i=$2; i<=$1; i++ ))
  do
    ./a.out $1 $i  1 >> data.txt
  done
}

#r fijo, n creciente
function rfijo {
  for (( i=$2; i<=$1; i++ ))
  do
    ./a.out $i $2  1 >> data.txt
  done

}



echo "Elija una opción"
echo "1. Graficar para n fijo y r crece hasta n"
echo "2. Graficar para r fijo y y que crezca desde r hasta n"
read opcion
if [[ "$opcion" == 1 ]]; then
  nfijo 100 3
elif [[ "$opcion" == 2 ]]; then
  rfijo 100 3
fi
#gnuplot -persist <<-EOFMarker
# set title "Tu hermana " font ",14" textcolor rgbcolor "royalblue"
#    plot "data.txt" using 1:2 with lines
#EOFMarker
#Para borrar todo
#echo -n "" > data.txt
# g++ main.cpp -lgmp
