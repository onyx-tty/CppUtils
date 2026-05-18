// SPDX-FileCopyrightText: 2026 Łukasz Wrodarczyk
// SPDX-License-Identifier: MIT

#pragma once

#include "CppUtils/Log/Detail/QtLogHelpers.h"

#include <source_location>
#include <QString>

// Qt 6.5+ provides dedicated headers <QtLogging> and <QtTypes>.
// Use them when possible to reduce compilation times.
// For older Qt versions, fall back to the full <QtCore>.
// <QtVersionChecks> didn't exist before Qt 6.5, so it can't be used either.
#if __has_include(<QtEnvironmentVariables>) // Qt >=6.5
#       include <QtLogging>
#       include <QtTypes>
#else
#       include <QtGlobal> // Qt <6.5
#endif

namespace qt::log::detail {

void fatalImpl(const QString& msg, const std::source_location& loc) {
        const QString fn = getTrimmedFuncName(loc);
        qFatal("\033[31m[FATAL]\033[0m    %s : %s", fn.toStdString().c_str(),
               msg.toStdString().c_str());
}

[[nodiscard]] QString getTrimmedFuncName(const std::source_location& loc) {
        QString full = QString::fromStdString(loc.function_name());

        const qsizetype paren = full.indexOf('(');
        if (paren == -1) { return {}; }

        const qsizetype space = full.lastIndexOf(' ', paren);
        if (space == -1) { return {}; }

        return full.mid(space + 1, paren - space - 1);
}

} // namespace qt::log::detail
