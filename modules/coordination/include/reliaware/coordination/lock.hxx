//
// ReliaWare platform
// Copyright (c) 2025, ReliaWare
//
// SPDX-License-Identifier: BSD-3-Clause
//
#ifndef RELIAWARE_COORDINATION_HXX
#define RELIAWARE_COORDINATION_HXX

#pragma once

#include <utility>

namespace reliaware::coordination
{
    enum class lock_mode
    {
        NULL = 0,
        CONCURRENT_READ,
        CONCURRENT_WRITE,
        PROTECTED_READ,
        PROTECTED_WRITE,
        EXCLUSIVE
    };

    constexpr bool is_mode_compatible(lock_mode current, lock_mode desired)
    {
        constexpr bool compatibility_table[6][6] = {
            // NL     CR     CW     PR     PW     EX
            { true, true, true, true, true, true },     // NL
            { true, true, true, true, true, false },    // CR
            { true, true, true, false, false, false },  // CW
            { true, true, false, true, false, false },  // PR
            { true, true, false, false, false, false }, // PW
            { true, false, false, false, false, false } // EX
        };

        return compatibility_table[std::to_underlying(current)][std::to_underlying(desired)];
    }
}; // namespace reliaware::coordination

#endif // !RELIAWARE_COORDINATION_HXX
