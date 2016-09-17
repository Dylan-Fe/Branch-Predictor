//
//  BimodalDoubleBit.cpp
//  
//
//  Created by Dylan Ferrara on 10/28/15.
//
//

#include "BimodalDoubleBit.hpp"

using namespace std;

BimodalDoubleBit::BimodalDoubleBit(int tableSize) {
    for(int i = 0; i < tableSize; i++) {
        struct state s;
        s.topBit = false;
        s.bottomBit = false;
        history.push_back(s);
    }
    numCorrect = 0;
}

void BimodalDoubleBit::guess(unsigned long long addr, string behavior) {
    unsigned partail = addr % history.size();
    
    if (!history[partail].topBit) { //top bit = 0 indicates guess of T
        if (behavior == "T") {
            numCorrect++;
        }
    } else {
        if (behavior == "NT") {
            numCorrect++;
        }
    }
    
    //Advance state
    if (!history[partail].topBit) { //top bit = 0
        if (!history[partail].bottomBit) { //bottom bit = 0
            if (behavior == "NT") {
                history[partail].bottomBit = 1;
            }
        } else { //bottom bit = 1
            if (behavior == "T") {
                history[partail].bottomBit = 0;
            } else {
                history[partail].topBit = 1;
                history[partail].bottomBit = 0;
            }
        }
    } else { //top bit = 1
        if (history[partail].bottomBit) { //bottom bit = 1
            if (behavior == "T") {
                history[partail].bottomBit = 0;
            }
        } else { //bottom bit = 0
            if (behavior == "NT") {
                history[partail].bottomBit = 1;
            } else {
                history[partail].topBit = 0;
                history[partail].bottomBit = 1;
            }
        }
    }
}

string BimodalDoubleBit::stringGuess(unsigned long long addr, string behavior) {
    unsigned partail = addr % history.size();
    
    string returnVal = "";
    
    if (!history[partail].topBit) { //top bit = 0 indicates guess if T
        returnVal = "T";
        if (behavior == "T") {
            numCorrect++;
        }
    } else {
        returnVal = "NT";
        if (behavior == "NT") {
            numCorrect++;
        }
    }
    
    //Advance state
    if (!history[partail].topBit) { //top bit = 0
        if (!history[partail].bottomBit) { //bottom bit = 0
            if (behavior == "NT") {
                history[partail].bottomBit = 1;
            }
        } else { //bottom bit = 1
            if (behavior == "T") {
                history[partail].bottomBit = 0;
            } else {
                history[partail].topBit = 1;
                history[partail].bottomBit = 0;
            }
        }
    } else { //top bit = 1
        if (history[partail].bottomBit) { //bottom bit = 1
            if (behavior == "T") {
                history[partail].bottomBit = 0;
            }
        } else { //bottom bit = 0
            if (behavior == "NT") {
                history[partail].bottomBit = 1;
            } else {
                history[partail].topBit = 0;
                history[partail].bottomBit = 1;
            }
        }
    }
    return returnVal;
}