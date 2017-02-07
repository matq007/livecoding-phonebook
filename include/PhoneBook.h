//
// Created by Martin Proks on 9/23/15.
//

#ifndef LIVECODING_PHONEBOOK_PHONEBOOK_H
#define LIVECODING_PHONEBOOK_PHONEBOOK_H

#include <iostream>
#include <map>
#include "PhoneBookCollection.h"
#include "PhoneBookParser.h"

class PhoneBook {

private:

    std::string         phoneBookFileName;
    PhoneBookCollection phoneBookList;

public:

    PhoneBook(std::string phoneBookFileName);
    void load();
    void save();

    void createContact();
    void edit();
    void remove();
    void show();
    void info();
    unsigned int search();

};

#endif //LIVECODING_PHONEBOOK_PHONEBOOK_H
