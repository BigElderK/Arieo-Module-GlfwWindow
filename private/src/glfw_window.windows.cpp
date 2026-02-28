#include "base/prerequisites.h"
#include "core/core.h"
#include "glfw_window.h"

#if defined(ARIEO_PLATFORM_WINDOWS)
#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3native.h>
#include <windows.h>
namespace Arieo
{
    std::uint64_t GLFWindow::getWindowHandle()
    {
        HWND hwnd = glfwGetWin32Window(m_glfw_window);
        return reinterpret_cast<std::uint64_t>(hwnd);
    }
}
#endif




