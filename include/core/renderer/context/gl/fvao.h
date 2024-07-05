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

#ifndef FTY_RENDERER_GL_FAVO_H
#define FTY_RENDERER_GL_FAVO_H

#include "core/decls.h"
#include <stdint.h>

__FRONTY_NS_START(Fronty)
__FRONTY_NS_START(Renderer)

class FrontyVertexArrayObject final
{
private:
    static uint32_t s_VaoId;

public:
    FrontyVertexArrayObject()  = delete;
    ~FrontyVertexArrayObject() = delete;

public:
    static uint32_t genVertexArray() noexcept;
    static uint32_t getVertexArrayId() noexcept;
    static void unbindVertexArray() noexcept;
};

__FRONTY_NS_END()
__FRONTY_NS_END()

#endif /* FTY_RENDERER_GL_FAVO_H */