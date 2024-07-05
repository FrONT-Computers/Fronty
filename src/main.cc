#include "GL/glew.h"
#include "core/ui/window.h"
#include "core/renderer/context/gl/fvao.h"

// #include <AppKit/AppKit.h>

#include <iostream>
#include <vector>
#include "native/FTYCocoaWindow-Interface.h"

using namespace Fronty;

const char* vertex_shader =
    "#version 330 core\n"
    "in vec3 vp;"
    "void main() {"
    "  gl_Position = vec4(vp, 1.0);"
    "}";

const char* fragment_shader =
    "#version 330 core\n"
    "out vec4 frag_colour;"
    "void main() {"
    "  frag_colour = vec4(0.5, 0.0, 0.5, 1.0);"
    "}";

int main(void)
{
    Gui::Window window(900, 500, "Fronty");
    bool        result = window.initWindow();
    if (!result)
    {
        std::cerr << "Failed to initialize window\n";
        return -1;
    }

    GLFWwindow* regularWindow = const_cast<GLFWwindow*>(window.getCoreWindow());
    setTitleBarTransparent(regularWindow, true);

    // Initialize GLEW
    GLenum glew_status = glewInit();
    if (glew_status != GLEW_OK)
    {
        std::cerr << "Failed to initialize GLEW: " << glewGetErrorString(glew_status) << "\n";
        return -1;
    }

    // const float triangle_vertices[9] = {0, 0.5, 0, -0.5, -0.5, 0, 0.5, -0.5, 0};
    const float line[] = {-1, 1, 0, 1, 1, 0};

    // Vertex Array
    uint32_t vao = Renderer::FrontyVertexArrayObject::genVertexArray();

    // Vertex Buffer
    uint32_t vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(line), line, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

    Renderer::FrontyVertexArrayObject::unbindVertexArray();

    GLuint vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, &vertex_shader, NULL);
    glCompileShader(vs);

    GLint isCompiled = 0;
    glGetShaderiv(vs, GL_COMPILE_STATUS, &isCompiled);
    if (isCompiled == GL_FALSE)
    {
        GLint maxLength = 0;
        glGetShaderiv(vs, GL_INFO_LOG_LENGTH, &maxLength);

        std::vector<GLchar> errorLog(maxLength);
        glGetShaderInfoLog(vs, maxLength, &maxLength, &errorLog[0]);
        std::cerr << "Vertex shader compilation failed:\n"
                  << &errorLog[0] << "\n";

        glDeleteShader(vs);
        return -1;
    }

    GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, &fragment_shader, NULL);
    glCompileShader(fs);

    glGetShaderiv(fs, GL_COMPILE_STATUS, &isCompiled);
    if (isCompiled == GL_FALSE)
    {
        GLint maxLength = 0;
        glGetShaderiv(fs, GL_INFO_LOG_LENGTH, &maxLength);

        std::vector<GLchar> errorLog(maxLength);
        glGetShaderInfoLog(fs, maxLength, &maxLength, &errorLog[0]);
        std::cerr << "Fragment shader compilation failed:\n"
                  << &errorLog[0] << "\n";

        glDeleteShader(fs);
        return -1;
    }

    GLuint shader_programme = glCreateProgram();
    glAttachShader(shader_programme, fs);
    glAttachShader(shader_programme, vs);
    glLinkProgram(shader_programme);

    GLint isLinked = 0;
    glGetProgramiv(shader_programme, GL_LINK_STATUS, (int*)&isLinked);
    if (isLinked == GL_FALSE)
    {
        GLint maxLength = 0;
        glGetProgramiv(shader_programme, GL_INFO_LOG_LENGTH, &maxLength);

        std::vector<GLchar> errorLog(maxLength);
        glGetProgramInfoLog(shader_programme, maxLength, &maxLength, &errorLog[0]);
        std::cerr << "Shader linking failed:\n"
                  << &errorLog[0] << "\n";

        glDeleteProgram(shader_programme);
        return -1;
    }

    while (!window.shouldClose())
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shader_programme);
        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwPollEvents();
        glfwSwapBuffers(regularWindow);
    }

    glDeleteShader(vs);
    glDeleteShader(fs);
    glDeleteProgram(shader_programme);

    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);

    glfwTerminate();

    return 0;
}
