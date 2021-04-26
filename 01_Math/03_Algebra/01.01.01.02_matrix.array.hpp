#pragma once
#include <array>
#include <cstdint>
#include <vector>
#include "01.01.00_matrix-base.hpp"

/**
 * @brief 行列 (array)
 */
template <class T, std::uint32_t N, std::uint32_t M>
class matrix_array : matrix_base {
public:
    using value_type = T;

    matrix_array(T x = T(0)) { fill(x); }

    std::uint32_t height() const {
        return N;
    }
    std::uint32_t width() const {
        return M;
    }
    void fill(T x = T(0)) {
        for_each(_v.begin(), _v.end(), [&](auto&& vv) { vv.fill(x); });
    }
    const std::array<T, M>& operator [] (std::uint32_t i) const {
        return (_v.at(i));
    }
    std::array<T, M>& operator [] (std::uint32_t i) {
        return (_v.at(i));
    }

    friend std::ostream& operator << (std::ostream& os, const matrix_array<T, N, M>& A) {
        for (std::uint32_t i = 0; i < A.height(); ++i) for (std::uint32_t j = 0; j < A.width(); ++j) {
            os << A[i][j] << " \n"[j + 1 == A.width()];
        }
        return os;
    }

protected:
    std::array<std::array<T, M>, N> _v;
};

template <class T, std::uint32_t N, std::uint32_t M>
matrix_array<T, N, M> operator + (const matrix_array<T, N, M>& A, const T& x) {
    matrix_array<T, N, M> res;
    for (std::uint32_t i = 0; i < A.height(); ++i) for (std::uint32_t j = 0; j < A.width(); ++j) {
        res[i][j] = A[i][j] + x;
    }
    return res;
}
template <class T, std::uint32_t N, std::uint32_t M>
matrix_array<T, N, M> operator + (const T& x, const matrix_array<T, N, M>& A) {
    matrix_array<T, N, M> res;
    for (std::uint32_t i = 0; i < A.height(); ++i) for (std::uint32_t j = 0; j < A.width(); ++j) {
        res[i][j] = x + A[i][j];
    }
    return res;
}
template <class T, std::uint32_t N, std::uint32_t M>
matrix_array<T, N, M> operator + (const matrix_array<T, N, M>& A, const matrix_array<T, N, M>& B) {
    assert(A.height() == B.height() && A.width() == B.width());
    matrix_array<T, N, M> res;
    for (std::uint32_t i = 0; i < A.height(); ++i) for (std::uint32_t j = 0; j < A.width(); ++j) {
        res[i][j] = A[i][j] + B[i][j];
    }
    return res;
}

template <class T, std::uint32_t N, std::uint32_t M>
matrix_array<T, N, M> operator - (const matrix_array<T, N, M>& A, const T& x) {
    matrix_array<T, N, M> res;
    for (std::uint32_t i = 0; i < A.height(); ++i) for (std::uint32_t j = 0; j < A.width(); ++j) {
        res[i][j] = A[i][j] - x;
    }
    return res;
}
template <class T, std::uint32_t N, std::uint32_t M>
matrix_array<T, N, M> operator - (const T& x, const matrix_array<T, N, M>& A) {
    matrix_array<T, N, M> res;
    for (std::uint32_t i = 0; i < A.height(); ++i) for (std::uint32_t j = 0; j < A.width(); ++j) {
        res[i][j] = x - A[i][j];
    }
    return res;
}
template <class T, std::uint32_t N, std::uint32_t M>
matrix_array<T, N, M> operator - (const matrix_array<T, N, M>& A, const matrix_array<T, N, M>& B) {
    assert(A.height() == B.height() && A.width() == B.width());
    matrix_array<T, N, M> res;
    for (std::uint32_t i = 0; i < A.height(); ++i) for (std::uint32_t j = 0; j < A.width(); ++j) {
        res[i][j] = A[i][j] - B[i][j];
    }
    return res;
}

template <class T, std::uint32_t N, std::uint32_t M>
matrix_array<T, N, M> operator * (const matrix_array<T, N, M>& A, const T& x) {
    matrix_array<T, N, M> res;
    for (std::uint32_t i = 0; i < A.height(); ++i) for (std::uint32_t j = 0; j < A.width(); ++j) {
        res[i][j] = A[i][j] * x;
    }
    return res;
}
template <class T, std::uint32_t N, std::uint32_t M>
matrix_array<T, N, M> operator * (const T& x, const matrix_array<T, N, M>& A) {
    matrix_array<T, N, M> res;
    for (std::uint32_t i = 0; i < A.height(); ++i) for (std::uint32_t j = 0; j < A.width(); ++j) {
        res[i][j] = x * A[i][j];
    }
    return res;
}
template <class T, std::uint32_t N, std::uint32_t M>
std::vector<T> operator * (const matrix_array<T, N, M>& A, const std::vector<T>& v) {
    assert(A.width() == (std::uint32_t)v.size());
    std::vector<T> u(A.height(), T(0));
    for (std::uint32_t i = 0; i < A.height(); ++i) for (std::uint32_t j = 0; j < A.width(); ++j) {
        u[i] = u[i] + A[i][j] * v[j];
    }
    return u;
}
template <class T, std::uint32_t N, std::uint32_t M>
matrix_array<T, N, M> operator * (const matrix_array<T, N, M>& A, const matrix_array<T, N, M>& B) {
    assert(A.width() == B.height());
    matrix_array<T, N, M> res;
    for (std::uint32_t i = 0; i < A.height(); ++i) for (std::uint32_t j = 0; j < B.width(); ++j) for (std::uint32_t k = 0; k < A.width(); ++k) {
        res[i][j] = res[i][j] + A[i][k] * B[k][j];
    }
    return res;
}

template <class T, std::uint32_t N, std::uint32_t M>
matrix_array<T, N, M> operator / (const matrix_array<T, N, M>& A, const T& x) {
    matrix_array<T, N, M> res;
    for (std::uint32_t i = 0; i < A.height(); ++i) for (std::uint32_t j = 0; j < A.width(); ++j) {
        res[i][j] = A[i][j] / x;
    }
    return res;
}
template <class T, std::uint32_t N, std::uint32_t M>
matrix_array<T, N, M> operator ^ (matrix_array<T, N, M> A, std::uint64_t n) {
    assert(A.height() == A.width());
    matrix_array<T, N, M> B(0);
    for (std::uint32_t i = 0; i < A.height(); ++i) B[i][i] = T(1);
    while (n) {
        if (n & 1) B = B * A;
        A = A * A;
        n >>= 1;
    }
    return B;
}