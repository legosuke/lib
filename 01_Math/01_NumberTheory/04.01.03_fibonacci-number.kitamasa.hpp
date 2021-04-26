#pragma once
#include "../02_Combinatorics/01.02.02_modint.dynamic.hpp"
#include "../../05_DP/03_Efficient/02.01_kitamasa.hpp"

/**
 * @brief フィボナッチ数 (Kitamasa法)
 * @note O(log(n))
 */
std::uint64_t fibonacci_number(std::uint64_t n, std::uint64_t m) {
    if (n <= 2) return 1;
    modint::set_mod(m);
    std::vector<modint> a = {1, 1}, c = {1, 1};
    return kitamasa(a, c, n - 1).get_val();
}