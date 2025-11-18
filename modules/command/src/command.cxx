//
// ReliaWare SDS platform
// Copyright (c) 2025, ReliaWare
//
// SPDX-License-Identifier: BSD-3-Clause
//
#include <reliaware/command.hxx>

using namespace reliaware;

command::command(const std::string& name)
    : m_name(name)
{
}

command::~command()
{
}
