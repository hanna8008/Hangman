/*
Hanna Zelis
CSC 1710 - 01
4/15/2021
/home/students/hzelis/csc1710/programs/prog3/game.cpp

This program is designed to create a hangman game. 

*/





#include <iostream>
#include <cstring>
#include <string>
#include <list>
#include <fstream>



using namespace std;



//Function prototype to update the output w/user guess
string updateWordDash(int, string);

//Function prototype to keep the user's guesses updated 
int trackUserGuesses(string, char);

//Function prototype to show if the user's guess was found and update number of guesses left
void findGuessAndCalculateGuesses(int, string, int);

//Function prototype to message to the user what body part would be drawn if they got a guess wrong
void hangmanBody (int);
 
//Function to ASCII art for hangman dude
void makeMan(int);

//Function prototype to show whether the user won or lost
void userResult(string, string, int);





int main()
{





  //Declare variables

  string word, wordDash;
  char userGuess;
  int wordLength, i, guess, foundCounter, guessCounter;
  string previousGuess;
  int previousGuessLength;
  int previousLetters = trackUserGuesses(previousGuess, userGuess);


  
  const string list[10] = { "vietnam", "germany", "morocco", "romania", "ecuador", "belgium", "austria", "hungary", "iceland", "jamacia" };

  
  int randomWord = rand() % 10;
  for (i = 0; i <= randomWord; i++)
  {
    if (i == randomWord)
      word = list[i];
  }
  


  //Length of the word 
  wordLength = word.length(); 


  guess = 0;


  //Using a function to keep the dashes shown while the user fills in the correct guesses
  wordDash = updateWordDash(wordLength, word);

  cout << "Word = " << wordDash << endl;
  cout << endl; 
  cout << endl;
  cout << endl;
 

  //the user will continue to be asked for an input until they run out of guesses or solve the word 
  while ((wordDash != word) && (guess < 10))
  {

    foundCounter = 0;
   
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "Enter a letter: "; 
    cin >> userGuess;
    
    //adds the user's guesses to a list so they can see what they have guessed and so it can be tracked
    previousGuess.push_back(userGuess);    

    //Looks at the user's input and determines whether or not it is in the word, and if it is, it updates the dashes so that the guess replaces the dash at its certain point 
    for (i = 0; i < wordLength + 1; i++)
    {  

        if (word[i] == userGuess)
        {
         foundCounter++;
         wordDash[i] = userGuess;
        }
        if (word[i] != userGuess)
        {
          guessCounter++;
          wordDash = wordDash;
        }
    }

    findGuessAndCalculateGuesses(foundCounter, wordDash, previousLetters);
   
    if ((foundCounter >= 1) && (trackUserGuesses(previousGuess, userGuess) == 0))
      guess = guess - 1; 

    if ((guessCounter >= 1) && (trackUserGuesses(previousGuess, userGuess) == 0))
      guess++;

  
    guess = guess;

/*
Insert here the body part messaging of the program
*/ 
    if (guess > 0)
     hangmanBody(guess);    
 

    cout << "You have " << guess << "/10 guesses left" << endl;
    cout << endl;  
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;

  makeMan(guess);

  cout << endl;
  cout << endl;
  cout << endl;
  cout << endl;
  cout << endl;

  }
   
  //determines if the user won or lost
  userResult(wordDash, word, guess);

  return 0;
}





//Function to keep the output updated
string updateWordDash(int wordLengthFun, string wordFun)
{
  int i;
  
  string wordDashFun;

  wordFun.erase();

  for (i = 0; i < wordLengthFun; i++)
    wordDashFun = wordFun.insert(i, "_");

  
  return wordDashFun;
}





