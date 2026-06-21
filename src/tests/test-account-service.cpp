#include <iostream>
#include "../services/AccountService.h"

// include dependencies- declarations
int main() {
    AccountService testService; // avoid new: for memory leaks

    // direct object access
    /* ========== create accounts ========== */
    testService.createAccount(1, "Jim Halpert", 1000);
    testService.createAccount(2, "Dwight Schrute", 2000);
    testService.createAccount(3, "Michael Scott", 3000);
    testService.createAccount(4, "Andy Bernard", 500);

    /* ========== deposit money ========== */
    testService.deposit(4, 500);
    testService.deposit(1, 200);

    /* ========== withdraw money ========== */
    testService.withdraw(2, 200);
    testService.withdraw(3, 200);

    /*========== transfer money ========== */
    testService.transfer(2, 3, 500);
    testService.transfer(3, 4, 300);

    /*========== getting balance ========== */
    std::cout << "User 1: " << testService.getBalance(1) << std::endl;
    std::cout << "User 2: " << testService.getBalance(2) << std::endl;
    std::cout << "User 3: " << testService.getBalance(3) << std::endl;
    std::cout << "User 4: " << testService.getBalance(4) << std::endl;

    /* ============ Generating error logs ============ */

    // transfer amount > balance
    testService.transfer(1, 2, 10000);

    // account does not exist
    testService.transfer(999, 2, 100);

    // destination account does not exist
    testService.transfer(1, 999, 100);

    // withdraw amount > balance
    testService.withdraw(1, 50000);

    // withdraw invalid account
    testService.withdraw(999, 100);

    // deposit invalid account
    testService.deposit(999, 100);

    // deposit negative amount
    testService.deposit(1, -500);

    // withdraw negative amount
    testService.withdraw(1, -500);

    /* ============ Duplicate account creation ============ */

    bool duplicateCreated =
        testService.createAccount(
            1,
            "Duplicate Jim",
            5000
        );

    std::cout
        << "\nDuplicate Account Created? "
        << duplicateCreated
        << std::endl;

    /* ========== transactions ========== */
    std::cout << "\n===== TRANSACTION HISTORY =====\n";

    auto txns = testService.getTransactions();

    for(const auto& txn : txns)
    {
        std::cout
            << "TxnId: "
            << txn.getTransactionId()
            << std::endl

            << "SourceId: "
            << txn.getSourceAccountId()
            << std::endl

            << "DestId: "
            << txn.getDestinationAccountId()
            << std::endl

            << "Type: "
            << txn.getTransactionType()
            << std::endl

            << "Status: "
            << txn.getTransactionStatus()
            << std::endl

            << "Amount: "
            << txn.getAmount()
            << std::endl

            << "Failure Reason: "
            << txn.getFailureReason()
            << std::endl;

        std::cout << "==================\n";
    }

    /* ============ Final balances after all tests ============ */

    std::cout << "\n===== FINAL BALANCES =====\n";

    std::cout << "User 1: " << testService.getBalance(1) << std::endl;
    std::cout << "User 2: " << testService.getBalance(2) << std::endl;
    std::cout << "User 3: " << testService.getBalance(3) << std::endl;
    std::cout << "User 4: " << testService.getBalance(4) << std::endl;
}