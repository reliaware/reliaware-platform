//
// ReliaWare platform
// Copyright (c) 2025, ReliaWare
//
// SPDX-License-Identifier: BSD-3-Clause
//
#include <reliaware/network/address.hxx>

#include <stdexcept>

using namespace reliaware::network;

local_address::local_address(const local_address& addr)
    : address_base(addr)
{ }

local_address::local_address(const std::string& path)
{
    if (path.length() > sizeof(m_value.sun_path) - 1)
        throw std::length_error("path");

#ifdef __APPLE__
    m_value.sun_len = sizeof(m_value);
#endif
    m_value.sun_family = AF_LOCAL;

    path.copy(m_value.sun_path, sizeof(m_value.sun_path));
}

local_address::local_address(const sockaddr_un *addr)
    : address_base(addr)
{ }

local_address::operator std::string() const
{
    return std::string(m_value.sun_path);
}

ipv4_address::ipv4_address(const ipv4_address& addr)
    : address_base(addr)
{ }

ipv4_address::ipv4_address(in_addr_t addr, in_port_t port)
    : address_base()
{
#ifdef __APPLE__
    m_value.sin_len = sizeof(m_value);
#endif
    m_value.sin_family = AF_INET;
    m_value.sin_addr.s_addr = htonl(addr);
    m_value.sin_port = htons(port);
}

ipv4_address::ipv4_address(const sockaddr_in *addr)
    : address_base(addr)
{ }

ipv4_address::operator std::string() const
{
    char str[INET_ADDRSTRLEN];
    ::inet_ntop(AF_INET, &m_value, str, sizeof(str));
    return std::string(str);
}

ipv6_address::ipv6_address(const ipv6_address& addr)
    : address_base(addr)
{ }

ipv6_address::ipv6_address(in6_addr_t addr, in_port_t port)
{
#ifdef __APPLE__
    m_value.sin6_len = sizeof(m_value);
#endif
    m_value.sin6_family = AF_INET6;
    m_value.sin6_port = htons(port);

    std::memcpy(&m_value.sin6_addr, &addr, sizeof(m_value.sin6_addr));
}

ipv6_address::ipv6_address(const sockaddr_in6 *addr)
    : address_base(addr)
{ }

ipv6_address::operator std::string() const
{
    char str[INET6_ADDRSTRLEN];
    ::inet_ntop(AF_INET6, &m_value, str, sizeof(str));
    return std::string(str);
}
