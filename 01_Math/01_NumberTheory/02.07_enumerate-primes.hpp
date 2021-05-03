#pragma once
#include <cstdint>
#include <vector>
#include "03.01.00_sieve.base.hpp"

/**
 * @brief 素数列挙
 * @note O(n + SIEVE)
 *       - SIEVE : 篩
 */
template <class sieve>
std::vector<std::uint32_t> enumerate_primes(std::uint32_t n) {
    static_assert(is_sieve<sieve>::value);
    std::vector<std::uint32_t> res;
    auto is_prime = sieve();
    if (n >= 2) res.emplace_back(2);
    for (std::uint32_t i = 3; i <= n; i += 2) {
        if (is_prime[i]) res.emplace_back(i);
    }
    return res;
}