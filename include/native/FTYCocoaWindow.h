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

#ifndef FTY_NATIVE_COCOCA_WINDOW_H
#define FTY_NATIVE_COCOCA_WINDOW_H

#define GLFW_EXPOSE_NATIVE_COCOA

#import "FTYCocoaWindow-Interface.h"

#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

#import <AppKit/AppKit.h>

@interface FTYCocoaWindow : NSObject

- (void) setTitleBarTransparent:(GLFWwindow*)window shouldHide:(BOOL)hide;

@end

#endif /* FTY_NATIVE_COCOCA_WINDOW_H */ 