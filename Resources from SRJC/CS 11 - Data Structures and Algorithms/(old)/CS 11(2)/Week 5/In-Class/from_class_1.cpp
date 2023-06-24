#include <iostream>
#include "inventoryitem.h"
using namespace std;

void f(InventoryItem)

int main ()
{
  InventoryItem item1;
  InventoryItem item2("hammer");

  cout << "item1 is " << item1 << endl;
  cout << "item2 is " << item2 << endl;

  item1.setInfo("screwdriver", 5);
  item2.setUnits(9);

  cout << "item1 is " << item1 << endl;
  cout << "item2 is " << item2 << endl << endl;

  item1 = item2;
  cout << "after item1 = item2, " << endl;
  cout << "item1 is " << item1 << endl;
  cout << "item2 is " << item2 << endl << endl;

  item2.setInfo("lawn mower", 14);
  cout << "after item2.setInfo(\"lawn mower\", 14), " << endl;
  cout << "item1 is " << item1 << endl;
  cout << "item2 is " << item2 << endl << endl;

  item1 = item1;
  cout << "After item1 = item1, ";
  cout << "item1 is " << item1 << endl;

  f(item1);
  cout << "After being used as an argument to a pass-by-value parameter, ";
  cout << endl << "item1 is still " << item1 << endl << endl;

  cout << item1[1] << item1[2] << item1[3] << endl;

  item1[1] = 'c';
  item1[2] = 'i';
  item1[3] = 's';

  cout << item1[1] << item1[2] << item1[3] << endl;

  const InventoryItem item4("chair");
  cout << item4[1];
  item4[1] = 'z';
  cout << item4[1];

  //f(intem1);
  //cout << "After being used as an argument to a pass-by-value parameter, "
  //cout << endl << "item1 is still " << item1 << endl << endl;

  //InventoryItem item3(item1);   //same as InventoryItem item3 = item1;
  //int x(7);
}

void f(InventoryItem item1) {
  item1.setInfo("pizza", 67);
}

/*
Desired Output :

item1 is 0
item2 is 0 hammer
item1 is 5 screwdriver
item2 is 9 hammer
*/
