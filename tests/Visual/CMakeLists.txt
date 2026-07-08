add_subdirectory(Log)

add_executable(CppUtils_VisualTests main.cpp)

target_include_directories(CppUtils_VisualTests PRIVATE
        ${INCLUDE_DIR}
        ${CMAKE_CURRENT_LIST_DIR})

if(CPPUTILS_ENABLE_QT)
        target_compile_definitions(CppUtils_VisualTests PUBLIC
                CPPUTILS_ENABLE_QT)

        target_link_libraries(CppUtils_VisualTests PRIVATE
                CppUtils::VisualTests::Log::Qt)

        qt_finalize_executable(CppUtils_VisualTests)
endif()
