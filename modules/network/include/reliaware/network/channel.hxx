//
// ReliaWare platform
// Copyright (c) 2025, ReliaWare
//
// SPDX-License-Identifier: BSD-3-Clause
//
#ifndef RELIAWARE_NETWORK_CHANNEL_HXX
#define RELIAWARE_NETWORK_CHANNEL_HXX

#pragma once

#include <reliaware/network/socket.hxx>

namespace reliaware::network
{
    class channel : protected socket
    { };
}; // namespace reliaware::network

#endif // !RELIAWARE_NETWORK_CHANNEL_HXX
