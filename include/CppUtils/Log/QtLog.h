// SPDX-FileCopyrightText: 2026 Łukasz Wrodarczyk
// SPDX-License-Identifier: MIT

#pragma once

#include "CppUtils/Log/Detail/QtLogHelpers.h"

#include <QDebug>
#include <QString>

/* Logging formatters */
// Fatal - red
#define QFATAL(fmt, ...)                                                                             \
        do {                                                                                         \
                const QString fn = QString(                                                          \
                        QLatin1StringView(__PRETTY_FUNCTION__                                        \
                                                  + qt::log::detail::getTrimmedPrettyFunctionOffset( \
                                                          __PRETTY_FUNCTION__),                      \
                                          qt::log::detail::getTrimmedPrettyFunctionLength(           \
                                                  __PRETTY_FUNCTION__)));                            \
                const QString msg = QString::asprintf(fmt, ##__VA_ARGS__);                           \
                qFatal("\033[31m[FATAL]\033[0m    %s : %s", fn.toStdString().c_str(),                \
                       qPrintable(msg));                                                             \
        } while (0)

// Critical - purple
#define QCRITICAL()                                                                                 \
        qCritical().noquote() << "\033[35m[CRITICAL]\033[0m"                                        \
                              << QLatin1StringView(                                                 \
                                         __PRETTY_FUNCTION__                                        \
                                                 + qt::log::detail::getTrimmedPrettyFunctionOffset( \
                                                         __PRETTY_FUNCTION__),                      \
                                         qt::log::detail::getTrimmedPrettyFunctionLength(           \
                                                 __PRETTY_FUNCTION__))                              \
                              << ":"

// Warning - blue
#define QWARNING()                                                                                 \
        qWarning().noquote() << "\033[34m[WARNING]\033[0m "                                        \
                             << QLatin1StringView(                                                 \
                                        __PRETTY_FUNCTION__                                        \
                                                + qt::log::detail::getTrimmedPrettyFunctionOffset( \
                                                        __PRETTY_FUNCTION__),                      \
                                        qt::log::detail::getTrimmedPrettyFunctionLength(           \
                                                __PRETTY_FUNCTION__))                              \
                             << ":"

// TODO Optimize, this still instantiates a QDebug object
// Debug - cyan
#ifdef LOG_DEBUG
        #define QDEBUG()                                                                      \
                qDebug().noquote()                                                            \
                        << "\033[36m[DEBUG]\033[0m   "                                        \
                        << QLatin1StringView(                                                 \
                                   __PRETTY_FUNCTION__                                        \
                                           + qt::log::detail::getTrimmedPrettyFunctionOffset( \
                                                   __PRETTY_FUNCTION__),                      \
                                   qt::log::detail::getTrimmedPrettyFunctionLength(           \
                                           __PRETTY_FUNCTION__))                              \
                        << ":"

#else // Swallow anything streamed to it and ignore semicolons
        #define QDEBUG() \
                if (false) qDebug().noquote()
#endif

// Info - green
#define QINFO()                                                                                 \
        qInfo().noquote() << "\033[32m[INFO]\033[0m    "                                        \
                          << QLatin1StringView(                                                 \
                                     __PRETTY_FUNCTION__                                        \
                                             + qt::log::detail::getTrimmedPrettyFunctionOffset( \
                                                     __PRETTY_FUNCTION__),                      \
                                     qt::log::detail::getTrimmedPrettyFunctionLength(           \
                                             __PRETTY_FUNCTION__))                              \
                          << ":"
