#pragma once
#include <bitset>
#include "03.01.00_sieve.base.hpp"

/**
 * @brief 篩 (エラトステネス)
 * @note O(n⋅log(log(n))) time / O(n) space
 */
template <std::uint32_t N>
class eratosthenes : sieve_base {
public:
    eratosthenes() {
        is_prime.set();
        is_prime[0] = false;
        for (std::uint32_t i = 1; (2 * i + 1) * (2 * i + 1) <= N; ++i) if (is_prime[i]) {
            for (std::uint32_t j = 2 * i * (i + 1); 2 * j + 1 <= N; j += 2 * i + 1) {
                is_prime[j] = false;
            }
        }
    }

    const bool operator [] (std::uint32_t i) const {
        if (i % 2 == 0) return (i == 2);
        return (is_prime[(i - 1) / 2]);
    }
    
private:
    std::bitset<((N + 1) >> 1)> is_prime;
};