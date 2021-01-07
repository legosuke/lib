#pragma once
#include <cassert>
#include <type_traits>
#include "01.01.00_matrix-base.hpp"
#include "01.02.02.01_matrix-decomposition.LU.hpp"

/**
 * @brief 行列式 (LU 分解)
 * @note O(n^3)
 * @warning 行列 A は n 次の正方行列
 */
template <class Matrix>
typename Matrix::value_type matrix_determinant(Matrix A) {
    static_assert(is_matrix<Matrix>::value);
    assert(A.height() == A.width());
    auto LU = LU_decomposition(A);
    typename Matrix::value_type res = 1;
    for (std::uint32_t i = 0; i < LU.first.height(); ++i) {
        res = res * LU.first[i][i];
    }
    return res;
}