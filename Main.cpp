#include "BankFunctions.h"
#include <iostream>

int main() {
    // Example usage
    std::string password;
    std::string make_password;
    int user_id;
    int menu_input;
    int make_user_id;
    bool logged_in;

    std::cout << "WELCOME TO CPP BANK\n\n(1) CREATE ACCOUNT\n(2) LOG IN" << std::endl;


    std::cout << "Enter menu value: ";
    std::cin >> menu_input;

    if (menu_input == 1) {
        std::cout << "Enter User ID: ";
        std::cin >> make_user_id;
        std::cout << "Enter Password: ";
        std::cin >> make_password;

        UserInfo UserMake = { make_user_id, std::to_string(hashPassword(make_password)) , 0.0 };
        storeUserInfo(UserMake);
    }
    if (menu_input == 2) {
        std::cout << "Enter User ID: ";
        std::cin >> user_id;
        std::cout << "Enter Password: ";
        std::cin >> password;

        logged_in = logIn(user_id, std::to_string(hashPassword(password)));
    }


    return 0;
}
