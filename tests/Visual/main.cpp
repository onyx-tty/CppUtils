// SPDX-FileCopyrightText: 2026 Łukasz Wrodarczyk
// SPDX-License-Identifier: MIT

#ifdef CPPUTILS_ENABLE_QT
        #include "Log/QtLogTest.h"
#endif

int main() {
#ifdef CPPUTILS_ENABLE_QT
        displayTestLogs();
#endif

        return 0;
}
