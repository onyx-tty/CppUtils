cmake_minimum_required(VERSION 3.21)
project(CppUtils VERSION 0.16.3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(QT_VERSION_MAJOR 6)

# GNUInstallDirs is necessary to install libraries into
# correct paths on all platforms
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

if(ENABLE_CLANG_TIDY)
        set(CMAKE_CXX_CLANG_TIDY
                clang-tidy;
                -header-filter=.;)
endif()

# Export compile_commands.json to ensure language servers work properly
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Build shared by default
option(BUILD_SHARED_LIBS "Build using shared libraries" ON)
option(LOG_DEBUG "Print debug-level logs" OFF)
option(CPPUTILS_ENABLE_QT "Enable Qt in CppUtils" OFF)

if(CPPUTILS_ENABLE_QT)
        find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
endif()

# Store and propagate INCLUDE_DIR and SRC_DIR for use in target_include_directories
set(ROOT_DIR
        ${CMAKE_CURRENT_LIST_DIR})

set(INCLUDE_DIR
        ${ROOT_DIR}/include)

add_subdirectory(src)

if(PROJECT_IS_TOP_LEVEL)
        find_package(GTest REQUIRED)
        enable_testing()
        add_subdirectory(tests)
endif()

# Install headers
if(CPPUTILS_ENABLE_QT) # Both non-Qt and Qt
        install(
                DIRECTORY ${INCLUDE_DIR}/
                DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
                FILES_MATCHING
                PATTERN "*.h"
                PATTERN "*.tpp")
else() # Only non-Qt
        install(
                DIRECTORY ${INCLUDE_DIR}/
                DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
                FILES_MATCHING
                PATTERN "*.h"
                PATTERN "*.tpp"
                PATTERN "Qt*.h" EXCLUDE
                PATTERN "Qt*.tpp" EXCLUDE)
endif()

install( # Install compiled artifacts to correct destinations, register all targets
         # under the name CppUtils_export
        TARGETS CppUtils_AllNonQt
                CppUtils_String
                CppUtils_Time CppUtils_Time_Constants CppUtils_Time_POSIX
        EXPORT CppUtils_export
        ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR}
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

if(CPPUTILS_ENABLE_QT)
        install(TARGETS CppUtils_AllQt
                        CppUtils_String_Qt
                        CppUtils_Log_Qt CppUtils_Log_Qt_Helpers
                EXPORT CppUtils_export
                ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}
                LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
                RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR}
                INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
endif()

# Write resulting CppUtils_export to CppUtils_export.cmake
install(EXPORT CppUtils_export
        #NAMESPACE CppUtils::
        DESTINATION ${CMAKE_INSTALL_DATADIR}/cmake/CppUtils)

# Process the Config.cmake.in template, write CppUtilsConfig.cmake
# to the build directory
configure_package_config_file(${CMAKE_CURRENT_LIST_DIR}/cmake/Config.cmake.in
        "${CMAKE_CURRENT_BINARY_DIR}/CppUtilsConfig.cmake"
        INSTALL_DESTINATION "${CMAKE_INSTALL_DATADIR}/cmake/CppUtils")

# Generate CppUtilsConfigVersion.cmake to ensure version
# requirements are satisfied by the consumer
write_basic_package_version_file(
        CppUtilsConfigVersion.cmake
        VERSION ${PACKAGE_VERSION}
        COMPATIBILITY AnyNewerVersion)

# Copy both generated cmake files into the install tree
install(
        FILES ${CMAKE_CURRENT_BINARY_DIR}/CppUtilsConfig.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/CppUtilsConfigVersion.cmake
        DESTINATION ${CMAKE_INSTALL_DATADIR}/cmake/CppUtils)
