    #include <iostream>
    #include <cassert>
    #include <cstring>
    #include "mystring.h"
    using namespace std;

    MyString::MyString()
    {
        units = 0;
        information = new char[1];
        strcpy(information, "");
    }

    MyString::MyString(const char *inputString)
    {
        units = 0;
        information = new char[strlen(inputString) + 1];
        strcpy(information, inputString);
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

    void MyString::setInfo(const char *inputString, int inUnits)
    {
        units = inUnits;
        delete [] information;
        information = new char[strlen(inputString) + 1];
        strcpy(information, inputString);
    }

    void MyString::setUnits(int inUnits)
    {
        units = inUnits;
    }

    ostream& operator<<(ostream& out, const MyString& inputString)
    {
        out << inputString.units << " " << inputString.information;
        return out;
    }

    istream& operator>>(istream& in, MyString& target)
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
