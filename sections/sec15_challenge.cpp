// #include "sec15_challenge.h"

// using namespace std;

// // Base Account class implementation
// Account::Account(string name, double balance)
//     : name {name}, balance {balance} {
// }

// bool Account::deposit(double amount) {
//     if (amount >= 0) {
//         balance += amount;
//         return true;
//     }
//     return false;
// }

// bool Account::withdraw(double amount) {
//     if (balance - amount >= 0) {
//         balance -= amount;
//         return true;
//     }
//     return false;
// }

// double Account::get_balance() const {
//     return balance;
// }

// ostream &operator<<(ostream &os, const Account &account) {
//     os << "[Account: " << account.name << ": " << account.balance << "]";
//     return os;
// }

// // Derived Checkings_Account class implementation
// Checkings_Account::Checkings_Account(string name, double balance) 
//     : Account {name, balance} {
// }

// bool Checkings_Account::withdraw(double amount) {
//     amount += 1.50;
//     return Account::withdraw(amount);
// }

// ostream &operator<<(std::ostream &os, const Checkings_Account &account) {
//     os << "[Checkings Account: " << account.name << ": " << account.balance << "]";
//     return os;
// }

// // Derived Savings_Account class implementation
// Savings_Account::Savings_Account(string name, double balance, double int_rate) 
//     : Account {name, balance}, int_rate {int_rate} {
// }

// bool Savings_Account::deposit(double amount) {
//     amount += amount * (int_rate / 100);
//     return Account::deposit(amount);
// }

// ostream &operator<<(ostream &os, const Savings_Account &account) {
//     os << "[Savings Account: " << account.name << ": " << account.balance << ": " << account.int_rate << "%]";
//     return os;
// }

// // Derived Trust_Account class implementation
// Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
//     : Savings_Account {name, balance, int_rate}, withdrawals {0} {
// }

// bool Trust_Account::deposit(double amount) {
//     return Savings_Account::deposit(amount >= 5000 ? amount + 50 : amount);
// }

// bool Trust_Account::withdraw(double amount) {
//     if ((withdrawals > 3) || (amount > balance * 0.2)) {
//         cout << "Withdrawal failed. Number of withdrawals: " << withdrawals << " and withdrawal cap: " << balance * 0.2 << endl;
//         return false;
//     }
//     else {
//         withdrawals++;
//         return Account::withdraw(amount);
//     }
// }

// ostream &operator<<(std::ostream &os, const Trust_Account &account) {
//     os << "[Trust Account: " << account.name << ": " << account.balance << ": " << account.int_rate << "%]";
//     return os;
// }

// // Utility functions
// void display(const vector<Account> &accounts) {
//     cout << "\nAccounts: " << endl;
//     for (const auto &account: accounts) {
//         cout << account << endl;
//     }
// }

// void deposit(std::vector<Account> &accounts, double amount) {
//     cout << "\nDepositing to accounts: " << endl;
//     for (auto &account: accounts) {
//         if (account.deposit(amount)) {
//             cout << "Deposited " << amount << " to " << account << endl;
//         }
//         else {
//             cout << "Failed deposit of " << amount << " to " << account << endl;
//         }
//     }
// }

// void withdraw(std::vector<Account> &accounts, double amount) {
//     cout << "\nWithdrawing from accounts: " << endl;
//     for (auto &account: accounts) {
//         if (account.withdraw(amount)) {
//             cout << "Withdrew " << amount << " from " << account << endl;
//         }
//         else {
//             cout << "Failed withdrawal of " << amount << " from " << account << endl;
//         }
//     }
// }

// void display(const vector<Checkings_Account> &accounts) {
//     cout << "\nAccounts: " << endl;
//     for (const auto &account: accounts) {
//         cout << account << endl;
//     }
// }

// void deposit(std::vector<Checkings_Account> &accounts, double amount) {
//     cout << "\nDepositing to accounts: " << endl;
//     for (auto &account: accounts) {
//         if (account.deposit(amount)) {
//             cout << "Deposited " << amount << " to " << account << endl;
//         }
//         else {
//             cout << "Failed deposit of " << amount << " to " << account << endl;
//         }
//     }
// }

