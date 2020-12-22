#pragma once

/**
 * @brief 行列演算 (減算)
 */
template <class Matrix, typename Scalar>
Matrix operator - (const Matrix& A, const Scalar& x) {
    Matrix C(A.height(), A.width());
    for (int i = 0; i < A.height(); ++i) for (int j = 0; j < A.width(); ++j) {
        C[i][j] = A[i][j] - x;
    }
    return C;
}

template <typename Scalar, class Matrix>
Matrix operator - (const Scalar& x, const Matrix& A) {
    Matrix C(A.height(), A.width());
    for (int i = 0; i < A.height(); ++i) for (int j = 0; j < A.width(); ++j) {
        C[i][j] = x - A[i][j];
    }
    return C;
}

template <class Matrix>
Matrix operator - (const Matrix& A, const Matrix& B) {
    Matrix C(A.height(), A.width());
    for (int i = 0; i < A.height(); ++i) for (int j = 0; j < A.width(); ++j) {
        C[i][j] = A[i][j] - B[i][j];
    }
    return C;
}