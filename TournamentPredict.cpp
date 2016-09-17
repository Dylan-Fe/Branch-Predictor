//
//  TournamentPredict.cpp
//  
//
//  Created by Dylan Ferrara on 10/28/15.
//
//

#include "TournamentPredict.hpp"

using namespace std;

TournamentPredict::TournamentPredict() {
    gShare = new Gshare(2048, 11);
    bimodalDoubleBit = new BimodalDoubleBit(2048);
    
    for (int i = 0; i < 2048; i++) {
        struct select t;
        t.topBit = false;
        t.bottomBit = false;
        selector.push_back(t);
    }
    numCorrect = 0;
}


void TournamentPredict::guess(unsigned long long addr, string behavior) {
    string gshareGuess = gShare->stringGuess(addr, behavior);
    string bimodalGuess = bimodalDoubleBit->stringGuess(addr, behavior);
    
    unsigned partial = addr % selector.size();
    
    if (!selector[partial].topBit) {
        if (gshareGuess == behavior) {
            numCorrect++;
        }
    } else {
        if (bimodalGuess == behavior) {
            numCorrect++;
        }
    }
    
    //Advance State
    if (!selector[partial].topBit) { //top bit = 0
        if (!selector[partial].bottomBit) { //bottom bit = 0
            if (gshareGuess != behavior && bimodalGuess == behavior) {
                selector[partial].bottomBit = 1;
            }
        } else { //bottom bit = 1
            if (gshareGuess == behavior && bimodalGuess != behavior) {
                selector[partial].bottomBit = 0;
            } else if (gshareGuess != behavior && bimodalGuess == behavior) {
                selector[partial].topBit = 1;
                selector[partial].bottomBit = 0;
            }
        }
    } else { //top bit = 1
        if (selector[partial].bottomBit) { //bottom bit = 1
            if (bimodalGuess != behavior && gshareGuess == behavior) {
                selector[partial].bottomBit = 0;
            }
        } else { //bottom bit = 0
            if (bimodalGuess == behavior && gshareGuess != behavior) {
                selector[partial].bottomBit = 1;
            } else if (bimodalGuess != behavior && gshareGuess == behavior) {
                selector[partial].topBit = 0;
                selector[partial].bottomBit = 1;
            }
        }
    }
}

TournamentPredict::~TournamentPredict() {
    delete gShare;
    delete bimodalDoubleBit;
}