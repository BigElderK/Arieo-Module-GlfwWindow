#include "base/prerequisites.h"
#include "core/core.h"
#include "glfw_window.h"

#if defined(ARIEO_PLATFORM_APPLE)

#define GLFW_EXPOSE_NATIVE_COCOA
#include <GLFW/glfw3native.h>

// Required for Metal & Objective-C interop
#import <Cocoa/Cocoa.h>
#import <QuartzCore/QuartzCore.h>
#import <Metal/Metal.h>

namespace Arieo
{
    std::uint64_t GLFWindow::getWindowHandle()
    {
        NSBundle* bundle = [NSBundle bundleWithPath:@"/System/Library/Frameworks/QuartzCore.framework"];
        if (!bundle)
        {
            Core::Logger::error("Cocoa: Failed to find QuartzCore.framework");
            return 0;
        }

        // 1. Get the NSWindow from GLFW
        id cocoaWindow = glfwGetCocoaWindow(m_glfw_window);
        NSWindow* ns_window = (NSWindow*)cocoaWindow;
        if (!ns_window)
        {
            Core::Logger::error("Cocoa: Failed to find ns_window");
            return 0;
        }

        // 2. Get the content view (NSView*)
        NSView* view = [ns_window contentView];
        if (!view)
        {
            Core::Logger::error("Cocoa: Failed to find view");
            return 0;
        }
        
        // 3. Create & assign a CAMetalLayer
        CAMetalLayer* meta_layer = [[bundle classNamed:@"CAMetalLayer"] layer];        
        if (!meta_layer)
        {
            Core::Logger::error("Cocoa: Failed to create metalLayer");
            return 0;
        }

        // 4. Enable layer backing (required for Metal)
        [view setLayer:meta_layer];
        [view setWantsLayer:YES];

        return reinterpret_cast<std::uint64_t>(meta_layer);
    }
}
#endif