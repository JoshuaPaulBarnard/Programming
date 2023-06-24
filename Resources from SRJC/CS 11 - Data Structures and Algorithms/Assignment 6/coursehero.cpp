*/
CS 11 Data Structures and Algorithms Assignment 6: Classes/Pointers I Return to Course Homepage Assignment 6.1 /* Name: Sam Student Date: Sept. 29, 2015 Assignment Number: 6 Instructor: Dave Harden File: mystring.h The myString class is designed to make working with strings easier and less error‐prone than working with traditional null‐terminated C‐strings. The client can declare and use myStrings freely without concern for memory management issues or the size of the myString. Operations for input/output, construction, indexing, comparison, and concatenation of myStrings are provided. Assignment and copying of myString objects is allowed. myString(const char* inString); post: a myString object is created and initialized to "inString". myString(); post: a myString object is created and initialized to the empty string. myString(const myString& copyMe); post: a myString object is created and initialized to "copyMe". friend ostream& operator<<(ostream& out, const myString& printMe); pre: "out" is ready for writing. post: The contents of "printMe" have been inserted into "out". char operator (int index) const; pre: 0 <= index < length() post: The character at position "index" (counting from 0) has been returned. char& operator(int index); pre: 0 <= index < length() post: The character at position "index" (counting from 0) has been returned. friend bool operator<(const myString& left, const myString& right); post: true is returned if left < right; false otherwise. friend bool operator>(const myString& left, const myString& right); post: true is returned if left > right; false otherwise. friend bool operator<=(const myString& left, const myString& right); post: true is returned if left <= right; false otherwise. friend bool operator>=(const myString& left, const myString& right); post: true is returned if left >= right; false otherwise. friend bool operator==(const myString& left, const myString& right); post: true is returned if left == right; false otherwise. friend bool operator!=(const myString& left, const myString& right); post: true is returned if left != right; false otherwise. myString operator=(const myString& right); post: A copy of "right" is stored in the calling object. int length() const; post: the number of characters in the calling object is returned. */ #ifndef MYSTRING_H #define MYSTRING_H #include <iostream> #include <iostream> namespace compsci_mystring{ class myString { public: myString(const char* inString); myString(); myString(const myString& copyMe); ~myString(); friend std::ostream& operator<<(std::ostream& out, const myString& printMe); char operator (int index) const; char& operator(int index); friend bool operator<(const myString& left, const myString& right); friend bool operator>(const myString& left, const myString& right); friend bool operator<=(const myString& left, const myString& right); friend bool operator>=(const myString& left, const myString& right); friend bool operator==(const myString& left, const myString& right); friend bool operator!=(const myString& left, const myString& right); myString operator=(const myString& right); int length() const; private: char *str; }; } #endif /* Name: Sam Student Date: Sept. 29, 2015 Assignment Number: 6 Instructor: Dave Harden File: mystring.cpp CLASS INVARIANT: The class has one private data member defined as follows: char *str; str always represents a valid null‐terminated c‐string */ #include "mystring.h" #include <iostream> #include <cstring> #include <cassert> using namespace std; namespace compsci_mystring{ myString::myString(const char* inString) { str = new char[strlen(inString) + 1]; strcpy(str, inString); } myString::myString() { str = new char[1]; strcpy(str, ""); } myString::myString(const myString& copyMe) { str = new char[strlen(copyMe.str) + 1]; strcpy(str, copyMe.str); } } myString::~myString() { delete str; } ostream& operator<<(ostream& out, const myString& printMe) { out << printMe.str; return out; } char myString::operator(int index) const { assert (index >= 0 && index < strlen(str)); return str[index]; } char& myString::operator(int index) { assert (index >= 0 && index < strlen(str)); return str[index]; } bool operator<(const myString& left, const myString& right) { return strcmp(left.str, right.str) < 0; } bool operator>(const myString& left, const myString& right) { return strcmp(left.str, right.str) > 0; } bool operator<=(const myString& left, const myString& right) { return strcmp(left.str, right.str) <= 0; } bool operator>=(const myString& left, const myString& right) { { return strcmp(left.str, right.str) >= 0; } bool operator==(const myString& left, const myString& right) { return strcmp(left.str, right.str) == 0; } bool operator!=(const myString& left, const myString& right) { return strcmp(left.str, right.str) != 0; } myString myString::operator=(const myString& right) { if (this != &right){ delete str; str = new char[strlen(right.str) + 1]; strcpy(str, right.str); } return *this; } int myString::length() const { return strlen(str); } }
