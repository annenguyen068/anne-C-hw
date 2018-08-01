
/* Anh TN Nguyen
 Assignment 7.1
 CIS 278 _ San Mateo Community College
 */




#include <iostream>
using namespace std;


// Function prototypes
int lastIndexOf(const char* inString, char target);
void reverse(char* inString);
int replace(char* inString, char target, char replacementChar);
bool isPalindrome(const char* inString);
void toupper_str(char* inString);
int numLetters(const char* inString);






int main()
{
    //// This is the main function that revokes all the other functions to check if they are working properly or not. It runs through 6 functions as mentions in Function Prototypes.
    
    cout << "Last index of 'o' in 'Hello World' = "
    << lastIndexOf("Hello World", 'o') << endl;
    
    cout << "Last index of 'l' in 'Hello World' = "
    << lastIndexOf("Hello World", 'l') << endl;
    
    cout << "Last index of 'A' in 'Hello World' = "
    << lastIndexOf("Hello World", 'A') << endl;
    
    ////
    char instr[] = "Hellot";
    cout << "Reverse of '" << instr << "' = ";
    reverse(instr);
    cout << instr << endl;
    
    ////
    char instr1[] = "Hello";
    cout << replace(instr1, 'l', 'L') << endl;
    cout << instr1 << endl;
    
    ///
    cout << isPalindrome("abba") << endl;
    cout << isPalindrome("abbac") << endl;
    cout << isPalindrome("abc cba") << endl;
    
    ///
    char instr2[] = "Hello";
    toupper_str(instr2);
    cout << instr2 << endl;
    
    ///
    cout << numLetters("Hello there ") << endl;
    return 0;
    
    
}







// This function finds the index with the largest integer. It receives a string, a target char to look for It uses a for loop to iterate through the array to find the index with the largest inteter. If the pre condition is not met, the function will return -1.


int lastIndexOf(const char* inString, char target)
{
    int li = -1;
    for (int i = int((strlen(inString) - 1)); i >= 0; i --)
    {
        if (inString[i] == target)
        {
            li = i;
            break;
        }
    }
    return li;
}






// This function receives a c-string char and an int returned by function strlen(). It use a loop to alters any string that is passed in, It reverses the string "Hellot" to "tolleH".

void reverse(char* inString)
{
    int L = int(strlen(inString));
    for (int i = 0; i <= L/2; i ++)
    {
        int j = L-i-1;
        if (i > j) break;
        char temp = inString[i];
        inString[i] = inString[j];
        inString[j] = temp;
    }
}







// This function finds all instances of the char 'target' in the string and replace them with 'replacementChar'. It returns the number of replacements that it makes. If the target char does not appear in the string it returns 0.

int replace(char* inString, char target, char replacementChar)
{
    int L = int(strlen(inString));
    int occur = 0;
    for (int i = 0; i < L; i ++)
    {
        if (inString[i] == target)
        {
            inString[i] = replacementChar;
            occur ++;
        }
    }
    return occur;
}






// This function receives a c-string char and an int returned by function strlen(). It then uses a loop to iterate through the 1st half of the array and the 2nd half to find if the argument string is a palindrome. It returns true if it is and returns false if it is no.
bool isPalindrome(const char* inString)
{
    int L = int(strlen(inString));
    for (int i = 0; i <= L/2; i ++)
    {
        int j = L-i-1;
        if (i > j) break;
        if (toupper(inString[i]) != toupper(inString[j]))
            return false;
    }
    return true;
}
// This function converts the c-string parameter to all uppercase. It received a char and use strlen funtion to return an int L, it then uses a loop and uses toupper function to convert the c-string parameters to uppercase.

void toupper_str(char* inString)
{
    int L = int(strlen(inString));
    for (int i = 0; i <= L; i ++)
    {
        inString[i] = toupper(inString[i]);
    }
}






//This function returns the number of letters in the c-string. It receives the c-string char and int. It uses the counting algorithm to count the number of the letters in c-string.

int numLetters(const char* inString)
{
    int i = 0;
    while (inString[i] != '\0')
    {
        i ++;
    }
    return i;
}




//SampleOutput:
/*Last index of 'o' in 'Hello World' = 7
Last index of 'l' in 'Hello World' = 9
Last index of 'A' in 'Hello World' = -1
Reverse of 'Hellot' = tolleH
2
HeLLo
1
0
1
HELLO
12
Program ended with exit code: 0*/