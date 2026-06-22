add_subdirectory(
        Log)
add_subdirectory(
        String)
add_subdirectory(
        Time)

add_library(CppUtils_AllNonQt INTERFACE)
add_library(CppUtils::AllNonQt ALIAS CppUtils_AllNonQt)
target_link_libraries(CppUtils_AllNonQt INTERFACE
        #CppUtils::Log
        CppUtils::String
        CppUtils::Time
        CppUtils::Time::Constants
        CppUtils::Time::POSIX)

if(CPPUTILS_ENABLE_QT)
        add_library(CppUtils_AllQt INTERFACE)
        add_library(CppUtils::AllQt ALIAS CppUtils_AllQt)
        target_link_libraries(CppUtils_AllQt INTERFACE
                #CppUtils::Log
                CppUtils::Log::Qt
                CppUtils::String
                CppUtils::String::Qt
                CppUtils::Time
                CppUtils::Time::Constants
                CppUtils::Time::POSIX)
endif()
