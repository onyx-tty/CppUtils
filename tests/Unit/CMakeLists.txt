add_subdirectory(String)
add_subdirectory(Time)

include_guard(GLOBAL)

add_executable(CppUtils_UnitTests dummy.cpp)

target_include_directories(CppUtils_UnitTests PRIVATE
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(CppUtils_UnitTests PRIVATE
        CppUtils::UnitTests::String
        CppUtils::UnitTests::Time::POSIX)

if(CPPUTILS_ENABLE_QT)
        target_link_libraries(CppUtils_UnitTests PRIVATE
                CppUtils::UnitTests::String::Qt)
endif()

target_link_libraries(CppUtils_UnitTests PUBLIC
        GTest::gtest
        GTest::gtest_main)

add_test(NAME CppUtils_UnitTests COMMAND CppUtils_UnitTests)
