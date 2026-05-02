// SPDX-FileCopyrightText: 2026 Łukasz Wrodarczyk
// SPDX-License-Identifier: MIT

#pragma once

#include "CppUtils/Conversion/ConversionPolicies.h"

#include <optional>
#include <string>

namespace string {

// Turn all characters lowercase
void toLower(std::string& str);

// Return a lowercase copy
[[nodiscard]] std::string toLowerCopy(std::string str);

// TODO Block through concepts
// Convert to a string
// Enable if not a pointer or if it's a C-string
template<typename T>
[[nodiscard]] std::enable_if_t<
        !std::is_pointer_v<std::decay_t<T>> || std::is_same_v<std::decay_t<T>, const char*>
                || (std::is_array_v<T>
                    && (std::is_same_v<std::remove_extent_t<T>, char>
                        || std::is_same_v<std::remove_extent_t<T>, const char>) ),
        std::optional<std::string>>
filteredToString(const T& value, ConversionPolicies policies = ConversionPolicies{});

} // namespace string

#include "StdString.tpp"
