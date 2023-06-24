/*
Joshua Barnard
CS 11 - Spring 2018
Assignment 12_2
MyString.cpp

*/

#include <stdio.h>
#include "MyString.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
namespace cs_mystring {
    
    
    
    MyString::MyString(const char *inString)
    {
        
        String = new char[strlen(inString) + 1];
        strcpy(String, inString);
    }
    
    
    MyString::MyString()
    {
        
        String = new char[1];
        strcpy(String, "");
    }
    
    
    
    
    
    
    
    
    
    MyString::MyString(const MyString& right)
    {
        
        String = new char[strlen(right.String) + 1];
        strcpy(String, right.String);
    }
    
    
    
    
    
    
    MyString::~MyString()
    {
        delete [] String;
    }
    
    
    
    
    
    
    std::ostream& operator<<(std::ostream& out, const MyString& source)
    {
        out << source.String;
        return out;
    }
    
    
    
    /*
     Here first the String in the istream is read into a temp array, Then a new array
     is allocated guaranteed to be the exact size of the String and termChar stored in temp.
     Last the string in temp is copied into the new array and returned.
     */
    
    
    std::istream& operator>>(std::istream& in, MyString& right)
    {
        delete [] right.String;
        char temp[128];
        in >> temp;
        right.String = new char[strlen(temp) +1];
        strcpy(right.String, temp);
        return in;
    }
    
    
    
    /*
     Here first we skip over spaces with isspace, in.peek, and in.ignore, then make
     a temp char array and use getline to read from the stream up till the deliminating
     char "target" which is passed in as a argument. After deallocting the String array
     the string stored in temp is copied to "String"
     */
    
    
    void MyString::read(std::istream& in, char target)
    {

        char temp[128];
        in.getline(temp, 128, target);
        delete [] String;
        String = new char[strlen(temp) + 1];
        strcpy(String, temp);
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    MyString operator+(const MyString& left, const MyString& right)
    {
        MyString result;
        delete [] result.String;
        result.String = new char[strlen(left.String) + strlen(right.String) + 1];
        strcpy(result.String, left.String);
        strcat(result.String, right.String);
        return result;
    }
  
    
    
    
    
    MyString MyString::operator=(const MyString& right)
    {
        if (this != &right){
           
            delete [] String;
            String = new char[strlen(right.String) + 1];
            strcpy(String, right.String);
        }
        return *this;
    }
    
    
    
    
    
    
    MyString MyString::operator+=(const MyString& right)
    {
        *this = *this + right;
        return *this;
    }
    
    
    
    
    
    
    char MyString::operator[](int index) const
    {
        assert(index >= 0 && index < strlen(String));
        return String[index];
    }
    
    
    
    
    
    
    char& MyString::operator[](int index)
    {
        assert(index >= 0 && index < strlen(String));
        return String[index];
    }
    
    
    
    
    
    
    bool operator<(const MyString& left, const MyString& right)
    {
        return strcmp(left.String, right.String) < 0;
    }
    
    
    
    
    
    
    bool operator>(const MyString& left, const MyString& right)
    {
        return strcmp(left.String, right.String) > 0;
    }
    
    
    
    
    
    
    bool operator<=(const MyString& left, const MyString& right)
    {
        return strcmp(left.String, right.String) <= 0;
    }
    
    
    
    
    
    
    bool operator>=(const MyString& left, const MyString& right)
    {
        
        //keeping to see the difference of simplification **
//        bool status;
//        if(strcmp(left.String, right.String) >= 0){
//            status = true;
//        } else {
//            status = false;
//        }
//        return status;
        
        return strcmp(left.String, right.String) >= 0;
    }
    
    
    
    
    
    
    bool operator==(const MyString& left, const MyString& right)
    {
        return strcmp(left.String, right.String) == 0;
    }
    
    
    
    
    
    
    bool operator!=(const MyString& left, const MyString& right)
    {
       return strcmp(left.String, right.String) != 0;
    }
    
    
    int MyString::length()const
    {
        
        return strlen(String);
    }
}
