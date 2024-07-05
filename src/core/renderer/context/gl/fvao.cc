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

#include "core/renderer/context/gl/fvao.h"
#include <GL/glew.h>

__FRONTY_NS_START(Fronty)
__FRONTY_NS_START(Renderer)

uint32_t FrontyVertexArrayObject::s_VaoId;

uint32_t FrontyVertexArrayObject::genVertexArray() noexcept
{
    glGenVertexArrays(1, &s_VaoId);
    glBindVertexArray(s_VaoId);
    glEnableVertexAttribArray(0);
    return s_VaoId;
}

uint32_t FrontyVertexArrayObject::getVertexArrayId() noexcept
{
    return s_VaoId;
}

void FrontyVertexArrayObject::unbindVertexArray() noexcept
{
    glBindVertexArray(0);
}

__FRONTY_NS_END()
__FRONTY_NS_END()