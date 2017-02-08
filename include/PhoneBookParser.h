//
// Created by Martin Proks on 9/6/15.
//

#ifndef LIVECODING_PHONEBOOK_PARSER_H
#define LIVECODING_PHONEBOOK_PARSER_H

#include "tinyxml2/tinyxml2.h"
#include "PhoneBookCollection.h"

class PhoneBookParser {

private:

    std::string phoneBookFileName;
    tinyxml2::XMLDocument xml;

public:

    PhoneBookParser(const std::string& phoneBookFileName);

    void load();
    bool exists() const;
    void createXML();
    unsigned int getMaxID();

    PhoneBookCollection loadDataFromXML();
    void store(PhoneBookCollection phoneBookList);

};


#endif //LIVECODING_PHONEBOOK_PARSER_H
