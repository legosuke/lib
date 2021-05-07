#pragma once
#include <cstdint>
#include "01.02.01.01_gcd.hpp"
#include "../02_Combinatorics/01.03.02_mod-pow.big-mod.hpp"
#include "../../06_Others/04_Random/01_random-number.hpp"

/**
 * @brief 素数判定 (強擬似素数)
 * @note O(k⋅log²(n))
 * @attention 誤判定する確率は 4⁻ᵏ
 */
bool is_prime(std::uint64_t n, std::uint32_t k = 20) {
    if (n < 2 || !(n & 1)) return (n == 2);
    for (std::uint32_t i = 0; i < k; ++i) {
        auto a = random_number(2ul, n);
        if (gcd(n, a) != 1) return false;
        std::uint64_t s = 0, n1 = n - 1, d = n1;
        while (!(d & 1)) {
            d >>= 1;
            ++s;
        }
        auto pw = mod_pow(a, d, n);
        bool is_composite = (pw != 1);
        for (std::uint32_t i = 0; i < s; ++i) {
            is_composite &= (pw != n1);
            pw = mul(pw, pw, n);
        }
        if (is_composite) return false;
    }
    return true;
}