#
# ReliaWare platform
# Copyright (c) 2025, ReliaWare
#
# SPDX-License-Identifier: BSD-3-Clause
#
project(reliaware-services-transport)

add_executable(reliaware-transport-service)
target_sources(reliaware-transport-service PRIVATE
    src/main.cxx)
