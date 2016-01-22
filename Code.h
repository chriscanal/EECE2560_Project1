// Code.h
// Problem Set 1A                                 Chris Canal
// Team cansym                                    canal.c@husky.neu.edu
//                                                Sarada Symonds
//                                                symonds.s@husky.neu.edu
//
// Class header file for homework 1. Contains
// declarations for the Code Class

#ifndef Code_Code_h
#define Code_Code_h

#include <iostream>
#include <vector>

class Code
//code class declaration
{
    public:

        //default constructor
        Code();

        //constructor
        Code(int newN, int newM);

        //n and m setter
        void set(int newN, int newM);

        //sets the code digits from a string
        void setCodeDigits(const std::string &guess);

        //accessor, does not change data
        std::vector<int> getCode() const;

        //initialize random variables
        void randomInit();

        //Checks how many integers are in the correct location
        int checkCorrect( Code& guessDigits) const;

        //Checks how many integers are in the incorrect location
        int checkIncorrect( Code& guessDigits) const;

        //Runs checkIncorrect and checkCorrect and prints result
        void checkGuess( Code& guessCode) const;



    private:

        //number of digits in the code
        int n;

        //range of digits in code
        int m;

        //vector containg code
        std::vector<int> codeDigits;
};

#endif
