add_subdirectory(Detail)

include_guard(GLOBAL)

if(CPPUTILS_ENABLE_QT)
        add_library(CppUtils_Log_Qt INTERFACE)
        add_library(CppUtils::Log::Qt ALIAS CppUtils_Log_Qt)

        target_include_directories(CppUtils_Log_Qt INTERFACE
                $<BUILD_INTERFACE:${INCLUDE_DIR}>
                $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

        target_link_libraries(CppUtils_Log_Qt INTERFACE
                CppUtils::Log::Qt::Helpers)

        target_link_libraries(CppUtils_Log_Qt INTERFACE
                Qt${QT_VERSION_MAJOR}::Core)

        # Print debug-level logs
        if(${LOG_DEBUG}) # refer to the CACHE version specifically
                target_compile_definitions(CppUtils_Log_Qt INTERFACE LOG_DEBUG)
        endif()
endif()
