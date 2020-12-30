#pragma once
#include <cstdint>
#include <ostream>
#include <vector>
#include "01.01.00_matrix-base.hpp"
#include "01.02.01.00_matrix-operation.hpp"

/**
 * @brief 行列 (vector)
 */
template <class T>
class matrix_vector : matrix_base {
protected:
    std::uint32_t n, m;
    std::vector<std::vector<T>> v;

public:
    matrix_vector(std::uint32_t n, std::uint32_t m, T x = 0) : n(n), m(m), v(n, std::vector<T>(m, x)) {}
    void fill(T x) { v.clear(); v.resize(n, std::vector<T>(m, x)); }
    std::uint32_t height() const { return n; }
    std::uint32_t width() const { return m; }
    inline const std::vector<T>& operator [] (std::uint32_t i) const { return (v.at(i)); }
    inline std::vector<T>& operator [] (std::uint32_t i) { return (v.at(i)); }
    friend std::ostream& operator << (std::ostream& os, const matrix_vector<T>& M) {
        for (std::uint32_t i = 0; i < M.height(); ++i) for (std::uint32_t j = 0; j < M.width(); ++j) {
            os << M[i][j] << " \n"[j + 1 == M.width()];
        }
        return os;
    }
    using value_type = T;
};