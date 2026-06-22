add_subdirectory(Constants)
add_subdirectory(POSIX)

add_library(CppUtils_Time INTERFACE)
add_library(CppUtils::Time ALIAS CppUtils_Time)

target_link_libraries(CppUtils_Time INTERFACE
        CppUtils::Time::Constants
        CppUtils::Time::POSIX)
