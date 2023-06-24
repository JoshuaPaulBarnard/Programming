/*
Joshua Paul Barnard
CS 11 - SRJC
Spring 2017
Assignment 1 - 2
a1_2.cpp

This program receives an integer indicatingnumber of players in a game.
The program then call the initializeArrays function which creates 2 arrays
  whose size is based on the number of players.
The user then inputs the name and value of a game score for each player.
The program will then call the sortData function to sort the data in descending order.
The program will then call the displayData function to output the data, showing
  the top scores first with the lowerest score last.
*/

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

void initializeArrays(string names[], int scores[], int size);
int indexOfLargest(const int list[], int startingIndex, int size);
void sortData(string names[], int scores[], int size);
void displayData(const string names[], const int scores[], int size);

int main()
{
  int size;

  cout << "How many scores will you enter?: \t";
  cin >> size;

  string *names = new string[size];
  int *scores = new int[size];

  initializeArrays(names, scores, size);
  sortData(names, scores, size);
  displayData(names, scores, size);

  return 0;
}


void initializeArrays(string names[], int scores[], int size)
{
  for(int i=0; i < size; i++) {
    cout << "Enter the name for score #" << i+1 << ": \t";
    cin >> names[i];
    cout << "Enter the score for score #" << i+1 << ": \t";
    cin >> scores[i];
  }

}


int indexOfLargest(const int list[], int startingIndex, int size)
{
    int targetIndex = startingIndex;

    for (int i = startingIndex; i < size; i++)
    {
        if (list[i] > list[targetIndex])
        {
            targetIndex = i;
        }
    }

    return targetIndex;
}
//  This code is from 9.6, as the assignment said we could use code from this lesson.





void sortData(string names[], int scores[], int size)
{
  for (int i = 0; i < size; i++)
  {
      swap( names[ indexOfLargest(scores, i, size) ], names[ i ] );

      swap( scores[ indexOfLargest(scores, i, size) ], scores[ i ] );
  }
}






void displayData(const string names[], const int scores[], int size)
{
  cout << "Top Scores:" << endl;
  for(int i=0; i < size; i++)
  {
    cout << names[i] << ": " << scores[i] << endl;
  }
}






/*
How many scores will you enter?: 	4
Enter the name for score #1: 	Suzy
Enter the score for score #1: 	600
Enter the name for score #2: 	Jeff
Enter the score for score #2: 	9900
Enter the name for score #3: 	Armando
Enter the score for score #3: 	8000
Enter the name for score #4: 	Tim
Enter the score for score #4: 	514
Top Scores:
Jeff: 9900
Armando: 8000
Suzy: 600
Tim: 514
*/
