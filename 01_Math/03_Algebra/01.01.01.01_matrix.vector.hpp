#pragma once
#include <cstdint>
#include <ostream>
#include <vector>

/**
 * @brief 行列 (vector による実装)
 */
template <class T>
class Matrix {
protected:
    std::uint32_t n, m;
    std::vector<std::vector<T>> v;

public:
    Matrix(std::uint32_t n, std::uint32_t m, T x = 0) : n(n), m(m), v(n, std::vector<T>(m, x)) {}
    void fill(T x) { v.clear(); v.resize(n, std::vector<T>(m, x)); }
    constexpr std::uint32_t height() const { return n; }
    constexpr std::uint32_t width() const { return m; }
    inline const std::vector<T>& operator [] (std::uint32_t i) const { return (v.at(i)); }
    inline std::vector<T>& operator [] (std::uint32_t i) { return (v.at(i)); }
    friend std::ostream& operator << (std::ostream& os, const Matrix<T>& M) {
        for (std::uint32_t i = 0; i < M.height(); ++i) for (std::uint32_t j = 0; j < M.width(); ++j) {
            os << M[i][j] << " \n"[j + 1 == M.width()];
        }
        return os;
    }
    using value_type = T;
};