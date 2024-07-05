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

#ifndef FTY_UI_WINDOW_H
#define FTY_UI_WINDOW_H

#define __FRONTY_C_TYPES

#include "core/decls.h"
#include "core/types.h"

#include <GLFW/glfw3.h>

#include <string>

__FRONTY_NS_START(Fronty)

class Context;

__FRONTY_NS_START(Gui)

class Window final
{
private:
    friend class Fronty::Context;

private:
    GLFWwindow* m_Window;
    uint32_t    m_Width, m_Height;
    int         monitor;
    std::string m_Title;
    /* Static Fields */
    static bool s_IsWindowOpen;

public:
    Window(const uint32_t&, const uint32_t&, const std::string&);
    ~Window();

public:
    /* Add More Member Functions */
    bool initWindow() noexcept;
    bool initWindowFromSharedObject(Window*) noexcept;
    bool shouldClose() const noexcept;
    void closeWindow() noexcept;

    __FRONTY_IMMUTABLE_OBJ(GLFWwindow*)
    getCoreWindow() const noexcept;

public:
    /* TODO: Needs to be a Render Context (OpenGL, Metal, DirectX, etc) */
    void attachRenderer(const Types::ContextType&&) noexcept;
    /* To Monitor Memory Consumption */
    void attachMemoryLog(const void*) noexcept;
    void attachWindowFlags(const Types::WindowStateFlags&) noexcept;
};

__FRONTY_NS_END()
__FRONTY_NS_END()

#endif /* FTY_UI_WINDOW_H */