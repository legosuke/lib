#pragma once
#include <cstdint>
#include "01.02.01_gcd.hpp"
#include "../02_Combinatorics/01.03.02_mod-pow.big-mod.hpp"
#include "../02_Combinatorics/01.07_jacobi-symbol.hpp"
#include "../../06_Others/04_Random/01_random-number.hpp"

/**
 * @brief 素数判定 (オイラー擬素数)
 * @note O(k⋅log²(n))
 * @attention 誤判定する確率は 2⁻ᵏ
 */
bool is_prime(std::uint64_t n, std::uint32_t k = 40) {
    if (n <= 2 || !(n & 1)) return (n == 2);
    for (std::uint32_t i = 0; i < k; ++i) {
        auto a = random_number(2ul, n);
        if (gcd(n, a) != 1) return false;
        if ((n + jacobi(a, n)) % n != mod_pow(a, (n - 1) / 2, n)) return false;
    }
    return true;
}