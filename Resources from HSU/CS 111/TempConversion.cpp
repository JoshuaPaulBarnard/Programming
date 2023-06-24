//-------------------------------------------------------------------------------------------
//Joshua P. Barnard
//CS 111 Homework 9/23/13
//Temperature Conversion
//This program was designed to convert Fahrenheit to Celsius, and Celsius to Fahrenheit.
//--------------------------------------------------------------------------------------------

#include <iostream>
using namespace std;

char type;
float temp,newtemp;

int main(){

cout<<"Enter Temperature type: F is Fahrenheit, C is Celsius:  ";
cin>>type;

cout<<"Enter Temperature:  ";
cin>>temp;

if(type == 'f'||type =='F'){
	newtemp = (temp-32.0)*(5.0/9.0);
	cout<<"New Temperature in Celsius is:  "<<newtemp;
}

if(type=='c'||type=='C'){
	newtemp = (temp*(9.0/5.0))+32.0;
	cout<<"New Temperature in Fahrenheit:  "<<newtemp;
}


}
