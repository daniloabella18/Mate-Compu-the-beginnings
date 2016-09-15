#include <iostream>
#include <gmp.h>
#include <cstdlib>
#include <time.h>
using namespace std;


void factorial(mpf_t n, mpf_t r, mpf_t r_result, mpf_t n_result, mpf_t comb, mpf_t nr_result)
{
 int i=mpf_cmp_ui (r, 1);


  while( i > 0 )
  { 

//-----------------------------------------------// Comparaciones

    i=mpf_cmp_ui (r, 1);

//-----------------------------------------------//

    mpf_init_set(r_result, r); //r_result = i

    cout<<"\nr=";

    mpf_out_str(stdout,10,100,r); 
  
    cout<<"\nr_r:" ;

    mpf_out_str(stdout,10,100,r_result);

//-----------------------------------------------//
    
    mpf_init_set(n_result, n); //n_result = j

    cout<<"\nn=";

    mpf_out_str(stdout,10,100,n); 
  
    cout<<"\nn_r:" ;

    mpf_out_str(stdout,10,100,n_result);

//-----------------------------------------------//

    mpf_sub_ui(r,r,1); mpf_sub_ui(n,n,1);
 
    mpf_div(nr_result,n_result,r_result ); // n/r_result = n_result / r_result

    cout<<"\nnr_r: ";

    mpf_out_str(stdout,10,100,nr_result);

    mpf_mul(comb,comb,nr_result); //comb = comb * n/r_result
  
    cout<<"\ncomb: ";
    mpf_out_str(stdout,10,100,comb);

    cout<<"\nCiclo\n";
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

  mpf_t n,r;

  mpf_init_set_str (r, argv[2], 10);
  mpf_init_set_str (n, argv[1], 10);

  /* Asigna punteros */
  mpf_t n_result;
  mpf_t r_result;
  mpf_t nr_result;
  mpf_t comb;
  /* Inicia variables y les asigna un número */
  mpf_init_set_ui(n_result, 1); //inicia puntero y le inicia valor
  mpf_init_set_ui(r_result, 1);
  mpf_init_set_ui(nr_result, 1);
  mpf_init_set_ui(comb,1);

  factorial( n,r,r_result,n_result,comb,nr_result );

  cout<<"\nCombinatoria:";

  mpf_out_str(stdout,10,10,comb);

  mpf_clear(n_result);
  mpf_clear(r_result);
  mpf_clear(nr_result);
  mpf_clear(comb);
  end = clock();
  cout<<"\nTiempo: "; cout<<((double)(end-start))/CLOCKS_PER_SEC; cout<<"\n\n";
  return 0;
}