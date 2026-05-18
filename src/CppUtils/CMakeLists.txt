add_subdirectory(
        Conversion)
add_subdirectory(
        Log)
add_subdirectory(
        String)
add_subdirectory(
        Time)

if(NOT TARGET CppUtils_AllNonQt)
        add_library(CppUtils_AllNonQt INTERFACE)
        add_library(CppUtils::AllNonQt ALIAS CppUtils_AllNonQt)
        target_link_libraries(CppUtils_AllNonQt INTERFACE
                CppUtils::Conversion
                #CppUtils::Log
                CppUtils::String
                CppUtils::Time
                CppUtils::Time::Constants
                CppUtils::Time::POSIX)
endif()

if(CPPUTILS_ENABLE_QT AND NOT TARGET CppUtils_AllQt)
        add_library(CppUtils_AllQt INTERFACE)
        add_library(CppUtils::AllQt ALIAS CppUtils_AllQt)
        target_link_libraries(CppUtils_AllQt INTERFACE
                CppUtils::Conversion
                #CppUtils::Log
                CppUtils::Log::Qt
                CppUtils::String
                CppUtils::String::Qt
                CppUtils::Time
                CppUtils::Time::Constants
                CppUtils::Time::POSIX)
endif()
