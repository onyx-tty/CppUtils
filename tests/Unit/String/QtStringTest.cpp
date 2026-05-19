// SPDX-FileCopyrightText: 2026 Łukasz Wrodarczyk
// SPDX-License-Identifier: MIT

#include "CppUtils/String/QtString.h"

#include <gtest/gtest.h>
#include <string>
#include <QString>

using namespace qt::string;

/* toQString */
TEST(ToQStringTest, HandlesQString) {
        QString qstr = "aBc";
        EXPECT_EQ(toQString(qstr), "aBc");
}

TEST(ToQStringTest, HandlesStdString) {
        std::string str = "aBcDeF";
        EXPECT_EQ(toQString(str), "aBcDeF");
}

TEST(ToQStringTest, HandlesNumbers) {
        constexpr int    i  = 5;
        constexpr long   l  = -10;
        constexpr float  f  = 7.11;
        constexpr double d  = 11.7;
        constexpr char   ch = 'a';

        EXPECT_EQ(toQString(i), "5");
        EXPECT_EQ(toQString(l), "-10");
        EXPECT_EQ(toQString(f), "7.11");
        EXPECT_EQ(toQString(d), "11.7");
        EXPECT_EQ(toQString(ch), "97");
}

TEST(ToQStringTest, HandlesUnsigned) {
        constexpr unsigned      u   = 100;
        constexpr unsigned long ul  = 2000;
        constexpr unsigned char uch = 'Z';

        EXPECT_EQ(toQString(u), "100");
        EXPECT_EQ(toQString(ul), "2000");
        EXPECT_EQ(toQString(uch), "90");
}

TEST(ToQStringTest, HandlesReferences) {
        unsigned u  = 100;
        char     ch = 'a';

        unsigned& uref   = u;
        char&     chrref = ch;

        EXPECT_EQ(toQString(uref), "100");
        EXPECT_EQ(toQString(chrref), "97");
}
