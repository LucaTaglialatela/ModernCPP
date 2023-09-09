// #ifndef _SEC15_CHALLENGE_H_
// #define _SEC15_CHALLENGE_H_

// #include <iostream>
// #include <string>
// #include <vector>

// // Base Account class
// class Account {
//     friend std::ostream &operator<<(std::ostream &os, const Account &account);

// public:
//     Account(std::string name = def_name, double balance = def_balance);
//     bool deposit(double amount);
//     bool withdraw(double amount);
//     double get_balance() const;


// protected:
//     std::string name;
//     double balance;

// private:
//     static constexpr const char *def_name {"Unnamed Account"};
//     static constexpr double def_balance {0.0};
// };

// // Derived Checkings_Account class
// class Checkings_Account: public Account {
//     friend std::ostream &operator<<(std::ostream &os, const Checkings_Account &account);

// public:
//     Checkings_Account(std::string name = def_name, double balance = def_balance);
//     bool withdraw(double amount);

// protected:
//     std::string name;
//     double balance;

// private:
//     static constexpr const char *def_name {"Unnamed Checkings Account"};
//     static constexpr double def_balance {0.0};
// };

// // Derived Savings_Account class
// class Savings_Account: public Account {
//     friend std::ostream &operator<<(std::ostream &os, const Savings_Account &account);

// public:
//     Savings_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);
//     bool deposit(double amount);

// protected:
//     double int_rate;

// private:
//     static constexpr const char *def_name {"Unnamed Savings Account"};
//     static constexpr double def_balance {0.0};
//     static constexpr double def_int_rate {0.0};
// };

// // Derived Trust_Account class
// class Trust_Account: public Savings_Account {
//     friend std::ostream &operator<<(std::ostream &os, const Trust_Account &account);

// public:
//     Trust_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);
//     bool deposit(double amount);
//     bool withdraw(double amount);

// protected:
//     double int_rate;
//     int withdrawals;

// private:
//     static constexpr const char *def_name {"Unnamed Trust Account"};
//     static constexpr double def_balance {0.0};
//     static constexpr double def_int_rate {0.0};
// };

// // Utility functions
// void display(const std::vector<Account> &accounts);
// void deposit(std::vector<Account> &accounts, double amount);
// void withdraw(std::vector<Account> &accounts, double amount);

// void display(const std::vector<Savings_Account> &accounts);
// void deposit(std::vector<Savings_Account> &accounts, double amount);
// void withdraw(std::vector<Savings_Account> &accounts, double amount);

// void section_15_challenge();

// #endif