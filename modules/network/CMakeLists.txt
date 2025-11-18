#
# ReliaWare SDS platform
# Copyright (c) 2025, ReliaWare
#
# SPDX-License-Identifier: BSD-3-Clause
#
project(reliaware-modules-network)

add_library(reliaware-network SHARED)

target_include_directories(reliaware-network PUBLIC include)
target_compile_options(reliaware-network PRIVATE
    -pedantic -Wall -Wextra -Werror)
target_sources(reliaware-network PRIVATE
    src/address.cxx
    src/socket.cxx)
