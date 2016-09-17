//
//  BimodalSingleBit.cpp
//  
//
//  Created by Dylan Ferrara on 10/27/15.
//
//

#include "BimodalSingleBit.hpp"

using namespace std;

BimodalSingleBit::BimodalSingleBit(int tableSize) {
    for(int i = 0; i < tableSize; i++) {
        history.push_back(true);
    }
    numCorrect = 0;
}

void BimodalSingleBit::guess(unsigned long long addr, string behavior) {
    unsigned partial = addr % history.size();
    
    if (history[partial]) {
        if (behavior == "T") {
            numCorrect++;
        }
    } else {
        if (behavior == "NT") {
            numCorrect++;
        }
    }
    
    if (behavior == "T") {
        history[partial] = true;
    } else {
        history[partial] = false;
    }
    
}