//
// Created by Martin Proks on 9/6/15.
//

#ifndef LIVECODING_PHONEBOOK_PERSON_H
#define LIVECODING_PHONEBOOK_PERSON_H

#endif //LIVECODING_PHONEBOOK_PERSON_H

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
    void setName(const std::string& name);
    void setMiddleName(const std::string& middleName);
    void setSurname(const std::string& surname);
    void setTitle(const std::string& title);
    void setDateOfBirth(const std::string& dateOfBirth);
    void setStreet(const std::string& street);
    void setCity(const std::string& city);
    void setPhoneHome(const std::string& number);
    void setPhoneCell(const std::string& number);
    void setAddedAt(time_t addedAt);
    void setUpdatedAt(time_t updatedAt);

    unsigned int getID() const;
    std::string getName() const;
    std::string getMiddleName() const;
    std::string getSurname() const;
    std::string getTitle() const;
    std::string getDateOfBirth() const;
    std::string getStreet() const;
    std::string getCity() const;
    std::string getPhoneHome() const;
    std::string getPhoneCell() const;
    time_t getAddedAt() const;
    time_t getUpdatedAt() const;

};