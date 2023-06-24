//-----------------------------------------------------
//  Program returns the factors for an inputted number.
//  filename: factors.cpp      by Joshua Paul Barnard
//-----------------------------------------------------

#include<iostream>
using namespace std;

int main()
{
	int i,num1,num2,num3;

	cout<<"Enter a number:";
	cin>>num1;
	cout<<"The factors of given number are:\n";
	for(i=1;i<=num1;i++)
	{
		if(num1%i==0)
		{
			cout<<i<<" ";
		}
	}
	cout<<'\n';


	cout<<"\nEnter a number:";
	cin>>num2;
	cout<<"The factors of given number are:\n";
	for(i=1;i<=num2;i++)
	{
		if(num2%i==0)
		{
			cout<<i<<" ";
		}
	}
	cout<<'\n';


	cout<<"\nEnter a number:";
	cin>>num3;
	cout<<"The factors of given number are:\n";
	for(i=1;i<=num3;i++)
	{
		if(num3%i==0)
		{
			cout<<i<<" ";
		}
	}
	cout<<'\n';

	return 0;
}
