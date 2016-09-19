
#include <cstdlib>
#include <gmp.h>
#include <iostream>
#include "p1.cpp"
#include "p2.cpp"
#include "p3.cpp"
/* Estos no pueden ser agregados hasta que se arregle la salida"
   #include "p4.cpp"
   #include "p5.cpp"
 */
using namespace std;

int main(int argc, char const *argv[]) {
        if(argc < 4) {
                cout<<"Insufficient arguments";
        }else{
                clock_t tStart = clock();
                double dif;
                switch (atoi(argv[3])) {
                case 1:
                        p1(argc, argv);
                        break;
                case 2:
                        p2(argc, argv);
                        break;
                case 3:
                        // p3(argc,argv);
                        break;
                case 4:
                        // p4(argc,argv);
                        break;
                case 5:
                        // p5(argc,argv);
                        break;
                }
                printf("\t%.7f\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
        }
        return 0;
}
