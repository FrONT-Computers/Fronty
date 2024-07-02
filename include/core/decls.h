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

#ifndef FTY_DECLS
#define FTY_DECLS

// no value no pointer
#define __FRONTY_IMMUTABLE_OBJ(obj) const obj const

#if __cplusplus
#define __FRONTY_DECLS_START extern "C" {
#define __FRONTY_DECLS_END }
#else
#define __FRONTY_DECLS_START
#define __FRONTY_DECLS_END
#endif

#endif /* FTY_DECLS */