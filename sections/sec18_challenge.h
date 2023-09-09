/* #############################################
## Implementation found in sec16_challenge.cpp
############################################# */
#ifndef _SEC18_CHALLENGE_H_
#define _SEC18_CHALLENGE_H_

class IllegalBalanceException: public std::exception {
public:
    IllegalBalanceException() = default;
    ~IllegalBalanceException() = default;
    virtual const char *what() const noexcept;
};

class InsufficientFundsException: public std::exception {
public:
    InsufficientFundsException() = default;
    ~InsufficientFundsException() = default;
    virtual const char *what() const noexcept;
};

void section_18_challenge();

#endif