//
// ReliaWare platform
// Copyright (c) 2025, ReliaWare
//
// SPDX-License-Identifier: BSD-3-Clause
//
#ifndef RELIAWARE_NETWORK_SOCKET_HXX
#define RELIAWARE_NETWORK_SOCKET_HXX

#pragma once

#include <reliaware/network/address.hxx>

namespace reliaware::network
{
    class socket
    {
    protected:
        int m_fd;

    public:
        socket(int fd);
        socket(int domain, int type, int protocol);
        virtual ~socket();

        socket(const socket&) = delete;
        socket& operator=(const socket&) = delete;

        void bind(const address& addr);
    };
};

#endif // !RELIAWARE_NETWORK_SOCKET_HXX
