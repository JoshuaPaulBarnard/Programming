#include <iostream>
//#include "feetinches.h"

using namespace std;

int main() {
    int x, y;
    int *p1;

    p1 = &x;
    *p1 = 99;

    cout << "x is: " << x << endl;
    cout << "p1 is: " << *p1 << endl;

    p1 = &y;
    *p1 = -300;

    int temp;
    int *p2;

    p2 = &x;

    // Switching the values of x and y
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;

    /* Check
    cout << "x is: " << x << endl;
    cout << "y is: " << y << endl;
    */


}
