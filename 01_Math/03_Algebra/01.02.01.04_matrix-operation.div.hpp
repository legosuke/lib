#pragma once
#include <cassert>

/**
 * @brief 行列演算 (除算)
 */
template <class Matrix, typename Scalar>
Matrix operator / (const Matrix& A, const Scalar& x) {
    Matrix C(A.height(), A.width());
    for (int i = 0; i < A.height(); ++i) for (int j = 0; j < A.width(); ++j) {
        C[i][j] = A[i][j] / x;
    }
    return C;
}