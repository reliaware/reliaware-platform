//
// ReliaWare platform
// Copyright (c) 2025, ReliaWare
//
// SPDX-License-Identifier: BSD-3-Clause
//
#include <reliaware/listener.hxx>

using namespace reliaware;

listener::listener(const address& addr, int type, int protocol)
    : socket(addr.family(), type, protocol)
{
}

listener::~listener()
{
}
