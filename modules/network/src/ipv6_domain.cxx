//
// ReliaWare platform
// Copyright (c) 2025, ReliaWare
//
// SPDX-License-Identifier: BSD-3-Clause
//
#include <reliaware/network/ipv6_domain.hxx>

#include <stdexcept>

#include <arpa/inet.h>

using namespace reliaware::network;

ipv6_domain::ipv6_address::ipv6_address(const ipv6_address& addr)
    : address_base(addr)
{ }

ipv6_domain::ipv6_address::ipv6_address(in6_addr_t addr, in_port_t port)
{
#ifdef __APPLE__
    m_value.sin6_len = sizeof(m_value);
#endif
    m_value.sin6_port = htons(port);

    std::memcpy(&m_value.sin6_addr, &addr, sizeof(m_value.sin6_addr));
}

ipv6_domain::ipv6_address::ipv6_address(const sockaddr_in6 *addr)
    : address_base(addr)
{ }

ipv6_domain::ipv6_address::operator std::string() const
{
    // TODO: define addrstrlen in domain_base
    char str[INET6_ADDRSTRLEN];
    ::inet_ntop(AF_INET6, &m_value, str, sizeof(str));
    return std::string(str);
}
