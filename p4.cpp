#include <iostream>
#include <gmp.h>
#include <cstdlib>
#include <time.h>
using namespace std;


void factorial(int n, int r, mpf_t r_result, mpf_t n_result, mpf_t comb, mpf_t nr_result)
{
  int i=r,j=n;

  while( i>0 )
  { 
    mpf_init_set_ui(r_result, i); //r_result = i

    cout<<"\ni="; cout<< i;  cout<<" r_r:" ;

    mpf_out_str(stdout,10,100,r_result);
    
    mpf_init_set_ui(n_result, j); //n_result = j

    cout<<"\nj="; cout<< j;  cout<<" n_r:" ;

    mpf_out_str(stdout,10,100,n_result);

    j--; i--;
 
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
  clock_t start, end;
  start = clock();
  int n=6;
  int r=3;
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

  mpf_out_str(stdout,10,10,comb);

  mpf_clear(n_result);
  mpf_clear(r_result);
  mpf_clear(nr_result);
  mpf_clear(comb);
  end = clock();
  cout<<"\nTiempo: "; cout<<((double)(end-start))/CLOCKS_PER_SEC; cout<<"\n";
  return 0;
}