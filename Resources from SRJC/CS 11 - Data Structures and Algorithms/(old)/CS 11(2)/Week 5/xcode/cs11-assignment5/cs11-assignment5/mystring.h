//
//  Header.h
//  cs11-assignment5
//
//  Created by Joshua Barnard on 9/28/17.
//  Copyright © 2017 Joshua Barnard. All rights reserved.
//

#ifndef Header_h
#define Header_h
#include <iostream>
namespace cs_mystring {
    
    class MyString {
        
    public:
        MyString();
        MyString(const char *inString);
        MyString(const MyString& right);
        ~MyString();
        MyString operator=(const MyString& right);
        int length(const MyString& inString);
        friend std::ostream& operator<<(std::ostream& out, const MyString& inString);
        friend std::istream& operator>>(std::istream& in, MyString& target);
        char operator[](int index) const;
        char& operator[](int index);
        
    private:
        char *string;
        char *information;
        int units;
    };
    
}






#endif /* Header_h */
