// SPDX-FileCopyrightText: 2026 Łukasz Wrodarczyk
// SPDX-License-Identifier: MIT

#pragma once

#include <cstddef>
#include <string_view>
#include <QString>

namespace qt {
namespace log {
namespace detail {

// TODO Return pair instead
[[nodiscard]] constexpr size_t getTrimmedPrettyFunctionOffset(std::string_view pretty_function) {
        const size_t paren = pretty_function.find('(');
        if (paren == std::string_view::npos) { return 0; }

        const size_t space = pretty_function.rfind(' ', paren);
        if (space == std::string_view::npos) { return 0; }

        return space + 1;
}

[[nodiscard]] constexpr size_t getTrimmedPrettyFunctionLength(std::string_view pretty_function) {
        const size_t paren = pretty_function.find('(');
        if (paren == std::string_view::npos) { return pretty_function.size(); }

        const size_t space = pretty_function.rfind(' ', paren);
        if (space == std::string_view::npos) { return paren; }

        return paren - space - 1;
}

// Concatenate all arguments into one string
[[nodiscard]] inline QString concatArgs() {
        return "";
}

template<typename MainStr, typename... RestStr>
[[nodiscard]] inline QString concatArgs(const MainStr& main_string, const RestStr&... rest_strings);

} // namespace detail
} // namespace log
} // namespace qt

#include "QtLogHelpers.tpp"
