//
//  Gshare.cpp
//  
//
//  Created by Dylan Ferrara on 10/28/15.
//
//

#include "Gshare.hpp"

using namespace std;

Gshare::Gshare(int tableSize, int globalSize) {
    for (int i = 0; i < tableSize; i++) {
        struct states s;
        s.topBit = false;
        s.bottomBit = false;
        ghistory.push_back(s);
    }
    numCorrect = 0;
    globalReg = 0;
    this->globalSize = globalSize;
}

void Gshare::guess(unsigned long long addr, string behavior) {
    unsigned partail = addr % ghistory.size();
    partail = partail ^ (globalReg % (0x1 << globalSize));
    
    if (!ghistory[partail].topBit) { //top bit = 0 indicates guess if T
        if (behavior == "T") {
            numCorrect++;
        }
    } else {
        if (behavior == "NT") {
            numCorrect++;
        }
    }
    
    //Advance state
    if (!ghistory[partail].topBit) { //top bit = 0
        if (!ghistory[partail].bottomBit) { //bottom bit = 0
            if (behavior == "NT") {
                ghistory[partail].bottomBit = 1;
            }
        } else { //bottom bit = 1
            if (behavior == "T") {
                ghistory[partail].bottomBit = 0;
            } else {
                ghistory[partail].topBit = 1;
                ghistory[partail].bottomBit = 0;
            }
        }
    } else { //top bit = 1
        if (ghistory[partail].bottomBit) { //bottom bit = 1
            if (behavior == "T") {
                ghistory[partail].bottomBit = 0;
            }
        } else { //bottom bit = 0
            if (behavior == "NT") {
                ghistory[partail].bottomBit = 1;
            } else {
                ghistory[partail].topBit = 0;
                ghistory[partail].bottomBit = 1;
            }
        }
    }
    
    globalReg = globalReg << 1;
    if(behavior == "T") {
        globalReg |= 0x1;
    } else {
        globalReg |= 0x0;
    }
}

string Gshare::stringGuess(unsigned long long addr, string behavior) {
    unsigned partail = addr % ghistory.size();
    partail = partail ^ (globalReg % (0x1 << globalSize));
    
    string returnVal = "";
    
    if (!ghistory[partail].topBit) { //top bit = 0 indicates guess if T
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
    if (!ghistory[partail].topBit) { //top bit = 0
        if (!ghistory[partail].bottomBit) { //bottom bit = 0
            if (behavior == "NT") {
                ghistory[partail].bottomBit = 1;
            }
        } else { //bottom bit = 1
            if (behavior == "T") {
                ghistory[partail].bottomBit = 0;
            } else {
                ghistory[partail].topBit = 1;
                ghistory[partail].bottomBit = 0;
            }
        }
    } else { //top bit = 1
        if (ghistory[partail].bottomBit) { //bottom bit = 1
            if (behavior == "T") {
                ghistory[partail].bottomBit = 0;
            }
        } else { //bottom bit = 0
            if (behavior == "NT") {
                ghistory[partail].bottomBit = 1;
            } else {
                ghistory[partail].topBit = 0;
                ghistory[partail].bottomBit = 1;
            }
        }
    }
    
    globalReg = globalReg << 1;
    if(behavior == "T") {
        globalReg |= 0x1;
    } else {
        globalReg |= 0x0;
    }
    return returnVal;
}