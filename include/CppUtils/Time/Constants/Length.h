// SPDX-FileCopyrightText: 2026 Łukasz Wrodarczyk
// SPDX-License-Identifier: MIT

#pragma once

#include <ctime>

namespace timing {

constexpr std::time_t minute = 60;
constexpr std::time_t hour   = minute * 60;
constexpr std::time_t day    = hour * 24;
constexpr std::time_t week   = day * 7;

} // namespace timing
