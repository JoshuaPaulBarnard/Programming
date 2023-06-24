//
//  Header.h
//  operatorOverload
//
//  Created by Ryan  Martino on 8/31/17.
//  Copyright © 2017 Ryan  Martino. All rights reserved.
//

#ifndef Header_h
#define Header_h
using namespace std;

class feetInches {
    
public:
    feetInches(int inFeet = 0, int inINches = 0);
    feetInches addedTo(const feetInches &other) const;
    void print() const;
    
private:
    int feet;
    
    int inches;
    
};
feetInches::feetInches(int inFeet, int inInches)
{
    feet = inFeet;
    
    inches = inInches;
}


feetInches feetInches::addedTo(const feetInches &other) const
{
    feetInches = temp;
    
    temp.feet
    
}




#endif /* Header_h */
