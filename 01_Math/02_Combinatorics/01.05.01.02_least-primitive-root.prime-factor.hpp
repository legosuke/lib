#pragma once
#include <cassert>
#include <cstdint>
#include <vector>
#include "01.03.02_mod-pow.big-mod.hpp"

/**
 * @brief $mod p$ の最小原始根 (素因数分解)
 * @note O(p⋅log²(p)/log(log(p)) + IP + PF)
 *       - IP : 素数判定
 *       - PF : 素因数分解
 * @note 実際は少し速い
 */
template <bool (*is_prime)(std::uint64_t), std::vector<std::pair<std::uint64_t, std::uint32_t>> (*prime_factor)(std::uint64_t)>
std::uint64_t least_primitive_root2(std::uint64_t p) {
    assert(is_prime(p));
    if (p == 2) return 1;
    auto pf = prime_factor(p - 1);
    for (std::uint64_t g = 2; g < p; ++g) {
        bool is_primitive_root = true;
        for (auto pp : pf) {
            if (mod_pow(g, (p - 1) / pp.first, p) == 1) {
                is_primitive_root = false;
                break;
            }
        }
        if (is_primitive_root) return g;
    }
    return -1;
}