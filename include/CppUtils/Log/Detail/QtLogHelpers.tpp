// SPDX-FileCopyrightText: 2026 Łukasz Wrodarczyk
// SPDX-License-Identifier: MIT

#pragma once

#include "CppUtils/Log/Detail/QtLogHelpers.h"
#include "CppUtils/String/QtString.h"

#include <QString>

void qt::log::detail::fatalImpl(const QString& msg, const std::source_location& loc) {
        const QString fn = getTrimmedFuncName(loc);
        qFatal("\033[31m[FATAL]\033[0m    %s : %s", fn.toStdString().c_str(),
               msg.toStdString().c_str());
}

[[nodiscard]] QString qt::log::detail::getTrimmedFuncName(const std::source_location& loc) {
        QString full = QString::fromStdString(loc.function_name());

        const qsizetype paren = full.indexOf('(');
        if (paren == -1) { return {}; }

        const qsizetype space = full.lastIndexOf(' ', paren);
        if (space == -1) { return {}; }

        return full.mid(space + 1, paren - space - 1);
}

template<typename MainStr, typename... RestStr>
inline QString concatArgs(const MainStr& main_string, const RestStr&... rest_strings) {
        return qt::string::toQString(main_string) + " " + concatArgs(rest_strings...);
}
