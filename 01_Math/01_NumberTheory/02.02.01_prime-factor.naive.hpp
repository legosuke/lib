#include <cstdint>
#include <vector>

/**
 * @brief 素因数分解 (素朴な手法)
 * @note O(\sqrt{n})
 */
std::vector<std::pair<std::uint64_t, std::uint8_t>> prime_factor(std::uint64_t n) {
    std::vector<std::pair<std::uint64_t, std::uint8_t>> pf;
    for (std::uint64_t p = 2; p * p <= n; ++p) {
        if (n % p != 0) continue;
        std::uint8_t e = 0;
        while (n % p == 0) {
            n /= p;
            ++e;
        }
        pf.emplace_back(p, e);
    }
    if (n != 1) pf.emplace_back(n, 1);
    return pf;
}