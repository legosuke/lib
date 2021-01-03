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
public:
    using value_type = bool;

    matrix_bitset() = default;
    explicit matrix_bitset(bool x = 0) { init(x); }

    std::uint32_t height() const {
        return n;
    }
    std::uint32_t width() const {
        return m;
    }
    void init(bool x) {
        for_each(_v.begin(), _v.end(), [&](std::bitset<m> vv) { if (x) vv.set(); else vv.reset(); });
    }

    const std::bitset<m>& operator [] (std::uint32_t i) const {
        return (_v.at(i));
    }
    std::bitset<m>& operator [] (std::uint32_t i) {
        return (_v.at(i));
    }

    friend std::ostream& operator << (std::ostream& os, const matrix_bitset<n, m>& A) {
        for (std::uint32_t i = 0; i < A.height(); ++i) for (std::uint32_t j = 0; j < A.width(); ++j) {
            os << A[i][j] << " \n"[j + 1 == A.width()];
        }
        return os;
    }

protected:
    std::array<std::bitset<m>, n> _v;
};