// SPDX-FileCopyrightText: 2026 Łukasz Wrodarczyk
// SPDX-License-Identifier: MIT

#pragma once

#include "CppUtils/Log/Detail/QtLogHelpers.h"
#include "CppUtils/String/QtString.h"

template<typename MainStr, typename... RestStr>
inline QString concatArgs(const MainStr& main_string, const RestStr&... rest_strings) {
        return qt::string::toQString(main_string) + " " + concatArgs(rest_strings...);
}
