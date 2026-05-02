include_guard(GLOBAL)

add_library(CppUtils_UnitTests_String
        CStringTest.cpp
        StringTest.cpp)
add_library(CppUtils::UnitTests::String ALIAS CppUtils_UnitTests_String)

target_include_directories(CppUtils_UnitTests_String PRIVATE
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(CppUtils_UnitTests_String PRIVATE
        CppUtils::String)

target_link_libraries(CppUtils_UnitTests_String PUBLIC
        GTest::gtest
        GTest::gtest_main)

if(CPPUTILS_ENABLE_QT)
        add_library(CppUtils_UnitTests_String_Qt
                QtStringTest.cpp)
        add_library(CppUtils::UnitTests::String::Qt ALIAS CppUtils_UnitTests_String_Qt)

        target_link_libraries(CppUtils_UnitTests_String_Qt PRIVATE
                CppUtils::String::Qt)

        target_link_libraries(CppUtils_UnitTests_String_Qt PUBLIC
                Qt${QT_VERSION_MAJOR}::Core)

        target_link_libraries(CppUtils_UnitTests_String_Qt PUBLIC
                GTest::gtest
                GTest::gtest_main)
endif()
