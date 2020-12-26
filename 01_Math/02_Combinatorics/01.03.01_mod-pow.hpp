#pragma once
#include <cstdint>

/**
 * @brief 累乗 : $a^n\bmod{m}$
 * @note O(\log{n})
 */
std::uint32_t mod_pow(std::int64_t a, std::uint64_t n, std::uint32_t m) {
    a = (a % m + m) % m;
    std::uint64_t res = 1;
    while (n) {
        if (n & 1) (res *= a) %= m;
        (a *= a) %= m;
        n >>= 1;
    }
    return (std::uint32_t)res;
}