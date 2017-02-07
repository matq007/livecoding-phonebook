//
// Created by Martin Proks on 9/23/15.
//

#ifndef LIVECODING_PHONEBOOK_PHONEBOOK_H
#define LIVECODING_PHONEBOOK_PHONEBOOK_H

#include "PhoneBookCollection.h"

class PhoneBook {

private:

    std::string         phoneBookFileName;
    PhoneBookCollection phoneBookList;

public:

    PhoneBook(const std::string& phoneBookFileName);
    void load();
    void save();

    void createContact();
    void edit();
    void remove();
    void show() const;
    void info();
    unsigned int search();

};

#endif //LIVECODING_PHONEBOOK_PHONEBOOK_H
