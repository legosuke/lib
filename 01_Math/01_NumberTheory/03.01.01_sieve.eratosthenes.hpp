#pragma once
#include <cstdint>
#include <vector>

/**
 * @brief 篩 (エラトステネス)
 * @note O(n⋅log(log(n)))
 */
std::vector<bool> sieve(std::uint32_t n) {
    std::vector<bool> isp(n, true);
    isp[0] = isp[1] = false;
    for (std::uint32_t i = 2; i * i < n; ++i) if (isp[i]) {
        for (std::uint32_t j = i * i; j < n; j += i) {
            isp[j] = false;
        }
    }
    return isp;
}