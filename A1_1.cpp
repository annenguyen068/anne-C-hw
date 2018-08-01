/*
 Written by: Anh Nguyen 
 Assigment 1
 
 Question:
 Magic Dates
 The date June 10, 1960, is special because when we write it in the following format, the
 month times the day equals the year.
 6/10/60
 Write a program that asks the user to enter a month (in numeric form), a day, and a two digit
 year. The program should then determine whether the month times the day is equal to
 the year. If so, it should display a message saying the date is magic. Otherwise, it should
 display a message saying the date is not magic.
*/



#include <iostream>
using namespace std;

int main() {
    
    int day;
    int month;
    int year;

    cout<<"Please enter month: ";
    cin>>month;

    cout<<"Please enter day: ";
    cin>>day;
    
    cout<<"Please enter year: ";
    cin>>year;

    if(month*day==year)
    {
        cout<<"The date is magic"<<endl;
    }
    else
    {
        cout<<"The date is not magic"<<endl;
    }
}


/*
----- Output ------
 Please enter month: 6
 Please enter day: 10
 Please enter year: 60
 The date is magic
 Program ended with exit code: 0
 
 Please enter month: 6
 Please enter day: 10
 Please enter year: 70
 The date is not magic
 Program ended with exit code: 0
*/
