#pragma once
#include <cstdint>
#include <vector>
#include "01.01.01.02_matrix.array.hpp"

/**
 * @brief 正方行列 (array)
 */
template <class T, std::uint32_t n>
class square_matrix_array : public matrix_array<T, n, n> {
public:
    square_matrix_array(T x = 0) : matrix_array<T, n, n>(x) {}
};