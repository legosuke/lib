#pragma once
#include <bitset>
#include "02.04.02_least-prime-factor.sieve.hpp"
#include "03.01.00_sieve.base.hpp"

/**
 * @brief 篩 (線形)
 * @note O(n) time / O(n⋅log(n)) space
 */
template <std::uint32_t N>
class linear : sieve_base {
public:
    linear() {
        is_prime.reset();
        auto lpf = least_prime_factor(N + 1);
        for (std::uint32_t i = 2; i <= N; ++i) {
            is_prime[i] = (lpf[i] == i);
        }
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