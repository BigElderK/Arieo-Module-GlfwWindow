#include "base/prerequisites.h"
#include "core/core.h"
#include "glfw_window.h"
namespace Arieo
{
    void GLFWindowManager::initialize()
    {
        if(!glfwInit())
        {
            Core::Logger::fatal("Failed to initialize GLFW");
        }
    }

    void GLFWindowManager::finalize()
    {
        for(GLFWindow* window : std::unordered_set(m_glf_window_set))
        {
            destroyWindow(window);
        }
        m_glf_window_set.clear();
        glfwTerminate();
    }

    void* GLFWindowManager::getDisplay()
    {
        return nullptr;
    }

    Base::Interface<Interface::Window::IWindow> GLFWindowManager::createWindow(std::uint16_t pos_x, std::uint16_t pos_y, std::uint16_t width, std::uint16_t height)
    {
        // Configure GLFW window
        // glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        // glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        GLFWwindow* window = glfwCreateWindow(width, height, "GLFW Window", nullptr, nullptr);
        if (!window) 
        {
            Core::Logger::error("Failed to create GLFW window");
            return nullptr;
        }

        GLFWindow* glf_window = Base::newT<GLFWindow>(this, window);
        m_glf_window_set.emplace(glf_window);

        return glf_window;
    }

    Base::Interface<Interface::Window::IWindow> GLFWindowManager::getMainWindow()
    {
        Core::Logger::error("GLFWindowManager::getMainWindow() not implemented, using createWindow instead");
        return nullptr;
    }

    void GLFWindowManager::destroyWindow(Base::Interface<Interface::Window::IWindow> window)
    {
        GLFWindow* glfwindow = window.castTo<GLFWindow>();
        m_glf_window_set.erase(glfwindow);
        glfwDestroyWindow(glfwindow->m_glfw_window);
        window.destroyAs<GLFWindow>();
    }

    void GLFWindowManager::onInitialize()
    {

    }

    void GLFWindowManager::onTick()
    {
        for(GLFWindow* window : m_glf_window_set)
        {
            if(!glfwWindowShouldClose(window->m_glfw_window)) 
            {
                // Clear the screen
                // glClear(GL_COLOR_BUFFER_BIT);

                // Swap front and back buffers
                glfwSwapBuffers(window->m_glfw_window);

                // Poll for and process events
                glfwPollEvents();
            }
            else
            {
                destroyWindow(window);
            }
        }
    }

    void GLFWindowManager::onDeinitialize()
    {
        
    }
}