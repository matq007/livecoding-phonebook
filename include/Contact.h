//
// Created by Martin Proks on 9/6/15.
//

#ifndef LIVECODING_PHONEBOOK_PERSON_H
#define LIVECODING_PHONEBOOK_PERSON_H

#endif //LIVECODING_PHONEBOOK_PERSON_H

#include <iostream>
#include <string>
#include <ctime>
#include <regex>

class Contact {

private:

    unsigned int id;
    std::string name;
    std::string middleName;
    std::string surname;
    std::string title;
    std::string dateOfBirth;
    std::string street;
    std::string city;
    std::string phoneHome;
    std::string phoneCell;
    std::time_t addedAt;
    std::time_t updatedAt;

public:

    Contact();
    void prettyPrint();
    bool validate();

    void setID(unsigned int id);
    void setName(std::string name);
    void setMiddleName(std::string middleName);
    void setSurname(std::string surname);
    void setTitle(std::string title);
    void setDateOfBirth(std::string dateOfBirth);
    void setStreet(std::string street);
    void setCity(std::string city);
    void setPhoneHome(std::string number);
    void setPhoneCell(std::string number);
    void setAddedAt(time_t addedAt);
    void setUpdatedAt(time_t updatedAt);

    unsigned int getID();
    std::string getName();
    std::string getMiddleName();
    std::string getSurname();
    std::string getTitle();
    std::string getDateOfBirth();
    std::string getStreet();
    std::string getCity();
    std::string getPhoneHome();
    std::string getPhoneCell();
    time_t getAddedAt();
    time_t getUpdatedAt();

};