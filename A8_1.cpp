// Anh T N Nguyen _ CIS 278
// College of San Mateo
// Assignment 8





/*This program receives scores and the names of people they belong to and then sorts them in descending order by score amount. It uses structs which have two fields: an int named score and a char array named name.The program will prompt the user to enter a name and then prompts them to enter a score until both arrays are full. The name and score pairs are maintained by keeping the name and its score in the same index number for both arrays. Then, the program sorts them in descending order by score andkeeps the original name and score pairs together. Finally, it prints the sorted scores in two columns, one the names and the other the scores. Each row contains a pair of names and scores entered together by the user.*/



#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;



// Defines a Highscore structure.
struct Highscore
{
    int score;
    char name[24];
};


// Function prototypes
void initializeData(Highscore scores[], int size);
void sortData(Highscore scores[], int size);
void displayData(const Highscore scores[], int size);

int main()
{
    int size;
    
    cout << "How many scores will you be entering?: ";
    cin >> size;
    cin.ignore();
    
    Highscore *highscorePtr;
    highscorePtr = new Highscore[size];
    
    initializeData(highscorePtr, size);
    sortData(highscorePtr, size);
    displayData(highscorePtr, size);
    
    return 0;
}





/* This fuction asks a user to enter 5 names and scores. Each name and score combination is stored as a structure in the scores array.
 pre: size <= the size of the arrays
 post: scores[] and names[] are initialized
 */

void initializeData(Highscore scores[], int size)
{
    for (int index = 0; index < size; index++)
    {
        cout << "Enter the name for score #" << index + 1 << ": ";
        cin.getline(scores[index].name, 24);
        
        cout << "Enter " << scores[index].name << "'s score: ";
        cin >> scores[index].score;
        cin.ignore();
    }
}







/* This function performs a descending order selection sort on the scores array. The array is returned sorted in descending order accoring to highest score.
pre: size <= the size of the arrays
post: Both arrays are sorted in descending order by scores.
*/

void sortData(Highscore scores[], int size)
{
    int startScan, maxIndex, maxValue;
    
    for (startScan = 0; startScan < (size - 1); startScan++)
    {
        maxIndex = startScan;                   // sets maxIndex to the index of the start of the scan
        maxValue = scores[startScan].score;     // max value = the first score in the array
        for (int index = startScan + 1; index < size; index++)
        {
            if (scores[index].score > maxValue)
            {
                maxValue = scores[index].score;
                maxIndex = index;
            }
        }
        swap(scores[maxIndex],scores[startScan]);
    }
}







/* This function takes the sorted scores array, and the size int as input.It displays the sorted scores array by using a loop. First, it prints out "Top Scorers:" and then on a new line,prints the contents of the arrays in two columns. The names are printed on the left and the scores are printed on the right. They are separated by a :

pre: size <= the size of the arrays
post: prints the two arrays in two columns
*/


void displayData(const Highscore scores[], int size)
{
    cout << "\n ** Top Scorers ** \n" << endl;
    
    for (int index = 0; index < size; index++)
    {
        cout << setw(8) << scores[index].name << ":" << setw(6) << scores[index].score << endl;
    }
}

/* Sample Output:
 
 How many scores will you be entering?: 5
 Enter the name for score #1: Anh
 Enter Anh's score: 67
 Enter the name for score #2: Nang
 Enter Nang's score: 98
 Enter the name for score #3: Ban
 Enter Ban's score: 98
 Enter the name for score #4: Mai
 Enter Mai's score: 89
 Enter the name for score #5: Hong
 Enter Hong's score: 45
 
 ** Top Scorers **
 
 Nang:    98
 Ban:    98
 Mai:    89
 Anh:    67
 Hong:    45
 Program ended with exit code: 0 */

