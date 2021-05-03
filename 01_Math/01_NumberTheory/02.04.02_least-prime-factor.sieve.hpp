#pragma once
#include <cstdint>
#include <numeric>
#include <vector>

/**
 * @brief 最小素因数 (篩)
 * @note O(n)
 */
std::vector<std::uint32_t> least_prime_factor(std::uint32_t n) {
    std::vector<std::uint32_t> lpf(n, 0), pr;
    for (std::uint32_t i = 2; i < n; ++i) {
        if (lpf[i] == 0) {
            lpf[i] = i;
            pr.emplace_back(i);
        }
        for (std::uint32_t j = 0; j < (uint32_t)pr.size() && pr[j] <= lpf[i] && i * pr[j] < n; ++j) {
            lpf[i * pr[j]] = pr[j];
        }
    }
    return lpf;
}