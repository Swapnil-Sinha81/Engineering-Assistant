#include "Transaction.h"

Transaction::Transaction(
    int transactionId,
    int sourceAccountId,
    int destinationAccountId,
    double amount,
    const std::string& transactionType,
    const std::string& transactionStatus,
    const std::string& failureReason
)
{
    this->transactionId = transactionId;
    this->sourceAccountId = sourceAccountId;
    this->destinationAccountId = destinationAccountId;
    this->amount = amount;

    this->transactionType = transactionType;
    this->transactionStatus = transactionStatus;
    this->failureReason = failureReason;
}

int Transaction::getTransactionId() const
{
    return transactionId;
}

int Transaction::getSourceAccountId() const
{
    return sourceAccountId;
}

int Transaction::getDestinationAccountId() const
{
    return destinationAccountId;
}

double Transaction::getAmount() const
{
    return amount;
}

std::string Transaction::getTransactionStatus() const
{
    return transactionStatus;
}

std::string Transaction::getTransactionType() const
{
    return transactionType;
}

std::string Transaction::getFailureReason() const
{
    return failureReason;
}