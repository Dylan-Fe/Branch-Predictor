//
//  Gshare.hpp
//  
//
//  Created by Dylan Ferrara on 10/28/15.
//
//

#ifndef Gshare_hpp
#define Gshare_hpp

#include <vector>
#include <string>

struct states {
    bool topBit;
    bool bottomBit;
};

//if top bit is 0 then:
// if bottom bit is 0 --> Strong Taken
// if bottom bit is 1 --> Weak Taken
//if top bit is 1 then:
// if bottom bit is 0 --> Weak Not Taken
// if bottom bit is 1 --> Strong Not Taken

class Gshare {
public:
    Gshare(int tableSize, int globalSize);
    void guess(unsigned long long addr, std::string behavior);
    std::string stringGuess(unsigned long long addr, std::string behavior);
    int numCorrect;
private:
    std::vector<states> ghistory;
    unsigned int globalReg;
    int globalSize;
    
};

#endif /* Gshare_hpp */
