#pragma once
#include <vector>

template <class MatrixClass, typename ScalarType>
MatrixClass operator * (const MatrixClass& A, const ScalarType& x) {
    MatrixClass C(A.height(), A.width());
    for (int i = 0; i < A.height(); ++i) for (int j = 0; j < A.width(); ++j) {
        C[i][j] = A[i][j] * x;
    }
    return C;
}

template <typename ScalarType, class MatrixClass>
MatrixClass operator * (const ScalarType& x, const MatrixClass& A) {
    MatrixClass C(A.height(), A.width());
    for (int i = 0; i < A.height(); ++i) for (int j = 0; j < A.width(); ++j) {
        C[i][j] = x * A[i][j];
    }
    return C;
}

template <class MatrixClass, typename ScalarType>
std::vector<ScalarType> operator * (const MatrixClass& A, const std::vector<ScalarType>& v) {
    std::vector<ScalarType> u(A.height(), 0);
    for (int i = 0; i < A.height(); ++i) for (int j = 0; j < A.width(); ++j) {
        u[i] = u[i] + A[i][j] * v[j];
    }
    return u;
}

template <class MatrixClass>
MatrixClass operator * (const MatrixClass& A, const MatrixClass& B) {
    assert(A.width() == B.height());
    MatrixClass C(A.height(), B.width());
    for (int i = 0; i < A.height(); ++i) for (int j = 0; j < B.width(); ++j) for (int k = 0; k < A.width(); ++k) {
        C[i][j] = C[i][j] + A[i][k] * B[k][j];
    }
    return C;
}