#pragma once
#include <vector>
#include "01.01.01.01_matrix.vector.hpp"

template <class T>
class SquareMatrix : public Matrix<T> {
public:
    SquareMatrix(std::uint32_t n, T x = 0) : Matrix<T>(n, n, x) {}
};