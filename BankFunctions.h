#pragma once
#include <string>

struct UserInfo {
    std::size_t accountNumber;
    std::string passwordHash;
    double balance;
};

void storeUserInfo(const UserInfo& user);

double getAccountBalance(std::size_t accountNumber, const std::string& passwordHash);

std::size_t hashPassword(const std::string& password);

std::size_t hashID(int& user_id);

bool logIn(std::size_t accountNumber, const std::string& password);

void updateBalance(std::size_t accountNumber, const std::string& password, double* amount, int i);

bool accountExists(std::size_t accountNumber);

void transfer(std::size_t accountNumber, const std::string& password, std::size_t transferAccountNumber, double amount);

void updateTransfer(std::size_t accountNumber, std::string password, double amount, bool removeMoney);

void deleteAccount(std::size_t accoutnNumber, const std::string& password);