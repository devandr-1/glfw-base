cmake_minimum_required(VERSION 3.19)

project(glfw-base-template VERSION 1.0.0)

add_subdirectory(lib)

add_executable(app main.cpp)

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})
target_link_libraries(app OpenGL::GL)

target_include_directories(app PUBLIC ${glfw_include})
target_link_libraries(app ${glfw_lib})

target_link_libraries(app glew)

if(APPLE)
    target_link_libraries(app "-framework Cocoa -framework IOKit")
endif()