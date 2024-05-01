CPP Bank System

Overview
--------
This project is a simple banking system implemented in C++. It allows users to create accounts, log in, deposit money, withdraw money, transfer money between accounts, and delete accounts. The system utilizes file I/O for data storage.

Features
--------
**Account creation:** Users can create new accounts with unique user IDs and passwords.

**Login:** Users can log in to their accounts using their user IDs and passwords.

**Deposit:** Users can deposit money into their accounts.

**Withdrawal:** Users can withdraw money from their accounts, provided they have sufficient funds.

**Transfer:** Users can transfer money from their accounts to another account.

**Account deletion:** Users can delete their accounts, removing them from the system.

Usage
-----
- Clone the repository to your local machine.
- Compile the `main.cpp` file along with `bankfunctions.cpp` & `bankfunctions.h` using your C++ compiler.
- Run the compiled executable.
- Follow the prompts to navigate through the banking system.

Demo Accounts
-------------
For testing purposes, the system includes two demo accounts:

- Demo Account 1
  - User ID: 7645
  - Password: password
- Demo Account 2
  - User ID: 4057
  - Password: iHrtC++

File Structure
--------------
- main.cpp: Contains the main program logic.
- bankfunctions.cpp: Contains functions related to banking operations.
- BankFunctions.h: Header file for function declarations.
- user_data.txt: Text file for storing user account information.

Dependencies
------------
C++ compiler
