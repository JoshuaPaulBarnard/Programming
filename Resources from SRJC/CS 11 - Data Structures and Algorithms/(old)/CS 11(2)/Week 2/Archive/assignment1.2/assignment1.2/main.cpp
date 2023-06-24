//
//  main.cpp
//  Created by Ryan  Martino on 8/22/17.
//  t-th 10:30
//  Dave Harden
//  assignment1.2
//
//  This program uses a pointer to a int (scores) and a pointer to a string (names) to dynamically allocate arrays. The user is prompted for a number of scores that will be entered. The scores and the respective users name are then stored in dynamically allocated arrays. Then the scores array is passed into the indexOfLargest fucntion to find the targeted index number and returns it. Which is used in sortData function to swap the largestIndex with the current i in the scores array and respectively the names to follow to sort the scores in decneding order. Then a display function is called to show the names of the top scorers and their score.

#include <iostream>

using namespace std;

void initializeArrays(string names[], int scores[], int size);

void sortData(string names[], int scores[], int size);

int indexOfLargest(int scores[], int startingIndex, int size);

void displayData(const string names[], const int scores[], int size);

int main() {
    
    int size;
    
    int *scores;
    
    string *names;

    cout << "How many scores will you enter?" << endl;
    
    cin >> size;
    
    scores = new int[size];
    
    names = new string[size];
    
    initializeArrays(names, scores, size);
    
    sortData(names, scores, size);
    
    displayData(names, scores, size);
    
    delete [] scores;
    
    delete [] names;
    
    return 0;
    
}

//  This function accepts the arrays names[] and scores[] along with the int variable size that is set by the user. Then it loops thru all the spaces allocated for the arrays and asks the user for the name, and score ans sets the values.

void initializeArrays(string names[], int scores[], int size) {
    
    for(int i = 0; i < size; i++) {
        
        cout << "Enter  the name for score # " << i + 1 << ": ";
        
        cin >> names[i];
        
        cout << "Enter  the score for score # " << i + 1 << ": ";
        
        cin >> scores[i];
        
    }
    
}

//  This function accepts the arrays names[] and scores[] and the int variable size then loops thru the index positions. First in the loop it sets the largestIndex to equal the targetIndex returned from the IndexOfLarget function and swaps the scores and names [largestIndex] with current index [i].

void sortData(string names[], int scores[], int size) {
    
    for(int i = 0; i < size - 1; i++) {
        
        int largestIndex = indexOfLargest(scores, i, size);
        
        swap(scores[largestIndex],
             scores[i]);
        
        swap(names[largestIndex], names[i] );
    }
    
}

//  This function accepts the scores array the starting index i and the size. Then it sets the startingIndex to the targetIndex. Then in the for loop the i is set to one position after the staring index. then as long as i less than the size it will compaire if the value in scores[i] is larger than scores[targetIndex] if thats true then targetIndex becomes i and targetIndex Gets returned till completion.

int indexOfLargest(int scores[], int startingIndex, int size) {

        int targetIndex = startingIndex;
        
        for (int i = startingIndex + 1; i < size; i++){
            if (scores[i] > scores[targetIndex]){
                targetIndex = i;
            }
        }
        
        return targetIndex;
}

//  this function accepts the names[] and the scores[] along with their respective size then displays the top Scores and their names.

void displayData(const string names[], const int scores[], int size) {
    
    cout << "Top scores: " << endl;
    
    for(int i = 0; i < size; i++) {
        
        
        cout  << names[i] << " " << scores[i] << endl;
    }
    
    
}
//  How many scores will you enter?
//4
//Enter  the name for score # 1: Ryan
//Enter  the score for score # 1: 34
//Enter  the name for score # 2: nicky
//Enter  the score for score # 2: 12
//Enter  the name for score # 3: Daniel
//Enter  the score for score # 3: 58
//Enter  the name for score # 4: john
//Enter  the score for score # 4: 120
//Top scores:
//john 120
//Daniel 58
//Ryan 34
//nicky 12
//Program ended with exit code: 0
