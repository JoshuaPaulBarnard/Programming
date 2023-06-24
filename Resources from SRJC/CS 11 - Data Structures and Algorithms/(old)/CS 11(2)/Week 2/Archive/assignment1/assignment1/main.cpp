//
//  main.cpp
//  Created by Ryan  Martino on 8/22/17.
//  t-th 10:30
//  Dave Harden
//  assignment1

// This program follows a sequence of instructions that were supplied that are all loosely tied into each other to practice using pointers. The tasks involve storing addresses in the pointers, using pointers to manipululate the values stored in the space the pointer points too. Along with swapping values of two variables using pointers and a temp variable. A nonNegative func is made that accepts the address of a variable and test if the variable stored in it is negative. If so it sets it 0. Array and pointer manipluation is practiced next. A swap variable that accepts the address of two variables and swaps the values stored in them is made.

#include <iostream>
using namespace std;

void noNegatives(int *x);
void swap(int *ptr1, int *ptr2);

int main() {
    
    int x;
    
    int y;
    
    int* p1;
    
    p1 = &x;
    
    *p1 = 99;
    
    cout << x << endl;
    
    cout << *p1 << endl;
    
    p1 = &y;
    
    *p1 = -300;
    
    int temp;
    
    int* p2;
    
    p2 = &x;

    temp = *p1;
    
    *p1 = *p2;
    
    *p2 = temp;

    noNegatives(&x);
    
    noNegatives(&y);
    
    cout << "x is: " << *p2 << endl;
    
    p2 = &y;
    
    cout << "y is: " << *p2 << endl;
    
    int a[2];
    
    p2 = a;
    
    *p2 = x;

    p2 = (p2 + 1);
    
    *p2 = y;
    
    p2 = (p2 - 1);
    
    cout << p2 << endl;
    
    cout << p2 + 1 << endl;
    
    p1 = &a[0];
    
    p2 = &a[1];
    
    temp = *p1;
    
    *p1 = *p2;
    
    *p2 = temp;
    
    cout << a[0] << " " << a[1] << endl;
    
    swap(&x,&y);
    
    cout << x << " " << y << endl;
    
    swap(a[0], a[1]);
    
    cout << a[0] << " " << a[1] << endl;
    
    return 0;
    
}
//    this function takes in two pointers and switches the values that they point too.
void swap(int *ptr1, int *ptr2) {
    
    int tempVar;
    
    tempVar = *ptr1;
    
    *ptr1 = *ptr2;
    
    *ptr2 = tempVar;
    
    
}

//    this function test for a negative value thats stored in the address passed to it and set it to 0 if so.
void noNegatives(int *x) {
    
    if (*x < 0) {
        *x = 0;
    }
}

//99
//99
//x is: 0
//y is: 99
//0x7fff5fbff680
//0x7fff5fbff684
//99 0
//99 0
//0 99
//Program ended with exit code: 0
