#pragma once
#include <cstdint>

/**
 * @brief 拡張ユークリッドの互助法
 * @note O(\min\log(a,b))
 */
std::int64_t ext_gcd(std::int64_t a, std::int64_t b, std::int_least64_t& x, std::int_least64_t& y) {
    if (b == 0) { x = 1; y = 0; return a; }
    auto g = ext_gcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}