// void withdraw(std::vector<Checkings_Account> &accounts, double amount) {
//     cout << "\nWithdrawing from accounts: " << endl;
//     for (auto &account: accounts) {
//         if (account.withdraw(amount)) {
//             cout << "Withdrew " << amount << " from " << account << endl;
//         }
//         else {
//             cout << "Failed withdrawal of " << amount << " from " << account << endl;
//         }
//     }
// }

// void display(const vector<Savings_Account> &accounts) {
//     cout << "\nSavings Accounts: " << endl;
//     for (const auto &account: accounts) {
//         cout << account << endl;
//     }
// }

// void deposit(std::vector<Savings_Account> &accounts, double amount) {
//     cout << "\nDepositing to accounts: " << endl;
//     for (auto &account: accounts) {
//         if (account.deposit(amount)) {
//             cout << "Deposited " << amount << " to " << account << endl;
//         }
//         else {
//             cout << "Failed deposit of " << amount << " to " << account << endl;
//         }
//     }
// }

// void withdraw(std::vector<Savings_Account> &accounts, double amount) {
//     cout << "\nWithdrawing from accounts: " << endl;
//     for (auto &account: accounts) {
//         if (account.withdraw(amount)) {
//             cout << "Withdrew " << amount << " from " << account << endl;
//         }
//         else {
//             cout << "Failed withdrawal of " << amount << " from " << account << endl;
//         }
//     }
// }

// void display(const vector<Trust_Account> &accounts) {
//     cout << "\nSavings Accounts: " << endl;
//     for (const auto &account: accounts) {
//         cout << account << endl;
//     }
// }

// void deposit(std::vector<Trust_Account> &accounts, double amount) {
//     cout << "\nDepositing to accounts: " << endl;
//     for (auto &account: accounts) {
//         if (account.deposit(amount)) {
//             cout << "Deposited " << amount << " to " << account << endl;
//         }
//         else {
//             cout << "Failed deposit of " << amount << " to " << account << endl;
//         }
//     }
// }

// void withdraw(std::vector<Trust_Account> &accounts, double amount) {
//     cout << "\nWithdrawing from accounts: " << endl;
//     for (auto &account: accounts) {
//         if (account.withdraw(amount)) {
//             cout << "Withdrew " << amount << " from " << account << endl;
//         }
//         else {
//             cout << "Failed withdrawal of " << amount << " from " << account << endl;
//         }
//     }
// }

// void section_15_challenge() {
//     cout.precision(2);
//     cout << fixed;

//     vector<Account> accounts;
//     accounts.push_back(Account {});
//     accounts.push_back(Account {"Larry"});
//     accounts.push_back(Account {"Moe", 2000});
//     accounts.push_back(Account {"Curly", 5000});

//     display(accounts);
//     deposit(accounts, 1000);
//     withdraw(accounts, 2000);

//     vector<Savings_Account> savings_accounts;
//     savings_accounts.push_back(Savings_Account {});
//     savings_accounts.push_back(Savings_Account {"Jimmy"});
//     savings_accounts.push_back(Savings_Account {"Jiminey", 2000});
//     savings_accounts.push_back(Savings_Account {"Jones", 5000, 5.0});

//     display(savings_accounts);
//     deposit(savings_accounts, 1000);
//     withdraw(savings_accounts, 2000);

//     vector<Checkings_Account> checkings_accounts;
//     checkings_accounts.push_back(Checkings_Account {});
//     checkings_accounts.push_back(Checkings_Account {"Jeb"});
//     checkings_accounts.push_back(Checkings_Account {"Job", 2000});
//     checkings_accounts.push_back(Checkings_Account {"Jib", 5000});

//     display(checkings_accounts);
//     deposit(checkings_accounts, 1000);
//     withdraw(checkings_accounts, 2000);

//     vector<Trust_Account> trust_accounts;
//     trust_accounts.push_back(Trust_Account {});
//     trust_accounts.push_back(Trust_Account {"Athos", 10000, 5.0});
//     trust_accounts.push_back(Trust_Account {"Parthinikos", 20000, 4.0});
//     trust_accounts.push_back(Trust_Account {"Ephkos Strobos", 30000});

//     display(trust_accounts);
//     deposit(trust_accounts, 1000);
//     withdraw(trust_accounts, 3000);

//     for (int i = 0; i < 5; i++) {
//         withdraw(trust_accounts, 1000);
//     }
// }
