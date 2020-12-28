#pragma once
#include <array>
#include <bitset>
#include <cstdint>
#include "01.01.00_matrix-base.hpp"

/**
 * @brief 行列 (bitset)
 */
template <std::uint32_t n, std::uint32_t m>
class matrix_bitset : matrix_base {
protected:
    std::array<std::bitset<m>, n> v;

public:
    matrix_bitset(bool x = 0) { fill(x); }
    void fill(bool x) { for_each(v.begin(), v.end(), [&](std::bitset<m> vv) { if (x) vv.set(); else vv.reset(); }); }
    constexpr std::uint32_t height() const { return n; }
    constexpr std::uint32_t width() const { return m; }
    inline const std::bitset<m>& operator [] (std::uint32_t i) const { return (v.at(i)); }
    inline std::bitset<m>& operator [] (std::uint32_t i) { return (v.at(i)); }
    friend std::ostream& operator << (std::ostream& os, const matrix_bitset<n, m>& M) {
        for (std::uint32_t i = 0; i < M.height(); ++i) for (std::uint32_t j = 0; j < M.width(); ++j) {
            os << M[i][j] << " \n"[j + 1 == M.width()];
        }
        return os;
    }
    using value_type = bool;
};