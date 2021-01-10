#pragma once
#include "01_union-find.hpp"

/**
 * @brief 属性つき Union-Find (min-max)
 * @warning データの値は後から変更できない
 */
template <typename T>
class union_find_minmax : public union_find {
public:
    union_find_minmax() = default;
    explicit union_find_minmax(std::uint32_t n) : union_find(n), _min(n), _max(n) {}

    void set(std::uint32_t x, T val) {
        assert(0 <= x && x < _n);
        _min[x] = _max[x] = val;
    }
    std::uint32_t unite_trees(std::uint32_t x, std::uint32_t y) {
        assert(0 <= x && x < _n && 0 <= y && y < _n);
        x = find_root(x); y = find_root(y);
        std::uint32_t res = union_find::unite_trees(x, y);
        _min[res] = std::min(_min[x], _min[y]);
        _max[res] = std::max(_max[x], _max[y]);
        return res;
    }
    T min(std::uint32_t x) {
        assert(0 <= x && x < _n);
        return _min[find_root(x)];
    }
    T max(std::uint32_t x) {
        assert(0 <= x && x < _n);
        return _max[find_root(x)];
    }

protected:
    std::vector<T> _min, _max;
};