/*
Joshua Barnard
CS 11 - Spring 2018
Assignment 12 - 1
a12_1.cpp

*/

#include <iostream> 
#include <cstring>
    using namespace std;

    void reverseWithinBounds( char a[], int lower, int upper );
    void reverseCstring( char string[] );

	int const array_size = 128;

    int main(  ) 
	{
		char inputString[ array_size ];

		cout << "Welcome to the String Reversal C++ Program by Joshua Paul Barnard" << endl;
		cout << "Type ~ to quit the program." << endl;
		cout << "Please enter a string to reverse:  ";
		cin.getline( inputString, array_size - 1, '\n');

		while( inputString[0] != '~'  )
		{
			cout << "Before:  " << inputString << endl;
			reverseCstring( inputString );
			cout << "After:  " << inputString << endl << endl;

			cout << "Please enter another string:  ";
			cin.getline(inputString, array_size - 1, '\n');
		}

		system("pause");

		/*
        const int numItems = 5;
        char array[ numItems ] = { 'A', 'B', 'C', 'D', 'E' };
		char cString[ 100 ];
		

        cout << "Array Before Reversing (Within Bounds): " << array << endl;
        reverseWithinBounds( array, 1, 4 );
        cout << "Array After Reversing (Within Bounds): " << array << endl;

        cout << "Please Enter A String To Be Reversed" << endl;
        cin >> cString;
        cout << "Your String Before Reversing: " << cString << endl;
        reverseCstring( cString );
        cout << "Your String After Reversing: " << cString << endl;
		*/
}






    void reverseWithinBounds( char aString[], int lowerBound, int upperBound )
    {
        if( lowerBound < upperBound ) 
		{
			char tempChar = aString[ lowerBound ];
			aString[ lowerBound ] = aString[ upperBound ];
			aString[ upperBound ] = tempChar;
			reverseWithinBounds( aString, lowerBound + 1, upperBound - 1 );
        }
    }





    void reverseCstring( char string[] )
    {
        reverseWithinBounds( string, 0, strlen( string ) -1 );
    }


/*
Welcome to the String Reversal C++ Program by Joshua Paul Barnard
Type ~ to quit the program.
Please enter a string to reverse:  Hello
Before:  Hello
After:  olleH

Please enter another string:  Todays date is: 05/14/2018
Before:  Todays date is: 05/14/2018
After:  8102/41/50 :si etad syadoT

Please enter another string:  ~
Press any key to continue . . .
 */
