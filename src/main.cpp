/*
 * PhoneBook application
 * Author: Martin Proks
 * Version 0.1
 *
 * Created on September 3, 2015, 12:26 PM
 */
#include <iostream>
#include "app.h"

using namespace std;

int main(int argc, char** argv) {

    cout << "Welcome to Phonebook application v 0.1" << endl;
    string phoneBookFileName;


    if (argc == 1) {

        phoneBookFileName = "phoneBook.xml";

    } else if (argc == 2) {

        string param = argv[1];
        if (param == "--help" || param == "-h") {
            help();
        }

        if (param.substr(param.find_last_of(".") + 1) == "xml") {
            phoneBookFileName = param;
        }

    } else {

        cout << "[ERROR]: Bad number of parameters, see help" << endl;
        help();
        return -1;

    }

    PhoneBook phoneBook(phoneBookFileName);
    phoneBook.load();
    menu(phoneBook); //menu with options

    return 0;
}
