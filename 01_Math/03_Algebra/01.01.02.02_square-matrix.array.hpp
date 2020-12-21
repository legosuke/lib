#pragma once
#include <cstdint>
#include <vector>
#include "01.01.01.02_matrix.array.hpp"

template <class T, std::uint32_t n>
class SquareMatrix : public Matrix<T, n, n> {
public:
    SquareMatrix(T x = 0) : Matrix<T, n, n>(x) {}
};