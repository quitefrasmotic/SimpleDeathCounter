cmake_minimum_required(VERSION 3.1.0)
project(simple-death-counter VERSION 0.9.0 LANGUAGES CXX)

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
#FetchContent_MakeAvailable(qhotkey)
# Make package available manually so that I can exclude it from the build and packaging
FetchContent_GetProperties(qhotkey)
if(NOT qhotkey_POPULATED)
  FetchContent_Populate(qhotkey)
  add_subdirectory(${qhotkey_SOURCE_DIR} ${qhotkey_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

add_executable(${PROJECT_NAME} 
    src/main.cpp
    src/main_widget.cpp
    src/main_widget.ui
)

target_link_libraries(${PROJECT_NAME} Qt5::Widgets QHotkey::QHotkey)

install(
    TARGETS ${PROJECT_NAME}
    DESTINATION bin/
)

if(MINGW)
    set(CMAKE_CXX_FLAGS "-mwindows")
    set(CPACK_GENERATOR "NSIS" "TXZ")

    # I have no idea how to properly find the dependency DLLs so I'm just copying them from a directory I manually placed them in for now
    install(
        DIRECTORY deploy_libs_win/
        DESTINATION bin/
    )
    install(
        DIRECTORY deploy_libs_win/platforms/
        DESTINATION bin/platforms/
    )
    install(
        DIRECTORY deploy_libs_win/styles/
        DESTINATION bin/styles/
    )
elseif(LINUX)
    set(CPACK_GENERATOR "TXZ")

    install(
        DIRECTORY deploy_libs_linux/
        DESTINATION bin/
    )
    install(
        DIRECTORY deploy_libs_linux/platforms/
        DESTINATION bin/platforms/
    )
    install(
        DIRECTORY deploy_libs_linux/styles/
        DESTINATION bin/styles/
    )
endif()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

set(CPACK_CREATE_DESKTOP_LINKS "simple-death-counter")
set(CPACK_MONOLITHIC_INSTALL TRUE)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")

set(CPACK_NSIS_COMPRESSOR "/SOLID lzma")
set(CPACK_NSIS_DISPLAY_NAME "SimpleDeathCounter")
set(CPACK_NSIS_MODIFY_PATH ON)
set(CPACK_NSIS_PACKAGE_NAME "SimpleDeathCounter")

set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "A dead simple, streamer-controlled OBS death counter for Windows and Linux")
set(CPACK_PACKAGE_EXECUTABLES "simple-death-counter" "SimpleDeathCounter")
set(CPACK_PACKAGE_INSTALL_REGISTRY_KEY ${CPACK_PACKAGE_NAME})
set(CPACK_PACKAGE_INSTALL_DIRECTORY "simple-death-counter")
set(CPACK_PACKAGE_VENDOR "daupaloffer")

include(CPack)
