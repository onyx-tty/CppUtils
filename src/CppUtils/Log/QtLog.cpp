// SPDX-FileCopyrightText: 2026 Łukasz Wrodarczyk
// SPDX-License-Identifier: MIT

#include "CppUtils/Log/QtLog.h"

#include <QString>
#include <QtGlobal>

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
