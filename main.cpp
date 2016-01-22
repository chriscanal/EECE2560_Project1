// main.cpp
// Problem Set 1A                                 Chris Canal
// Team cansym                                    canal.c@husky.neu.edu
//                                                Sarada Symonds
//                                                symonds.s@husky.neu.edu
//
// Main program file for homework 1. Contains declarations for
// randomInit, checkCorect, and checkIncorect.

#include "Code.h"
#include <iostream>
#include <vector>
#include <time.h>    //for making rand() more random

using namespace std;

Code::Code()
//default constructor
{
    n = 0;
    m = 0;
}

Code::Code(int newN, int newM)
//constructor for range and length of the code
{
    set(newN, newM);
}

vector<int> Code::randomInit()
//initializes a random string of digits to be used as the code
{
    for(int i = 0; i < n; i++)
    //for each digit n, will add a random digit
    {
        //inserts an additional random digit to codeDigits
        //that is in the range 0 to m-1
        codeDigits.push_back(rand() % m);
    }

}

int Code::checkCorrect( Code& guessDigits)
//returns the  number of correct digits in the correct location
{
   int numberCorrect = 0;

   for(int i = 0; i < guessDigits.codeDigits.size(); i++)
   {

       if (guessDigits.codeDigits[i] == codeDigits[i])
       {
           numberCorrect += 1;
       }

   }

   return numberCorrect;
//end of checkCorrect function
}


int Code::checkIncorrect( Code& guessDigits)
//returns the  number of correct digits in the incorrect location
{
    vector<int> guessVector = guessDigits.getCode();
    vector<int> codeVector = getCode();
    int incorrectLocationDigits = 0;

    for(int i = 0; i < codeVector.size(); i++)
    //for each digit in codeDigits
    {

        for(int j = 0; j < guessVector.size(); j++)
        //for each digit in guessDigits
        {

            if(codeVector[i] == guessVector[j])
            //increments incorrectDigits if digit is in code
            //but not right place. Sets matched vector numbers
            //to -1 so that they will not match with other ints
            {
                if (i == j){
                    codeVector[i] = -1;
                    guessVector[j] = -1;
                    j = guessVector.size();
                }
                else
                {
                    codeVector[i] = -1;
                    guessVector[j] = -1;
                    incorrectLocationDigits++;
                    j = guessVector.size();
                }

            //end of if statement to determine if digits match
            }

        //end of for loop to go through each guess digit
        }

    //end of for loop to go through each code digit
    }

    return incorrectLocationDigits;

//end of checkIncorrect function
}

void Code::set(int newN, int newM)
//sets the range and length of the code
{
    n = newN;
    m = newM;
}

void Code::setCodeDigits(const string &guess)
//adds an integer to codeDigits
{
    for(int i = 0; i < guess.length(); i++)
    //adds each number in guess to codeDigits
    {
        //Subtract 48 to convert from ASCII to Integer
        codeDigits.push_back(guess[i] - 48);
    }
}

vector<int> Code::getCode()
//returns the code vector
{
    return codeDigits;
}

void Code::checkGuess( Code& guessCode)
//prints out the results of checkCorrent and checkIncorrect
{
    cout << "Result: (" << checkCorrect(guessCode);
    cout << ", " << checkIncorrect(guessCode);
    cout << ")" << endl;
}

void printCodeDigits(Code viewingCode)
//prints the code vector in a readable format
{
    cout << "Code: (";

    for(int i = 0; i < viewingCode.getCode().size(); ++i)
    {
       cout << viewingCode.getCode()[i];
        if (i != viewingCode.getCode().size() - 1)
        {
            cout << ", ";
        }
    }

    cout << ")" << endl;
//end of printCodeDigits
}

int main()
{
    srand (time(NULL));   //Uses time to make rand more random

    int n = 5;            //n is the number of digits
    int m = 5;            //m is the range of the guess

    //initialize secrete code object
    Code computerCode(n, m);

    //initializing a random string of integers for computerCode
    computerCode.randomInit();

    //print the randomly generated code
    cout << "Random Code Generated: ";
    printCodeDigits(computerCode);


    //initialize instances of the Code class for testing
    Code sampleGuess1;
    Code sampleGuess2;
    Code sampleGuess3;

    //set the codeDigits of each sample Code
    sampleGuess1.setCodeDigits("50326");
    sampleGuess2.setCodeDigits("21222");
    sampleGuess3.setCodeDigits("13345");

    //check the guess codes against the computerCode
    printCodeDigits(sampleGuess1);
    computerCode.checkGuess(sampleGuess1);
    printCodeDigits(sampleGuess2);
    computerCode.checkGuess(sampleGuess2);
    printCodeDigits(sampleGuess3);
    computerCode.checkGuess(sampleGuess3);

    //Let the user know the code finished executing
    cout << "Done" << endl;

    return 0;

//end of main function
}
