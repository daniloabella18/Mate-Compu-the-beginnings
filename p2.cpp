#include <iostream>
#include <gmp.h>
#include <cstdlib>
using namespace std;


void factorial2(mpz_t n, mpz_t result){
        mpz_t i;
        for (mpz_init_set_ui(i, 1); mpz_cmp(i,n) <= 0; mpz_add_ui(i, i, 1)) {
                mpz_mul(result,result,i); //result = result * i
        }
}

//multiply all the numbres between from and to and the result in result
void multiply(mpz_t from, mpz_t to, mpz_t result){
        for (; mpz_cmp(from,to) <=0; mpz_add_ui(from, from, 1)) {
                mpz_mul(result,result,from); //result = result * i
        }
}

int p2(int argc, char const *argv[]) {
        /* Asigna punteros */
        mpz_t n;
        mpz_t r;
        mpz_t nr;
        mpz_t n_result;
        mpz_t r_result;
        mpz_t nr_result;
        mpz_t comb;
        /* Inicia variables y les asigna un número */
        mpz_init_set_str(n, argv[1],10);
        mpz_init_set_str(r, argv[2],10);
        mpz_init(nr);
        mpz_sub(nr,n, r);   //nr = n-r
        mpz_init_set_ui(n_result, 1);
        mpz_init_set_ui(r_result, 1);
        mpz_init_set_ui(nr_result, 1);
        mpz_init_set_ui(comb,0);

        //This applies symmetry
        if(mpz_cmp(r,nr) > 0) { //if r is greater than nr
                mpz_add_ui(r,r,1);
                multiply(r,n,n_result);
                factorial2(nr,nr_result);
                mpz_cdiv_q(comb,n_result, nr_result);
        }else{
                mpz_add_ui(nr,nr,1);
                multiply(nr,n,n_result);
                factorial2(r,r_result);
                mpz_cdiv_q(comb,n_result, r_result);
        }

        mpz_out_str(stdout,10,comb);


        mpz_clear(n_result);
        mpz_clear(r_result);
        mpz_clear(nr_result);
        mpz_clear(n);
        mpz_clear(r);
        mpz_clear(nr);
        mpz_clear(comb);
        return 0;
}
