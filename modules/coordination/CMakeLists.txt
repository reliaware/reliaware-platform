#
# ReliaWare platform
# Copyright (c) 2025, ReliaWare
#
# SPDX-License-Identifier: BSD-3-Clause
#
project(reliaware-modules-coordination)

add_library(reliaware-coordination SHARED)
target_include_directories(reliaware-coordination PUBLIC include)
target_sources(reliaware-coordination PRIVATE
    src/lock.cxx)
