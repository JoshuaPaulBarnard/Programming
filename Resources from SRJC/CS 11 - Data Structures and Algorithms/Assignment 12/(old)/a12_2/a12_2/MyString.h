/*
Joshua Barnard
CS 11 - Spring 2018
Assignment 12_2
MyString.h

*/

#ifndef MyString_h
#define MyString_h
#include <iostream>
namespace cs_mystring 
{
    class MyString 
	{
    public:
        MyString(  );
        MyString( const char *inString );
        MyString( const MyString& right );
        ~MyString(  );
        MyString operator=( const MyString& right );
        MyString operator+=( const MyString& right );
        int length(  )const;
        friend std::ostream& operator<<( std::ostream& out, const MyString& source );
        friend std::istream& operator>>( std::istream& in, MyString& target );
        void read( std::istream& in, char target );
        friend MyString operator+( const MyString& left, const MyString& right );
        friend bool operator<( const MyString& left, const MyString& right );
        friend bool operator>( const MyString& left, const MyString& right );
        friend bool operator<=( const MyString& left, const MyString& right );
        friend bool operator>=( const MyString& left, const MyString& right );
        friend bool operator==( const MyString& left, const MyString& right );
        friend bool operator!=( const MyString& left, const MyString& right );
        char operator[]( int index ) const;
        char& operator[]( int index );
    private:
        char *String;
        
    };
}
#endif /* MyString_h */
