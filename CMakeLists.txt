cmake_minimum_required (VERSION 3.31)

#TODO implement with ubuntu and raspberry
if(CMAKE_SYSTEM_NAME STREQUAL "Windows" OR CMAKE_SYSTEM_NAME STREQUAL "Darwin")
arieo_engine_project(
    arieo_glfw_win_module
    ALIAS arieo::modules::window::glfw
    PROJECT_TYPE module
    SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/private/src/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/private/src/*/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/private/src/*.mm
        ${CMAKE_CURRENT_SOURCE_DIR}/private/src/*/*.mm
    INTERFACES
        arieo::interface::window
    PACKAGES
        glfw
    LIBS
        arieo::base
        arieo::core
        glfw::glfw
)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
# arieo_engine_project(
#     arieo_glfw_win_module
#     ALIAS arieo::modules::window::glfw
#     PROJECT_TYPE module
#     SOURCES
#         ${CMAKE_CURRENT_SOURCE_DIR}/private/src/*.cpp
#         ${CMAKE_CURRENT_SOURCE_DIR}/private/src/*/*.cpp
#     INTERFACES
#         arieo::interface::window
#     PACKAGES
#         glfw
#         ubuntu_sysroot
#     LIBS
#         arieo::base
#         arieo::core
#         glfw::glfw
#         ubuntu_sysroot::X11
# )
endif()