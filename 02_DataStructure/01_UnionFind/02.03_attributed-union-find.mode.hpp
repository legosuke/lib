#pragma once
#include <unordered_map>
#include "01_union-find.hpp"

/**
 * @brief 属性つき Union-Find (mode)
 * @warning データの値は後から変更できない
 */
template <typename T>
class UnionFindMode : public UnionFind {
public:
    UnionFindMode() = default;
    explicit UnionFindMode(std::uint32_t n) : UnionFind(n), _mode(n), _count(n) {}

    void set(std::uint32_t x, T val) {
        assert(0 <= x && x < _n);
        _mode[x] = val;
        _count[x][val]++;
    }
    std::uint32_t unite_trees(std::uint32_t x, std::uint32_t y) {
        assert(0 <= x && x < _n && 0 <= y && y < _n);
        x = find_root(x); y = find_root(y);
        std::uint32_t res = UnionFind::unite_trees(x, y);
        for (auto p : _count[y]) {
            _count[x][p.first] += p.second;
            if (_count[x][p.first] >= _count[x][_mode[x]]) {
                if (_count[x][p.first] == _count[x][_mode[x]]) {
                    if (p.first < _mode[x]) _mode[x] = p.first;
                } else {
                    _mode[x] = p.first;
                }
            }
        }
        return res;
    }
    T mode(std::uint32_t x) {
        assert(0 <= x && x < _n);
        return _mode[find_root(x)];
    }
    std::uint32_t mode_count(std::uint32_t x) {
        assert(0 <= x && x < _n);
        x = find_root(x);
        return _count[x][mode[x]];
    }

protected:
    std::vector<T> _mode;
    std::vector<std::unordered_map<T, std::uint32_t>> _count;
};