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
    std::uint32_t height() const { return n; }
    std::uint32_t width() const { return m; }
    inline const std::array<T, m>& operator [] (std::uint32_t i) const { return (v.at(i)); }
    inline std::array<T, m>& operator [] (std::uint32_t i) { return (v.at(i)); }
};