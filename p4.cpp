// Danilo Abellá - Sergio Salinas
// LCC - USACH
// Xubuntu

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

    i=mpf_cmp_ui (r, 1);		// Da un valor a "i" dependiendo si "r" es <1, =1 o >1.

//--------------------------------------------------------------------------//

    mpf_init_set(r_result, r); 			//r_result = r

    cout<<"\nr=";

    mpf_out_str(stdout,10,100,r); 		// Muestra r
  
    cout<<"\nr_r:" ;

    mpf_out_str(stdout,10,100,r_result);  	// Muestra r_result

//--------------------------------------------------------------------------//
    
    mpf_init_set(n_result, n); 			//n_result = n

    cout<<"\nn=";

    mpf_out_str(stdout,10,100,n); 		// Muestra n
  
    cout<<"\nn_r:" ;

    mpf_out_str(stdout,10,100,n_result);  	// Muestra n_result

//--------------------------------------------------------------------------//

    mpf_sub_ui(r,r,1); mpf_sub_ui(n,n,1);	// Resta valores a "r" y "n".
 
    mpf_div(nr_result,n_result,r_result ); 	// nr_result = n_result / r_result

    cout<<"\nnr_r: ";

    mpf_out_str(stdout,10,100,nr_result);	// Muestra nr_result

    mpf_mul(comb,comb,nr_result); //comb = comb * n/r_result
  
    cout<<"\ncomb: ";
    mpf_out_str(stdout,10,100,comb);		// Muestra comb

    cout<<"\nCiclo\n";
   }
}


int main(int argc, char *argv[]) 
{
//--------------/ Evalua que el usuario coloque al menos 2 numeros //--------//
  if (argc<3)
  {					
     printf("Please supply two numbers to add.\n");
     return 1;
  }
//--------------------------------------------------------------------------//
  clock_t start, end;
  start = clock();				// Toma tiempo inicial

  mpf_t n,r;
// Transforma valores ingresados como variables mpf_t.
  mpf_init_set_str (r, argv[2], 10);
  mpf_init_set_str (n, argv[1], 10);

  /* Asigna punteros */
  mpf_t n_result;
  mpf_t r_result;
  mpf_t nr_result;
  mpf_t comb;
  /* Inicia variables y les asigna un número */
  mpf_init_set_ui(n_result, 1);
  mpf_init_set_ui(r_result, 1);
  mpf_init_set_ui(nr_result, 1);
  mpf_init_set_ui(comb,1);

  factorial( n,r,r_result,n_result,comb,nr_result );    // Factorial de divisiones

//--------------/ Combinatoria /----------------//

  cout<<"\nCombinatoria:";

  mpf_out_str(stdout,10,10,comb);
// Elimina punteros
  mpf_clear(n_result);
  mpf_clear(r_result);
  mpf_clear(nr_result);
  mpf_clear(comb);

  end = clock();              			// Toma tiempo final

  cout<<"\nTiempo: "; cout<<((double)(end-start))/CLOCKS_PER_SEC; cout<<"\n\n";   // Calcula tiempo usado y lo muestra
 
  return 0;
}