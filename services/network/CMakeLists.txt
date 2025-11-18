#
# ReliaWare platform
# Copyright (c) 2025, ReliaWare
#
# SPDX-License-Identifier: BSD-3-Clause
#
project(reliaware-services-network)

add_executable(reliaware-network-service)
target_sources(reliaware-network-service PRIVATE
    src/main.cxx)
