#include "SavingsAccount.h"
#include <iostream>
#include <iomanip>

SavingsAccount::SavingsAccount(const std::string& number, const std::string& holder, double initialBalance, double rate)
    : Account(number, holder, initialBalance), interestRate(rate) {}

bool SavingsAccount::withdraw(double amount) {
    if (balance - amount >= 100) {  // Minimum balance requirement
        balance -= amount;
        std::cout << "Withdrew $" << amount << " from Savings Account. New balance is $" << balance << "." << std::endl;
        return true;
    } else {
        std::cout << "Withdrawal not allowed. Minimum balance requirement not met." << std::endl;
        return false;
    }
}

void SavingsAccount::displayAdditionalDetails() const {
    std::cout << "Interest Rate: " << std::fixed << std::setprecision(2) << interestRate * 100 << "%" << std::endl;
}

std::string SavingsAccount::getAccountType() const {
    return "Savings Account";
}
