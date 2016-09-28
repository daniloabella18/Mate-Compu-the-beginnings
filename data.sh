#!/bin/bash
#g++ main.cpp -lgmp && ./a.out 4 3 1

#n fijo y r crece hasta n
#n=$1 r=$2 $3=metodo
function nFijo {
  for (( i=$2; i<=$1; i++ ))
  do
    ./a.out $1 $i  $3 >> data.txt
  done
}

#r fijo, n creciente
#n=$1 r=$2 $3=metodo
function rFijo {
  for (( i=$2; i<=$1; i++ ))
  do
    ./a.out $i $2  $3 >> data.txt
  done

}

#n=$1 r=$2 $3=k  $4=metodo
#n fijo y r esta siendo constantemente multiplicado por k hasta n
function nFijokVaria {
for (( i=$2; i<=$1; i=i*$3 ))
  do
    ./a.out $i $2  $4 >> data.txt
  done
}

#n=$1 r=$2 $3=k  $4=metodo
#n fijo y r siendo constantemente multiplicado por k hasta n
function nFijokVaria {
for (( i=$2; i<=$1; i=i*$3 ))
  do
    ./a.out $1 $i  $4>> data.txt
  done
}

#r fijo con r siendo multiplicado por k hasta n
#n=$1 r=$2 $3=k  $4=metodo
function rFijokVaria {
for (( i=$2; i<=$1; i=i*$3 ))
  do
    ./a.out $i $2  $4>> data.txt
  done
}

#n y r crecen recorriendo todas las combinaciones posibles
#n=$1  metodo=$2
function nVariarVaria {
for (( i=0; i<=$1; i++ ))
  do
    for (( j = 0 ; j <= i; j++ )); do
      ./a.out $i $j $2>> data.txt
    done
  done
}
echo "Elija una opción"
echo "1. Graficar para n fijo y r crece hasta n"
echo "2. Graficar para r fijo y n va desde r hasta n"
echo "3. Graficar para n fijo y r siendo constantemente multiplicado por k hasta n"
echo "4. Graficar para r fijo con r siendo multiplicado por k hasta n"
echo "5. Graficar para n y r crecen recorriendo todas las combinaciones posibles"
read opcion
if [[ "$opcion" == 1 ]]; then
  echo "Ingrese n, r y método combinatorio a utilizar"
  read n r m
  nfijo $n $r $m
elif [[ "$opcion" == 2 ]]; then
  echo "Ingrese n, r y método combinatorio a utilizar"
  read n r m
  rfijo $n $r $m
elif [[ "$opcion" == 3 ]]; then
  echo "Ingrese n y método combinatorio a utilizar"
  read n m
  nFijokVaria $n $r $k $m
elif [[ "$opcion" == 4 ]]; then
  echo "Ingrese n, r, k y método combinatorio a utilizar"
  read n r k m
  nFijokVaria $n $r $k $m
elif [[ "$opcion" == 5 ]]; then
  echo "Ingrese n y método combinatorio a utilizar"
  read n r m
  nVariarVaria $n $r $m
fi

gnuplot -persist <<-EOFMarker
 set title "Tu hermana " font ",14" textcolor rgbcolor "royalblue"
    plot "data.txt" using 1:2 with lines
EOFMarker
#Para borrar todo
echo -n "" > data.txt
