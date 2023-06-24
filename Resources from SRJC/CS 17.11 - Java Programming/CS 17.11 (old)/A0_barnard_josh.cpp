// Joshua Paul Barnard
// A0 - Character Counter Program in C++
// Due:  1/24/2018
// CS 17.11 - Java Programming
// Microsoft Visual Studio 2017

//#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const int lettersAmount = 26;

struct letterInfo
{
	int letterCounter;
	char letter;
};

int main()
{
	ifstream inputFile;
	ofstream outputFile;
	string inputFileName;
	char character;
	letterInfo Letters[lettersAmount];

	// I/O options
	cout << "Please enter the name of the file you would like to open: ";
	cin >> inputFileName;

	inputFile.open(inputFileName.c_str());
	if (inputFile.fail())
	{
		cout << endl << "I am sorry, but there was a problem loading your file.";
		cout << endl << "Please Try Again" << endl << endl;
		return 1;
	}


/* SRK

WTF?
*/
	outputFile.open("A0-Character_Counter.txt");

	// Loop for initializing an array of structs
	for (int i = 0; i < lettersAmount; i++)
	{
		Letters[i].letter = static_cast<char>(i + 65);
		Letters[i].letterCounter = 0;
	}

	// Loops through file and counts each iterance of a letter
	inputFile >> character;
	while (!inputFile.eof())
	{
		if ('A' <= toupper(character) && toupper(character) <= 'Z')
			Letters[static_cast<int>(toupper(character)) - 65].letterCounter++;

		inputFile >> character;
	}

	inputFile.close();

/* SRK
there are always programs that make me scratch my head. why are you 
writing the output to a file? that wasn't in the spec, and it leaves 
a file left on my file system that will never, ever be used again?
you're lucky that it didn't cause an error 'cause that would have cost
you points. going forward, make sure that you do precisely what the 
project asks - i'll grade everything that you submit, and if you submit
that acts as an appendix (i.e., no useful addition to the program, i'll 
ding you for it.
*/
	// Output and Display the occurance of each letter
	outputFile << fixed << showpoint << setprecision(2);
	outputFile << "Letter     Observed" << endl;
	for (int index = 0; index < lettersAmount; index++)
	{
		if (Letters[index].letterCounter > 0)
		{
			cout << " " << Letters[index].letter << " was observed " << Letters[index].letterCounter << " times" << endl;
			outputFile << setw(4) << Letters[index].letter << setw(12) << Letters[index].letterCounter << " " << endl;
		}
	}

	outputFile.close();

	return 0;
}
