cmake_minimum_required(VERSION 3.13)
project(dyingsunseteditor VERSION 0.0.1)

# Get Vulkan
find_package(Vulkan REQUIRED)

configure_file(dyingsunseteditorConfig.h.in dyingsunseteditorConfig.h)

set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
set(VENDORS_DIR ${CMAKE_SOURCE_DIR}/vendors)

add_executable(${PROJECT_NAME} ${SOURCE_DIR}/main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})

# Download All Submodules
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${SOURCE_DIR}/.git")
  option(GIT_SUBMODULE "Check submodules during build" ON)
  if(GIT_SUBMODULE)
    message(STATUS "Submodule update")
    execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                    RESULT_VARIABLE GIT_SUBMOD_RESULT)
    
    if(NOT GIT_SUBMOD_RESULT EQUAL "0")
      message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodule")
    endif()
  endif()
endif()

# Check if GLFW submodule exists
if(NOT EXISTS "${VENDORS_DIR}/GLFW/CMakeLists.txt")
  message(FATAL_ERROR "The GLFW submodule was not downloaded! GET_SUBMODULE is off or failed!")
endif()

# GLFW
add_subdirectory(${VENDORS_DIR}/GLFW)
target_include_directories(${PROJECT_NAME} PUBLIC ${VENDORS_DIR}/GLFW/include)
target_link_directories(${PROJECT_NAME} PRIVATE ${VENDORS_DIR}/GLFW/src)
target_link_libraries(${PROJECT_NAME} glfw)

# Check if GLM submodule exists
if(NOT EXISTS "${VENDORS_DIR}/glm/CMakeLists.txt")
  message(FATAL_ERROR "The glm submodule was not downloaded! GET_SUBMODULE is off or failed!")
endif()

# GLM
add_subdirectory(${VENDORS_DIR}/glm)
target_link_libraries(${PROJECT_NAME} glm::glm)

# Vulkan
target_include_directories(${PROJECT_NAME} PUBLIC ${Vulkan_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${Vulkan_LIBRARIES})