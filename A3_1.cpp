//
//  main.cpp
//  A3_1
//
//  Created by Anh Nguyen on 9/4/17.
//  SMCC_CIS 278 (CS1)
//  Copyright (c) 2017 Nguyet Anh NGUYEN. All rights reserved.

//  Assignment 3 : Write a program that plays a number guessing game with a Human user. The Human user will think of a number between 1 and 100, inclusive.
//  The program will make guesses and the user will tell the program to guess higher or lower.
 


#include <iostream>
#include <iomanip>

using namespace std;

// Function prototypes
void playOneGame();
void getUserResponseToGuess(int guess, char& result);
int getMidpoint(int low, int high);

// The main function that calls the playOneGame () function.

int main() {
    char response;
    
    cout << "Ready to play (y/n)? ";
    cin >> response;
    while (response == 'y') {
        playOneGame();
        cout << "Great! Do you want to play again (y/n)? ";
        cin >> response;
    }
}

// The getUserResponseToGuess() function prompt the user with the phrase "is it <guess> (h/l/c)? " with the value replacing the token <guess>.
// It sets its "result" parameter equal to either 'h', 'l', or 'c'.

void getUserResponseToGuess(int guess, char& result)
{
    cout << "Is it "<<guess<<" h/l/c?";
    cin >> result;
}

// The getMidpoint() function accept two integers, and return the midpoint of the two integers.
// If there are two values in the middle of the range then you should consistently chose the smaller of the two.

int getMidpoint(int low, int high)
{
    int midpoint = (low +high)/2;
    return midpoint;
}
    
// The playOneGame() function implements a complete guessing game on the range of 1 to 100. It revoked the getUserResponseToGuess() and getMidpoint() inside.

void playOneGame()
{
    int low = 1;
    int high = 100;
    char result = ' ';
    int guess = getMidpoint(low, high);
    
    while (result != 'c')
    {
        getUserResponseToGuess(guess, result);
        
        if (result == 'h')
            low = guess;
        else
            high = guess;
        
        guess = getMidpoint(low, high);
    }
    
    // Output Sample :
    /* Ready to play (y/n)? y
     Is it 50 h/l/c? l
     Is it 25 h/l/c?h
     Is it 37 h/l/c?l
     Is it 31 h/l/c?l
     Is it 28 h/l/c?h
     Is it 29 h/l/c?h
     Is it 30 h/l/c?c
     Great! Do you want to play again (y/n)? y
     Is it 50 h/l/c?h
     Is it 75 h/l/c?l
     Is it 62 h/l/c?l
     Is it 56 h/l/c?h
     Is it 59 h/l/c?h
     Is it 60 h/l/c?c
     Great! Do you want to play again (y/n)? n
     Program ended with exit code: 0 */
    
}


