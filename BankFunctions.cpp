#include "BankFunctions.h"
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>



void storeUserInfo(const UserInfo& user) {
    std::ofstream outFile("user_data.txt", std::ios::app);
    if (outFile.is_open()) {
        outFile << user.accountNumber << " " << user.passwordHash << " "<< std::fixed << std::setprecision(2) << user.balance << "\n";
        outFile.close();
    }
    else {
        std::cerr << "Unable to open file for writing\n";
    }
}

double getAccountBalance(std::size_t accountNumber, const std::string& password) {
    std::ifstream inFile("user_data.txt");
    std::size_t storedAccountNumber;
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

bool logIn(std::size_t accountNumber, const std::string& password) {
    std::ifstream inFile("user_data.txt");
    std::size_t storedAccountNumber;
    std::string storedPassword;

    double balance;

    while (inFile >> storedAccountNumber >> storedPassword >> balance) {
        // Compare hashed account number and password with stored hashed values
        if (storedAccountNumber == accountNumber && storedPassword == password) {
            std::cout << "SIGNIN SUCCESSFUL" << std::endl;
            inFile.close();
            return true;
        }
    }
    inFile.close();
    std::cout << "INCORRECT PASSWORD OR USER ID" << std::endl;
    return false;
}


void updateBalance(std::size_t accountNumber, const std::string& password, double* amount, int i) {
    std::ifstream inFile("user_data.txt");
    std::ofstream outFile("temp_user_data.txt");

    if (!inFile.is_open() || !outFile.is_open()) {
        std::cerr << "Unable to open file for reading or writing\n";
        return;
    }

    std::size_t storedAccountNumber;
    std::string storedPasswordHash;
    double balance;
    bool updated = false;
    double trueAmount = 0;

    while (inFile >> storedAccountNumber >> storedPasswordHash >> balance) {
        if (storedAccountNumber == accountNumber && storedPasswordHash == password) {
            for (int u = 0; u < i; u++) {
                trueAmount += amount[u];
            }
            balance += trueAmount;
            updated = true;
        }
        outFile << storedAccountNumber << " " << storedPasswordHash << " " << std::fixed << std::setprecision(2) << balance << "\n";
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


bool accountExists(std::size_t accountNumber) {
    std::ifstream inFile("user_data.txt");
    if (!inFile.is_open()) {
        std::cerr << "Unable to open file for reading\n";
        return false;
    }
    std::size_t storedAccountNumber;
    std::string storedPasswordHash;
    double balance;
    while (inFile >> storedAccountNumber >> storedPasswordHash >> balance) {
        if (storedAccountNumber == accountNumber) {
            inFile.close();
            return true;
        }
    }
    inFile.close();
    return false;
}

void updateTransfer(std::size_t accountNumber, std::string password, double amount, bool removeMoney) {
    std::ifstream inFile("user_data.txt");
    std::ofstream outFile("temp_user_data.txt");

    if (!inFile.is_open() || !outFile.is_open()) {
        std::cerr << "Unable to open file for reading or writing\n";
        return;
    }

    std::size_t storedAccountNumber;
    std::string storedPasswordHash;
    double balance;
    bool updated = false;

    while (inFile >> storedAccountNumber >> storedPasswordHash >> balance) {
        if (storedAccountNumber == accountNumber && storedPasswordHash == password && removeMoney == true) {
            balance -= amount;
            updated = true;
        }
        if (storedAccountNumber == accountNumber && removeMoney == false) {
            balance += amount;
            updated = true;
        }
        outFile << storedAccountNumber << " " << storedPasswordHash << " " << std::fixed << std::setprecision(2) << balance << "\n";
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

void transfer(std::size_t accountNumber, const std::string& password, std::size_t transferAccountNumber, double amount) {
    updateTransfer(accountNumber, password, amount, true);
    updateTransfer(transferAccountNumber, password, amount, false);
}

void deleteAccount(std::size_t accountNumber, const std::string& password) {
    std::ifstream inFile("user_data.txt");
    std::ofstream outFile("temp_user_data.txt");

    if (!inFile.is_open() || !outFile.is_open()) {
        std::cerr << "Unable to open file for reading or writing\n";
        return;
    }

    std::size_t storedAccountNumber;
    std::size_t deleteNumber = 0;
    std::string deletePass = "";
    std::string storedPasswordHash;
    double balance;
    bool updated = false;

    while (inFile >> storedAccountNumber >> storedPasswordHash >> balance) {
        if (storedAccountNumber == accountNumber && storedPasswordHash == password) {
            storedAccountNumber = deleteNumber;
            storedPasswordHash = deletePass;
            balance = 0;
            
            updated = true;
        }
        outFile << storedAccountNumber << " " << storedPasswordHash << "" << std::fixed << std::setprecision(2) << balance << "\n";
        
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