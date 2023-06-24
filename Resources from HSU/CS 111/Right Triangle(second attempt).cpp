//---------------------------------------------------------------------
//Joshua P. Barnard
//CS 111 Fall 2013
//Due: 11/07/13
//This program determines if three integers are a Right Triangle, and finds the
//factors for each integer.
//---------------------------------------------------------------------


#include <iostream>
using namespace std;

//******************************************************************************
//This is the function for factoring each integer.
//******************************************************************************

void factors (int value)
{
	int i; 
	
	cout<<"The factors of " << value << " are\n"; 
	for(i=1; i <= value; i++)
	{
		if(value % i == 0) 
		{
			cout<<i<<" ";
		}
	}
	cout<<'\n';
}


//******************************************************************************
//This is the function for determining if the three integers form a Right 
//Triangle or not.
//******************************************************************************

char RightTriangle (int a, int b, int c)
{
	int a2 = a*a;
	int b2 = b*b;
	int c2 = c*c;
	char answer;
	
	if (a2+b2==c2)
		cout<<"Yes, It is a right triangle.\n";
	
	else
		cout<<"No, It is not a right triangle.\n";
	return (answer);
}


//******************************************************************************
//This is the main function for inputting the values.
//******************************************************************************

int main()
{
	int a, b, c;
	char more, answer;
	a=0;
	b=0;
	c=0;
	more = 'y';
	answer = 'x';
	int count = 1;
	
	while (count <=4)
	{
		cout<<"Please Input Three Positive Integers:  \n";
		cin>>a>>b>>c;
		factors(a);
		factors(b);
		factors(c);
		answer = RightTriangle(a,b,c);
		count++;
		cout<<'\n';
	}
	
	
	return 0;
}
