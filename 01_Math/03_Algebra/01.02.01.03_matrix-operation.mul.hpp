#pragma once
#include <vector>

/**
 * @brief 行列演算 (乗算)
 */
template <class Matrix, typename Scalar>
Matrix operator * (const Matrix& A, const Scalar& x) {
    Matrix C(A.height(), A.width());
    for (int i = 0; i < A.height(); ++i) for (int j = 0; j < A.width(); ++j) {
        C[i][j] = A[i][j] * x;
    }
    return C;
}

template <typename Scalar, class Matrix>
Matrix operator * (const Scalar& x, const Matrix& A) {
    Matrix C(A.height(), A.width());
    for (int i = 0; i < A.height(); ++i) for (int j = 0; j < A.width(); ++j) {
        C[i][j] = x * A[i][j];
    }
    return C;
}

template <class Matrix, typename Scalar>
std::vector<Scalar> operator * (const Matrix& A, const std::vector<Scalar>& v) {
    std::vector<Scalar> u(A.height(), 0);
    for (int i = 0; i < A.height(); ++i) for (int j = 0; j < A.width(); ++j) {
        u[i] = u[i] + A[i][j] * v[j];
    }
    return u;
}

template <class Matrix>
Matrix operator * (const Matrix& A, const Matrix& B) {
    assert(A.width() == B.height());
    Matrix C(A.height(), B.width());
    for (int i = 0; i < A.height(); ++i) for (int j = 0; j < B.width(); ++j) for (int k = 0; k < A.width(); ++k) {
        C[i][j] = C[i][j] + A[i][k] * B[k][j];
    }
    return C;
}