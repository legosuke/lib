#pragma once
#include <cstdint>
#include <type_traits>
#include <utility>
#include "01.01.00_matrix-base.hpp"

/**
 * @brief ガウスの消去法 (バイナリ)
 * @note O(nm^2)
 * @warning 行列 A に対して破壊的
 */
template <class Matrix>
std::uint32_t gaussian_elimination(Matrix& A) {
    static_assert(is_matrix<Matrix>::value);
    static_assert(std::is_same<typename Matrix::value_type, bool>::value);
    std::uint32_t rank = 0;
    for (std::uint32_t k = 0; k < A.width(); ++k) {
        std::uint32_t pivot = -1;
        for (std::uint32_t i = rank; i < A.height(); ++i) if (A[i][k]) {
            pivot = i;
            break;
        }
        if (!~pivot) continue;
        std::swap(A[pivot], A[rank]);
        for (std::uint32_t i = 0; i < A.height(); ++i) if (i != rank && A[i][k]) {
            A[i] ^= A[rank];
        }
        ++rank;
    }
    return rank;
}