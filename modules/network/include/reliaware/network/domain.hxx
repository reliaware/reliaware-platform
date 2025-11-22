//
// ReliaWare platform
// Copyright (c) 2025, ReliaWare
//
// SPDX-License-Identifier: BSD-3-Clause
//
#ifndef RELIAWARE_NETWORK_DOMAIN_HXX
#define RELIAWARE_NETWORK_DOMAIN_HXX

#pragma once

#include <bits/sockaddr.h>
#include <sys/socket.h>

#include <cstring>
#include <string>

namespace reliaware::network
{
    class domain
    {
    public:
        static constexpr sa_family_t family = AF_UNSPEC;

        class address
        {
        public:
            virtual int family() const = 0;
            virtual const sockaddr *value() const = 0;
            virtual socklen_t length() const = 0;

            virtual explicit operator std::string() const = 0;
        };

        using address_t = address;
    };

    template <sa_family_t TAddressFamily>
    class domain_base : public domain
    {
    public:
        static constexpr sa_family_t family = TAddressFamily;

        template <class TAddress>
        class address_base : public address
        {
        protected:
            TAddress m_value;

        protected:
            address_base()
            {
                std::memset(&m_value, 0, sizeof(m_value));
                reinterpret_cast<sockaddr *>(&m_value)->sa_family = TAddressFamily;
            }

            address_base(const TAddress *addr)
            {
                std::memcpy(&m_value, addr, sizeof(m_value));
            }

        public:
            virtual int family() const
            {
                return value()->sa_family;
            }

            virtual const sockaddr *value() const
            {
                return reinterpret_cast<const sockaddr *>(&m_value);
            }

            virtual socklen_t length() const
            {
                return sizeof(m_value);
            }
        };
    };
}; // namespace reliaware::network

#endif // !RELIAWARE_NETWORK_DOMAIN_HXX
