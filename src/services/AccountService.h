/* 
    Coordinates create account, transfer and account lookup
    Handles multi-account workflows
    Account ensures correctness of its own state, while AccountService ensures consistency across multiple accounts.
*/

#pragma once
#include <unordered_map>
#include <vector>
#include "../models/Account.h"
#include "../models/Transaction.h"
#include <string>

class AccountService {
    private:
        // for accounts workflows
        std::unordered_map<int, Account> accounts;
        // for transactions workflow
        std::vector<Transaction> transactions;
        // simple counter: if not declared starts from garbage value
        int nextTransactionId; 

        void recordTransaction(
            int sourceId,
            int destinationId,
            double amount,
            const std::string& type,
            const std::string& status,
            const std::string& reason
        );

    public:
        AccountService();
        bool createAccount(
            int id,
            const std::string& name,
            double balance
        );

        Account* getAccount(int id);
        bool withdraw(int id, double amount);
        bool deposit(int id, double amount);
        bool transfer(int fromId, int toId, double amount);

        /* ========= service-level getters: Account + Transactions ========= */
        double getBalance(int id);
        // const: not modify account service
        const std::vector<Transaction>& getTransactions() const;
};