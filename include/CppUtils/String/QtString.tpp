// SPDX-FileCopyrightText: 2026 Łukasz Wrodarczyk
// SPDX-License-Identifier: MIT

#pragma once

#include "CppUtils/String/QtString.h"

#include <string>
#include <type_traits>
#include <QString>

namespace qt::string {

// TODO Block through concepts
template<typename T>
[[nodiscard]] QString toQString(const T& value) {
        if constexpr (std::is_arithmetic_v<T>) {
                return QString::number(value);
        } else if constexpr (std::is_same_v<T, std::string>) {
                return QString::fromStdString(value.c_str());
        } else if constexpr (std::is_convertible_v<T, QString>) {
                return QString(value);
        } else {
                static_assert(!sizeof(T*), "Type not supported for toQString!");
        }
}

} // namespace qt::string
