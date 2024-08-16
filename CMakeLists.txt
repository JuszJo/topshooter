cmake_minimum_required(VERSION 3.10)
project(top-down)

set(CMAKE_CXX_STANDARD 11)

# Include directories
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/include/GLM
    ${CMAKE_SOURCE_DIR}/include/GLFW
    ${CMAKE_SOURCE_DIR}/include/glm
)

# Specify where to look for libraries
link_directories(${CMAKE_SOURCE_DIR}/lib)

# Find OpenGL
find_package(OpenGL REQUIRED)

add_executable(top-down main.cpp)

# Link libraries
target_link_libraries(top-down
    PRIVATE ${CMAKE_SOURCE_DIR}/lib/libglfw.so.3.4
    PRIVATE ${CMAKE_SOURCE_DIR}/lib/libGLEW.so.2.2.0
    PRIVATE ${OPENGL_LIBRARIES}
)

# Include GLM as header-only library
target_include_directories(top-down PRIVATE ${CMAKE_SOURCE_DIR}/include/glm)