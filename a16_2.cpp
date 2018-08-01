/*Anh T Nguyen
 CIS 278 _ San Mateo Community College
 Assignment 16*/





#include <cctype>
#include <iostream>
#include <string>
#include <cassert>

/* The MyString class can be used to handle constructing strings, reading/printing, and accessing characters. In addition, the MyString object will have the ability to make a full deep-copy of itself when copied.
 
 MyString();
 post: initializing MyString object with empty value
 
 MyString(const char *instr);
 post: initializing MyString object with value *instr
 
 MyString(const MyString& right)
 post:  initializing MyString object by copying from MyString right
 
 ~MyString();
 post: MyString is deleted
 
 MyString operator=(const MyString& right);
 post: overloaded operator assigned current object to the 'right'
 
 friend MyString operator+(const MyString& left, const MyString& right);
 post:  the concatenation of MyString& left and right is returned
 
 friend MyString operator+(const MyString& left, const char *right);
 post: the concatenation of MyString& left and char *right is returned
 
 friend MyString operator+(const char *left, const MyString& right);
 post: the concatenation of char* left and MyString& right is returned
 
 MyString operator+=(const MyString& right);
 post:  the concatenation of left and right is assigned to left and returned
 
 MyString operator+=(const char *right);
 post: the concatenation of left and right is assigned to left and returned
 
 
 friend ostream& operator<<(ostream& out, const MyString& source);
 pre: "out" is ready for writing.
 post: The contents of "source" have been inserted into "out".
 
 friend istream& operator>>(istream& in, MyString& target);
 pre: "in" is ready for reading.
 post: Whitespace in "in" is skipped and the following non‐whitespace characters is extracted from "in" and stored in "source". Reading is terminated by the next whitespace character.
 
 void read(istream& in, char delim);
 pre: "in" is ready for reading.
 post: Characters in "in", terminated by "delim" is extracted then stored in the object.
 
 char operator[](int index) const;
 pre: 0 <= index < length()
 post: the character at position "index" is returned.
 
 char& operator[](int index);
 pre: 0 <= index < length()
 post: The character at position "index" has been returned.
 
 int length() const;
 post: the number of characters in the object is returned.
 
 
 
 
 // compare operators, MyString vs MyString
 friend bool operator<(const MyString& left, const MyString& right);
 post: Return true if MyString& left < MyString& right, else, return false
 
 friend bool operator<=(const MyString& left, const MyString& right);
 post: Return true if MyString& left <= MyString& right, else, return false
 
 friend bool operator>(const MyString& left, const MyString& right);
 post: Return true if MyString& left > MyString& right, else, return false
 
 friend bool operator>=(const MyString& left, const MyString& right);
 post: Return true if MyString& left >= MyString& right, else, return false
 
 friend bool operator==(const MyString& left, const MyString& right);
 post: Return true if MyString& left == MyString& right, else, return false
 
 friend bool operator!=(const MyString& left, const MyString& right);
 post:Return true if MyString& left != MyString& right, else, return false
 
 
 
 
 // compare operators, MyString vs c-string
 friend bool operator<(const MyString& left, const char *right);
 post: Return true if MyString& left < char *right, else, return false
 
 friend bool operator<=(const MyString& left, const char *right);
 post: Return true if MyString& left <= char *right, else, return false
 
 friend bool operator>(const MyString& left, const char *right);
 post: Return true if MyString& left > char *right, else, return false
 
 friend bool operator>=(const MyString& left, const char *right);
 post: Return true if MyString& left >= char *right, else, return false
 
 friend bool operator==(const MyString& left, const char *right);
 post: Return true if MyString& left == char *right, else, return false
 
 friend bool operator!=(const MyString& left, const char *right);
 post:
 Return true if MyString& left == char *right, else, return false
 
 
 
 // compare operators, c-string vs MyString
 
 
 friend bool operator<(const char *left, const MyString& right);
 post: Return true if char *left < MyString& *right, else, return false
 
 friend bool operator<=(const char *left, const MyString& right);
 post: Return true if char *left <= MyString& *right, else, return false
 
 
 friend bool operator>(const char *left, const MyString& right);
 post: Return true if char *left > MyString& *right, else, return false
 
 friend bool operator>=(const char *left, const MyString& right);
 post: Return true if char *left >= MyString& *right, else, return false
 
 friend bool operator==(const char *left, const MyString& right);
 post: Return true if char *left == MyString& *right, else, return false
 
 friend bool operator!=(const char *left, const MyString& right);
 post:  Return true if char *left != MyString& *right, else, return false
 
 */




using namespace std;
class MyString {
private:
    char *mystr;
public:
    MyString();
    MyString(const char *instr);
    MyString(const MyString& right);
    ~MyString();
    MyString operator=(const MyString& right);
    
    friend MyString operator+(const MyString& left, const MyString& right);
    friend MyString operator+(const MyString& left, const char *right);
    friend MyString operator+(const char *left, const MyString& right);
    
