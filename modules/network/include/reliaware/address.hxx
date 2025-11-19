//
// ReliaWare platform
// Copyright (c) 2025, ReliaWare
//
// SPDX-License-Identifier: BSD-3-Clause
//
#ifndef RELIAWARE_ADDRESS_HXX
#define RELIAWARE_ADDRESS_HXX

#pragma once

/**
 * TODO: move ifdefs into compat/
 */

#include <sys/socket.h>
#include <sys/un.h>
#include <netinet/in.h>
#ifdef __linux__
#   include <linux/in6.h>
#endif
#include <arpa/inet.h>

#include <string>
#include <cstring>

namespace reliaware
{
#ifdef __linux__
    using in6_addr_t = struct in6_addr;
#endif

    class address
    {
    public:
        virtual int family() const = 0;
        virtual const sockaddr *value() const = 0;
        virtual socklen_t length() const = 0;

        virtual explicit operator std::string() const = 0;
    };

    template<class TAddress>
    class address_base : public address
    {
    protected:
        TAddress m_value;

    protected:
        address_base() {
            std::memset(&m_value, 0, sizeof(m_value));
        }

        address_base(const TAddress *addr) {
            std::memcpy(&m_value, addr, sizeof(m_value));
        }

    public:
        virtual int family() const {
            return value()->sa_family;
        }

        virtual const sockaddr *value() const {
            return reinterpret_cast<const sockaddr *>(&m_value);
        }

        virtual socklen_t length() const {
            return sizeof(m_value);
        }
    };

    class local_address : public address_base<struct sockaddr_un>
    {
    public:
        local_address() = delete;

        local_address(const local_address& addr);
        local_address(const std::string& path);
        local_address(const sockaddr_un *addr);

        virtual explicit operator std::string() const;
    };

    class ipv4_address : public address_base<struct sockaddr_in>
    {
    public:
        ipv4_address() = delete;

        ipv4_address(const ipv4_address& addr);
        ipv4_address(in_addr_t addr, in_port_t port);
        ipv4_address(const sockaddr_in *addr);

        virtual explicit operator std::string() const;
    };

    class ipv6_address : public address_base<struct sockaddr_in6>
    {
    public:
        ipv6_address() = delete;

        ipv6_address(const ipv6_address& addr);
        ipv6_address(in6_addr_t addr, in_port_t port);
        ipv6_address(const sockaddr_in6 *addr);

        virtual explicit operator std::string() const;
    };
};

#endif // !RELIAWARE_ADDRESS_HXX
