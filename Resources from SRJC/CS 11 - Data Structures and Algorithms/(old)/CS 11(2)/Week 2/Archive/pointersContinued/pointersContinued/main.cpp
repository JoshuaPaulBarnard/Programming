//
//  main.cpp
//  pointersContinued
//
//  Created by Ryan  Martino on 8/29/17.
//  Copyright © 2017 Ryan  Martino. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    
    int *intPtr;
    
    intPtr = new int;
    
    int arraySize;
    
    cout << "enter the sixe of the array" << endl;
    
    cin >> arraySize;
    
    string *stringArray;
    
    stringArray = new string[arraySize];
    
    *intPtr = 392;
    
    stringArray[0] = "Nicole";
    
    stringArray[2] = "Ryan";
    
    cout << *intPtr << " " << *stringArray << " " << stringArray[2] << endl;
    
    cout << stringArray << " " << &stringArray[2] << " " << stringArray + 2 << endl;
    
    delete intPtr;
    
    delete [] stringArray;

    
    int* ptr2 = new int;
    
    int* ptr1 = new int;
    
    *ptr2 = 44;
    
    *ptr1 = *ptr2;
    
    ptr1 = ptr2;
    
    
    
    
    return 0;
}
