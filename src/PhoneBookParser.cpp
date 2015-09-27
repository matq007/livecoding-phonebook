//
// Created by Martin Proks on 9/6/15.
//

#include "PhoneBookParser.h"

PhoneBookParser::PhoneBookParser(std::string phoneBookFileName) {

    this->phoneBookFileName  = phoneBookFileName;

}

void PhoneBookParser::load() {

    if(this->exists()) {

        std::cout << "[INFO]: Loading XML file" << std::endl;

        tinyxml2::XMLError eResult = this->xml.LoadFile(this->phoneBookFileName.c_str());

        if (eResult != tinyxml2::XML_SUCCESS) {
            std::cout << "[ERROR]: In loading XML file on startup, closing application" << std::endl;
            exit(-1);
        }

    } else {
        std::cout << "[INFO]: File not found, creating new one" << std::endl;
        this->createXML();
    }

}

/**
 * Checks if XML File already exists
 * @return true if file exists
 */
bool PhoneBookParser::exists() {

    std::ifstream infile(this->phoneBookFileName);
    return infile.good();
}

/**
 * Creates empty default structure of XML File
 */
void PhoneBookParser::createXML() {

    tinyxml2::XMLNode *pRoot = this->xml.NewElement("phoneBook");
    this->xml.InsertFirstChild(pRoot);

    tinyxml2::XMLElement *idElement = this->xml.NewElement("ID_MAX");
    idElement->SetText(0);
    pRoot->InsertEndChild(idElement);

    tinyxml2::XMLElement *contactsElement = this->xml.NewElement("contacts");
    pRoot->InsertEndChild(contactsElement);

    tinyxml2::XMLError eResult = this->xml.SaveFile(this->phoneBookFileName.c_str());
    if (eResult != tinyxml2::XML_SUCCESS) {
        std::cout << "[ERROR]: In creating XML file" << std::endl;
    }
}

/**
 * Loads XML File and parses data
 * @return parsed data in vector
 */
PhoneBookCollection PhoneBookParser::loadDataFromXML() {

    tinyxml2::XMLNode* root = this->xml.FirstChild();
    PhoneBookCollection phoneBookList;

    phoneBookList.setMaxID(this->getMaxID());

    if (root != nullptr) {

        tinyxml2::XMLElement* contactsElement = root->FirstChildElement("contacts");
        tinyxml2::XMLElement* contactElement = contactsElement->FirstChildElement("contact");

        while(contactElement != nullptr) {

            int _id;
            contactElement->QueryIntAttribute("id", &_id);

            int _addedAt;
            tinyxml2::XMLElement* addedElement = contactElement->FirstChildElement("addedAt");
            addedElement->QueryIntText(&_addedAt);

            int _updatedAt;
            tinyxml2::XMLElement* updatedElement = contactElement->FirstChildElement("updatedAt");
            updatedElement->QueryIntText(&_updatedAt);

            Contact tmpContact;
            tmpContact.setID(_id);
            tmpContact.setName(contactElement->FirstChildElement("name")->GetText());
            tmpContact.setMiddleName(contactElement->FirstChildElement("middlename")->GetText());
            tmpContact.setSurname(contactElement->FirstChildElement("surname")->GetText());
            tmpContact.setTitle(contactElement->FirstChildElement("title")->GetText());
            tmpContact.setDateOfBirth(contactElement->FirstChildElement("dateOfBirth")->GetText());
            tmpContact.setStreet(contactElement->FirstChildElement("street")->GetText());
            tmpContact.setCity(contactElement->FirstChildElement("city")->GetText());
            tmpContact.setPhoneHome(contactElement->FirstChildElement("home")->GetText());
            tmpContact.setPhoneCell(contactElement->FirstChildElement("cell")->GetText());


            tmpContact.setAddedAt( (time_t) _addedAt);
            tmpContact.setUpdatedAt( (time_t) _updatedAt);

            phoneBookList.add(tmpContact);

            contactElement = contactElement->NextSiblingElement("contact");
        }
    }

    return phoneBookList;
}

/**
 * Returns Max ID, every user has its specific ID, MUST BE UNIQUE
 * @return current maxID
 */
