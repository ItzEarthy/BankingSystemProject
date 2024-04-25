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

double getAccountBalance(int accountNumber, const std::string& password) {
    std::ifstream inFile("user_data.txt");
    int storedAccountNumber;
    std::string storedPasswordHash;
    double balance;

    while (inFile >> storedAccountNumber >> storedPasswordHash >> balance) {
        if (storedAccountNumber == accountNumber && storedPasswordHash == password) {
            inFile.close();
            return balance;
        }
    }
    // Return a default value if the user is not found or if the password is incorrect
    inFile.close();
    return -1.0;
}

bool logIn(int accountNumber, const std::string& password) {
    std::ifstream inFile("user_data.txt");
    int storedAccountNumber;
    std::string storedPasswordHash;

    while (inFile >> storedAccountNumber >> storedPasswordHash) {
        if (storedAccountNumber == accountNumber && storedPasswordHash == password) {
            std::cout << "SIGNIN SUCCSESSFUL";
            return true;
        }
    }
    inFile.close();
    std::cout << "INCORRECT PASSWORD OR USER ID";
    return false;
}

void updateBalance(int accountNumber, const std::string& password, double* amount, int i) {
    std::ifstream inFile("user_data.txt");
    std::ofstream outFile("temp_user_data.txt");

    if (!inFile.is_open() || !outFile.is_open()) {
        std::cerr << "Unable to open file for reading or writing\n";
        return;
    }

    int storedAccountNumber;
    std::string storedPasswordHash;
    double balance;
    bool updated = false;

    while (inFile >> storedAccountNumber >> storedPasswordHash >> balance) {
        if (storedAccountNumber == accountNumber && storedPasswordHash == password) {
            //balance += amount;
            updated = true;
        }
        outFile << storedAccountNumber << " " << storedPasswordHash << " " << balance << "\n";
    }

    inFile.close();
    outFile.close();

    if (!updated) {
        std::cout << "Failed to update balance. Invalid account number or password." << std::endl;
        remove("temp_user_data.txt");
        return;
    }

    remove("user_data.txt");
    rename("temp_user_data.txt", "user_data.txt");
}


std::size_t hashPassword(const std::string& password) {
    return std::hash<std::string>{}(password);
}

std::size_t hashID(int& user_id) {
    return std::hash<int>{}(user_id);
}

