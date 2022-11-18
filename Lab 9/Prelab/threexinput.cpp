// Alisha Meena Gursahaney
// amg9zd
// prelab 9

#include <iostream>
#include <cstdlib>
#include "timer.h"

using namespace std;

extern "C" int threexplusone(int);

int  main () {

    // delcare the local variables
    int  x, iterations, ans;

    // enter int 1
    // cout << "Enter a number: ";
    cin >> x;
    // going into rdi

    // cout << "Enter iterations of subroutine: ";
    cin >> iterations;

    // timer* timer1 = new timer();

    // timer1->start();

    for (int i = 1; i <= iterations; i++) {
        ans = threexplusone(x);
    }
    
    // timer1->stop();

    // int ans = threexplusone(x);
    // cout << "Steps: " << ans << endl;
    cout << ans << endl;

    // all done!
    return 0;
}
