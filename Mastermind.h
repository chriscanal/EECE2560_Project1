// Mastermind.h
// Problem Set 1b                                 Chris Canal
// Team cansym                                    canal.c@husky.neu.edu
//                                                Sarada Symonds
//                                                symonds.s@husky.neu.edu
//
// Class header file for homework 1b. Contains
// declarations for the Mastermind Class

#ifndef Mastermind_h
#define Mastermind_h

#include <iostream>
#include <vector>

class Mastermind
//code class declaration
{
    public:

        //default constructor
        Mastermind();

        //constructor that for setting n and m in secretCode from keyboard
        Mastermind(int newN, int newM);

        void printSecretCode();

        Code humanGuess();

        Response getResponse(Code & guessCode, Code & secretCode);

        bool isSolved(Response responseObj);

        int playGame();


    private:

        //vector containg code
        Code secretCode;
};

#endif
