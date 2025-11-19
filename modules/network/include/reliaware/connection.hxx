//
// ReliaWare platform
// Copyright (c) 2025, ReliaWare
//
// SPDX-License-Identifier: BSD-3-Clause
//
#ifndef RELIAWARE_CONNECTION_HXX
#define RELIAWARE_CONNECTION_HXX

#pragma once

#include <reliaware/socket.hxx>
#include <reliaware/buffer.hxx>

namespace reliaware
{
    class connection : protected socket
    {
    };
};

#endif // !RELIAWARE_CONNECTION_HXX
