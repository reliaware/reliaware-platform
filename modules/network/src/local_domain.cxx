//
// ReliaWare platform
// Copyright (c) 2025, ReliaWare
//
// SPDX-License-Identifier: BSD-3-Clause
//
#include <reliaware/network/local_domain.hxx>

#include <stdexcept>

using namespace reliaware::network;


local_domain::local_address::local_address(const local_address& addr)
    : address_base(addr)
{
}

local_domain::local_address::local_address(const std::string& path)
{
    if (path.length() > sizeof(m_value.sun_path) - 1)
        throw std::length_error("path");

#ifdef __APPLE__
    m_value.sun_len    = sizeof(m_value);
#endif
    m_value.sun_family = AF_LOCAL;

    path.copy(m_value.sun_path, sizeof(m_value.sun_path));
}

local_domain::local_address::local_address(const sockaddr_un *addr)
    : address_base(addr)
{
}

local_domain::local_address::operator std::string() const
{
    return std::string(m_value.sun_path);
}
