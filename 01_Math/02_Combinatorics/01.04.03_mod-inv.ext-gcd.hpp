#pragma once
#include <cassert>
#include <cstdint>
#include "../01_NumberTheory/01.04.01_ext-gcd.hpp"
#include "01.01_mod-operation.hpp"

/**
 * @brief 逆元 : $a^{-1}\bmod{m}$ (拡張ユークリッドの互助法)
 * @note O(log(m))
 * @warning a と m は互いに素
 */
std::uint32_t mod_inv(std::int64_t a, std::uint32_t m) {
    std::int_least64_t x, y;
    auto g = ext_gcd(a, m, x, y);
    assert(g == 1);
    return mod(x, m);
}