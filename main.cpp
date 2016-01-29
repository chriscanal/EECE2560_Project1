// main.cpp
// Problem Set 1b                                 Chris Canal
// Team cansym                                    canal.c@husky.neu.edu
//                                                Sarada Symonds
//                                                symonds.s@husky.neu.edu
//
// Main program file for homework 1b.

#include "Code.h"
#include "Response.h"
#include "Mastermind.h"
#include <iostream>
#include <vector>
#include <time.h>    //for making rand() more random

using namespace std;


//------------Global Operator Overloading (MUST GO FIRST)---------------
ostream&  operator << (ostream & ostr, Response responseObj)
{
    ostr << "(" << responseObj.getCorrect() << ", " << responseObj.getIncorrect() << ")";

    return ostr;
}

//---------------------Code Class Functions-----------------

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

int Code::getN()
//returns number of digits in the code
{
  return n;
}

void Code::randomInit()
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

int Code::checkCorrect( Code& guessDigits) const
//returns the  number of correct digits in the correct location
{
   int numberCorrect = 0;

   for(int i = 0; i < guessDigits.getCode().size(); i++)
   {

       if (guessDigits.getCode()[i] == getCode()[i])
       {
           numberCorrect += 1;
       }

   }

   return numberCorrect;
//end of checkCorrect function
}


int Code::checkIncorrect( Code& guessDigits) const
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

vector<int> Code::getCode() const
//returns the code vector
{
    return codeDigits;
}

void Code::checkGuess( Code& guessCode) const
//prints out the results of checkCorrent and checkIncorrect
{
    cout << "Result: (" << checkCorrect(guessCode);
    cout << ", " << checkIncorrect(guessCode);
    cout << ")" << endl;
}



//---------------------Response Class Functions-----------------


Response::Response()
//default constructor
{
    correctDigits = 0;
    incorrectDigits = 0;
}

Response::Response(int newCorrectDigits, int newIncorrectDigits)
//constructor for two given values
{
    correctDigits = newCorrectDigits;
    incorrectDigits = newIncorrectDigits;
}

void Response::set(int newCorrectDigits, int newIncorrectDigits)
//set correct and incorrect digit amounts
{
    correctDigits = newCorrectDigits;
    incorrectDigits = newIncorrectDigits;
}

void Response::setCorrect(int newCorrectDigits)
//set only correct digit amount
{
    correctDigits = newCorrectDigits;
}

void Response::setIncorrect(int newIncorrectDigits)
//set only incorrect digit amount
{
    incorrectDigits = newIncorrectDigits;
}

int Response::getCorrect()
//get correct digit
{
    return correctDigits;
}


int Response::getIncorrect()
//get incorrect digit
{
    return incorrectDigits;
}

//operator overload to compare two Response objects
bool operator == ( Response & response1, Response & response2)
{
    return (response1.getCorrect() == response2.getCorrect()) && (response1.getIncorrect() == response2.getIncorrect());
}

//---------------------Mastermind Class Functions-----------------

Mastermind::Mastermind()
//default constructor
{
  secretCode.set(5, 10);
}

Mastermind::Mastermind(int newN, int newM)
//constructor for the mastermind class
{
  secretCode.set(newN, newM);
}

void Mastermind::printSecretCode()
//prints the secret code from the mastermind object
{
  cout << "Secret Code: (";

  for(int i = 0; i < secretCode.getCode().size(); ++i)
  {
     cout << secretCode.getCode()[i];
      if (i != secretCode.getCode().size() - 1)
      {
          cout << ", ";
      }
  }

  cout << ")" << endl;
}

Code Mastermind::humanGuess()
//reads a guess from the keyboard and returns guess as Code object
{
  Code guessCode;
  string guessString;
  cout << "\nPlease enter your guess, numbers only please:" << endl;
  cin >> guessString;
  guessCode.setCodeDigits(guessString);

  return guessCode;
}

Response Mastermind::getResponse(Code & guessCode, Code & secretCode)
//Compares two codes and gets response
{
    Response codeResponse;
    codeResponse.setCorrect(secretCode.checkCorrect(guessCode));
    codeResponse.setIncorrect(secretCode.checkIncorrect(guessCode));

    return codeResponse;
}

bool Mastermind::isSolved(Response responseObj)
//Checks the Response obj to see if it the code is solved

// Instructions: Create a function isSolved() that is passed a response and returns
// true if the response indicates that the board has been solved.
{

    return responseObj.getCorrect() == secretCode.getN();

}

int Mastermind::playGame()
// Instructions: Initializes a random code, prints it to the screen, and then
// iteratively gets a guess from the user and prints the response until either the codemaker
// or the codebreaker has won.
{
    Mastermind newGame;
    newGame.secretCode.randomInit();
    newGame.printSecretCode();

    Code userGuessCode;
    Response userResponse;
    for (int i = 0; i < 10; i++)
    {
        userGuessCode = newGame.humanGuess();
        userResponse = newGame.getResponse(userGuessCode, newGame.secretCode);
        cout << userResponse << endl;
        if (newGame.isSolved(userResponse))
        {
            cout << "\nCongradulations! You have guessed correctly! \nEXITING GAME..." << endl;
            i = 10;
        }
        else
        {
            cout << "\nPlease guess again...";
        }
        if (i == 9)
        {
            cout << "Wait. Actually...\nThat was your last guess. \nSorry\nYOU LOOSE";
        }
    }
    return 0;
}

//---------------------  Free Functions   ----------------------

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
    Mastermind theGame;
    return theGame.playGame();

//end of main function
}
