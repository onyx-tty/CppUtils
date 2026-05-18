// SPDX-FileCopyrightText: 2026 Łukasz Wrodarczyk
// SPDX-License-Identifier: MIT

#pragma once

#include <QString>

namespace qt::string {

// Convert to QString if compatible
template<typename T>
[[nodiscard]] QString toQString(const T& value);

} // namespace qt::string

#include "QtString.tpp"
