//
//  Code.h
//  Code
//
//  Created by Chris Canal and Sarada Symonds on 01-16-2016.
//

#ifndef Code_Code_h
#define Code_Code_h

#include <iostream>
#include <vector>

//code class declaration
class Code
{
    public:

        //default constructor
        Code();

        //constructor
        Code(int newN, int newM);

        //n and m setter
        void set(int newN, int newM);

        void setCodeDigits(const std::string &guess);

        //accessor, does not change data
        std::vector<int> getCode();

        //initialize random variables
        std::vector<int> randomInit();

        int checkCorrect( Code& guessDigits);

        int checkIncorrect( Code& guessDigits);



    private:

        //number of digits in the code
        int n;

        //range of digits in code
        int m;

        //vector containg code
        std::vector<int> codeDigits;
};

#endif
