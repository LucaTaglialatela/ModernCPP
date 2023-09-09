#ifndef _SEC16_CHALLENGE_H_
#define _SEC16_CHALLENGE_H_

#include <iostream>
#include <string>
#include <vector>

// Printable Interface
class I_Printable {
    friend std::ostream &operator<<(std::ostream &os, const I_Printable &obj);

public:
    virtual void print(std::ostream &os) const = 0;
    virtual ~I_Printable() = default;
};

// Abstract Base Account class
class Account: public I_Printable {
public:
    Account(std::string name = def_name, double balance = def_balance);
    virtual bool deposit(double amount) = 0;
    virtual bool withdraw(double amount) = 0;
    virtual void print(std::ostream &os) const override;
    virtual ~Account() = default;

protected:
    std::string name;
    double balance;

private:
    static constexpr const char *def_name {"Unnamed Account"};
    static constexpr double def_balance {0.0};
};

// Derived Checkings_Account class
class Checkings_Account: public Account {
public:
    Checkings_Account(std::string name = def_name, double balance = def_balance);
    virtual bool withdraw(double amount) override;
    virtual bool deposit(double amount) override;
    virtual void print(std::ostream &os) const override;
    virtual ~Checkings_Account() = default;

protected:
    std::string name;
    double balance;

private:
    static constexpr const char *def_name {"Unnamed Checkings Account"};
    static constexpr double def_balance {0.0};
};

// Derived Savings_Account class
class Savings_Account: public Account {
public:
    Savings_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);
    virtual bool deposit(double amount) override;
    virtual bool withdraw(double amount) override;
    virtual void print(std::ostream &os) const override;
    virtual ~Savings_Account() = default;

protected:
    double int_rate;

private:
    static constexpr const char *def_name {"Unnamed Savings Account"};
    static constexpr double def_balance {0.0};
    static constexpr double def_int_rate {0.0};
};

// Derived Trust_Account class
class Trust_Account: public Savings_Account {
public:
    Trust_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);
    virtual bool deposit(double amount) override;
    virtual bool withdraw(double amount) override;
    virtual void print(std::ostream &os) const override;
    virtual ~Trust_Account() = default;

protected:
    double int_rate;
    int withdrawals;

private:
    static constexpr const char *def_name {"Unnamed Trust Account"};
    static constexpr double def_balance {0.0};
    static constexpr double def_int_rate {0.0};
};

// Utility functions
void display(const std::vector<Account *> &accounts);
void deposit(std::vector<Account *> &accounts, double amount);
void withdraw(std::vector<Account *> &accounts, double amount);

void section_16_challenge();

#endif