#
# ReliaWare platform
# Copyright (c) 2025, ReliaWare
#
# SPDX-License-Identifier: BSD-3-Clause
#
project(reliaware-modules-service)

add_library(reliaware-service SHARED)
target_include_directories(reliaware-service PUBLIC include)
target_sources(reliaware-service PRIVATE
    src/service.cxx)
