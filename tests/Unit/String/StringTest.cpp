// SPDX-FileCopyrightText: 2026 Łukasz Wrodarczyk
// SPDX-License-Identifier: MIT

#include "CppUtils/Conversion/ConversionPolicies.h"
#include "CppUtils/String/StdString.h"

#include <gtest/gtest.h>
#include <optional>
#include <string>
#include <type_traits>

using namespace string;

template<typename T>
[[nodiscard]] std::enable_if_t<
        !std::is_pointer_v<std::decay_t<T>> || std::is_same_v<std::decay_t<T>, const char*>
                || (std::is_array_v<T>
                    && (std::is_same_v<std::remove_extent_t<T>, char>
                        || std::is_same_v<std::remove_extent_t<T>, const char>) ),
        std::string> static filteredToStringWrapper(const T& value, ConversionPolicies policies =
                                                                            ConversionPolicies{}) {
        return filteredToString(value, policies).value_or("NULLOPT");
}

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

/* string_utils::filteredToString */
TEST(FilteredToStringTest, HandleInteger) {
        EXPECT_EQ(filteredToStringWrapper(34), "34");
}

TEST(FilteredToStringTest, HandleLong) {
        EXPECT_EQ(filteredToStringWrapper(34l), "34");
}

TEST(FilteredToStringTest, HandleFloat) {
        EXPECT_EQ(filteredToStringWrapper(3.4f), "3.400000");
}

TEST(FilteredToStringTest, HandleDouble) {
        EXPECT_EQ(filteredToStringWrapper(3.4), "3.400000");
}

TEST(FilteredToStringTest, HandleChar) {
        EXPECT_EQ(filteredToStringWrapper('f'), "102");
}

TEST(FilteredToStringTest, HandleBool) {
        EXPECT_EQ(filteredToStringWrapper(true), "1");
}

TEST(FilteredToStringTest, HandleString) {
        const std::string somestr = "somestr";
        EXPECT_EQ(filteredToStringWrapper(somestr), "somestr");
}

TEST(FilteredToStringTest, HandleEmptyString) {
        const std::string emptystr = "";
        EXPECT_EQ(filteredToStringWrapper(emptystr), "");
}

TEST(FilteredToStringTest, HandleCString) {
        const char  somecstr_carr[] = "const array";
        char        somecstr_arr[]  = "array";
        const char* somecstr_ptr    = "pointer";

        EXPECT_EQ(filteredToStringWrapper(somecstr_carr), "const array");
        EXPECT_EQ(filteredToStringWrapper(somecstr_arr), "array");
        EXPECT_EQ(filteredToStringWrapper(somecstr_ptr), "pointer");
}

TEST(FilteredToStringTest, HandleEmptyCString) {
        const char  emptycstr_carr[] = "";
        char        emptycstr_arr[]  = "";
        const char* emptycstr_ptr    = "";

        EXPECT_EQ(filteredToStringWrapper(emptycstr_carr), "");
        EXPECT_EQ(filteredToStringWrapper(emptycstr_arr), "");
        EXPECT_EQ(filteredToStringWrapper(emptycstr_ptr), "");
}

TEST(FilteredToStringTest, HandleReferences) {
        std::string  str    = "abc";
        std::string& strref = str;

        int  i    = 5;
        int& iref = i;

        char  ch    = 'f';
        char& chref = ch;

        char cstr[]        = "abcdef";
        char (&cstrref)[7] = cstr;

        bool  b    = false;
        bool& bref = b;

        float  f    = 3.14;
        float& fref = f;

        EXPECT_EQ(filteredToStringWrapper(strref), "abc");
        EXPECT_EQ(filteredToStringWrapper(iref), "5");
        EXPECT_EQ(filteredToStringWrapper(chref), "102");
        EXPECT_EQ(filteredToStringWrapper(cstrref), "abcdef");
        EXPECT_EQ(filteredToStringWrapper(bref), "0");
        EXPECT_EQ(filteredToStringWrapper(fref), "3.140000");
}

TEST(FilteredToStringTest, HandleConstReferences) {
        std::string        str     = "abc";
        const std::string& strcref = str;

        const int  i     = 5;
        const int& icref = i;

        const char  ch     = 'f';
        const char& chcref = ch;

        const char cstr[]         = "abcdef";
        const char (&cstrcref)[7] = cstr;

        const bool  b     = false;
        const bool& bcref = b;

        const float  f     = 3.14;
        const float& fcref = f;

        EXPECT_EQ(filteredToStringWrapper(strcref), "abc");
        EXPECT_EQ(filteredToStringWrapper(icref), "5");
        EXPECT_EQ(filteredToStringWrapper(chcref), "102");
        EXPECT_EQ(filteredToStringWrapper(cstrcref), "abcdef");
        EXPECT_EQ(filteredToStringWrapper(bcref), "0");
        EXPECT_EQ(filteredToStringWrapper(fcref), "3.140000");
}
