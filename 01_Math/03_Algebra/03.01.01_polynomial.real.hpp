#pragma once
#include <vector>
#include "03.01.00_polynomial.base.hpp"

/**
 * @brief 多項式 (実数)
 */
template <typename T>
class polynomial_real : polynomial_base {
public:
    polynomial_real() = default;
    polynomial_real(std::uint32_t n) : _v(n, 0) {}
    polynomial_real(std::vector<T> v) : _v(v) {}

    std::uint32_t size() const {
        return _v.size();
    }
    void resize(std::uint32_t n) {
        _v.resize(n);
    }
    const T& operator [] (std::uint32_t i) const {
        return (_v.at(i));
    }
    T& operator [] (std::uint32_t i) {
        return (_v.at(i));
    }
    friend std::ostream& operator << (std::ostream& os, const polynomial_real<T>& x) {
        for (std::uint32_t i = 0; i < x.size(); ++i) {
            if (i) os << " ";
            os << x[i];
        }
        return os;
    }

private:
    std::vector<T> _v;
};

template <class T>
polynomial_real<T> operator + (const polynomial_real<T>& a, const polynomial_real<T>& b) {
    std::uint32_t n = std::max(a.size(), b.size());
    polynomial_real<T> res(n);
    for (std::uint32_t i = 0; i < n; ++i) {
        if (i < a.size()) res[i] += a[i];
        if (i < b.size()) res[i] += b[i];
    }
    return res;
}

template <class T>
polynomial_real<T> operator - (const polynomial_real<T>& a, const polynomial_real<T>& b) {
    std::uint32_t n = std::max(a.size(), b.size());
    polynomial_real<T> res(n);
    for (std::uint32_t i = 0; i < n; ++i) {
        if (i < a.size()) res[i] += a[i];
        if (i < b.size()) res[i] -= b[i];
    }
    return res;
}