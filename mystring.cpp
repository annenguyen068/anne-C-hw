/*Anh T Nguyen 
 CIS 278 _ San Mateo Community College 
 Assignment 13 */


#include "MyString.h"
using namespace std;
namespace cs_mystring
{
    MyString::MyString()
    {
        mystr = new char[1];
        strcpy(mystr, "");
    }

    MyString::MyString(const char *instr)
    {
        mystr = new char[strlen(instr) + 1];
        strcpy(mystr, instr);
    }

    MyString::MyString(const MyString& right)
    {
        mystr = new char[strlen(right.mystr) + 1];
        strcpy(mystr, right.mystr);
    }

    MyString::~MyString()
    {
        delete [] mystr;
    }

    int MyString::length() const
    {
        return (int)strlen(mystr);
    }

    ostream& operator<<(ostream& out, const MyString& source)
    {
        out << source.mystr;
        return out;
    }
    
    MyString MyString::operator=(const MyString& right)
    {
        if (this != &right){
            delete [] mystr;
            mystr = new char[strlen(right.mystr) + 1];
            strcpy(mystr, right.mystr);
        }
        return *this;
    }
    
    char MyString::operator[](int index) const
    {
        assert(index >= 0 && index < strlen(mystr));
        return mystr[index];
    }

    char& MyString::operator[](int index)
    {
        assert(index >= 0 && index < strlen(mystr));
        return mystr[index];
    }
    
    // compare operators, MyString vs MyString
    bool operator<(const MyString& left, const MyString& right)
    {
        return strcmp(left.mystr, right.mystr) < 0;
    }

    bool operator<=(const MyString& left, const MyString& right)
    {
        return strcmp(left.mystr, right.mystr) <= 0;
    }
    
    bool operator>(const MyString& left, const MyString& right)
    {
        return strcmp(left.mystr, right.mystr) > 0;
    }

    bool operator>=(const MyString& left, const MyString& right)
    {
        return strcmp(left.mystr, right.mystr) >= 0;
    }
    
    bool operator==(const MyString& left, const MyString& right)
    {
        return strcmp(left.mystr, right.mystr) == 0;
    }
    
    bool operator!=(const MyString& left, const MyString& right)
    {
        return strcmp(left.mystr, right.mystr) != 0;
    }
    
    
    // compare operators, MyString vs c-string
    bool operator<(const MyString& left, const char *right)
    {
        return strcmp(left.mystr, right) < 0;
    }
    bool operator<=(const MyString& left, const char *right)
    {
        return strcmp(left.mystr, right) <= 0;
    }
    bool operator>(const MyString& left, const char *right)
    {
        return strcmp(left.mystr, right) > 0;
    }
    bool operator>=(const MyString& left, const char *right)
    {
        return strcmp(left.mystr, right) >= 0;
    }
    bool operator==(const MyString& left, const char *right)
    {
        return strcmp(left.mystr, right) == 0;
    }
    bool operator!=(const MyString& left, const char *right)
    {
        return strcmp(left.mystr, right) != 0;
    }
    
    // compare operators, c-string vs MyString
    bool operator<(const char *left, const MyString& right)
    {
        return strcmp(left, right.mystr) < 0;
    }
    bool operator<=(const char *left, const MyString& right)
    {
        return strcmp(left, right.mystr) <= 0;
    }
    bool operator>(const char *left, const MyString& right)
    {
        return strcmp(left, right.mystr) > 0;
    }
    bool operator>=(const char *left, const MyString& right)
    {
        return strcmp(left, right.mystr) >= 0;
    }
    bool operator==(const char *left, const MyString& right)
    {
        return strcmp(left, right.mystr) == 0;
    }
    bool operator!=(const char *left, const MyString& right)
    {
        return strcmp(left, right.mystr) != 0;
    }
    
}

