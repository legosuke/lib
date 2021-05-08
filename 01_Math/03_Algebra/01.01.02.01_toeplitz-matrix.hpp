#pragma once
#include <cassert>
#include <cstdint>
#include <vector>
#include "01.01.00_matrix-base.hpp"
#include "01.01.01.01_matrix.vector.hpp"
#include "05.01.01_convolution.fast-fourier-transform.hpp"

/**
 * @brief Toeplitz 行列
 */
template <typename T>
class toeplitz_matrix : matrix_base {
public:
    using value_type = T;

    toeplitz_matrix() = default;
    toeplitz_matrix(std::uint32_t n, T x = T(0)) { init(n, x); }
    toeplitz_matrix(std::vector<T> v) {
        assert(v.size() & 1);
        _n = (v.size() + 1) >> 1;
        _data = v;
    }

    std::uint32_t height() const {
        return _n;
    }
    std::uint32_t width() const {
        return _n;
    }
    void fill(T x = T(0)) {
        _data.clear(); _data.assign(2 * _n - 1, x);
    }
    void init(std::uint32_t n, T x = T(0)) {
        _n = n;
        fill(x);
    }
    const T& at(std::uint32_t i, std::uint32_t j) const {
        return _data.at(j - i + _n - 1);
    }
    T& at(std::uint32_t i, std::uint32_t j) {
        return (_data.at(j - i + _n - 1));
    }
    std::vector<T> data() const {
        return _data;
    }

    friend std::ostream& operator << (std::ostream& os, const toeplitz_matrix<T>& A) {
        for (std::uint32_t i = 0; i < A.height(); ++i) for (std::uint32_t j = 0; j < A.width(); ++j) {
            os << A.at(i, j) << " \n"[j + 1 == A.width()];
        }
        return os;
    }

private:
    std::uint32_t _n;
    std::vector<T> _data;
};

/**
 * @note O(n)
 */
template <class T>
toeplitz_matrix<T> operator + (const toeplitz_matrix<T>& A, const toeplitz_matrix<T>& B) {
    assert(A.height() == B.height());
    toeplitz_matrix<T> res(A.height());
    for (std::uint32_t i = 0; i < A.height(); ++i) {
        res.at(i, 0) = A.at(i, 0) + B.at(i, 0);
    }
    for (std::uint32_t j = 1; j < A.width(); ++j) {
        res.at(0, j) = A.at(0, j) + B.at(0, j);
    }
    return res;
}

/**
 * @note O(n)
 */
template <class T>
toeplitz_matrix<T> operator - (const toeplitz_matrix<T>& A, const toeplitz_matrix<T>& B) {
    assert(A.height() == B.height());
    toeplitz_matrix<T> res(A.height());
    for (std::uint32_t i = 0; i < A.height(); ++i) {
        res.at(i, 0) = A.at(i, 0) - B.at(i, 0);
    }
    for (std::uint32_t j = 1; j < A.width(); ++j) {
        res.at(0, j) = A.at(0, j) - B.at(0, j);
    }
    return res;
}

/**
 * @note O(n⋅lg(n))
 */
template <typename T>
std::vector<T> operator * (const toeplitz_matrix<T>& A, const std::vector<T>& v) {
    assert(A.width() == v.size());
    std::vector<T> b, c;
    for (auto&& vv : v) b.emplace_back(vv);
    for (auto&& aa : A.data()) c.emplace_back(aa);
    std::reverse(begin(c), end(c));
    if constexpr (std::is_integral<T>::value) {
        auto y = __fft::integral_convolution(b, c);
        std::vector<T> res(begin(y), end(y));
        res.erase(begin(res), begin(res) + A.height() - 1);
        res.resize(A.height());
        return res;
    } else {
        static_assert(std::is_floating_point<T>::value);
        return __fft::real_convolution(b, c);
    }
}

/**
 * @note O(n²)
 */
template <typename T>
matrix_vector<T> operator * (const toeplitz_matrix<T>& A, const toeplitz_matrix<T>& B) {
    assert(A.height() == B.height());
    std::uint32_t n = A.height();
    matrix_vector<T> res(n, n);
    auto a = A.data(), b = B.data();
    for (std::uint32_t j = 0; j < n; ++j) {
        for (std::uint32_t k = 0; k < n; ++k) {
            res[0][j] += a[n - 1 + k] * b[j + n - 1 - k];
        }
    }
    for (std::uint32_t i = 1; i < n; ++i) {
        for (std::uint32_t k = 0; k < n; ++k) {
            res[i][0] += a[n - 1 - i + k] * b[n - 1 - k];
        }
    }
    for (std::uint32_t i = 0; i + 1 < n; ++i) {
        for (std::uint32_t j = 0; j + 1 < n; ++j) {
            res[i + 1][j + 1] = res[i][j] + a[n - 2 - i] * b[j + n] - a[2 * n - 2 - i] * b[j];
        }
    }
    return res;
}