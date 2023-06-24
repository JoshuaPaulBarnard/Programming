/*
Joshua Paul Barnard
CS 11 - SRJC
Spring 2018
Assignment 12 - 2
a12_2.cpp

*/

#pragma warning(disable:4996)
#include <cstdio>
#include "a12_2.h"
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
		String = new char[1];
		strcpy( String, "" );
	}






	MyString::MyString( const char *inString )
	{
		String = new char[ strlen( inString ) + 1 ];
		strcpy( String, inString );
	}






	MyString::MyString( const MyString& right )
	{
		String = new char[ strlen( right.String ) + 1 ];
		strcpy( String, right.String );
	}






	MyString::~MyString()
	{
		delete[] String;
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
		delete[] right.String;
		char temp[ 128 ];
		in >> temp;
		
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
		while ( isspace(in.peek() ) )
			in.ignore();

		char temp[ 128 ];
		in.getline( temp, 128, target );

		delete[] String;
		String = new char[ strlen( temp ) + 1 ];
		strcpy( String, temp );
	}






	int MyString::length()const
	{
		return strlen( String );
	}






	MyString operator+( const MyString& left, const MyString& right )
	{
		MyString solution;
		delete[] solution.String;

		solution.String = new char[strlen(left.String) + strlen(right.String) + 1];
		strcpy( solution.String, left.String );
		strcat( solution.String, right.String );
		
		return solution;
	}





	MyString MyString::operator+=( const MyString& right )
	{
		*this = *this + right;
		return *this;
	}





	MyString MyString::operator=( const MyString& right )
	{
		if (this !=& right)
		{
			delete[] String;
			String = new char[ strlen( right.String ) + 1 ];

			strcpy( String, right.String );
		}
		return *this;
	}





	char MyString::operator[]( int index ) const
	{
		assert( index >= 0 && index < strlen( String ) );
		return String[ index ];
	}






	char& MyString::operator[]( int index )
	{
		assert( index >= 0 && index < strlen( String ) );
		return String[ index ];
	}






	bool operator<( const MyString& left, const MyString& right )
	{
		bool status = false;

		if( strcmp( left.String, right.String ) < 0 )
		{
			status = true;
		}

		return status;
	}






	bool operator<=( const MyString& left, const MyString& right )
	{
		bool status = false;

		if( strcmp( left.String, right.String ) <= 0 )
		{
			status = true;
		}

		return status;
	}






	bool operator>( const MyString& left, const MyString& right )
	{
		bool status = false;

		if( strcmp( left.String, right.String ) > 0 )
		{
			status = true;
		}

		return status;
	}






	bool operator>=( const MyString& left, const MyString& right )
	{
		bool status = false;

		if( strcmp( left.String, right.String ) >= 0 )
		{
			status = true;
		}

		return status;
	}






	bool operator==( const MyString& left, const MyString& right )
	{
		bool status = false;

		if( strcmp( left.String, right.String ) == 0 )
		{
			status = true;
		}

		return status;
	}






	bool operator!=( const MyString& left, const MyString& right )
	{
		bool status = false;

		if ( strcmp( left.String, right.String) != 0 )
		{
			status = true;
		}

		return status;
	}

	bool isAPalindrome( const MyString& inputString, int left, int right )
	{
		if ( left >= right ) 
		{
			return true;
		}
		else if ( ispunct( inputString[ left ] ) || isspace( inputString[ left] ) ) 
		{
			return isAPalindrome( inputString, left + 1, right );
		}
		else if ( ispunct( inputString[ right ] ) || isspace( inputString[ right ] ) ) 
		{
			return isAPalindrome( inputString, left, right - 1 );
		}
		else if ( toupper( inputString[ left ] ) != toupper( inputString[ right ] ) ) 
		{
			return false;
		}
		else 
		{
			return isAPalindrome( inputString, left + 1, right - 1 );
		}
	}
}

/*
----- Testing basic String creation & printing
string [0] = Wow
string [1] = C++ is neat!
string [2] =
string [3] = a-z

----- Now reading MyStrings from file

----- first, word by word
Read string = The
Read string = first
Read string = time
Read string = we
Read string = will
Read string = read
Read string = individual
Read string = words,
Read string = next
Read string = we
Read string = read
Read string = whole
Read string = lines

----- now, line by line
Read string = The  first  time  we  will
Read string = read individual words, next
Read string = we read whole lines

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

----- Testing concatentation on MyStrings
outrageous + milk = outrageousmilk
milk +  = milk
+ cow = cow
cow + bell = cowbell

----- Testing concatentation between MyString and char *
abcde + XYZ = abcdeXYZ
XYZ + abcde = XYZabcde

----- Testing shorthand concat/assign on MyStrings
who += what = whowhatandwhowhat
what += WHEN = whatWHENandwhatWHEN
WHEN += Where = WHENWhereandWHENWhere
Where += why = WherewhyandWherewhy

----- Testing shorthand concat/assign using char *
I love  += programming = I love programming

----- Testing copy constructor and operator= on MyStrings
original is cake, copy is fake
original is cake, copy is fake
after self assignment, copy is Copy Cat
Testing pass & return MyStrings by value and ref
after calling Append, sum is BinkyBoo
val is winky
after assign,  val is BinkyBoo


-------------------------------------------------------------------
Palindrome Test
This function will check whether or a word is a Palindrome or not.
Type ~ to quit

Please enter a word to check:  hi
hi is not a palindrome.
Please enter a word to check:  hello
hello is not a palindrome.
Please enter a word to check:  6886
6886 is a palindrome.
Please enter a word to check:  bob
bob is a palindrome.
Please enter a word to check:  ~
Press any key to continue . . .
*/