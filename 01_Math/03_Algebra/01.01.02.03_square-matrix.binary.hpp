#pragma once
#include <cstdint>
#include <vector>
#include "01.01.01.03_matrix.binary.hpp"

/**
 * @brief 正方行列 (バイナリ)
 */
template <std::uint32_t n>
class SquareMatrix : public Matrix<n, n> {
public:
    SquareMatrix(bool x = 0) : Matrix<n, n>(x) {}
};