// SPDX-FileCopyrightText: 2026 Łukasz Wrodarczyk
// SPDX-License-Identifier: MIT

#pragma once

#include "CppUtils/String/CString.h"

#include <cassert>
#include <stdexcept>
#include <vector>

namespace c_string {

template<size_t N>
constexpr std::optional<size_t> findTerminatorIndex(const char (&str)[N]) {
        for (size_t i = 0; i != N; ++i) {
                if (str[i] == '\0') { return i; }
        }

        return std::nullopt; // not found
}

template<size_t N1, size_t N2>
auto join(const char (&str1)[N1], const char (&str2)[N2], bool allow_empty) {
        // Find actual length
        const size_t n1 = findTerminatorIndex(str1).value_or(N1),
                     n2 = findTerminatorIndex(str2).value_or(N2);

        // Handle both being empty
        if (n1 + n2 == 0) {
                if (allow_empty) {
                        return std::vector<char>{'\0'};
                } else {
                        throw std::runtime_error("Passed empty strings to c_string_utils::join!");
                }
        }

        std::vector<char> result{};
        result.reserve(n1 + n2 + 1); // +1 for null terminator

        result.insert(result.end(), str1, str1 + n1);
        result.insert(result.end(), str2, str2 + n2);
        result.push_back('\0'); // null terminate

        return result;
}

} // namespace c_string
