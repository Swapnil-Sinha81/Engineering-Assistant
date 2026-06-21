#include "Account.h"
#include <string>

Account::Account(int id, const std::string& name, double initialBalance) {
    this -> accountId = id;
    this -> ownerName = name;
    this -> balance = initialBalance;
}

/* ========== getters: we return a constant value and cannot modify data ========== */
int Account::getAccountId() const {
    return accountId;
}

std::string Account::getOwnerName() const {
    return ownerName;
}

double Account::getBalance() const {
    return balance;
}

/* ========== performing actions ========== */
/* if we want to get the balance we can use getters, else we withdraw and return status */
bool Account::deposit(double amount) {
    if(amount <= 0) return false;
    balance += amount;
    return true;
}

bool Account::withdraw(double amount) {
    if(amount <= 0) return false;
    if(balance < amount) return false;
    balance -= amount;
    return true;
}