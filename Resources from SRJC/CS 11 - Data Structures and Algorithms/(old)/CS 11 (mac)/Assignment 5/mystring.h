/*
Joshua Paul Barnard
CS 11 - SRJC
Spring 2017
Assignment 5 - 1
mystring.h

*/

#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>

class MyString
{
    public:
        MyString();
        MyString( const char *inString );
        MyString::MyString( const MyString& right );
        ~MyString();
        friend std::ostream& operator<<( std::ostream& out, const MyString& source );
        friend std::istream& operator>>( std::istream& in, MyString& right );
        void read( std::istream& in, char target );
        int length() const;
        MyString operator+( const MyString& left, const MyString& right );
        MyString operator=( const MyString& right );
        MyString operator+=( const MyString& right );
        char operator[]( int index ) const;
        char& operator[]( int index );
        MyString operator<( const MyString& left, const MyString& right );
        MyString operator<=( const MyString& left, const MyString& right );
        MyString operator>( const MyString& left, const MyString& right );
        MyString operator>=( const MyString& left, const MyString& right );
        MyString operator==( const MyString& left, const MyString& right );
        MyString operator!=( const MyString& left, const MyString& right );

    private:
        char *String;
        int length;
};

#endif
