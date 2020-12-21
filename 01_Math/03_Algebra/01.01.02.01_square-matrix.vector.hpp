#pragma once
#include <vector>
#include "01.01.01.01_matrix.vector.hpp"

/**
 * @brief 正方行列 (vector による実装)
 */
template <class T>
class SquareMatrix : public Matrix<T> {
public:
    SquareMatrix(std::uint32_t n, T x = 0) : Matrix<T>(n, n, x) {}
};