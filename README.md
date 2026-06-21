# Payment Service

A simple payment service built in **C++** to explore backend service design, object-oriented programming, transaction management, service orchestration, rollback handling, and testing.

## Features

* Create accounts
* Deposit funds
* Withdraw funds
* Transfer funds between accounts
* Transaction history and audit logging
* Failure tracking
* Rollback support for failed transfers
* Service-level orchestration
* Unit test driver

---

## Architecture

### Account

Represents a bank account and manages account state.

**Responsibilities**

* Account creation
* Balance management
* Deposits
* Withdrawals
* Account information retrieval

### Transaction

Immutable record of an operation performed in the system.

**Responsibilities**

* Transaction tracking
* Status management
* Failure reason tracking
* Audit history generation

### AccountService

Coordinates workflows across accounts.

**Responsibilities**

* Account lookup
* Deposit orchestration
* Withdraw orchestration
* Transfer orchestration
* Transaction logging
* Rollback handling
* System consistency

---

## Project Structure

```text
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
```

---

## Design Principles

### Separation of Concerns

**Account**

* Owns account state and balance operations

**Transaction**

* Owns transaction history and audit data

**AccountService**

* Coordinates multi-account workflows and consistency

---

## Transaction Logging

Every operation executed through `AccountService` creates a transaction record.

### Transaction Types

* `DEPOSIT`
* `WITHDRAW`
* `TRANSFER`

### Transaction Status

* `SUCCESS`
* `FAILED`

### Failure Reasons

* `ACCOUNT_NOT_FOUND`
* `SOURCE_ACCOUNT_NOT_FOUND`
* `DESTINATION_ACCOUNT_NOT_FOUND`
* `INSUFFICIENT_FUNDS`
* `ROLLBACK_TRIGGERED`

---

## Rollback Support

Transfers are treated as atomic operations.

```text
Withdraw Source
      ↓
Deposit Destination
      ↓
Failure?
      ↓
Rollback Source
```

This ensures account balances remain consistent when multi-step operations fail.

---

## Build & Run

### Build

```bash
cmake -B build
cmake --build build
```

### Run Tests

```bash
./build/test-account-service
```

---

## Test Script

```bash
#!/bin/bash

g++ \
../tests/test-account-service.cpp \
../models/Account.cpp \
../models/Transaction.cpp \
../services/AccountService.cpp \
-o test

./test
```

Run:

```bash
chmod +x run_test.sh
./run_test.sh
```

---

## Learning Objectives

* C++ class design
* Header vs implementation files
* Object-oriented programming
* Service orchestration
* Transaction management
* Rollback strategies
* Unit testing
* Build systems and linking

---

## Future Enhancements

* REST APIs
* HTTP routing
* PostgreSQL integration
* Persistent storage
* Authentication & authorization
* Metrics and monitoring
* Incident management
* AI-assisted root cause analysis

```
```
