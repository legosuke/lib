#pragma once
#include "02.01.01_factorial.table.hpp"

/**
 * @brief 組合せ (階乗 + 逆元)
 */
template <class ModInt>
class Combination {
public:
    /**
     * @note O(n)
     */
    Combination(std::uint32_t n) {
        fact = factorial_table<ModInt>(n);
        ifact.resize(n + 1);
        ifact[n] = fact[n].inv();
        for (std::uint32_t i = n; i >= 1; --i) {
            ifact[i - 1] = ifact[i] * i;
        }
    }

    /**
     * @brief nCk
     * @note O(1)
     */
    ModInt c(std::uint32_t n, std::uint32_t k) {
        return fact[n] * ifact[k] * ifact[n - k];
    }
private:
    std::vector<ModInt> fact, ifact;
};