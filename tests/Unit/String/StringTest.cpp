// SPDX-FileCopyrightText: 2026 Łukasz Wrodarczyk
// SPDX-License-Identifier: MIT

#include "CppUtils/String/StdString.h"

#include <gtest/gtest.h>
#include <string>

using namespace string;

/* toLower */
TEST(ToLowerTest, HandlesAllUpper) {
        std::string str = "HELLO";
        toLower(str);
        EXPECT_EQ(str, "hello");
}

TEST(ToLowerTest, HandlesMixedCase) {
        std::string str = "WoOzY";
        toLower(str);
        EXPECT_EQ(str, "woozy");
}

TEST(ToLowerTest, HandlesAlreadyLower) {
        std::string str = "hello";
        toLower(str);
        EXPECT_EQ(str, "hello");
}

TEST(ToLowerTest, HandlesEmptyString) {
        std::string str = "";
        toLower(str);
        EXPECT_EQ(str, "");
}

/* makeLower */
TEST(MakeLowerTest, HandlesAllUpper) {
        const std::string str = makeLower("HELLO");
        EXPECT_EQ(str, "hello");
}

TEST(MakeLowerTest, HandlesMixedCase) {
        const std::string str = makeLower("WoOzY");
        EXPECT_EQ(str, "woozy");
}

TEST(MakeLowerTest, HandlesAlreadyLower) {
        const auto str = makeLower("hello");
        EXPECT_EQ(str, "hello");
}

TEST(MakeLowerTest, HandlesEmptyString) {
        const auto str = makeLower("");
        EXPECT_EQ(str, "");
}

/* toUpper */
TEST(ToUpperTest, HandlesAllLower) {
        std::string str = "hello";
        toUpper(str);
        EXPECT_EQ(str, "HELLO");
}

TEST(ToUpperTest, HandlesMixedCase) {
        std::string str = "WoOzY";
        toUpper(str);
        EXPECT_EQ(str, "WOOZY");
}

TEST(ToUpperTest, HandlesAlreadyUpper) {
        std::string str = "HELLO";
        toUpper(str);
        EXPECT_EQ(str, "HELLO");
}

TEST(ToUpperTest, HandlesEmptyString) {
        std::string str = "";
        toUpper(str);
        EXPECT_EQ(str, "");
}

/* makeUpper */
TEST(MakeUpperTest, HandlesAllLower) {
        const std::string str = makeUpper("hello");
        EXPECT_EQ(str, "HELLO");
}

TEST(MakeUpperTest, HandlesMixedCase) {
        const std::string str = makeUpper("WoOzY");
        EXPECT_EQ(str, "WOOZY");
}

TEST(MakeUpperTest, HandlesAlreadyUpper) {
        const auto str = makeUpper("HELLO");
        EXPECT_EQ(str, "HELLO");
}

TEST(MakeUpperTest, HandlesEmptyString) {
        const auto str = makeUpper("");
        EXPECT_EQ(str, "");
}
