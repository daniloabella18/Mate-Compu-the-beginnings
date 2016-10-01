// Danilo Abellá - Sergio Salinas
// LCC - USACH
// Xubuntu


int p5(int argc, char const *argv[],bool flag)
{
        float pot_n;
        short y;

        mpf_t r, n, nn, nr, p_el, pr_el, nr_el;
        mpf_t fac_n, fac_r, fac_nr, rnr, fac_actual;

        mpf_init_set_ui(nr,1);
        mpf_init_set_ui(rnr,1);

        mpf_init_set_str (r, argv[2], 10);
        mpf_init_set_str (n, argv[1], 10);
        mpf_sub (nr, n, r);   

// Asigna punteros
        mpf_t comb;
        mpf_t dospi;
        mpf_t div;
// Punteros de operacion
        mpf_t n_e;
        mpf_t n_raiz;

//----------------------/ exp /---------------------------------------------//

        mpf_t exp;	mpf_init_set_d( exp, 2.7182818284590452353602874713526624977 );

//----------------------/ 2_pi_raiz /---------------------------------------------//

            mpf_init_set_d ( dospi, 6.28318530717958647692528676655 );	mpf_sqrt ( dospi, dospi );

        mpf_init_set_ui(fac_n,1);
        mpf_init_set_ui(fac_r,1);
        mpf_init_set_ui(fac_nr,1);
        mpf_init_set_ui(rnr,1);
 
        for ( y=0 ; y < 3 ; y++ )
        {
// Inicia variables y les asigna un número
          mpf_init_set_ui(fac_actual,1); 
          mpf_init_set_ui(comb,1);
          mpf_init_set_ui(div,1);
          mpf_init_set_ui(n_e,1);
          mpf_init_set_ui(n_raiz,1);

//----------------------/ n_e /---------------------------------------------//

            mpf_div( n_e , n , exp );
            pot_n = mpf_get_ui(n); 	
            mpf_pow_ui( n_e , n_e , pot_n );

//----------------------/ n_raiz /---------------------------------------------//

	    mpf_sqrt ( n_raiz, n );

//----------------------/ fac_actual /---------------------------------------------//

	    mpf_mul ( fac_actual, n_e, n_raiz );	mpf_mul ( fac_actual, fac_actual, dospi );

//----------------------/ Les damos los valores a los "fac" usando el "fac_actual" /---------------------------------------------//

     	  switch( y )
          {
            case ( 0 ):

            mpf_init_set(fac_n,fac_actual);  
            mpf_init_set(n,r); 			// n = r

            break;
//---------------------------------------------------------------------------------------------------//
            case ( 1 ):

            mpf_init_set(fac_r,fac_actual);
            mpf_init_set(n,nr); 		// n = nr

            break;
//---------------------------------------------------------------------------------------------------//
            case ( 2 ):

            mpf_init_set(fac_nr,fac_actual);  
            break;
//---------------------------------------------------------------------------------------------------//
          }
        }

        mpf_mul( rnr , fac_r , fac_nr ); 		// denominador

        mpf_div( comb , fac_n , rnr );			// division

        if(flag==false){ gmp_printf (" %.*Ff", 1, comb ); }  		// Muestra resultado final

        //Clears
        // Fórmula de Combinacion
        mpf_clear( comb );
        mpf_clear( dospi );
        mpf_clear( div );

// Punteros de operacion
        mpf_clear( n_e );
        mpf_clear( n_raiz );
        mpf_clear( exp );

        mpf_clear( fac_n );
        mpf_clear( fac_r );
        mpf_clear( fac_nr );
        mpf_clear( rnr );

        return 0;
}
