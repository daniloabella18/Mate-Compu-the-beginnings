// Danilo Abellá - Sergio Salinas
// LCC - USACH
// Xubuntu


void factorial(mpf_t n, mpf_t r, mpf_t r_result, mpf_t n_result, mpf_t comb, mpf_t nr_result)
{
        int i=mpf_cmp_ui (r, 1);


        while( i > 0 )
        {

                i=mpf_cmp_ui (r, 1); // Da un valor a "i" dependiendo si "r" es <1, =1 o >1.

//--------------------------------------------------------------------------//

                mpf_init_set(r_result, r); //r_result = r

//--------------------------------------------------------------------------//

                mpf_init_set(n_result, n); //n_result = n

//--------------------------------------------------------------------------//

                mpf_sub_ui(r,r,1); mpf_sub_ui(n,n,1); // Resta valores a "r" y "n".

                mpf_div(nr_result,n_result,r_result ); // nr_result = n_result / r_result

                mpf_mul(comb,comb,nr_result); //comb = comb * n/r_result
        }
}


int p4(int argc, char const *argv[],bool flag)
{

        mpf_t n,r;
// Transforma valores ingresados como variables mpf_t.
        mpf_init_set_str (r, argv[2], 10);
        mpf_init_set_str (n, argv[1], 10);

        /* Asigna punteros */
        mpf_t n_result;
        mpf_t r_result;
        mpf_t nr_result;
        mpf_t comb;

        mpf_set_default_prec( 1024 );
        
        /* Inicia variables y les asigna un número */
        mpf_init_set_ui(n_result, 1);
        mpf_init_set_ui(r_result, 1);
        mpf_init_set_ui(nr_result, 1);
        mpf_init_set_ui(comb,1);

        factorial( n,r,r_result,n_result,comb,nr_result ); // Factorial de divisiones

//--------------/ Combinatoria /----------------//

  //    cout<<"\nCombinatoria:";

        if(flag==false)
          gmp_printf (" %.*Ff", 1, comb);


    //  cout<<"\n"<<endl;

// Elimina punteros
        mpf_clear(n_result);
        mpf_clear(r_result);
        mpf_clear(nr_result);
        mpf_clear(comb);

        return 0;
}