unsigned int PhoneBookParser::getMaxID() {

    tinyxml2::XMLNode *pRoot = this->xml.FirstChild();
    tinyxml2::XMLElement *idElement = pRoot->FirstChildElement("ID_MAX");
    if (idElement == nullptr) {
        std::cout << "[ERROR]: Finding element MAX ID" << std::endl;
        exit(-1);
    }

    int id;
    idElement->QueryIntText(&id);

    return (unsigned int) id;
}

/**
 * Saving XML File
 */
void PhoneBookParser::store(PhoneBookCollection phoneBookList) {

    this->xml.Clear();

    tinyxml2::XMLNode *pRoot = this->xml.NewElement("phoneBook");
    this->xml.InsertFirstChild(pRoot);

    tinyxml2::XMLElement *idElement = this->xml.NewElement("ID_MAX");
    idElement->SetText(phoneBookList.getMaxID());
    pRoot->InsertEndChild(idElement);

    // CONTACTS ELEMENT
    tinyxml2::XMLElement* contactsElement = this->xml.NewElement("contacts");
    pRoot->InsertEndChild(contactsElement);

    std::vector<Contact> contacts = phoneBookList.getPhoneBook();

    for (unsigned long i = 0; i < contacts.size(); i ++) {

        // CONTACT ELEMENT
        tinyxml2::XMLElement* contactElement = this->xml.NewElement("contact");
        contactElement->SetAttribute("id", contacts[i].getID());
        pRoot->InsertEndChild(contactElement);

        // NAME
        tinyxml2::XMLElement* nameElement = this->xml.NewElement("name");
        nameElement->SetText(contacts.at(i).getName().c_str());
        contactElement->InsertEndChild(nameElement);

        // MIDDLENAME
        tinyxml2::XMLElement* midElement = this->xml.NewElement("middlename");
        midElement->SetText(contacts.at(i).getMiddleName().c_str());
        contactElement->InsertEndChild(midElement);

        // SURNAME
        tinyxml2::XMLElement* surElement = this->xml.NewElement("surname");
        surElement->SetText(contacts.at(i).getSurname().c_str());
        contactElement->InsertEndChild(surElement);

        // TITLE
        tinyxml2::XMLElement* titleElement = this->xml.NewElement("title");
        titleElement->SetText(contacts.at(i).getTitle().c_str());
        contactElement->InsertEndChild(titleElement);

        // DATE OF BIRTH
        tinyxml2::XMLElement* birthElement = this->xml.NewElement("dateOfBirth");
        birthElement->SetText(contacts.at(i).getDateOfBirth().c_str());
        contactElement->InsertEndChild(birthElement);

        // STREET
        tinyxml2::XMLElement* streetElement = this->xml.NewElement("street");
        streetElement->SetText(contacts.at(i).getStreet().c_str());
        contactElement->InsertEndChild(streetElement);

        // CITY
        tinyxml2::XMLElement* cityElement = this->xml.NewElement("city");
        cityElement->SetText(contacts.at(i).getCity().c_str());
        contactElement->InsertEndChild(cityElement);

        // PHONE HOME
        tinyxml2::XMLElement* pHoneElement = this->xml.NewElement("home");
        pHoneElement->SetText(contacts.at(i).getPhoneHome().c_str());
        contactElement->InsertEndChild(pHoneElement);

        // CELL HOME
        tinyxml2::XMLElement* pCellElement = this->xml.NewElement("cell");
        pCellElement->SetText(contacts.at(i).getPhoneCell().c_str());
        contactElement->InsertEndChild(pCellElement);

        // ADDED AT
        tinyxml2::XMLElement* addedAtElement = this->xml.NewElement("addedAt");
        addedAtElement->SetText((int) contacts.at(i).getAddedAt());
        contactElement->InsertEndChild(addedAtElement);

        // UPDATED AT
        tinyxml2::XMLElement* updatedAtElement = this->xml.NewElement("updatedAt");
        updatedAtElement->SetText((int) contacts.at(i).getUpdatedAt());
        contactElement->InsertEndChild(updatedAtElement);

        contactsElement->InsertEndChild(contactElement);
    }

    // SAVING
    tinyxml2::XMLError eResult = this->xml.SaveFile(this->phoneBookFileName.c_str());
    if (eResult != tinyxml2::XML_SUCCESS) {
        std::cout << "[ERROR]: In creating XML file" << std::endl;
    }

}