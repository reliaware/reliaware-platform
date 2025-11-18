#
# ReliaWare platform
# Copyright (c) 2025, ReliaWare
#
# SPDX-License-Identifier: BSD-3-Clause
#
project(reliaware-services-registry)

add_executable(reliaware-registry-service)
target_sources(reliaware-registry-service PRIVATE
    src/main.cxx)
