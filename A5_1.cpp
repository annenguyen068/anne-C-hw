//
//  main.cpp
//  A5_1
//  Anh T Nguyen
//  CIS 278 - SMCC
//  Created by Nguyet Anh on 9/19/17.
//  Copyright (c) 2017 Nguyet Anh NGUYEN. All rights reserved.
//



/* Assignment 5.1 [45 points]
 
 Write a program that records high-score data for a fictitious game. The program will ask the user to enter five names, and five scores. It will store the data in memory, and print it back out sorted by score.
 
 The output from your program should look exactly like this:
 
 Enter the name for score #1: Suzy
 Enter the score for score #1: 600
 Enter the name for score #2: Kim
 Enter the score for score #2: 9900
 Enter the name for score #3: Bob
 Enter the score for score #3: 1012
 Enter the name for score #4: Armando
 Enter the score for score #4: 8000
 Enter the name for score #5: Tim
 Enter the score for score #5: 514
 
 Top Scorers:
 Kim: 9900
 Armando: 8000
 Bob: 1012
 Suzy: 600
 Tim: 514
 Additional Requirements
 
 The data must be stored in two arrays: an array of strings named names, and an array of ints named scores. These arrays must be declared in the main function.
 
 All of the user input should be done in a function named initializeArrays(). It should have the following signature:
 
 void initializeArrays(string names[], int scores[], int size)
 You must also write two more functions: one to sort both arrays in descending order by score, and one to display the final list of names and scores. They should have the following signatures.
 
 void sortData(string names[], int scores[], int size)
 void displayData(const string names[], const int scores[], int size)
 The main function should be very short. It should just declare the arrays and then invoke these three functions.
 
 You may use any sort algorithm, but I would recommend using the selection sort from lesson 9.6. Don't use C++'s sort() function, but you can use the swap() function.
 */




#include <iostream>
#include <iomanip>
using namespace std;


// Function prototypes
void sort_decreasing(string [], int [], int);
void displayData(string [], int [], int);
void userinput(string [], int [], int);


int main()
{
    // initialize scores and names array with 5 elements
    int size = 5;
    string names[] = {"","","","",""};
    int scores[]={0,0,0,0,0};
    
    // input scores and names from user
    userinput(names, scores, size);
    
    // sort both names and scores based on decreasing scores
    sort_decreasing(names, scores, size);
    
    // print out sorted names and scores
    displayData(names, scores, size);
    
    return 0;
    
}






//*********************************************************************
// This function is to take input from user and store in 2 arrays: names and scores
//*********************************************************************
void userinput(string names[], int scores[], int size)
{
    for (int i=0; i < size; i ++)
    {
        cout << "Enter the name for score #" << i+1 << " : ";
        cin >> names[i];
        cout << "Enter the score for score #" << i+1 << " : ";
        cin >> scores[i];
    }
}






//*********************************************************************
// This fuction implements selection sort algorithm to sort names and scores in
// decreasing order of scores.
//*********************************************************************
void sort_decreasing(string names[], int scores[], int size)
{
    // index and value of max score
    int max_index, max_val;
    
    // player who has max score
    string max_name;
    
    // check each element in scores - except last one
    for (int i = 0; i < (size - 1); i++)
    {
        
        max_index = i;
        max_val = scores[i];
        max_name = names[i];
        
        // loop through the rest of elements to find what is best scores and its index
        for(int j = i + 1; j < size; j++)
        {
            if (scores[j] > max_val)
            {
                max_val = scores[j];
                max_name = names[j];
                max_index = j;
            }
        }
        
        // swap score between current player and the one who had the max score
        scores[max_index] = scores[i];
        scores[i] = max_val;
        
        // swap name between current player and the one who had the max score
        names[max_index] = names[i];
        names[i] = max_name;
    }
}







//*********************************************************************
// This funtion is to display name and score of each player, the results of the game
//*********************************************************************
void displayData(string names[], int scores[], int size)
{
    cout << "Top Scorers:" << endl;
    for (int count = 0; count < size; count++)
    {
        cout << names[count] << ": " << scores [count] << endl;
    }
}




/*********** Output ***************
 
 Enter the name for score #1 : James
 Enter the score for score #1 : 10
 Enter the name for score #2 : Ann
 Enter the score for score #2 : 200
 Enter the name for score #3 : Tim
 Enter the score for score #3 : 15
 Enter the name for score #4 : Eric
 Enter the score for score #4 : 300
 Enter the name for score #5 : Wang
 Enter the score for score #5 : 23
 Top Scorers:
 Eric: 300
 Ann: 200
 Wang: 23
 Tim: 15
 James: 10
 
 ********************************/

