//
// ReliaWare platform
// Copyright (c) 2025, ReliaWare
//
// SPDX-License-Identifier: BSD-3-Clause
//
#include <reliaware/network/ipv4_domain.hxx>

#include <stdexcept>

#include <arpa/inet.h>

using namespace reliaware::network;

ipv4_domain::ipv4_address::ipv4_address(const ipv4_address& addr)
    : address_base(addr)
{ }

ipv4_domain::ipv4_address::ipv4_address(in_addr_t addr, in_port_t port)
    : address_base()
{
#ifdef __APPLE__
    m_value.sin_len = sizeof(m_value);
#endif
    m_value.sin_addr.s_addr = htonl(addr);
    m_value.sin_port = htons(port);
}

ipv4_domain::ipv4_address::ipv4_address(const sockaddr_in *addr)
    : address_base(addr)
{ }

ipv4_domain::ipv4_address::operator std::string() const
{
    char str[INET_ADDRSTRLEN];
    ::inet_ntop(AF_INET, &m_value, str, sizeof(str));
    return std::string(str);
}
