#pragma once
#include <cstdint>

/**
 * @brief 大きな mod 上の計算
 * @note O(1)
 */
inline std::int64_t mod(std::int64_t a, std::int64_t m) {
    return (a % m + m) % m;
}

/**
 * @note O(\log{m})
 */
inline std::int64_t mul(std::int64_t a, std::int64_t b, std::int64_t m) {
    a = mod(a, m), b = mod(b, m);
    std::int64_t res = 0;
    while (b) {
        if (b & 1) res = mod(res + a, m);
        a = mod(a + a, m);
        b >>= 1;
    }
    return res;
}