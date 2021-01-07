#pragma once
#include <cassert>
#include <cmath>
#include <cstdint>
#include <functional>
#include <type_traits>
#include <vector>
#include "01.00_matrix-constants.hpp"
#include "01.01.01.01_matrix.vector.hpp"

/**
 * @brief 逆行列 (ガウスの消去法)
 * @note O(n^3)
 * @warning 行列 A は n 次の正方行列
 */
template <class SquareMatrix, std::uint32_t (*gaussian_elimination)(SquareMatrix&)>
SquareMatrix inverse_matrix(SquareMatrix A) {
    static_assert(is_matrix<SquareMatrix>::value);
    assert(A.height() == A.width());
    using T = typename SquareMatrix::value_type;
    matrix_vector<T> AE(A.height(), A.width() << 1);
    for (std::uint32_t i = 0; i < A.height(); ++i) for (std::uint32_t j = 0; j < A.width(); ++j) {
        AE[i][j] = A[i][j];
    }
    for (std::uint32_t i = 0; i < A.height(); ++i) {
        AE[i][i + A.width()] = 1;
    }
    std::uint32_t rank = gaussian_elimination(AE);
    SquareMatrix res(A.height(), A.width());
    if (rank != A.height()) return res;
    for (std::uint32_t i = 0; i < A.height(); ++i) for (std::uint32_t j = 0; j < A.width(); ++j) {
        res[i][j] = AE[i][j + A.width()];
    }
    return res;
}