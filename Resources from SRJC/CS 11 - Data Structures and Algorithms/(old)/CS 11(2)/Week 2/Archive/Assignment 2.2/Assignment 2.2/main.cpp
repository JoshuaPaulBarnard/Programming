//
//  main.cpp
//  Assignment 2.2
//
//  Created by Ryan  Martino on 9/4/17.
//  Copyright © 2017 Ryan  Martino. All rights reserved.
//

#include <iostream>
using namespace std;
struct Inputs
{
    char ch;
    int integer;
};
void getInputs(Inputs *p);
int main() {
    int size;
//    Inputs var;
    
    Inputs *array;
    array = new Inputs[size];
    
//    array = &var;
   
    getInputs(array);
    for(int i = 0; i < size; i++)
    cout << array[i].ch << endl;
    
    
    return 0;
}
void getInputs(Inputs *p) {
    
    int i = 0;
    char c = p;
//    cout << "enter a sequence of characters(end with '.') " << endl;
//    for(int i = 0; i < size; i++){
    cout << "enter a sequence of characters(end with '.') " << endl;
    cin.ignore();
    cin.get();
    while(p[i].ch != '.' )
    {
        
        p[i].ch = cin.get();
        i++;
    }
//    
//    while(c != '.'){
//        p[i].ch = c;
//    cin.ignore('\n');
//    cin.ignore(' ');
//        c++;
//    cout << c << "here" << endl;
    
       
//
    }


    


