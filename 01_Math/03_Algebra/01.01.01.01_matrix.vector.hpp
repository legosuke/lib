#pragma once
#include <cstdint>
#include <vector>

template <class T>
class Matrix {
protected:
    std::uint32_t n, m;
    std::vector<std::vector<T>> v;

public:
    Matrix(std::uint32_t n, std::uint32_t m, T x = 0) : n(n), m(m), v(n, std::vector<T>(m, x)) {}
    void fill(T x) { v.clear(); v.resize(n, std::vector<T>(m, x)); }
    std::uint32_t height() const { return n; }
    std::uint32_t width() const { return m; }
    inline const std::vector<T>& operator [] (std::uint32_t i) const { return (v.at(i)); }
    inline std::vector<T>& operator [] (std::uint32_t i) { return (v.at(i)); }
};