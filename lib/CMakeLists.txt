set(glfw_lib ${CMAKE_CURRENT_SOURCE_DIR}/glfw/lib-x86_64/libglfw3.a PARENT_SCOPE)
set(glfw_include ${CMAKE_CURRENT_SOURCE_DIR}/glfw/include PARENT_SCOPE)

add_library(
    glew
    glew-2.1.0/src/glew.c
)

target_include_directories(glew PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/glew-2.1.0/include)