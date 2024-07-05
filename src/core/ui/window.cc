/**
 *  Fronty - Free Open Sourced Web Browser
 *   Copyright (C) 2024 FrONT Computers.
 *
 *   @author Mustafa Malik (avia.shabbyman@gmail.com)
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "core/ui/window.h"

#include <spdlog/spdlog.h>
#include <GLFW/glfw3.h>

__FRONTY_NS_START(Fronty)
__FRONTY_NS_START(Gui)

bool Window::s_IsWindowOpen;

Window::Window(const uint32_t& width, const uint32_t& height, const std::string& title)
    : m_Width(width)
    , m_Height(height)
    , m_Title(title)
{
    m_Window = NULL;
}

Window::~Window()
{
    glfwTerminate();
    spdlog::info("[Browser Window]: Window Closed");
}

bool Window::initWindow() noexcept
{
    if (m_Window != NULL)
        return false;

    if (!glfwInit())
        return false;

#ifdef __APPLE__
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#endif

    if ((m_Window = glfwCreateWindow(m_Width, m_Height, m_Title.c_str(), NULL, NULL)) == NULL)
    {
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(m_Window);

    spdlog::info("[Browser Window]: Window Created");
    return true;
}

bool Window::initWindowFromSharedObject(Window* win) noexcept
{
    if ((win->m_Window = glfwCreateWindow(win->m_Width, win->m_Height, win->m_Title.c_str(), NULL, m_Window)) == NULL)
        return false;

    glfwMakeContextCurrent(win->m_Window);

    spdlog::info("[Browser Window]: Child Window Created");
    return true;
}

bool Window::shouldClose() const noexcept
{
    return glfwWindowShouldClose(m_Window);
}

void Window::closeWindow() noexcept
{
    if (m_Window == NULL)
        return;
    glfwSetWindowShouldClose(m_Window, 1);
}

__FRONTY_IMMUTABLE_OBJ(GLFWwindow*)
Window::getCoreWindow() const noexcept
{
    return m_Window;
}

void Window::attachRenderer(const Types::ContextType&&) noexcept
{
}

void Window::attachMemoryLog(const void*) noexcept
{
}

void Window::attachWindowFlags(const Types::WindowStateFlags&) noexcept
{
}

__FRONTY_NS_END()
__FRONTY_NS_END()