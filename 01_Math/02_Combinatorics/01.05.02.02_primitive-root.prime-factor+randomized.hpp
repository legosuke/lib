#pragma once
#include <cassert>
#include <chrono>
#include <cstdint>
#include <random>
#include "01.03.02_mod-pow.big-mod.hpp"

/**
 * @brief $\mod{p}$ の原始根 (素因数分解 + 乱択)
 * @note O(log³(p)/log(log(p)) + IP + PF)
 *       - IP : 素数判定
 *       - PF : 素因数分解
 */
template <bool (*is_prime)(std::uint64_t), std::vector<std::pair<std::uint64_t, std::uint32_t>> (*prime_factor)(std::uint64_t)>
std::uint64_t primitive_root(std::uint64_t p) {
    assert(is_prime(p));
    if (p == 2) return 1;
    std::mt19937_64 mt(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<std::uint64_t> dist(2, p - 1);
    auto pf = prime_factor(p - 1);
    while (true) {
        std::uint64_t g = dist(mt);
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