//Determines whether or not a user has already inputed a number
int trackUserGuesses(string previousGuessFun, char userGuessFun)
{
  cout << "Prior guesses: " << previousGuessFun << endl;

  int previousLetters;
  int i, count;
  int length = previousGuessFun.size();
  count = 0;

  previousLetters = 0;
  
  //Counts how many times the user's guess was inputed
  for (i = 0; i <= length; i++)
  {
    if (previousGuessFun[i] == userGuessFun)
    count++;
  }

  //If the last for loop counted that the guess occured more than once, the user is informed
  if (count >= 2)
  {
    previousLetters++;
    cout << "You already guessed this." << endl;
    cout << endl;
  }
  
  //updating this in the last foor loop is if it equals 0, the letter occured once and a guess can be added and if it equals one, don't increment guess

  return previousLetters;

}





//Function to determine if user's guess is in word and how many guesses the user has left
void findGuessAndCalculateGuesses(int foundCounterFun, string wordDashFun, int previousLettersFun)
{

  //user's guess was found in the word (foundCounterFun) and the user guessed their guess once or more (previousLettersFun)
  if (((foundCounterFun >= 1) && (previousLettersFun == 0)) || ((foundCounterFun >= 1) && (previousLettersFun != 0)))
  {
    cout << endl;
    cout << wordDashFun << endl;
    cout << "Letter found :)" << endl;
    cout << endl;
  }

  //user's guess was not found (foundCounterFun) and it was the first time the user guessed this guess specifically (previousLettersFun)
  if ((foundCounterFun < 1) && (previousLettersFun == 0))
  {
    cout << endl;
    cout << wordDashFun << endl;
    cout << "Letter not found :(" << endl;
    cout << endl;
  }

  //using separate if statement if the user's guess was not found and the user inputed a guess for a second time, the amount of guesses the user used up should not increase
  if ((foundCounterFun < 1) && (previousLettersFun >= 1))
  {
    cout << endl;
    cout << wordDashFun << endl;
    cout << "Letter not found :(" << endl;
    cout << endl;
  }

  return;
}





//Function for determine what body type to tell the users would be drawn if the hangman guy was being drawn
void hangmanBody (int guessFun)
{
  int i;
  string body[11] = { "head", "torso", "left arm", "right arm", "left leg", "right leg",
                            "left eye", "right eye", "nose", "frown(mouth)" };

  if (guessFun == 1)
    cout << "Body part drawn due to 1 wrong guess: " << body[0] << endl;
  if (guessFun == 2)
    cout << "Body part drawn due to 2 wrong guesses: " << body[1] << endl;
  if (guessFun == 3)
    cout << "Body part drawn due to 3 wrong guesss: " << body[2] << endl;
  if (guessFun == 4)
    cout << "Body part drawn due to 4 wrong guesses: " << body[3] << endl;
  if (guessFun == 5)
    cout << "Body part drawn due to 5 wrong guesses: " << body[4] << endl;
  if (guessFun == 6)
    cout << "Body part drawn due to 6 wrong guesses: " << body[5] << endl;
  if (guessFun == 7)
    cout << "Body part drawn due to 7 wrong guesses: " << body[6] << endl;
  if (guessFun == 8)
    cout << "Body part drawn due to 8 wrong guesses: " << body[7] << endl;
  if (guessFun == 9)
    cout << "Body part drawn due to 9 wrong guesses: " << body[8] << endl;
  if (guessFun == 10)
    cout << "Body part drawn due to 10 wrong guesses: " << body[9] << endl;

}





