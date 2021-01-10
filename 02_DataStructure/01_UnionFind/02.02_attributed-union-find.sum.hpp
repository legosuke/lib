#pragma once
#include "01_union-find.hpp"

/**
 * @brief 属性つき Union-Find (sum)
 * @warning データの値は後から変更できない
 */
template <typename T>
class union_find_sum : public union_find {
public:
    union_find_sum() = default;
    explicit union_find_sum(std::uint32_t n) : union_find(n), _sum(n) {}

    void set(std::uint32_t x, T val) {
        assert(0 <= x && x < _n);
        _sum[x] = val;
    }
    std::uint32_t unite_trees(std::uint32_t x, std::uint32_t y) {
        assert(0 <= x && x < _n && 0 <= y && y < _n);
        x = find_root(x); y = find_root(y);
        std::uint32_t res = union_find::unite_trees(x, y);
        _sum[res] = _sum[x] + _sum[y];
        return res;
    }
    T sum(std::uint32_t x) {
        assert(0 <= x && x < _n);
        return _sum[find_root(x)];
    }

protected:
    std::vector<T> _sum;
};