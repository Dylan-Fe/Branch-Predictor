//
//  BimodalDoubleBit.hpp
//  
//
//  Created by Dylan Ferrara on 10/28/15.
//
//

#ifndef BimodalDoubleBit_hpp
#define BimodalDoubleBit_hpp

#include <vector>
#include <string>

struct state {
    bool topBit;
    bool bottomBit;
};

//if top bit is 0 then:
// if bottom bit is 0 --> Strong Taken
// if bottom bit is 1 --> Weak Taken
//if top bit is 1 then:
// if bottom bit is 0 --> Weak Not Taken
// if bottom bit is 1 --> Strong Not Taken

class BimodalDoubleBit {
public:
    BimodalDoubleBit(int tableSize);
    void guess(unsigned long long addr, std::string behavior);
    std::string stringGuess(unsigned long long addr, std::string behavior);
    int numCorrect;
private:
    std::vector<state> history;
    
};
#endif /* BimodalDoubleBit_hpp */
