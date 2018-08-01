/* Anh T Nguyen
 CIS 278 _ San Mateo Community College
 Assignment 12 */

#include "fraction.h"

namespace cs_Fraction
{
    /*This simplify function is a private member function. First of all, if the denominator is negative, it will multiply the denominator and numerator with -1. After that, It reduces the calling object to lowest terms by finding common factors between denominator and numerator. Then, It uses a for loop to continue to look for the common factors with the maximum value is the denuminator and then decrement until finding the value that is divisible by num and den.*/
    
    void Fraction::simplify()
    {
        if (this->den < 0)
        {
            this->den = -1 * this->den;
            this->num = -1 * this->num;
        }
        for (int i = this->den; i > 1; i--)
        {
            if ((this->num % i == 0) && (this->den % i == 0))
            {
                this->num = this->num / i;
                this->den = this->den / i;
            }
        }
    }


    ostream& operator<<(ostream& out, const Fraction& f)
    {
        int div = f.num/f.den;
        int mod = f.num % f.den;
        if (div == 0)
            out << mod << "/" << f.den;
        else
            out << div << "+" << mod << "/" << f.den;
        return out;
    }
    
    istream& operator>>(istream& in,Fraction& right)
    {
        int temp = 0;
        in >> right.num;
        if (in.peek() == '+')
        {
            temp = right.num;
            in.ignore();
            in >> right.num;
        }
        else if (in.peek() == '/')
        {
            in.ignore();
            in >> right.den;
            
        }
        else
        {
            right.den = 1;
        }
        
        if (temp >= 0)
        {
            right.num = temp * right.den + right.num;
        }
        else
        {
            right.num = -( abs(temp) * right.den + right.num);
        }
        right.simplify();
        return in;
    }

    Fraction::Fraction (int n, int d)
    {
        assert(d != 0);
        if (n == 0) d = 1;
        num = n;
        den = d;
        simplify();
    }
    bool operator<(const Fraction& f1, const Fraction& f2)
    {
        if (f1.num*f2.den<f1.den*f2.num)
            return true;
        else
            return false;
        
    }

    bool operator<=(const Fraction& f1, const Fraction& f2)
    {
        if (f1.num*f2.den<=f1.den*f2.num)
            return true;
        else
            return false;
        
    }
    bool operator>(const Fraction& f1, const Fraction& f2)
    {
        if (f1.num*f2.den>f1.den*f2.num)
            return true;
        else
            return false;
    }

    bool operator>=(const Fraction& f1, const Fraction& f2)
    {
        if (f1.num*f2.den>=f1.den*f2.num)
            return true;
        else
            return false;
    }


    bool operator==(const Fraction& f1, const Fraction& f2)
    {
        if (f1.num*f2.den==f1.den*f2.num)
            return true;
        else
            return false;
    }

    bool operator!=(const Fraction& f1, const Fraction& f2)
    {
        if (f1.num*f2.den==f1.den*f2.num)
            return true;
        else
            return false;
    }


    Fraction operator+(const Fraction& f1, const Fraction& f2)
    {
        int n = f1.den*f2.num + f1.num*f2.den;
        int d = f1.den * f2.den;
        Fraction result = Fraction(n = n, d = d);
        return result;
    }

    Fraction operator-(const Fraction& f1, const Fraction& f2)
    {
        int n = f1.den*f2.num - f1.num*f2.den;
        int d = f1.den * f2.den;
        Fraction result = Fraction(n = n, d = d);
        return result;
    }


    Fraction operator*(const Fraction& f1, const Fraction& f2)
    {
        int n = f1.num*f2.num;
        int d = f1.den*f2.den;
        Fraction result = Fraction(n = n, d = d);
        return result;
        
    }

    Fraction operator/(const Fraction& f1, const Fraction& f2)
    {
        int n = f1.num*f2.den;
        int d = f1.den*f2.num;
        Fraction result = Fraction(n = n, d = d);
        return result;
        
    }


    Fraction Fraction::operator+=(const Fraction& f)
    {
        num = f.den*num + f.num*den;
        den = den * f.den;
        simplify();
        return *this;
    }



    Fraction Fraction::operator-=(const Fraction& f)
    {
        num = f.den*num - f.num*den;
        den = den * f.den;
        simplify();
        return *this;
    }

    Fraction Fraction::operator*=(const Fraction& f)
    {
        num = f.num*num;
        den = f.den*den;
        simplify();
        return *this;
    }

    Fraction Fraction::operator/=(const Fraction& f)
    {
        num = f.num*den;
        den = f.den*num;
        simplify();
        return *this;
    }

    Fraction Fraction:: operator++()
    {
        num = num+den;
        den = den*1;
        simplify();
        return *this;
    }

    Fraction Fraction:: operator--()
    {
        num = num-den;
        den = den*1;
        simplify();
        return *this;
    }

    Fraction Fraction:: operator++(int k)
    {
        num = num+ (k*den);
        den = den*1;
        simplify();
        return *this;
        
    }

    Fraction Fraction::operator--(int k)
    {
        num = num -(k*den);
        den = den*1;
        simplify();
        return *this;
    }
}
