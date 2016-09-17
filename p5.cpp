#include <iostream>
#include <gmp.h>
#include <cstdlib>
#include <time.h>
#include <math.h>
using namespace std;


void factorial( mpf_t r, mpf_t r_result, mpf_t fac )
{
  int i=mpf_cmp_ui (r, 1);

  while( i > 0 )
  { 

    i=mpf_cmp_ui (r, 1);
//-----------------------------------------------//

    mpf_init_set(r_result, r); //r_result = r

    cout<<"\nr=";

    mpf_out_str(stdout,10,100,r); 
  
    cout<<"\nr_r:" ;

    mpf_out_str(stdout,10,100,r_result);

//-----------------------------------------------//

    mpf_mul(fac,fac,r_result); //fac = fac * r_result
  
    cout<<"\nFactorial: ";

    mpf_out_str(stdout,10,100,fac);

    cout<<"\nCiclo\n";

    mpf_sub_ui(r,r,1);
  }
}


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
  mpf_t n_result;
  mpf_t r_result;
  mpf_t numerador;
  mpf_t fac;
  mpf_t comb;
  mpf_t div;
// Inicia variables y les asigna un número
  mpf_init_set_ui(n_result, 1); //inicia puntero y le inicia valor
  mpf_init_set_ui(r_result, 1);
  mpf_init_set_ui(numerador, 1);
  mpf_init_set_ui(fac,1);
  mpf_init_set_ui(comb,1);
  mpf_init_set_ui(div,1);


//--------------------------------------------------------//

  n_pow = mpf_get_ui(n_el);

  cout<<"\nn_pow: ((n+1)/2)=";  cout<<n_pow;  cout<<"\n";
//-------------------------------------------------------------//
  potencia = (n_pow+1)/2;

  cout<<"\npotencia: n^((n+1)/2)=";  cout<<potencia;  cout<<"\n";
//-------------------------------------------------------------//
  numerador_n = pow( n_pow , potencia );

  cout<<"\nnumerador_n: n^((n+1)/2)=";  cout<<numerador_n;  cout<<"\n";
//-------------------------------------------------------------//
/*mpf_pow_ui( numerador , n , potencia);

  cout<<"\nnumerador: n^((n+1)/2)=";  mpf_out_str(stdout,10,10,numerador);  cout<<"\n";*/




//--------------------------------------------------------//

  factorial( r,r_result,fac );

  cout<<"\nCombinatoria:";

  mpf_out_str(stdout,10,10,comb);

  mpf_clear(n_result);
  mpf_clear(r_result);
  mpf_clear(n);
  mpf_clear(r);
  mpf_clear(n_el);
  mpf_clear(numerador);
  mpf_clear(fac);
  mpf_clear(comb);
  mpf_clear(div);

  end = clock();

  cout<<"\nTiempo: "; cout<<((double)(end-start))/CLOCKS_PER_SEC; cout<<"\n\n";
  return 0;
}