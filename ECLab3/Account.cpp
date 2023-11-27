#include "Account.h"
#include <iostream>

Account::Account(const std::string& number, const std::string& holder, double initialBalance)
    : accountNumber(number), accountHolder(holder), balance(initialBalance) {}

void Account::displayDetails() const {
    std::cout << "Account Number: " << accountNumber << std::endl;
    std::cout << "Account Holder: " << accountHolder << std::endl;
    std::cout << "Account Balance: $" << balance << std::endl;
    displayAdditionalDetails();
}

void Account::deposit(double amount) {
    balance += amount;
    std::cout << "Deposited $" << amount << ". New balance is $" << balance << "." << std::endl;
}

bool Account::withdraw(double amount) {
    if (amount <= balance) {
        balance -= amount;
        std::cout << "Withdrew $" << amount << ". New balance is $" << balance << "." << std::endl;
        return true;
    } else {
        std::cout << "Withdrawal failed: Insufficient funds." << std::endl;
        return false;
    }
}

void Account::displayAdditionalDetails() const {
    // Implement additional details specific to the account if any.
}

std::string Account::getAccountType() const {
    return "General Account";
}

std::ostream& operator<<(std::ostream& os, const Account& account) {
    os << "Account Number: " << account.accountNumber << std::endl;
    os << "Account Holder: " << account.accountHolder << std::endl;
    os << "Account Balance: $" << account.balance << std::endl;
    account.displayAdditionalDetails();
    return os;
}

