#pragma once
#include <cstdint>
#include "01.00_matrix-constants.hpp"

/**
 * @brief 行列の階数 (ガウスの消去法)
 * @note O(nm^2)
 */
template <class Matrix, std::uint32_t (*gaussian_elimination)(Matrix&)>
std::uint32_t matrix_rank(Matrix A) {
    return gaussian_elimination(A, matrix::EPS);
}