#GMP y factoriales

##Compilando

Se compila usando el siguiente codigo en la terminal, se requiere la librería gmp para ello.

  `g++ main.cpp -lgmp`

Se ejecuta con

  `./a.out n r metodo`

Donde n y r son los valores de la función C(n,r) y metodo el método elegido para encontrar el resultado de la función.

##Ejecuntado script
El script para gráficar se debe ejecutar con

  `bash data.sh`

Esto va a generar 4 tipos de gráficos de distintos para cada estrategia y se demora cerca de 2 días en completarse.

Los gráficos son:

 - n fijo y r crece hasta n, donce n = 100
 - n fijo y r crece hasta n, donce n = 300
 - n fijo y r crece hasta n, donce n = 500
 - n fijo y r crece hasta n, donce n = 10000 (se recomienda omitir este)

Link del repositorio git: https://github.com/daniloabella18/Mate-Compu-the-beginnings

Creado por Sergio Salinas y Danilo Ábella.
