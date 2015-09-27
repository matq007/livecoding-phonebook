//
// Created by Martin Proks on 9/6/15.
//

#include "Contact.h"

Contact::Contact() {

}

void Contact::prettyPrint() {

    char buff[20];

    strftime(buff, 20, "%Y-%m-%d %H:%M:%S", localtime(&this->addedAt));
    std::string addedAt(buff);

    strftime(buff, 20, "%Y-%m-%d %H:%M:%S", localtime(&this->updatedAt));
    std::string updatedAt(buff);

    std::cout << "Name: \t\t\t\t"       << this->name           <<std::endl;
    std::cout << "Middlename: \t\t"     << this->middleName     <<std::endl;
    std::cout << "Surname: \t\t\t"      << this->surname        <<std::endl;
    std::cout << "Title: \t\t\t\t"      << this->title          <<std::endl;
    std::cout << "Date Of Birth: \t\t"  << this->dateOfBirth    <<std::endl;
    std::cout << "Street: \t\t\t"       << this->street         <<std::endl;
    std::cout << "City: \t\t\t\t"       << this->city           <<std::endl;
    std::cout << "Home phone: \t\t"     << this->phoneHome      <<std::endl;
    std::cout << "Cell phone: \t\t"     << this->phoneCell      <<std::endl;
    std::cout << "Added at: \t\t\t"     << addedAt              <<std::endl;
    std::cout << "Updated at: \t\t"     << updatedAt            <<std::endl;
    std::cout << "-------------------------------------"        <<std::endl;
}

void Contact::setID(unsigned int id) {
    if(id > 0) {
        this->id = id;
    } else {
        std::cout << "[ERROR]: ID must be grater then 0, exiting application" <<std::endl;
        exit(-1);
    }
}

void Contact::setName(std::string name) {
    this->name = name;
}

void Contact::setMiddleName(std::string middleName) {
    this->middleName = middleName;
}

void Contact::setSurname(std::string surname) {
    this->surname = surname;
}

void Contact::setTitle(std::string title) {
    this->title = title;
}

void Contact::setDateOfBirth(std::string dateOfBirth) {
    this->dateOfBirth = dateOfBirth;
}

void Contact::setStreet(std::string street) {
    this->street = street;
}

void Contact::setCity(std::string city) {
    this->city = city;
}

void Contact::setPhoneHome(std::string number) {
    this->phoneHome = number;
}

void Contact::setPhoneCell(std::string number) {
    this->phoneCell = number;
}

void Contact::setAddedAt(time_t addedAt) {
    this->addedAt = addedAt;
}
void Contact::setUpdatedAt(time_t updatedAt) {
    this->updatedAt = updatedAt;
}

unsigned int Contact::getID() {
    return this->id;
}

std::string Contact::getName() {
    return this->name;
}

std::string Contact::getMiddleName() {
    return this->middleName;
}

std::string Contact::getSurname() {
    return this->surname;
}

std::string Contact::getTitle() {
    return this->title;
}

std::string Contact::getDateOfBirth() {
    return this->dateOfBirth;
}

std::string Contact::getStreet() {
    return this->street;
}

std::string Contact::getCity() {
    return this->city;
}

std::string Contact::getPhoneHome() {
    return this->phoneHome;
}

std::string Contact::getPhoneCell() {
    return this->phoneCell;
}

time_t Contact::getAddedAt() {
    return this->addedAt;
}

time_t Contact::getUpdatedAt() {
    return this->updatedAt;
}

/**
 * Validating input from user
 * Check: Day of birth format: DD/MM/YYYY (03/12/2000)
 * Check: Cell and Hom phone if they are not empty
 */
bool Contact::validate() {

    bool validation = true;

    std::regex patternDayOfBirth("\\d{2}[\\//]\\d{2}[\\//]\\d{4}");
    if (!std::regex_match(this->dateOfBirth, patternDayOfBirth)) {
        std::cout << "\t [WARNING]: Day of birth is not in correct format DD/MM/YYYY" << std::endl;
        validation = false;
    }

    if (this->phoneCell != "") {
        std::regex patterNumber("^\\+?\\d*$");
        if (!std::regex_match(this->phoneCell, patterNumber)) {
            std::cout << "\t [WARNING]: Cell phone number is not in correct format number" << std::endl;
            validation = false;
        }
    }

    if (this->phoneHome != "") {
        std::regex patterNumber("^\\+?\\d*$");
        if (!std::regex_match(this->phoneHome, patterNumber)) {
            std::cout << "\t [WARNING]: Home phone number is not in correct format number" << std::endl;
            validation = false;
        }
    }

    return validation;
}