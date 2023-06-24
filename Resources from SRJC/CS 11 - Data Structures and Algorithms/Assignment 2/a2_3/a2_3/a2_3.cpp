/*
Joshua Paul Barnard
CS 11 - SRJC
Spring 2018
Assignment 2 - 3
a2_3.cpp

This program receives an integer indicating the number of players in to score.
The program then call the initializeData function which initializes our struct with
the users inputint a name and score for each participant.
The program will then call the sortData function to sort the data in descending order.
The program will then call the displayData function to output the data, showing
the top scores first with the lowerest score last.
*/

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct highScore
{
	int score;
	char *name = new char[24];
};

void initializeData( highScore scores[], int size );
int indexOfLargest( highScore scores[], int startingIndex, int size );
void sortData( highScore scores[], int size );
void displayData( const highScore scores[], int size );

// Loop to initialize the struct
void initializeData( highScore scores[], int size )
{
	for ( int i = 0; i < size; i++ )
	{
		cout << "Enter the name for participant #" << i + 1 << ": \t";
		cin >> scores[i].name;
		cout << "Enter the score for participant #" << i + 1 << ": \t";
		cin >> scores[i].score;
	}
}

int indexOfLargest( highScore scores[], int startingIndex, int size )
{
	int targetIndex = startingIndex;

	for( int i = startingIndex + 1; i < size; i++ )
	{
		if( scores[i].score > scores[targetIndex].score )
		{
			targetIndex = i;
		}
	}

	return targetIndex;
}

void sortData( highScore scores[], int size )
{
	int largestIndex = 0;

	for ( int i = 0; i < size - 1; ++i )
	{
		largestIndex = indexOfLargest( scores, i, size );
		swap(scores[largestIndex], scores[i]);
	}
}


void displayData( const highScore scores[], int size )
{
	cout << endl << "Top Scores:" << endl;
	for( int i = 0; i < size; i++ )
	{
		cout << scores[i].name << ": " << scores[i].score << endl;
	}
}


int main()
{
	int size = 0;
	highScore *scores;

	cout << "How many scores will you enter?: \t";
	cin >> size;

	scores = new highScore[ size ];

	initializeData( scores, size );
	sortData( scores, size );
	displayData( scores, size );

	return 0;
}

/*
How many scores will you enter?:        4
Enter the name for participant #1:      Suzy
Enter the score for participant #1:     600
Enter the name for participant #2:      Jeff
Enter the score for participant #2:     9900
Enter the name for participant #3:      Armando
Enter the score for participant #3:     8000
Enter the name for participant #4:      Tim
Enter the score for participant #4:     514

Top Scores:
Jeff: 9900
Armando: 8000
Suzy: 600
Tim: 514
*/