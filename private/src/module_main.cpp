#include "base/prerequisites.h"
#include "core/core.h"
#include "glfw_window.h"
namespace Arieo
{
    GENERATOR_MODULE_ENTRY_FUN()
    ARIEO_DLLEXPORT void ModuleMain()
    {
        Core::Logger::setDefaultLogger("glfw_window");

        static struct DllLoader
        {
            Base::Instance<GLFWindowManager> glfw_window_manager;
            
            DllLoader()
            {
                glfw_window_manager->setSelf(glfw_window_manager.queryInterface<Interface::Window::IWindowManager>());
                glfw_window_manager->initialize();
                
                Base::Interface<Interface::Main::IMainModule> main_module = Core::ModuleManager::getInterface<Interface::Main::IMainModule>();
                main_module->registerTickable(glfw_window_manager.queryInterface<Interface::Main::ITickable>());

                Core::ModuleManager::registerInstance<Interface::Window::IWindowManager, GLFWindowManager>(
                    "glfw_window_manager", 
                    glfw_window_manager
                );
            }

            ~DllLoader()
            {
                Core::ModuleManager::unregisterInstance<Interface::Window::IWindowManager, GLFWindowManager>(
                    glfw_window_manager
                );
                glfw_window_manager->finalize();
            }
        } dll_loader;
    }
}