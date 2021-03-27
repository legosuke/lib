#include <cstdint>
#include <numeric>
#include <vector>

/**
 * @brief 最小素因数 (篩)
 * @note O(n\log{\log{n}})
 */
std::vector<std::uint32_t> least_prime_factor(std::uint32_t n) {
    std::vector<std::uint32_t> lpf(n);
    std::iota(lpf.begin(), lpf.end(), 0);
    for (std::uint32_t i = 2; i * i < n; ++i) if (lpf[i] == i) {
        for (std::uint32_t j = i * i; j < n; j += i) {
            lpf[j] = i;
        }
    }
    return lpf;
}