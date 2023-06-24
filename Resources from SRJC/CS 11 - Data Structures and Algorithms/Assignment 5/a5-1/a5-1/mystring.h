/*
Joshua Paul Barnard
CS 11 - SRJC
Spring 2017
Assignment 5 - 1
mystring.h

*/

#pragma warning(disable:4996)
#ifndef mystring_h
#define mystring_h
#include <iostream>

namespace cs_mystring {

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
			MyString operator+=(const MyString& right);

			MyString operator=( const MyString& right );

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
			int lengthValue;


	};
}

	#endif
