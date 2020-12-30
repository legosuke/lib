#pragma once
#include <array>
#include <cstdint>
#include "01.01.00_matrix-base.hpp"
#include "01.02.01.00_matrix-operation.hpp"

/**
 * @brief 行列 (array)
 */
template <class T, std::uint32_t n, std::uint32_t m>
class matrix_array : matrix_base {
protected:
    std::array<std::array<T, m>, n> v;

public:
    matrix_array(T x = 0) { fill(x); }
    void fill(T x) { for_each(v.begin(), v.end(), [&](auto vv) { vv.fill(x); }); }
    constexpr std::uint32_t height() const { return n; }
    constexpr std::uint32_t width() const { return m; }
    inline const std::array<T, m>& operator [] (std::uint32_t i) const { return (v.at(i)); }
    inline std::array<T, m>& operator [] (std::uint32_t i) { return (v.at(i)); }
    friend std::ostream& operator << (std::ostream& os, const matrix_array<T, n, m>& M) {
        for (std::uint32_t i = 0; i < M.height(); ++i) for (std::uint32_t j = 0; j < M.width(); ++j) {
            os << M[i][j] << " \n"[j + 1 == M.width()];
        }
        return os;
    }
    using value_type = T;
};