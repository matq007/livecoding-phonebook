//
// Created by Martin Proks on 9/6/15.
//

#include "Contact.h"
#include "boost/regex.hpp"
#include <iostream>

Contact::Contact() {

}

void Contact::prettyPrint() const {

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

void Contact::setName(const std::string& name) {
    this->name = name;
}

void Contact::setMiddleName(const std::string& middleName) {
    this->middleName = middleName;
}

void Contact::setSurname(const std::string& surname) {
    this->surname = surname;
}

void Contact::setTitle(const std::string& title) {
    this->title = title;
}

void Contact::setDateOfBirth(const std::string& dateOfBirth) {
    this->dateOfBirth = dateOfBirth;
}

void Contact::setStreet(const std::string& street) {
    this->street = street;
}

void Contact::setCity(const std::string& city) {
    this->city = city;
}

void Contact::setPhoneHome(const std::string& number) {
    this->phoneHome = number;
}

void Contact::setPhoneCell(const std::string& number) {
    this->phoneCell = number;
}

void Contact::setAddedAt(time_t addedAt) {
    this->addedAt = addedAt;
}
void Contact::setUpdatedAt(time_t updatedAt) {
    this->updatedAt = updatedAt;
}

unsigned int Contact::getID() const {
    return this->id;
}

std::string Contact::getName() const {
    return this->name;
}

std::string Contact::getMiddleName() const {
    return this->middleName;
}

std::string Contact::getSurname() const {
    return this->surname;
}

std::string Contact::getTitle() const {
    return this->title;
}

std::string Contact::getDateOfBirth() const {
    return this->dateOfBirth;
}

std::string Contact::getStreet() const {
    return this->street;
}

std::string Contact::getCity() const {
    return this->city;
}

std::string Contact::getPhoneHome() const {
    return this->phoneHome;
}

std::string Contact::getPhoneCell() const {
    return this->phoneCell;
}

time_t Contact::getAddedAt() const {
    return this->addedAt;
}

time_t Contact::getUpdatedAt() const {
    return this->updatedAt;
}

/**
 * Validating input from user
 * Check: Day of birth format: DD/MM/YYYY (03/12/2000)
 * Check: Cell and Hom phone if they are not empty
 */
bool Contact::validate() {

    bool validation = true;

    boost::regex patternDayOfBirth("\\d{2}[\\//]\\d{2}[\\//]\\d{4}");
    if (!boost::regex_match(this->phoneHome, patternDayOfBirth)) {
        validation = false;
    }
    
    if (this->phoneCell != "") {
        boost::regex patterNumber("^\\+?\\d*$");
        if (!boost::regex_match(this->phoneCell, patterNumber)) {
            validation = false;
        }
    }

    if (this->phoneHome != "") {
        boost::regex patterNumber("^\\+?\\d*$");
        if (!boost::regex_match(this->phoneHome, patterNumber)) {
            validation = false;
        }
    }

    return validation;
}