// mathfun.cpp
// prelab 8
// Alisha Meena Gursahaney
// amg9zd


#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

extern "C" int product (int, int);
extern "C" int power (int, int);

int  main () {

    // delcare the local variables
    int  x, y;

    // enter int 1
    cout << "Enter integer 1: ";
    cin >> x;

    cout << "Enter integer 2: ";
    cin >> y;

    int prod = product( x, y );
    cout << "Product: " << prod << endl;

    int pow = power( x, y );
    cout << "Power: " << pow << endl;

    // all done!
    return 0;
}
