#ifndef _MYSTRING_H_
#define _MYSTRING_H_

using namespace std;

// Section 14 challenge classes
class MyString {
    friend ostream &operator<<(ostream &os, const MyString &rhs);
    friend istream &operator>>(istream &is, const MyString &rhs);

private:
    char *str;

public:
    MyString();
    MyString(const char *s);
    MyString(const MyString &source);
    MyString(MyString &&source);
    ~MyString();

    // Overloaded Copy
    MyString &operator=(const MyString &rhs);

    // Overloaded Move
    MyString &operator=(MyString &&rhs);

    // Overloaded Unary -
    MyString operator-() const;

    // Overloaded ==
    bool operator==(const MyString &rhs) const;

    // Overloaded !=
    bool operator!=(const MyString &rhs) const;

    // Overloaded <
    bool operator<(const MyString &rhs) const;
    
    // Overloaded >
    bool operator>(const MyString &rhs) const;

    // Overloaded +
    MyString operator+(const MyString &rhs) const;
    
    // Overloaded +=
    MyString operator+=(const MyString &rhs);
    
    // Overloaded *
    MyString operator*(const int n) const;
    
    // Overloaded *=
    MyString operator*=(const int n);

    // void display() const;

    // int getLength() const;

    // const char *get_string() const;
};

void section_14_challenge();

#endif // _MYSTRING_H_
