//
//  main.cpp
//  assignment2
//
//  Created by Ryan  Martino on 8/29/17.
//  Copyright © 2017 Ryan  Martino. All rights reserved.
//

#include <iostream>

using namespace std;

int lastIndexOf(const char* inString, char target);
void reverse(char* inString);
int replace(char* inString, char target, char replacementChar);
bool isPalindrome(const char* inString);
void toupper(char* inString);
int numLetters(const char* inString);

int main()
{
    const int size = 40;
    char inString[size];
    char target;
    char replacementChar;
    cout << "Enter a c String" << endl;
    cin.getline(inString, size);
//    cout << "enter the target character" << endl;
//    cin.get(target);
//    lastIndexOf(inString, target);
//    cout << "the index of the last char matching the one you entered is: " << lastIndexOf(inString, target) << endl;
//    reverse(inString);
//    cout << inString << endl;
//    cout << "search the string for a target character and replace it with a replacement char" << endl;
//    cout << "Enter a target character" << endl;
//    cin >> target;
//    cout << "Enter a replacement character for : " << target << endl;
//    cin >> replacementChar;
//    replace(inString, target, replacementChar);
//    cout << inString << "test" << endl;
//    cout << replace(inString, target, replacementChar) << endl;
//   
//    cout << target << " apears " << replace(inString, target, replacementChar) << " times and InString is now " << inString <<  endl;
//    cout << isPalindrome(inString) << endl;
//    cout << inString << endl;
//    cout << inString << endl;
//    toupper(inString);
//    cout << inString << endl;
    numLetters(inString);
    cout << "there are " << numLetters(inString) << " letters in the cstring" << endl;
    return 0;
}
int numLetters(const char* inString){
    int numOfLetters = 0;
    int i = 0;
    while(inString[i] != '\0'){
        numOfLetters++;
        i++;
    }
     
    return numOfLetters;
}
void toupper(char* inString){
    
 
    int i =0;
    while(inString[i] != '\0')
    {
        inString[i] = toupper(inString[i]);
        i++;
    }

}

bool isPalindrome(const char* inString){
    
    int i = 0;
    int lastIndex = strlen(inString)-1;
    while(i < lastIndex){
        if(toupper(inString[i]) != toupper(inString[lastIndex])){
            return false;
        } else {
            i++;
            lastIndex--;
        }
    }
    return true;
}

int replace(char* inString, char target, char replacementChar){

    int timesReplaced = 0;
    int i =0;
    while(inString[i] != '\0')
    {
        if(inString[i] == target){
            timesReplaced++;
            inString[i] = replacementChar;
        }
        i++;
    }
    return  timesReplaced;
}

void reverse(char* inString) {
    char temp;
    int length = strlen(inString);
    for(int i = 0; i < length/2; i++ ) {
        temp = inString[i];
        inString[i] = inString[strlen(inString)-i -1];
        inString[strlen(inString)-i -1] = temp;
    }
}
int lastIndexOf(const char* inString, char target)
{
    int lastIndex = strlen(inString) -1;
        for(int i = lastIndex; i >=0; i--) {
            if(inString[i] == target) {
                return i;
            }
        }
    return -1;
}
