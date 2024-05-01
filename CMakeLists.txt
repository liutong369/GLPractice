cmake_minimum_required(VERSION 3.14)

project(gl_main)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(PROCESSOR_NUM 16)

set(ROOT_DIR ${CMAKE_CURRENT_LIST_DIR})
set(SRC_DIR ${ROOT_DIR}/src)
set(OPEN_SRC_DIR ${ROOT_DIR}/open_source)
set(CMAKE_DIR ${ROOT_DIR}/cmake)

if (NOT CMAKE_INSTALL_PREFIX)
    set(CMAKE_INSTALL_PREFIX ${ROOT_DIR}/output)
endif ()

if (NOT CMAKE_PREFIX_PATH)
    set(CMAKE_PREFIX_PATH ${CMAKE_INSTALL_PREFIX})
endif ()

include(${CMAKE_DIR}/compile_options.cmake)

add_subdirectory(src)
add_subdirectory(open_source)
