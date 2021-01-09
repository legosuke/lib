#pragma once
#include <cassert>
#include <cstdlib>
#include <utility>
#include <vector>

/**
 * @brief ポテンシャル付き Union-Find
 */
template <typename T>
class PotentializedUnionFind {
public:
    PotentializedUnionFind() = default;
    explicit PotentializedUnionFind(std::uint32_t n)
        : _n(n), _num(n), _par(n, n), _size(n, 1), _weight(n) {}

    bool unite_trees(std::uint32_t x, std::uint32_t y, T w) {
        assert(0 <= x && x < _n && 0 <= y && y < _n);
        w += weight(x); w -= weight(y);
        x = find_root(x); y = find_root(y);
        if (x == y) return (w == 0);
        if (_size[x] < _size[y]) std::swap(x, y), w = -w;
        _size[x] += _size[y];
        _par[y] = x;
        _weight[y] = w;
        --_num;
        return true;
    }
    std::uint32_t find_root(std::uint32_t x) {
        assert(0 <= x && x < _n);
        if (_par[x] == _n) return x;
        std::uint32_t root = find_root(_par[x]);
        _weight[x] += _weight[_par[x]];
        return _par[x] = root;
    }
    bool is_root(std::uint32_t x) {
        assert(0 <= x && x < _n);
        return (_par[x] == _n);
    }
    bool is_same(std::uint32_t x, std::uint32_t y) {
        assert(0 <= x && x < _n && 0 <= y && y < _n);
        return (find_root(x) == find_root(y));
    }
    std::size_t tree_size(std::uint32_t x) {
        assert(0 <= x && x < _n);
        return _size[find_root(x)];
    }
    std::size_t number_of_trees() {
        return _num;
    }
    T weight(std::uint32_t x) {
        assert(0 <= x && x < _n);
        find_root(x);
        return _weight[x];
    }
    T diff_weight(std::uint32_t x, std::uint32_t y) {
        assert(0 <= x && x < _n && 0 <= y && y < _n);
        assert(is_same(x, y));
        return weight(y) - weight(x);
    }

protected:
    std::uint32_t _n, _num;
    std::vector<std::uint32_t> _par, _size;
    std::vector<T> _weight;
};