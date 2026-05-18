// SPDX-FileCopyrightText: 2026 Łukasz Wrodarczyk
// SPDX-License-Identifier: MIT

#include "QtLogTest.h"
#include "CppUtils/Log/QtLog.h"

#include <QString>

void displayTestLogs() {
        QINFO() << "Example of QINFO! QString:" << QString("abc") << "- string literal:" << "abc"
                << "- int:" << 5;

        QDEBUG() << "Example of QDEBUG! QString:" << QString("abc") << "- string literal:" << "abc"
                 << "- int:" << 5;

        QWARNING() << "Example of QWARNING! QString:" << QString("abc")
                   << "- string literal:" << "abc" << "- int:" << 5;

        QCRITICAL() << "Example of QCRITICAL! QString:" << QString("abc")
                    << "- string literal:" << "abc" << "- int:" << 5;

        QFATAL("Example of QFATAL! String literal: %s - int: %i", "abc", 5);
}
