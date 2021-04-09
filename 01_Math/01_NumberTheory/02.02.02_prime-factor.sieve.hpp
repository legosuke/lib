#include <cstdint>
#include <vector>
#include "02.04.02_least-prime-factor.sieve.hpp"

const std::uint32_t MAX_N = 1000000;
std::vector<std::uint32_t> lpf = least_prime_factor(MAX_N + 1);

/**
 * @brief 素因数分解 (LPFを利用した手法)
 * @note O(log(n))
 */
std::vector<std::pair<std::uint32_t, std::uint8_t>> prime_factor(std::uint32_t n) {
    std::vector<std::pair<std::uint32_t, std::uint8_t>> pf;
    while (n > 1) {
        std::uint32_t p = lpf[n];
        std::uint8_t e = 0;
        while (n % p == 0) {
            n /= p;
            ++e;
        }
        pf.emplace_back(p, e);
    }
    return pf;
}