#!/bin/bash

g++ \
../tests/test-account-service.cpp \
../models/Account.cpp \
../services/AccountService.cpp \
-o test

./test