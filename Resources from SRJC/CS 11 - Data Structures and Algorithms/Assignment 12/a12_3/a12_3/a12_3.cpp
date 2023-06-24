/*
Joshua Barnard
CS 11 - Spring 2018
Assignment 12_3
a12_3.cpp

*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

    int indexOfSmallest( int array[], int startingIndex, int size );
    void sortArray( int array[], int start, int end );

	int const array_size = 5;

	void main()
	{
		srand( time( NULL ) );
		int randomArray[ array_size ];


		for( int index = 0; index < array_size; ++index ) 
		{
			randomArray[ index ] = rand() % 10;
		}

		cout << "Array Before being Sorted:  " << endl;
		for ( int counter = 0; counter < array_size; counter++ )
		{
			cout << randomArray[ counter ] << " ";
		}
		cout << endl << endl;

		sortArray( randomArray, 0, array_size );
		cout << "Array After being Sorted:  " << endl;
		for( int counter = 0; counter < array_size; counter++ )
		{
			cout << randomArray[ counter ] << " ";
		}
		cout << endl << endl;
		
		system("pause");
	}




    void sortArray( int array[], int start, int end )
    {
        if( start < end ) 
		{
            swap( array[ start ], array[ indexOfSmallest( array, start, end ) ] );
            sortArray( array, ++start, end );
        }
    }






    int indexOfSmallest( int array[], int startingIndex, int end )
    {
        int targetIndex = startingIndex;
        for ( int i = startingIndex ; i < end; i++ )
		{
            if ( array[i] < array[targetIndex] )
			{
                targetIndex = i;
            }
        }
        return targetIndex;
    }



/*
Array Before being Sorted:
1 1 8 5 0

Array After being Sorted:
0 1 1 5 8

Press any key to continue . . .

*/
