#pragma once
#include "01.01_mod-operation.hpp"

/**
 * @brief 累乗 : $a^n\bmod{m}$ ($m$ が大きい場合)
 * @note O(log(n))
 */
std::uint64_t mod_pow(std::int64_t a, std::uint64_t n, std::uint64_t m) {
    a = mod(a, m);
    std::uint64_t res = 1;
    while (n) {
        if (n & 1) res = mul(res, a, m);
        a = mul(a, a, m);
        n >>= 1;
    }
    return res;
}