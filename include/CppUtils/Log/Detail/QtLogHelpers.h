// SPDX-FileCopyrightText: 2026 Łukasz Wrodarczyk
// SPDX-License-Identifier: MIT

#pragma once

#include <cstddef>
#include <source_location>
#include <string_view>
#include <QString>

namespace qt {
namespace log {
namespace detail {

void fatalImpl(const QString&              msg,
               const std::source_location& loc = std::source_location::current());

[[nodiscard]] QString getTrimmedFuncName(const std::source_location& loc);

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
