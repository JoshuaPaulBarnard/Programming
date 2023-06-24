/*
Joshua Barnard
CS 11 - Spring 2018
Assignment 12_2
main.cpp

*/


#include "MyString.h"
#include <fstream>
#include <cctype>      // for toupper()
#include <cstring>
#include <cassert>
#include <iostream>

using namespace cs_mystring;
using namespace std;
bool isPalindrome(MyString string, int lowerBound, int upperBound);
int main() {
    
    
   
    MyString string;
    
    while(string != "quit"){
        cout << "Enter A String: " << endl;
        cin >> string;
    if(isPalindrome(string, 0, string.length() -1)) {
        cout << string << " Is A Palindrome" << endl;
    } else {
        cout << string <<  " Is Not A Palindrome" << endl;
    }
        
    }
 return 0;
}


bool isPalindrome(MyString string, int lowerBound, int upperBound)
{
   
    while(ispunct(string[lowerBound]) || isspace(string[lowerBound])) {
        lowerBound + 1;
    }
    
    
    while(ispunct(string[upperBound]) || isspace(string[upperBound])){
        upperBound - 1;
    }
    if(lowerBound > upperBound) {
       return true;
    } else if((toupper(string[lowerBound]) == toupper(string[upperBound]))) {
        
        return isPalindrome(string, lowerBound + 1, upperBound - 1);
    } else
        return false ;
    }

