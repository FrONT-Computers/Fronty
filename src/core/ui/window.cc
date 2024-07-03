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
#include <GLFW/glfw3.h>

__FRONTY_NS_START(Fronty)
__FRONTY_NS_START(Gui)

bool Window::s_IsWindowOpen;

Window::Window(const uint32_t& width, const uint32_t& height, const std::string& title)
    : m_Width(width)
    , m_Height(height)
    , m_Title(title)
{
}

Window::~Window()
{
    glfwTerminate();
}

bool Window::initWindow() noexcept
{
}

void Window::closeWindow() noexcept
{
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