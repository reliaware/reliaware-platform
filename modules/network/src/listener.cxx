//
// ReliaWare platform
// Copyright (c) 2025, ReliaWare
//
// SPDX-License-Identifier: BSD-3-Clause
//
#include <system_error>

#include <reliaware/network/listener.hxx>

using namespace reliaware::network;

int listener::check_type(int type)
{
    if ((type != SOCK_STREAM) && (type != SOCK_SEQPACKET))
        throw std::invalid_argument("type");

    return type;
}

listener::listener(const address& addr, int type, int protocol)
    : socket(addr.family(), check_type(type), protocol)
{
    try {
        bind(addr);
    } catch (std::exception& e) {
        socket::~socket();
        throw e;
    }
}

listener::~listener()
{
}

void listener::listen(int backlog)
{
    if (::listen(m_fd, backlog) < 0)
        throw std::system_error(errno, std::generic_category());
}
