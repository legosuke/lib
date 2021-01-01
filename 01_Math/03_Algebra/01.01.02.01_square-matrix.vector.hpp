#pragma once
#include <vector>
#include "01.01.01.01_matrix.vector.hpp"

/**
 * @brief 正方行列 (vector)
 */
template <class T>
class square_matrix_vector : public matrix_vector<T> {
public:
    square_matrix_vector() = default;
    explicit square_matrix_vector(std::uint32_t n, T x = T(0)) : matrix_vector<T>(n, n, x) {}
    // square_matrix_vector& operator = (const matrix_vector<T>& rhs) {
    //     *this->_n = rhs._n; *this->_m = rhs._m; *this->_v = rhs._v;
    //     return *this;
    // }
};