// SPDX-FileCopyrightText: 2026 Łukasz Wrodarczyk
// SPDX-License-Identifier: MIT

#pragma once

#include <cstdlib>
#include <optional>

namespace c_string {

// Find index of the null terminator
template<size_t N>
[[nodiscard]] constexpr std::optional<size_t> findTerminatorIndex(const char (&str)[N]);

// Return a copy of two concatenated strings
template<size_t N1, size_t N2>
[[nodiscard]] auto join(const char (&str1)[N1], const char (&str2)[N2], bool allow_empty = false);

} // namespace c_string

#include "CString.tpp"
