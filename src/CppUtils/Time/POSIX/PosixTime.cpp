// SPDX-FileCopyrightText: 2026 Łukasz Wrodarczyk
// SPDX-License-Identifier: MIT

#include "CppUtils/Time/POSIX/PosixTime.h"
#include "CppUtils/Time/Constants/Length.h"

#include <cmath>
#include <cstdlib>
#include <ctime>

time_t timing::posix::getMidnight(time_t timestamp) {
        const time_t days_since_epoch = timestamp / timing::day;
        const time_t midnight         = days_since_epoch * timing::day;

        return midnight;
}

time_t timing::posix::getCurrentMidnight() {
        return timing::posix::getMidnight(std::time(nullptr));
}

time_t timing::posix::findCloserHour(time_t hour1, time_t hour2) {
        const time_t now   = std::time(nullptr);
        const time_t diff1 = std::abs(hour1 - now);
        const time_t diff2 = std::abs(hour2 - now);

        return (diff1 <= diff2) ? hour1 : hour2;
}
