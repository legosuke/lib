#pragma once
#include <cstdint>
#include <vector>
#include "01.01.01.03_matrix.bitset.hpp"

/**
 * @brief 正方行列 (bitset)
 */
template <std::uint32_t n>
class square_matrix_bitset : public matrix_bitset<n, n> {
public:
    square_matrix_bitset(bool x = 0) : matrix_bitset<n, n>(x) {}
};