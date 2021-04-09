#pragma once
#include <cstdint>
#include <type_traits>
#include <utility>
#include "../02_Combinatorics/01.02.00_modint-base.hpp"

/**
 * @brief ガウスの消去法 ($\mod{p}$)
 * @note O(nm²)
 * @warning p は素数
 * @warning 行列 A に対して破壊的
 */
template <class Matrix>
std::uint32_t gaussian_elimination(Matrix& A) {
    static_assert(is_modint<typename Matrix::value_type>::value);
    std::uint32_t rank = 0;
    for (std::uint32_t k = 0; k < A.width(); ++k) {
        std::uint32_t pivot = -1;
        for (std::uint32_t i = rank; i < A.height(); ++i) if (A[i][k]) {
            pivot = i;
            break;
        }
        if (!~pivot) continue;
        std::swap(A[pivot], A[rank]);
        const auto q = A[rank][k].inv();
        for (std::uint32_t j = 0; j < A.width(); ++j) A[rank][j] = A[rank][j] * q;
        for (std::uint32_t i = 0; i < A.height(); ++i) if (i != rank && A[i][k]) {
            const auto q2 = A[i][k];
            for (std::uint32_t j = k; j < A.width(); ++j) A[i][j] = A[i][j] - A[rank][j] * q2;
        }
        ++rank;
    }
    return rank;
}