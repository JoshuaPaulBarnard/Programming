//---------------------------------------------------------------------
//Joshua P. Barnard
//CS 111 Fall 2013
//Due: 11/07/13
//Right Triangle
//---------------------------------------------------------------------


#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	int count=1;
	
	cout<<"Please Input The Heights (Opposites) Whole Distance:  \n";
	cin>>a;
	
	cout<<"Please Input The Bases (Adjacent's) Whole Distance:  \n";
	cin>>b;
	
	cout<<"Please Input The Hypotenuses Whole Distance:  \n";
	cin>>c;
	
	
	return 0;
}

int factors (int a, int b, int c)
{
	int i; 
	
	cout<<"The factors of the height are:\n"; 
	for(i=1;i<=a;i++)
	{
		if(a%i==0) 
		{
			cout<<i<<" ";
		}
	}
	cout<<'\n';


	cout<<"The factors of the base are:\n"; 
	for(i=1;i<=b;i++)
	{
		if(b%i==0) 
		{
			cout<<i<<" ";
		}
	}
	cout<<'\n';
	

 
	cout<<"The factors of the hypotenuse are:\n"; 
	for(i=1;i<=c;i++)
	{
		if(c%i==0) 
		{
			cout<<i<<" ";
		}
	}
	cout<<'\n';
	
	return 0;
}


int RightTriangle (int a, int b, int c)
{
	int a2 = a*a;
	int b2 = b*b;
	int c2 = c*c;
	
	if (a2+b2==c2)
		cout<<"/nThis is a right triangle";
	
	else
		cout<<"/nThis is not a right triangle";
}

