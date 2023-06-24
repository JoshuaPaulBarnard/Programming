//-----------------------------------------------------
//  this program presents a menu of four choices of
//  math problems for the user to choose
//  filename: menu.cpp      by Patrick Panelli
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
		cout << "please enter \n 1 to find a numbers factorial \n 2 to sum between a range of numbers \n 3 to find the probability of two people in a group having the same birthday \n 4 to find the GCF of two numbers \n 5 to end" << endl;
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
   int last;
   float p, numerator;
   cout.setf(ios::fixed);
   cout.precision(2);
   last = 365-n+1;
   numerator = 365;
   p=1;
   do
   		{
   			p = p * (numerator/365);
   			numerator--;
   		}	
   	while(numerator >= last);
	return 1-p;		
}

// finds the greatest common factor between
// two passed in numbers, returns the result
int
commonfactor(int a, int b)
{
   int factor = 1;
   int i, number;
   if (a<b)
   	{
   		number = a;
   	}
	else
	{
		number = b;
	}
	for (i=1;i<=number;i++)
		{
			if (a % i == 0 && b % i == 0)
			{
				factor = i;
			}
		}
	return factor;
}


int
main()
{
   int choice, answer, value1, value2;
   float prob;
      
   do
   {
      choice = menu();
      switch(choice)
      {
         case 1: cout << "Factorial number please : ";
                 cin  >> value1;
                 answer = factorial(value1);
                 cout << value1 << " ! = " << answer << endl;
                 break;
                 
         case 2: cout << "Two values to sum between please : \n";
                 cin  >> value1 >> value2;
                 answer = total(value1,value2);
                 cout << "the sum from " << value1 << " to "
                      << value2 << " is " << answer << endl;
                 break;
                 
         case 3: cout << "Please enter the numer of people in the room : ";
         		 cin >> value1;
         		 prob = sameday(value1);
         		 cout << "the odds of two people having the same birthday are " << prob << endl;
         		 break;
            
         case 4: cout << "Please enter two numbers you would like to find the GCF for : "; 
         		 cin >> value1 >> value2;
         		 answer = commonfactor(value1,value2);
         		 cout << "The greatest common factor of : " << " " << value1 << " " << "&" << " " << value2 << " " << "is " << answer << endl;
         		 break;
         		 
         case 5: break;
         
         default: cout << "illegal choice\n";
                  break;
      }
   }
   while (choice != 5);
   
   return 0;
}
                     
                     
         
