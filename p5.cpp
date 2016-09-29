 using namespace std;

void factorial( mpf_t nn, mpf_t nn_result, mpf_t fac )
{
        int i=mpf_cmp_ui (nn, 1);

        while( i > 0 )
        {

                i=mpf_cmp_ui (nn, 1); // nn = i
//-----------------------------------------------//

                mpf_init_set(nn_result, nn); //nn_result = nn

//-----------------------------------------------//

                mpf_mul(fac,fac,nn_result); //fac = fac * nn_result

                mpf_sub_ui(nn,nn,1); // nn = nn - 1
        }
}

//-----------------------------------------------------------------------------------------------------------------------------//


void taylor ( mpf_t n, mpf_t p_el, mpf_t div_taylor, mpf_t denom, mpf_t nn, mpf_t nn_result, mpf_t fac )
{
        int i;  mpf_init_set_ui( denom, 1 );

        for ( i=1; i < 100; i++ )
        {
                mpf_pow_ui( p_el, n, i);       // p_el = n^i

                mpf_init_set_ui(nn,i);         // nn=i

                mpf_init_set_ui(fac,1);        // fac = 1

                factorial( nn,nn_result,fac );   // fac = n!

                mpf_div( div_taylor, p_el, fac ); // div_taylor = p_el / fac

                mpf_add( denom, denom, div_taylor ); // denom = denom + div_taylor
        }
}

//-----------------------------------------------------------------------------------------------------------------------------//



int p5(int argc, char const *argv[],bool flag)
{
        float n_pow, pot;
        short y;

        mpf_t n,r,nn,nr,p_el,pr_el,nr_el,fac_actual;
        mpf_t fac_n,fac_r,fac_nr,rnr;

        mpf_init_set_ui(nr,1);
        mpf_init_set_ui(rnr,1);

        mpf_init_set_str (r, argv[2], 10);
        mpf_init_set_str (n, argv[1], 10);
        mpf_init_set_str (p_el, argv[1], 10);
        mpf_init_set_str (pr_el, argv[2], 10);
        mpf_sub (nr, n, r);
        mpf_init_set(nr_el, nr);
	mpf_t potencia;
        

// Asigna punteros
        mpf_t nn_result;
        mpf_t numerador;
        mpf_t fac;
        mpf_t comb;
        mpf_t denom;
        mpf_t div_taylor;
        mpf_t div;
        mpf_t dospi;
        mpf_t raiz;

        mpf_init_set_ui(fac_n,1);
        mpf_init_set_ui(fac_r,1);
        mpf_init_set_ui(fac_nr,1);
 
        for ( y=0 ; y < 3 ; y++ )
        { 
// Inicia variables y les asigna un número
          mpf_init_set_ui(nn_result, 1);
          mpf_init_set_ui(numerador, 1);
          mpf_init_set_ui(fac,1);
          mpf_init_set_ui(comb,1);
          mpf_init_set_ui(denom,1);
          mpf_init_set_ui(div_taylor,1);
          mpf_init_set_ui(dospi,1);
          mpf_init_set_ui(raiz,1);
          mpf_init_set_ui(div,1);
          mpf_init_set_ui(fac_actual,1); 
          mpf_init_set_ui(potencia,1); 

//========================// Division //==========================--------------------------//
//----------/ Numerador /-----------------------------------------------------------------//

          n_pow = mpf_get_ui(p_el);                                 // Pasaje a int;
          mpf_add_ui( potencia, p_el, 1 );
          mpf_div_ui( potencia, potencia, 2 );
//-------------------------------------------------------------//
          pot = mpf_get_ui(potencia);               // Pasaje a float;
          
//---------------------------------------------------------------------------------------//                 
          mpf_pow_ui(numerador, p_el, pot );			// Calcular potencia;
//----------/Denominador /-----------------------------------------------------------------//

          taylor ( n, p_el, div_taylor, denom, nn, nn_result, fac );

          mpf_div( div, numerador, denom );                      

//========================// Raiz //==========================--------------------------//

          mpf_init_set_d( dospi, 6.28318530717958647692528676655 );

          mpf_sqrt ( raiz, dospi );

//========================// Resultado final //==========================--------------------------//


          mpf_mul(fac_actual,raiz,div); 	//fac_actual = raiz * div

     	  switch( y )
          {
            case ( 0 ):

            mpf_init_set(fac_n,fac_actual);  
            mpf_init_set(p_el,pr_el); 		// p_el = pr_el
            mpf_init_set(n,r); 			// n = r

            break;
//---------------------------------------------------------------------------------------------------//
            case ( 1 ):

            mpf_init_set(fac_r,fac_actual);
            mpf_init_set(p_el,nr_el); 		// p_el = nr_el
            mpf_init_set(n,nr); 		// n = nr

            break;
//---------------------------------------------------------------------------------------------------//
            case ( 2 ):

            mpf_init_set(fac_nr,fac_actual);  
            break;
//---------------------------------------------------------------------------------------------------//
          }

        }


        mpf_mul( rnr , fac_r , fac_nr ); // denominador

        mpf_div( comb , fac_n , rnr ); 
        if(flag==false){ gmp_printf (" %.*Ff", 1, comb); }


        mpf_clear(nn_result);
        mpf_clear(n);
        mpf_clear(nn);
        mpf_clear(nr);
        mpf_clear(p_el);
        mpf_clear(pr_el);
        mpf_clear(nr_el);
        mpf_clear(numerador);
        mpf_clear(fac);
        mpf_clear(comb);
        mpf_clear(denom);
        mpf_clear(div);
        mpf_clear(dospi);
        mpf_clear(raiz);
        mpf_clear(fac_actual);
        mpf_clear(fac_n);
        mpf_clear(fac_nr);
        mpf_clear(fac_r);
        mpf_clear(rnr);
        mpf_clear(potencia);

        return 0;
}
