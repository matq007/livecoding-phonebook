//
// Created by Martin Proks on 9/6/15.
//

#ifndef LIVECODING_PHONEBOOK_PHONEBOOKCOLLECTION_H
#define LIVECODING_PHONEBOOK_PHONEBOOKCOLLECTION_H

#include <iostream>
#include <vector>
#include <map>
#include <regex>
#include "boost/algorithm/string.hpp"
#include "Contact.h"

class PhoneBookCollection {

private:

    std::vector<Contact> phoneBook;
    int maxID;

public:

    PhoneBookCollection();
    std::vector<Contact> getPhoneBook();
    Contact get(unsigned int index);

    void setMaxID(int id);
    int getMaxID();

    void add(Contact person);
    void edit(unsigned int index);
    void remove(unsigned int index);
    void show();
    bool verifyIndex(unsigned int index);

    std::map<unsigned int, Contact> search(std::string pattern);
};

#endif //LIVECODING_PHONEBOOK_PHONEBOOKCOLLECTION_H
