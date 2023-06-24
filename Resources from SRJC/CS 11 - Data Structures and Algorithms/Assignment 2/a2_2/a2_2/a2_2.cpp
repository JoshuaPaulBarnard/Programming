/*
Joshua Paul Barnard
CS 11 - SRJC
Spring 2018
Assignment 2 - 2
a2_2.cpp

This program will prompt the user to input text.
The program will count the letter in a struct as the user inputs the text.
This program will output a list of letters in the users next, with the frequency of each letter,
and all the text entered after the period.
*/

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int lettersAmount = 26;

struct letterInfo
{
	int letterCounter;
	char letter;
};

int main() {
	char userInput;
	letterInfo Letters[lettersAmount];


	// Loop for initializing an array of structs
	for (int i = 0; i < lettersAmount; i++)
	{
		Letters[i].letter = static_cast<char>(i + 65);
		Letters[i].letterCounter = 0;
	}


	// User Input
	cout << "Please enter text, ending with a ." << endl;
	cin >> userInput;
	while (userInput != '.') 
	{
		if ('A' <= toupper( userInput ) && toupper( userInput ) <= 'Z' )
		{
			Letters[ static_cast<int>( toupper( userInput ) ) - 65 ].letterCounter++;
		}
		cin >> userInput;
	}


	// Output
	for( int index = 0; index < lettersAmount; index++ )
	{
		if( Letters[ index ].letterCounter > 0 )
		{
			cout << " " << Letters[index].letter << " was observed " << Letters[index].letterCounter << " times" << endl;
		}
	}

	if( cin.peek() != '\n' ) 
	{
		cout << "The following characters were entered after the '.': ";
		cin.get( userInput );

		while( userInput != '\n' ) 
		{
			cout << userInput;
			cin >> userInput;
		}

		cout << endl;
	}

	return 0;
}

/*
Please enter text, ending with a .
John Jacob Jingle Himer Schmidt, thats my name too.
A was observed 3 times
B was observed 1 times
C was observed 2 times
D was observed 1 times
E was observed 3 times
G was observed 1 times
H was observed 4 times
I was observed 3 times
J was observed 3 times
L was observed 1 times
M was observed 4 times
N was observed 3 times
O was observed 4 times
R was observed 1 times
S was observed 2 times
T was observed 4 times
Y was observed 1 times
*/