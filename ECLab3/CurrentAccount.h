#ifndef CURRENTACCOUNT_H
#define CURRENTACCOUNT_H

#include "Account.h"
#include <string>

class CurrentAccount : public Account {
private:
    double overdraftLimit;

public:
    // Constructor
    CurrentAccount(const std::string& number, const std::string& holder, double initialBalance, double limit);

    // Withdraw money from the account, considering the overdraft limit
    // Returns true if the withdrawal was successful, false otherwise
    bool withdraw(double amount) override;

    // Display additional details specific to the current account
    void displayAdditionalDetails() const override;

    // Get a string representing the type of account (Current Account)
    std::string getAccountType() const override;
};

#endif // CURRENTACCOUNT_H
