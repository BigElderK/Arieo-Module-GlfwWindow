cmake_minimum_required (VERSION 3.31)

include($ENV{ARIEO_BUILDENV_PACKAGE_INSTALL_FOLDER}/cmake/build_environment.cmake)
project(ArieoEngine)

#TODO implement with ubuntu and raspberry
if(CMAKE_SYSTEM_NAME STREQUAL "Windows" OR CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    arieo_engine_project(
        arieo_glfw_win_module
        PROJECT_TYPE module

        PACKAGES
            Arieo-Interface-Window
            glfw
            Arieo-Core
        INTERFACES
            Arieo-Interface-Window::arieo_window_interface
        PRIVATE_LIBS
            Arieo-Core::arieo_core
            glfw::glfw

        SOURCES
            ${CMAKE_CURRENT_SOURCE_DIR}/private/src/*.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/private/src/*/*.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/private/src/*.mm
            ${CMAKE_CURRENT_SOURCE_DIR}/private/src/*/*.mm
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
#         ${CMAKE_CURRENT_SOURCE_DIR}/private/src/*.cpp
#         ${CMAKE_CURRENT_SOURCE_DIR}/private/src/*/*.cpp
# )
endif()