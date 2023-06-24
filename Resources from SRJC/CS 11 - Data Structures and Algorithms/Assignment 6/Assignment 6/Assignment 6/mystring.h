/*
Joshua Paul Barnard
CS 11 - SRJC
Spring 2018
Assignment 6 - 1
mystring.h

This new class MyString makes it easier to work with strings and should provide
us with more control and less errors than using the native C-strings.  
The client program can use and declare MyStrings, and the input/output, class construction,
concatenating, comparing, and indexing operations are provided.

myString();
post: myString is initialized as an empty string.

myString ( const char* inString );
post: myString object is initialized to char inString.

myString( const myString& right );
post: myString object is initialized to the const right.

friend ostream& operator<<( ostream& out, const myString& source );
pre: out is prepared to be written.
post: source is placed into out.

friend istream& operator>>( istream& in, myString& target );
pre: in is prepared to be read with a sequence of characters of 128 or less characters.
post: The sequence of characters are extracted from in and placed in target.
The leading whitespace character is ignored, and the function ends at the next whitespace.

void read( istream& in, char target );
pre: in is prepared to read a sequence of characters with less than 128 characters.
post: The in characters are ended by target and then extracted and placed into the calling function.

int length() const;
post: Returns the number of characters in the called object.

friend myString operator+( const myString& left, const myString& right );
post: Returns the concatenatation of left and right.

myString operator+=( const myString& right );
post: Returns left after concatenating left and right.

myString operator=(const myString& right);
post: right is placed in the objected called.

char operator[] ( int index ) const;
pre: Index initialized to 0
post: Returns the character at position index. 

char& operator[]( int index );
pre: Index initialized to 0
post: Returns the character at position index. 

friend bool operator<( const myString& left, const myString& right );
post: Returns false unless left is less than right.

friend bool operator<=(const myString& left, const myString& right);
post:  Returns false unless left is less or equal to right.

friend bool operator>( const myString& left, const myString& right );
post:  Returns false unless left is more than right.

friend bool operator>=(const myString& left, const myString& right);
post: Returns false unless left is more than or equal to the right.

friend bool operator==(const myString& left, const myString& right);
post:  Returns false unless left is equal to right.

friend bool operator!=(const myString& left, const myString& right);
post:  Returns false unless left is not equal to the right.

myString operator=(const myString& right);
post: A copy of "right" is stored in the calling object.
*/

#pragma warning(disable:4996)
#ifndef mystring_h
#define mystring_h
#include <iostream>

namespace cs_mystring 
{

	class MyString
	{
	public:
		MyString();
		MyString( const char *inString );
		MyString( const MyString& right );
		~MyString();

		friend std::ostream& operator<<( std::ostream& out, const MyString& source );
		friend std::istream& operator>>( std::istream& in, MyString& target );
		void read( std::istream& in, char target );

		int length()const;

		friend MyString operator+( const MyString& left, const MyString& right );
		MyString operator+=( const MyString& right );
		MyString operator= (const MyString& right );

		char operator[]( int index ) const;
		char& operator[]( int index );

		friend bool operator<( const MyString& left, const MyString& right );
		friend bool operator<=( const MyString& left, const MyString& right );
		friend bool operator>( const MyString& left, const MyString& right );
		friend bool operator>=( const MyString& left, const MyString& right );
		friend bool operator==( const MyString& left, const MyString& right );
		friend bool operator!=( const MyString& left, const MyString& right );

	private:
		char *String;

	};
}

#endif
