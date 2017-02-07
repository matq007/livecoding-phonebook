//
// Created by Martin Proks on 9/27/15.
//

#include <iostream>
#include "gtest/gtest.h"
#include "PhoneBookCollection.h"

class PhoneBookCollectionTest : public ::testing::Test {

protected:

    PhoneBookCollectionTest() {
    }

    virtual ~PhoneBookCollectionTest() {
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

    PhoneBookCollection p;
};

TEST_F(PhoneBookCollectionTest, RemoveIndexOutOfRange) {
    Contact contact1;
    Contact contact2;
    contact1.setID(1);
    contact1.setID(2);
    p.add(contact1);
    p.add(contact2);

    EXPECT_TRUE(p.verifyIndex(1));
    EXPECT_FALSE(p.verifyIndex(10));
}
