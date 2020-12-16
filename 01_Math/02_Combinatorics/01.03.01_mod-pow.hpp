#pragma once
#include <cstdint>

/**
 * @brief 累乗 : $a^n\mod{m}$
 * @note O(\log{n})
 */
std::int64_t mod_pow(std::int64_t a, std::int64_t n, std::int32_t m) {
    a = (a % m + m) % m;
    std::int64_t res = 1;
    while (n) {
        if (n & 1) (res *= a) %= m;
        (a *= a) %= m;
        n >>= 1;
    }
    return res;
}