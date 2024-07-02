#include "GLFW/glfw3.h"
#include <iostream>

int main(void)
{
    GLFWwindow* window;

    if (!glfwInit())
        return 1;

    if ((window = glfwCreateWindow(900, 500, "Fronty", NULL, NULL)) == NULL)
    {
        glfwTerminate();
        return 1;
    }

    glfwMakeContextCurrent(window);
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}