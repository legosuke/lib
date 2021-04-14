#pragma once
#include <cassert>
#include <cstdint>
#include <type_traits>
#include <utility>
#include <vector>
#include "../01_NumberTheory/01.04.01_ext-gcd.hpp"
#include "01.01_mod-operation.hpp"
#include "01.06.00_pre-chinese-remainder-theorem.hpp"

/**
 * @brief 中国剰余定理 (拡張ユークリッドの互除法)
 * @note O(t⋅log(max(mᵢ)))
 */
template <typename Integer>
std::pair<Integer, Integer> chinese_remainder_theorem(std::vector<Integer> r, std::vector<Integer> m) {
    static_assert(std::is_integral<Integer>::value);
    if (!pre_chinese_remainder_theorem(r, m)) return std::make_pair(0, -1);
    Integer x = 0, M = 1;
    for (std::uint32_t i = 0; i < r.size(); ++i) {
        Integer p, q;
        ext_gcd(M, m[i], p, q);
        x += (r[i] - x) * p % m[i] * M;
        M *= m[i];
    }
    return std::make_pair(mod(x, M), M);
}