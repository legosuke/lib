#pragma once
#include <cstdint>
#include <random>
#include "01_Math/01_NumberTheory/01.02.01_gcd.hpp"
#include "01_Math/02_Combinatorics/01.03.02_mod-pow.big-mod.hpp"
#include "06_Others/04_Rnd/01_rnd-number.hpp"

/**
 * @brief 素数判定 (フェルマー)
 * @note O(k\log^2{n})
 */
bool is_prime(std::uint64_t n, std::uint32_t k = 50) {
    if (n <= 2) return (n == 2);
    for (std::uint32_t i = 0; i < k; ++i) {
        auto a = random_number(2ul, n);
        if (gcd(n, a) != 1) return false;
        if (mod_pow(a, n - 1, n) != 1) return false;
    }
    return true;
}