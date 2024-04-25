#include "BankFunctions.h"
#include <iostream>

int main() {
    std::string password;
    std::string make_password;
    int user_id;
    int menu_input;
    int make_user_id;
    bool logged_in = false;
    double* amount = new double;
    double withdraw_num;
    int i = 0;
    double placeholder = 0.0;
    int log_menu_input;

    std::cout << "WELCOME TO CPP BANK\n\n(1) CREATE ACCOUNT\n(2) LOG IN" << std::endl;
    std::cout << logged_in;
    while (logged_in == false) {
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
            menu_input = 0;
        }
        if (menu_input == 2) {
            std::cout << "Enter User ID: ";
            std::cin >> user_id;
            std::cout << "Enter Password: ";
            std::cin >> password;
            //password = std::to_string(hashPassword(password));
            //user_id = hashID(user_id);
           
            logged_in = logIn(hashID(user_id), std::to_string(hashPassword(password)));
            
        }

    }

    while (logged_in == true) {
        
        std::cout << "(1) Depostit\n(2) Withdrawl\n(3) Transfer\n(4) Log Out\n(5) Delete Account" << std::endl;
        std::cin >> log_menu_input;
        /// Deposit Money
        // Ask how many deposits they have and use array
        if (log_menu_input == 1) {
            std::cout << "How many deposits do you want to make: ";
            std::cin >> i;

            for (int x = 0; x < i; x++) {
                bool ty = true;
                while (ty == true) {
                    std::cout << "Enter amount for depostit #" << x << ": ";
                    std::cin >> placeholder;
                    if (placeholder > 0) {
                        amount[i] = placeholder;
                        ty = false;
                    }
                    else {
                        std::cout << "try again";
                    }

                }
                updateBalance(hashID(user_id), std::to_string(hashPassword(password)), amount, i);
            }
        }
    
        /// Withdral Money
        // Ask amount and withdrawl
       
        if (log_menu_input == 2) {
            std::cout << "POOPY";
            int check = 1;
            while (check == 1) {
                std::cout << "Please enter amount that you would like to withdraw from your account:" << std::endl;
                std::cin >> withdraw_num;
                if (withdraw_num > 0 || withdraw_num < getAccountBalance(hashID(user_id), std::to_string(hashPassword(password)))) {
                    amount[0] = (-1 * withdraw_num);
                    updateBalance(hashID(user_id), std::to_string(hashPassword(password)), amount, 1);
                }
                else {
                    std::cout << "Invalid input please try again POOPY" << std::endl;
                    check == 0;
                }
                std::cout << "Would you like to make another withdrawal?(1) If not continue by pressing(2)" << std::endl;
                std::cin >> check;
            }
       
        }

        /// Transfer Money
        // Have user put in account number and vaidate if true
        // Enter amount you want to send
        // Withdrawl from your accound and dposit in other account

        /// Log Out
        
        /// Delete Account
        // Set all data to nothing
        
    }
    

    return 0;
}
