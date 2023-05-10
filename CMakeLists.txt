cmake_minimum_required(VERSION 3.5)

project(pre-commit_installer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

file(GLOB SOURCES src/*.cpp)
file(GLOB HEADERS include/*.h)

add_executable(commit_installer ${SOURCES} ${HEADERS})
