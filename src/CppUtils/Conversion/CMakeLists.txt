include_guard(GLOBAL)

add_library(CppUtils_Conversion INTERFACE)
add_library(CppUtils::Conversion ALIAS CppUtils_Conversion)

target_include_directories(CppUtils_Conversion INTERFACE
        $<BUILD_INTERFACE:${INCLUDE_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
