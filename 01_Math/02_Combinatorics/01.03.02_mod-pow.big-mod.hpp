#pragma once
#include "01.01.01_big-mod.hpp"

/**
 * @brief 累乗 : $a^n\pmod{m}$ (mod が大きい場合)
 * @note O(\log{n}\log{m})
 */
std::int64_t mod_pow(std::int64_t a, std::int64_t n, std::int64_t MOD) {
    a = (a % MOD + MOD) % MOD;
    std::int64_t res = 1;
    while (n) {
        if (n & 1) res = mul(res, a, MOD);
        a = mul(a, a, MOD);
        n >>= 1;
    }
    return res;
}