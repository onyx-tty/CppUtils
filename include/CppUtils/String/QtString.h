// SPDX-FileCopyrightText: 2026 Łukasz Wrodarczyk
// SPDX-License-Identifier: MIT

#pragma once

#include <QString>

namespace qt {
namespace string {

// Convert to QString if compatible
template<typename T>
[[nodiscard]] QString toQString(const T& value);

} // namespace string
} // namespace qt

#include "QtString.tpp"
