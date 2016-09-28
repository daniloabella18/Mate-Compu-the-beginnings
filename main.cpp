
#include <cstdlib>
#include <gmp.h>
#include <iostream>
#include <time.h>
#include "p1.cpp"
#include "p2.cpp"
#include "p3.cpp"
#include "p4.cpp"
/* Estos no pueden ser agregados hasta que se arregle la salida"

   #include "p5.cpp"
 */
using namespace std;

int main(int argc, char const *argv[]) {
        double t =0;
        double sum=0;
        clock_t tStart;
        bool flag =false;
        if(argc < 4) {
                cout<<"Insufficient arguments";
        }else{
          do{
                tStart = clock();
                switch (atoi(argv[3])) {
                case 1:
                        p1(argc, argv,flag);
                        flag = true;
                        break;
                case 2:
                        p2(argc, argv);
                        flag = true;
                        break;
                case 3:
                        p3(argc,argv,flag);
                        flag = true;
                        break;
                case 4:
                        p4(argc,argv,flag);
                        flag = true;
                        break;
                case 5:
                        // p5(argc,argv);
                        break;
                }
                t=(t + (double)(clock() - tStart)/CLOCKS_PER_SEC )/2;
                sum+=t;
            }while(sum < 1);
            printf("\t%.7f\n", t);
        }


        return 0;
}
