/*
Joshua Paul Barnard
CS 11 - SRJC
Fall 2017
Assignment 1 - 1
a1_1.cpp

This program will initialize variables, pointers, and arrays to demonstrate how pointers work.
We created our own swap function and a function which takes in a number, and returns the
number unchanged or returns the number as a zero.
The end output from this program is a list of outputs demonstrating our ability to use
and understand pointers.
*/

#include <iostream>

using namespace std;

void noNegatives(int *a);
void swap(int *s1, int *s2);

int main()
{
    // #1:  Create two integer variables named x and y
    int x, y;

    // #2:  Create an int pointer named p1
    int *p1;

    // #3:  Store the address of x in p1
    p1 = &x;

    // #4:  Use only p1 (not x) to set the value of x to 99
    *p1 = 99;

    // #5:  Using cout and x (not p1), display the value of x
    cout << endl << "Questions 5:" << endl;
    cout << "x is: " << x << endl << endl;

    // #6:  Using cout and the pointer p1 (not x), display the value of x
    cout << "Questions 6:" << endl;
    cout << "p1 is: " << *p1 << endl << endl;

    // #7:  Store the address of y into p1
    p1 = &y;

    // #8:  Use only p1 (not y) to set the value of y to 300
    *p1 = -300;

    // #9:  Create two new variables: an int named temp, and an int pointer named p2. Make p2 point to x.
    int temp = 0;
    int *p2;
    p2 = &x;

    // #10:  Use only temp, p1, and p2 (not x or y) to swap the values in x and
    //        y (this will take a few statements.  Don't use a swap function).
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;

    // #12:  Invoke the function twice: once with the address of x as the argument,
    //        and once with the address of y.  Use x or y for the argument (not p1 or p2).
    noNegatives(&x);
    noNegatives(&y);

    // #13:  Use p2 to display the values in x and y (this will require both assignment statements
    //        and cout statements). You can use x and y in assignment statements,
    //        but not in your cout statement.
    cout << "Question 13" << endl;
    p2 = &x;
    cout << "x is: " << *p2 << endl;
    p2 = &y;
    cout << "y is: " << *p2 << endl << endl;

    // #14:  Create an int array named 'a' with two elements. Make p2 point to the first element of a.
    int a[2];
    p2 = a;

    // #15:  Use only p2 and x (not a) to initialize the first element of a with the value of x.
    p2[0] = x;

    // #16:  Use only p2 and y (not a) to initialize the second element of a with the value of y.
    p2[1] = y;

    // #17:  Using cout and p2 only, display the address of the first element in a.
    cout << "Questions 17:" << endl;
    cout << "The adress of the First Element of array a is: " << p2[0] << endl << endl;

    // #18:  Using cout and p2 only, display the address of the second element in a.
    cout << "Questions 18:" << endl;
    cout << "The adress of the Second Element of array a is: " << p2[1] << endl << endl;

    // #19:  Use p1, p2, and temp to swap the values in the two elements of array 'a'.
    p1 = &a[0];
    p2 = &a[1];
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;

    // #20:  Display the values of the two elements.
    cout << "Question 20:" << endl;
    cout << "a[0] is: " << a[0] << endl;
    cout << "a[1] is: " << a[1] << endl << endl;

    // #22:  Invoke your swap function with the addresses of x and y (using the
    //        address of operator), then print their values.
    swap(&x, &y);
    cout << "Question 22:" << endl;
    cout << "x is: " << x << endl;
    cout << "y is: " << y << endl << endl;

    // #23:  Invoke your swap function with the address of the two elements in array 'a', then print their values.
    swap(&a[0], &a[1]);
    //swapArray(a, 0, 1);
    cout << "Question 23:" << endl;
    cout << "a[0] is: " << a[0] << endl;
    cout << "a[1] is: " << a[1] << endl << endl;

return 0;
}


// #11:  Write a function with the following signature: void noNegatives(int *x).
//        The function should accept the address of an int variable. If the value
//        of this integer is negative then it should set it to zero.
void noNegatives(int *x)
{

    if(*x < 0)
    {
        *x = 0;
    }
}


// #21:  Write a function named 'swap' that accepts two pointers to integers as arguments, and then
//        swaps the contents of the two integers. Do not use any reference parameters.
void swap(int *s1, int *s2)
{
    int Temp = 0;

    Temp = *s1;
    *s1 = *s2;
    *s2 = Temp;
}






/*
Questions 5:
x is: 99

Questions 6:
p1 is: 99

Question 13
x is: 0
y is: 99

Questions 17:
The adress of the First Element of array a is: 0

Questions 18:
The adress of the Second Element of array a is: 99

Question 20:
a[0] is: 99
a[1] is: 0

Question 22:
x is: 99
y is: 0

Question 23:
a[0] is: 0
a[1] is: 99
*/
