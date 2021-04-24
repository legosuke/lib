#pragma once
#include <cstdint>
#include <vector>

/**
 * @brief 篩 (エラトステネス)
 * @note O(n⋅log(log(n)))
 */
std::vector<bool> sieve(std::uint32_t n) {
    std::vector<bool> is_prime(n, true);
    is_prime[0] = is_prime[1] = false;
    for (std::uint32_t i = 2; i * i < n; ++i) if (is_prime[i]) {
        for (std::uint32_t j = i * i; j < n; j += i) {
            is_prime[j] = false;
        }
    }
    return is_prime;
}