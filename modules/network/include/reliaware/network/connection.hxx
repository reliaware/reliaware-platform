//
// ReliaWare platform
// Copyright (c) 2025, ReliaWare
//
// SPDX-License-Identifier: BSD-3-Clause
//
#ifndef RELIAWARE_NETWORK_CONNECTION_HXX
#define RELIAWARE_NETWORK_CONNECTION_HXX

#pragma once

#include <reliaware/network/buffer.hxx>
#include <reliaware/network/socket.hxx>

namespace reliaware::network
{
    class connection : protected socket
    {
    public:
        connection(const address& addr, int type, int protocol);
        virtual ~connection();

        void connect(const address& addr);
    };
}; // namespace reliaware::network

#endif // !RELIAWARE_CNETWORK_ONNECTION_HXX
