cmake_minimum_required(VERSION 3.5)

project(pre-commit_installer VERSION 1.2.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON) # Add build directory to include path

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

file(GLOB SOURCES src/*.cpp)
file(GLOB HEADERS include/*.h)

# Settings for Windows
if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    add_compile_definitions(APP_NAME="${PROJECT_NAME}") # Name in Windows properties
    configure_file(version.rc.in version.rc) # Set VERSIONINFO file

    # Set Windows resources
    enable_language("RC")
    set(WIN32_RESOURCES ${PROJECT_BINARY_DIR}/version.rc)
endif()

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${WIN32_RESOURCES})

configure_file(config.h.in config.h) # Set config header file
