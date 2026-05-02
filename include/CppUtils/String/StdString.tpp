// SPDX-FileCopyrightText: 2026 Łukasz Wrodarczyk
// SPDX-License-Identifier: MIT

#pragma once

#include "CppUtils/Conversion/ConversionPolicies.h"
#include "CppUtils/String/StdString.h"

#include <type_traits>

namespace string {

template<typename T>
std::enable_if_t<!std::is_pointer_v<std::decay_t<T>> || std::is_same_v<std::decay_t<T>, const char*>
                         || (std::is_array_v<T>
                             && (std::is_same_v<std::remove_extent_t<T>, char>
                                 || std::is_same_v<std::remove_extent_t<T>, const char>) ),
                 std::optional<std::string>>
filteredToString(const T& value, ConversionPolicies policies) {
        // filter out the value if it's not permitted, using policies
        if constexpr (std::is_same_v<T, bool>) {
                if (!policies.allow_bool) { return std::nullopt; }
        } else if constexpr (std::is_convertible_v<T, const char*>) {
                if (!policies.allow_string) { return std::nullopt; }
        } else if constexpr (std::is_arithmetic_v<T>) {
                if (!policies.allow_number) { return std::nullopt; }
        } else if constexpr (std::is_same_v<T, std::string>) {
                if (!policies.allow_string) { return std::nullopt; }
        } else { // std::nullopt for unsupported types
                return std::nullopt;
        }

        // forward respectively
        if constexpr (std::is_same_v<T, std::string>) {
                return value;
        } else if constexpr (std::is_convertible_v<T, const char*>) {
                return std::string(value);
        } else { // redirect
                return std::to_string(value);
        }
}

} // namespace string
