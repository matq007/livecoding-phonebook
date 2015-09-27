//
// Created by Martin Proks on 9/23/15.
//

#include "app.h"

void menu(PhoneBook phoneBook) {

    std::string input;
    help();

    while(std::cin.good() && !std::cin.eof()) {

        std::cout << "> ";

        getline(std::cin, input);

        int option = atoi(input.c_str());

        switch(option) {
            case 1:
                help();
                break;
            case 2:
                phoneBook.show();
                break;
            case 3:
                phoneBook.info();
                break;
            case 4:
                phoneBook.createContact();
                break;
            case 5:
                phoneBook.edit();
                break;
            case 6:
                phoneBook.remove();
                break;
            case QUIT:
                quit(phoneBook);
            default:
                std::cout << "Bad input, try again" << std::endl;
                break;
        }

    }
    std::cout << std::endl;
}

void quit(PhoneBook phoneBook) {

    std::string answer;
    std::cout << "Do you want to save changes? [Y/N]: ";
    std::getline(std::cin, answer);

    if (boost::to_lower_copy(answer) == "y") {
        std::cout << "[INFO]: Saving phoneBook";
        phoneBook.save();
    }

    exit(0);

}


void help() {

    std::cout << "MENU: " << std::endl;
    std::cout << "[1] Help" << std::endl;
    std::cout << "[2] Show Phonebook" << std::endl;
    std::cout << "[3] Show/Find contact" << std::endl;
    std::cout << "[4] Add contact" << std::endl;
    std::cout << "[5] Edit contact" << std::endl;
    std::cout << "[6] Delete contact" << std::endl;
    std::cout << "[7] Quit" << std::endl;

}