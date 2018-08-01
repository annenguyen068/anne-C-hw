//
//  main.cpp
//  A6_2
//  Anh T Nguyen
//  CIS 278 - SMCC
//  Created by Nguyet Anh on 9/27/17.
//  Copyright (c) 2017 Nguyet Anh NGUYEN. All rights reserved.
//



/* Assignment 5.1 [45 points]
 
 Rewrite the High Scores program so that it uses Dynamic Memory Allocation to create the names and scores arrays.
It starts out by asking the user how many scores will be entered. It allocates appropriate arrays (names and scores), and then proceed just like the original High Scores assignment (sort out scores in descending order).
 
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
    // initialize scores and names array with pointers
    int *scores;
    string *names;
    
    int size;
    
    // Get the number of scores that user wants to process:
    cout << "Enter the number of users: ";
    cin >> size;
    
    scores = new int[size];
    names = new string[size];
    
    // input scores and names from user
    userinput(names, scores, size);
    
    // sort both names and scores based on decreasing scores
    sort_decreasing(names, scores, size);
    
    // print out sorted names and scores
    displayData(names, scores, size);
    
    return 0;
    
}




//*********************************************************************
/* This function asks the user to put in the names and scores. The user's responses is stored in result pass
by reference */

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
// This funtion is to display names and scores of each player accordingly, in descending order, as a result of sort_decreasing function.
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
 
 Enter the number of users: 5
 Enter the name for score #1 : Ann
 Enter the score for score #1 : 20
 Enter the name for score #2 : Mike
 Enter the score for score #2 : 30
 Enter the name for score #3 : Wang
 Enter the score for score #3 : 40
 Enter the name for score #4 : Nam
 Enter the score for score #4 : 50
 Enter the name for score #5 : Van
 Enter the score for score #5 : 60
 Top Scorers:
 Van: 60
 Nam: 50
 Wang: 40
 Mike: 30
 Ann: 20
 Program ended with exit code: 0
 
 ********************************/