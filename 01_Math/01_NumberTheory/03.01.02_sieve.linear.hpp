#pragma once
#include <cstdint>
#include <vector>
#include "02.04.02_least-prime-factor.sieve.hpp"

/**
 * @brief 篩 (線形)
 * @note O(n)
 */
std::vector<bool> sieve(std::uint32_t n) {
    std::vector<bool> isp(n, false);
    std::vector<std::uint32_t> lpf = least_prime_factor(n);
    for (std::uint32_t i = 2; i < n; ++i) {
        isp[i] = (lpf[i] == i);
    }
    return isp;
}