// SPDX-FileCopyrightText: 2026 Łukasz Wrodarczyk
// SPDX-License-Identifier: MIT

#include "CppUtils/String/StdString.h"

#include <cctype>
#include <string>

void string::toLower(std::string& str) {
        // TODO Eliminate narrowing conversion
        for (char& ch : str) { ch = std::tolower(static_cast<unsigned char>(ch)); }
}

std::string string::toLowerCopy(std::string str) {
        string::toLower(str);
        return str;
}
