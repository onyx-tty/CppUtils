// SPDX-FileCopyrightText: 2026 Łukasz Wrodarczyk
// SPDX-License-Identifier: MIT

#include "CppUtils/Log/QtLog.h"

#include <QString>

// Qt 6.5+ provides a dedicated header <QtLogging>.
// Use it when possible to reduce compilation times.
// For older Qt versions, fall back to the full <QtCore>.
// <QtVersionChecks> didn't exist before Qt 6.5, so it can't be used either.
#if __has_include(<QtEnvironmentVariables>) // Qt >=6.5
        #include <QtLogging>
#else
        #include <QtGlobal> // Qt <6.5
#endif

void qt::log::setupLogging() {
        using namespace Qt::StringLiterals;

        // clang-format off
        qSetMessagePattern(
                u"%{if-fatal}\033[31m[FATAL]\033[0m   %{endif}"_s
                u"%{if-critical}\033[35m[CRITICAL]\033[0m%{endif}"_s
                u"%{if-warning}\033[33m[WARNING]\033[0m %{endif}"_s
                u"%{if-debug}\033[36m[DEBUG]\033[0m   %{endif}"_s
                u"%{if-info}\033[32m[INFO]\033[0m    %{endif}"_s
                u" %{function}: %{message}"_s);
        // clan-format on
}
