
#ifndef Header_h
#define Header_h
#include <iostream>
#include "feetInches.h"
using namespace std;
//using namespace cs_feetInches;


int main()
{

  cs_feetInches::feetInches f1, f2(3), f3(4, 7);
  int x;

  f1 = f2 + f3;
  cout << f2 << " plus " << f3 << " equals " << f1 << endl;

  cout << ++f1;
  cout << endl:
  cout << f1++;
  cout << endl;
  cout << "f1 is now" << f1 << endl;

  x = 42;
  f1 = x + f3;
  //f1 = f2.operator+(f3);
  cout << "f1 is now " << f1 << endl;

/*
  f2.print();
  cout << " plus ";
  f3.print();
  cout << " equals ";
  f1.print();
  cout << endl;


  (f1++).print();
  cout << endl;
  (++f1).print();
  cout << endl;
  f1.print();

  cout << f1++ << endl;
  cout << ++f1 << endl;
  cout << f1 << endl;

  int x;
  x = 42;
  f1 = x + f3;

  if (f2 < f1)
    {
      cout << "f1 is now " << f1 << endl;
    }
  else
    {

    }

    */

  }
