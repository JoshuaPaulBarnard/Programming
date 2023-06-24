//-------------------------------------------------------------------------------------------
//Joshua P. Barnard
//CS 111 Homework 10/07/13
//Prime Factorization
//This program is used to determine if a positive integer more than 2 is prime
//--------------------------------------------------------------------------------------------

#include <iostream>
using namespace std;



int main(){

int integer;
int count = 2;
int prime;

cout<<"Enter a positive integer more than 2:  ";
cin>>integer;


while (count < integer && prime != 0)
{
	prime = integer % count;                       
										  //Test to see if integer is prime by remainder division
	count = count + 1;
}	
	
	                                      //Display Whether the integer is prime or not
	if (count == integer)
		cout << '\n' << "The number " << integer << " is prime." << '\n';
	
	else if (count != integer)
		cout << '\n' << "The number " << integer << " is not prime." << '\n';
	

return 0;
}
