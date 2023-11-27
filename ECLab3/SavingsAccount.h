#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"
#include <string>

class SavingsAccount : public Account {
private:
    double interestRate; // Interest rate for the savings account

public:
    // Constructor
    SavingsAccount(const std::string& number, const std::string& holder, double initialBalance, double rate);

    // Withdraw money from the account, ensuring the balance doesn't fall below a minimum threshold
    // Returns true if the withdrawal was successful, false otherwise
    bool withdraw(double amount) override;

    // Display additional details specific to the savings account, such as the interest rate
    void displayAdditionalDetails() const override;

    // Get a string representing the type of account (Savings Account)
    std::string getAccountType() const override;
};

#endif // SAVINGSACCOUNT_H
