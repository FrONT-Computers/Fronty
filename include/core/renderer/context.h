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

#ifndef FTY_RENDERER_CONTEXT_H
#define FTY_RENDERER_CONTEXT_H

#include "core/renderer/types.h"

__FRONTY_NS_START(Fronty)

class Context final
{
private:
    static Types::ContextType s_ContextMode;

public:
    Context()  = delete;
    ~Context() = delete;

public:
    /* Check if window is NOT open */
    static void               setRendererContext(const Types::ContextType&&) noexcept;
    static Types::ContextType getRendererContext() noexcept;
};

__FRONTY_NS_END()

#endif /* FTY_RENDERER_CONTEXT_H */