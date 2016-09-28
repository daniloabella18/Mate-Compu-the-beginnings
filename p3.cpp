/* Calcula el factorial de un número n y lo guarda en result */
void factorial(mpf_t n, mpf_t result) {
        mpf_t i;
        for (mpf_init_set_ui(i, 1); mpf_cmp(i, n) <= 0; mpf_add_ui(i, i, 1)) {
                mpf_mul(result, result, i); // result = result * i
        }
}

int p3(int argc, char const *argv[],bool flag) {
        /* Asigna punteros */
        mpf_t n;
        mpf_t r;
        mpf_t nr;
        mpf_t n_result;
        mpf_t r_result;
        mpf_t nr_result;
        mpf_t comb;
        /* Inicia variables y les asigna un número */
        mpf_set_default_prec( 32 );
        mpf_init(n);
        mpf_init(r);
        mpf_init(n_result);
        mpf_init(r_result);
        mpf_init(nr_result);
        mpf_init(comb);
        mpf_set_str(n, argv[1], 10);
        mpf_set_str(r, argv[2], 10);
        mpf_init(nr);
        mpf_sub(nr, n, r);      // nr = n-r
        mpf_set_ui(n_result, 1); // inicia puntero y le inicia valor
        mpf_set_ui(r_result, 1);
        mpf_set_ui(nr_result, 1);
        mpf_set_ui(comb, 0);

        /*Calcula los factoriales de n,r y n-r*/
        factorial(n, n_result);
        factorial(r, r_result);
        factorial(nr, nr_result);

        mpf_mul(comb, r_result, nr_result); // Multiplica dos mpf, si tiene _ui
        mpf_div(comb, n_result, comb);// multiplica un mpf y una constante

        //se muestra la salida una sola vez, esto es para poder ejecutar el programa varias veces y sacar el promedio del tiempo sin tener que ver el mismo resultado varias veces.
        if(flag==false)
          gmp_printf ("%.*Ff", 0, comb, 0);


        /* Libera los punteros */
        mpf_clear(n_result);
        mpf_clear(r_result);
        mpf_clear(nr_result);
        return 0;
}
