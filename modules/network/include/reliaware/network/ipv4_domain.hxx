//
// ReliaWare platform
// Copyright (c) 2025, ReliaWare
//
// SPDX-License-Identifier: BSD-3-Clause
//
#ifndef RELIAWARE_NETWORK_IPV4_DOMAIN_HXX
#define RELIAWARE_NETWORK_IPV4_DOMAIN_HXX

#pragma once

#include <reliaware/network/domain.hxx>

#include <netinet/in.h>
#include <sys/socket.h>

#include <cstring>
#include <string>

namespace reliaware::network
{
    class ipv4_domain : public domain_base<AF_INET>
    {
    public:
        class ipv4_address : public address_base<struct sockaddr_in>
        {
        public:
            ipv4_address(const ipv4_address& addr);
            ipv4_address(in_addr_t addr, in_port_t port);
            ipv4_address(const sockaddr_in *addr);

            virtual explicit operator std::string() const;
        };

        using address_t = ipv4_address;
    };

}; // namespace reliaware::network

#endif // !RELIAWARE_NETWORK_IPV4_DOMAIN_HXX
