cmake_minimum_required(VERSION 3.21)

project(MyVault VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(myvault app/main.cpp
    domain/Entry.h)

target_include_directories(myvault PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
