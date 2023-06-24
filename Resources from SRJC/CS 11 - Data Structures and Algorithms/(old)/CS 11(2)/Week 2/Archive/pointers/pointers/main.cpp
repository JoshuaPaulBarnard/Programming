//
//  main.cpp
//  pointers
//
//  Created by Ryan  Martino on 8/22/17.
//  Copyright © 2017 Ryan  Martino. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    
    int* intptr;
    int* intptr1;
    
    int i;
    intptr = &i;
    
    *intptr = 47;
    
    cout << intptr << " " << i << " " << *intptr << endl;
    //make thing on left point to thing on right
    intptr1 = intptr;
    
    cout << intptr1 << " " << i << " " << *intptr1 << endl;
    
    string* strptr1;
    string str1("hello");
    strptr1 = &str1;
    
//    -> dereference and select
    
    cout << strptr1 -> substr(2, 3) << endl;
 
    
    string* strptr2;
    string* strptr3;
    
    string str2("there");
    string str3("penelope");
    
    strptr2 = &str2;
    strptr3 = &str3;
    
    string* array[10] = {strptr1, strptr2, strptr3};
    
    *array[0] = *array[1] + *array [2];
    
    cout << *array[0] << " " <<  *array[1] << " " << *array[2] << endl;
    
    array[0] = nullptr;
    
    int array2[10];
    int* ptr;
//    same as ptr = &array2[0]
    ptr = array2;
    
    init(ptr);
    for (int i = 0; i < 10; i++) {
        count << ptr[i] << " ";
    }
                     
                     cout << endl;
    
    
}

void init(int* x) {
    for (int i = 0; i <10; i++) {
        x[i] = i;
    }
    
}
