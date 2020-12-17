#pragma once
#include "01_Math/02_Combinatorics/01.01.01_big-mod.hpp"

/**
 * @brief 累乗 : $a^n\bmod{m}$ ($m$ が大きい場合)
 * @note O(\log{n}\log{m})
 */
std::int64_t mod_pow(std::int64_t a, std::int64_t n, std::int64_t m) {
    a = (a % m + m) % m;
    std::int64_t res = 1;
    while (n) {
        if (n & 1) res = mul(res, a, m);
        a = mul(a, a, m);
        n >>= 1;
    }
    return res;
}