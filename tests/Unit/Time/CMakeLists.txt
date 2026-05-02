add_subdirectory(POSIX)

include_guard(GLOBAL)

add_library(CppUtils_UnitTests_Time INTERFACE)
add_library(CppUtils::UnitTests::Time ALIAS CppUtils_UnitTests_Time)

target_link_libraries(CppUtils_UnitTests_Time INTERFACE
        CppUtils::UnitTests::Time::POSIX
        CppUtils::Time)
