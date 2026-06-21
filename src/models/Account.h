/* 
    Bank Account: Declaration 
    This piece owns - Details related to an account
    handles rules of accounts
*/
#pragma once // if this file is included multiple times, it will only be processed once
#include <string>

class Account
{
private:
    int accountId;
    std::string ownerName;
    double balance;

public:
    Account(
        int id,
        const std::string& name,
        double initialBalance
    );

    int getAccountId() const;

    std::string getOwnerName() const;

    double getBalance() const;

    bool deposit(double amount);

    bool withdraw(double amount);
};