    MyString operator+=(const MyString& right);
    MyString operator+=(const char *right);
    
    
    friend ostream& operator<<(ostream& out, const MyString& source);
    friend istream& operator>>(istream& in, MyString& target);
    void read(istream& in, char delim);
    
    char operator[](int index) const;
    char& operator[](int index);
    
    int length() const;
    
    // compare operators, MyString vs MyString
    friend bool operator<(const MyString& left, const MyString& right);
    friend bool operator<=(const MyString& left, const MyString& right);
    friend bool operator>(const MyString& left, const MyString& right);
    friend bool operator>=(const MyString& left, const MyString& right);
    friend bool operator==(const MyString& left, const MyString& right);
    friend bool operator!=(const MyString& left, const MyString& right);
    
    // compare operators, MyString vs c-string
    friend bool operator<(const MyString& left, const char *right);
    friend bool operator<=(const MyString& left, const char *right);
    friend bool operator>(const MyString& left, const char *right);
    friend bool operator>=(const MyString& left, const char *right);
    friend bool operator==(const MyString& left, const char *right);
    friend bool operator!=(const MyString& left, const char *right);
    
    // compare operators, c-string vs MyString
    friend bool operator<(const char *left, const MyString& right);
    friend bool operator<=(const char *left, const MyString& right);
    friend bool operator>(const char *left, const MyString& right);
    friend bool operator>=(const char *left, const MyString& right);
    friend bool operator==(const char *left, const MyString& right);
    friend bool operator!=(const char *left, const MyString& right);
};

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





istream& operator>>(istream& in, MyString& target)
{
    while (isspace(in.peek()))
    {
        in.ignore();
    }
    char temp[128];
    in.getline(temp, 127, ' ');
    delete [] target.mystr;
    target.mystr = new char[strlen(temp) + 1];
    strcpy(target.mystr, temp);
    return in;
}





void MyString::read(istream& in, char delim)
{
    char temp[128];
    in.getline(temp, 127, delim);
    delete [] mystr;
    mystr = new char[strlen(temp) + 1];
    strcpy(mystr, temp);
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







//concat operators
MyString operator+(const MyString& left, const MyString& right)
{
    MyString tmp;
    tmp.mystr = new char[strlen(left.mystr) + strlen(right.mystr) + 1];
    strcpy(tmp.mystr, left.mystr);
    strcat(tmp.mystr, right.mystr);
    return tmp;
}





MyString operator+(const MyString& left, const char *right)
{
    MyString tmp(right);
    return left+tmp;
}






MyString operator+(const char *left, const MyString& right)
{
    MyString tmp(left);
    return tmp+right;
}






MyString MyString::operator+=(const MyString& right)
{
    *this = *this + right;
    return *this;
}






MyString MyString::operator+=(const char *right)
{
    MyString tmp(right);
    *this = *this + tmp;
    return *this;
}


//*********************************************
// MAIN RUN
//*********************************************
/*This is the program that reads in any number of MyStrings of characters from the user and determines if each MyString is a palindrome. The program will prompt the user to enter a string. Then it uses a loop and a sub-function to check if the string entered in is a Palindrome or not. The user will terminate each MyString by pressing the return (or enter) button. The user will indicate that there are no more MyStrings by entering "quit" */


// This is the prototype of the program

bool isAPalindrome(const MyString mystr, int b1, int b2);





// This is the main function of the program

int main() {
    MyString mystr("s");
    while (mystr != "quit")
    {
        cout << "Enter a string: ";
        mystr.read(cin, '\n');
        if (isAPalindrome(mystr, 0, mystr.length() - 1)) {
            cout << mystr << " is a palindrome." << endl;
        } else {
            cout << mystr << " is not a palindrome." << endl;
        }
    }
    cout << "Bye!";
}







// This bool function is used to test if MyString is a palindrome or not. This function takes 3 inputs: a MyString object mystr, start position of mystr (b1), end position of mystr (b2). This is a recursive function. The base step is to check if b1>=b2 --> true, mystr[b1] != mystr[b2]-->false. It ignores punctuations and white spaces.
//pre: none
//post: returns true if mystr is a palindrome

bool isAPalindrome(const MyString mystr, int b1, int b2)
{
    if (b1 >= b2)
        return true;
    if (ispunct(mystr[b1]) || isspace(mystr[b1]))
        return isAPalindrome(mystr, b1 + 1, b2);
    if (ispunct(mystr[b2]) || isspace(mystr[b2]))
        return isAPalindrome(mystr, b1, b2 - 1);
    if (toupper(mystr[b1]) != toupper(mystr[b2]))
        return false;
    return isAPalindrome(mystr, b1 + 1, b2 - 1);
}






/* OUTPUT
 Enter a string: Able was I, ere I saw Elba
 Able was I, ere I saw Elba is a palindrome.
 Enter a string: peanut butter
 peanut butter is not a palindrome.
 Enter a string: quit
 quit is not a palindrome.
 Bye!Program ended with exit code: 0
 */
