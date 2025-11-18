#
# ReliaWare platform
# Copyright (c) 2025, ReliaWare
#
# SPDX-License-Identifier: BSD-3-Clause
#
cmake_minimum_required(VERSION 3.31)

project(reliaware VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_EXTENSIONS ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_EXTENSIONS ON)

if("${CMAKE_BUILD_TYPE}" STREQUAL "")
    set(CMAKE_BUILD_TYPE Debug)
endif()

add_compile_options(-pedantic -Wall -Wextra -Werror)
if ("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
    add_compile_options(-O0 -g -fno-omit-frame-pointer)
elseif("${CMAKE_BUILD_TYPE}" STREQUAL "Release")
    add_compile_definitions(-O2)
endif()

add_subdirectory(modules)
add_subdirectory(services)
add_subdirectory(tools)
