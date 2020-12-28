#pragma once
#include <vector>
#include "01.01.01.01_matrix.vector.hpp"

/**
 * @brief 正方行列 (vector)
 */
template <class T>
class square_matrix_vector : public matrix_vector<T> {
public:
    square_matrix_vector(std::uint32_t n, T x = 0) : matrix_vector<T>(n, n, x) {}
};