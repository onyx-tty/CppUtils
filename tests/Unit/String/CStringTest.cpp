// SPDX-FileCopyrightText: 2026 Łukasz Wrodarczyk
// SPDX-License-Identifier: MIT

#include "CppUtils/String/CString.h"

#include <cstddef>
#include <gtest/gtest.h>
#include <optional>
#include <string>

using namespace c_string;

/* c_string_utils::findTerminatorIndex */
TEST(CStrFindTerminatorIndexTest, NormalStringLiteral) {
        constexpr char str[] = "abcde";
        constexpr auto index = findTerminatorIndex(str);
        EXPECT_EQ(index.value(), 5);
}

TEST(CStrFindTerminatorIndexTest, NullTerminatorAlone) {
        constexpr char str[] = "";
        constexpr auto index = findTerminatorIndex(str);
        EXPECT_EQ(index.value(), 0);
}

TEST(CStrFindTerminatorIndexTest, ExplicitNullTerminator) {
        constexpr char str[] = "\0";
        constexpr auto index = findTerminatorIndex(str);
        ASSERT_EQ(index.value(), 0);
        EXPECT_EQ(str[0], '\0');
        EXPECT_EQ(str[1], '\0');
}

TEST(CStrFindTerminatorIndexTest, NoNullTerminator) {
        constexpr char original_str[] = "abcdefg";

        char hacky_str[7]{};
        for (size_t i = 0; original_str[i] != '\0'; ++i) { hacky_str[i] = original_str[i]; }

        const auto index = findTerminatorIndex(hacky_str);
        EXPECT_EQ(index, std::nullopt);
}

/* c_string_utils::join */
TEST(CStrJoinTest, RuntimeStr) {
        const char str1[] = "Hello ";
        const char str2[] = "World!";

        const auto joined_str = join(str1, str2);
        EXPECT_STREQ(joined_str.data(), "Hello World!");
}

TEST(CStrJoinTest, ConstexprStr) {
        constexpr const char str1[] = "Hello ";
        constexpr const char str2[] = "World!";

        const auto joined_str = join(str1, str2);
        EXPECT_STREQ(joined_str.data(), "Hello World!");
}

TEST(CStrJoinTest, Str1NotNullTerminated) {
        char           str1[6]{};
        constexpr char str2[] = "World!";

        for (size_t i = 0; str2[i] != '\0'; ++i) { str1[i] = str2[i]; }

        const auto joined_str = join(str1, str2);
        EXPECT_STREQ(joined_str.data(), "World!World!");
}

TEST(CStrJoinTest, Str2NotNullTerminated) {
        constexpr char str1[] = "Hello ";
        char           str2[6]{};

        for (size_t i = 0; str1[i] != '\0'; ++i) { str2[i] = str1[i]; }

        const auto joined_str = join(str1, str2);
        EXPECT_STREQ(joined_str.data(), "Hello Hello ");
}

TEST(CStrJoinTest, NeitherNullTerminated) {
        constexpr char temp_str1[] = "Hello ";
        constexpr char temp_str2[] = "World!";

        static_assert(sizeof(temp_str1) == sizeof(temp_str2),
                      "Sizes of strings differ in CStrJoinTest.NeitherNullTerminated!");

        char real_str1[6]{}, real_str2[6]{};
        for (size_t i = 0; temp_str1[i] != '\0' && temp_str2[i] != '\0'; ++i) {
                real_str1[i] = temp_str1[i];
                real_str2[i] = temp_str2[i];
        }

        const auto joined_str = join(real_str1, real_str2);
        EXPECT_STREQ(joined_str.data(), "Hello World!");
}

TEST(CStrJoinTest, ConstructString) {
        constexpr char c_str1[] = "Str1";
        constexpr char c_str2[] = "Str2";

        const std::string str = join(c_str1, c_str2).data();
        EXPECT_EQ(str, "Str1Str2");
}
