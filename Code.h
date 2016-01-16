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

        //initialize random variables
        randomInit(int n, int m, vector<int>& codeDigits);



    private:

        //number of digits in the code
        int n;

        //range of digits in code
        int m;

        //code
        std::vector <int> codeDigits;
}

int main()
{

   return 0;
}
