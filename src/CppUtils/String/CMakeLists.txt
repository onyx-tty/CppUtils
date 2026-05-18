# Non-Qt
if(NOT TARGET CppUtils::String)
        add_library(CppUtils_String
                ${CMAKE_CURRENT_LIST_DIR}/StdString.cpp)
        add_library(CppUtils::String ALIAS CppUtils_String)

        target_include_directories(CppUtils_String PUBLIC
                $<BUILD_INTERFACE:${INCLUDE_DIR}>
                $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
endif()

# Qt
if(CPPUTILS_ENABLE_QT AND NOT TARGET CppUtils::String::Qt)
        add_library(CppUtils_String_Qt INTERFACE)
        add_library(CppUtils::String::Qt ALIAS CppUtils_String_Qt)

        target_include_directories(CppUtils_String_Qt INTERFACE
                $<BUILD_INTERFACE:${INCLUDE_DIR}>
                $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

        target_link_libraries(CppUtils_String_Qt INTERFACE
                Qt${QT_VERSION_MAJOR}::Core)
endif()
