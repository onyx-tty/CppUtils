// SPDX-FileCopyrightText: 2026 Łukasz Wrodarczyk
// SPDX-License-Identifier: MIT

#include "CppUtils/String/StdString.h"

#include <cctype>
#include <string>

void string::toLower(std::string& str) {
        for (char& ch : str) {
                ch = static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));
        }
}

std::string string::makeLower(std::string str) {
        string::toLower(str);
        return str;
}
