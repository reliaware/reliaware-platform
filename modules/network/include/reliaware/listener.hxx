//
// ReliaWare platform
// Copyright (c) 2025, ReliaWare
//
// SPDX-License-Identifier: BSD-3-Clause
//
#ifndef RELIAWARE_LISTENER_HXX
#define RELIAWARE_LISTENER_HXX

#pragma once

#include <reliaware/socket.hxx>

namespace reliaware
{
    class listener : protected socket
    {
    public:
        listener() = delete;
        listener(const address& addr, int type, int protocol);
        virtual ~listener();
    };
};

#endif // !RELIAWARE_LISTENER_HXX
