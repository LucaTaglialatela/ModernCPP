#include "sec4_challenge.h"
#include <iostream>

using namespace std;

void section_4_challenge() {
    int number;

    cout << "Enter your favourite number between 1 and 100: ";
    
    cin >> number;

    cout << "Amazing that's my favourite number too."  << endl;
    cout << "No really, " << number << " is my favourite number too." << endl;

    return;
}