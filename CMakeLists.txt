cmake_minimum_required(VERSION 3.13)
project(dyingsunseteditor VERSION 0.0.1)

set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
set(VENDORS_DIR ${CMAKE_SOURCE_DIR}/vendors)

add_executable(${PROJECT_NAME} ${SOURCE_DIR}/main.cpp)

add_subdirectory(${VENDORS_DIR}/GLFW)

target_include_directories(${PROJECT_NAME} 
  PUBLIC ${VENDORS_DIR}/GLFW/include
)

target_link_directories(${PROJECT_NAME}
  PRIVATE ${VENDORS_DIR}/GLFW/src
)

target_link_libraries(${PROJECT_NAME} glfw)