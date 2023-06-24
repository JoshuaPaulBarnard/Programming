#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>
using namespace std;

class MyString {
    public:
        MyString();
        MyString(const char *inputString);
        MyString(const MyString& right);
        ~MyString();
        MyString operator=(const MyString& right);
        void setInfo(const char *inputString, int inUnits);
        void setUnits(int inUnits);
        friend std::ostream& operator<<(std::ostream& out, const MyString& inputString);
        friend std::istream& operator>>(std::istream& in, MyString& target);
        char operator[](int index) const;
        char& operator[](int index);

    private:
        char *information;
        int units;
};

#endif
