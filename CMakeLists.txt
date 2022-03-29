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

find_package(Qt5 REQUIRED COMPONENTS 
    Widgets
)

include(FetchContent)
FetchContent_Declare(
        qhotkey
        GIT_REPOSITORY https://github.com/Skycoder42/QHotkey.git
        GIT_TAG        master
)
FetchContent_MakeAvailable(qhotkey)

add_executable(${PROJECT_NAME} 
    src/main.cpp
    src/main_widget.cpp
    src/main_widget.ui
)

target_link_libraries(${PROJECT_NAME} Qt5::Widgets QHotkey::QHotkey)
target_include_directories(${PROJECT_NAME} PUBLIC ${qhotkey_SOURCE_DIR}/QHotkey)

if(MINGW)
    set(CMAKE_CXX_FLAGS "-mwindows")
endif()

include(CPack)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
