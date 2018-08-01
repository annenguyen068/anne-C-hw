#include <iostream>

using namespace std;


/* Anh T Nguyen
 CIS 278 _ San Mateo Community College
 Assignment 16.3*/

// This is a recursive function to sort an array of integers into ascending order. The function places the smallest element in the first position, then sorts the rest of the array by a recursive call. This is a recursive version of the selection sort.



// Function prototypes

// Find index of minimum value in an integer array a[]
int min_index(int a[], int b1, int b2);

// Recursive function to do selection sort
void arraySort(int a[], int b1, int b2);

// A define ARRAY_SIZE to calculate size of array
#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))

int main()
{
    int a[] = {3,1,6,4,10,16,5,400,20};
    int a_size = ARRAY_SIZE(a);
    arraySort(a, 0, (a_size-1));
    for (int i = 0; i < a_size; i++)
    {
        cout << a[i] << " ";
    }
    
}






// This is to find index of minimum value in an integer array a[] from index b1 to index b2
// pre: none
// post: index of minimum value of array a[b1:b2]
int min_index(int a[], int b1, int b2)
{
    int idx = b1;
    for (int i = b1 + 1; i <= b2; i++)
    {
        if (a[i] < a[idx]) idx = i;
    }
    return idx;
}







// This used selection sort algorithm, by using recursive strategy.
// Each step, it find the index of minimum value and then swap value at b1 with this min value.
// The recursive step will run for from b1+1 to b2 and so on --> finally the whole array will be sorted
// pre: none
// post: array a[] of integers is sorted
void arraySort(int a[], int b1, int b2)
{
    if (b1 < b2)
    {
        int x = a[b1];
        int min_idx = min_index(a,b1,b2);
        a[b1] = a[min_idx];
        a[min_idx] = x;
        arraySort(a, b1 + 1, b2);
    }
}


/* OUTPUT :

1 3 4 5 6 10 16 20 400 Program ended with exit code: 0
*/