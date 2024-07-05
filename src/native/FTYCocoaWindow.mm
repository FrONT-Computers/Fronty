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

#import "native/FTYCocoaWindow.h"

@implementation FTYCocoaWindow

- (void) setTitleBarTransparent:(GLFWwindow*)window shouldHide:(BOOL)hide;
{
    NSWindow* currentWindow = glfwGetCocoaWindow(window);
    
    /* NSWindowStyleMaskFullSizeContentView */ 

    currentWindow.titlebarAppearsTransparent = hide;
    currentWindow.styleMask =   NSWindowStyleMaskTitled | 
                                NSWindowStyleMaskClosable | 
                                NSWindowStyleMaskMiniaturizable | 
                                NSWindowStyleMaskResizable;
    currentWindow.contentView.wantsLayer = YES;

    NSLog(@"Cocoa Window Configured");
}

void setTitleBarTransparent(GLFWwindow* window, bool hide)
{
    return [[FTYCocoaWindow new] setTitleBarTransparent: window shouldHide: hide];
}

@end