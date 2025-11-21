//
// ReliaWare platform
// Copyright (c) 2025, ReliaWare
//
// SPDX-License-Identifier: BSD-3-Clause
//
#ifndef RELIAWARE_NETWORK_DOMAIN_HXX
#define RELIAWARE_NETWORK_DOMAIN_HXX

#pragma once

#include <sys/socket.h>

#include <string>
#include <cstring>

namespace reliaware::network
{
    class domain
    {
    public:
        // TODO: replace with sa_family_t
        using address_family_t = int;

        virtual address_family_t address_family() const = 0;

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

    template<domain::address_family_t TAF_ID>
    class domain_base : public domain
    {
    public:
        virtual address_family_t address_family() const {
            return TAF_ID;
        }

        template<class TAddress>
        class address_base : public address
        {
        protected:
            TAddress m_value;

        protected:
            address_base() {
                std::memset(&m_value, 0, sizeof(m_value));
                value()->sa_family = TAF_ID;
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

        using address_t = address_base;
    };
};

#endif // !RELIAWARE_NETWORK_DOMAIN_HXX
