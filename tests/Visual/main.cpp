// SPDX-FileCopyrightText: 2026 Łukasz Wrodarczyk
// SPDX-License-Identifier: MIT

#include "Log/QtLogTest.h"

int main() {
#ifdef CPPUTILS_ENABLE_QT
        displayTestLogs();
#endif

        return 0;
}
