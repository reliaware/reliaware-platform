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

    protected:
        socket(int fd);
        static socket create(int fd);

    public:
        socket(int domain, int type, int protocol);
        virtual ~socket();

        socket(const socket&) = delete;
        socket& operator=(const socket&) = delete;

        bool closed() const noexcept;

        void bind(const address& addr);
        void close() noexcept;
    };
};

#endif // !RELIAWARE_NETWORK_SOCKET_HXX
