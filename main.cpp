// Homework 1                                     Chris Canal
//                                                canal.c@husky.neu.edu
//                                                Sarada Symonds
//                                                symonds.s@husky.neu.edu
//
// Main program file for homework 1. Contains declarations for
// randomInit, checkCorect, and checkIncorect.
//

#include "Code.h"
#include <iostream>
#include <vector>


int main {

    return 0;
}

Code::randomInit(int n, int m, vector<int>& codeDigits)
//initializes a random string of digits to be used as the code
{
    for(int i = 0; i <= n; i++)
    //for each digit n, will add a random digit
    {
        //inserts an additional random digit to codeDigits
        codeDigits.push_back(std::rand() % (m-1) + 0);
    }
}

Code::Code(int n, int m){
}
