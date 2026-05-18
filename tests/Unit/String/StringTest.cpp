// SPDX-FileCopyrightText: 2026 Łukasz Wrodarczyk
// SPDX-License-Identifier: MIT

#include "CppUtils/String/StdString.h"

#include <gtest/gtest.h>
#include <string>

using namespace string;

/* string_utils::toLower */
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

TEST(ToLowerTest, EmptyString) {
        std::string str = "";
        toLower(str);
        EXPECT_EQ(str, "");
}

/* string_utils::makeLower */
TEST(makeLowerTest, AllUpper) {
        const std::string str = makeLower("HELLO");
        EXPECT_EQ(str, "hello");
}

TEST(makeLowerTest, MixedCase) {
        const std::string str = makeLower("WoOzY");
        EXPECT_EQ(str, "woozy");
}

TEST(makeLowerTest, AlreadyLower) {
        const auto str = makeLower("hello");
        EXPECT_EQ(str, "hello");
}

TEST(makeLowerTest, EmptyString) {
        const auto str = makeLower("");
        EXPECT_EQ(str, "");
}
