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

std::optional<reliaware::network::socket> listener::accept(int flags)
{
    int fd;
    struct sockaddr addr;
    socklen_t addrlen;

again:
    if ((fd = ::accept4(m_fd, &addr, &addrlen, flags)) < 0)
    {
        if (errno == EINTR)
            goto again;

        if (errno == EAGAIN || errno == EWOULDBLOCK)
            return std::nullopt;

        throw std::system_error(errno, std::generic_category());
    }

    // TODO:
    // 1. Return an address somehow; maybe incapsulate in inside
    //    the socket class?
    // 2. Return connection?

    return std::make_optional<reliaware::network::socket>(fd);
}
