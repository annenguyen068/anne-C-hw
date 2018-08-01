/* Anh T Nguyen 
CIS 278 _ San Mateo Community College
Assignment 12 */


#ifndef fraction_h
#define fraction_h

#include <iostream>
#include <string>
#include <cassert>


// This fraction class can be used to represent numbers that can be expressed as the ratio of two integers, that is, rational numbers or "fraction"s.
/* 
 
 Fraction (int n=0, int d=1);
 post: A fraction with numerator equal to inNum and denominator equal to inDen has been created.
 
 void Fraction::simplify()
 post : non-negative denominators, fractions reduced to the lowest terms.

friend ostream& operator<<(ostream& out, const Fraction& f);
 post: The fraction source has been inserted into the ostream out. If the value of source is a mixed number, a '+' has been inserted between the whole number part and the fraction part. Use a '/' to separate the numerator from the denominator of the fraction.
 
 
 friend istream& operator>>(istream& in,Fraction& right)
 pre: The istream object in is ready for reading.
 post: The fraction in the istream in has been read and assigned to the fraction right.
 
 
friend bool operator<(const Fraction& f1, const Fraction& f2);
  post: Returns true if f1 < f2, else, returns false.
 
friend bool operator<=(const Fraction& f1, const Fraction& f2);
  post: Returns true if f1 <= f2, else, returns false.
 
friend bool operator>(const Fraction& f1, const Fraction& f2);
  post: Returns true if f1 > f2, else, returns false.
 
friend bool operator>=(const Fraction& f1, const Fraction& f2);
  post: Returns true if f1 >= f2, else, returns false.
 
friend bool operator==(const Fraction& f1, const Fraction& f2);
  post: Returns true if f1 == f2, else, returns false.
 
friend bool operator!=(const Fraction& f1, const Fraction& f2);
  post: Returns true if f1 != f2, else, returns false.
 
friend Fraction operator+(const Fraction& f1, const Fraction& f2);
  post: Returns the sum f1 + f2.
 
friend Fraction operator-(const Fraction& f1, const Fraction& f2);
 post: Returns the difference of f1 - f2.
 
friend Fraction operator*(const Fraction& f1, const Fraction& f2);
 post: Returns the product of f1 * f2.
 
friend Fraction operator/(const Fraction& f1, const Fraction& f2);
 post: Returns the result of f1/ f2.
 
Fraction operator+=(const Fraction& f);
 post: calculate the sum of the calling object and f; then returns the result.
 
Fraction operator-=(const Fraction& f);
 post: calculate the difference of the calling object and f;then returns the result.
 
Fraction operator*=(const Fraction& f);
 post: calculate the product of the calling object and f;then returns the result.
 
Fraction operator/=(const Fraction& f);
 post : calculate the quotient of the calling object and f;then returns the result.
 
Fraction operator++();
  Post : Adds one to the calling object. Returns the result .
 
Fraction operator--();
 Post : Substract one from the calling object. Returns the result .
 
Fraction operator++(int k);
 Post : Adds one to the calling object but then returns the original value of the calling object.
Fraction operator--(int k);
 Post :  Subtracts one from the calling object but then returns the original value of the calling object.
*/
using namespace std;
namespace cs_Fraction
{
    
    class Fraction
    {
    private:
        int num;
        int den;
        void simplify();

    public:
        Fraction (int n=0, int d=1);
        friend ostream& operator<<(ostream& out, const Fraction& f);
        friend istream& operator>>(istream& in,Fraction& right);
        friend bool operator<(const Fraction& f1, const Fraction& f2);
        friend bool operator<=(const Fraction& f1, const Fraction& f2);
        friend bool operator>(const Fraction& f1, const Fraction& f2);
        friend bool operator>=(const Fraction& f1, const Fraction& f2);
        friend bool operator==(const Fraction& f1, const Fraction& f2);
        friend bool operator!=(const Fraction& f1, const Fraction& f2);
        friend Fraction operator+(const Fraction& f1, const Fraction& f2);
        friend Fraction operator-(const Fraction& f1, const Fraction& f2);
        friend Fraction operator*(const Fraction& f1, const Fraction& f2);
        friend Fraction operator/(const Fraction& f1, const Fraction& f2);
        Fraction operator+=(const Fraction& f);
        Fraction operator-=(const Fraction& f);
        Fraction operator*=(const Fraction& f);
        Fraction operator/=(const Fraction& f);
        Fraction operator++();
        Fraction operator--();
        Fraction operator++(int k);
        Fraction operator--(int k);
    };
}
#endif


