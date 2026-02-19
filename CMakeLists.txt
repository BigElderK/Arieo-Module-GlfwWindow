cmake_minimum_required (VERSION 3.31)

include($ENV{ARIEO_BUILDENV_PACKAGE_INSTALL_FOLDER}/cmake/build_environment.cmake)
project(ArieoEngine)

#TODO implement with ubuntu and raspberry
if(CMAKE_SYSTEM_NAME STREQUAL "Windows" OR CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    arieo_engine_project(
        arieo_glfw_win_module
        PROJECT_TYPE module

        DEPENDENCIES
            ARIEO_PACKAGES
                Arieo-Core
                Arieo-Interface-Window
            THIRDPARTY_PACKAGES
                glfw
            INTERFACES
                Arieo-Interface-Window::arieo_window_interface
            PRIVATE_LIBS
                Arieo-Core::arieo_core
                glfw::glfw

        SOURCES
            CXX_SOURCES
                ${CMAKE_CURRENT_LIST_DIR}/private/src/*.cpp
                ${CMAKE_CURRENT_LIST_DIR}/private/src/*/*.cpp
                ${CMAKE_CURRENT_LIST_DIR}/private/src/*.mm
                ${CMAKE_CURRENT_LIST_DIR}/private/src/*/*.mm
    )
elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
# arieo_engine_project(
#     arieo_glfw_win_module
#     PROJECT_TYPE module
#
#     PACKAGES
#         glfw
#         ubuntu_sysroot
#     INTERFACES
#         Arieo-Interface-Window::arieo_window_interface
#     PRIVATE_LIBS
#         Arieo-Core::arieo_core
#         glfw::glfw
#         ubuntu_sysroot::X11
#
#     SOURCES
#         ${CMAKE_CURRENT_LIST_DIR}/private/src/*.cpp
#         ${CMAKE_CURRENT_LIST_DIR}/private/src/*/*.cpp
# )
    # Create a dummy install target for Linux (not yet implemented)
    message(STATUS "Arieo-Module-GlfwWindow: Skipping build for ${CMAKE_SYSTEM_NAME} (not yet implemented)")
    install(CODE "message(STATUS \"Arieo-Module-GlfwWindow: No installation needed for ${CMAKE_SYSTEM_NAME}\")")
else()
    # Create a dummy install target for other platforms
    message(STATUS "Arieo-Module-GlfwWindow: Skipping build for ${CMAKE_SYSTEM_NAME} (Windows/Darwin only)")
    install(CODE "message(STATUS \"Arieo-Module-GlfwWindow: No installation needed for ${CMAKE_SYSTEM_NAME}\")")
endif()
