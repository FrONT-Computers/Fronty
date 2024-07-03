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

#ifndef FTY_RENDERER_TYPES_H
#define FTY_RENDERER_TYPES_H

#include "core/decls.h"

__FRONTY_NS_START(Fronty)
__FRONTY_NS_START(Types)

enum class ContextType
{
    CONTEXT_OPENGL,
    CONTEXT_DIRECTX,
    CONTEXT_METAL,
    CONTEXT_OPENGLES
};

enum class WindowStateFlags
{
    FLAG_WINDOW_DEFAULT_PAGE = 0x1,
    FLAG_WINDOW_RESTORE_PAGE = 0x2,

    FLAG_WINDOW_FULLSCREEN = 0x4,
    FLAG_WINDOW_MODAL_VIEW = 0x8,

    FLAG_WINDOW_ANTI_ALIAS = 0x10,
    FLAG_WINDOW_VSYNC      = 0x20,

    // FLAG_WINDOW_FULLSCREEN = 0x40
};

__FRONTY_NS_END()
__FRONTY_NS_END()

#endif /* FTY_RENDERER_TYPES_H */