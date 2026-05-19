// SPDX-FileCopyrightText: 2026 Łukasz Wrodarczyk
// SPDX-License-Identifier: MIT

#pragma once

#include "CppUtils/Time/Constants/Length.h"

#include <ctime>

namespace timing::posix {

[[nodiscard]] constexpr time_t roundToMidnight(time_t timestamp) {
        const time_t days_since_epoch = timestamp / timing::day;
        const time_t midnight         = days_since_epoch * timing::day;

        return midnight;
}

[[nodiscard]] time_t todayMidnight();

[[nodiscard]] time_t closerToNow(time_t hour1, time_t hour2);

} // namespace timing::posix