/*Sample Output :
 
 
 ----- Testing basic Fraction creation & printing
 (Fractions should be in reduced form, and as mixed numbers.)
 Fraction [0] = 1/2
 Fraction [1] = -5/7
 Fraction [2] = 10+0/1
 Fraction [3] = -4+0/1
 Fraction [4] = 0/1
 Fraction [5] = 4+2/3
 Fraction [6] = 0/1
 
 ----- Now reading Fractions from file
 Read Fraction = 1/3
 Read Fraction = 1/2
 Read Fraction = 3/4
 Read Fraction = -4/5
 Read Fraction = 6+0/1
 Read Fraction = 5+0/1
 Read Fraction = -8+0/1
 Read Fraction = 1+2/5
 Read Fraction = -16+-2/3
 Read Fraction = 2+0/1
 Read Fraction = 0/1
 
 ----- Testing relational operators between Fractions
 Comparing 1/2 to 1/2
	Is left < right? false
	Is left <= right? true
	Is left > right? false
	Is left >= right? true
	Does left == right? true
	Does left != right ? true
 Comparing 1/2 to -1/2
	Is left < right? false
	Is left <= right? false
	Is left > right? true
	Is left >= right? true
	Does left == right? false
	Does left != right ? false
 Comparing -1/2 to 1/10
	Is left < right? true
	Is left <= right? true
	Is left > right? false
	Is left >= right? false
	Does left == right? false
	Does left != right ? false
 Comparing 1/10 to 0/1
	Is left < right? false
	Is left <= right? false
	Is left > right? true
	Is left >= right? true
	Does left == right? false
	Does left != right ? false
 Comparing 0/1 to 0/1
	Is left < right? false
	Is left <= right? true
	Is left > right? false
	Is left >= right? true
	Does left == right? true
	Does left != right ? true
 
 ----- Testing relations between Fractions and integers
 Comparing -1/2 to 2
	Is left < right? true
	Is left <= right? true
	Is left > right? false
	Is left >= right? false
	Does left == right? false
	Does left != right ? false
 Comparing -3 to 1/4
	Is left < right? true
	Is left <= right? true
	Is left > right? false
	Is left >= right? false
	Does left == right? false
	Does left != right ? false
 
 ----- Testing binary arithmetic between Fractions
 1/6 + 1/3 = 1/2
 1/6 - 1/3 = 1/6
 1/6 * 1/3 = 1/18
 1/6 / 1/3 = 1/2
 1/3 + -2/3 = -1/3
 1/3 - -2/3 = -1+0/1
 1/3 * -2/3 = -2/9
 1/3 / -2/3 = -1/2
 -2/3 + 5+0/1 = 4+1/3
 -2/3 - 5+0/1 = 5+2/3
 -2/3 * 5+0/1 = -3+-1/3
 -2/3 / 5+0/1 = -2/15
 5+0/1 + -1+-1/3 = 3+2/3
 5+0/1 - -1+-1/3 = -6+-1/3
 5+0/1 * -1+-1/3 = -6+-2/3
 5+0/1 / -1+-1/3 = -3+-3/4
 
 ----- Testing arithmetic between Fractions and integers
 -1/2 + 4 = 3+1/2
 -1/2 - 4 = 4+1/2
 -1/2 * 4 = -2+0/1
 -1/2 / 4 = -1/8
 3 + -1/2 = 2+1/2
 3 - -1/2 = -3+-1/2
 3 * -1/2 = -1+-1/2
 3 / -1/2 = -6+0/1
 
 ----- Testing shorthand arithmetic assignment on Fractions
 1/6 += 4+0/1 = 4+1/6
 4+1/6 -= 4+0/1 = 1/6
 1/6 *= 4+0/1 = 2/3
 2/3 /= 4+0/1 = 1+0/1
 4+0/1 += -1/2 = 3+1/2
 3+1/2 -= -1/2 = 4+0/1
 4+0/1 *= -1/2 = -2+0/1
 -2+0/1 /= -1/2 = 1/2
 -1/2 += 5+0/1 = 4+1/2
 4+1/2 -= 5+0/1 = -1/2
 -1/2 *= 5+0/1 = -2+-1/2
 -2+-1/2 /= 5+0/1 = 1+0/1
 
 ----- Testing shorthand arithmetic assignment using integers
 -1/3 += 3 = 2+2/3
 2+2/3 -= 3 = -1/3
 -1/3 *= 3 = -1+0/1
 -1+0/1 /= 3 = 1+0/1
 
 ----- Testing increment/decrement prefix and postfix
 Now g = -1/3
 g++ = -1/3
 Now g = -1/3
 ++g = 2/3
 Now g = 2/3
 g-- = 2/3
 Now g = 2/3
 --g = -1/3
 Now g = -1/3
 Program ended with exit code: 0 */
