Payment Service

A payment service built in C++ to learn backend service design, object-oriented programming, service orchestration, transaction logging, and testing.

⸻

Business Objects

Account

Represents a bank account and manages account-level operations.

Responsibilities:

* Account creation
* Balance management
* Deposit operations
* Withdraw operations
* Account information retrieval

Transaction

Represents an immutable record of an operation performed within the system.

Responsibilities:

* Transaction tracking
* Transaction status management
* Failure reason tracking
* Audit history generation

AccountService

Coordinates workflows involving one or more accounts.

Responsibilities:

* Account lookup
* Deposit orchestration
* Withdraw orchestration
* Transfer orchestration
* Transaction recording
* Rollback handling
* System consistency

⸻

Project Structure

src/
├── models
│   ├── Account.h
│   ├── Account.cpp
│   ├── Transaction.h
│   └── Transaction.cpp
│
├── services
│   ├── AccountService.h
│   └── AccountService.cpp
│
├── tests
│   └── test-account-service.cpp
│
└── build
    └── run_test.sh

⸻

Design Principles

Separation of Concerns

Account

Responsible for its own state.

Balance
Owner
Deposit
Withdraw

Transaction

Responsible for audit history.

Transaction ID
Source Account
Destination Account
Status
Failure Reason

AccountService

Responsible for coordinating workflows.

Transfer
Rollback
Transaction Logging
Account Lookup

⸻

Key Learnings

Header Files (.h)

Used for declarations.

Examples:

class Account;
class Transaction;
class AccountService;

Purpose:

* Define interfaces
* Separate declaration from implementation
* Improve code organization

⸻

CPP Files (.cpp)

Used for implementations.

Examples:

Account::deposit(...)
Account::withdraw(...)
AccountService::transfer(...)

Purpose:

* Implement business logic
* Keep interfaces clean
* Support modular compilation

⸻

Linker

The linker combines implementations from multiple .cpp files into a single executable.

Example:

Account.cpp
Transaction.cpp
AccountService.cpp
        ↓
     Linker
        ↓
 Executable

⸻

Executable

The final runnable program generated after compilation and linking.

Example:

./test

⸻

Transaction Logging

Every operation performed through AccountService is recorded as a transaction.

Supported transaction types:

DEPOSIT
WITHDRAW
TRANSFER

Supported statuses:

SUCCESS
FAILED

Example failure reasons:

ACCOUNT_NOT_FOUND
SOURCE_ACCOUNT_NOT_FOUND
DESTINATION_ACCOUNT_NOT_FOUND
INSUFFICIENT_FUNDS
ROLLBACK_TRIGGERED

⸻

Rollback Handling

Transfers are treated as atomic operations.

Example:

Withdraw from Source Account
        ↓
Deposit to Destination Account
        ↓
Failure?
        ↓
Rollback Source Account

This ensures consistency across multiple account updates.

⸻

Running Tests

Build

cmake -B build
cmake --build build

Run

./build/test-account-service

⸻

Test Script

File:

build/run_test.sh

Contents:

#!/bin/bash
g++ \
../tests/test-account-service.cpp \
../models/Account.cpp \
../models/Transaction.cpp \
../services/AccountService.cpp \
-o test
./test

Run:

chmod +x run_test.sh
./run_test.sh

⸻

Current Features

* Create Account
* Deposit Funds
* Withdraw Funds
* Transfer Funds
* Transaction History
* Failure Tracking
* Rollback Support
* Service-Level Orchestration
* Unit Test Driver

⸻

Future Improvements

* HTTP Routes
* REST APIs
* Persistent Storage
* PostgreSQL Integration
* Incident Generation
* AI-Assisted Root Cause Analysis
* Service Monitoring
* Metrics Collection
* Authentication & Authorization