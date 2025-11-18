//
// ReliaWare platform
// Copyright (c) 2025, ReliaWare
//
// SPDX-License-Identifier: BSD-3-Clause
//
#ifndef RELIAWARE_SOCKET_HXX
#define RELIAWARE_SOCKET_HXX

#pragma once

namespace reliaware
{
    class socket
    {
    private:
        int m_fd;

    public:
        socket(int domain, int type, int protocol);
        virtual ~socket();
    };
};

#endif // !RELIAWARE_SOCKET_HXX
