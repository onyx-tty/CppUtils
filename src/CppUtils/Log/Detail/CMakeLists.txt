include_guard(GLOBAL)

if(CPPUTILS_ENABLE_QT)
        add_library(CppUtils_Log_Qt_Helpers
                QtLogHelpers.cpp)
        add_library(CppUtils::Log::Qt::Helpers ALIAS CppUtils_Log_Qt_Helpers)

        target_include_directories(CppUtils_Log_Qt_Helpers PRIVATE
                $<BUILD_INTERFACE:${INCLUDE_DIR}>
                $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

        target_link_libraries(CppUtils_Log_Qt_Helpers PRIVATE
                CppUtils::String::Qt)

        target_link_libraries(CppUtils_Log_Qt_Helpers PUBLIC
                Qt${QT_VERSION_MAJOR}::Core)
endif()
