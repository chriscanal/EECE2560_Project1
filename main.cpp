// Homework 1                                     Chris Canal
//                                                canal.c@husky.neu.edu
//                                                Sarada Symonds
//                                                symonds.s@husky.neu.edu
//
// Main program file for homework 1. Contains declarations for
// randomInit, checkCorect, and checkIncorect.
//

//comments to the side for variables?

#include "Code.h"
#include <iostream>
#include <vector>
#include <time.h>    //for making rand() more random

using namespace std;

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
        codeDigits.push_back(guess[i]-48);
    }
}

vector<int> Code::getCode()
{
    return codeDigits;
}

int Code::checkCorrect( Code& guessDigits){
   int numberCorrect = 0;
   for(int i = 0; i < guessDigits.codeDigits.size(); i++)
   {
       if ( guessDigits.codeDigits[i] == codeDigits[i] )
       {
           numberCorrect += 1;
       }
   }
   return numberCorrect;
}

//returns the  number of correct digits in the incorrect location
int Code::checkIncorrect( Code& guessDigits)
{
    vector<int> guessVector = guessDigits.getCode();
    vector<int> codeVector = getCode();
    int incorrectLocationDigits = 0;
    for(int i=0; i<codeVector.size(); i++)
    //for each digit in codeDigits
    {
        for(int j=0; j<guessVector.size(); j++)
        //for each digit in guessDigits
        {
            if(codeVector[i] == guessVector[j])
            //increments incorrectDigits if digit is in code and guess, but not right place
            //replaces
            {
                if (i == j){
                    cout << "\ni == j : position(" << i << ", " << j << ") - Value: (" << codeVector[i] << " == " << guessVector[j] << ")" << endl;
                    codeVector[i] = -1;
                    guessVector[j] = -1;
                    j = guessVector.size();
                }
                else
                {
                    cout << "\ni != j : position(" << i << ", " << j << ") - Value: (" << codeVector[i] << " == " << guessVector[j] << ")" << endl;
                    codeVector[i] = -1;
                    guessVector[j] = -1;
                    incorrectLocationDigits++;
                    j = guessVector.size();
                }
            }
        }
    }
    return incorrectLocationDigits;
}

void printCodeDigits(Code viewingCode)
{
    cout << "(";
    for(int i=0; i<viewingCode.getCode().size(); ++i)
    {
        cout << viewingCode.getCode()[i];
        if (i != viewingCode.getCode().size()-1){
            cout << ", ";
        }
    }
    cout << ")" << endl;
}

void Code::checkGuess( Code& guessCode)
{
    cout << "(" << checkCorrect(guessCode);
    cout << ", " << checkIncorrect(guessCode);
    cout << ")" << endl;
}

Code::Code(){
    n = 0;
    m = 0;
}

int main(){
    srand (time(NULL));   //Uses time to make rand more random

    int n = 5;            //n is the number of digits
    int m = 5;            //m is the range of the guess

    //secrete code object
    Code computerCode(n, m);

    //initializing a random string of integers for computerCode
    computerCode.randomInit();
    cout << "Random Code Generated: ";
    printCodeDigits(computerCode);


    //instances of Code for testing
    Code sampleGuess1;
    Code sampleGuess2;
    Code sampleGuess3;

    //setting the codeDigits of each sample Code
    sampleGuess1.setCodeDigits("50326");
    sampleGuess2.setCodeDigits("21222");
    sampleGuess3.setCodeDigits("13345");

    //checking the guess codes against the computerCode
    computerCode.checkGuess(sampleGuess1);
    computerCode.checkGuess(sampleGuess2);
    computerCode.checkGuess(sampleGuess3);

    cout << "Done" << endl;

    return 0;
}
