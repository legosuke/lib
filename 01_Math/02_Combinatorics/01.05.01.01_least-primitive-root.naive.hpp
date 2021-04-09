#pragma once
#include <cassert>
#include <cstdint>
#include "../01_NumberTheory/02.01.01_is-prime.naive.hpp"

/**
 * @brief $\mod{p}$ の最小原始根 (素朴な手法)
 * @note O(p²)
 * @note 実際は少し速い
 */
std::uint32_t least_primitive_root(std::uint32_t p) {
    assert(is_prime(p));
    if (p == 2) return 1;
    for (std::uint32_t g = 2; g < p; ++g) {
        std::uint64_t w = 1;
        for (std::uint32_t i = 0; i < p - 2; ++i) {
            w = w * g % p;
            if (w == 1) break;
        }
        if (w != 1) return g;
    }
    return -1;
}