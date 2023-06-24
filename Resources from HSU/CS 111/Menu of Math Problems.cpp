//-----------------------------------------------------
//  This program presents a menu of four choices of
//  different math problems for the user to choose.
//   filename: menu.cpp      by Joshua P. Barnard
//-----------------------------------------------------

#include <iostream>
using namespace std;

// outputs several choices to the user,
// inputs and returns the choice selected
// note that choice 5 is to end the program
int
menu()
{
   int x;
   cout << "Please Enter Your Selection: \n1 - Find a Numbers Factorial. \n2 - Sum up a sequence of numbers between a given range. \n3 - Finding the probability of two individuals having the same birthdate. \n4 - Find the Greatest Common Factor (GCF) of two integers. \n5 - End the program." << endl;
   cin >> x;
   return x;

}

// receives a number to find its factorial
// the result is returned
int
factorial(int value)
{
   int result, multiple;

   result = 1;
   for(multiple = 1; multiple <=value; multiple++)
   {
      result *= multiple;
   }
   return result;
}

// receives two numbers to sum from the
// first to the second, returning the answer
int
total(int a, int b)
{
   int sum;

   sum = a;
   while(a < b)
   {
      a++;
      sum = sum + a;
   }
   return sum;
}

// receives a number representing the amount of
// people present, and returns the probability
// that at least two have the same birthday
float
sameday(int n)
{

}

// finds the greatest common factor between
// two passed in numbers, returns the result
int
commonfactor(int a, int b)
{

}

int
main()
{
   int choice, answer, value1, value2;
   float prob;

   do
   {
      choice = menu();
      //cin >> choice;
      switch(choice)
      {
         case 1: cout << "Factorial number please : ";
                 cin  >> value1;
                 answer = factorial(value1);
                 cout << value1 << " ! = " << answer << endl;
                 break;

         case 2: cout << "Two values to sum between please : ";
                 cin  >> value1 >> value2;
                 answer = total(value1,value2);
                 cout << "the sum from " << value1 << " to "
                      << value2 << " is " << answer << endl;
                 break;
         case 3:

         case 4:

         case 5: break;

         default: cout << "illegal choice\n";
                  break;
      }
   }
   while (choice != 5);

   //system("pause");
   return 0;
} 
