#pragma once
#include <cassert>
#include <chrono>
#include <cstdint>
#include <random>
#include "../01_NumberTheory/02.01.01_is-prime.naive.hpp"

/**
 * @brief $\mod{p}$ の原始根 (乱択)
 * @note O(p⋅log(p))
 */
std::uint32_t primitive_root(std::uint32_t p) {
    assert(is_prime(p));
    if (p == 2) return 1;
    std::mt19937 mt(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<std::uint32_t> dist(2, p - 1);
    while (true) {
        std::uint32_t g = dist(mt);
        std::uint64_t w = 1;
        for (std::uint32_t i = 0; i < p - 2; ++i) {
            w = w * g % p;
            if (w == 1) break;
        }
        if (w != 1) return g;
    }
    return -1;
}