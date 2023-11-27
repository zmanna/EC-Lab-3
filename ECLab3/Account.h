#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>

class Account {
protected:
    std::string accountNumber;
    std::string accountHolder;
    double balance;

public:
    // Constructor
    Account(const std::string& number, const std::string& holder, double initialBalance);

    // Display basic account details
    void displayDetails() const;

    // Deposit money into the account
    void deposit(double amount);

    // Withdraw money from the account
    // Returns true if the withdrawal was successful, false otherwise
    virtual bool withdraw(double amount);

    // Display additional details for the account, if any
    virtual void displayAdditionalDetails() const = 0; // Made pure virtual to enforce implementation in derived classes

    // Get a string representing the type of account
    virtual std::string getAccountType() const = 0; // Made pure virtual to enforce implementation in derived classes

    // Overload the stream insertion operator to output account details
    friend std::ostream& operator<<(std::ostream& os, const Account& account);
};

#endif // ACCOUNT_H
