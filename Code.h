//
//  Code.h
//  Code
//
//  Created by Chris Canal and Sarada Symonds on 01/16/2016.
//

#ifndef Code_Code_h
#define Code_Code_h

#include <iostream>

//code class declaration
class Code
{
    public:

        //default constructor
        Code();

        //constructor
        Code(int newN, int newM);

        //n and m setter
        set(int newN, int newM);

        setCodeDigits(const std::string &guess);

        //accessor, does not change data
        getCode();

        //initialize random variables
        void randomInit();

        checkCorrect( const Code& guessDigits);

        int checkIncorrect( const Code& guessDigits);



    private:

        //number of digits in the code
        int n;

        //range of digits in code
        int m;

        //code
        std::vector <int> codeDigits;
}
