// Anh T Nguyen
// Assignmnet 10_CIS 278
// San Mateo Community College
//  Created by Nguyet Anh on 11/17/17.
//  Copyright (c) 2017 Nguyet Anh NGUYEN. All rights reserved.
//

#include "fraction.h"

// The class has 1 private member function and 10 public member fuctions.

//Definition of simplify Function. This function is a private member function. It's used to reduce the calling object to lowest terms by finding common factors between denominator and numerator. It uses a for loop to continue to look for the common factors with the maximum value is the denuminator and then decrement until finding the value that is divisible by num and den.

void fraction::simplify()
{
    for (int i = den; i > 1; i--)
    {
        
        if ((num % i == 0) && (den % i == 0)) {
            
            num = num / i;
            den = den / i;
        }
    }
}







// This is a default constructor that are set to assign numerator = n and denominator = d


fraction::fraction (int n, int d)
{
    num = n;
    den = d;
}





// This is a default constructor set to assign the value 0 to the fraction it takes two parameters. The first parameter represents the initial numerator of the fraction, and the second parameter represents the initial denominator of the fraction. It assigns numerator = 0 and denominator = 1


fraction::fraction ()
{
    num = 0;
    den = 1;
}





// These functions are to set the values of the numerators and denominators of the fractions that would be assigned in the main fuction.


int fraction::getNum() const
{
        return num;
}
    
int fraction::getDen() const
{
        return den;
}





// This function is for printing out the fraction. It takes in the numerator and denominator values and prints them out in an order of a function .

void fraction::print () const

{
    cout << num << "/" << den << endl;
    
}



// Definition of Addition Function. In this fuction, fraction f is declared as a constant, the function assigns to it the result of the addition operation, and then return its simplified value.


fraction fraction::addedTo(fraction f) const

{
    int num2 = f.getDen()*num + f.getNum()*den;
    int den2 = den*f.getDen();
        
    fraction f2(num2,den2);
    f2.simplify();
    return f2;
}






// Definition of Subtraction Function. In this fuction, fraction f is declared as a constant, the function assigns to it the result of the subtraction operation, and then return its simplified value.
    
fraction fraction::subtract(fraction f) const
{
    int num2 = f.getDen()*num - f.getNum()*den;
    int den2 = den*f.getDen();
        
    fraction f2 (num2,den2);
    f2.simplify();
       
    return f2;
}






// Definition of Multiplication Function. In this fuction, fraction f is declared as a constant, the function assigns to it the result of the multiplication operation, and then return its simplified value.


fraction fraction::multipliedBy(fraction f)const
{
    int den2 = f.getDen() * den;
    int num2 = f.getNum()* num;
        
    fraction f2 (num2,den2);
    f2.simplify();
        
    return f2;
}





// Definition of division Function. In this fuction, fraction f is declared as a constant, the function assigns to it the result of the division operation, and then return its simplified value.


fraction fraction::dividedBy(fraction f)const
{
    int num2 = f.getDen() * num;
    int den2 = f.getNum()* den;
        
    fraction f2 (num2,den2);
    f2.simplify();
        
    return f2;
}






// Definition of isEqualto Function. This is a boolean operation to compares two fraction objects to determine weather the fraction objects are equals by by cross-multiplying. If numerator1 * denominator2 equals denominator1 * numerator2, then the Function returns True, else, it returns False.


bool fraction::isEqualTo (fraction f) const
{
    if (f.getNum()*den == f.getDen()*num)
        return true;
    else
        return false;
}