//
void makeMan(int guessFun)
{

  if (guessFun == 1)
  {
    cout << "  OOO  " << endl;
    cout << " O   O " << endl;
    cout << "O     O" << endl;
    cout << "O     O" << endl;
    cout << "O     O" << endl;
    cout << " O   O " << endl;
    cout << "  OOO  " << endl;
  }

  if (guessFun == 2)
  {
    cout << "  OOO  " << endl;
    cout << " O   O " << endl;
    cout << "O     O" << endl;
    cout << "O     O" << endl;
    cout << "O     O" << endl;
    cout << " O   O " << endl;
    cout << "  OOO  " << endl;  
    cout << "   |   " << endl;
    cout << "   |   " << endl;
  }

  if (guessFun == 3) 
  {
    cout << "  OOO  " << endl;
    cout << " O   O " << endl;
    cout << "O     O" << endl;
    cout << "O     O" << endl;
    cout << "O     O" << endl;
    cout << " O   O " << endl;
    cout << "  OOO  " << endl;
    cout << "  L|   " << endl;
    cout << "   |   " << endl;
  }

  if (guessFun == 4)
  {
    cout << "  OOO  " << endl;
    cout << " O   O " << endl;
    cout << "O     O" << endl;
    cout << "O     O" << endl;
    cout << "O     O" << endl;
    cout << " O   O " << endl;
    cout << "  OOO  " << endl;
    cout << "  L|/   " << endl;
    cout << "   |   " << endl;
  }

  if (guessFun == 5)
  {
    cout << "  OOO  " << endl;
    cout << " O   O " << endl;
    cout << "O     O" << endl;
    cout << "O     O" << endl;
    cout << "O     O" << endl;
    cout << " O   O " << endl;
    cout << "  OOO  " << endl;
    cout << "  L|/   " << endl;
    cout << "   |   " << endl;
    cout << "  /    " << endl;
  }

  if (guessFun == 6)
  {
    cout << "  OOO  " << endl;
    cout << " O   O " << endl;
    cout << "O     O" << endl;
    cout << "O     O" << endl;
    cout << "O     O" << endl;
    cout << " O   O " << endl;
    cout << "  OOO  " << endl;
    cout << "  L|/   " << endl;
    cout << "   |   " << endl;
    cout << "  / L   " << endl;
  }

  if (guessFun == 7)
  {
    cout << "  OOO  " << endl;
    cout << " O   O " << endl;
    cout << "O o   O" << endl;
    cout << "O     O" << endl;
    cout << "O     O" << endl;
    cout << " O   O " << endl;
    cout << "  OOO  " << endl;
    cout << "  L|/   " << endl;
    cout << "   |   " << endl;
    cout << "  / L   " << endl;
  }

  if (guessFun == 8)
    {
    cout << "  OOO  " << endl;
    cout << " O   O " << endl;
    cout << "O o o O" << endl;
    cout << "O     O" << endl;
    cout << "O     O" << endl;
    cout << " O   O " << endl;
    cout << "  OOO  " << endl;
    cout << "  L|/   " << endl;
    cout << "   |   " << endl;
    cout << "  / L   " << endl;
  }

  if (guessFun == 9)
  {
    cout << "  OOO  " << endl;
    cout << " O   O " << endl;
    cout << "O o o O" << endl;
    cout << "O  )  O" << endl;
    cout << "O     O" << endl;
    cout << " O   O " << endl;
    cout << "  OOO  " << endl;
    cout << "  L|/   " << endl;
    cout << "   |   " << endl;
    cout << "  / L   " << endl;
  }

  if (guessFun == 10)
  {
    cout << "  OOO  " << endl;
    cout << " O   O " << endl;
    cout << "O o o O" << endl;
    cout << "O  )  O" << endl;
    cout << "O  n  O" << endl;
    cout << " O   O " << endl;
    cout << "  OOO  " << endl;
    cout << "  L|/   " << endl;
    cout << "   |   " << endl;
    cout << "  / L   " << endl;
  }
   
return;
}





//Fnction that says whether or not the user won
void userResult(string wordDashFun, string wordFun, int guessFun)
{

  if ((wordDashFun != wordFun) && (guessFun >= 10))
  {
    cout << "You lost :(" << endl;
    cout << "The word = " << wordFun << endl;
    cout << endl;
  }
  
  if ((wordDashFun == wordFun) && (guessFun <= 10))
  {
    cout << "You won :)" << endl;
    cout << endl;
  }

  return;  
}
