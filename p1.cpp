#include <iostream>
#include <gmp.h>
#include <cstdlib>
using namespace std;


void factorial(int a, mpz_t result){
  int i;
  for(i = 1 ; i<=a; i++){
    mpz_mul_ui(result,result,i); //result = result * i
  }
}


int main(int argc, char const *argv[]) {
  int n=4;
  int r=2;
  int nr = n - r;
  /* Asigna punteros */
  mpz_t n_result;
  mpz_t r_result;
  mpz_t nr_result;
  mpz_t comb;
  /* Inicia variables y les asigna un número */
  mpz_init_set_ui(n_result, 1); //inicia puntero y le inicia valor
  mpz_init_set_ui(r_result, 1);
  mpz_init_set_ui(nr_result, 1);
  mpz_init_set_ui(comb,0);

  factorial(n,n_result);
  factorial(r,r_result);
  factorial(nr, nr_result);

  mpz_mul(comb,r_result,nr_result); // Multiplica dos mpz, si tiene _ui multiplica un mpz y una constante
  mpz_cdiv_q(comb,n_result, comb );

  mpz_out_str(stdout,10,comb);

  mpz_clear(n_result);
  mpz_clear(r_result);
  mpz_clear(nr_result);
  return 0;
}
