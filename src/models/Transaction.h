/*
    Transaction txn(
    101,
    2,
    3,
    500,
    "TRANSFER",
    "SUCCESS"
    );

    txn.getTransactionStatus(); -> represents one transaction
    object itself contains the state
*/

#pragma once
#include <string>

class Transaction {
private:
    // Account details
    int transactionId;
    int sourceAccountId;
    int destinationAccountId;
    double amount;

    // Transaction Info
    std::string transactionType;
    std::string transactionStatus;
    std::string failureReason;

public:
    Transaction(
        int transactionId,
        int sourceAccountId,
        int destinationAccountId,
        double amount,
        const std::string& transactionType,
        const std::string& transactionStatus,
        const std::string& failureReason
    );

    /* ======= getters declaration ======= */
    // no params need because objects handle that info
    // if managing lot of transactions, diff. class
    int getTransactionId() const;
    int getSourceAccountId() const;
    int getDestinationAccountId() const;
    double getAmount() const;
    std::string getTransactionStatus() const;
    std::string getTransactionType() const;
    std::string getFailureReason() const;
};