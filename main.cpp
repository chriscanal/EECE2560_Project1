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

using namespace std;

vector<int> Code::randomInit()
//initializes a random string of digits to be used as the code
{
    for(int i = 0; i <= n; i++)
    //for each digit n, will add a random digit
    {
        //inserts an additional random digit to codeDigits
        codeDigits.push_back(rand() % (m-1) + 0);
    }
}

Code::Code(int newN, int newM)
//constructor for range and length of the code
{
    set(newN, newM);
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
        codeDigits.push_back(guess[i]);
    }
}

vector<int> Code::getCode()
{
    return codeDigits;
}

int Code::checkCorrect( const Code& guessDigits){
   int numberCorrect = 0;
   for(int i = 0; i <= guessDigits.codeDigits.size(); i++)
   {
       if ( guessDigits.codeDigits[i] == codeDigits[i] )
       {
           numberCorrect += 1;
       }
   }
   return numberCorrect;
}

//returns the  number of correct digits in the incorrect location
int Code::checkIncorrect( const Code& guessDigits)
{
    int incorrectDigits = 0;
    for(int i=0; i<=n; i++)
    //for each digit in codeDigits
    {
        for(int j=0; j<=n; j++)
        //for each digit in guessDigits
        {
            if(codeDigits[i] == guessDigits.codeDigits[j] && i != j)
            //increments incorrectDigits if digit is in code and guess, but not right place
            //replaces
            {
                incorrectDigits++;
                break;
            }
        }
    }

    return incorrectDigits;
}


void printCodeDigits(Code viewingCode)
{
    cout << "(";
    for(int i=0; i<viewingCode.getCode().size(); ++i)
    {
        cout << viewingCode.getCode()[i] << ", " ;
    }
    cout << ")" << endl;
}

void askUserForDigits(Code& computerCode)
{
    int m;
    int n;
    cout << "Please enter an integer value: ";
    cin >> m;
    cout << "\nThe value you entered is " << m;
    cout << "Please enter a second integer value: ";
    cin >> n;
    cout << "\nThe second value you entered is " << n << endl;
    computerCode.randomInit();
    cout << "The code has been generated, time to start guessing :)" << endl;
}

void printCheckCorrectandCheckIncorrect(Code& code)
{

}

Code::Code(){
    n = 0;
    m = 0;
}

int main(){

    int n = 5;            //n is the number of digits
    int m = 7;            //m is the range of the guess

    //secrete code object
    Code computerCode(n, m);

    //initializing a random string of integers for computerCode
    computerCode.randomInit();

    //instances of Code for testing
    Code sampleGuess1;
    Code sampleGuess2;
    Code sampleGuess3;

    //setting the codeDigits of each sample Code
    sampleGuess1.setCodeDigits("50326");
    sampleGuess2.setCodeDigits("21222");
    sampleGuess3.setCodeDigits("13345");

    for (int i = 0; i < sampleGuess1.getCode().size(); i++){
        cout << "Digit Number" << sampleGuess1.getCode()[i] << endl;
    }
    cout << "Hello Chris" << endl;

    return 0;
}
