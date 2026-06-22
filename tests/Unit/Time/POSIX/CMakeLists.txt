add_library(CppUtils_UnitTests_Time_POSIX OBJECT
        PosixTimeTest.cpp)
add_library(CppUtils::UnitTests::Time::POSIX ALIAS CppUtils_UnitTests_Time_POSIX)

target_include_directories(CppUtils_UnitTests_Time_POSIX
        PRIVATE ${INCLUDE_DIR}
                ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(CppUtils_UnitTests_Time_POSIX PRIVATE
        CppUtils::Time::POSIX)

target_link_libraries(CppUtils_UnitTests_Time_POSIX PUBLIC
        GTest::gtest
        GTest::gtest_main)

add_test(NAME CppUtils_UnitTests COMMAND CppUtils_UnitTests)
