# Payment Service

A payment service built to explore:

- Object-Oriented Design
- Service Layer Architecture
- Transaction Logging
- Rollback & Consistency
- Build Systems (CMake)

---

## Architecture

```text
                +------------------+
                |  AccountService  |
                +------------------+
                         |
        +----------------+----------------+
        |                                 |
        v                                 v
+----------------+              +----------------+
|    Account     |              |  Transaction   |
+----------------+              +----------------+
| Balance State  |              | Audit History  |
| Deposit        |              | Status         |
| Withdraw       |              | Failure Reason |
+----------------+              +----------------+
```

### Responsibilities

| Component | Responsibility |
|------------|---------------|
| Account | Owns account state and balance operations |
| Transaction | Stores transaction audit records |
| AccountService | Coordinates workflows across accounts |

---

## Supported Operations

```text
Create Account
Deposit
Withdraw
Transfer
Transaction Logging
Rollback
```

---

## Transfer Flow

```text
Source Withdraw
       |
       v
Destination Deposit
       |
       +---- Success ----> Commit
       |
       +---- Failure ----> Rollback (Maintain Atomicity)
```

---

## Project Structure

```text
src/
├── models/
│   ├── Account.h
│   ├── Account.cpp
│   ├── Transaction.h
│   └── Transaction.cpp
│
├── services/
│   ├── AccountService.h
│   └── AccountService.cpp
│
├── tests/
│   └── test-account-service.cpp
│
└── build/
    └── run_test.sh
```

---

## Build

```bash
cmake -B build
cmake --build build
```

---

## Run

```bash
./build/test-account-service
```

---

## Example Transaction Log

```text
TxnId: 5
SourceId: 2
DestId: 3
Type: TRANSFER
Status: SUCCESS
Amount: 500
```

---

## Concepts Practiced

- Classes & Objects
- Header / Implementation Separation
- Service Layer Pattern
- Transaction Management
- Rollback Handling
- Build & Linking
- Testing

---

## Roadmap

- [x] Account Management
- [x] Transaction Logging
- [x] Rollback Support
- [ ] HTTP Routes
- [ ] REST APIs
- [ ] Database Persistence
- [ ] Incident Management
- [ ] AI Root Cause Analysis
```