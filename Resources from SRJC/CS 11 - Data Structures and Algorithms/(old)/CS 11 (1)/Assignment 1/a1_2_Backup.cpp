/*
Joshua Paul Barnard
CS 11 - SRJC
Spring 2017
Assignment 1 - 2
*/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

void initializeArrays(string names[], int scores[], int size);
void sortData(string names[], int scores[], int size);
void displayData(const string names[], const int scores[], int size);

int main()
{
  int size;

  cout << "How many scores will you enter?: " << endl;
  cin >> size;

  string *names = new string[size];
  int scores[size];

  initializeArrays(names, scores, size);
  sortData(names, scores, size);
  displayData(names, scores, size);

  return 0;
}

void initializeArrays(string names[], int scores[], int size)
{
  for(int i=0; i < size; i++) {
    cout << "Enter the name for score #" << i+1 << ": " << endl;
    cin >> names[i];
    cout << "Enter the score for score #" << i+1 << ": " << endl;
    cin >> scores[i];
  }

}

void swap(int *s1, int *s2)
{
    int temp;

    temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

int indexOfSmallest(const int list[], int startingIndex, int size)
{
    int targetIndex = startingIndex;

    for (int i = startingIndex + 1; i < size; i++)
    {
        if (list[i] < list[targetIndex])
        {
            targetIndex = i;
        }
    }

    return targetIndex;
}

void sortData(string names[], int scores[], int size)
{
  for (int i = 0; i < size; i++)
  {
      swap(scores[indexOfSmallest(scores, i, size)],
           scores[i]);
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
Not Finished In Time
*/
