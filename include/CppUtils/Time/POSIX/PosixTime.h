// SPDX-FileCopyrightText: 2026 Łukasz Wrodarczyk
// SPDX-License-Identifier: MIT

#pragma once

#include <ctime>

namespace timing::posix {

[[nodiscard]] time_t getMidnight(time_t timestamp);
[[nodiscard]] time_t getCurrentMidnight();
[[nodiscard]] time_t closerToNow(time_t hour1, time_t hour2);

} // namespace timing::posix
