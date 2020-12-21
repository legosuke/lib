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
    __int128_t am = mod(a, m), bm = mod(b, m);
    return std::int64_t(am * bm % m);
}