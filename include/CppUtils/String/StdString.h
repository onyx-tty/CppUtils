// SPDX-FileCopyrightText: 2026 Łukasz Wrodarczyk
// SPDX-License-Identifier: MIT

#pragma once

#include <string>

namespace string {

// Turn all characters lowercase
void toLower(std::string& str);

// Return a lowercase copy
[[nodiscard]] std::string makeLower(std::string str);

// Turn all characters uppercase
void toUpper(std::string& str);

// Return an uppercase copy
[[nodiscard]] std::string makeUpper(std::string str);

} // namespace string
