#include "Account.h"
#include "SavingsAccount.h"
#include "CurrentAccount.h"
#include <iostream>

// Function to transfer funds from one account to another
void transfer(Account& from, Account& to, double amount) {
    if (from.withdraw(amount)) { // Attempt to withdraw the amount from the 'from' account
        to.deposit(amount);      // Deposit the withdrawn amount into the 'to' account
    } else {
        std::cerr << "Transfer failed: insufficient funds or minimum balance requirement not met." << std::endl;
    }
}

int main() {
    SavingsAccount savings("S123", "John Doe", 1000, 0.02);
    CurrentAccount current("C456", "Jane Doe", 2000, 500);

    // Display initial details
    std::cout << "Initial account details:" << std::endl;
    savings.displayDetails();
    current.displayDetails();

    // Perform transactions
    std::cout << "\nPerforming transactions:" << std::endl;
    savings.deposit(500);
    current.withdraw(1000);

    // Display details after transactions
    std::cout << "\nAccount details after transactions:" << std::endl;
    savings.displayDetails();
    current.displayDetails();

    // Transfer 300 from savings to current
    std::cout << "\nTransferring 300 from savings to current account:" << std::endl;
    transfer(savings, current, 300);

    // Display details after transfer
    std::cout << "\nAccount details after transfer:" << std::endl;
    savings.displayDetails();
    current.displayDetails();

    // Assuming operator<< is overloaded for both account types
    std::cout << "\nFinal state of accounts:" << std::endl;
    std::cout << savings;
    std::cout << current;

    return 0;
}
