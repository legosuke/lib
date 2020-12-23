#pragma once
#include <cstdint>
#include <array>

/**
 * @brief 行列 (array による実装)
 */
template <class T, std::uint32_t n, std::uint32_t m>
class Matrix {
protected:
    std::array<std::array<T, m>, n> v;

public:
    Matrix(T x = 0) { fill(x); }
    void fill(T x) { v.fill(v.begin(), v.end(), x); }
    constexpr std::uint32_t height() const { return n; }
    constexpr std::uint32_t width() const { return m; }
    inline const std::array<T, m>& operator [] (std::uint32_t i) const { return (v.at(i)); }
    inline std::array<T, m>& operator [] (std::uint32_t i) { return (v.at(i)); }
    friend std::ostream& operator << (std::ostream& os, const Matrix<T, m>& M) {
        for (std::uint32_t i = 0; i < M.height(); ++i) for (std::uint32_t j = 0; j < M.width(); ++j) {
            os << M[i][j] << " \n"[j + 1 == M.width()];
        }
        return os;
    }
};