#!/bin/bash
#g++ main.cpp -lgmp && ./a.out 4 3 1


#n fijo y r crece hasta n
#n=$1 r=$2 $3=metodo
function nFijo {
  echo -n "" > Informe/Metodo$3/plot$1m$3.txt
  for (( i=$2; i<=$1; i++ ))
  do
    echo $(./a.out $1 $i $3) $i >> Informe/Metodo$3/plot$1m$3.txt
  done
  gnuplot -persist <<-EOFMarker
   set title "Metodo $3 \n{/*0.8 r creciente con n = $1}" font ",14" textcolor rgbcolor "royalblue"
   set nokey
   set ylabel "Tiempo"
   set format y "%7.3f"
   set xlabel "r"
   set format y "%.7f"
   set term png
   set output "Informe/Metodo$3/plot$1m$3.png"
   plot "Informe/Metodo$3/plot$1m$3.txt"  using 3:2 with lines
EOFMarker
}



echo "Se están creando las gráficas, por favor espere"
for (( j = 1; j <= 5; j++ )); do

  n=300
  r=1
  nFijo $n $r $j

  n=500
  r=1
  nFijo $n $r $j

  n=300
  r=1
  nFijo $n $r $j

done
