/*Anh T Nguyen 
 CIS 278 _ San Mateo Community College 
 Assignment 16*/


// This is a recursive function that has an argument that is an array of characters and two arguments that are bounds on array indices. The function reverses the order of those entries in the array whose indices are between the two bounds.



#include <iostream>
#include <string>

using namespace std;

void reverseWithinBounds(char a[], int b1, int b2);
void reverseCstring(char *a);







int main()
{
    /*char a[] = {'A', 'B', 'C', 'D', 'E'};
    cout << a << endl;
    reverseWithinBounds(a,1,4);
    cout << a << endl;*/
    
    char a[100] = "ABCDE";
    cout << "Input: " << a << endl;
    reverseCstring(a);
    cout << "Reversed: " << a << endl;
    return 0;
}






// This is to reverse an array of characters (a[]) from start position (b1) to end position (b2).
// It is a recursive function. Each step, it swap value of a[b1] with a[b2]
// pre : none
// post :a[b1] is a[b2] is swapped 

void reverseWithinBounds(char a[], int b1, int b2)
{
    if (b1 < b2) {
        // swap
        char x = a[b1];
        a[b1] = a[b2];
        a[b2] = x;
        // recurse
        reverseWithinBounds(a, b1+1, b2-1);
    }
}





// This is to reverse a C-string. It re-used the function reverseWithinBounds above.
// pre : C-String
// post : C-string reversed
void reverseCstring(char *a)
{
    int b1 = 0;
    int b2 = (int)strlen(a)-1;
    reverseWithinBounds(a, b1, b2);
}

/* output:
 Input: ABCDE
 Reversed: EDCBA
*/
