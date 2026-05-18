// SPDX-FileCopyrightText: 2026 Łukasz Wrodarczyk
// SPDX-License-Identifier: MIT

#pragma once

#include "CppUtils/Log/Detail/QtLogHelpers.h"

#include <source_location>
#include <QDebug>
#include <QString>

/* Logging formatters */
// Fatal - red
#define QFATAL(fmt, ...) qt::log::detail::fatalImpl(QString::asprintf(fmt, ##__VA_ARGS__))

// Critical - purple
#define QCRITICAL()                                                       \
        qCritical().noquote() << "\033[35m[CRITICAL]\033[0m"              \
                              << qt::log::detail::getTrimmedFuncName(     \
                                         std::source_location::current()) \
                              << ":"

// Warning - blue
#define QWARNING()                                                       \
        qWarning().noquote() << "\033[34m[WARNING]\033[0m "              \
                             << qt::log::detail::getTrimmedFuncName(     \
                                        std::source_location::current()) \
                             << ":"

// TODO Optimize, this still instantiates a QDebug object
// Debug - cyan
#ifdef LOG_DEBUG
        #define QDEBUG()                                                                        \
                qDebug().noquote()                                                              \
                        << "\033[36m[DEBUG]\033[0m   "                                          \
                        << qt::log::detail::getTrimmedFuncName(std::source_location::current()) \
                        << ":"
#else // Swallow anything streamed to it and ignore semicolons
        #define QDEBUG(fmt, ...) \
                if (false) qDebug().noquote()
#endif

// Info - green
#define QINFO()                                                                                   \
        qInfo().noquote() << "\033[32m[INFO]\033[0m    "                                          \
                          << qt::log::detail::getTrimmedFuncName(std::source_location::current()) \
                          << ":"
