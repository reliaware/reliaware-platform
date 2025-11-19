#
# ReliaWare platform
# Copyright (c) 2025, ReliaWare
#
# SPDX-License-Identifier: BSD-3-Clause
#
project(reliaware-modules-network)

add_library(reliaware-network SHARED)

target_include_directories(reliaware-network PUBLIC include)
target_sources(reliaware-network PRIVATE
    src/buffer.cxx
    src/address.cxx
    src/socket.cxx
    src/listener.cxx
    src/connection.cxx)
