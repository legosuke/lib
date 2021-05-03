#pragma once
#include <cstdint>
#include <vector>
#include "../02_Combinatorics/01.03.02_mod-pow.big-mod.hpp"

/**
 * @brief 素数判定 (ミラー・ラビン、決定的)
 * @note O(log³(n))
 * @warning n ≤ 2⁶⁴
 */
bool is_prime(std::uint64_t n) {
    if (n < 2 || !(n & 1)) return (n == 2);
    std::uint64_t d = n - 1;
    while (!(d & 1)) d >>= 1;
    for (auto a : std::vector<std::uint32_t>{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (a >= n) break;
        std::uint64_t t = d, y = mod_pow(a, t, n);
        while (t != n - 1 && y != 1 && y != n - 1) {
            y = mod_pow(y, 2, n);
            t <<= 1;
        }
        if (y != n - 1 && !(t & 1)) return false;
    }
    return true;
}