//
// ReliaWare platform
// Copyright (c) 2025, ReliaWare
//
// SPDX-License-Identifier: BSD-3-Clause
//
#ifndef RELIAWARE_COMPAT_IN_HXX
#define RELIAWARE_COMPAT_IN_HXX

#pragma once

#include <netinet/in.h>

#ifdef __linux__
#   include <linux/in6.h>
#endif

#ifdef __linux__
using in6_addr_t = struct in6_addr;
#endif

#endif // !RELIAWARE_COMPAT_IN_HXX
