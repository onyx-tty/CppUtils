// SPDX-FileCopyrightText: 2026 Łukasz Wrodarczyk
// SPDX-License-Identifier: MIT

#pragma once

#include <string>

namespace string {

// Turn all characters lowercase
void toLower(std::string& str);

// Return a lowercase copy
[[nodiscard]] std::string toLowerCopy(std::string str);

} // namespace string
