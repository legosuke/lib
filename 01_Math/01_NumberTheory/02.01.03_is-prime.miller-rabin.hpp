#pragma once
#include <cstdint>
#include <random>
#include "../02_Combinatorics/01.03.02_mod-pow.big-mod.hpp"
#include "../../06_Others/04_Random/01_random-number.hpp"

/**
 * @brief 素数判定 (ミラー・ラビン)
 * @note O(k\log^3{n})
 * @attention 誤判定する確率は 4^{-k}
 */
bool is_prime(std::uint64_t n, std::uint32_t k = 20) {
    if (n == 2) return true;
    if (n < 2 || !(n & 1)) return false;
    std::uint64_t d = n - 1;
    while (!(d & 1)) d >>= 1;
    for (std::uint32_t i = 0; i < k; ++i) {
        std::uint64_t a = random_number((std::uint64_t)1, n), t = d, y = mod_pow(a, t, n);
        while (t != n - 1 && y != 1 && y != n - 1) {
            y = mod_pow(y, 2, n);
            t <<= 1;
        }
        if (y != n - 1 && !(t & 1)) return false;
    }
    return true;
}