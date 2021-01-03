#pragma once
#include <cmath>
#include <cstdint>
#include <type_traits>
#include <utility>
#include "01.00_matrix-constants.hpp"

/**
 * @brief ガウスの消去法 (実数)
 * @note O(nm^2)
 * @warning 行列 A に対して破壊的
 */
template <class Matrix>
std::uint32_t gaussian_elimination(Matrix& A) {
    static_assert(std::is_floating_point<typename Matrix::value_type>::value);
    std::uint32_t rank = 0;
    for (std::uint32_t k = 0; k < A.width(); ++k) {
        std::uint32_t pivot = -1;
        double mx = matrix::EPS;
        for (std::uint32_t i = rank; i < A.height(); ++i) if (fabs(A[i][k]) > mx) {
            mx = fabs(A[i][k]);
            pivot = i;
        }
        if (!~pivot) continue;
        std::swap(A[pivot], A[rank]);
        const auto q = A[rank][k];
        for (std::uint32_t j = 0; j < A.width(); ++j) A[rank][j] = A[rank][j] / q;
        for (std::uint32_t i = 0; i < A.height(); ++i) if (i != rank && A[i][k]) {
            const auto q2 = A[i][k];
            for (std::uint32_t j = k; j < A.width(); ++j) A[i][j] = A[i][j] - A[rank][j] * q2;
        }
        ++rank;
    }
    return rank;
}