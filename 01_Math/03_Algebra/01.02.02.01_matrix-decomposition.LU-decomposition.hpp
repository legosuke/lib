#pragma once
#include <cassert>
#include <cstdint>
#include <type_traits>
#include <utility>
#include "01.01.00_matrix-base.hpp"

/**
 * @brief 行列の分解 (LU 分解)
 * @note O(n^3)
 * @warning 行列 A は n 次の正方行列
 */
template <class Matrix>
std::pair<Matrix, Matrix> LU_decomposition(Matrix A) {
    static_assert(is_matrix<Matrix>::value);
    assert(A.height() == A.width());
    Matrix L(A.height(), A.width()), U(A.height(), A.width());
    for (std::uint32_t k = 0; k < A.width(); ++k) {
        for (std::uint32_t i = k; i < A.height(); ++i) {
            L[i][k] = A[i][k];
        }
        U[k][k] = 1;
        for (std::uint32_t j = k + 1; j < A.width(); ++j) {
            U[k][j] = A[k][j] / L[k][k];
        }
        for (std::uint32_t i = k + 1; i < A.height(); ++i) for (std::uint32_t j = k + 1; j < A.width(); ++j) {
            A[i][j] = A[i][j] - L[i][k] * U[k][j];
        }
    }
    return std::make_pair(L, U);
}