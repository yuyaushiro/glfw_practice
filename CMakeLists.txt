cmake_minimum_required(VERSION 2.8)
project(GLFW)

add_compile_options("-std=c++14")

set (CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
find_package(GLEW REQUIRED)
find_package(GLFW REQUIRED)
find_package(OpenGL REQUIRED)

include_directories(${GLEW_INCLUDE_DIR})
include_directories(${GLFW_INCLUDE_DIR})
include_directories(include)

add_executable(glfw_app.out
  src/main.cpp
)
target_link_libraries(glfw_app.out ${GLFW_LIBRARIES} ${OPENGL_LIBRARY} ${GLEW_LIBRARIES})
