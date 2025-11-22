//
// ReliaWare platform
// Copyright (c) 2025, ReliaWare
//
// SPDX-License-Identifier: BSD-3-Clause
//
#ifndef RELIAWARE_NETWORK_SOCKET_HXX
#define RELIAWARE_NETWORK_SOCKET_HXX

#pragma once

#include <reliaware/network/domain.hxx>

#include <sys/socket.h>
#include <unistd.h>

#include <system_error>

namespace reliaware::network
{
    template<class TDomain>
    class socket
    {
    protected:
        int m_fd;
        // typename TDomain::address_t m_address;

    protected:
        socket(int fd)
            : m_fd(fd)
        { }

        static socket<TDomain> create(int fd)
        {
            return socket(fd);
        }

    public:
        socket(const socket&) = delete;
        socket& operator=(const socket&) = delete;

        socket(int type, int protocol)
            : m_fd(-1)
        {
            if ((m_fd = ::socket(TDomain::family, type, protocol)) < 0)
                throw std::system_error(errno, std::generic_category());
        }

        virtual ~socket()
        {
            close();
        }

        bool closed() const noexcept
        {
            return m_fd == -1;
        }

        void bind(const TDomain::address_t& addr)
        {
            if (::bind(m_fd, addr.value(), addr.length()) < 0)
                throw std::system_error(errno, std::generic_category());
        }

        void close() noexcept
        {
            if (!closed()) {
                ::close(m_fd);
                m_fd = -1;
            }
        }
    };
}; // namespace reliaware::network

#endif // !RELIAWARE_NETWORK_SOCKET_HXX
