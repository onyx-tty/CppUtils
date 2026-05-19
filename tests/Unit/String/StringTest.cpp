// SPDX-FileCopyrightText: 2026 Łukasz Wrodarczyk
// SPDX-License-Identifier: MIT

#include "CppUtils/String/StdString.h"

#include <gtest/gtest.h>
#include <string>

using namespace string;

/* toLower */
TEST(ToLowerTest, AllUpper) {
        std::string str = "HELLO";
        toLower(str);
        EXPECT_EQ(str, "hello");
}

TEST(ToLowerTest, MixedCase) {
        std::string str = "WoOzY";
        toLower(str);
        EXPECT_EQ(str, "woozy");
}

TEST(ToLowerTest, AlreadyLower) {
        std::string str = "hello";
        toLower(str);
        EXPECT_EQ(str, "hello");
}

TEST(ToLowerTest, HandlesEmptyString) {
        std::string str = "";
        toLower(str);
        EXPECT_EQ(str, "");
}

/* toUpper */
TEST(ToUpperTest, AllLower) {
        std::string str = "hello";
        toUpper(str);
        EXPECT_EQ(str, "HELLO");
}

TEST(ToUpperTest, MixedCase) {
        std::string str = "WoOzY";
        toUpper(str);
        EXPECT_EQ(str, "WOOZY");
}

TEST(ToUpperTest, AlreadyUpper) {
        std::string str = "HELLO";
        toUpper(str);
        EXPECT_EQ(str, "HELLO");
}

TEST(ToUpperTest, HandlesEmptyString) {
        std::string str = "";
        toUpper(str);
        EXPECT_EQ(str, "");
}
