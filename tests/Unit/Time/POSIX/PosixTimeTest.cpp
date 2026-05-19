// SPDX-FileCopyrightText: 2026 Łukasz Wrodarczyk
// SPDX-License-Identifier: MIT

#include "CppUtils/Time/POSIX/PosixTime.h"
#include "CppUtils/Time/Constants/Length.h"

#include <cstddef>
#include <ctime>
#include <gtest/gtest.h>

using namespace timing;

// Check if each was taken before and after midnight respectively
// If yes, the unit test may have been ran during midnight
[[nodiscard]] inline bool dayDiffers(const size_t& t1, const size_t& t2) {
        return (t1 - t2) > timing::day;
}

TEST(RoundToMidnightTest, ReturnsCorrectMidnight) {
        // Afternoon 2025-10-01 15:45 UTC = 1759333500
        // Midnight  2025-10-01 00:00 UTC = 1759276800
        EXPECT_EQ(posix::roundToMidnight(1759333500), 1759276800);
}

TEST(RoundToMidnightTest, ReturnsItselfAtMidnight) {
        // Midnight  2025-10-01 00:00 UTC = 1759276800
        EXPECT_EQ(posix::roundToMidnight(1759276800), 1759276800);
}

// TODO TwoCallsSpacedBy24HoursIfCalledOnDifferentDays
// t1 = findMidnight(), t2 = findMidnight() + epoch_duration::day
// requires params

TEST(CloserToNowTest, ReturnsHour1IfCloser) {
        const time_t hour1  = time(nullptr);
        const time_t hour2  = 555;
        const time_t closer = posix::closerToNow(hour1, hour2);

        EXPECT_EQ(closer, hour1);
}

TEST(CloserToNowTest, ReturnsHour2IfCloser) {
        const time_t hour1  = 555;
        const time_t hour2  = time(nullptr);
        const time_t closer = posix::closerToNow(hour1, hour2);

        EXPECT_EQ(closer, hour2);
}
