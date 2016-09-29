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
for (( i=$2; i<=$1; $i=i*$3 ))
  do
    echo $(./a.out $i $2  $4) $i >> Informe/Metodo$3/data3.txt
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
      plot "Informe/Metodo$3/data3.txt"  using 3:2 with lines
EOFMarker
}

# #n=$1 r=$2 $3=k  $4=metodo
# #n fijo y r siendo constantemente multiplicado por k hasta n
# function rFijokVaria {
# for (( i=$2; i<=$1; i=i*$3 ))
#   do
#     ./a.out $1 $i $4>> data.txt
#   done
# }
#
# #r fijo con r siendo multiplicado por k hasta n
# #n=$1 r=$2 $3=k  $4=metodo
# function rFijokVaria {
# for (( i=$2; i<=$1; i=i*$3 ))
#   do
#     ./a.out $i $2  $4>> data.txt
#   done
# }
#
# #n y r crecen recorriendo todas las combinaciones posibles
# #n=$1  metodo=$2
# function nVariarVaria {
# for (( i=0; i<=$1; i++ ))
#   do
#     for (( j = 0 ; j <= i; j++ )); do
#       ./a.out $i $j $2>> data.txt
#     done
#   done
# }

echo "Elija una opción"
echo "1. Graficar para n fijo y r crece hasta n"
echo "2. Graficar para r fijo y n va desde r hasta n"
echo "3. Graficar para n fijo y r siendo constantemente multiplicado por k hasta n"
#echo "4. Graficar para r fijo con r siendo multiplicado por k hasta n"
#echo "5. Graficar para n y r crecen recorriendo todas las combinaciones posibles"
read opcion
#borra todo en data.txt
if [[ "$opcion" == 1 ]]; then
  echo "Ingrese método combinatorio a utilizar"
  n=1000
  r=1
  read m
  nFijo $n $r $m
elif [[ "$opcion" == 2 ]]; then
  echo "método combinatorio a utilizar"
  n=1000
  r=150
  read m
  rFijo $n $r $m
elif [[ "$opcion" == 3 ]]; then
  echo "Ingrese k y método combinatorio a utilizar"
  n=10000
  r=1
  read n r k m
  nFijokVaria $n $r $k $m
# elif [[ "$opcion" == 4 ]]; then
#   echo "Ingrese n, r, k y método combinatorio a utilizar"
#   read n r k m
#   nFijokVaria $n $r $k $m
# elif [[ "$opcion" == 5 ]]; then
#   echo "Ingrese n y método combinatorio a utilizar"
#   read n r m
#   nVariarVaria $n $r $m
fi
