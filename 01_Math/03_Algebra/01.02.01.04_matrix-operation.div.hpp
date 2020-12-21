#pragma once
#include <cassert>

template <class MatrixClass, typename ScalarType>
MatrixClass operator / (const MatrixClass& A, const ScalarType& x) {
    MatrixClass C(A.height(), A.width());
    for (int i = 0; i < A.height(); ++i) for (int j = 0; j < A.width(); ++j) {
        C[i][j] = A[i][j] / x;
    }
    return C;
}