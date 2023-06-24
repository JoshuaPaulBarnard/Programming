//
//  main.cpp
//  asssignment 2.3
//
//  Created by Ryan  Martino on 9/6/17.
//  Copyright © 2017 Ryan  Martino. All rights reserved.
//

#include <iostream>

struct highscore {
    int score;
    char *name = new char[24];
    
};
    
    using namespace std;
    void initializeData(highscore scores[], int size);
   int indexOfLargest(highscore scores[], int startingIndex, int size);
    void sortData(highscore scores[], int size);
    void displayData(const highscore scores[], int size);
    
    int main() {
        highscore score;
        int size;
        highscore *scores;
        scores = &score;
        cout << "How many scores will you enter?" << endl;
        cin >> size;
        scores = new highscore[size];
        initializeData(scores, size);
        sortData(scores, size);
        displayData(scores, size);
        delete [] scores;
        return 0;
        
    }
    
    //  This function accepts the arrays names[] and scores[] along with the int variable size that is set by the user. Then it loops thru all the spaces allocated for the arrays and asks the user for the name, and score ans sets the values.
    
    void initializeData(highscore scores[], int size) {
        
        for(int i = 0; i < size; i++) {
            
            cout << "Enter  the name for score # " << i + 1 << ": ";
            
            cin >> scores[i].name;
            
            cout << "Enter  the score for score # " << i + 1 << ": ";
            
            cin >> scores[i].score;
            
        }
        
    }
    
    //  This function accepts the arrays names[] and scores[] and the int variable size then loops thru the index positions. First in the loop it sets the largestIndex to equal the targetIndex returned from the IndexOfLarget function and swaps the scores and names [largestIndex] with current index [i].
    
    void sortData(highscore scores[], int size) {
        
        for(int i = 0; i < size - 1; i++) {
            
            int largestIndex = indexOfLargest(scores, i, size);
            
            swap(scores[largestIndex],
                 scores[i]);
            
           
        }
        
    }
    
    //  This function accepts the scores array the starting index i and the size. Then it sets the startingIndex to the targetIndex. Then in the for loop the i is set to one position after the staring index. then as long as i less than the size it will compaire if the value in scores[i] is larger than scores[targetIndex] if thats true then targetIndex becomes i and targetIndex Gets returned till completion.
    
    int indexOfLargest(highscore scores[], int startingIndex, int size) {
        
        int targetIndex = startingIndex;
        
        for (int i = startingIndex + 1; i < size; i++){
            if (scores[i].score > scores[targetIndex].score){
                targetIndex = i;
            }
        }
        
        return targetIndex;
    }
    
    //  this function accepts the hiughscore scores[] along with its respective size then displays the top scores and their names
    void displayData(const highscore scores[], int size) {
        cout << "Top scores: " << endl;
        for(int i = 0; i < size; i++) {
            cout  << scores[i].score << " " << scores[i].name << endl;
        }
        
        
    }

    
