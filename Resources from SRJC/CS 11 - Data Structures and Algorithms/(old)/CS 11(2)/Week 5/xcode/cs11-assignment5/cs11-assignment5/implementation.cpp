//
//  implementation.cpp
//  cs11-assignment5
//
//  Created by Joshua Barnard on 9/28/17.
//  Copyright © 2017 Joshua Barnard. All rights reserved.
//

#include <stdio.h>
#include "mystring.h"
#include <iostream>
#include <cassert>
namespace cs_mystring
{
    MyString:: MyString()
    {
        information = new char[1];
        strcpy(information, "");
    }
    
    MyString:: MyString(const char* inString)
    {
        units = 0;
        information = new char[strlen(inString) + 1];
        strcpy(information, inString);
    }
    
    MyString::MyString(const MyString& right)
    {
        units = right.units;
        information = new char[strlen(right.information) + 1];
        strcpy(information, right.information);
    }
    
    MyString::~MyString()
    {
        delete [] information;
    }
    
    MyString MyString::operator=(const MyString& right)
    {
        if (this != &right){
            units = right.units;
            delete [] information;
            information = new char[strlen(right.information) + 1];
            strcpy(information, right.information);
        }
        return *this;
    }
  
    int MyString::length(const MyString& inString)const{
    
        int length = strlen(inString.information);
        return units;
    }

    std::ostream& operator<<(std::ostream& out, const MyString& source)
    {
        out << source.units << " " << source.information;
        return out;
    }
    
    /*
    
    std::istream& operator>>(std::istream& in, MyString& target)
    {
        while (isspace(in.peek())){
            in.ignore();
        }
        
        char temp[128];
        in.getline(temp, 127, ':');
        delete [] target.information;
        target.information = new char[strlen(temp) + 1];
        strcpy(target.information, temp);
        in >> target.units;
        
        return in;
    }
     
     */
    
    char MyString::operator[](int index) const
    {
        assert(index >= 0 && index < strlen(information));
        return information[index];
    }
    
    char& MyString::operator[](int index)
    {
        assert(index >= 0 && index < strlen(information));
        return information[index];
    }
    
}
