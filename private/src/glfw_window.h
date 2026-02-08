#pragma once
#include "interface/window/window.h"

// #define GLFW_INCLUDE_VULKAN
#define GLFW_INCLUDE_NONE

#include <GLFW/glfw3.h>
namespace Arieo
{
    class GLFWindow final
        : public Interface::Window::IWindow
    {
    public:
        GLFWindow(Interface::Window::IWindowManager* window_manager, GLFWwindow* window)
            : m_window_manager(window_manager), m_glfw_window(window)
        {

        }

        std::uint64_t getWindowHandle() override;

        Base::Math::Rect<std::uint32_t> getWindowRect() override
        {
            Base::Math::Rect<std::uint32_t> win_rect{};

            int x, y;
            int width, height;
            glfwGetWindowPos(m_glfw_window, &x, &y);
            glfwGetWindowSize(m_glfw_window, &width, &height);

            return Base::Math::Rect<std::uint32_t>(
                x, y, width, height
            );
        }

        
        Base::Math::Vector<std::uint32_t, 2> getFramebufferSize() override
        {
            int width, height;
            glfwGetFramebufferSize(m_glfw_window, &width, &height);
            return Base::Math::Vector<std::uint32_t, 2>(width, height);
        }
        
        bool isClosed() override
        {
            return glfwWindowShouldClose(m_glfw_window);
        }

        Interface::Window::IWindowManager* getWindowManager() override
        {
            return m_window_manager;
        }
        
        Base::StringID getWindowPlatform() override
        {
            if(glfwGetPlatform() == GLFW_PLATFORM_WAYLAND)
            {
                return Base::MakeStringID("wayland");
            }
            else if(glfwGetPlatform() == GLFW_PLATFORM_X11)
            {
                return Base::MakeStringID("x11");
            }
            else if(glfwGetPlatform() == GLFW_PLATFORM_WIN32)
            {
                return Base::MakeStringID("win32");
            }
            else if(glfwGetPlatform() == GLFW_PLATFORM_COCOA)
            {
                return Base::MakeStringID("cocoa");
            }
            return Base::MakeStringID("unknown");
        } 

    private:
        friend class GLFWindowManager;
        GLFWwindow* m_glfw_window;
        Interface::Window::IWindowManager* m_window_manager;
    };

    class GLFWindowManager final
        : public Interface::Window::IWindowManager
    {
    protected:
        std::unordered_set<GLFWindow*> m_glf_window_set;
    public:
        void initialize();
        void finalize();

        void* getDisplay() override;

        Interface::Window::IWindow* createWindow(std::uint16_t pos_x, std::uint16_t pos_y, std::uint16_t width, std::uint16_t height) override;
        void destroyWindow(Interface::Window::IWindow*) override;

        Interface::Window::IWindow* getMainWindow() override;
    public:
        void onInitialize() override;
        void onTick() override;
        void onDeinitialize() override;
    };
}