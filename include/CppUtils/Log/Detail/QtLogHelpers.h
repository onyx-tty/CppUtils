// SPDX-FileCopyrightText: 2026 Łukasz Wrodarczyk
// SPDX-License-Identifier: MIT

#pragma once

#include "CppUtils/String/QtString.h"

#include <cstddef>
#include <source_location>
#include <string_view>
#include <QString>

namespace qt::log::detail {

void fatalImpl(const QString&              msg,
               const std::source_location& loc = std::source_location::current());

[[nodiscard]] QString getTrimmedFuncName(const std::source_location& loc);

// Concatenate all arguments into one string
[[nodiscard]] inline QString concatArgs() {
        return "";
}

template<typename MainStr, typename... RestStr>
[[nodiscard]] inline QString concatArgs(const MainStr& main_string, const RestStr&... rest_strings) {
        return qt::string::toQString(main_string) + " " + concatArgs(rest_strings...);
}

} // namespace qt::log::detail

#include "QtLogHelpers.tpp"
