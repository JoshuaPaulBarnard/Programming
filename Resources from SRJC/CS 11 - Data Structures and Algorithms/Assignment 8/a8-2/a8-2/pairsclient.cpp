/*
Joshua Barnard
CS 11 - Spring 2018
Assignment 8
pairsclient.cpp

*/


#include <iostream>
#include <ctime>
#include <cstdlib>
#include "orderedpair.h"
using namespace std;
using namespace cs_pairs;





int main() 
{
	int num1, num2;
	OrderedPair<int> myList[10];

	srand(static_cast<unsigned>(time(0)));
	cout << "default value: ";
	myList[0].print();
	cout << endl;

	for (int i = 0; i < 10; i++) {
		myList[i].setFirst(rand() % 50);
		myList[i].setSecond(rand() % 50 + 50);
	}

	myList[2] = myList[0] + myList[1];

	if (myList[0] < myList[1]) 
	{
		myList[0].print();
		cout << " is less than ";
		myList[1].print();
		cout << endl;
	}

	for( int i = 0; i < 10; i++ ) 
	{
		myList[i].print();
		cout << endl;
	}

	cout << "Enter two numbers to use in an OrderedPair.  Make sure they are different numbers: ";
	cin >> num1 >> num2;
	OrderedPair<int> x;

	try 
	{
		x.setFirst( num1 );
		x.setSecond( num2 );
	} 
	catch ( OrderedPair<int>::DuplicateMemberError e ) 
	{
		cout << "The two numbers inputted were equal to each other." << endl;
		x.setFirst( 0 );
		x.setSecond( 0 );
	}

	cout << "The resulting OrderedPair: ";
	x.print();
	cout << endl;


	string str1, str2;
	OrderedPair<string> myList2[10];
	
	srand(static_cast<unsigned>(time(0)));
	cout << "default value: ";
	myList2[0].print();
	cout << endl;

	for (int i = 0; i < 10; i++) 
	{
		string empty = "";
		myList2[i].setFirst(empty + char('a' + rand() % 26));
		myList2[i].setSecond(empty + char('A' + rand() % 26));
	}

	myList2[2] = myList2[0] + myList2[1];

	if (myList2[0] < myList2[1])
	{
		myList2[0].print();
		cout << " is less than ";
		myList2[1].print();
		cout << endl;
	}

	for (int i = 0; i < 10; i++)
	{
		myList2[i].print();
		cout << endl;
	}

	cout << "Enter two numbers to use in an OrderedPair.  Make sure they are different numbers: ";
	cin >> str1 >> str2;
	OrderedPair<string> y;

	try
	{
		y.setFirst(str1);
		y.setSecond(str2);
	}
	catch (OrderedPair<string>::DuplicateMemberError e)
	{
		cout << "The inputted strings were equal to each other." << endl;
		y.setFirst("");
		y.setSecond("");
	}


	cout << "The resulting OrderedPair: ";
	y.print();
	cout << endl;

	system( "pause" );
}

/*
default value: (0, 0)
(1, 87) is less than (34, 87)
(1, 87)
(34, 87)
(35, 174)
(40, 72)
(14, 99)
(45, 88)
(49, 93)
(39, 75)
(26, 51)
(3, 96)
Enter two numbers to use in an OrderedPair.  Make sure they are different numbers: 3
3
The two numbers inputted were equal to each other.
The resulting OrderedPair: (0, 0)


default value: (, )
(i, O)
(d, X)
(id, OX)
(f, S)
(q, X)
(q, T)
(w, T)
(n, A)
(c, C)
(i, N)
Enter two strings to use in an OrderedPair.  Make sure they are different strings: asd
asd
The inputted strings were equal to each other.
The resulting OrderedPair: (, )

*/
