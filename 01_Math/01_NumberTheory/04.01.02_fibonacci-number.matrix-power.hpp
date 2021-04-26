#pragma once
#include "../02_Combinatorics/01.02.02_modint.dynamic.hpp"
#include "../03_Algebra/01.01.01.02_matrix.array.hpp"

/**
 * @brief フィボナッチ数 (行列累乗)
 * @note O(log(n))
 */
std::uint64_t fibonacci_number(std::uint64_t n, std::uint64_t m) {
    if (n <= 2) return 1;
    modint::set_mod(m);
    matrix_array<modint, 2, 2> a(0);
    a[0][0] = a[0][1] = a[1][0] = 1;
    a = a ^ (n - 2);
    std::vector<modint> x(2, 1);
    x = a * x;
    return x[0].get_val();
}