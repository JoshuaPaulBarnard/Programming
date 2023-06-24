/*
Joshua P. Barnard
CS 11 - SRJC
Spring 2018
Assignment 8 - 1
a8-1.cpp

*/

#include <iostream>
#include <vector>
using namespace std;

const int MAX_NAMESIZE = 24;
struct highscore 
{
	char name[ MAX_NAMESIZE ];
	int score;
};

void getArraySize( int& size );
void initializeData( vector<highscore>& scores );
void sortData( vector<highscore>& scores );
void displayData( const vector<highscore>& scores );
vector<highscore>::iterator indexOfLargest( const vector<highscore>& scores, vector<highscore>::iterator j );

int main()
{
	int size;
	getArraySize( size );
	vector<highscore> scores( size );
	initializeData( scores );
	sortData( scores );
	displayData( scores );
	system( "pause" );
}






void getArraySize( int& size )
{
	cout << "How many scores will you enter?: ";
	cin >> size;
	cin.ignore();
}






void initializeData( vector<highscore>& scores )
{
	int count = 0;
	for( vector<highscore>::iterator i = scores.begin(); i != scores.end(); i++, count++ )
	{
		cout << "Enter the name for score #" << ( count + 1 ) << ": ";
		cin >> ( *i ).name;
		cout << "Enter the score for score #" << ( count + 1 ) << ": ";
		cin >> ( *i ).score;
		cin.ignore();
	}
	cout << endl;
}






void sortData( vector<highscore>& scores )
{
	for( vector<highscore>::iterator i = scores.begin(); i != scores.end() - 1; i++ ) 
	{
		vector<highscore>::iterator largetsIndex;
		largetsIndex = indexOfLargest( scores, i );
		swap( *i, *largetsIndex );
	}
}






vector<highscore>::iterator indexOfLargest ( const vector<highscore>& scores, 
	vector<highscore>::iterator j )
{
	vector<highscore>::iterator targetIterator = j;
	vector<highscore>::iterator targetOut;
	for ( vector<highscore>::iterator i = j + 1; i != scores.end(); i++ ) 
	{
		if ( i->score > targetIterator->score ) 
		{
			targetIterator = i;
		}
	}
	return targetIterator;
}






void displayData( const vector<highscore>& scores )
{
	cout << "Top Scorers: " << endl;
	for( vector<highscore>::const_iterator i = scores.begin(); 
		i != scores.end(); i++ ) 
	{
		cout << i->name << ": " << i->score << endl;
	}
}
