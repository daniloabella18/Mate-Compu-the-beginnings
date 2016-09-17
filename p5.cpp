#include <iostream>
#include <gmp.h>
#include <cstdlib>
#include <time.h>
#include <math.h>
using namespace std;

//-----------------------------------------------------------------------------------------------------------------------------//


void factorial( mpf_t r, mpf_t r_result, mpf_t fac )
{
  int i=mpf_cmp_ui (r, 1);

  while( i > 0 )
  { 

    i=mpf_cmp_ui (r, 1);       // r = i
//-----------------------------------------------//

    mpf_init_set(r_result, r); //r_result = r

//-----------------------------------------------//

    mpf_mul(fac,fac,r_result); //fac = fac * r_result

    mpf_sub_ui(r,r,1);         // r = r - 1
  }
}

//-----------------------------------------------------------------------------------------------------------------------------//


void taylor ( mpf_t n , mpf_t n_el , mpf_t div_taylor , mpf_t denom , mpf_t r , mpf_t r_result , mpf_t fac )
{ 
  int i;  mpf_init_set_ui( denom , 1 );

  for ( i=1 ; i < 100 ; i++ )
  { 
    mpf_pow_ui( n_el , n , i);                 // n_el = n^i

    mpf_init_set_ui(r,i);                      // r=i

    mpf_init_set_ui(fac,1);                    // fac = 1

    factorial( r,r_result,fac );               // fac = n!

    mpf_div( div_taylor , n_el , fac );        // div_taylor = n_el / fac 

    mpf_add( denom , denom , div_taylor ); // denom = denom + div_taylor
  }
  
   cout<<"\ndenominador: e^n=";  mpf_out_str(stdout,10,100,denom);  cout<<"\n";
}


//-----------------------------------------------------------------------------------------------------------------------------//



int main(int argc, char *argv[]) 
{
  if (argc<3)
  {					
     printf("Please supply two numbers to add.\n");
     return 1;
  }

  clock_t start, end;
  start = clock();

  float n_pow, potencia, numerador_n;

  mpf_t n,r,n_el;

  mpf_init_set_str (r, argv[2], 10);
  mpf_init_set_str (n, argv[1], 10);
  mpf_init_set_str (n_el, argv[1], 10);

// Asigna punteros 
  mpf_t r_result;
  mpf_t numerador;
  mpf_t fac;
  mpf_t comb;
  mpf_t denom;
  mpf_t div_taylor;
  mpf_t div;
  mpf_t dospi;
  mpf_t raiz;
// Inicia variables y les asigna un número
  mpf_init_set_ui(r_result, 1);
  mpf_init_set_ui(numerador, 1);
  mpf_init_set_ui(fac,1);
  mpf_init_set_ui(comb,1);
  mpf_init_set_ui(denom,1);
  mpf_init_set_ui(div_taylor,1);
  mpf_init_set_ui(dospi,1);
  mpf_init_set_ui(raiz,1);
  mpf_init_set_ui(div,1);

//========================// Division //==========================--------------------------//
//----------/ Numerador /-----------------------------------------------------------------//

  n_pow = mpf_get_ui(n_el);                                   		// Pasaje a int;

  cout<<"\nn_pow: ((n+1)/2)=";  cout<<n_pow;  cout<<"\n";
//-------------------------------------------------------------//
  potencia = (n_pow+1)/2;				     		// Pasaje a float;

  cout<<"\npotencia: n^((n+1)/2)=";  cout<<potencia;  cout<<"\n";
//---------------------------------------------------------------------------------------//
  numerador_n = pow( n_pow , potencia );                     		// Calcular potencia;

  cout<<"\nnumerador_n: n^((n+1)/2)=";  cout<<numerador_n;  cout<<"\n";


//----------/Denominador /-----------------------------------------------------------------//

  taylor ( n , n_el , div_taylor , denom , r , r_result , fac );

  mpf_ui_div( div , numerador_n , denom );                        		// div = numerador_n / denom 

  cout<<"\ndiv: ( n^((n+1)/2) / e^n ) ="; mpf_out_str(stdout,10,100,div);  cout<<"\n";

//========================// Raiz //==========================--------------------------//

  mpf_init_set_d( dospi , 6.28318530717958647692528676655 );

  cout<<"\ndospi: "; mpf_out_str(stdout,10,100,dospi);  cout<<"\n";

  mpf_sqrt ( raiz , dospi );

  cout<<"\nraiz de dospi: "; mpf_out_str(stdout,10,100,raiz);  cout<<"\n";


//========================// Resultado final //==========================--------------------------//


  mpf_mul(comb,raiz,div); //fac = fac * r_result

  cout<<"\nk!(apróx):";

  mpf_out_str(stdout,10,10,comb); // Muestra resultado final

  mpf_clear(r_result);
  mpf_clear(n);
  mpf_clear(r);
  mpf_clear(n_el);
  mpf_clear(numerador);
  mpf_clear(fac);
  mpf_clear(comb);
  mpf_clear(denom);
  mpf_clear(div);
  mpf_clear(dospi);
  mpf_clear(raiz);


  end = clock();

  cout<<"\nTiempo: "; cout<<((double)(end-start))/CLOCKS_PER_SEC; cout<<"\n\n";
  return 0;
}