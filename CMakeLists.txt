cmake_minimum_required(VERSION 3.10)
project(dyingsunseteditor VERSION 0.0.1)

set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
set(VENDORS_DIR ${CMAKE_SOURCE_DIR}/vendors)

add_executable(dyingsunseteditor ${SOURCE_DIR}/main.cpp)