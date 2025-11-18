//
// ReliaWare platform
// Copyright (c) 2025, ReliaWare
//
// SPDX-License-Identifier: BSD-3-Clause
//
#include <reliaware/socket.hxx>

#include <sys/socket.h>
#include <unistd.h>
#include <system_error>

using namespace reliaware;

socket::socket(int domain, int type, int protocol)
    : m_fd(-1)
{
    if ((m_fd = ::socket(domain, type, protocol)) == -1)
        throw std::system_error(errno, std::generic_category());
}

socket::~socket()
{
    if (m_fd != -1)
        ::close(m_fd);
}
