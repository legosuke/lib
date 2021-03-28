#pragma once
#include <cstdint>
#include <vector>
#include "01.04.03_mod-inv.ext-gcd.hpp"
#include "../01_NumberTheory/02.04.02_least-prime-factor.sieve.hpp"

/**
 * @brief 逆元の列挙
 * @note O(n)
 */
std::vector<std::uint32_t> mod_inv_table(std::uint32_t n, std::uint64_t m) {
    auto lpf = least_prime_factor(n);
    std::vector<std::uint32_t> res(n);
    res[0] = 0; res[1] = 1;
    for (std::uint32_t i = 2; i < n; ++i) {
        if (lpf[i] == i) res[i] = mod_inv(i, m);
        else res[i] = res[lpf[i]] * res[i / lpf[i]] % m;
    }
    return res;
}