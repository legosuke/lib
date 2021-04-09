#pragma once
#include <cstdint>
#include <numeric>
#include <vector>

/**
 * @brief オイラーのトーシェント関数 (テーブル)
 * @note O(n⋅log(log(n)))
 */
std::vector<std::uint32_t> totient(std::uint32_t n) {
    std::vector<std::uint32_t> phi(n);
    std::iota(phi.begin(), phi.end(), 0);
    for (std::uint32_t i = 2; i < n; ++i) {
        if (phi[i] != i) continue;
        for (std::uint32_t j = i; j < n; j += i) {
            phi[j] -= phi[j] / i;
        }
    }
    return phi;
}