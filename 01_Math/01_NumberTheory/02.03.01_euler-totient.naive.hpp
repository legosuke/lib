#pragma once
#include <cstdint>

/**
 * @brief オイラーのトーシェント関数 (素朴な手法)
 * @note O(\sqrt{n})
 */
std::uint64_t totient(std::uint64_t n) {
    std::uint64_t res = n;
    for (std::uint64_t p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
            while (n % p == 0) {
                n /= p;
            }
            res -= res / p;
        }
    }
    if (n > 1) res -= res / n;
    return res;
}