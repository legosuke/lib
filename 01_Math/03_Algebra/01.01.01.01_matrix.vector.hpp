#pragma once
#include <cassert>
#include <cstdint>
#include <ostream>
#include <vector>

/**
 * @brief 行列 (vector)
 */
template <class T>
class matrix_vector {
public:
    using value_type = T;

    matrix_vector() = default;
    explicit matrix_vector(std::uint32_t n, std::uint32_t m, T x = T(0)) { init(n, m, x); }

    std::uint32_t height() const {
        return _n;
    }
    std::uint32_t width() const {
        return _m;
    }
    void init(std::uint32_t n, std::uint32_t m, T x = T(0)) {
        _n = n; _m = m;
        _v.clear(); _v.assign(_n, std::vector<T>(_m, x));
    }
    const std::vector<T>& operator [] (std::uint32_t i) const {
        return (_v.at(i));
    }
    std::vector<T>& operator [] (std::uint32_t i) {
        return (_v.at(i));
    }

protected:
    std::uint32_t _n, _m;
    std::vector<std::vector<T>> _v;
};

template <class T>
matrix_vector<T> operator + (const matrix_vector<T>& A, const T& x) {
    matrix_vector<T> res(A.height(), A.width());
    for (std::uint32_t i = 0; i < A.height(); ++i) for (std::uint32_t j = 0; j < A.width(); ++j) {
        res[i][j] = A[i][j] + x;
    }
    return res;
}

template <class T>
matrix_vector<T> operator + (const T& x, const matrix_vector<T>& A) {
    matrix_vector<T> res(A.height(), A.width());
    for (std::uint32_t i = 0; i < A.height(); ++i) for (std::uint32_t j = 0; j < A.width(); ++j) {
        res[i][j] = x + A[i][j];
    }
    return res;
}

template <class T>
matrix_vector<T> operator + (const matrix_vector<T>& A, const matrix_vector<T>& B) {
    assert(A.height() == B.height() && A.width() == B.width());
    matrix_vector<T> res(A.height(), A.width());
    for (std::uint32_t i = 0; i < A.height(); ++i) for (std::uint32_t j = 0; j < A.width(); ++j) {
        res[i][j] = A[i][j] + B[i][j];
    }
    return res;
}

template <class T>
matrix_vector<T> operator - (const matrix_vector<T>& A, const T& x) {
    matrix_vector<T> res(A.height(), A.width());
    for (std::uint32_t i = 0; i < A.height(); ++i) for (std::uint32_t j = 0; j < A.width(); ++j) {
        res[i][j] = A[i][j] - x;
    }
    return res;
}

template <class T>
matrix_vector<T> operator - (const T& x, const matrix_vector<T>& A) {
    matrix_vector<T> res(A.height(), A.width());
    for (std::uint32_t i = 0; i < A.height(); ++i) for (std::uint32_t j = 0; j < A.width(); ++j) {
        res[i][j] = x - A[i][j];
    }
    return res;
}

template <class T>
matrix_vector<T> operator - (const matrix_vector<T>& A, const matrix_vector<T>& B) {
    assert(A.height() == B.height() && A.width() == B.width());
    matrix_vector<T> res(A.height(), A.width());
    for (std::uint32_t i = 0; i < A.height(); ++i) for (std::uint32_t j = 0; j < A.width(); ++j) {
        res[i][j] = A[i][j] - B[i][j];
    }
    return res;
}

template <class T>
matrix_vector<T> operator * (const matrix_vector<T>& A, const T& x) {
    matrix_vector<T> res(A.height(), A.width());
    for (std::uint32_t i = 0; i < A.height(); ++i) for (std::uint32_t j = 0; j < A.width(); ++j) {
        res[i][j] = A[i][j] * x;
    }
    return res;
}

template <class T>
matrix_vector<T> operator * (const T& x, const matrix_vector<T>& A) {
    matrix_vector<T> res(A.height(), A.width());
    for (std::uint32_t i = 0; i < A.height(); ++i) for (std::uint32_t j = 0; j < A.width(); ++j) {
        res[i][j] = x * A[i][j];
    }
    return res;
}

template <class T>
std::vector<T> operator * (const matrix_vector<T>& A, const std::vector<T>& v) {
    assert(A.width() == (std::uint32_t)v.size());
    std::vector<T> u(A.height(), T(0));
    for (std::uint32_t i = 0; i < A.height(); ++i) for (std::uint32_t j = 0; j < A.width(); ++j) {
        u[i] = u[i] + A[i][j] * v[j];
    }
    return u;
}

template <class T>
matrix_vector<T> operator * (const matrix_vector<T>& A, const matrix_vector<T>& B) {
    assert(A.width() == B.height());
    matrix_vector<T> res(A.height(), B.width());
    for (std::uint32_t i = 0; i < A.height(); ++i) for (std::uint32_t j = 0; j < B.width(); ++j) for (std::uint32_t k = 0; k < A.width(); ++k) {
        res[i][j] = res[i][j] + A[i][k] * B[k][j];
    }
    return res;
}

template <class T>
matrix_vector<T> operator / (const matrix_vector<T>& A, const T& x) {
    matrix_vector<T> res(A.height(), A.width());
    for (std::uint32_t i = 0; i < A.height(); ++i) for (std::uint32_t j = 0; j < A.width(); ++j) {
        res[i][j] = A[i][j] / x;
    }
    return res;
}

template <class T>
matrix_vector<T> operator ^ (matrix_vector<T> A, std::uint64_t n) {
    assert(A.height() == A.width());
    matrix_vector<T> B(A.height(), A.width());
    for (int i = 0; i < A.height(); ++i) B[i][i] = 1;
    while (n) {
        if (n & 1) B = B * A;
        A = A * A;
        n >>= 1;
    }
    return B;
}

template <class T>
std::ostream& operator << (std::ostream& os, const matrix_vector<T>& A) {
    for (std::uint32_t i = 0; i < A.height(); ++i) for (std::uint32_t j = 0; j < A.width(); ++j) {
        os << A[i][j] << " \n"[j + 1 == A.width()];
    }
    return os;
}