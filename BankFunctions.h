#pragma once
#include <string>

struct UserInfo {
    int accountNumber;
    std::string passwordHash;
    double balance;
};

void storeUserInfo(const UserInfo& user);

double getAccountBalance(int accountNumber, const std::string& passwordHash);

std::size_t hashPassword(const std::string& password);

std::size_t hashID(int& user_id);

bool logIn(int accountNumber, const std::string& password);

void updateBalance(int accountNumber, const std::string& password, double* amount, int i);

bool accountExists(int accountNumber);