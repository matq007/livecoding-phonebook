//
// Created by Martin Proks on 9/26/15.
//

#include <iostream>
#include "gtest/gtest.h"
#include "../src/Contact.h"

class ContactTest : public ::testing::Test {

protected:

    ContactTest() {
    }

    virtual ~ContactTest() {
    }

    // If the constructor and destructor are not enough for setting up
    // and cleaning up each test, you can define the following methods:
    virtual void SetUp() {
        // Code here will be called immediately after the constructor (right
        // before each test).
    }

    virtual void TearDown() {
        // Code here will be called immediately after each test (right
        // before the destructor).
    }

    Contact c;
};

TEST_F(ContactTest, setName) {
    c.setName("Martin");
    EXPECT_EQ("Martin", c.getName());
}

TEST_F(ContactTest, CorrectFormatDayOfBirth) {
    c.setDateOfBirth("3.3.2010");
    bool res = c.validate();
    EXPECT_FALSE(res);
}

TEST_F(ContactTest, CorrectFormatCellPhone) {
    c.setPhoneCell("-");
    bool res = c.validate();
    EXPECT_FALSE(res);
}