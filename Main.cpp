#include "BankFunctions.h"
#include <iostream>
#include <random>
#include <iomanip>

int main() {
    std::string password;
    std::string make_password = "password";
    int user_id;
    int menu_input;
    int make_user_id = 1111;
    int i = 0;
    int log_menu_input;
    bool logged_in = false;
    bool system_run = true;
    double *amount = new double;
    double withdraw_num;
    double placeholder = 0.0;
    std::random_device seed;
    std::mt19937 gen(seed());
    std::uniform_int_distribution<> rand_id(1111, 9999);

    ///Demo accounts
    /// id: 7776 password: password
    /// id: 5328 password: iHrtC++
    while (system_run == true) {
        while (logged_in == false) {
            std::cout << "WELCOME TO CPP BANK\n\n(1) CREATE ACCOUNT\n(2) LOG IN\n(3) SYSTEM SHUTDOWN" << std::endl;
            std::cout << "Enter menu value: ";
            std::cin >> menu_input;

            if (menu_input == 1) {
                ///ADD random ID number and also check if the id is already being used
                while (menu_input == 1) {

                    make_user_id = rand_id(gen);

                    if (accountExists(hashID(make_user_id))) {
                        std::cout << ".";
                        make_user_id = rand_id(gen);
                    }

                    if (!accountExists(hashID(make_user_id))) {
                        std::cout << "Your User ID: " << make_user_id << std::endl;
                        std::cout << "Create Password: ";
                        std::cin >> make_password;


                        UserInfo UserMake = { hashID(make_user_id), std::to_string(hashPassword(make_password)), 0.00 };
                        storeUserInfo(UserMake);
                        std::cout << "ACCOUNT CREATED \n" << std::endl;

                        make_password = "password";
                        make_user_id = 0;
                        menu_input = 0;
                    }
                }
            }
            if (menu_input == 2) {
                std::cout << "Enter User ID: ";
                std::cin >> user_id;
                std::cout << "Enter Password: ";
                std::cin >> password;
                //password = std::to_string(hashPassword(password));
                //user_id = hashID(user_id);
                //std::cout << hashID(user_id) << std::endl;
                //std::cout << hashPassword(password);

                logged_in = logIn(hashID(user_id), std::to_string(hashPassword(password)));
                //logged_in = logIn(user_id, std::to_string(hashPassword(password)));
                menu_input = 0;
            }
            if (menu_input == 3) {
                std::cout << "SYSTEM SHUTTING DOWN. GOODBYE";
                system_run = false;
                return 0;
            }
        }

        while (logged_in == true) {

            std::cout << "\n CURRENT BALANCE: $" << std::fixed << std::setprecision(2) << getAccountBalance(hashID(user_id), std::to_string(hashPassword(password))) << "\n(1) Depostit\n(2) Withdrawl\n(3) Transfer\n(4) Log Out\n(5) Delete Account" << std::endl;
            std::cin >> log_menu_input;
            /// Deposit Money
            // Ask how many deposits they have and use array
            if (log_menu_input == 1) {
                std::cout << "\nHow many deposits do you want to make: ";
                std::cin >> i;

                for (int x = 0; x < i; x++) {
                    bool ty = true;
                    while (ty == true) {
                        std::cout << "Enter amount for depostit #" << x + 1 << ": ";
                        std::cin >> placeholder;
                        if (placeholder > 0) {
                            amount[x] = placeholder;
                            ty = false;
                        }
                        else {
                            std::cout << "try again";
                        }
                    }
                }
                updateBalance(hashID(user_id), std::to_string(hashPassword(password)), amount, i);
            }

            /// Withdral Money
            // Ask amount and withdrawl

            if (log_menu_input == 2) {
                int check = 1;
                while (check == 1) {
                    std::cout << "Please enter amount that you would like to withdraw from your account:" << std::endl;
                    std::cin >> withdraw_num;
                    if (withdraw_num > 0 || withdraw_num < getAccountBalance(hashID(user_id), std::to_string(hashPassword(password)))) {
                        amount[0] = (-1 * withdraw_num);
                        updateBalance(hashID(user_id), std::to_string(hashPassword(password)), amount, 1);
                    }
                    else {
                        std::cout << "Invalid input please try again" << std::endl;
                        check = 0;
                    }
                    std::cout << "Would you like to make another withdrawal?\n(1) YES\n(2) NO" << std::endl;
                    std::cin >> check;
                }
            }

            /// Transfer Money
            // Have user put in account number and vaidate if true
            // Enter amount you want to send
            // Withdrawl from your accound and dposit in other account

            /// Log Out
            if (log_menu_input == 4) {
                std::cout << "LOGGING OUT" << std::endl;
                logged_in = false;
            }

            /// Delete Account
            // Set all data to nothing

        }

    }
    return 0;
}
