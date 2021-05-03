#pragma once
#include <bitset>
#include "03.01.00_sieve.base.hpp"

/**
 * @brief 篩 (アトキン)
 * @note O(n/log(log(n))) time / O(n) space
 */
template <std::uint32_t N>
class atkin : sieve_base {
public:
    atkin() {
        is_prime.reset();
        for (std::uint32_t x = 1; x * x < N; ++x) {
            for (std::uint32_t y = 1; y * y < N; ++y) {
                std::uint32_t n = (4 * x * x) + (y * y);
                if (n <= N && (n % 12 == 1 || n % 12 == 5)) {
                    is_prime[n].flip();
                }
                n = (3 * x * x) + (y * y);
                if (n <= N && n % 12 == 7) {
                    is_prime[n].flip();
                }
                n = (3 * x * x) - (y * y);
                if (x > y && n <= N && n % 12 == 11) {
                    is_prime[n].flip();
                }
            }
        }
        for (std::uint32_t r = 5; r * r < N; ++r) {
            if (!is_prime[r]) continue;
            for (std::uint32_t i = r * r; i < N; i += r * r) {
                is_prime[i] = false;
            }
        }
        is_prime[2] = is_prime[3] = true;
    }

    const bool operator [] (std::uint32_t i) const {
        return (is_prime[i]);
    }
    
private:
    std::bitset<N + 1> is_prime;
};