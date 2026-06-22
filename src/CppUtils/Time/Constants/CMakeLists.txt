add_library(CppUtils_Time_Constants INTERFACE)
add_library(CppUtils::Time::Constants ALIAS CppUtils_Time_Constants)

target_include_directories(CppUtils_Time_Constants INTERFACE
        $<BUILD_INTERFACE:${INCLUDE_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
