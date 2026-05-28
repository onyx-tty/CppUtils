// SPDX-FileCopyrightText: 2026 Łukasz Wrodarczyk
// SPDX-License-Identifier: MIT

#include "QtLogTest.h"
#include "CppUtils/Log/QtLog.h"

#include <QDebug>
#include <QString>

// Qt 6.5+ provides a dedicated header <QtLogging>.
// Use it when possible to reduce compilation times.
// For older Qt versions, fall back to the full <QtCore>.
// <QtVersionChecks> didn't exist before Qt 6.5, so it can't be used either.
#if __has_include(<QtEnvironmentVariables>) // Qt >=6.5
        #include <QtLogging>
#else
        #include <QtGlobal> // Qt <6.5
#endif

void displayTestLogs() {
        qt::log::setupLogging();

        qInfo() << "Example of QINFO! QString:" << QString("abc") << "- string literal:" << "abc"
                << "- int:" << 5;

        qDebug() << "Example of QDEBUG! QString:" << QString("abc") << "- string literal:" << "abc"
                 << "- int:" << 5;

        qWarning() << "Example of QWARNING! QString:" << QString("abc")
                   << "- string literal:" << "abc" << "- int:" << 5;

        qCritical() << "Example of QCRITICAL! QString:" << QString("abc")
                    << "- string literal:" << "abc" << "- int:" << 5;

        qFatal("Example of QFATAL! String literal: %s - int: %i", "abc", 5);
}
