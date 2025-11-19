//
// ReliaWare platform
// Copyright (c) 2025, ReliaWare
//
// SPDX-License-Identifier: BSD-3-Clause
//
#ifndef RELIAWARE_CHANNEL_HXX
#define RELIAWARE_CHANNEL_HXX

#pragma once

#include <reliaware/socket.hxx>

namespace reliaware
{
    class channel : protected socket
    {
    };
};

#endif // !RELIAWARE_CHANNEL_HXX
