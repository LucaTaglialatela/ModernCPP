#include <iostream>
#include <cstring>

#include "sec14_challenge.h"

 // No-args constructor
MyString::MyString() 
    : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
MyString::MyString(const char *s) 
    : str {nullptr} {
        if (s==nullptr) {
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[strlen(s)+1];
            strcpy(str, s);
        }
}

// Copy constructor
MyString::MyString(const MyString &source) 
    : str{nullptr} {
        str = new char[strlen(source.str)+ 1];
        strcpy(str, source.str);
 //       std::cout << "Copy constructor used" << std::endl;

}

// Move constructor
MyString::MyString( MyString &&source) 
    :str(source.str) {
        source.str = nullptr;
//        std::cout << "Move constructor used" << std::endl;
}

 // Destructor
MyString::~MyString() {
    delete [] str;
}

// Section 14 challenge class implementation
ostream &operator<<(ostream &os, const MyString &rhs) {
    os << rhs.str;
    return os;
};

istream &operator>>(istream &is, MyString &rhs) {
    char *buff = new char[1000];
    is >> buff;
    rhs = MyString {buff};
    delete [] buff;
    return is;
};

// Overloaded Copy
MyString &MyString::operator=(const MyString &rhs) {
    if (this == &rhs) { return *this; }
    delete this->str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(this->str, rhs.str);
    return *this;
};

// Overloaded Move
MyString &MyString::operator=(MyString &&rhs) {
    if (this == &rhs) { return *this; }
    delete this->str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
};

// Overloaded Unary -
MyString MyString::operator-() const {
    char *buff = new char[strlen(str) + 1];
    strcpy(buff, str);
    for (size_t i = 0; i < strlen(str); i++) {
        buff[i] = tolower(buff[i]);
    }
    MyString res {buff};
    delete [] buff;
    return res;
};

// Overloaded ==
bool MyString::operator==(const MyString &rhs) const {
    return strcmp(str, rhs.str) == 0;
};

// Overloaded !=
bool MyString::operator!=(const MyString &rhs) const {
    return strcmp(str, rhs.str) != 0;
};

// Overloaded <
bool MyString::operator<(const MyString &rhs) const {
    return strcmp(str, rhs.str) < 0;
};

// Overloaded >
bool MyString::operator>(const MyString &rhs) const {
    return strcmp(str, rhs.str) > 0;
};

// Overloaded +
MyString MyString::operator+(const MyString &rhs) const {
    char *buff = new char[strlen(str) + strlen(rhs.str) + 1];
    strcpy(buff, str);
    strcat(buff, rhs.str);
    MyString res {buff};
    delete [] buff;
    return res;
};

// Overloaded +=
MyString MyString::operator+=(const MyString &rhs) {
    *this = *this + rhs;
    return *this;
};

// Overloaded *
MyString MyString::operator*(const int n) const {
    char *buff = new char[strlen(str) * n + 1];
    strcpy(buff, str);
    for (int i = 1; i < n; i++) {
        strcat(buff, str);
    }
    MyString res {buff};
    delete [] buff;
    return res;
};

// Overloaded *=
MyString MyString::operator*=(const int n) {
    *this = *this * n;
    return *this;
};

void section_14_challenge() {
    MyString a {"Alpha"};
    MyString b {"Beta"};

    cout << (a == b) << endl;
    cout << (a != b) << endl;
    cout << (a < b) << endl;
    cout << (a > b) << endl;
    
    MyString c {"GAMMA"};
    cout << (-c) << endl;

    cout << (a + b) << endl;

    cout << (a * 3) << endl;
}
