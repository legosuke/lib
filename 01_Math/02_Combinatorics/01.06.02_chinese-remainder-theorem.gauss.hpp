#pragma once
#include <cassert>
#include <cstdint>
#include <type_traits>
#include <utility>
#include <vector>
#include "../01_NumberTheory/01.03.01_lcm.hpp"
#include "01.01_mod-operation.hpp"
#include "01.04.03_mod-inv.ext-gcd.hpp"
#include "01.06.00_pre-chinese-remainder-theorem.hpp"

/**
 * @brief 中国剰余定理 (Gauss)
 * @note O(t⋅log(max(mᵢ)))
 */
template <typename Integer>
std::pair<Integer, Integer> chinese_remainder_theorem(std::vector<Integer> r, std::vector<Integer> m) {
    static_assert(std::is_integral<Integer>::value);
    if (!pre_chinese_remainder_theorem(r, m)) return std::make_pair(0, -1);
    Integer x = 0, M = 1;
    for (std::uint32_t i = 0; i < r.size(); ++i) {
        M = lcm(M, m[i]);
    }
    for (std::uint32_t i = 0; i < r.size(); ++i) {
        Integer Mi = M / m[i], li = mod_inv(Mi, m[i]);
        (x += r[i] * li * Mi % M) %= M;
    }
    return std::make_pair(mod(x, M), M);
}