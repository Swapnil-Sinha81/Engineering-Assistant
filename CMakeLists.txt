# 1. Instead of manually running g++ commands, we use CMake for builds.
# 2. CMake figures out which files to compile and how to link them.
# 3. Generates the final executable that can be run.

# Minimum CMake version required
cmake_minimum_required(VERSION 3.16)

# Project name
project(PaymentService)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Build executable
add_executable(

    test-account-service

    # Test Driver
    src/tests/test-account-service.cpp

    # Business Objects
    src/models/Account.cpp
    src/models/Transaction.cpp

    # Service Layer
    src/services/AccountService.cpp
)

# Allows:
#   #include "Account.h"
# instead of:
#   #include "../models/Account.h"
target_include_directories(

    test-account-service

    PRIVATE

    src/models
    src/services
)