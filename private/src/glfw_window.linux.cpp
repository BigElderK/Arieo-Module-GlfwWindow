#include "base/prerequisites.h"
#include "core/core.h"
#include "glfw_window.h"

#if defined(ARIEO_PLATFORM_LINUX)
// #define GLFW_EXPOSE_NATIVE_X11
// #define GLFW_EXPOSE_NATIVE_WAYLAND
#include "X11/Xlib.h"
//#include "X11/extensions/Xrandr.h"
#include <GLFW/glfw3native.h>
namespace Arieo
{
    std::uint64_t GLFWindow::getWindowHandle()
    {
        // Window x11_window = glfwGetX11Window(m_glfw_window);
        // if(x11_window != nullptr)
        // {
        //     return reinterpret_cast<std::uint64_t>(x11_window);
        // }

        // struct wl_surface* wayland_surface = glfwGetWaylandWindow(m_glfw_window);
        // if (wayland_surface != nullptr) 
        // {
        //     return reinterpret_cast<std::uint64_t>(wayland_surface);
        // }

        Core::Logger::error("cannot get window handle");
        return 0;
    }
}
#endif