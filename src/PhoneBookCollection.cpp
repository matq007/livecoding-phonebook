//
// Created by Martin Proks on 9/6/15.
//

#include "PhoneBookCollection.h"
#include <iostream>

PhoneBookCollection::PhoneBookCollection() {

    this->phoneBook = std::vector<Contact>();
}

std::vector<Contact> PhoneBookCollection::getPhoneBook() {

    return this->phoneBook;
}

int PhoneBookCollection::getMaxID() {
    return this->maxID;
}

void PhoneBookCollection::setMaxID(int id) {
    this->maxID = id;
}

void PhoneBookCollection::show() const {

    unsigned long size = this->phoneBook.size();

    if (size == 0) {
        std::cout << "[INFO]: No contacts found" << std::endl;
    } else {
        for(unsigned long i = 0; i < size; i++) {
            this->phoneBook[i].prettyPrint();
        }
    }
}

/**
 * Returns object (contact) from vector
 * @return Contact
 */
Contact PhoneBookCollection::get(unsigned int index) const {

    return this->phoneBook[index];

}

void PhoneBookCollection::add(const Contact& person) {

    this->phoneBook.push_back(person);
}

void PhoneBookCollection::edit(unsigned int index) {

    if (this->verifyIndex(index)) {
        Contact &found = this->phoneBook.at(index);
        std::string tmp;

        std::cout << "Name: (" << found.getName() << ") :";
        std::getline(std::cin, tmp);
        if (tmp != "") found.setName(tmp);
        if (tmp != "") found.setName(tmp);
        std::cout << "Middlename: (" << found.getMiddleName() << ") :";
        std::getline(std::cin, tmp);
        if (tmp != "") found.setMiddleName(tmp);
        std::cout << "Surname: (" << found.getSurname() << ") :";
        std::getline(std::cin, tmp);
        if (tmp != "") found.setSurname(tmp);
        std::cout << "Birthday: (" << found.getDateOfBirth() << ") :";
        std::getline(std::cin, tmp);
        if (tmp != "") found.setDateOfBirth(tmp);
        std::cout << "Street: (" << found.getStreet() << ") :";
        std::getline(std::cin, tmp);
        if (tmp != "") found.setStreet(tmp);
        std::cout << "City: (" << found.getCity() << ") :";
        std::getline(std::cin, tmp);
        if (tmp != "") found.setCity(tmp);
        std::cout << "Home phone: (" << found.getPhoneHome() << ") :";
        std::getline(std::cin, tmp);
        if (tmp != "") found.setPhoneHome(tmp);
        std::cout << "Cell phone: (" << found.getPhoneCell() << ") :";
        std::getline(std::cin, tmp);
        if (tmp != "") found.setPhoneCell(tmp);

        time_t updatedAt = time(NULL);
        found.setUpdatedAt(updatedAt);

        if(found.validate()) {
            std::cout << "[INFO]: Contact updated" << std::endl;
        }
    } else {
        std::cout << "Index out of range !" << std::endl;
    }

}

void PhoneBookCollection::remove(unsigned int index) {

    if (this->verifyIndex(index)) {
        std::cout << "[ERROR]: Index does not exist !";
    } else {
        this->phoneBook.erase(this->phoneBook.begin() + index);
        std::cout << "[INFO]: Contact removed" << std::endl;
    }

}

/**
 * Verify if index is not out of range
 * @return false if error
 */
bool PhoneBookCollection::verifyIndex(unsigned int index) {
    return (index > 0 && index < this->phoneBook.size());
}

/**
 * Returns search result from vector
 * @return <INDEX_NUMBER, CONTACT>
 */
std::map<unsigned int, Contact> PhoneBookCollection::search(const std::string& pattern) {

    std::map<unsigned int, Contact> searchResult;

    for(unsigned long index = 0; index < this->phoneBook.size(); index++) {

        if(
           boost::contains(boost::to_lower_copy(this->phoneBook[index].getName()), pattern) ||
           boost::contains(boost::to_lower_copy(this->phoneBook[index].getSurname()), pattern) ||
           boost::contains(this->phoneBook[index].getPhoneCell(), pattern) ||
           boost::contains(this->phoneBook[index].getPhoneHome(), pattern)
        ) {

            searchResult.insert( std::pair<unsigned int, Contact>(index, this->phoneBook[index]) );

        }

    }

    return searchResult;
}