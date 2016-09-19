#include <iostream>
#include <gmp.h>
#include <cstdlib>
#include "p1.cpp"
#include "p2.cpp"
using namespace std;

int main(int argc, char const *argv[]) {

        switch (atoi(argv[3])) {
        case 1:
                p1(argc,argv);
                break;
        case 2:
                p2(argc,argv);
                break;
        case 3:
                p3(argc,argv);
                break;
        case 4:
                p4(argc,argv);
                break;
        case 5:
                p5(argc,argv);
                break;
        }

        return 0;
}
