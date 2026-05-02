include_guard(GLOBAL)

if(CPPUTILS_ENABLE_QT)
        add_library(CppUtils_Log_Qt_Helpers INTERFACE)
        add_library(CppUtils::Log::Qt::Helpers ALIAS CppUtils_Log_Qt_Helpers)

        target_include_directories(CppUtils_Log_Qt_Helpers INTERFACE
                $<BUILD_INTERFACE:${INCLUDE_DIR}>
                $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

        target_link_libraries(CppUtils_Log_Qt_Helpers INTERFACE
                CppUtils::String::Qt)

                target_link_libraries(CppUtils_Log_Qt_Helpers INTERFACE
                        Qt${QT_VERSION_MAJOR}::Core)
endif()
