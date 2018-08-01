// Anh T Nguyen
// Assignmnet 10_CIS 278
// San Mateo Community College
//  Created by Nguyet Anh on 11/17/17.
//  Copyright (c) 2017 Nguyet Anh NGUYEN. All rights reserved.

/* This is fraction class has objects that represent fractions. It has two data members, one to represent the numerator of the fraction being represented, and one to represent the denominator of the fraction being represented. The class has 11 member functions as described below :
 - void simplify ();
 pre: raw fractions are put in without being simplified
 post : simplified fractions
 
 - fraction (int n, int d);
 pre : numerators and denominators are integers and not negative
 post : numerator value = n, denominator value = d
 
 -fraction ()
 pre : none
 post : fraction = 0/1
 
 -int getNum() const;
 pre : numerator = n, denominator = d
 post : fraction's numerator is set with values assigned from main function
 
 -int getDen() const;
 pre : numerator = n, denominator = d
 post : fraction's numerator is set with values assigned from main function
 
 -void print () const;
 pre : numerator = n, denominator = d
 post : fraction = numerator/ denominator is printed out
 
 -fraction addedTo(fraction f)const;
 pre : numerator = n, denominator = d
 post : the sum of 2 fractions is calculated
 
 -fraction subtract(fraction f)const;
 pre : numerator = n, denominator = d
 post : the difference of 2 fractions is calculated
 
 -fraction multipliedBy(fraction f)const;
 pre : numerator = n, denominator = d
 post :the product of 2 fractions is calculated
 
 -fraction dividedBy(fraction f)const;
 pre : numerator = n, denominator = d
 post :the division of 2 fractions is calculated
 
 -bool isEqualTo (fraction f)const;
 pre : numerator = n, denominator = d
 post : The question "if the 2 fractions are equal or not" is answered
 
 */



#ifndef fraction_h
#define fraction_h

#include <iostream>
using namespace std;

class fraction
{
private:
    int num;
    int den;
    void simplify ();

public:
    fraction (int n, int d);
    fraction ();

    int getNum() const;
    int getDen() const;
    void print () const;
    fraction addedTo(fraction f)const;
    fraction subtract(fraction f)const;
    fraction multipliedBy(fraction f)const;
    fraction dividedBy(fraction f)const;
    bool isEqualTo (fraction f)const;
};
#endif

/* Sample Output : 
 
 The result starts off at 0/1
 
 The product of 9/8
 and 2/3
 is 3/4
 
 The quotient of 9/8
 and 2/3
 is 27/16
 
 The sum of 9/8
 and 2/3
 is 43/24
 
 The difference of 9/8
 and 2/3
 is 11/24
 
 The two fractions are not equal.
 The product of 12/8
 and 202/303
 is 1/1
 
 Program ended with exit code: 0
 */
