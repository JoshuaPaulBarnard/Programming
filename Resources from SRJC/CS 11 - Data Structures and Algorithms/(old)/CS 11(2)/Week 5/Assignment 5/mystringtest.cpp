   #include <iostream>
   #include "mystring.h"
   using namespace std;

   void f(MyString item1);

   int main()
   {
       MyString item1;
       MyString item2("hammer");

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
       cout << "after item1 = item1, ";
       cout << "item1 is " << item1 << endl << endl;


       f(item1);
       cout << "after being used as an argument to pass-by-value parameter, ";
       cout << endl << "item1 is still " << item1 << endl << endl;


       MyString item3 = item1;

       cout << "after MyString item3 = item1;" << endl;
       cout << "item1 is " << item1 << endl;
       cout << "item3 is " << item3 << endl << endl;

       item3.setInfo("ice cream", 962);
       cout << "after item3.setInfo(\"ice cream\", 962);" << endl;
       cout << "item1 is " << item1 << endl;
       cout << "item3 is " << item3 << endl << endl;



       cout << item1[1] << item1[2] << item1[3] << endl;
       item1[1] = 'c';
       item1[2] = 'i';
       item1[3] = 's';
       cout << item1[1] << item1[2] << item1[3] << endl;
       const MyString item4("chair");
       cout << item4[0] << endl;


       cout << "enter two inventory items: ";
       cin >> item1 >> item2;
       cout << "you entered " << item1 << " and " << item2 << endl << endl;

   }

   void f(MyString item1)
   {
       item1.setInfo("pizza", 67);
   }



/*




The Big Four has been reduced to the Big-3.
The Big-3 are the three member functions that must be included in any class which
 uses dynamic memory.
 The Assignment operator
 The Copy Constructor
 The Destructor

*/
