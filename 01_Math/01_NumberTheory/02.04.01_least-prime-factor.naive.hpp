#include <cstdint>

/**
 * @brief 最小素因数 (素朴な手法)
 * @note O(√n)
 */
std::uint64_t least_prime_factor(std::uint64_t n) {
    if (n <= 1) return n;
    for (std::uint64_t p = 2; p * p <= n; ++p) {
        if (n % p == 0) return p;
    }
    return n;
}