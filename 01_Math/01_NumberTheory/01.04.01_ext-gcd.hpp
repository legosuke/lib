#pragma once
#include <cassert>
#include <cstdint>
#include <type_traits>

/**
 * @brief 拡張ユークリッドの互除法
 * @note O(min(log(a),log(b)))
 */
template <typename Integer1, typename Integer2, typename Integer3>
Integer1 ext_gcd(Integer1 a, Integer2 b, Integer3& x, Integer3& y) {
    static_assert(std::is_integral<Integer1>::value);
    static_assert(std::is_integral<Integer2>::value);
    static_assert(std::is_integral<Integer3>::value || std::is_same<Integer3, __int128_t>::value);
    if (b == 0) { x = 1; y = 0; return a; }
    auto g = ext_gcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}