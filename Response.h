// Response.h
// Problem Set 1b                                 Chris Canal
// Team cansym                                    canal.c@husky.neu.edu
//                                                Sarada Symonds
//                                                symonds.s@husky.neu.edu
//
// Class header file for homework 1b. Contains
// declarations for the Response Class

#ifndef Response_h
#define Response_h

#include <iostream>
#include <vector>

class Response
//code class declaration
{
    public:

        //default constructor
        Response();

        //constructor
        Response(int newCorrectDigits, int newIncorrectDigits);

        //set correct and incorrect digit amounts
        void set(int newCorrectDigits, int newIncorrectDigits);

        //set only correct digit amounts
        void setCorrect(int newCorrectDigits);

        //set only incorrect digit amounts
        void setIncorrect(int newCorrectDigits);

        //get correct digit
        int getCorrect();

        //get incorrect digit
        int getIncorrect();

        //operator overload to compare two Response objects
        friend bool operator == (const Response & response1, const Response & response2);


    private:

        //number of correct and incorrect digits
        int correctDigits, incorrectDigits;
};

#endif
