// SPDX-FileCopyrightText: 2026 Łukasz Wrodarczyk
// SPDX-License-Identifier: MIT

#include "CppUtils/Time/POSIX/PosixTime.h"

#include <ctime>
#include <gtest/gtest.h>

using namespace timing;

/* roundToMidnight */
TEST(RoundToMidnightTest, Afternoon) {
        // Afternoon 2025-10-01 15:45 UTC = 1759333500
        // Midnight  2025-10-01 00:00 UTC = 1759276800
        EXPECT_EQ(posix::roundToMidnight(1759333500), 1759276800);
}

TEST(RoundToMidnightTest, AlreadyMidnight) {
        // Midnight  2025-10-01 00:00 UTC = 1759276800
        EXPECT_EQ(posix::roundToMidnight(1759276800), 1759276800);
}

/* closerToNow */
TEST(CloserToNowTest, FirstIsCloser) {
        const time_t first  = time(nullptr);
        const time_t second = 555;
        const time_t closer = posix::closerToNow(first, second);

        EXPECT_EQ(closer, first);
}

TEST(CloserToNowTest, SecondIsCloser) {
        const time_t first  = 555;
        const time_t second = time(nullptr);
        const time_t closer = posix::closerToNow(first, second);

        EXPECT_EQ(closer, second);
}
