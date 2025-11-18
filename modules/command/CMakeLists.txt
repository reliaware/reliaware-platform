#
# ReliaWare platform
# Copyright (c) 2025, ReliaWare
#
# SPDX-License-Identifier: BSD-3-Clause
#
project(reliaware-modules-command)

add_library(reliaware-command SHARED)
target_include_directories(reliaware-command PUBLIC include)
target_sources(reliaware-command PRIVATE
    src/command.cxx)
