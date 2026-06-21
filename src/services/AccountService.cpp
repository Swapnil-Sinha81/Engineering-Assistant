/* manager of accounts where Account is the actual entity */
#include "AccountService.h"

/* ========== map: place individual accounts ==========*/
bool AccountService::createAccount(
    int id,
    const std::string& name,
    double balance
) {
    auto result =
        accounts.emplace(
            id,
            Account(id, name, balance)
        );

    return result.second;
}

Account* AccountService::getAccount(int id) {
    // search across map
    auto it = accounts.find(id);
    if(it == accounts.end()) return nullptr;
    // return account details
    return &it->second;
}

AccountService::AccountService() {
    // start with counter '1'
    nextTransactionId = 1;
}

/* ============== HANDLE: Recording Transactions ============== */

// deposit will help in recording transaction + we audit failure
bool AccountService::deposit(int id, double amount)
{
    Account* acc = getAccount(id);

    if(!acc)
    {
        recordTransaction(
            -1,
            id,
            amount,
            "DEPOSIT",
            "FAILED",
            "ACCOUNT_NOT_FOUND"
        );

        return false;
    }

    bool success = acc->deposit(amount);

    if(success)
    {
        recordTransaction(
            -1,
            id,
            amount,
            "DEPOSIT",
            "SUCCESS",
            ""
        );
    }
    else
    {
        recordTransaction(
            -1,
            id,
            amount,
            "DEPOSIT",
            "FAILED",
            "INVALID_AMOUNT"
        );
    }

    return success;
}

// record transactions
bool AccountService::withdraw(int id, double amount)
{
    Account* acc = getAccount(id);

    if(!acc)
    {
        recordTransaction(
            id,
            -1,
            amount,
            "WITHDRAW",
            "FAILED",
            "ACCOUNT_NOT_FOUND"
        );

        return false;
    }

    bool success = acc->withdraw(amount);

    if(success)
    {
        recordTransaction(
            id,
            -1,
            amount,
            "WITHDRAW",
            "SUCCESS",
            ""
        );
    }
    else
    {
        recordTransaction(
            id,
            -1,
            amount,
            "WITHDRAW",
            "FAILED",
            "INSUFFICIENT_FUNDS"
        );
    }

    return success;
}

// one of the main ops: perform transfer of amount
// Rollback is handled in AccountService because it coordinates multi-account operations and must maintain system consistency across multiple state changes.
// also we handle monitoring transactions
bool AccountService::transfer(int fromId, int toId, double amount)
{
    Account* src = getAccount(fromId);
    Account* dst = getAccount(toId);

    if(!src)
    {
        recordTransaction(
            fromId,
            toId,
            amount,
            "TRANSFER",
            "FAILED",
            "SOURCE_ACCOUNT_NOT_FOUND"
        );
        return false;
    }

    if(!dst)
    {
        recordTransaction(
            fromId,
            toId,
            amount,
            "TRANSFER",
            "FAILED",
            "DESTINATION_ACCOUNT_NOT_FOUND"
        );
        return false;
    }

    if(!src->withdraw(amount))
    {
        recordTransaction(
            fromId,
            toId,
            amount,
            "TRANSFER",
            "FAILED",
            "INSUFFICIENT_FUNDS"
        );
        return false;
    }

    if(!dst->deposit(amount))
    {
        src->deposit(amount); // rollback

        recordTransaction(
            fromId,
            toId,
            amount,
            "TRANSFER",
            "FAILED",
            "ROLLBACK_TRIGGERED"
        );

        return false;
    }

    recordTransaction(
        fromId,
        toId,
        amount,
        "TRANSFER",
        "SUCCESS",
        ""
    );

    return true;
}

// retrieve transactions
const std::vector<Transaction>&
AccountService::getTransactions() const
{
    return transactions;
}

/* ========= service-level getters: since that is in Account ========= */
double AccountService::getBalance(int id) {
    Account* acc = getAccount(id);
    if(!acc) return -1;
    return acc -> getBalance();
}

/* =========== transaction worflow capturing =========== */
void AccountService::recordTransaction(int sourceId, int destinationId, double amount, const std::string& type, const std::string& status, const std::string& reason) {
    transactions.emplace_back(
        nextTransactionId++,
        sourceId,
        destinationId,
        amount,
        type,
        status,
        reason
    );
}