//
// ReliaWare platform
// Copyright (c) 2025, ReliaWare
//
// SPDX-License-Identifier: BSD-3-Clause
//
#ifndef RELIAWARE_NETWORK_LOCAL_DOMAIN_HXX
#define RELIAWARE_NETWORK_LOCAL_DOMAIN_HXX

#pragma once

#include <reliaware/network/domain.hxx>

#include <sys/socket.h>
#include <sys/un.h>

#include <string>
#include <cstring>

namespace reliaware::network
{
    class local_domain : public domain_base<AF_LOCAL>
    {
    public:
        class local_address : public address_base<struct sockaddr_un>
        {
        public:
            local_address() = delete;

            local_address(const local_address& addr);
            local_address(const std::string& path);
            local_address(const sockaddr_un *addr);

            virtual explicit operator std::string() const;
        };

        using address_t = local_address;
    };

};

#endif // !RELIAWARE_NETWORK_LOCAL_DOMAIN_HXX
