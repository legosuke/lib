#pragma once

template <class MatrixClass, typename ScalarType>
MatrixClass operator + (const MatrixClass& A, const ScalarType& x) {
    MatrixClass C(A.height(), A.width());
    for (int i = 0; i < A.height(); ++i) for (int j = 0; j < A.width(); ++j) {
        C[i][j] = A[i][j] + x;
    }
    return C;
}

template <typename ScalarType, class MatrixClass>
MatrixClass operator + (const ScalarType& x, const MatrixClass& A) {
    MatrixClass C(A.height(), A.width());
    for (int i = 0; i < A.height(); ++i) for (int j = 0; j < A.width(); ++j) {
        C[i][j] = x + A[i][j];
    }
    return C;
}

template <class MatrixClass>
MatrixClass operator + (const MatrixClass& A, const MatrixClass& B) {
    MatrixClass C(A.height(), A.width());
    for (int i = 0; i < A.height(); ++i) for (int j = 0; j < A.width(); ++j) {
        C[i][j] = A[i][j] + B[i][j];
    }
    return C;
}