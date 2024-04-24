#include "BankFunctions.h"
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>


void storeUserInfo(const UserInfo& user) {
    std::ofstream outFile("user_data.txt", std::ios::app);
    if (outFile.is_open()) {
        outFile << user.accountNumber << " " << user.passwordHash << " " << user.balance << "\n";
        outFile.close();
    }
    else {
        std::cerr << "Unable to open file for writing\n";
    }
}

double getAccountBalance(int accountNumber, const std::string& passwordHash) {
    std::ifstream inFile("user_data.txt");
    int storedAccountNumber;
    std::string storedPasswordHash;
    double balance;
    while (inFile >> storedAccountNumber >> storedPasswordHash >> balance) {
        if (storedAccountNumber == accountNumber && storedPasswordHash == passwordHash) {
            inFile.close();
            return balance;
        }
    }
    // Return a default value if the user is not found or if the password is incorrect
    inFile.close();
    return -1.0;
}

bool logIn(int accountNumber, const std::string& passwordHash) {
    std::ifstream inFile("user_data.txt");
    int storedAccountNumber;
    std::string storedPasswordHash;
    while (inFile >> storedAccountNumber >> storedPasswordHash) {
        if (storedAccountNumber == accountNumber && storedPasswordHash == passwordHash) {
            std::cout << "SIGNIN SUCCSESSFUL";
            return true;
        }
    }
    inFile.close();
    std::cout << "INCORRECT PASSWORD OR USER ID";
    return false;
}

std::size_t hashPassword(const std::string& password) {
    return std::hash<std::string>{}(password);
}