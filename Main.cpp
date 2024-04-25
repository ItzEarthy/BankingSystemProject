#include "BankFunctions.h"
#include <iostream>

int main() {
    std::string password;
    std::string make_password;
    int user_id;
    int menu_input;
    int make_user_id;
    bool logged_in = false;
    double* amount= new double;
    int i =0;

    std::cout << "WELCOME TO CPP BANK\n\n(1) CREATE ACCOUNT\n(2) LOG IN" << std::endl;
    
    while (!logged_in) {
        std::cout << "Enter menu value: ";
        std::cin >> menu_input;

        if (menu_input == 1) {
            ///ADD random ID number and also check if the id is already being used
            std::cout << "Enter User ID: ";
            std::cin >> make_user_id;
            std::cout << "Enter Password: ";
            std::cin >> make_password;
            
            UserInfo UserMake = { hashID(make_user_id), std::to_string(hashPassword(make_password)), 0.0 };
            storeUserInfo(UserMake);

            make_password = "";
            make_user_id = 0;
        }
        if (menu_input == 2) {
            std::cout << "Enter User ID: ";
            std::cin >> user_id;
            std::cout << "Enter Password: ";
            std::cin >> password;
            password = hashPassword(password);
            user_id - hashID(user_id);

            logged_in = logIn(user_id, password);
        }
        
    }

    while (logged_in) {
        std::cout << "(1) Depostit\n(2) Withdrawl\n(3) Transfer\n(4) Log Out\n(5) Delete Account" << std::endl;
        
        /// Deposit Money
        // Ask how many deposits they have and use array

        /// Withdral Money
        // Ask amount and withdrawl

        /// Transfer Money
        // Have user put in account number and vaidate if true
        // Enter amount you want to send
        // Withdrawl from your accound and dposit in other account

        /// Log Out
        
        /// Delete Account
        // Set all data to nothing
        updateBalance(user_id, password, amount, i);
    }
    

    return 0;
}
