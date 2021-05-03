#pragma once
#include <bitset>
#include "03.01.00_sieve.base.hpp"

/**
 * @brief 篩 (エラトステネス)
 * @note O(n⋅log(log(n)))
 */
template <std::uint32_t N>
class eratosthenes : sieve_base {
public:
    eratosthenes() {
        is_prime.set();
        is_prime[0] = is_prime[1] = false;
        for (std::uint32_t i = 2; i * i <= N; ++i) if (is_prime[i]) {
            for (std::uint32_t j = i * i; j <= N; j += i) {
                is_prime[j] = false;
            }
        }
    }

    const bool& operator [] (std::uint32_t i) const {
        return (is_prime[i]);
    }
    bool operator [] (std::uint32_t i) {
        return (is_prime[i]);
    }
    
private:
    std::bitset<N + 1> is_prime;
};