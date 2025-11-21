//
// ReliaWare platform
// Copyright (c) 2025, ReliaWare
//
// SPDX-License-Identifier: BSD-3-Clause
//
#ifndef RELIAWARE_NETWORK_IPV6_DOMAIN_HXX
#define RELIAWARE_NETWORK_IPV6_DOMAIN_HXX

#pragma once

#include <reliaware/network/domain.hxx>

#include <sys/socket.h>
#include <netinet/in.h>
#ifdef __linux__
#   include <linux/in6.h>
#endif

#include <string>
#include <cstring>

namespace reliaware::network
{
#ifdef __linux__
    using in6_addr_t = struct in6_addr;
#endif

    class ipv6_domain : public domain_base<AF_INET6>
    {
    public:
        class ipv6_address : public address_base<struct sockaddr_in6>
        {
        public:
            ipv6_address() = delete;

            ipv6_address(const ipv6_address& addr);
            ipv6_address(in6_addr_t addr, in_port_t port);
            ipv6_address(const sockaddr_in6 *addr);

            virtual explicit operator std::string() const;
        };

        using address_t = ipv6_address;
    };

};

#endif // !RELIAWARE_NETWORK_IPV6_DOMAIN_HXX
