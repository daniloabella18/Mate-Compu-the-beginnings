#!/bin/bash
#g++ main.cpp -lgmp && ./a.out 4 3 1



#Esto esta malo hasta que se resuelva la estructura de los gráficos

#n fijo y r crece hasta n
#n=$1 r=$2 $3=metodo
function nFijo {
  echo -n "" > Informe/Metodo$3/data1.txt
  for (( i=$2; i<=$1; i++ ))
  do
    echo $(./a.out $1 $i $3) $i >> Informe/Metodo$3/data1.txt
  done
  gnuplot -persist <<-EOFMarker
   set title "Metodo $3 \n{/*0.8 r creciente}" font ",14" textcolor rgbcolor "royalblue"
   set nokey
   set ylabel "Tiempo"
   set format y "%7.3f"
   set xlabel "r"
   set format y "%.7f"
   set term png
   set output "Informe/Metodo$3/plot1m$3.png"
      plot "Informe/Metodo$3/data1.txt"  using 3:2 with lines
EOFMarker
}

#r fijo, n creciente
#n=$1 r=$2 $3=metodo
function rFijo {
  echo -n "" > Informe/Metodo$3/data1.txt
  for (( i=$2; i<=$1; i++ ))
  do
    echo $(./a.out $i $2  $3) $i >> Informe/Metodo$3/data2.txt
  done
  gnuplot -persist <<-EOFMarker
   set title "Metodo $3 \n{/*0.8 n creciente, r fijo}" font ",14" textcolor rgbcolor "royalblue"
   set nokey
   set ylabel "Tiempo"
   set format y "%7.3f"
   set xlabel "n"
   set format y "%.7f"
   set term png
   set output "Informe/Metodo$3/plot2m$3.png"
      plot "Informe/Metodo$3/data2.txt"  using 3:2 with lines
EOFMarker

}

#n=$1 r=$2 $3=k  $4=metodo
#n fijo y r esta siendo constantemente multiplicado por k hasta n
function nFijokVaria {
  echo -n "" > Informe/Metodo$4/data3.txt
  for (( i=$2; i<=$1; i = i*$3 ))
    do
      echo $(./a.out $1 $i $4) $i >> Informe/Metodo$4/data3.txt
    done
  gnuplot -persist <<-EOFMarker
   set title "Metodo $4 \n{/*0.8 r*k creciendo hasta n}" font ",14" textcolor rgbcolor "royalblue"
   set nokey
   set ylabel "Tiempo"
   set format y "%7.3f"
   set xlabel "r*k"
   set format y "%.7f"
   set term png
   set output "Informe/Metodo$3/plot3m$4.png"
      plot "Informe/Metodo$4/data3.txt"  using 3:2 with lines
EOFMarker
}

# echo "Elija una opción"
# echo "1. Graficar para n fijo y r crece hasta n"
# echo "2. Graficar para r fijo y n va desde r hasta n"
# echo "3. Graficar para n fijo y r siendo constantemente multiplicado por k hasta n"
echo "Se están haciendo los gráficos, no me cierres"
for i in 1 2 3 4 ; do
  for opcion in  2 3 ; do
    if [[ "$opcion" == 1 ]]; then
      n=100
      r=1
    #  read m
      nFijo $n $r $i
    elif [[ "$opcion" == 2 ]]; then
      n=150
      r=15
      #read m
      rFijo $n $r $i
    elif [[ "$opcion" == 3 ]]; then
      n=1000
      r=1
      k=2
      nFijokVaria $n $r $k $i
    fi
  done
done
