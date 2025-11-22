//
// ReliaWare platform
// Copyright (c) 2025, ReliaWare
//
// SPDX-License-Identifier: BSD-3-Clause
//
#ifndef RELIAWARE_COMMAND_HXX
#define RELIAWARE_COMMAND_HXX

#pragma once

#include <string>

namespace reliaware
{
    class command
    {
    private:
        std::string m_name;

    public:
        command(const std::string& name);
        virtual ~command();
    };
}; // namespace reliaware

#endif // !RELIAWARE_COMMAND_HXX
