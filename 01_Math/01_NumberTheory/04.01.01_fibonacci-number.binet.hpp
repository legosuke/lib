#pragma once
#include <cmath>
#include "../02_Combinatorics/01.02.02_modint.dynamic.hpp"

/**
 * @brief フィボナッチ数 (Binet)
 * @warning m は 2 と互いに素
 */
std::uint64_t fibonacci_number(std::uint64_t n, std::uint64_t m) {
    using P = std::pair<modint, modint>;
    modint::set_mod(m);
    auto mul = [](P a, P b) {
        return P(a.first * b.first + 5 * a.second * b.second, a.first * b.second + a.second * b.first);
    };
    P res(1, 0), alpha(modint(2).inv(), modint(2).inv());
    for (std::uint32_t i = 0; i < 60; ++i) {
        if (n >> i & 1) res = mul(res, alpha);
        alpha = mul(alpha, alpha);
    }
    return (2 * res.second).get_val();
}