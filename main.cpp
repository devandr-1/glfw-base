#ifdef __APPLE__
#define GL_SILENCE_DEPRECATION

#endif

#define GLFW_INCLUDE_NONE

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

void error_callback(int error, const char* message)
{
    fprintf(stderr, "Error: %s\n", message);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

int main()
{
    glfwSetErrorCallback(error_callback);

    if (!glfwInit())
    {
        return -1;
    }

    GLFWwindow* window;
    window = glfwCreateWindow(640, 480, "Hello, World!", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // should be initialized after glfwMakeContextCurrent
    if (glewInit() != GLEW_OK)
    {
        std::cout << "Glew initialization failed\n";
        return -1;
    }
    
    glfwSetKeyCallback(window, key_callback);

    int width, height;
    glfwGetFramebufferSize(window, &height, &width);
    
    glViewport(0, 0, width, height);

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 1;
}