//
// ReliaWare platform
// Copyright (c) 2025, ReliaWare
//
// SPDX-License-Identifier: BSD-3-Clause
//
#ifndef RELIAWARE_NETWORK_CONNECTION_HXX
#define RELIAWARE_NETWORK_CONNECTION_HXX

#pragma once

#include <reliaware/network/buffer.hxx>
#include <reliaware/network/socket.hxx>

namespace reliaware::network
{
    template<class TDomain>
    class connection : protected socket<TDomain>
    {
    public:
        connection(const TDomain::address_t& addr, int type, int protocol)
            : socket(type, protocol)
        {
            try {
                bind(addr);
            } catch (std::exception& e) {
                socket::~socket();
                throw e;
            }
        }

        virtual ~connection()
        { }

        void connect(const TDomain::address_t& addr)
        {
            if (::connect(m_fd, addr.value(), addr.length()) < 0)
                throw std::system_error(errno, std::generic_category());
        }
    };
}; // namespace reliaware::network

#endif // !RELIAWARE_CNETWORK_ONNECTION_HXX
