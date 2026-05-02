include_guard(GLOBAL)

if(CPPUTILS_ENABLE_QT)
        add_library(CppUtils_VisualTests_Log_Qt
                QtLogTest.cpp)
        add_library(CppUtils::VisualTests::Log::Qt ALIAS CppUtils_VisualTests_Log_Qt)

        target_include_directories(CppUtils_VisualTests_Log_Qt PRIVATE
                ${INCLUDE_DIR}
                ${CMAKE_CURRENT_LIST_DIR})

        target_link_libraries(CppUtils_VisualTests_Log_Qt PRIVATE
                CppUtils::Log::Qt)

        target_link_libraries(CppUtils_VisualTests_Log_Qt PUBLIC
                Qt${QT_VERSION_MAJOR}::Core)
endif()
