cmake_minimum_required(VERSION 3.2.0)
project(meshReader)

set(root ${CMAKE_SOURCE_DIR})

#----------glfw-----------
set(glfwPath ${root}/extern/glfw)
add_subdirectory(${glfwPath})
include_directories(${glfwPath}/include)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

#----------glad------------
set(gladPath ${root}/extern/glad)
include_directories(${gladPath}/include)
add_library(glad STATIC ${gladPath}/src/glad.c)

#----------Catch2----------
include_directories(${root}/extern/Catch2/src)
include_directories(${root}/build/extern/Catch2/generated-includes)
add_subdirectory(${root}/extern/Catch2)



add_executable(meshReader ${root}/src/main.cpp)
target_link_libraries(meshReader PRIVATE glfw glad)

enable_testing()
add_executable(test_executable ${root}/src/test.cpp)
target_link_libraries(test_executable PRIVATE  Catch2::Catch2WithMain glfw glad)
add_test(NAME test_name COMMAND test_executable)
