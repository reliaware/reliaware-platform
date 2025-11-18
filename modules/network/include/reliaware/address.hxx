//
// ReliaWare SDS platform
// Copyright (c) 2025, ReliaWare
//
// SPDX-License-Identifier: BSD-3-Clause
//
#ifndef RELIAWARE_ADDRESS_HXX
#define RELIAWARE_ADDRESS_HXX

#pragma once

#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>

#include <string>
#include <cstring>

namespace reliaware
{
    class address
    {
    public:
        virtual int family() = 0;
        virtual const sockaddr *value() = 0;
    };

    template<class _Address>
    class address_base : public address
    {
    protected:
        _Address m_value;

    protected:
        address_base() {
            std::memset(&m_value, 0, sizeof(m_value));
        }

        address_base(const _Address *addr) {
            std::memcpy(&m_value, addr, sizeof(m_value));
        }

    public:
        virtual int family() {
            return value()->sa_family;
        }

        virtual const sockaddr *value() {
            return reinterpret_cast<sockaddr *>(&m_value);
        }
    };

    class local_address : public address_base<struct sockaddr_un>
    {
    public:
        local_address(const local_address& addr);
        local_address(const std::string& path);
        local_address(const sockaddr_un *addr);
    };

    class ipv4_address : public address_base<struct sockaddr_in>
    {
    public:
        ipv4_address(const ipv4_address& addr);
        ipv4_address(in_addr_t addr, in_port_t port);
        ipv4_address(const sockaddr_in *addr);
    };

    class ipv6_address : public address_base<struct sockaddr_in6>
    {
    public:
        ipv6_address(const ipv6_address& addr);
        ipv6_address(in6_addr_t addr, in_port_t port);
        ipv6_address(const sockaddr_in6 *addr);
    };
};

#endif // !RELIAWARE_ADDRESS_HXX
