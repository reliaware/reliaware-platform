//
// ReliaWare platform
// Copyright (c) 2025, ReliaWare
//
// SPDX-License-Identifier: BSD-3-Clause
//
#ifndef RELIAWARE_SERVICE_HXX
#define RELIAWARE_SERVICE_HXX

#pragma once

#include <string>

namespace reliaware
{
    class service
    {
    private:
        std::string m_name;

    public:
        service(const std::string& name);
        virtual ~service();
    };
};

#endif // !RELIAWARE_SERVICE_HXX
