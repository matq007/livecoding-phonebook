//
// Created by Martin Proks on 9/23/15.
//

#include "PhoneBook.h"
#include <iostream>
#include <PhoneBookParser.h>

PhoneBook::PhoneBook(const std::string &phoneBookFileName)
        : phoneBookFileName(phoneBookFileName) {
}

/**
 * Loads and parses XML document into vector
 */
void PhoneBook::load() {

    PhoneBookParser parser(this->phoneBookFileName);
    parser.load();
    this->phoneBookList = parser.loadDataFromXML();

}

/**
 * Creates and validates new contact added by user
 */
void PhoneBook::createContact() {

    unsigned int id = this->phoneBookList.getMaxID() + 1;
    std::string input;
    time_t addedAt = time(NULL);

    Contact contact;

    contact.setID(id);

    std::cout << "Name: ";
    std::getline(std::cin, input);
    contact.setName(input);

    std::cout << "Middlename: ";
    std::getline(std::cin, input);
    contact.setMiddleName(input);

    std::cout << "Surname: ";
    std::getline(std::cin, input);
    contact.setSurname(input);

    std::cout << "Title: ";
    std::getline(std::cin, input);
    contact.setTitle(input);

    std::cout << "Date of Birth (DD/MM/YYYY): ";
    std::getline(std::cin, input);
    contact.setDateOfBirth(input);

    std::cout << "Street: ";
    std::getline(std::cin, input);
    contact.setStreet(input);

    std::cout << "City: ";
    std::getline(std::cin, input);
    contact.setCity(input);

    std::cout << "Home phone: ";
    std::getline(std::cin, input);
    contact.setPhoneHome(input);

    std::cout << "Cell phone: ";
    std::getline(std::cin, input);
    contact.setPhoneCell(input);

    contact.setAddedAt(addedAt);
    contact.setUpdatedAt(addedAt);

    if (!contact.validate()) {
        std::cout << "[ERROR]: Contact not created, in createContact() method" << std::endl;
    }

    this->phoneBookList.setMaxID(id);
    this->phoneBookList.add(contact);

    std::cout << "[INFO]: Contact added" << std::endl;

}

/**
 * Print all contacts
 */
void PhoneBook::show() const {

    this->phoneBookList.show();

}

/**
 * Print specific contact
 */
void PhoneBook::info() {

    unsigned long index = this->search();
    this->phoneBookList.get(index).prettyPrint();

}

/**
 * Edits contact
 */
void PhoneBook::edit() {

    unsigned long index = this->search();
    this->phoneBookList.edit(index);

}

/**
 * Removes contact from vector
 */
void PhoneBook::remove() {

    unsigned long index = this->search();
    this->phoneBookList.remove(index);

}

/**
 * Stores vector structure into XML File
 */
void PhoneBook::save() {

    PhoneBookParser parser(this->phoneBookFileName);
    parser.store(this->phoneBookList);

}

/**
 * Prints searched resuls
 * Searches input in surname and number
 */
unsigned int PhoneBook::search() {

    std::string input;
    std::cout << "Type name, surname or number to find the contact: ";
    std::getline(std::cin, input);

    std::map<unsigned int, Contact> searchResult = this->phoneBookList.search(input);

    for (std::map<unsigned int, Contact>::iterator it = searchResult.begin(); it != searchResult.end(); ++it) {

        std::cout << "[" << it->first << "]: "
                  << it->second.getName() << " " << it->second.getSurname()
                  << " | " << it->second.getPhoneHome() << " | " << it->second.getPhoneCell()
                  << std::endl;

    }

    // pick choice
    std::string index;
    std::cout << "Choose number: ";
    getline(std::cin, index);

    return (unsigned int) atoi(index.c_str());

}