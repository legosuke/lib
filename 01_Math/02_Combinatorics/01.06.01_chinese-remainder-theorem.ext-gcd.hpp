#pragma once
#include <cassert>
#include <cstdint>
#include <type_traits>
#include <utility>
#include <vector>
#include "../01_NumberTheory/01.04.01_ext-gcd.hpp"
#include "01.01_mod-operation.hpp"

template <typename Integer>
std::pair<Integer, Integer> chinese_remainder_theorem(std::vector<Integer> r, std::vector<Integer> m) {
    static_assert(std::is_integral<Integer>::value);
    Integer x = 0, M = 1;
    for (std::uint32_t i = 0; i < r.size(); ++i) {
        Integer p, q;
        auto d = ext_gcd(M, m[i], p, q);
        if ((r[i] - x) % d != 0) return std::make_pair(0, -1);
        auto tmp = (r[i] - x) / d * p % (m[i] / d);
        x += M * tmp;
        M *= m[i] / d;
    }
    return std::make_pair(mod(x, M), M);
}