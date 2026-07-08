if(CPPUTILS_ENABLE_QT)
        add_library(CppUtils_Log_Qt
                QtLog.cpp)
        add_library(CppUtils::Log::Qt ALIAS CppUtils_Log_Qt)

        target_include_directories(CppUtils_Log_Qt PUBLIC
                $<BUILD_INTERFACE:${INCLUDE_DIR}>
                $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

        target_link_libraries(CppUtils_Log_Qt PUBLIC
                Qt${QT_VERSION_MAJOR}::Core)
endif()
