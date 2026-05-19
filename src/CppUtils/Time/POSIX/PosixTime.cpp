// SPDX-FileCopyrightText: 2026 Łukasz Wrodarczyk
// SPDX-License-Identifier: MIT

#include "CppUtils/Time/POSIX/PosixTime.h"

#include <cmath>
#include <cstdlib>
#include <ctime>

time_t timing::posix::todayMidnight() {
        return timing::posix::roundToMidnight(std::time(nullptr));
}

time_t timing::posix::closerToNow(time_t hour1, time_t hour2) {
        const time_t now   = std::time(nullptr);
        const time_t diff1 = std::abs(hour1 - now);
        const time_t diff2 = std::abs(hour2 - now);

        return (diff1 <= diff2) ? hour1 : hour2;
}
