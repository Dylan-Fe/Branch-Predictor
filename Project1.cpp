//
//  CS320 Project1.cpp
//  
//
//  Created by Dylan Ferrara on 10/24/15.
//
//
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "BimodalSingleBit.hpp"
#include "BimodalDoubleBit.hpp"
#include "Gshare.hpp"
#include "TournamentPredict.hpp"

using namespace std;

int alwaysT = 0;
int alwaysNT = 0;
int totalCalls = 0;

void always_Taken(unsigned long long addr, string behavior) {
    if (behavior == "T") {
        alwaysT++;
    }
}

void always_NotTaken(unsigned long long addr, string behavior) {
    if (behavior == "NT") {
        alwaysNT++;
    }
}

int main(int arg, char *args[]) {
    unsigned long long addr;
    string behavior;
    
    if (arg != 3) {
        cerr << "ERROR: Needs Input and Output files" << endl;
    }
    
    ifstream infile(args[1]);
    ofstream outfile(args[2]);
    
    BimodalSingleBit t1(16);
    BimodalSingleBit t2(32);
    BimodalSingleBit t3(128);
    BimodalSingleBit t4(256);
    BimodalSingleBit t5(512);
    BimodalSingleBit t6(1024);
    BimodalSingleBit t7(2048);
    
    BimodalDoubleBit v1(16);
    BimodalDoubleBit v2(32);
    BimodalDoubleBit v3(128);
    BimodalDoubleBit v4(256);
    BimodalDoubleBit v5(512);
    BimodalDoubleBit v6(1024);
    BimodalDoubleBit v7(2048);
    
    Gshare g1(2048, 3);
    Gshare g2(2048, 4);
    Gshare g3(2048, 5);
    Gshare g4(2048, 6);
    Gshare g5(2048, 7);
    Gshare g6(2048, 8);
    Gshare g7(2048, 9);
    Gshare g8(2048, 10);
    Gshare g9(2048, 11);
    
    TournamentPredict tp1;
    
    while (infile >> hex >> addr) {
        infile >> behavior;
        
        always_Taken(addr, behavior);
        always_NotTaken(addr, behavior);
        
        t1.guess(addr, behavior);
        t2.guess(addr, behavior);
        t3.guess(addr, behavior);
        t4.guess(addr, behavior);
        t5.guess(addr, behavior);
        t6.guess(addr, behavior);
        t7.guess(addr, behavior);
        
        v1.guess(addr, behavior);
        v2.guess(addr, behavior);
        v3.guess(addr, behavior);
        v4.guess(addr, behavior);
        v5.guess(addr, behavior);
        v6.guess(addr, behavior);
        v7.guess(addr, behavior);
        
        g1.guess(addr, behavior);
        g2.guess(addr, behavior);
        g3.guess(addr, behavior);
        g4.guess(addr, behavior);
        g5.guess(addr, behavior);
        g6.guess(addr, behavior);
        g7.guess(addr, behavior);
        g8.guess(addr, behavior);
        g9.guess(addr, behavior);
        
        tp1.guess(addr, behavior);
        
        totalCalls++;
    }
    
    //Static outputs
    outfile << alwaysT << "," << totalCalls << ";\n";
    outfile << alwaysNT << "," << totalCalls << ";\n";
    
    //Bimodal 1bit outputs
    outfile << t1.numCorrect << "," << totalCalls << "; " << t2.numCorrect << "," << totalCalls << "; " << t3.numCorrect << "," << totalCalls << "; " << t4.numCorrect << "," << totalCalls << "; " << t5.numCorrect << "," << totalCalls << "; " << t6.numCorrect << "," << totalCalls << "; " << t7.numCorrect << "," << totalCalls << ";\n";
    
    //Bimodal 2bit ouputs
    outfile << v1.numCorrect << "," << totalCalls << "; " << v2.numCorrect << "," << totalCalls << "; " << v3.numCorrect << "," << totalCalls << "; " << v4.numCorrect << "," << totalCalls << "; " << v5.numCorrect << "," << totalCalls << "; " << v6.numCorrect << "," << totalCalls << "; " << v7.numCorrect << "," << totalCalls << ";\n";
    
    //Global History outputs
    outfile << g1.numCorrect << "," << totalCalls << "; " << g2.numCorrect << "," << totalCalls << "; " << g3.numCorrect << "," << totalCalls << "; " << g4.numCorrect << "," << totalCalls << "; " << g5.numCorrect << "," << totalCalls << "; " << g6.numCorrect << "," << totalCalls << "; " << g7.numCorrect << "," << totalCalls << "; " << g8.numCorrect << "," << totalCalls << "; " << g9.numCorrect << "," << totalCalls << ";\n";
    
    //Tournament output
    outfile << tp1.numCorrect << "," << totalCalls << ";\n";
    
    infile.close();
    outfile.close();
    
    return 0;
}