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

/* string_utils::toLowerCopy */
TEST(ToLowerCopyTest, AllUpper) {
        const std::string str = toLowerCopy("HELLO");
        EXPECT_EQ(str, "hello");
}

TEST(ToLowerCopyTest, MixedCase) {
        const std::string str = toLowerCopy("WoOzY");
        EXPECT_EQ(str, "woozy");
}

TEST(ToLowerCopyTest, AlreadyLower) {
        const auto str = toLowerCopy("hello");
        EXPECT_EQ(str, "hello");
}

TEST(ToLowerCopyTest, EmptyString) {
        const auto str = toLowerCopy("");
        EXPECT_EQ(str, "");
}
