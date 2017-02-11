//
// Created by Martin Proks on 9/26/15.
//

#include <iostream>
#include "gtest/gtest.h"
#include "Contact.h"

class ContactTest : public ::testing::Test {

protected:

    ContactTest() {
    }

    virtual ~ContactTest() {
    }

    // If the constructor and destructor are not enough for setting up
    // and cleaning up each test, you can define the following methods:
    virtual void SetUp() {

    }

    virtual void TearDown() {
        // Code here will be called immediately after each test (right
        // before the destructor).
    }

    Contact c;

};

TEST_F(ContactTest, CorrectNameSet) {
    c.setName("Martin");
    EXPECT_EQ("Martin", c.getName());
}

TEST_F(ContactTest, CorrectValidation) {
    EXPECT_FALSE(c.validate());
}

TEST_F(ContactTest, ValidationPhoneHomeFail) {
    c.setDateOfBirth("03/12/2000");
    c.setPhoneHome("-");
    c.setPhoneCell("123456");
    EXPECT_FALSE(c.validate());
}

TEST_F(ContactTest, ValidationPhoneCellFail) {
    c.setDateOfBirth("03/12/2000");
    c.setPhoneHome("123456");
    c.setPhoneCell("-");
    EXPECT_FALSE(c.validate());
}

TEST_F(ContactTest, ValidationBirthFormatFail) {
    c.setDateOfBirth("3.12.2000");
    c.setPhoneHome("123456");
    c.setPhoneCell("123456");
    EXPECT_FALSE(c.validate());
}
