#include "sec16_challenge.h"
#include "sec18_challenge.h"
#include <memory>

using namespace std;

// Implementation of section 18 exception classes
const char *IllegalBalanceException::what() const noexcept {
    return "Illegal balance exception";
}

const char *InsufficientFundsException::what() const noexcept {
    return "Insufficient funds exception";
}

// Printable Interface implementation
ostream &operator<<(ostream &os, I_Printable &obj) {
    obj.print(os);
    return os;
}

// Base Account class implementation
Account::Account(string name, double balance)
    : name {name}, balance {balance} {
        if (balance < 0.0) {
            throw IllegalBalanceException();
        }
}

bool Account::deposit(double amount) {
    if (amount >= 0) {
        balance += amount;
        return true;
    }
    return false;
}

bool Account::withdraw(double amount) {
    if (balance - amount >= 0) {
        balance -= amount;
        return true;
    }
    throw InsufficientFundsException();
    return false;
}

void Account::print(std::ostream &os) const {
    os.precision(2);
    os << fixed;
    os << "[Account: " << name << ": " << balance << "]";
}

// Derived Checkings_Account class implementation
Checkings_Account::Checkings_Account(string name, double balance) 
    : Account {name, balance} {
}

bool Checkings_Account::withdraw(double amount) {
    amount += 1.50;
    return Account::withdraw(amount);
}

bool Checkings_Account::deposit(double amount) {
    return Account::deposit(amount);
}

void Checkings_Account::print(std::ostream &os) const {
    os.precision(2);
    os << fixed;
    os << "[Checkings Account: " << name << ": " << balance << "]";
}

// Derived Savings_Account class implementation
Savings_Account::Savings_Account(string name, double balance, double int_rate) 
    : Account {name, balance}, int_rate {int_rate} {
}

bool Savings_Account::deposit(double amount) {
    amount += amount * (int_rate / 100);
    return Account::deposit(amount);
}

bool Savings_Account::withdraw(double amount) {
    return Account::withdraw(amount);
}

void Savings_Account::print(std::ostream &os) const {
    os.precision(2);
    os << fixed;
    os << "[Savings Account: " << name << ": " << balance << ": " << int_rate << "%]";
}

// Derived Trust_Account class implementation
Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
    : Savings_Account {name, balance, int_rate}, withdrawals {0} {
}

bool Trust_Account::deposit(double amount) {
    return Savings_Account::deposit(amount >= 5000 ? amount + 50 : amount);
}

bool Trust_Account::withdraw(double amount) {
    if ((withdrawals > 3) || (amount > balance * 0.2)) {
        cout << "Withdrawal failed. Number of withdrawals: " << withdrawals << " and withdrawal cap: " << balance * 0.2 << endl;
        return false;
    }
    else {
        withdrawals++;
        return Account::withdraw(amount);
    }
}

void Trust_Account::print(std::ostream &os) const {
    os.precision(2);
    os << fixed;
    os << "[Trust Account: " << name << ": " << balance << ": " << int_rate << "% : " << withdrawals << "]";
}

// Utility functions
void display(const vector<Account *> &accounts) {
    cout << "\nAccounts: " << endl;
    for (const auto account: accounts) {
        cout << *account << endl;
    }
}

void deposit(std::vector<Account *> &accounts, double amount) {
    cout << "\nDepositing to accounts: " << endl;
    for (auto account: accounts) {
        if (account->deposit(amount)) {
            cout << "Deposited " << amount << " to " << *account << endl;
        }
        else {
            cout << "Failed deposit of " << amount << " to " << *account << endl;
        }
    }
}

void withdraw(std::vector<Account *> &accounts, double amount) {
    cout << "\nWithdrawing from accounts: " << endl;
    for (auto account: accounts) {
        if (account->withdraw(amount)) {
            cout << "Withdrew " << amount << " from " << *account << endl;
        }
        else {
            cout << "Failed withdrawal of " << amount << " from " << *account << endl;
        }
    }
}

void section_16_challenge() {
    Account *p1 = new Checkings_Account("Jim", 10000);
    Account *p2 = new Savings_Account("Jiminey", 1000);
    Account *p3 = new Trust_Account("Jones");

    vector<Account *> accounts {p1, p2, p3};

    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts, 2000);
    display(accounts);
}

void section_18_challenge() {
    unique_ptr<Account> jimini_acc;
    unique_ptr<Account> jones_acc;

    try {
        jimini_acc = make_unique<Savings_Account> ("Jimini", -2000);
        cout << *jimini_acc << endl;
    }
    catch (const IllegalBalanceException &ex) {
        cerr << ex.what() << endl;
    }

    try {
        jones_acc = make_unique<Savings_Account> ("Jones", 1000);
        cout << *jones_acc << endl;
        jones_acc->withdraw(500);
        cout << *jones_acc << endl;
        jones_acc->withdraw(1000);
        cout << *jones_acc << endl;
    }
    catch (const IllegalBalanceException &ex) {
        cerr << ex.what() << endl;
    }
    catch (const InsufficientFundsException &ex) {
        cerr << ex.what() << endl;
    }
}
