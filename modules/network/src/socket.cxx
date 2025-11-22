//
// ReliaWare platform
// Copyright (c) 2025, ReliaWare
//
// SPDX-License-Identifier: BSD-3-Clause
//
#include <reliaware/network/socket.hxx>

#include <sys/socket.h>
#include <system_error>
#include <unistd.h>

using namespace reliaware::network;

socket::socket(int fd)
    : m_fd(fd)
{ }

reliaware::network::socket socket::create(int fd)
{
    return socket(fd);
}

socket::socket(int domain, int type, int protocol)
    : m_fd(-1)
{
    if ((m_fd = ::socket(domain, type, protocol)) < 0)
        throw std::system_error(errno, std::generic_category());
}

socket::~socket()
{
    close();
}

void socket::bind(const address& addr)
{
    if (::bind(m_fd, addr.value(), addr.length()) < 0)
        throw std::system_error(errno, std::generic_category());
}

void socket::close() noexcept
{
    if (m_fd != -1) {
        ::close(m_fd);
        m_fd = -1;
    }
}

bool socket::closed() const noexcept
{
    return m_fd == -1;
}
