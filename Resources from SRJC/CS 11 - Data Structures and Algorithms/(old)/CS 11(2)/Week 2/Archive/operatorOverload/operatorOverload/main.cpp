//
//  main.cpp
//  operatorOverload
//
//  Created by Ryan  Martino on 8/31/17.
//  Copyright © 2017 Ryan  Martino. All rights reserved.
//

#include <iostream>
#include "Header.h"

int main() {
   
//    {
//        Fraction f1, f2, f3;
//        
//        cout << "The Anser Is: " << f1 << endl;
//    
//    }
    
    feetInches f1, f2(3), f3(4, 7);
    
    f1 = f2.addedTo(f3);
    
    f2.print();
    
    cout << "Plus ";
    
    f3.print();
    
    cout << "equals ";
    
    f1.print();
    
    
    return 0;
}
