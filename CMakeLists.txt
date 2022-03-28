cmake_minimum_required(VERSION 3.1.0)
project(SimpleDeathCounter VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

#set(Qt5_DIR "/usr/x86_64-w64-mingw32/sys-root/mingw/lib/cmake/Qt5")
#set(Qt5Core_DIR "/usr/x86_64-w64-mingw32/sys-root/mingw/lib/cmake/Qt5Core")
#set(Qt5Widgets_DIR "/usr/x86_64-w64-mingw32/sys-root/mingw/lib/cmake/Qt5Widgets")

#set(CMAKE_PREFIX_PATH "/usr/x86_64-w64-mingw32/sys-root/mingw/lib/cmake/Qt5")
#set(CMAKE_FIND_LIBRARY_SUFFIXES ${CMAKE_STATIC_LIBRARY_SUFFIX})
#list(PREPEND CMAKE_FIND_LIBRARY_SUFFIXES .a)
find_package(Qt5 REQUIRED COMPONENTS 
    Widgets
    Core
)
#find_package(Qt5Widgets REQUIRED PATHS /usr/x86_64-w64-mingw32/sys-root/mingw/lib)

add_executable(${PROJECT_NAME} 
    src/main.cpp
    src/mainwidget.cpp
)

if(MINGW)
    set(CMAKE_CXX_FLAGS "-mwindows")
endif()
#include_directories("/usr/x86_64-w64-mingw32/sys-root/mingw/include")

#add_library(Qt5Widgets STATIC IMPORTED)
#set_property(TARGET Qt5Widgets PROPERTY IMPORTED_LOCATION "/usr/x86_64-w64-mingw32/sys-root/mingw/lib/libQt5Widgets.a")
#if(MINGW)
#    message(STATUS "Compiling with mingw, setting static lib location..")   
#endif()

#add_library(QHotkey STATIC)

#target_link_options(${PROJECT_NAME} PUBLIC -static-libgcc -static-libstdc++)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::Core QHotkey::QHotkey)
target_include_directories(${PROJECT_NAME} PUBLIC ${qhotkey_SOURCE_DIR}/QHotkey)


include(CPack)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

include(FetchContent)
FetchContent_Declare(
        qhotkey
        GIT_REPOSITORY https://github.com/Skycoder42/QHotkey.git
        GIT_TAG        master
)
FetchContent_MakeAvailable(qhotkey)

#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")
