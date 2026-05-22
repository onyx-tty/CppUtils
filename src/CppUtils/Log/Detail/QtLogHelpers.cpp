// SPDX-FileCopyrightText: 2026 Łukasz Wrodarczyk
// SPDX-License-Identifier: MIT

#include "CppUtils/Log/Detail/QtLogHelpers.h"
#include "CppUtils/String/QtString.h"

#include <source_location>
#include <QString>

// Qt 6.5+ provides a dedicated header <QtTypes>.
// Use it when possible to reduce compilation times.
// For older Qt versions, fall back to the full <QtCore>.
// <QtVersionChecks> didn't exist before Qt 6.5, so it can't be used either.
#if __has_include(<QtTypes>) // Qt >=6.5
        #include <QtTypes>
#else
        #include <QtGlobal> // Qt <6.5
#endif

QString qt::log::detail::getTrimmedFuncName(const std::source_location& loc) {
        QString full = QString::fromStdString(loc.function_name());

        const qsizetype paren = full.indexOf('(');
        if (paren == -1) { return {}; }

        const qsizetype space = full.lastIndexOf(' ', paren);
        if (space == -1) { return {}; }

        return full.mid(space + 1, paren - space - 1);
}
