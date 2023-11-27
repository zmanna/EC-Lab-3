#include "CurrentAccount.h"
#include <iostream>

CurrentAccount::CurrentAccount(const std::string& number, const std::string& holder, double initialBalance, double limit)
    : Account(number, holder, initialBalance), overdraftLimit(limit) {}

bool CurrentAccount::withdraw(double amount) {
    // Check if the withdrawal is within the overdraft limit
    if (balance - amount >= -overdraftLimit) {
        balance -= amount;
        std::cout << "Withdrew $" << amount << " from Current Account. New balance is $" << balance << "." << std::endl;
        return true;
    } else {
        std::cout << "Withdrawal not allowed. Overdraft limit exceeded." << std::endl;
        return false;
    }
}

void CurrentAccount::displayAdditionalDetails() const {
    std::cout << "Overdraft Limit: $" << overdraftLimit << std::endl;
}

std::string CurrentAccount::getAccountType() const {
    return "Current Account";
}
