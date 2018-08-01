//
//  main.cpp
//  A4_1 Arrays
//  CIS 278 _ SMCC
//  Created by Anh Thi Nguyet Nguyen on 9/10/17.
//  Copyright (c) 2017 Nguyet Anh NGUYEN. All rights reserved.
//
//  Write a program that reads five cards from the user, then analyzes the cards and prints out the category of hand that they represent.Poker hands are categorized according to the following labels: Straight flush, four of a kind, full house, straight, flush, three of a kind, two pairs, pair, high card.


#include <iostream>
using namespace std;


// Function prototypes :  Each function accepts a const int array that contains five integers, each representing one of the 5 cards in the hand, and return "true" if the hand contains the cards indicated by the name of the function, "false" if it does not.

bool containsPair(const int hand[]);
bool containsTwoPair(const int hand[]);
bool containsThreeOfaKind(const int hand[]);
bool containsStraight(const int hand[]);
bool containsFullHouse(const int hand[]);
bool containsFourOfaKind(const int hand[]);
int repeatCount(int idx, const int hand[]);
bool is_diff_between_1_and_4(int idx, const int hand[]);







// This is the main function of the program, which asks user to put in 5 value of the cards and revokes functions to analyzes the cards and prints out the category of hand that they represent
int main() {
    
    int i; 
    int hand [5];
    
    for (i=0; i<5; i++)
    {
           cout << "Enter a value" << endl;
           cin >> hand [i];
    }
    
    cout << endl;
    
    for (i=0; i<5; i++)
    {
        cout << hand[i] << " ";
    }
    cout << endl;

    if (containsPair(hand)) {
        cout << "contains a pair" << endl;
    }
    if (containsTwoPair(hand)) {
        cout << "contains two pairs" << endl;
    }
    if (containsThreeOfaKind(hand)) {
        cout << "contains Three of a Kind" << endl;
    }
    if (containsFourOfaKind(hand)) {
        cout << "contains Four of a Kind" << endl;
    }
    if (containsFullHouse(hand)) {
        cout << "contains Full House" << endl;
    }
    if (containsStraight(hand)) {
        cout << "contains Straight" << endl;
    }
    if ( (!containsStraight(hand)) &&  (!containsPair(hand)) ) {
        cout << "contains high card" << endl;
    }
    return 0;
}






// The repeatCount() function is used to count how many time one value is repeated in the hand. 

int repeatCount(int idx, const int hand[])
{
    int count = 0;
    for (int i = 0; i<5; i++)
    {
        if (hand[i] == hand[idx]) count += 1;
    }
    return count;
}






// This function is used to define the difference between one value and the other in the hand (it is used for define the hand contains Straight or not). "d" is the difference between 1 value and another in the hand. It returns "true" if d>4, d<-4, d==00, and  returns "false" with other "d" values.

bool is_diff_between_1_and_4(int idx, const int hand[])
{
    for (int i = 0; i<5; i++)
    {
        if ( i != idx)
        {
            int d = hand[i] - hand[idx];
            if (d > 4 || d < -4 || d == 0) return false;
        }
    }
    return true;
}







// This function is used to decide if the hand contains pair or not, it calls the repeatCount() function that's mentioned above. It returns "true" if the repeatCount is >=2, and "false" if it does not.

bool containsPair(const int hand[])
{
    for (int i = 0; i < 5; i++)
    {
        if (repeatCount(i, hand) >= 2)
            return true;
    }
    return false;
}







// This function is used to decide if the hand contains Two par or not, it calls the repeatCount() function that's mentioned above.
bool containsTwoPair(const int hand[])
{
    int pair = 0;
    int repeated = 0;
    for (int i = 0; i < 5; i++)
    {
        if (repeatCount(i, hand) >= 2)
        {
            if (repeated == 0)
            {
                repeated = hand[i];
                pair += 1;
            }
            else
            {
                if (repeated != hand[i])
                {
                    pair += 1;
                    repeated = hand[i];
                }
            }
                
        }
    }
    if (pair > 1)
        return true;
    return false;
}







//// This function is used to decide if the hand contains Three of a kind or not, it calls the repeatCount() function that's mentioned above. It returns "true" if the repeatCount is >=3, and "false" if it does not.
bool containsThreeOfaKind(const int hand[])
{
    for (int i = 0; i < 5; i++)
    {
        if (repeatCount(i, hand) >= 3)
            return true;
    }
    return false;
}







//// This function is used to decide if the hand contains four of a pair or not, it calls the repeatCount() function that's mentioned above. It returns "true" if the repeatCount is >=4, and "false" if it does not.
bool containsFourOfaKind(const int hand[])
{
    for (int i = 0; i < 5; i++)
    {
        if (repeatCount(i, hand) >= 4)
            return true;
    }
    return false;
}







//// This function is used to decide if the hand contains Fullhouse or not, it calls the containsTwopair() and containsThreeofaKind() function that's mentioned above. It returns "true" if the the 2 sub-funtions return "true", and "false" if they do not.
bool containsFullHouse(const int hand[])
{
    if (containsTwoPair(hand) &&  containsThreeOfaKind(hand))
        return true;
    return false;
}







// This function is used to decide if the hand contains Straight or not, it calls the is_diff_between_1_and_4() function that's mentioned above. It returns "true" if the sub-funtion returns "true", and "false" if it does not.
bool containsStraight(const int hand[])
{
    for (int i = 0; i < 5; i++)
    {
        // check if the difference between hand[i] and other values is from 1-4
        if ( !is_diff_between_1_and_4 (i, hand) )
            return false;
    }
    return true;
}







/*Output Sample 
 
 Enter a value
 1
 Enter a value
 2
 Enter a value
 3
 Enter a value
 4
 Enter a value
 5
 
 1 2 3 4 5
 contains Straight
 Program ended with exit code: 0*/

