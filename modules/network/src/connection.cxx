//
// ReliaWare platform
// Copyright (c) 2025, ReliaWare
//
// SPDX-License-Identifier: BSD-3-Clause
//
#include <reliaware/network/connection.hxx>

#include <sys/socket.h>
#include <system_error>

using namespace reliaware::network;

connection::connection(const address& addr, int type, int protocol)
    : socket(addr.family(), type, protocol)
{
    try {
        bind(addr);
    } catch (std::exception& e) {
        socket::~socket();
        throw e;
    }
}

connection::~connection()
{
}

void connection::connect(const address& addr)
{
    if (::connect(m_fd, addr.value(), addr.length()) < 0)
        throw std::system_error(errno, std::generic_category());
}
