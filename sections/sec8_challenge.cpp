#include "sec8_challenge.h"
#include <iostream>

using namespace std;

void section_8_challenge() {
    const int dollar_val {100};
    const int quarter_val {25};
    const int dime_val {10};
    const int nickel_val {5};
    int amount, dollars, quarters, dimes, nickels, pennies;
    amount = dollars = quarters = dimes = nickels = pennies = 0;

    cout << "Please enter an amount of cents: " << endl;
    cin >> amount;

    dollars = amount / dollar_val;
    amount %= dollar_val;

    quarters = amount / quarter_val;
    amount %= quarter_val;

    dimes = amount / dime_val;
    amount %= dime_val;

    nickels = amount / nickel_val;
    amount %= nickel_val;

    pennies = amount;

    cout << "You can provide change as follows:" << endl;
    cout << "Dollars: " << dollars << endl;
    cout << "Quarters: " << quarters << endl;
    cout << "Dimes: " << dimes << endl;
    cout << "Nickels: " << nickels << endl;
    cout << "Pennies: " << amount << endl;

    return;
}