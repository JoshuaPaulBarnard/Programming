/*
Joshua Paul Barnard
CS 11 - SRJC
Spring 2017
Assignment 5 - 1
mystring.cpp


*/

#pragma warning(disable:4996)
#include <stdio.h>
#include "mystring.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
using namespace std;

namespace cs_mystring
{

    MyString::MyString()
    {
        lengthValue = 0;
        String = new char[1];
        strcpy( String, "" );
    }






    MyString::MyString( const char *inString )
    {
        lengthValue = 0;
        String = new char[ strlen( inString ) + 1] ;

        strcpy( String, inString );
    }






    MyString::MyString( const MyString& right )
    {
        lengthValue = right.lengthValue;
        String = new char[ strlen( right.String ) + 1 ];
        strcpy( String, right.String );
    }






    MyString::~MyString()
    {
        delete [] String;
    }






    std::ostream& operator<<( std::ostream& out, const MyString& source )
    {
        out << source.String;
        return out;
    }



    /*
        The String in istream is read into a temp array.
        A new array is then allocated to the exact size of the String and termChar stored in temp.
        The string stored in temp is then copied into the new array and returned.
    */


    std::istream& operator>>( std::istream& in, MyString& right )
    {
        char temp[ 128 ];
        in >> temp;

        delete [] right.String;
        right.String = new char[ strlen( temp ) + 1 ];
        strcpy( right.String, temp );

        return in;
    }



    /*
        Initially we skip over spaces using isspace, in.peek, and in.ignore.
        Then we make a temp char array, and use getline to read from the stream until the
        deliminating char "target" which is passed in as a argument.
        The string is stored in temp is copied to "String" after deallocting the string array.
    */


    void MyString::read( std::istream& in, char target )
    {
        while( isspace( in.peek() ) )
        in.ignore();

        char temp[ 128 ];
        in.getline( temp, 128, target );

        delete [] String;
        String = new char[ strlen( temp ) + 1 ];
        strcpy( String, temp );
    }






    int MyString::length()const
    {
        int lengthValue = strlen( String );
        return lengthValue;
    }






    MyString operator+( const MyString& left, const MyString& right )
    {
        MyString solution;
        char *temp;
        temp = new char[ strlen( left.String ) ];

        strcpy( temp, left.String );
        char *ccString;
        ccString = new char[ strlen( temp ) + strlen( right.String ) ];
        ccString = strcat( temp, right.String );

        solution = ccString;
        return solution;
    }





	MyString MyString::operator+=( const MyString& right )
	{
		*this = *this + right;
		return *this;
	}




    
	MyString MyString::operator=( const MyString& right )
    {
        if ( this != &right )
        {
          lengthValue = right.lengthValue;

          delete [] String;
          String = new char[ strlen( right.String ) + 1 ];

          strcpy( String, right.String );
        }
        return *this;
    }





    char MyString::operator[]( int index ) const
    {
        assert( index >= 0 && index < strlen( String ) );
        return String[index];
    }






    char& MyString::operator[]( int index )
    {
        assert( index >= 0 && index < strlen( String ) );
        return String[ index ];
    }






    bool operator<( const MyString& left, const MyString& right )
    {
		bool status = false;

        if(strcmp(left.String, right.String) < 0 )
        {
            status = true;
        }

        return status;
    }






    bool operator<=( const MyString& left, const MyString& right )
    {
		bool status = false;

		if ( strcmp( left.String, right.String ) <= 0 )
		{
			status = true;
		}

		return status;
	}






    bool operator>( const MyString& left, const MyString& right )
    {
		bool status = false;

		if ( strcmp( left.String, right.String ) > 0 )
		{
			status = true;
		}

		return status;
	}






    bool operator>=( const MyString& left, const MyString& right )
    {
		bool status = false;

		if ( strcmp( left.String, right.String ) >= 0 )
		{
			status = true;
		}

		return status;
	}






    bool operator==( const MyString& left, const MyString& right )
    {
		bool status = false;

		if ( strcmp( left.String, right.String ) == 0 )
		{
			status = true;
		}

		return status;
	}






    bool operator!=( const MyString& left, const MyString& right )
    {
		bool status = false;

        if( strcmp( left.String, right.String ) != 0 )
        {
            status = true;
        }

        return status;
    }
}

/*
----- Testing basic String creation & printing
string [0] = Wow
string [1] = C++ is neat!
string [2] =
string [3] = a-z

----- Testing access to characters (using const)
Whole string is abcdefghijklmnopqsrtuvwxyz
now char by char: abcdefghijklmnopqsrtuvwxyz
----- Testing access to characters (using non-const)
Start with abcdefghijklmnopqsrtuvwxyz and convert to ABCDEFGHIJKLMNOPQSRTUVWXYZ

----- Testing relational operators between MyStrings
Comparing app to apple
Is left < right? true
Is left <= right? true
Is left > right? false
Is left >= right? false
Does left == right? false
Does left != right ? true
Comparing apple to
Is left < right? false
Is left <= right? false
Is left > right? true
Is left >= right? true
Does left == right? false
Does left != right ? true
Comparing  to Banana
Is left < right? true
Is left <= right? true
Is left > right? false
Is left >= right? false
Does left == right? false
Does left != right ? true
Comparing Banana to Banana
Is left < right? false
Is left <= right? true
Is left > right? false
Is left >= right? true
Does left == right? true
Does left != right ? false

----- Testing relations between MyStrings and char *
Comparing he to hello
Is left < right? true
Is left <= right? true
Is left > right? false
Is left >= right? false
Does left == right? false
Does left != right ? true
Comparing why to wackity
Is left < right? false
Is left <= right? false
Is left > right? true
Is left >= right? true
Does left == right? false
Does left != right ? true

----- Testing copy constructor and operator= on MyStrings
original is cake, copy is fake
original is cake, copy is fake
after self assignment, copy is Copy Cat
Testing pass & return MyStrings by value and ref
after calling Append, sum is Binky
val is winky
after assign,  val is Binky
Press any key to continue . . .
*/