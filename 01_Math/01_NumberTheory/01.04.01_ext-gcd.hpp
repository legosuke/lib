#pragma once
#include <cassert>
#include <cstdint>
#include <type_traits>

/**
 * @brief 拡張ユークリッドの互助法
 * @note O(min(log(a),log(b)))
 */
template <typename Integer>
Integer ext_gcd(Integer a, Integer b, Integer& x, Integer& y) {
    static_assert(std::is_integral<Integer>::value);
    if (b == 0) { x = 1; y = 0; return a; }
    auto g = ext_gcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}