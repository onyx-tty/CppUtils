// SPDX-FileCopyrightText: 2026 Łukasz Wrodarczyk
// SPDX-License-Identifier: MIT

#pragma once

#include "CppUtils/String/QtString.h"

#include <source_location>
#include <QString>

// Qt 6.5+ provides a dedicated header <QtLogging>.
// Use it when possible to reduce compilation times.
// For older Qt versions, fall back to the full <QtCore>.
// <QtVersionChecks> didn't exist before Qt 6.5, so it can't be used either.
#if __has_include(<QtLogging>) // Qt >=6.5
        #include <QtLogging>
#else
        #include <QtGlobal> // Qt <6.5
#endif

namespace qt::log::detail {

[[nodiscard]] QString getTrimmedFuncName(const std::source_location& loc);

inline void fatalImpl(const QString& msg, const std::source_location& loc = std::source_location::current()) {
        const QString fn = getTrimmedFuncName(loc);
        qFatal("\033[31m[FATAL]\033[0m    %s : %s", fn.toStdString().c_str(),
               msg.toStdString().c_str());
}

// Concatenate all arguments into one string
[[nodiscard]] inline QString concatArgs() {
        return "";
}

template<typename MainStr, typename... RestStr>
[[nodiscard]] inline QString concatArgs(const MainStr& main_string, const RestStr&... rest_strings) {
        return qt::string::toQString(main_string) + " " + concatArgs(rest_strings...);
}

} // namespace qt::log::detail
