//
// ReliaWare platform
// Copyright (c) 2025, ReliaWare
//
// SPDX-License-Identifier: BSD-3-Clause
//
#ifndef RELIAWARE_NETWORK_LISTENER_HXX
#define RELIAWARE_NETWORK_LISTENER_HXX

#pragma once

#include <reliaware/network/socket.hxx>

#include <system_error>
#include <optional>

namespace reliaware::network
{
    template<class TDomain>
    class listener : protected socket<TDomain>
    {
    private:
        static int check_type(int type)
        {
            if (type != SOCK_STREAM && type != SOCK_SEQPACKET)
                throw std::invalid_argument("type");

            return type;
        }

    public:
        listener(const TDomain::address_t& addr, int type, int protocol)
            : socket(check_type(type), protocol)
        {
            try {
                bind(addr);
            } catch (std::exception& e) {
                socket::~socket();
                throw e;
            }
        }

        virtual ~listener()
        { }

        void listen(int backlog = SOMAXCONN)
        {
            if (::listen(m_fd, backlog) < 0)
                throw std::system_error(errno, std::generic_category());
        }

        socket<TDomain> accept(int flags = 0)
        {
            int fd;
            struct sockaddr addr;
            socklen_t addrlen;

        again:
            if ((fd = ::accept4(m_fd, &addr, &addrlen, flags)) < 0)
            {
                if (errno == EINTR)
                    goto again;

                // if (errno == EAGAIN || errno == EWOULDBLOCK)
                //     return std::nullopt;

                throw std::system_error(errno, std::generic_category());
            }

            return socket<TDomain>::create(fd);
        }
    };
}; // namespace reliaware::network

#endif // !RELIAWARE_NETWORK_LISTENER_HXX
