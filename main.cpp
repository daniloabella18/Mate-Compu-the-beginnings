
#include <cstdlib>
#include <gmp.h>
#include <iostream>
#include <time.h>
#include "p1.cpp"
#include "p2.cpp"
#include "p3.cpp"
#include "p4.cpp"
#include "p5.cpp"
using namespace std;

int main(int argc, char const *argv[]) {
        double t =0;
        double cont=0;
        clock_t tStart;
        bool flag =false;
        if(argc < 4) {
                cout<<"Insufficient arguments"<<endl;
        }else if(atoi(argv[1])< atoi(argv[2])) {
                cout<<"Error, n no puede ser menor que r"<<endl;
        } else{
                do {
                        tStart = clock();
                        switch (atoi(argv[3])) {
                        case 1:
                                p1(argc, argv,flag);
                                flag = true;
                                break;
                        case 2:
                                p2(argc, argv,flag);
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
                                p5(argc,argv,flag);
                                flag = true;
                                break;
                        }
                        /* Calcula el promedio */
                        t += (double)(clock() - tStart)/CLOCKS_PER_SEC;
                        /*Ve si ya ha pasado un segundo  */
                        cont++;
                } while(t < 1);
                printf("\t%.7f\n", t/cont);
        }
        return 0;
}
