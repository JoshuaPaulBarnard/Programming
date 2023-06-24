/*
Joshua Paul Barnard
CS 11 - SRJC
Spring 2017
Assignment 5 - 1
mystring.cpp


*/

#include <stdio.h>
#include "mystring.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
using namespace std;

namespace cs_mystring {

    MyString::MyString()
    {
        length = 0;
        String = new char[1];
        strcpy( String, "" );
    }






    MyString::MyString( const char *inString )
    {
        length = 0;
        String = new char[ strlen( inString ) + 1] ;

        strcpy( String, inString );
    }






    MyString::MyString( const MyString& right )
    {
        length = right.length;
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






    int MyString::length() const
    {
        int length = strlen( String );
        return length;
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



    MyString MyString::operator=( const MyString& right )
    {
        if ( this != &right )
        {
          length = right.length;

          delete [] String;
          String = new char[ strlen( right.String ) + 1 ];

          strcpy( String, right.String );
        }
        return *this;
    }






    MyString MyString::operator+=( const MyString& right )
    {
        *this = *this + right;
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
        bool status = strcmp( left.String, right.String );

        if( status < 0 )
        {
            status = true;
        }

        return status;
    }






    bool operator<=( const MyString& left, const MyString& right )
    {
        bool status = strcmp( left.String, right.String );

        if( status <= 0 )
        {
            status = true;
        }

        return status;
    }






    bool operator>( const MyString& left, const MyString& right )
    {
        bool status = strcmp( left.String, right.String );

        if( status > 0 )
        {
            status = true;
        }

        return status;
    }






    bool operator>=( const MyString& left, const MyString& right )
    {
        bool status = strcmp( left.String, right.String );

        if( status >= 0 )
        {
            status = true;
        }

        return status;
    }






    bool operator==( const MyString& left, const MyString& right )
    {
        bool status = strcmp( left.String, right.String );

        if( status == 0)
        {
            status = true;
        }

        return status;
    }






    bool operator!=( const MyString& left, const MyString& right )
    {
        bool status = strcmp( left.String, right.String );

        if( status != 0 )
        {
            status = true;
        }

        return status;
    }
}
