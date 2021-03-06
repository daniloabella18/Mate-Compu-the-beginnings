/* Calcula el factorial de un número n y lo guarda en result */
void factorial(mpz_t n, mpz_t result) {
        mpz_t i;
        for (mpz_init_set_ui(i, 1); mpz_cmp(i, n) <= 0; mpz_add_ui(i, i, 1)) {
                mpz_mul(result, result, i); // result = result * i
        }
}

int p1(int argc, char const *argv[],bool flag) {
        /* Asigna punteros */
        mpz_t n;
        mpz_t r;
        mpz_t nr;
        mpz_t n_result;
        mpz_t r_result;
        mpz_t nr_result;
        mpz_t comb;
        /* Inicia variables y les asigna un número */
        mpz_init_set_str(n, argv[1], 10);
        mpz_init_set_str(r, argv[2], 10);
        mpz_init(nr);
        mpz_sub(nr, n, r);      // nr = n-r
        mpz_init_set_ui(n_result, 1); // inicia puntero y le inicia valor
        mpz_init_set_ui(r_result, 1);
        mpz_init_set_ui(nr_result, 1);
        mpz_init_set_ui(comb, 0);

        /*Calcula los factoriales de n,r y n-r*/
        factorial(n, n_result);
        factorial(r, r_result);
        factorial(nr, nr_result);

        mpz_mul(comb, r_result, nr_result); // Multiplica dos mpz, si tiene _ui
        mpz_cdiv_q(comb, n_result, comb);// multiplica un mpz y una constante

        //se muestra la salida una sola vez, esto es para poder ejecutar el programa varias veces y sacar el promedio del tiempo sin tener que ver el mismo resultado varias veces.
        if(flag==false)
          mpz_out_str(stdout, 10, comb);

        /* Libera los punteros */
        mpz_clear(n_result);
        mpz_clear(r_result);
        mpz_clear(nr_result);
        return 0;
}
