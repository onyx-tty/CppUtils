add_library(CppUtils_Time_POSIX
        PosixTime.cpp)
add_library(CppUtils::Time::POSIX ALIAS CppUtils_Time_POSIX)

target_include_directories(CppUtils_Time_POSIX PUBLIC
        $<BUILD_INTERFACE:${INCLUDE_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
