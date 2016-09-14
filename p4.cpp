#include <iostream>
#include <gmp.h>
#include <cstdlib>
using namespace std;


void factorial(int n, int r, mpz_t r_result, mpz_t n_result, mpz_t comb, mpz_t nr_result)
{
  int i=r,j=n;

  while( i>0 )
  { 
    mpz_init_set_ui(r_result, i); //r_result = i

   cout<<"\nr_r: ";

    mpz_out_str(stdout,10,r_result);
    
    mpz_init_set_ui(n_result, j); //n_result = j
    cout<<"\nn_r: ";
    mpz_out_str(stdout,10,n_result);

    j--; i--;
 
    mpz_tdiv_q(nr_result,n_result,r_result ); // n/r_result = n_result / r_result
    cout<<"\nnr_r: ";
    mpz_out_str(stdout,10,nr_result);

    mpz_mul(comb,comb,nr_result); //comb = comb * n/r_result
  
    cout<<"\ncomb: ";
    mpz_out_str(stdout,10,comb);

    cout<<"\nVuelta 1\n";
   }
}



int main(int argc, char const *argv[]) {
  int n=5;
  int r=2;
  /* Asigna punteros */
  mpz_t n_result;
  mpz_t r_result;
  mpz_t nr_result;
  mpz_t comb;
  /* Inicia variables y les asigna un número */
  mpz_init_set_ui(n_result, 1); //inicia puntero y le inicia valor
  mpz_init_set_ui(r_result, 1);
  mpz_init_set_ui(nr_result, 1);
  mpz_init_set_ui(comb,1);

  factorial( n,r,r_result,n_result,comb,nr_result );

  mpz_out_str(stdout,10,comb);

  mpz_clear(n_result);
  mpz_clear(r_result);
  mpz_clear(nr_result);
  mpz_clear(comb);
  return 0;
}