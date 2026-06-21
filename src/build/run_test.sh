#!/bin/bash

g++ \                                                                             
../tests/test-account-service.cpp \
../models/Account.cpp \
../models/Transaction.cpp \
../services/AccountService.cpp \
-o test


./test