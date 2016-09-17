//
//  TournamentPredict.hpp
//  
//
//  Created by Dylan Ferrara on 10/28/15.
//
//

#ifndef TournamentPredict_hpp
#define TournamentPredict_hpp

#include <vector>
#include <string>

#include "Gshare.hpp"
#include "BimodalDoubleBit.hpp"

struct select {
    bool topBit;
    bool bottomBit;
};

//if top bit is 0 then:
// if bottom bit is 0 --> Prefer Gshare
// if bottom bit is 1 --> Weakly Prefer Gshare
//if top bit is 1 then:
// if bottom bit is 0 --> Weakly Prefer Bimodal
// if bottom bit is 1 --> Prefer Bimodal

class TournamentPredict {
public:
    TournamentPredict();
    void guess(unsigned long long addr, std::string behavior);
    ~TournamentPredict();
    int numCorrect;
private:
    std::vector<struct select> selector;
    
    Gshare* gShare;
    BimodalDoubleBit* bimodalDoubleBit;
};

#endif /* TournamentPredict_hpp */
