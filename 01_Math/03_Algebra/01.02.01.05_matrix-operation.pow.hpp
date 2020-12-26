#pragma once
#include <cassert>
#include <cstdint>

/**
 * @brief 行列演算 (累乗)
 */
template <class Matrix>
Matrix operator ^ (Matrix A, std::uint64_t n) {
    assert(A.height() == A.width());
    Matrix B(A.height(), A.width(), 0);
    for (int i = 0; i < A.height(); ++i) B[i][i] = 1;
    while (n) {
        if (n & 1) B = B * A;
        A = A * A;
        n >>= 1;
    }
    return B;
}