#pragma once
#include <vector>
#include <ostream>

/**
 * @brief 多項式
 */
template <class T>
std::vector<T> operator + (const std::vector<T>& a, const std::vector<T>& b) {
    std::uint32_t n = std::max(a.size(), b.size());
    std::vector<T> res(n);
    for (std::uint32_t i = 0; i < n; ++i) {
        if (i < a.size()) res[i] += a[i];
        if (i < b.size()) res[i] += b[i];
    }
    return res;
}

template <class T>
std::vector<T> operator - (const std::vector<T>& a, const std::vector<T>& b) {
    std::uint32_t n = std::max(a.size(), b.size());
    std::vector<T> res(n);
    for (std::uint32_t i = 0; i < n; ++i) {
        if (i < a.size()) res[i] += a[i];
        if (i < b.size()) res[i] -= b[i];
    }
    return res;
}

template <typename T>
std::ostream& operator << (std::ostream& os, const std::vector<T>& x) {
    for (std::uint32_t i = 0; i < x.size(); ++i) {
        if (i) os << " ";
        os << x[i];
    }
    return os;
}