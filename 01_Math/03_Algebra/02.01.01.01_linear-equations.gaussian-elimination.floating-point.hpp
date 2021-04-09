#pragma once
#include <cassert>
#include <cmath>
#include <cstdint>
#include <type_traits>
#include <vector>
#include "01.00_matrix-constants.hpp"
#include "01.01.01.01_matrix.vector.hpp"
#include "01.02.01.01_gaussian-elimination.floating-point.hpp"

/**
 * @brief 連立一次方程式 (ガウスの消去法、実数)
 * @note O(nm²)
 */
template <class Matrix, typename T>
std::vector<T> linear_equations(Matrix& A, std::vector<T>& b) {
    static_assert(std::is_same<Matrix::value_type, T>::value);
    assert(A.height() == (std::uint32_t)b.size());
    matrix_vector<T> Ab(A.height(), A.width() + 1);
    for (std::uint32_t i = 0; i < A.height(); ++i) {
        for (std::uint32_t j = 0; j < A.width(); ++j) Ab[i][j] = A[i][j];
        Ab[i][Ab.width() - 1] = b[i];
    }
    std::vector<T> res;
    std::uint32_t rank = gaussian_elimination(Ab);
    for (std::uint32_t i = rank; i < Ab.height(); ++i) {
        if (std::fabs(Ab[i][Ab.width() - 1]) > matrix::EPS) return res;
    }
    res.resize(Ab.height(), 0);
    for (std::uint32_t i = 0; i < Ab.height(); ++i) res[i] = Ab[i][Ab.width() - 1];
    return res;
}