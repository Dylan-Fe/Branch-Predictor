//
//  BimodalSingleBit.hpp
//  
//
//  Created by Dylan Ferrara on 10/27/15.
//
//

#ifndef BimodalSingleBit_hpp
#define BimodalSingleBit_hpp

#include <vector>
#include <string>

class BimodalSingleBit {
public:
    BimodalSingleBit(int tableSize);
    void guess(unsigned long long addr, std::string behavior);
    int numCorrect;
private:
    std::vector<bool> history;
    
};

#endif /* BimodalSingleBit_hpp */
